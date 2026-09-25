//
// dr840_netbridge.sv - the network card's frames, to and from the MiSTer.
//
// Two rings in the DDR memory the FPGA shares with the HPS, at physical
// 0x38000000, which scripts/drnet (a daemon on the MiSTer's Linux) serves
// with a TAP interface routed onto the network. Byte offsets:
//
//   0x0000  magic "DRNE" -- written by the daemon while it runs: the link
//   0x0008  tx_head      -- frames this has put in the transmit ring
//   0x0010  tx_tail      -- frames the daemon has taken from it
//   0x0018  rx_head      -- frames the daemon has put in the receive ring
//   0x0020  rx_tail      -- frames this has taken from it
//   0x0028  hello        -- this adds one to it when it starts, having
//                           published its own two counters as zero
//   0x0030  echo         -- the daemon copies hello here once it has
//                           reset its side: the link is up only while
//                           the magic is there and the echo is ours, so a
//                           core loaded afresh never reads a queue left
//                           from the one before
//   0x1000  transmit ring: 16 slots of 0x800, a 16-bit length at +0
//           and the frame at +8
//   0x9000  receive ring, the same
//
// Counters are 32-bit, little-endian, in the low half of their 64-bit
// word; a slot is the counter modulo 16, and head - tail is how many are
// waiting. A frame's byte i is at slot + 8 + i, as Linux sees memory:
// byte lane i % 8 of the 64-bit word.
//
// The DDR side runs every clock (Avalon: a request is taken on an edge
// where it is high and BUSY is not). The NIC side is sampled on the core's
// enabled edges, so each strobe to it is held until one has passed.
//
`default_nettype none

module dr840_netbridge (
    input  wire        clk,
    input  wire        cen,           // the core's, which the NIC samples on
    input  wire        rst_n,
    input  wire        enable,        // the network card is fitted

    // ---- the NIC
    input  wire        tx_req,
    input  wire [13:0] tx_base,
    input  wire [10:0] tx_len,
    output reg         tx_done,
    output reg         tx_ok,
    output reg         rx_offer,
    output reg  [10:0] rx_len,
    output reg  [47:0] rx_dst,
    input  wire        rx_answer,
    input  wire        rx_take,
    output reg         rx_byte,
    output reg  [7:0]  rx_data,
    input  wire        rx_busy,
    output reg  [13:0] b_addr,
    input  wire [7:0]  b_q,

    // ---- the DDR, 64-bit
    input  wire        ddr_busy,
    output reg  [28:0] ddr_addr,
    output reg         ddr_rd,
    output reg         ddr_we,
    output reg  [63:0] ddr_din,
    input  wire [63:0] ddr_dout,
    input  wire        ddr_dout_ready,

    // Slot 1's accesses, logged to 0x38100000 as 64-bit words, the count
    // at 0x38 (see dr840_tx39.sv's trace_word).
    input  wire        trace_stb,
    input  wire [63:0] trace_word,

    output reg         link,          // the daemon is there
    output reg  [31:0] dbg_tx,        // frames handed to it
    output reg  [31:0] dbg_rx         // and taken from it
);
    localparam [28:0] BASE = 29'h0700_0000;           // 0x38000000 / 8
    localparam [31:0] MAGIC = 32'h454E_5244;           // "DRNE", little-endian

    localparam [4:0] S_IDLE = 5'd0, S_POLL0 = 5'd1, S_POLL1 = 5'd2, S_POLL2 = 5'd3,
                     S_TX_BYTE = 5'd4, S_TX_WAIT = 5'd5, S_TX_WORD = 5'd6, S_TX_LEN = 5'd7,
                     S_TX_HEAD = 5'd8, S_TX_ACK = 5'd9,
                     S_RX_LEN = 5'd10, S_RX_W0 = 5'd11, S_RX_OFFER = 5'd12, S_RX_ANS = 5'd13,
                     S_RX_WORD = 5'd14, S_RX_BYTE = 5'd15, S_RX_TAIL = 5'd16,
                     S_READ = 5'd17, S_WRITE = 5'd18, S_HELLO = 5'd19, S_HELLO_W = 5'd20,
                     S_POLLE = 5'd21, S_START = 5'd22, S_TRACE = 5'd23, S_ZERO = 5'd24;
    reg [4:0]  st, ret;
    reg [31:0] tx_head, tx_tail, rx_head, rx_tail;
    reg [19:0] poll_cnt;
    reg [10:0] n;               // bytes done
    reg [63:0] acc;             // a word being assembled, or read
    reg [1:0]  bw;              // byte-read latency
    reg [2:0]  lanes;
    reg        pulse_wait;
    reg        magic_ok, hello_read;
    // The trace: a small queue, drained into the DDR when the bridge is idle.
    reg [63:0] tq [0:63];
    reg [5:0]  tq_w, tq_r;
    reg [31:0] t_count;
    always @(posedge clk) if (trace_stb && enable) tq[tq_w] <= trace_word;
    reg [31:0] epoch;

    // A frame slot's word address.
    function [28:0] slot_word(input [15:0] ring_base_bytes, input [31:0] ctr, input [10:0] byte_off);
        slot_word = BASE + {13'd0, ring_base_bytes[15:3]} + {17'd0, ctr[3:0], 8'd0} + {18'd0, byte_off[10:3]};
    endfunction

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            st <= S_START; ret <= S_IDLE;
            tx_done <= 1'b0; tx_ok <= 1'b0; rx_offer <= 1'b0; rx_len <= 11'd0; rx_dst <= 48'd0;
            rx_byte <= 1'b0; rx_data <= 8'd0; b_addr <= 14'd0;
            ddr_addr <= 29'd0; ddr_rd <= 1'b0; ddr_we <= 1'b0; ddr_din <= 64'd0;
            link <= 1'b0; dbg_tx <= 32'd0; dbg_rx <= 32'd0;
            tx_head <= 32'd0; tx_tail <= 32'd0; rx_head <= 32'd0; rx_tail <= 32'd0;
            poll_cnt <= 20'd0; n <= 11'd0; acc <= 64'd0; bw <= 2'd0; lanes <= 3'd0; pulse_wait <= 1'b0;
            magic_ok <= 1'b0; epoch <= 32'd0; hello_read <= 1'b0; tq_w <= 6'd0; tq_r <= 6'd0; t_count <= 32'd0;
        end else begin
            if (trace_stb && enable && (tq_w + 6'd1 != tq_r)) tq_w <= tq_w + 6'd1;
            // Strobes to the NIC last until an enabled edge has seen them.
            if (cen) begin tx_done <= 1'b0; rx_offer <= 1'b0; rx_byte <= 1'b0; end
            if (!enable) begin
                st <= S_START; link <= 1'b0; ddr_rd <= 1'b0; ddr_we <= 1'b0;
                tx_head <= 32'd0; rx_tail <= 32'd0;
            end else case (st)
            // ------------------------------------------------ hello, once
            // Its own counters published as zero first, so a daemon that
            // answers the hello starts from what is really there.
            S_START: begin
                ddr_addr <= BASE + 29'd1; ddr_din <= 64'd0; ddr_we <= 1'b1; st <= S_WRITE; ret <= S_ZERO;
            end
            S_ZERO: begin
                ddr_addr <= BASE + 29'd4; ddr_din <= 64'd0; ddr_we <= 1'b1; st <= S_WRITE; ret <= S_HELLO;
            end
            S_HELLO: begin
                // First the hello read, then one more than it written back.
                if (!hello_read) begin
                    hello_read <= 1'b1;
                    ddr_addr <= BASE + 29'd5; ddr_rd <= 1'b1; st <= S_READ; ret <= S_HELLO;
                end else begin
                    hello_read <= 1'b0;
                    epoch <= acc[31:0] + 32'd1;
                    ddr_addr <= BASE + 29'd5; ddr_din <= {32'd0, acc[31:0] + 32'd1};
                    ddr_we <= 1'b1; st <= S_WRITE; ret <= S_IDLE;
                end
            end
            // ------------------------------------------------ one DDR word
            S_READ: begin
                if (ddr_rd && !ddr_busy) ddr_rd <= 1'b0;
                if (ddr_dout_ready) begin acc <= ddr_dout; st <= ret; end
            end
            S_WRITE: if (!ddr_busy) begin ddr_we <= 1'b0; st <= ret; end

            // ------------------------------------------------ idle: poll, or work
            S_IDLE: begin
                poll_cnt <= poll_cnt + 20'd1;
                if (tx_req && !tx_done && link && (tx_head - tx_tail) < 32'd16) begin
                    n <= 11'd0; lanes <= 3'd0; acc <= 64'd0;
                    b_addr <= tx_base; bw <= 2'd0; st <= S_TX_BYTE;
                end else if (tx_req && !tx_done && !link) begin
                    // No daemon: the carrier is lost, as with no cable.
                    tx_ok <= 1'b0; tx_done <= 1'b1; st <= S_TX_ACK;
                end else if (link && rx_head != rx_tail && !rx_busy) begin
                    ddr_addr <= slot_word(16'h9000, rx_tail, 11'd0); ddr_rd <= 1'b1;
                    st <= S_READ; ret <= S_RX_LEN;
                end else if (tq_r != tq_w) begin
                    ddr_addr <= BASE + 29'h0002_0000 + {16'd0, t_count[12:0]};   // 0x38100000, 8192 words
                    ddr_din <= tq[tq_r]; ddr_we <= 1'b1; st <= S_WRITE; ret <= S_TRACE;
                end else if (poll_cnt[15:0] == 16'd0) begin
                    // Every 0.7 ms: the magic, the daemon's two counters.
                    ddr_addr <= BASE; ddr_rd <= 1'b1; st <= S_READ; ret <= S_POLL0;
                end
            end
            S_TRACE: begin
                tq_r <= tq_r + 6'd1; t_count <= t_count + 32'd1;
                ddr_addr <= BASE + 29'd7; ddr_din <= {32'd0, t_count + 32'd1};
                ddr_we <= 1'b1; st <= S_WRITE; ret <= S_IDLE;
            end
            S_POLL0: begin
                magic_ok <= (acc[31:0] == MAGIC);
                ddr_addr <= BASE + 29'd6; ddr_rd <= 1'b1; st <= S_READ; ret <= S_POLLE;
            end
            S_POLLE: begin
                link <= magic_ok && acc[31:0] == epoch;
                ddr_addr <= BASE + 29'd2; ddr_rd <= 1'b1; st <= S_READ; ret <= S_POLL1;
            end
            S_POLL1: begin
                tx_tail <= acc[31:0];
                ddr_addr <= BASE + 29'd3; ddr_rd <= 1'b1; st <= S_READ; ret <= S_POLL2;
            end
            S_POLL2: begin
                // The counters run on across a lost link: the daemon, when it
                // comes back, takes up the ones published here.
                rx_head <= acc[31:0];
                st <= S_IDLE;
            end

            // ------------------------------------------------ transmit
            S_TX_BYTE: begin
                // b_q is the byte at b_addr two clocks on.
                bw <= bw + 2'd1;
                if (bw == 2'd2) begin
                    acc[8 * lanes +: 8] <= b_q;
                    n <= n + 11'd1; lanes <= lanes + 3'd1;
                    b_addr <= b_addr + 14'd1; bw <= 2'd0;
                    if (lanes == 3'd7 || n + 11'd1 == tx_len) st <= S_TX_WORD;
                end
            end
            S_TX_WORD: begin
                // The word just filled: bytes (n-1) & ~7 onward, at +8.
                ddr_addr <= slot_word(16'h1000, tx_head, (n - 11'd1) + 11'd8);
                ddr_din <= acc; ddr_we <= 1'b1; st <= S_WRITE;
                ret <= (n == tx_len) ? S_TX_LEN : S_TX_BYTE;
                acc <= 64'd0; lanes <= 3'd0;
            end
            S_TX_LEN: begin
                ddr_addr <= slot_word(16'h1000, tx_head, 11'd0);
                ddr_din <= {53'd0, tx_len}; ddr_we <= 1'b1; st <= S_WRITE; ret <= S_TX_HEAD;
            end
            S_TX_HEAD: begin
                // Published only once the frame is all there.
                ddr_addr <= BASE + 29'd1; ddr_din <= {32'd0, tx_head + 32'd1};
                tx_head <= tx_head + 32'd1; dbg_tx <= dbg_tx + 32'd1;
                ddr_we <= 1'b1; st <= S_WRITE; ret <= S_TX_ACK;
                tx_ok <= 1'b1; tx_done <= 1'b1;
            end
            S_TX_ACK: begin
                // tx_done is held until an enabled edge; then tx_req drops.
                if (!tx_done && !tx_req) st <= S_IDLE;
            end

            // ------------------------------------------------ receive
            S_RX_LEN: begin
                rx_len <= (acc[10:0] > 11'd1518) ? 11'd1518 : acc[10:0];
                ddr_addr <= slot_word(16'h9000, rx_tail, 11'd8); ddr_rd <= 1'b1;
                st <= S_READ; ret <= S_RX_W0;
            end
            S_RX_W0: begin
                rx_dst <= {acc[7:0], acc[15:8], acc[23:16], acc[31:24], acc[39:32], acc[47:40]};
                rx_offer <= 1'b1; st <= S_RX_OFFER;
            end
            S_RX_OFFER: if (cen) st <= S_RX_ANS;          // the offer has been seen
            S_RX_ANS: if (rx_answer) begin
                if (rx_take && rx_len != 11'd0) begin
                    n <= 11'd0; lanes <= 3'd0; st <= S_RX_BYTE;   // acc still holds word 0
                end else st <= S_RX_TAIL;
            end
            S_RX_WORD: begin
                ddr_addr <= slot_word(16'h9000, rx_tail, n + 11'd8); ddr_rd <= 1'b1;
                st <= S_READ; ret <= S_RX_BYTE;
            end
            S_RX_BYTE: begin
                if (!pulse_wait) begin
                    rx_data <= acc[8 * lanes +: 8]; rx_byte <= 1'b1; pulse_wait <= 1'b1;
                end else if (cen) begin
                    // Seen: the next byte, from this word or the next.
                    pulse_wait <= 1'b0;
                    n <= n + 11'd1; lanes <= lanes + 3'd1;
                    if (n + 11'd1 == rx_len) st <= S_RX_TAIL;
                    else if (lanes == 3'd7) st <= S_RX_WORD;
                end
            end
            S_RX_TAIL: if (!rx_busy) begin
                ddr_addr <= BASE + 29'd4; ddr_din <= {32'd0, rx_tail + 32'd1};
                rx_tail <= rx_tail + 32'd1; dbg_rx <= dbg_rx + 32'd1;
                ddr_we <= 1'b1; st <= S_WRITE; ret <= S_IDLE;
            end
            default: st <= S_IDLE;
            endcase
        end
    end
endmodule

`default_nettype wire
