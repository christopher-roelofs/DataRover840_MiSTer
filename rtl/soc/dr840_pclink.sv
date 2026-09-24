//
// dr840_pclink.sv - the computer at the far end of the serial port.
//
// Magic Cap installs packages over its serial port: on a PC, WinPcLink
// waits for the device; on the device the user goes to the Storeroom and
// taps the computer. This is the PC's half of that conversation, as the
// reference emulator's pclink.c has it, with the package in the SDRAM
// where the OSD's file loader put it.
//
// The wire is a stream cut into blocks: a two-byte big-endian length, the
// bytes, and a CRC-32 of them (all ones to start, no final complement).
// Inside the blocks the bytes 0E, 0F and 10 are quoted with a 10 in front
// of them, and a block never splits a quote from the byte it quotes, so a
// block is at most 256 bytes and can be 255. The stream itself is
// commands: a four-byte tag, a big-endian length, the payload.
//
// The device speaks first, with "ChMa" and then Cnct. The PC answers Cntd
// twice -- once starts the device processing commands but leaves a
// second wait to time out twenty seconds later, in the middle of a large
// transfer -- and then offers the package: SPkg with WinPcLink's fixed
// 1028-byte record (the length twice, a flag word, and the name in
// UTF-16), then the package bytes as a stream of their own, then four
// zero bytes. Every Ping from the device gets a Pong; after a while with
// nothing to say the PC pings, and the device's Pong once the package is
// all out is the transfer complete. GBye or Abrt before that is a
// failure.
//
// Bytes come from the guest's UART as it hands them to its transmitter,
// and go into its receiver's holding register when that is empty and a
// frame time has passed since the last, which is the pace a real wire
// would set. Everything here runs on the core's enabled edges.
//
`default_nettype none

module dr840_pclink #(
    parameter [24:0] PKG_BASE = 25'h100_0000    // in the SDRAM, after the cards
) (
    input  wire        clk,
    input  wire        cen,
    input  wire        rst_n,

    // The package: how long it is, and a toggle that offers it -- clears
    // everything and waits for the guest to link.
    input  wire        go_tog,
    input  wire [24:0] pkg_len,

    // The loader's writes while it arrives: a word at a byte offset.
    input  wire [24:0] wr_addr,
    input  wire [31:0] wr_data,
    input  wire        wr_req,
    output reg         wr_ack,

    // The memory, through the board's arbiter.
    output reg  [24:0] pmem_addr,
    output reg         pmem_req,
    output reg         pmem_we,
    output reg  [31:0] pmem_wdata,
    input  wire        pmem_ack,
    input  wire [31:0] pmem_rdata,

    // The guest's UART A: a byte as it is handed over (a toggle, so it
    // is not missed on the enabled edges), and one for its receiver.
    input  wire        gtx_tog,
    input  wire [7:0]  gtx_data,
    output reg         grx_tog,
    output reg  [7:0]  grx_data,
    input  wire        grx_full,      // its holding register is full
    input  wire        uart_on,       // and the UART is enabled at all
    input  wire [19:0] bit_clocks,    // one bit time, in clocks
    // How fast the bytes go: a frame time each, as the wire would have
    // it; or 4 or 16 times that; or as fast as the guest reads them.
    input  wire [1:0]  speed,

    output reg  [2:0]  state,         // see below
    output reg  [24:0] sent           // package bytes handed over so far
);

    localparam [2:0] ST_IDLE = 3'd0,   // no package
                     ST_WAIT = 3'd1,   // offered; waiting for the guest to link
                     ST_LINK = 3'd2,   // linked and sending
                     ST_DONE = 3'd3,   // the guest has it
                     ST_FAIL = 3'd4;   // the guest hung up or stopped it

    localparam [7:0] CTRL_END = 8'h0E, CTRL_ABORT = 8'h0F, CTRL_QUOTE = 8'h10;
    localparam [31:0] TAG_CNCT = "Cnct", TAG_PING = "Ping", TAG_PONG = "Pong",
                      TAG_GBYE = "GBye", TAG_ABRT = "Abrt";
    localparam [15:0] IDLE_PING = 16'd20000;   // frame times with nothing to say

    // CRC-32, a byte at a time: the reflected polynomial, as zlib's table
    // computes it.
    function [31:0] crc8(input [31:0] c, input [7:0] b);
        integer i;
        reg [31:0] x;
        begin
            x = c ^ {24'd0, b};
            for (i = 0; i < 8; i = i + 1)
                x = x[0] ? ((x >> 1) ^ 32'hEDB8_8320) : (x >> 1);
            crc8 = x;
        end
    endfunction

    // ------------------------------------------------------------ pacing
    // A frame is ten bits; on the enabled edges that is five bit times.
    reg [22:0] frame_cen, pace, byte_cen;
    always @(posedge clk) if (cen) begin
        frame_cen <= {bit_clocks, 2'b00} + {3'd0, bit_clocks};
        case (speed)
        2'd0: byte_cen <= frame_cen;
        2'd1: byte_cen <= {2'd0, frame_cen[22:2]};
        2'd2: byte_cen <= {4'd0, frame_cen[22:4]};
        default: byte_cen <= 23'd1;
        endcase
    end

    // ------------------------------------------------- from the guest
    reg        gtx_q;
    wire       rx_v = (gtx_tog != gtx_q);
    reg        greeted;
    reg [31:0] gshift;
    reg [2:0]  rx_st;           // 0,1 length; 2 bytes; 3..6 the CRC
    reg [15:0] rx_rem;
    reg        escaped;
    reg [2:0]  cmd_idx;         // 0..7 collecting the tag and length; 8 skipping the payload
    reg        cmd_skip;
    reg [31:0] cmd_tag, cmd_rem;
    reg        offered;
    reg [3:0]  pong_pend;

    // A stream byte, out of the block and unquoted.
    wire       blk_byte = rx_v && greeted && (rx_st == 3'd2);
    wire       feed_v = blk_byte && (escaped || !(gtx_data == CTRL_QUOTE || gtx_data == CTRL_END
                                                  || gtx_data == CTRL_ABORT));
    // A command complete: with the last byte of its payload, or with its
    // length when it has none.
    wire       cmd_hdr_last = feed_v && !cmd_skip && (cmd_idx == 3'd7);
    wire [31:0] cmd_len_now = {cmd_rem[23:0], gtx_data};
    wire       dispatch = (cmd_hdr_last && cmd_len_now == 32'd0) ||
                          (feed_v && cmd_skip && cmd_rem == 32'd1);

    // ------------------------------------------------- to the guest
    localparam [2:0] MK_CNTD = 3'd0, MK_SPKG = 3'd1, MK_PKG = 3'd2, MK_ZERO = 3'd3,
                     MK_PONG = 3'd4, MK_PING = 3'd5;
    localparam [3:0] T_IDLE = 4'd0, T_FILL = 4'd1, T_HDR0 = 4'd2, T_HDR1 = 4'd3,
                     T_BODY = 4'd4, T_CRC0 = 4'd5, T_CRC1 = 4'd6, T_CRC2 = 4'd7, T_CRC3 = 4'd8;
    reg [3:0]  tx_st;
    reg [2:0]  mk;
    reg [2:0]  seq;             // 0 nothing; 1,2 Cntd; 3 SPkg; 4 the package; 5 the zeros
    reg [24:0] msg_len, mi;     // the message, and the byte of it being placed
    reg [8:0]  at, ridx;        // the block: bytes placed, and the one being sent
    reg [31:0] crc;
    reg        q_pend;          // the quote is placed; the byte itself is next
    reg [15:0] idle_cnt;
    reg [7:0]  blk [0:255];     // the block, quoted
    reg [7:0]  blk_q;
    reg        fill_we;
    reg [7:0]  fill_b, fill_at;
    // The package word being read, and which one it is.
    reg [31:0] word;
    reg [22:0] word_addr;
    reg        word_ok, reading;

    // The message's byte at mi.
    function [7:0] src(input [2:0] k, input [24:0] i, input [24:0] len, input [31:0] w);
        reg [11:0] j;
        begin
            j = i[11:0] - 12'd8;
            case (k)
            MK_CNTD: src = (i == 0) ? "C" : (i == 1) ? "n" : (i == 2) ? "t" : (i == 3) ? "d" : 8'd0;
            MK_PONG: src = (i == 0) ? "P" : (i == 1) ? "o" : (i == 2) ? "n" : (i == 3) ? "g" : 8'd0;
            MK_PING: src = (i == 0) ? "P" : (i == 1) ? "i" : (i == 2) ? "n" : (i == 3) ? "g" : 8'd0;
            MK_ZERO: src = 8'd0;
            MK_SPKG:
                // "SPkg", the length 1028, then WinPcLink's record: the
                // package length twice, 80000000 at word 5, the name's
                // length at word 7 and the name in UTF-16 from byte 32.
                if (i < 4)       src = (i == 0) ? "S" : (i == 1) ? "P" : (i == 2) ? "k" : "g";
                else if (i < 8)  src = (i == 6) ? 8'h04 : (i == 7) ? 8'h04 : 8'd0;
                else case (j)
                    12'd0, 12'd4:   src = {7'd0, len[24]};
                    12'd1, 12'd5:   src = len[23:16];
                    12'd2, 12'd6:   src = len[15:8];
                    12'd3, 12'd7:   src = len[7:0];
                    12'd20:         src = 8'h80;
                    12'd31:         src = 8'd7;
                    12'd33:         src = "P";
                    12'd35:         src = "a";
                    12'd37:         src = "c";
                    12'd39:         src = "k";
                    12'd41:         src = "a";
                    12'd43:         src = "g";
                    12'd45:         src = "e";
                    default:        src = 8'd0;
                endcase
            default: // the package, big-endian words
                case (i[1:0])
                2'd0: src = w[31:24];
                2'd1: src = w[23:16];
                2'd2: src = w[15:8];
                default: src = w[7:0];
                endcase
            endcase
        end
    endfunction

    wire [7:0] sb = src(mk, mi, pkg_len, word);
    wire       sb_quoted = (sb == CTRL_END) || (sb == CTRL_ABORT) || (sb == CTRL_QUOTE);
    wire       have_word = (mk != MK_PKG) || (word_ok && word_addr == mi[24:2]);
    wire       can_send = uart_on && !grx_full && (pace == 23'd0) && (state == ST_LINK);
    // The next message, when the sender is idle.
    wire       next_seq  = (seq != 3'd0);
    wire [2:0] seq_kind  = (seq == 3'd3) ? MK_SPKG : (seq == 3'd4) ? MK_PKG : (seq == 3'd5) ? MK_ZERO : MK_CNTD;
    wire [24:0] kind_len = (seq_kind == MK_SPKG) ? 25'd1036 : (seq_kind == MK_PKG) ? pkg_len
                         : (seq_kind == MK_ZERO) ? 25'd4 : 25'd8;

    // The block buffer: written as it is filled, read a byte ahead of the
    // one being sent.
    always @(posedge clk) if (cen) begin
        if (fill_we) blk[fill_at] <= fill_b;
        blk_q <= blk[ridx[7:0]];
    end

    reg go_q;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            go_q <= 1'b0; gtx_q <= 1'b0; grx_tog <= 1'b0; grx_data <= 8'd0;
            state <= ST_IDLE; sent <= 25'd0; pace <= 23'd0;
            greeted <= 1'b0; gshift <= 32'd0; rx_st <= 3'd0; rx_rem <= 16'd0; escaped <= 1'b0;
            cmd_idx <= 3'd0; cmd_skip <= 1'b0; cmd_tag <= 32'd0; cmd_rem <= 32'd0;
            offered <= 1'b0; pong_pend <= 4'd0;
            tx_st <= T_IDLE; mk <= MK_CNTD; seq <= 3'd0; msg_len <= 25'd0; mi <= 25'd0;
            at <= 9'd0; ridx <= 9'd0; crc <= 32'hFFFF_FFFF; q_pend <= 1'b0; idle_cnt <= 16'd0;
            fill_we <= 1'b0; fill_b <= 8'd0; fill_at <= 8'd0;
            word <= 32'd0; word_addr <= 23'd0; word_ok <= 1'b0; reading <= 1'b0;
            wr_ack <= 1'b0; pmem_addr <= 25'd0; pmem_req <= 1'b0; pmem_we <= 1'b0; pmem_wdata <= 32'd0;
        end else if (cen) begin
            gtx_q   <= gtx_tog;
            fill_we <= 1'b0;
            if (pace != 23'd0) pace <= pace - 23'd1;

            // ------------------------------------------------ the memory
            // One thing at a time: the loader's word in, or a word of
            // the package out.
            if (pmem_req) begin
                if (pmem_ack) begin
                    pmem_req <= 1'b0;
                    if (reading) begin word <= pmem_rdata; word_ok <= 1'b1; reading <= 1'b0; end
                    else wr_ack <= 1'b1;
                end
            end else if (wr_ack) begin
                if (!wr_req) wr_ack <= 1'b0;
            end else if (wr_req) begin
                pmem_addr <= PKG_BASE + {wr_addr[24:2], 2'b00};
                pmem_wdata <= wr_data; pmem_we <= 1'b1; pmem_req <= 1'b1;
                word_ok <= 1'b0;
            end else if (tx_st == T_FILL && !have_word && !reading) begin
                pmem_addr <= PKG_BASE + {mi[24:2], 2'b00};
                word_addr <= mi[24:2]; word_ok <= 1'b0;
                pmem_we <= 1'b0; pmem_req <= 1'b1; reading <= 1'b1;
            end

            // ------------------------------------------------ from the guest
            if (rx_v && state != ST_IDLE) begin
                if (!greeted) begin
                    gshift <= {gshift[23:0], gtx_data};
                    if ({gshift[23:0], gtx_data} == "ChMa") greeted <= 1'b1;
                end else case (rx_st)
                3'd0: begin rx_rem[15:8] <= gtx_data; rx_st <= 3'd1; end
                3'd1: begin
                    rx_rem[7:0] <= gtx_data;
                    rx_st <= ({rx_rem[15:8], gtx_data} == 16'd0) ? 3'd3 : 3'd2;
                end
                3'd2: begin
                    rx_rem <= rx_rem - 16'd1;
                    if (rx_rem == 16'd1) rx_st <= 3'd3;
                    if (escaped) escaped <= 1'b0;
                    else if (gtx_data == CTRL_QUOTE) escaped <= 1'b1;
                end
                3'd6: rx_st <= 3'd0;
                default: rx_st <= rx_st + 3'd1;
                endcase
            end
            // The stream: commands, of which only the tag matters.
            if (feed_v) begin
                if (!cmd_skip) begin
                    cmd_idx <= cmd_idx + 3'd1;
                    if (cmd_idx < 3'd4) cmd_tag <= {cmd_tag[23:0], gtx_data};
                    else                cmd_rem <= {cmd_rem[23:0], gtx_data};
                    if (cmd_idx == 3'd7) begin
                        cmd_idx <= 3'd0;
                        if (cmd_len_now != 32'd0) cmd_skip <= 1'b1;
                    end
                end else begin
                    cmd_rem <= cmd_rem - 32'd1;
                    if (cmd_rem == 32'd1) cmd_skip <= 1'b0;
                end
            end
            if (dispatch) begin
                if (cmd_tag == TAG_CNCT) begin
                    if (!offered) begin offered <= 1'b1; state <= ST_LINK; seq <= 3'd1; end
                end else if (cmd_tag == TAG_PING) begin
                    if (pong_pend != 4'd15) pong_pend <= pong_pend + 4'd1;
                end else if (cmd_tag == TAG_PONG) begin
                    // Its answer once it has finished taking the package.
                    if (state == ST_LINK && offered && seq == 3'd0 && tx_st == T_IDLE && pong_pend == 4'd0)
                        state <= ST_DONE;
                end else if (cmd_tag == TAG_GBYE || cmd_tag == TAG_ABRT) begin
                    if (state != ST_DONE && state != ST_IDLE) state <= ST_FAIL;
                end
            end

            // ------------------------------------------------ to the guest
            case (tx_st)
            T_IDLE: begin
                if (state == ST_LINK) begin
                    if (next_seq) begin
                        mk <= seq_kind; msg_len <= kind_len; seq <= seq + 3'd1;
                        if (kind_len != 25'd0) begin
                            mi <= 25'd0; at <= 9'd0; crc <= 32'hFFFF_FFFF; q_pend <= 1'b0; tx_st <= T_FILL;
                        end
                        if (seq == 3'd5) seq <= 3'd0;
                    end else if (pong_pend != 4'd0) begin
                        pong_pend <= pong_pend - 4'd1;
                        mk <= MK_PONG; msg_len <= 25'd8;
                        mi <= 25'd0; at <= 9'd0; crc <= 32'hFFFF_FFFF; q_pend <= 1'b0; tx_st <= T_FILL;
                    end else if (idle_cnt == IDLE_PING) begin
                        idle_cnt <= 16'd0;
                        mk <= MK_PING; msg_len <= 25'd8;
                        mi <= 25'd0; at <= 9'd0; crc <= 32'hFFFF_FFFF; q_pend <= 1'b0; tx_st <= T_FILL;
                    end else if (uart_on && !grx_full && pace == 23'd0) begin
                        // Nothing to send: one poll a frame time, and a
                        // Ping after twenty thousand of them.
                        pace <= frame_cen;
                        idle_cnt <= idle_cnt + 16'd1;
                    end
                end
            end
            T_FILL: if (have_word) begin
                if (sb_quoted && !q_pend) begin
                    fill_we <= 1'b1; fill_b <= CTRL_QUOTE; fill_at <= at[7:0]; crc <= crc8(crc, CTRL_QUOTE);
                    at <= at + 9'd1; q_pend <= 1'b1;
                    // A quote is never the last thing in a block: the
                    // byte it quotes follows, and there is room for it.
                end else begin
                    fill_we <= 1'b1; fill_b <= sb; fill_at <= at[7:0]; crc <= crc8(crc, sb);
                    at <= at + 9'd1; q_pend <= 1'b0;
                    mi <= mi + 25'd1;
                    if (mk == MK_PKG) sent <= mi + 25'd1;
                    if (at + 9'd1 >= 9'd255 || mi + 25'd1 == msg_len) begin
                        tx_st <= T_HDR0; ridx <= 9'd0;
                    end
                end
            end
            T_HDR0: if (can_send) begin
                grx_data <= {7'd0, at[8]}; grx_tog <= ~grx_tog; pace <= byte_cen; idle_cnt <= 16'd0;
                tx_st <= T_HDR1;
            end
            T_HDR1: if (can_send) begin
                grx_data <= at[7:0]; grx_tog <= ~grx_tog; pace <= byte_cen;
                tx_st <= T_BODY;
            end
            T_BODY: if (can_send) begin
                grx_data <= blk_q; grx_tog <= ~grx_tog; pace <= byte_cen;
                ridx <= ridx + 9'd1;
                if (ridx + 9'd1 == at) tx_st <= T_CRC0;
            end
            T_CRC0: if (can_send) begin
                grx_data <= crc[31:24]; grx_tog <= ~grx_tog; pace <= byte_cen; tx_st <= T_CRC1;
            end
            T_CRC1: if (can_send) begin
                grx_data <= crc[23:16]; grx_tog <= ~grx_tog; pace <= byte_cen; tx_st <= T_CRC2;
            end
            T_CRC2: if (can_send) begin
                grx_data <= crc[15:8]; grx_tog <= ~grx_tog; pace <= byte_cen; tx_st <= T_CRC3;
            end
            T_CRC3: if (can_send) begin
                grx_data <= crc[7:0]; grx_tog <= ~grx_tog; pace <= byte_cen;
                if (mi == msg_len) tx_st <= T_IDLE;
                else begin at <= 9'd0; crc <= 32'hFFFF_FFFF; tx_st <= T_FILL; end
            end
            default: tx_st <= T_IDLE;
            endcase

            // ------------------------------------------------ the offer
            // Everything back to the start, waiting for the guest.
            go_q <= go_tog;
            if (go_tog != go_q) begin
                state <= (pkg_len != 25'd0) ? ST_WAIT : ST_IDLE;
                sent <= 25'd0;
                greeted <= 1'b0; gshift <= 32'd0; rx_st <= 3'd0; escaped <= 1'b0;
                cmd_idx <= 3'd0; cmd_skip <= 1'b0;
                offered <= 1'b0; pong_pend <= 4'd0;
                tx_st <= T_IDLE; seq <= 3'd0; idle_cnt <= 16'd0; word_ok <= 1'b0;
            end
        end
    end
endmodule

`default_nettype wire
