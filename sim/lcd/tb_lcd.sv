// The LCD controller with a memory behind it and its raster brought out,
// so the scanout can be compared against the framebuffer that produced it.
//
// The memory is the testbench's: dr840_lcd asks the board for bursts and
// the board asks the SDRAM, and both of those are validated elsewhere. What
// is not validated anywhere else is whether the pixel that reaches the
// screen is the pixel that was in memory, which is what this is for.
`default_nettype none

module tb_lcd (
    input  wire        clk,
    input  wire        rst_n,

    input  wire [31:0] ctrl1,
    input  wire [31:0] ctrl2,
    input  wire [31:0] ctrl3,

    output wire [31:0] vmem_addr,
    output wire        vmem_req,
    input  wire        vmem_ack,
    input  wire [31:0] vmem_rdata,

    output wire        dbg_cen,
    output wire        ce_pix,
    output wire        hs,
    output wire        vs,
    output wire        de,
    output wire [7:0]  r,
    output wire [7:0]  g,
    output wire [7:0]  b
);
    // The core's clock enable: every second edge, as in the machine.
    reg cen;
    always @(posedge clk or negedge rst_n)
        if (!rst_n) cen <= 1'b0; else cen <= ~cen;

    assign dbg_cen = cen;

    dr840_lcd lcd (
        .clk(clk), .cen(cen), .rst_n(rst_n),
        .ctrl1(ctrl1), .ctrl2(ctrl2), .ctrl3(ctrl3),
        .cur_x(9'd511), .cur_y(9'd511), .cur_down(1'b0),      // the pointer parked off the panel
        .vmem_addr(vmem_addr), .vmem_req(vmem_req), .vmem_burst(),
        .vmem_ack(vmem_ack), .vmem_rdata(vmem_rdata),
        .ce_pix(ce_pix), .hs(hs), .vs(vs), .de(de), .r(r), .g(g), .b(b)
    );
endmodule

`default_nettype wire
