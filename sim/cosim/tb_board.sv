// The core, its caches and the board's address decode, with the two sides
// the rest of the machine has to provide: one memory and one peripheral
// bus. Nothing here is synthesised.
`default_nettype none

module tb_board (
    input  wire        clk,
    input  wire        rst_n,

    output wire [24:0] ram_addr,
    output wire        ram_req,
    output wire        ram_burst,
    output wire        ram_we,
    output wire [3:0]  ram_be,
    output wire [31:0] ram_wdata,
    input  wire        ram_ack,
    input  wire [31:0] ram_rdata,

    output wire [31:0] io_addr,
    output wire        io_req,
    output wire        io_we,
    output wire [3:0]  io_be,
    output wire [31:0] io_wdata,
    input  wire        io_ack,
    input  wire [31:0] io_rdata,
    input  wire        io_err,

    input  wire [5:0]  irq_in,

    output wire        retire_valid,
    output wire [31:0] retire_pc,
    output wire [31:0] retire_insn,
    output wire [31:0] retire_next_pc,
    output wire [31:0] ihit_count,
    output wire [31:0] imiss_count,
    output wire [31:0] dhit_count,
    output wire [31:0] dmiss_count
);
    wire [31:0] ia, ird, da, dwd, drd;
    wire        ireq, ibur, iack, ierr;
    wire        dreq, dbur, dwe, dack, derr;
    wire [3:0]  dbe;

    // One rate throughout in this harness, so the enable is held high. Left
    // unconnected it floats to zero and the core never moves -- which is
    // exactly what happened, silently, when the port was added.
    r3900_cached #(.COUNT_PER_INSN(1'b1)) cpu (
        .clk(clk), .cen(1'b1), .rst_n(rst_n),
        .imem_addr(ia), .imem_req(ireq), .imem_burst(ibur),
        .imem_ack(iack), .imem_rdata(ird), .imem_err(ierr),
        .dmem_addr(da), .dmem_req(dreq), .dmem_burst(dbur), .dmem_we(dwe),
        .dmem_be(dbe), .dmem_wdata(dwd), .dmem_ack(dack), .dmem_rdata(drd),
        .dmem_err(derr),
        .irq_in(irq_in),
        .retire_valid(retire_valid), .retire_pc(retire_pc),
        .retire_insn(retire_insn), .retire_next_pc(retire_next_pc),
        .ihit_count(ihit_count), .imiss_count(imiss_count),
        .dhit_count(dhit_count), .dmiss_count(dmiss_count)
    );

    dr840_mem board (
        .clk(clk), .cen(1'b1), .rst_n(rst_n),
        .imem_addr(ia), .imem_req(ireq), .imem_burst(ibur),
        .imem_ack(iack), .imem_rdata(ird), .imem_err(ierr),
        .dmem_addr(da), .dmem_req(dreq), .dmem_burst(dbur), .dmem_we(dwe),
        .dmem_be(dbe), .dmem_wdata(dwd), .dmem_ack(dack), .dmem_rdata(drd),
        .dmem_err(derr),
        .ram_addr(ram_addr), .ram_req(ram_req), .ram_burst(ram_burst),
        .ram_we(ram_we), .ram_be(ram_be), .ram_wdata(ram_wdata),
        .ram_ack(ram_ack), .ram_rdata(ram_rdata),
        // No adapter here: the harness answers directly, so a transaction
        // is in the memory exactly while a request is up and unanswered.
        .ram_busy(ram_req & ~ram_ack),
        .io_addr(io_addr), .io_req(io_req), .io_we(io_we), .io_be(io_be),
        .io_wdata(io_wdata), .io_ack(io_ack), .io_rdata(io_rdata),
        .io_err(io_err)
    );
endmodule

`default_nettype wire
