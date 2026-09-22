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

    // The decode is registered, and trusted only once the address it was
    // made from has stood for a clock. It is a chain of range comparisons,
    // and combinational it sat on the longest path in the machine: from a
    // cache's fill address, through here, into the acknowledgement, up the
    // stall network to the fetch redirect and down into the instruction
    // cache's RAM address -- 24.5 ns, against the 21.7 the core gets. The
    // requesters hold an address for a whole core period and everything
    // that acts on this samples on the core's edges, so a clock of latency
    // here is invisible; the qualifier only guards the one clock in which
    // the register still describes the previous address.
    reg [26:0] i_dec, d_dec;
    reg [31:0] i_addr_r, d_addr_r;
    always @(posedge clk) begin
        i_dec    <= decode(imem_addr);
        d_dec    <= decode(dmem_addr);
        i_addr_r <= imem_addr;
        d_addr_r <= dmem_addr;
    end
    wire i_dec_ok = (i_addr_r == imem_addr);
    wire d_dec_ok = (d_addr_r == dmem_addr);
    wire [1:0]  i_tgt = i_dec[26:25];
    wire [1:0]  d_tgt = d_dec[26:25];

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
    localparam [1:0] A_FREE = 2'd0, A_DATA = 2'd1, A_INSN = 2'd2;
    reg [1:0] owner;

    wire d_wants_ram = dmem_req && d_dec_ok && (d_tgt == T_RAM);
    wire i_wants_ram = imem_req && i_dec_ok && (i_tgt == T_RAM);

    wire grant_d = (owner == A_DATA) || ((owner == A_FREE) && d_wants_ram);
    wire grant_i = (owner == A_INSN) ||
                   ((owner == A_FREE) && !d_wants_ram && i_wants_ram);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            owner <= A_FREE;
        else case (owner)
            A_FREE: if (d_wants_ram)      owner <= A_DATA;
                    else if (i_wants_ram) owner <= A_INSN;
            A_DATA: if (!d_wants_ram && !ram_busy) owner <= A_FREE;
            A_INSN: if (!i_wants_ram && !ram_busy) owner <= A_FREE;
            default:                      owner <= A_FREE;
        endcase
    end

    assign ram_req   = (grant_d & d_wants_ram) | (grant_i & i_wants_ram);
    assign ram_addr  = grant_d ? d_dec[24:0] : i_dec[24:0];
    assign ram_burst = grant_d ? dmem_burst  : imem_burst;
    assign ram_we    = grant_d ? dmem_we     : 1'b0;
    assign ram_be    = grant_d ? dmem_be     : 4'b1111;
    assign ram_wdata = dmem_wdata;

    // ------------------------------------------------- peripherals

    // Only the data side reaches these in practice, but an instruction
    // fetch from them is decoded rather than quietly dropped.
    wire d_wants_io = dmem_req && d_dec_ok && (d_tgt == T_IO);
    wire i_wants_io = imem_req && i_dec_ok && (i_tgt == T_IO);

    assign io_req   = d_wants_io | (i_wants_io & ~d_wants_io);
    assign io_addr  = d_wants_io ? dmem_addr : imem_addr;
    assign io_we    = d_wants_io ? dmem_we   : 1'b0;
    assign io_be    = d_wants_io ? dmem_be   : 4'b1111;
    assign io_wdata = dmem_wdata;

    // ------------------------------------------------------------ replies

    wire d_none = dmem_req & d_dec_ok & (d_tgt == T_NONE);
    wire i_none = imem_req & i_dec_ok & (i_tgt == T_NONE);

    assign dmem_ack   = (grant_d & d_wants_ram & ram_ack)
                      | (d_wants_io & io_ack)
                      | d_none;
    assign dmem_rdata = d_wants_io ? io_rdata : ram_rdata;
    assign dmem_err   = d_none
                      | (d_wants_io & io_ack & io_err);

    assign imem_ack   = (grant_i & i_wants_ram & ram_ack)
                      | (i_wants_io & ~d_wants_io & io_ack)
                      | i_none;
    assign imem_rdata = (i_wants_io & ~d_wants_io) ? io_rdata : ram_rdata;
    assign imem_err   = i_none
                      | (i_wants_io & ~d_wants_io & io_ack & io_err);

endmodule

`default_nettype wire
