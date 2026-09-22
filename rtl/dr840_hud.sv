//
// dr840_hud.sv - a debug display, until the machine has one of its own.
//
// The DataRover's screen is drawn by the TX39 LCD controller, which does not
// exist yet, and the guest cannot print anything either because the UART
// does not exist yet. So a build that runs correctly on hardware and a build
// that is wedged look exactly alike. This makes them look different: eight
// 32-bit values in hex, large enough to read across a room.
//
//   row 0  the last retired PC
//   row 1  the instruction at it
//   row 2  instructions retired
//   row 3  instruction cache hits
//   row 4  instruction cache misses
//   row 5  data cache hits
//   row 6  data cache misses
//   row 7  device reads attempted
//   row 8  ROM words written into the SDRAM
//   row 9  bytes the guest has written to UART A
//
// Row 8 is the one to look at first. Zero there means no ROM arrived, and
// the core is held in reset rather than running forward through blank
// memory -- which it used to do, and which looked exactly like working.
//
// Row 2 climbing means the core is fetching from SDRAM and executing. Row 0
// sitting still means it is in a loop, which is what to expect while the
// peripherals are a stub: the ROM polls a register that will never change.
//
// 640x480 from a pixel enable every fourth 95 MHz clock, so 23.75 MHz and a
// 56.5 Hz frame. Not a standard rate; the scaler does not mind.
//
`default_nettype none

module dr840_hud (
    input  wire        clk,
    input  wire        rst_n,

    output reg         ce_pix,
    output reg         hs,
    output reg         vs,
    output reg         de,
    output reg  [7:0]  r,
    output reg  [7:0]  g,
    output reg  [7:0]  b,

    input  wire [31:0] v0, v1, v2, v3, v4, v5, v6, v7, v8, v9
);
    localparam H_ACT = 640, H_FP = 16, H_SY = 96, H_BP = 48;
    localparam V_ACT = 480, V_FP = 10, V_SY = 2,  V_BP = 33;
    localparam H_TOT = H_ACT + H_FP + H_SY + H_BP;   // 800
    localparam V_TOT = V_ACT + V_FP + V_SY + V_BP;   // 525

    reg [1:0]  pdiv;
    reg [9:0]  hc, vc;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pdiv <= 2'd0; hc <= 10'd0; vc <= 10'd0; ce_pix <= 1'b0;
        end else begin
            pdiv   <= pdiv + 2'd1;
            ce_pix <= (pdiv == 2'd3);
            if (pdiv == 2'd3) begin
                if (hc == H_TOT - 1) begin
                    hc <= 10'd0;
                    vc <= (vc == V_TOT - 1) ? 10'd0 : vc + 10'd1;
                end else hc <= hc + 10'd1;
            end
        end
    end

    wire active = (hc < H_ACT) && (vc < V_ACT);

    // Eight rows of eight digits, each glyph 8x8 scaled by four.
    localparam X0 = 10'd64, Y0 = 10'd64, CELL = 10'd32;

    wire [9:0] rx = hc - X0;
    wire [9:0] ry = vc - Y0;
    wire in_box = (hc >= X0) && (rx < CELL * 8) && (vc >= Y0) && (ry < CELL * 10);

    wire [2:0] col  = rx[7:5];     // which digit, 0 leftmost
    wire [3:0] row  = ry[8:5];     // which value
    wire [2:0] gx   = rx[4:2];     // pixel within the glyph
    wire [2:0] gy   = ry[4:2];

    reg [31:0] val;
    always @(*) case (row)
        4'd0: val = v0;  4'd1: val = v1;  4'd2: val = v2;  4'd3: val = v3;
        4'd4: val = v4;  4'd5: val = v5;  4'd6: val = v6;  4'd7: val = v7;
        4'd8: val = v8;  default: val = v9;
    endcase

    // Leftmost digit is the most significant.
    reg [3:0] nib;
    always @(*) case (col)
        3'd0: nib = val[31:28]; 3'd1: nib = val[27:24];
        3'd2: nib = val[23:20]; 3'd3: nib = val[19:16];
        3'd4: nib = val[15:12]; 3'd5: nib = val[11:8];
        3'd6: nib = val[7:4];   default: nib = val[3:0];
    endcase

    reg [7:0] glyph;
    always @(*) begin
        case ({nib, gy})
        // 0
        7'h00: glyph=8'h3C; 7'h01: glyph=8'h66; 7'h02: glyph=8'h6E; 7'h03: glyph=8'h76;
        7'h04: glyph=8'h66; 7'h05: glyph=8'h66; 7'h06: glyph=8'h3C; 7'h07: glyph=8'h00;
        // 1
        7'h08: glyph=8'h18; 7'h09: glyph=8'h38; 7'h0A: glyph=8'h18; 7'h0B: glyph=8'h18;
        7'h0C: glyph=8'h18; 7'h0D: glyph=8'h18; 7'h0E: glyph=8'h7E; 7'h0F: glyph=8'h00;
        // 2
        7'h10: glyph=8'h3C; 7'h11: glyph=8'h66; 7'h12: glyph=8'h06; 7'h13: glyph=8'h0C;
        7'h14: glyph=8'h30; 7'h15: glyph=8'h60; 7'h16: glyph=8'h7E; 7'h17: glyph=8'h00;
        // 3
        7'h18: glyph=8'h3C; 7'h19: glyph=8'h66; 7'h1A: glyph=8'h06; 7'h1B: glyph=8'h1C;
        7'h1C: glyph=8'h06; 7'h1D: glyph=8'h66; 7'h1E: glyph=8'h3C; 7'h1F: glyph=8'h00;
        // 4
        7'h20: glyph=8'h0C; 7'h21: glyph=8'h1C; 7'h22: glyph=8'h3C; 7'h23: glyph=8'h6C;
        7'h24: glyph=8'h7E; 7'h25: glyph=8'h0C; 7'h26: glyph=8'h0C; 7'h27: glyph=8'h00;
        // 5
        7'h28: glyph=8'h7E; 7'h29: glyph=8'h60; 7'h2A: glyph=8'h7C; 7'h2B: glyph=8'h06;
        7'h2C: glyph=8'h06; 7'h2D: glyph=8'h66; 7'h2E: glyph=8'h3C; 7'h2F: glyph=8'h00;
        // 6
        7'h30: glyph=8'h1C; 7'h31: glyph=8'h30; 7'h32: glyph=8'h60; 7'h33: glyph=8'h7C;
        7'h34: glyph=8'h66; 7'h35: glyph=8'h66; 7'h36: glyph=8'h3C; 7'h37: glyph=8'h00;
        // 7
        7'h38: glyph=8'h7E; 7'h39: glyph=8'h66; 7'h3A: glyph=8'h0C; 7'h3B: glyph=8'h18;
        7'h3C: glyph=8'h18; 7'h3D: glyph=8'h18; 7'h3E: glyph=8'h18; 7'h3F: glyph=8'h00;
        // 8
        7'h40: glyph=8'h3C; 7'h41: glyph=8'h66; 7'h42: glyph=8'h66; 7'h43: glyph=8'h3C;
        7'h44: glyph=8'h66; 7'h45: glyph=8'h66; 7'h46: glyph=8'h3C; 7'h47: glyph=8'h00;
        // 9
        7'h48: glyph=8'h3C; 7'h49: glyph=8'h66; 7'h4A: glyph=8'h66; 7'h4B: glyph=8'h3E;
        7'h4C: glyph=8'h06; 7'h4D: glyph=8'h0C; 7'h4E: glyph=8'h38; 7'h4F: glyph=8'h00;
        // A
        7'h50: glyph=8'h18; 7'h51: glyph=8'h3C; 7'h52: glyph=8'h66; 7'h53: glyph=8'h66;
        7'h54: glyph=8'h7E; 7'h55: glyph=8'h66; 7'h56: glyph=8'h66; 7'h57: glyph=8'h00;
        // B
        7'h58: glyph=8'h7C; 7'h59: glyph=8'h66; 7'h5A: glyph=8'h66; 7'h5B: glyph=8'h7C;
        7'h5C: glyph=8'h66; 7'h5D: glyph=8'h66; 7'h5E: glyph=8'h7C; 7'h5F: glyph=8'h00;
        // C
        7'h60: glyph=8'h3C; 7'h61: glyph=8'h66; 7'h62: glyph=8'h60; 7'h63: glyph=8'h60;
        7'h64: glyph=8'h60; 7'h65: glyph=8'h66; 7'h66: glyph=8'h3C; 7'h67: glyph=8'h00;
        // D
        7'h68: glyph=8'h78; 7'h69: glyph=8'h6C; 7'h6A: glyph=8'h66; 7'h6B: glyph=8'h66;
        7'h6C: glyph=8'h66; 7'h6D: glyph=8'h6C; 7'h6E: glyph=8'h78; 7'h6F: glyph=8'h00;
        // E
        7'h70: glyph=8'h7E; 7'h71: glyph=8'h60; 7'h72: glyph=8'h60; 7'h73: glyph=8'h7C;
        7'h74: glyph=8'h60; 7'h75: glyph=8'h60; 7'h76: glyph=8'h7E; 7'h77: glyph=8'h00;
        // F
        default: case (gy)
            3'd0: glyph=8'h7E; 3'd1: glyph=8'h60; 3'd2: glyph=8'h60; 3'd3: glyph=8'h7C;
            3'd4: glyph=8'h60; 3'd5: glyph=8'h60; 3'd6: glyph=8'h60; default: glyph=8'h00;
        endcase
        endcase
    end

    wire lit = in_box && glyph[3'd7 - gx];

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            hs <= 1'b0; vs <= 1'b0; de <= 1'b0;
            r <= 8'd0; g <= 8'd0; b <= 8'd0;
        end else if (ce_pix) begin
            hs <= (hc >= H_ACT + H_FP) && (hc < H_ACT + H_FP + H_SY);
            vs <= (vc >= V_ACT + V_FP) && (vc < V_ACT + V_FP + V_SY);
            de <= active;
            // Amber on near-black, which is roughly what the real panel
            // looks like and keeps one channel free for a later overlay.
            r <= (active && lit) ? 8'hFF : 8'h08;
            g <= (active && lit) ? 8'hB0 : 8'h08;
            b <= (active && lit) ? 8'h20 : 8'h10;
        end
    end

endmodule

`default_nettype wire
