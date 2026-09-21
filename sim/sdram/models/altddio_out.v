// Simulation stub for the Altera DDR output primitive.
//
// The controller uses exactly one of these, to forward its own clock to the
// SDRAM pin. Nothing in this simulation looks at that pin -- the chip model
// is clocked from the same net the controller is -- so reproducing the
// half-cycle phase relationship would buy nothing. The stub exists so the
// design elaborates; on hardware Quartus supplies the real primitive.
`timescale 1ns/1ps

module altddio_out #(
    parameter extend_oe_disable    = "OFF",
    parameter intended_device_family = "Cyclone V",
    parameter invert_output        = "OFF",
    parameter lpm_hint             = "UNUSED",
    parameter lpm_type             = "altddio_out",
    parameter oe_reg               = "UNREGISTERED",
    parameter power_up_high        = "OFF",
    parameter width                = 1
)(
    input  wire [width-1:0] datain_h,
    input  wire [width-1:0] datain_l,
    input  wire             outclock,
    input  wire             outclocken,
    input  wire             aclr,
    input  wire             aset,
    input  wire             sclr,
    input  wire             sset,
    input  wire             oe,
    output wire [width-1:0] dataout
);
    assign dataout = outclock ? datain_h : datain_l;
endmodule
