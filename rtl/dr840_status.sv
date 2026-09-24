// dr840_status.sv -- the machine's own account of itself, once a second,
// on the serial port.
//
// When the guest is Magic Cap the debug port is idle: it never transmits
// on UART A. So while it is idle this borrows the pin and sends a line of
// hex every second -- how many times the core has been let out of reset,
// how many exceptions it has taken, the ROM's checksum as loaded, the last
// retired PC and the retired count -- which `scripts/serial` reads over
// ssh. That makes a fault on the hardware something that can be collected
// rather than something someone has to describe.
//
//     R=00000001 E=00003A7F S=BE3685EB P=13C213F0 N=0BEBC200 F=00000000 X=00000000 B=00000000 M=.. A=.. K=.. L=..
//
// M is the memory test's mismatch count, from the walk the loader makes
// over the DRAM before the core is let go, and A the ROM summed as the
// memory gives it back -- which should equal S, the ROM as it was sent.
// F's top byte, X and B are the code, EPC and BadVAddr of the first fault
// at a place other than the first fault's: the boot's one BREAK is known,
// and what happens somewhere else is the trouble.
//
// R resets, E exceptions, S the ROM's checksum, P the last retired PC, N
// instructions retired, F faults -- exceptions other than interrupts, the
// last one's code in the top byte -- and X the last fault's EPC. While no
// fault has happened F's top byte carries Cause.IP at the last interrupt.
//
// K and L are the package link: K its state in the top three bits (0 no
// package, 1 offered, 2 linked and sending, 3 taken, 4 refused) and the
// package's length below, L the package summed as it was loaded.
//
// 38400 8N1, the same as the monitor, so one setting on the far end reads
// both.
`default_nettype none

module dr840_status #(
    parameter CLK_HZ = 92_000_000
) (
    input  wire        clk,
    input  wire        rst_n,
    input  wire [31:0] v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12,
    output reg         txd
);
    localparam [15:0] BIT_CLOCKS = 16'(CLK_HZ / 38400);
    localparam [31:0] PERIOD     = CLK_HZ;              // one second

    // Thirteen fields of " X=hhhhhhhh", then CR LF: 145 bytes.
    localparam LINE = 145;

    reg [31:0] s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12;  // the line's values
    reg [31:0] tick;
    reg [7:0]  pos;                                     // byte within the line
    reg        sending;
    reg [3:0]  tbit;                                     // 0 start, 1..8 data, 9 stop
    reg [15:0] bcnt;
    reg [7:0]  cur;

    function [7:0] hexch(input [3:0] n);
        hexch = (n < 4'd10) ? (8'h30 + {4'd0, n}) : (8'h37 + {4'd0, n});
    endfunction

    // The byte at `pos`: field f, position k within it. Counted along
    // with pos rather than divided out of it -- the divider was twelve
    // nanoseconds into the character mux.
    reg [6:0] f, k;
    reg [31:0] val;
    reg [7:0]  ch;
    always @(*) begin
        case (f)
        7'd0: val = s0; 7'd1: val = s1; 7'd2: val = s2; 7'd3: val = s3;
        7'd4: val = s4; 7'd5: val = s5; 7'd6: val = s6; 7'd7: val = s7;
        7'd8: val = s8; 7'd9: val = s9; 7'd10: val = s10; 7'd11: val = s11; default: val = s12;
        endcase
        if (pos == LINE - 2)      ch = 8'h0D;
        else if (pos == LINE - 1) ch = 8'h0A;
        else case (k)
        7'd0: ch = 8'h20;
        7'd1: case (f) 7'd0: ch = 8'h52; 7'd1: ch = 8'h45; 7'd2: ch = 8'h53;
                       7'd3: ch = 8'h50; 7'd4: ch = 8'h4E; 7'd5: ch = 8'h46;
                       7'd6: ch = 8'h58; 7'd7: ch = 8'h42; 7'd8: ch = 8'h4D;
                       7'd9: ch = 8'h41; 7'd10: ch = 8'h4B; 7'd11: ch = 8'h4C;
                       default: ch = 8'h4A; endcase
        7'd2: ch = 8'h3D;
        default: ch = hexch(val[4 * (7'd10 - k) +: 4]);   // k=3 -> bits 31:28
        endcase
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            tick <= 32'd0; pos <= 8'd0; f <= 7'd0; k <= 7'd0; sending <= 1'b0; tbit <= 4'd0; bcnt <= 16'd0;
            cur <= 8'd0; txd <= 1'b1;
            s0 <= 0; s1 <= 0; s2 <= 0; s3 <= 0; s4 <= 0; s5 <= 0; s6 <= 0; s7 <= 0; s8 <= 0; s9 <= 0;
            s10 <= 0; s11 <= 0; s12 <= 0;
        end else begin
            if (tick == PERIOD - 1) begin
                tick <= 32'd0;
                if (!sending) begin
                    s0 <= v0; s1 <= v1; s2 <= v2; s3 <= v3; s4 <= v4; s5 <= v5; s6 <= v6; s7 <= v7;
                    s8 <= v8; s9 <= v9; s10 <= v10; s11 <= v11; s12 <= v12;
                    sending <= 1'b1; pos <= 8'd0; f <= 7'd0; k <= 7'd0; tbit <= 4'd0; bcnt <= 16'd0;
                end
            end else tick <= tick + 32'd1;

            if (sending) begin
                if (bcnt == BIT_CLOCKS - 1) begin
                    bcnt <= 16'd0;
                    case (tbit)
                    4'd0: begin txd <= 1'b0; cur <= ch; tbit <= 4'd1; end         // start
                    4'd9: begin txd <= 1'b1; tbit <= 4'd10; end                   // stop
                    4'd10: begin
                        tbit <= 4'd0;
                        if (pos == LINE - 1) sending <= 1'b0;
                        else begin
                            pos <= pos + 8'd1;
                            if (k == 7'd10) begin k <= 7'd0; f <= f + 7'd1; end
                            else k <= k + 7'd1;
                        end
                    end
                    default: begin txd <= cur[tbit - 1]; tbit <= tbit + 4'd1; end   // data, LSB first
                    endcase
                end else bcnt <= bcnt + 16'd1;
            end else txd <= 1'b1;
        end
    end
endmodule

`default_nettype wire
