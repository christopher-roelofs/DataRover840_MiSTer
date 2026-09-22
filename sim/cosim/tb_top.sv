// Testbench shim. Presents the cached core's memory side under the same
// port names the bare core uses, so one harness drives either and the
// comparison is identical in both. Nothing here is synthesised.
`default_nettype none

module tb_top #(
    parameter bit COUNT_PER_INSN = 1'b0
) (
    input  wire        clk,
    input  wire        cen,          // the core's clock enable
    input  wire        rst_n,
    output wire [31:0] ibus_addr,
    output wire        ibus_req,
    output wire        ibus_burst,
    input  wire        ibus_ack,
    input  wire [31:0] ibus_rdata,
    input  wire        ibus_err,
    output wire [31:0] dbus_addr,
    output wire        dbus_req,
    output wire        dbus_burst,
    output wire        dbus_we,
    output wire [3:0]  dbus_be,
    output wire [31:0] dbus_wdata,
    input  wire        dbus_ack,
    input  wire [31:0] dbus_rdata,
    input  wire        dbus_err,
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
    r3900_cached #(.COUNT_PER_INSN(COUNT_PER_INSN)) u (
        .clk(clk), .cen(cen), .rst_n(rst_n),
        .imem_addr(ibus_addr), .imem_req(ibus_req), .imem_burst(ibus_burst),
        .imem_ack(ibus_ack), .imem_rdata(ibus_rdata), .imem_err(ibus_err),
        .dmem_addr(dbus_addr), .dmem_req(dbus_req), .dmem_burst(dbus_burst),
        .dmem_we(dbus_we),
        .dmem_be(dbus_be), .dmem_wdata(dbus_wdata), .dmem_ack(dbus_ack),
        .dmem_rdata(dbus_rdata), .dmem_err(dbus_err),
        .irq_in(irq_in),
        .retire_valid(retire_valid), .retire_pc(retire_pc),
        .retire_insn(retire_insn), .retire_next_pc(retire_next_pc),
        .ihit_count(ihit_count), .imiss_count(imiss_count),
        .dhit_count(dhit_count), .dmiss_count(dmiss_count)
    );
endmodule

`default_nettype wire
