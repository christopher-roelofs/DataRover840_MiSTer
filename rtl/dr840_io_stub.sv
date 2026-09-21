//
// dr840_io_stub.sv - a placeholder for the peripheral bus.
//
// The real machine has the TX39 on-chip block, two PC Card controllers and
// the unidentified chip in kseg3 behind here. None of them exist yet. This
// answers every access immediately so the core keeps running instead of
// stalling on the first register it touches, and it is wrong on purpose:
//
//   - The TX39 block reads as zero. Real behaviour is in magicrecomp's
//     docs/HARDWARE.md, and getting it right is what makes the ROM reach
//     the monitor banner -- UART transmit-ready is a *level*, and the reset
//     path depends on it asserting without anything writing the holding
//     register.
//   - Everything else reads all-ones, which is what an undriven bus does.
//     The PC Card detect lines are active low, so all-ones is "no card",
//     which is at least the right answer for an empty slot.
//
// Nothing here is a model of anything. It exists so the rest of the machine
// can be brought up on hardware before the peripherals are written, and so
// that what is missing is a file with a name rather than a hang.
//
`default_nettype none

module dr840_io_stub (
    input  wire        clk,
    input  wire        rst_n,

    input  wire [31:0] io_addr,
    input  wire        io_req,
    input  wire        io_we,
    input  wire [3:0]  io_be,
    input  wire [31:0] io_wdata,
    output wire        io_ack,
    output wire [31:0] io_rdata,
    output wire        io_err,

    // Counted so a build can show whether the guest is touching devices at
    // all, and how much.
    output reg  [31:0] io_count
);
    wire is_tx39 = (io_addr >= 32'h10C0_0000) && (io_addr < 32'h10C0_0400);

    assign io_ack   = io_req;
    assign io_rdata = is_tx39 ? 32'h0000_0000 : 32'hFFFF_FFFF;
    assign io_err   = 1'b0;

    always @(posedge clk or negedge rst_n)
        if (!rst_n)            io_count <= 32'd0;
        else if (io_req && !io_we) io_count <= io_count + 32'd1;

endmodule

`default_nettype wire
