//
// dr840_mem.sv - the DataRover's address decode, and the arbiter that puts
// the two cache ports onto one memory.
//
// The map is the reference's, which prints it at startup:
//
//   00000000-03BFFFFF  DRAM, 4 MB fitted across a 60 MB decode
//   03C00000-043FFFFF  flash
//   13C00000-143FFFFF  flash again, the second chip select; the OS runs here
//   1FC00000-1FFFFFFF  flash again, the reset alias
//   10400000-107FFFFF  PC Card controller, slot 0
//   10800000-10BFFFFF  PC Card controller, slot 1
//   10C00000-10C003FF  TX39 on-chip peripherals
//   08000000-0BFFFFFF  card 1 window A      0C000000-0FFFFFFF  card 2 window A
//   24000000-27FFFFFF  card 1 window B      28000000-2BFFFFFF  card 2 window B
//   FF000000-FF000FFF  the unidentified chip in kseg3
//
// Anything else is a bus error, which is how the ROM's own probes find out
// what is not there.
//
// RAM and flash both live in the one SDRAM, ROM at its base and DRAM above
// it, so a single chip serves both and the HPS can load the ROM into it
// before the core is let out of reset.
//
// One deliberate difference from the reference: a chip select mirrors its
// contents through the space it decodes, and the reference does that with a
// real modulo of the installed size -- 4,528,151 bytes, not a power of two.
// Here the window is masked to 8 MB instead, so an access past the end of
// the image reads whatever the SDRAM holds there rather than wrapping. In
// ten million instructions from reset nothing reads past the image at all
// (the furthest is its very last byte), and the ROM does not use mirroring
// to discover its size -- it does not discover it at all, it is a constant.
// A real modulo would be a 32-bit divide on the path to memory.
//
`default_nettype none

module dr840_mem #(
    // Where each thing sits in the SDRAM.
    parameter [24:0] ROM_BASE  = 25'h000_0000,   // 8 MB
    parameter [24:0] DRAM_BASE = 25'h080_0000    // 4 MB
) (
    input  wire        clk,
    input  wire        cen,          // the requesters' clock enable
    input  wire        rst_n,

    // ---- from the caches
    input  wire [31:0] imem_addr,
    input  wire        imem_req,
    input  wire        imem_burst,
    output wire        imem_ack,
    output wire [31:0] imem_rdata,
    output wire        imem_err,

    input  wire [31:0] dmem_addr,
    input  wire        dmem_req,
    input  wire        dmem_burst,
    input  wire        dmem_we,
    input  wire [3:0]  dmem_be,
    input  wire [31:0] dmem_wdata,
    output wire        dmem_ack,
    output wire [31:0] dmem_rdata,
    output wire        dmem_err,

    // ---- from the LCD controller: reads only, always bursts, physical
    // addresses like the others, and last in line.
    input  wire [31:0] vmem_addr,
    input  wire        vmem_req,
    output wire        vmem_ack,
    output wire [31:0] vmem_rdata,

    // The sound: one word every frame, after the LCD and before the caches.
    input  wire [31:0] amem_addr,
    input  wire        amem_req,
    output wire        amem_ack,
    output wire [31:0] amem_rdata,

    // The Magic Bus's receive DMA: words written, after the sound.
    input  wire [31:0] kmem_addr,
    input  wire        kmem_req,
    input  wire        kmem_we,
    input  wire [31:0] kmem_wdata,
    output wire        kmem_ack,

    // The package link (dr840_pclink.sv): the package as the loader
    // writes it and as the link reads it back. An SDRAM address, not a
    // guest one -- the package is nowhere in the guest's map.
    input  wire [24:0] pmem_addr,
    input  wire        pmem_req,
    input  wire        pmem_we,
    input  wire [31:0] pmem_wdata,
    output wire        pmem_ack,
    output wire [31:0] pmem_rdata,

    // The PC Cards: a memory card in a slot puts its common memory in
    // that slot's window B, which is then RAM -- a region of the SDRAM
    // above the DRAM, mirrored through the window by the card's size.
    // Window A, the attribute space, stays with the peripheral block,
    // which answers with the card's CIS.
    input  wire [1:0]  card_present,
    input  wire [21:0] card_mask0,       // size - 1 of the card in slot 1
    input  wire [21:0] card_mask1,       // and in slot 2

    // ---- to SDRAM
    output wire [24:0] ram_addr,
    output wire        ram_req,
    output wire        ram_burst,
    output wire        ram_we,
    output wire [3:0]  ram_be,
    output wire [31:0] ram_wdata,
    input  wire        ram_ack,
    input  wire [31:0] ram_rdata,
    // Whether the memory still has a transaction of ours in it.
    input  wire        ram_busy,

    // ---- to the peripheral bus, physical addresses, never cached
    output wire [31:0] io_addr,
    output wire        io_req,
    output wire        io_we,
    output wire [3:0]  io_be,
    output wire [31:0] io_wdata,
    input  wire        io_ack,
    input  wire [31:0] io_rdata,
    input  wire        io_err
);

    localparam [1:0] T_RAM = 2'd0, T_IO = 2'd1, T_NONE = 2'd2;

    // Decode. Returns where the access goes and, for memory, where in the
    // SDRAM it lands.
    function [26:0] decode(input [31:0] pa);
        reg [1:0]  t;
        reg [24:0] off;
        reg [31:0] rel;
        begin
            t   = T_NONE;
            off = 25'd0;
            rel = 32'd0;
            if (pa < 32'h03C0_0000) begin
                // 4 MB fitted, mirroring through a 60 MB decode.
                t = T_RAM;  off = DRAM_BASE | {3'd0, pa[21:0]};
            end else if (pa < 32'h0440_0000) begin
                rel = pa - 32'h03C0_0000;
                t = T_RAM;  off = ROM_BASE | {2'd0, rel[22:0]};
            end else if (pa >= 32'h13C0_0000 && pa < 32'h1440_0000) begin
                rel = pa - 32'h13C0_0000;
                t = T_RAM;  off = ROM_BASE | {2'd0, rel[22:0]};
            end else if (pa >= 32'h1FC0_0000 && pa < 32'h2000_0000) begin
                // The reset alias decodes 4 MB, so it reaches only the
                // first 4 MB of the image. That is the reference's window
                // too, and the reset code does not run past it.
                t = T_RAM;  off = ROM_BASE | {3'd0, pa[21:0]};
            end else if (pa >= 32'h1040_0000 && pa < 32'h10C0_0400) begin
                t = T_IO;                          // both card controllers
            end else if (pa >= 32'h0800_0000 && pa < 32'h1000_0000) begin
                t = T_IO;                          // card windows A
            end else if (pa >= 32'h2400_0000 && pa < 32'h2C00_0000) begin
                t = T_IO;                          // card windows B
            end else if (pa >= 32'hFF00_0000 && pa < 32'hFF00_1000) begin
                t = T_IO;                          // the kseg3 chip
            end
            decode = {t, off};
        end
    endfunction

    // A card's memory, when the address is in its window and it is there.
    // The card's presence and size are registered here, on the core's
    // edges: they come from the top level's registers, which no timing
    // group covers, and straight into the decode they cost two nanoseconds.
    localparam [24:0] CARD1_BASE = 25'h0C0_0000, CARD2_BASE = 25'h0E0_0000;
    reg  [1:0]  cp_q;
    reg  [21:0] cm0_q, cm1_q;
    always @(posedge clk) if (cen) begin cp_q <= card_present; cm0_q <= card_mask0; cm1_q <= card_mask1; end
    function [26:0] decode_card(input [31:0] pa);
        reg [26:0] d;
        begin
            d = decode(pa);
            if (pa >= 32'h2400_0000 && pa < 32'h2800_0000 && cp_q[0])
                d = {T_RAM, CARD1_BASE | {3'd0, pa[21:0] & cm0_q}};
            else if (pa >= 32'h2800_0000 && pa < 32'h2C00_0000 && cp_q[1])
                d = {T_RAM, CARD2_BASE | {3'd0, pa[21:0] & cm1_q}};
            decode_card = d;
        end
    endfunction
    wire [26:0] i_dec = decode_card(imem_addr);
    wire [26:0] d_dec = decode_card(dmem_addr);
    wire [26:0] v_dec = decode(vmem_addr);
    wire [26:0] a_dec = decode(amem_addr);
    wire [1:0]  a_tgt = a_dec[26:25];
    wire [26:0] k_dec = decode(kmem_addr);
    wire [1:0]  k_tgt = k_dec[26:25];
    wire [1:0]  i_tgt = i_dec[26:25];
    wire [1:0]  d_tgt = d_dec[26:25];
    wire [1:0]  v_tgt = v_dec[26:25];

    // ------------------------------------------------------------ arbiter

    // Data wins. It is the older instruction: anything in MEM was fetched
    // before whatever IF is asking for, and making the younger access wait
    // is free where making the older one wait is not.
    //
    // A burst holds the grant. The cache keeps its request asserted for all
    // four beats, so the grant follows the request rather than a counter.
    //
    // The grant also has to outlive the request. A requester can stop asking
    // while its access is still in the memory -- an instruction fetch does
    // exactly that when the data cache misses, because the stall reaches
    // back and the fetch stage stops asking for anything. If the grant went
    // with it, the acknowledgement for that fetch would arrive after the
    // arbiter had moved on and be handed to the data side, which would take
    // it as the first word of its own line. Every word after that lands one
    // slot late and the line is quietly wrong.
    // The LCD goes first. It asks for one burst at a time and drops its
    // request in between, so it takes the memory for sixteen bytes and
    // gives it back: eight of those per raster line, against the three
    // thousand clocks a raster line lasts, is about six percent of the
    // memory and it is never more. Last in line it would instead depend on
    // both caches being idle in the same cycle, which is not something the
    // picture should have to hope for.
    localparam [2:0] A_FREE = 3'd0, A_DATA = 3'd1, A_INSN = 3'd2, A_LCD = 3'd3, A_SND = 3'd4,
                     A_KBD = 3'd5, A_PKG = 3'd6;
    reg [2:0] owner;

    wire d_wants_ram = dmem_req && (d_tgt == T_RAM);
    wire i_wants_ram = imem_req && (i_tgt == T_RAM);
    wire v_wants_ram = vmem_req && (v_tgt == T_RAM);
    wire a_wants_ram = amem_req && (a_tgt == T_RAM);
    wire k_wants_ram = kmem_req && (k_tgt == T_RAM);
    wire p_wants_ram = pmem_req;

    wire grant_v = (owner == A_LCD) || ((owner == A_FREE) && v_wants_ram);
    wire grant_a = (owner == A_SND) ||
                   ((owner == A_FREE) && !v_wants_ram && a_wants_ram);
    wire grant_k = (owner == A_KBD) ||
                   ((owner == A_FREE) && !v_wants_ram && !a_wants_ram && k_wants_ram);
    wire grant_p = (owner == A_PKG) ||
                   ((owner == A_FREE) && !v_wants_ram && !a_wants_ram && !k_wants_ram && p_wants_ram);
    wire grant_d = (owner == A_DATA) ||
                   ((owner == A_FREE) && !v_wants_ram && !a_wants_ram && !k_wants_ram && !p_wants_ram && d_wants_ram);
    wire grant_i = (owner == A_INSN) ||
                   ((owner == A_FREE) && !v_wants_ram && !a_wants_ram && !k_wants_ram && !p_wants_ram && !d_wants_ram && i_wants_ram);

    // On the core's edges, like everything it arbitrates between. Every
    // input here changes only on one: the requests come from registers the
    // core enables, and `ram_busy` is the adapter's state, which starts and
    // ends transactions on enabled edges and nowhere else. So this is the
    // same machine, evaluated at the same moments -- the edges in between
    // only ever recomputed what it already held.
    //
    // What it buys is honesty in the .sdc. Clocked every cycle, this was
    // the tightest path in the design by an order of magnitude: the core's
    // MEM address, through the decode, into these three bits, ten
    // nanoseconds against one period, with two tenths to spare while
    // everything else had two whole nanoseconds. A grant is not a thing to
    // latch wrong occasionally -- it hands one requester's memory to
    // another, which is a cache line of somebody else's data and a pointer
    // made of it.
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            owner <= A_FREE;
        else if (cen) case (owner)
            A_FREE: if (v_wants_ram)      owner <= A_LCD;
                    else if (a_wants_ram) owner <= A_SND;
                    else if (k_wants_ram) owner <= A_KBD;
                    else if (p_wants_ram) owner <= A_PKG;
                    else if (d_wants_ram) owner <= A_DATA;
                    else if (i_wants_ram) owner <= A_INSN;
            A_DATA: if (!d_wants_ram && !ram_busy) owner <= A_FREE;
            A_INSN: if (!i_wants_ram && !ram_busy) owner <= A_FREE;
            A_LCD:  if (!v_wants_ram && !ram_busy) owner <= A_FREE;
            A_SND:  if (!a_wants_ram && !ram_busy) owner <= A_FREE;
            A_KBD:  if (!k_wants_ram && !ram_busy) owner <= A_FREE;
            A_PKG:  if (!p_wants_ram && !ram_busy) owner <= A_FREE;
            default:                      owner <= A_FREE;
        endcase
    end

    assign ram_req   = (grant_d & d_wants_ram) | (grant_i & i_wants_ram)
                     | (grant_v & v_wants_ram) | (grant_a & a_wants_ram) | (grant_k & k_wants_ram)
                     | (grant_p & p_wants_ram);
    assign ram_addr  = grant_d ? d_dec[24:0] : grant_i ? i_dec[24:0] : grant_a ? a_dec[24:0]
                     : grant_k ? k_dec[24:0] : grant_p ? pmem_addr : v_dec[24:0];
    assign ram_burst = grant_d ? dmem_burst  : grant_i ? imem_burst  : (grant_a || grant_k || grant_p) ? 1'b0 : 1'b1;

    assign ram_we    = grant_d ? dmem_we     : grant_k ? kmem_we : grant_p ? pmem_we : 1'b0;
    assign ram_be    = 4'b1111 & (grant_d ? dmem_be : 4'b1111);
    assign ram_wdata = grant_k ? kmem_wdata : grant_p ? pmem_wdata : dmem_wdata;

    assign vmem_ack   = grant_v & v_wants_ram & ram_ack;
    assign vmem_rdata = ram_rdata;
    assign amem_ack   = grant_a & a_wants_ram & ram_ack;
    assign amem_rdata = ram_rdata;
    assign kmem_ack   = grant_k & k_wants_ram & ram_ack;
    assign pmem_ack   = grant_p & p_wants_ram & ram_ack;
    assign pmem_rdata = ram_rdata;

    // ------------------------------------------------- peripherals

    // Only the data side reaches these in practice, but an instruction
    // fetch from them is decoded rather than quietly dropped.
    wire d_wants_io = dmem_req && (d_tgt == T_IO);
    wire i_wants_io = imem_req && (i_tgt == T_IO);

    assign io_req   = d_wants_io | (i_wants_io & ~d_wants_io);
    assign io_addr  = d_wants_io ? dmem_addr : imem_addr;
    assign io_we    = d_wants_io ? dmem_we   : 1'b0;
    assign io_be    = d_wants_io ? dmem_be   : 4'b1111;
    assign io_wdata = dmem_wdata;

    // ------------------------------------------------------------ replies

    assign dmem_ack   = (grant_d & d_wants_ram & ram_ack)
                      | (d_wants_io & io_ack)
                      | (dmem_req & (d_tgt == T_NONE));
    // Which side's data to hand back is decided from the decode, but one
    // edge late, from a register. Both replies come from registers and
    // neither can arrive on the first enabled edge after a request, so the
    // choice is always made in time -- and it takes the decode off the
    // path from the memory's reply into the core.
    reg d_from_io, i_from_io;
    always @(posedge clk) if (cen) begin
        d_from_io <= d_wants_io;
        i_from_io <= i_wants_io & ~d_wants_io;
    end
    assign dmem_rdata = d_from_io ? io_rdata : ram_rdata;
    assign dmem_err   = (dmem_req & (d_tgt == T_NONE))
                      | (d_wants_io & io_ack & io_err);

    assign imem_ack   = (grant_i & i_wants_ram & ram_ack)
                      | (i_wants_io & ~d_wants_io & io_ack)
                      | (imem_req & (i_tgt == T_NONE));
    assign imem_rdata = i_from_io ? io_rdata : ram_rdata;
    assign imem_err   = (imem_req & (i_tgt == T_NONE))
                      | (i_wants_io & ~d_wants_io & io_ack & io_err);

endmodule

`default_nettype wire
