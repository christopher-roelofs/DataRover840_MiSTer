//
// dr840_ne2000.sv - an NE2000 (DP8390) Ethernet controller, as a PC Card.
//
// The reference emulator's ne2000.c, register for register: the station
// PROM, 16 KB of packet RAM at 0x4000..0x7FFF, remote DMA, the three
// register pages, transmit and the receive ring. Magic Cap's Ne2000 driver
// package (with WCPack) talks to it through a PC Card slot; the frames go
// to and from the MiSTer's Linux through dr840_netbridge.sv.
//
// Reads have side effects (the DMA port advances, the tally counters and
// the reset port clear), so an access is one strobe: `acc` for one enabled
// edge, with `rdata` valid in that same cycle for the caller to latch.
// The packet RAM reads ahead at the DMA address, in two banks of even and
// odd bytes, so a sixteen-bit DMA read has both its bytes to hand at once.
//
// The 16-bit DMA port's bytes are in address order here: the first byte
// in [15:8], as the big-endian bus wants them (the reference swaps the
// NE2000's little-endian word at the board for the same reason).
//
`default_nettype none

module dr840_ne2000 #(
    parameter [47:0] MAC = 48'h02_00_00_84_00_01
) (
    input  wire        clk,
    input  wire        cen,
    input  wire        rst_n,

    // ---- register access, one strobe an access
    input  wire        acc,
    input  wire        we,
    input  wire [4:0]  port,
    input  wire        wide,          // 16 bits, at the DMA port
    input  wire [15:0] wdata,         // a byte in [7:0]; a word first-byte-high
    output reg  [15:0] rdata,
    input  wire        board_reset,   // the COR's reset bit: the reset port's read
    output wire        irq,

    // ---- transmit: a frame in packet RAM, for the bridge to copy out
    output reg         tx_req,        // held until tx_done
    output reg  [13:0] tx_base,       // RAM offset of its first byte
    output reg  [10:0] tx_len,
    input  wire        tx_done,       // a strobe on cen
    input  wire        tx_ok,         // taken; else the carrier is lost

    // ---- receive: the bridge offers a frame, and streams it if accepted
    input  wire        rx_offer,      // a strobe on cen, with the two below
    input  wire [10:0] rx_len,        // without FCS
    input  wire [47:0] rx_dst,        // its first six bytes
    output reg         rx_answer,     // a strobe: rx_take says whether to stream it
    output reg         rx_take,
    input  wire        rx_byte,       // a strobe on cen, each byte in order
    input  wire [7:0]  rx_data,
    output wire        rx_busy,       // still storing; offer nothing until clear

    // ---- the bridge reads transmit bytes through here
    input  wire [13:0] b_addr,
    output wire [7:0]  b_q,

    output reg  [31:0] dbg_tx, dbg_rx
);

    // ------------------------------------------------------------ state
    reg [7:0]  cr, isr, imr, dcr, rcr, tcr, tsr, rsr;
    reg [7:0]  pstart, pstop, bnry, curr, tpsr;
    reg [7:0]  par [0:5];
    reg [7:0]  mar [0:7];
    reg [15:0] rsar, rbcr, tbcr;
    reg [7:0]  tally [0:2];
    reg        tx_pending;

    assign irq = |(isr & imr & 8'h7F);

    function [7:0] prom(input [4:0] a);       // 16 bytes, each twice
        case (a[4:1])
        4'd0: prom = MAC[47:40]; 4'd1: prom = MAC[39:32]; 4'd2: prom = MAC[31:24];
        4'd3: prom = MAC[23:16]; 4'd4: prom = MAC[15:8];  4'd5: prom = MAC[7:0];
        4'd14, 4'd15: prom = 8'h57;
        default: prom = 8'h00;
        endcase
    endfunction

    // ------------------------------------------------------------ packet RAM
    // Two banks of 8 KB: even bytes and odd. Port A is the CPU's remote
    // DMA, reading ahead at RSAR and RSAR+1; port B is receive's writes and
    // the bridge's transmit reads.
    // Nothing here reads a byte in the cycle it is written -- the read-ahead
    // is taken again on the next -- so the RAMs need no read-during-write
    // behaviour, and without saying so Quartus builds them from logic.
    (* ramstyle = "no_rw_check" *) reg [7:0] ram_e [0:8191];
    (* ramstyle = "no_rw_check" *) reg [7:0] ram_o [0:8191];

    // The byte after RSAR, wrapped at PSTOP as the DMA wraps.
    wire [15:0] rsar_n = (pstop > pstart && rsar + 16'd1 == {pstop, 8'd0}) ? {pstart, 8'd0} : rsar + 16'd1;
    // Which RAM byte each bank holds for the read-ahead: the even bank has
    // RSAR's byte when RSAR is even, else RSAR+1's.
    wire [15:0] ae = rsar[0] ? rsar_n : rsar;
    wire [15:0] ao = rsar[0] ? rsar   : rsar_n;
    reg  [7:0]  qa_e, qa_o;

    // Port A writes: a DMA byte, or two.
    reg         wa_e, wa_o;
    reg  [12:0] wa_e_i, wa_o_i;
    reg  [7:0]  wa_e_d, wa_o_d;

    // Port B: receive writes, or the bridge's reads.
    reg         wb;
    reg  [13:0] wb_a;
    reg  [7:0]  wb_d;
    reg  [7:0]  qb_e, qb_o;
    reg         b_lsb;
    wire [13:0] pb_a = wb ? wb_a : b_addr;      // a pending write has the port

    // One address a port: a write takes the port for its cycle, and the
    // read-ahead is back on the next.
    wire [12:0] pa_e = wa_e ? wa_e_i : ae[13:1];
    wire [12:0] pa_o = wa_o ? wa_o_i : ao[13:1];
    always @(posedge clk) begin
        if (wa_e) ram_e[pa_e] <= wa_e_d;
        qa_e <= ram_e[pa_e];
    end
    always @(posedge clk) begin
        if (wa_o) ram_o[pa_o] <= wa_o_d;
        qa_o <= ram_o[pa_o];
    end
    always @(posedge clk) begin
        if (wb && !wb_a[0]) ram_e[pb_a[13:1]] <= wb_d;
        qb_e <= ram_e[pb_a[13:1]];
    end
    always @(posedge clk) begin
        if (wb && wb_a[0]) ram_o[pb_a[13:1]] <= wb_d;
        qb_o <= ram_o[pb_a[13:1]];
    end
    always @(posedge clk) b_lsb <= pb_a[0];
    assign b_q = b_lsb ? qb_o : qb_e;

    // A byte of the DMA's address space, as read ahead: the PROM below 32,
    // packet RAM at 0x4000..0x7FFF, all ones elsewhere.
    function [7:0] space(input [15:0] a, input [7:0] ram_byte);
        space = (a < 16'd32) ? prom(a[4:0])
              : (a >= 16'h4000 && a < 16'h8000) ? ram_byte : 8'hFF;
    endfunction
    wire [7:0] b0 = space(rsar,   rsar[0] ? qa_o : qa_e);
    wire [7:0] b1 = space(rsar_n, rsar[0] ? qa_e : qa_o);
    wire       dma_rd_ok = (cr[5:3] == 3'b001) && (rbcr != 16'd0);
    wire       dma_wr_ok = (cr[5:3] == 3'b010) && (rbcr != 16'd0);

    // ------------------------------------------------------------ reads
    always @(*) begin
        rdata = 16'h00FF;
        if (port == 5'h10) begin
            // The second byte of a word needs a second count left.
            if (wide) rdata = {dma_rd_ok ? b0 : 8'hFF,
                               (dma_rd_ok && rbcr != 16'd1) ? b1 : 8'hFF};
            else      rdata = {8'h00, dma_rd_ok ? b0 : 8'hFF};
        end else if (wide)                 rdata = 16'hFFFF;
        else if (port == 5'h1F)            rdata = 16'h0000;
        else if (port == 5'h00)            rdata = {8'h00, cr};
        else if (port[4])                  rdata = 16'h00FF;
        else case (cr[7:6])
        2'd0: case (port[3:0])
              4'd3:  rdata = {8'h00, bnry};
              4'd4:  rdata = {8'h00, tsr};
              4'd5, 4'd6: rdata = 16'h0000;
              4'd7:  rdata = {8'h00, isr};
              4'd8:  rdata = {8'h00, rsar[7:0]};
              4'd9:  rdata = {8'h00, rsar[15:8]};
              4'd12: rdata = {8'h00, rsr};
              4'd13: rdata = {8'h00, tally[0]};
              4'd14: rdata = {8'h00, tally[1]};
              4'd15: rdata = {8'h00, tally[2]};
              default: rdata = 16'h00FF;
              endcase
        2'd1: if (port[3:0] <= 4'd6)      rdata = {8'h00, par[port[2:0] - 3'd1]};
              else if (port[3:0] == 4'd7) rdata = {8'h00, curr};
              else                        rdata = {8'h00, mar[port[2:0]]};
        2'd2: case (port[3:0])
              4'd1:  rdata = {8'h00, pstart};
              4'd2:  rdata = {8'h00, pstop};
              4'd4:  rdata = {8'h00, tpsr};
              4'd12: rdata = {8'h00, rcr};
              4'd13: rdata = {8'h00, tcr};
              4'd14: rdata = {8'h00, dcr};
              4'd15: rdata = {8'h00, imr};
              default: rdata = 16'h00FF;
              endcase
        default: rdata = 16'h00FF;
        endcase
    end

    // ------------------------------------------------------------ receive
    // The multicast hash: the top six bits of the non-reflected CRC of the
    // destination, fed LSB first.
    function [5:0] mhash(input [47:0] d);
        integer i;
        reg [31:0] c;
        reg [7:0]  by;
        begin
            c = 32'hFFFF_FFFF;
            for (i = 0; i < 48; i = i + 1) begin
                by = d[47 - 8 * (i / 8) -: 8];
                if (c[31] ^ by[i % 8]) c = {c[30:0], 1'b0} ^ 32'h04C1_1DB7;
                else                   c = {c[30:0], 1'b0};
            end
            mhash = c[31:26];
        end
    endfunction
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

    // The offer's verdict, a stage after it: the filter, then room.
    reg        off_q;
    reg [10:0] off_len;
    reg [47:0] off_dst;
    reg [5:0]  off_hash;        // taken with the offer: the CRC is long
    wire       o_bcast = (off_dst == 48'hFFFF_FFFF_FFFF);
    wire       o_group = off_dst[40];
    wire [5:0] o_hash  = off_hash;
    wire [7:0] o_marb  = mar[o_hash[5:3]];
    wire       o_par   = (off_dst == {par[0], par[1], par[2], par[3], par[4], par[5]});
    wire       o_acc   = o_bcast ? rcr[2] : o_group ? (rcr[3] && o_marb[o_hash[2:0]]) : (rcr[4] || o_par);
    wire [10:0] o_pad  = (off_len < 11'd60) ? 11'd60 : off_len;
    wire [11:0] o_cnt  = {1'b0, o_pad} + 12'd4;               // with FCS
    wire [7:0]  o_pages = 8'((o_cnt + 12'd4 + 12'd255) >> 8);
    wire        o_ring_ok = !(pstart < 8'h40 || pstop > 8'h80 || pstart >= pstop || curr < pstart || curr >= pstop);
    wire        o_bnry_in = (bnry >= pstart && bnry < pstop);
    wire [8:0]  o_avail = (bnry > curr) ? {1'b0, bnry - curr} : {1'b0, pstop - curr} + {1'b0, bnry - pstart};
    wire [8:0]  o_next0 = {1'b0, curr} + {1'b0, o_pages};
    wire [7:0]  o_next  = (o_next0 >= {1'b0, pstop}) ? 8'(o_next0 - {1'b0, pstop - pstart}) : o_next0[7:0];

    // Storing: the frame from page CURR + 4, the padding, the FCS, then
    // the four-byte header at the page's start.
    localparam [2:0] R_IDLE = 3'd0, R_DATA = 3'd1, R_PAD = 3'd2, R_FCS = 3'd3, R_HDR = 3'd4;
    reg [2:0]  r_st;
    reg [15:0] r_ptr;           // the next byte's address
    reg [10:0] r_n, r_len, r_pad;
    reg [11:0] r_cnt;
    reg [7:0]  r_next, r_page;
    reg        r_group;
    reg [31:0] r_crc;
    reg [1:0]  r_k;
    assign rx_busy = (r_st != R_IDLE) || off_q;
    wire [15:0] r_ptr_n = (r_ptr + 16'd1 == {pstop, 8'd0}) ? {pstart, 8'd0} : r_ptr + 16'd1;

    // ------------------------------------------------------------ transmit
    reg [15:0] tx_wait;
    reg        tx_copied, tx_copied_ok;

    // ------------------------------------------------------------ the rest
    reg [7:0] v;
    reg       started;
    reg [7:0] iset, iclr;       // this cycle's interrupt events and acknowledgements
    reg       nreset;           // and whether the chip was reset
    integer   i;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cr <= 8'h21; isr <= 8'h80; imr <= 8'd0; dcr <= 8'd4; rcr <= 8'd0; tcr <= 8'd0;
            tsr <= 8'd0; rsr <= 8'd0; pstart <= 8'd0; pstop <= 8'd0; bnry <= 8'd0; curr <= 8'd0;
            tpsr <= 8'd0; rsar <= 16'd0; rbcr <= 16'd0; tbcr <= 16'd0; tx_pending <= 1'b0;
            for (i = 0; i < 6; i = i + 1) par[i] <= 8'd0;
            for (i = 0; i < 8; i = i + 1) mar[i] <= 8'd0;
            for (i = 0; i < 3; i = i + 1) tally[i] <= 8'd0;
            wa_e <= 1'b0; wa_o <= 1'b0; wa_e_i <= 13'd0; wa_o_i <= 13'd0; wa_e_d <= 8'd0; wa_o_d <= 8'd0;
            wb <= 1'b0; wb_a <= 14'd0; wb_d <= 8'd0;
            tx_req <= 1'b0; tx_base <= 14'd0; tx_len <= 11'd0; tx_wait <= 16'd0;
            tx_copied <= 1'b0; tx_copied_ok <= 1'b0;
            off_q <= 1'b0; off_len <= 11'd0; off_dst <= 48'd0; off_hash <= 6'd0; rx_answer <= 1'b0; rx_take <= 1'b0;
            r_st <= R_IDLE; r_ptr <= 16'd0; r_n <= 11'd0; r_len <= 11'd0; r_pad <= 11'd0;
            r_cnt <= 12'd0; r_next <= 8'd0; r_page <= 8'd0; r_group <= 1'b0; r_crc <= 32'd0; r_k <= 2'd0;
            dbg_tx <= 32'd0; dbg_rx <= 32'd0;
        end else begin
            wa_e <= 1'b0; wa_o <= 1'b0; wb <= 1'b0;
            if (cen) begin
                rx_answer <= 1'b0;
                iset = 8'd0; iclr = 8'd0; nreset = 1'b0;

                // -------------------------------------------- register access
                if (acc) begin
                    if (port == 5'h10) begin
                        if (!we) begin
                            // One or two bytes read, each advancing.
                            if (dma_rd_ok) begin
                                if (wide && rbcr != 16'd1) begin
                                    rsar <= (pstop > pstart && rsar_n + 16'd1 == {pstop, 8'd0}) ? {pstart, 8'd0} : rsar_n + 16'd1;
                                    rbcr <= rbcr - 16'd2;
                                    if (rbcr == 16'd2) iset = iset | 8'h40;
                                end else begin
                                    rsar <= rsar_n;
                                    rbcr <= rbcr - 16'd1;
                                    if (rbcr == 16'd1) iset = iset | 8'h40;
                                end
                            end
                        end else if (dma_wr_ok) begin
                            // The first byte at RSAR, the second after it.
                            if (rsar >= 16'h4000 && rsar < 16'h8000) begin
                                if (rsar[0]) begin wa_o <= 1'b1; wa_o_i <= rsar[13:1]; wa_o_d <= wide ? wdata[15:8] : wdata[7:0]; end
                                else         begin wa_e <= 1'b1; wa_e_i <= rsar[13:1]; wa_e_d <= wide ? wdata[15:8] : wdata[7:0]; end
                            end
                            if (wide && rbcr != 16'd1) begin
                                if (rsar_n >= 16'h4000 && rsar_n < 16'h8000) begin
                                    if (rsar_n[0]) begin wa_o <= 1'b1; wa_o_i <= rsar_n[13:1]; wa_o_d <= wdata[7:0]; end
                                    else           begin wa_e <= 1'b1; wa_e_i <= rsar_n[13:1]; wa_e_d <= wdata[7:0]; end
                                end
                                rsar <= (pstop > pstart && rsar_n + 16'd1 == {pstop, 8'd0}) ? {pstart, 8'd0} : rsar_n + 16'd1;
                                rbcr <= rbcr - 16'd2;
                                if (rbcr == 16'd2) iset = iset | 8'h40;
                            end else begin
                                rsar <= rsar_n;
                                rbcr <= rbcr - 16'd1;
                                if (rbcr == 16'd1) iset = iset | 8'h40;
                            end
                        end
                    end else if (!we && !wide && port == 5'h1F) begin
                        nreset = 1'b1;          // the reset port
                    end else if (!we && !wide && port[4:2] == 3'b011 && cr[7:6] == 2'd0 && port[1:0] != 2'd0) begin
                        tally[port[1:0] - 2'd1] <= 8'd0;          // 13..15 clear on read
                    end else if (we && !wide && port == 5'h00) begin
                        v = wdata[7:0];
                        started = cr[1];
                        cr <= (v & 8'hFB) | (tx_pending ? 8'h04 : 8'h00) | ((v[0]) ? {6'd0, started, 1'b0} : 8'h00);
                        if (v[0]) begin
                            if (!tx_pending) iset = iset | 8'h80;
                        end else if (v[1]) iclr = iclr | 8'h80;
                        if (v[5:3] == 3'b001 && rbcr == 16'd0) iset = iset | 8'h40;
                        // Transmit, if asked and started (as written).
                        if (v[2] && ((((v & 8'hFB) | (v[0] ? {6'd0, started, 1'b0} : 8'h00)) & 8'h03) == 8'h02)
                            && !tx_pending) begin
                            if ({tpsr, 8'd0} < 16'h4000 || {tpsr, 8'd0} + tbcr > 16'h8000 ||
                                tbcr < 16'd14 || tbcr > 16'd1518) begin
                                tsr <= 8'h08; iset = iset | 8'h08;
                                cr  <= ((v & 8'hFB) | (v[0] ? {6'd0, started, 1'b0} : 8'h00));
                            end else begin
                                cr <= (v & 8'hFB) | (v[0] ? {6'd0, started, 1'b0} : 8'h00) | 8'h04;
                                tx_pending <= 1'b1;
                                tx_req  <= 1'b1;
                                tx_base <= {tpsr[5:0], 8'd0};
                                tx_len  <= tbcr[10:0];
                                // 10 Mbit/s, with preamble, FCS and gap:
                                // 0.8 us a byte, 36.8 core edges.
                                tx_wait <= 16'((tbcr + 16'd24) * 16'd37);
                                tx_copied <= 1'b0;
                            end
                        end
                    end else if (we && !wide && !port[4]) begin
                        v = wdata[7:0];
                        case (cr[7:6])
                        2'd0: case (port[3:0])
                              4'd1:  pstart <= v;
                              4'd2:  pstop  <= v;
                              4'd3:  bnry   <= v;
                              4'd4:  tpsr   <= v;
                              4'd5:  tbcr[7:0]  <= v;
                              4'd6:  tbcr[15:8] <= v;
                              4'd7:  iclr   = iclr | (v & 8'h7F);
                              4'd8:  rsar[7:0]  <= v;
                              4'd9:  rsar[15:8] <= v;
                              4'd10: rbcr[7:0]  <= v;
                              4'd11: rbcr[15:8] <= v;
                              4'd12: rcr    <= v;
                              4'd13: tcr    <= v;
                              4'd14: dcr    <= v;
                              4'd15: imr    <= v & 8'h7F;
                              default: ;
                              endcase
                        2'd1: if (port[3:0] >= 4'd1 && port[3:0] <= 4'd6) par[port[2:0] - 3'd1] <= v;
                              else if (port[3:0] == 4'd7) curr <= v;
                              else if (port[3:0] >= 4'd8) mar[port[2:0]] <= v;
                        default: ;
                        endcase
                    end
                end
                if (board_reset) nreset = 1'b1;

                // -------------------------------------------- transmit
                if (tx_req && tx_done) begin
                    tx_req <= 1'b0; tx_copied <= 1'b1; tx_copied_ok <= tx_ok;
                end
                if (tx_pending && tx_wait != 16'd0) tx_wait <= tx_wait - 16'd1;
                if (tx_pending && tx_copied && tx_wait == 16'd0 && !(acc && we && port == 5'h00)) begin
                    tx_pending <= 1'b0; tx_copied <= 1'b0;
                    cr  <= cr & 8'hFB;
                    tsr <= tx_copied_ok ? 8'h01 : 8'h10;
                    iset = iset | (tx_copied_ok ? 8'h02 : 8'h08) | (cr[0] ? 8'h80 : 8'h00);
                    if (tx_copied_ok) dbg_tx <= dbg_tx + 32'd1;
                end

                // -------------------------------------------- receive
                if (rx_offer && !rx_busy) begin
                    off_q <= 1'b1; off_len <= rx_len; off_dst <= rx_dst; off_hash <= mhash(rx_dst);
                end
                if (off_q) begin
                    off_q <= 1'b0;
                    rx_answer <= 1'b1; rx_take <= 1'b0;
                    if (cr[1:0] != 2'b10 || off_len < 11'd14 || off_len > 11'd1518) begin
                        // not started, or not a frame: dropped unseen
                    end else if (!o_acc) begin
                        // filtered
                    end else if (rcr[5]) begin
                        if (tally[2] == 8'h7F) iset = iset | 8'h20;
                        tally[2] <= tally[2] + 8'd1;
                    end else if (!o_ring_ok) begin
                        // unsupported ring
                    end else if (isr[4] || (o_bnry_in && {1'b0, o_pages} >= o_avail)) begin
                        iset = iset | 8'h10; rsr <= 8'h10;
                        if (tally[2] == 8'h7F) iset = iset | 8'h20;
                        tally[2] <= tally[2] + 8'd1;
                    end else begin
                        rx_take <= 1'b1;
                        r_st <= R_DATA; r_len <= off_len; r_n <= 11'd0; r_pad <= o_pad;
                        r_cnt <= o_cnt; r_next <= o_next; r_page <= curr; r_group <= o_group;
                        r_ptr <= {curr, 8'd4}; r_crc <= 32'hFFFF_FFFF; r_k <= 2'd0;
                    end
                end
                case (r_st)
                R_DATA: if (rx_byte) begin
                    wb <= 1'b1; wb_a <= r_ptr[13:0]; wb_d <= rx_data;
                    r_crc <= crc8(r_crc, rx_data);
                    r_ptr <= r_ptr_n; r_n <= r_n + 11'd1;
                    if (r_n + 11'd1 == r_len) r_st <= (r_len < r_pad) ? R_PAD : R_FCS;
                end
                R_PAD: begin
                    wb <= 1'b1; wb_a <= r_ptr[13:0]; wb_d <= 8'd0;
                    r_crc <= crc8(r_crc, 8'd0);
                    r_ptr <= r_ptr_n; r_n <= r_n + 11'd1;
                    if (r_n + 11'd1 == r_pad) r_st <= R_FCS;
                end
                R_FCS: begin
                    // The complement, least significant byte first.
                    wb <= 1'b1; wb_a <= r_ptr[13:0];
                    wb_d <= ~r_crc[8 * r_k +: 8];
                    r_ptr <= r_ptr_n; r_k <= r_k + 2'd1;
                    if (r_k == 2'd3) begin r_st <= R_HDR; r_k <= 2'd0; end
                end
                R_HDR: begin
                    wb <= 1'b1; wb_a <= {r_page[5:0], 6'd0, r_k};
                    wb_d <= (r_k == 2'd0) ? (8'h01 | (r_group ? 8'h20 : 8'h00))
                          : (r_k == 2'd1) ? r_next
                          : (r_k == 2'd2) ? r_cnt[7:0] : {4'd0, r_cnt[11:8]};
                    r_k <= r_k + 2'd1;
                    if (r_k == 2'd3) begin
                        r_st <= R_IDLE;
                        curr <= r_next; rsr <= 8'h01 | (r_group ? 8'h20 : 8'h00);
                        iset = iset | 8'h01;
                        dbg_rx <= dbg_rx + 32'd1;
                    end
                end
                default: ;
                endcase

                // -------------------------------------------- the ISR, and reset
                isr <= (isr & ~iclr) | iset;
                if (nreset) begin
                    cr <= 8'h21; isr <= 8'h80; imr <= 8'd0; rbcr <= 16'd0; tsr <= 8'd0; rsr <= 8'd0;
                    tx_pending <= 1'b0; tx_req <= 1'b0; tx_copied <= 1'b0;
                    for (i = 0; i < 3; i = i + 1) tally[i] <= 8'd0;
                end
            end
        end
    end
endmodule

`default_nettype wire
