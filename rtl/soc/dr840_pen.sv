// dr840_pen.sv -- the pen, from panel pixels to the converter's counts.
//
// The reference's calibration puts the panel's corners at raw X 85..836 and
// Y 69..791: 751 counts across 479 pixels, 722 down 319. Multiplied and
// shifted rather than divided, in stages, because a pen moves at a
// human's speed and the multiply into the add was not going to close in
// one clock.
//
// The Y factor is 579 and needs ten bits. Written with nine it was 67,
// silently, and the pen's Y was squeezed into the top ninth of the panel:
// the first calibration target, near the top, passed, and the second, near
// the bottom, was nowhere near where the ROM expected it. The harness fed
// the converter its counts directly and never came through here; now it
// does.
`default_nettype none

module dr840_pen (
    input  wire       clk,
    input  wire [8:0] pen_px,           // 0..479
    input  wire [8:0] pen_py,           // 0..319
    output reg  [9:0] pen_x,            // 85..836
    output reg  [9:0] pen_y             // 69..791
);
    reg [18:0] xm, ym;
    always @(posedge clk) begin
        xm    <= pen_px * 10'd401;      // 751/479 * 256
        ym    <= pen_py * 10'd579;      // 722/319 * 256
        pen_x <= 10'd85 + xm[17:8];
        pen_y <= 10'd69 + ym[17:8];
    end
endmodule

`default_nettype wire
