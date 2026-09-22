// dr840_lcd.sv -- the TX3912 LCD controller, onto a VGA-timed raster.
//
// A DMA-driven flat framebuffer: VIDEOCTRL3 holds the base address and
// VIDEOCTRL2 the geometry. There is no drawing engine; the CPU writes
// pixels into RAM and this scans them out. Magic Cap programs a 480x320
// panel at 2 bits per pixel, four pixels per byte, most significant bits
// first, at physical 0x3F6A00 -- the top 38,400 bytes of the 4 MB. A set
// bit is ink: the stored value is coverage, and INVVID flips it.
//
// The MiSTer wants a raster, so this is one: 640x480 at a quarter of the
// system clock, the panel centred in it with a border round it. Each
// panel line is fetched into a line buffer during the raster line before
// it, eight 16-byte bursts through the board's arbiter -- the same bursts
// the caches use, at the lowest priority, about three percent of the
// memory's time. The fetch engine runs on the core's clock enable, like
// everything else that talks to the board.
//
// HORZVAL and LINEVAL are honoured as far as the raster allows: a panel
// wider than 640 or taller than 480 is clipped, and anything narrower is
// centred. BITSEL other than 2 bpp is shown as 2 bpp; nothing here
// programs it otherwise.
`default_nettype none

module dr840_lcd (
    input  wire        clk,
    input  wire        cen,
    input  wire        rst_n,

    // VIDEOCTRL1..3 as written.
    input  wire [31:0] ctrl1,
    input  wire [31:0] ctrl2,
    input  wire [31:0] ctrl3,

    // The memory port, physical addresses, bursts of four words.
    output reg  [31:0] vmem_addr,
    output reg         vmem_req,
    output wire        vmem_burst,
    input  wire        vmem_ack,
    input  wire [31:0] vmem_rdata,

    // The raster.
    output reg         ce_pix,
    output reg         hs,
    output reg         vs,
    output reg         de,
    output reg  [7:0]  r,
    output reg  [7:0]  g,
    output reg  [7:0]  b
);
    // ------------------------------------------------------------ registers
    wire        envid  = ctrl1[0];
    wire        invvid = ctrl1[2];
    wire [8:0]  horz   = ctrl2[20:12];                 // groups of 4 pixels, -1
    wire [9:0]  lines  = ctrl2[9:0];                   // lines, -1
    wire [10:0] pw     = {horz, 2'b00} + 11'd4;        // panel width, pixels
    wire [10:0] ph     = {1'b0, lines} + 11'd1;        // panel height
    wire [31:0] fb_pa  = {ctrl3[31:20], 20'd0} | {12'd0, ctrl3[19:4], 4'd0};
    // A line is (horz+1)*4 pixels at 2 bits: (horz+1) bytes. 480 pixels
    // is 120 bytes, 30 words, seven and a half bursts; eight are fetched.
    wire [10:0] line_bytes = {2'b00, horz} + 11'd1;

    // ------------------------------------------------------------ the raster
    localparam H_ACT = 640, H_FP = 16, H_SY = 96, H_BP = 48;
    localparam V_ACT = 480, V_FP = 10, V_SY = 2,  V_BP = 33;
    localparam H_TOT = H_ACT + H_FP + H_SY + H_BP;   // 800
    localparam V_TOT = V_ACT + V_FP + V_SY + V_BP;   // 525

    reg [1:0] pdiv;
    reg [9:0] hc, vc;
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

    // Where the panel sits: centred, clipped to the raster. Registered:
    // the geometry changes once, and from the register straight into the
    // pixel's arithmetic it was 12 ns in one clock.
    reg [10:0] pw_c, ph_c;
    reg [9:0]  x0, y0;
    always @(posedge clk) begin
        pw_c <= (pw > 11'd640) ? 11'd640 : pw;
        ph_c <= (ph > 11'd480) ? 11'd480 : ph;
        x0   <= 10'((11'd640 - pw_c) >> 1);
        y0   <= 10'((11'd480 - ph_c) >> 1);
    end
    // The pixel's place, a stage later. A pixel lasts four clocks, and
    // everything from here to the colour is delayed together, so the only
    // effect is the whole picture a clock late, which nothing can see.
    reg [9:0] px, py;
    reg       in_panel, active, hs_p, vs_p;
    always @(posedge clk) begin
        px       <= hc - x0;
        py       <= vc - y0;
        in_panel <= (hc >= x0) && ({1'b0, hc - x0} < pw_c) && (vc >= y0) && ({1'b0, vc - y0} < ph_c);
        active   <= (hc < H_ACT) && (vc < V_ACT);
        hs_p     <= (hc >= H_ACT + H_FP) && (hc < H_ACT + H_FP + H_SY);
        vs_p     <= (vc >= V_ACT + V_FP) && (vc < V_ACT + V_FP + V_SY);
    end

    // ------------------------------------------------------------ line buffers
    // Two of 32 words: one being shown, one being filled with the next
    // panel line. Which is which follows the raster line's parity.
    reg [31:0] lbuf [0:63];
    wire        show_bank = py[0];
    wire [4:0]  show_word = px[8:4];                   // 16 pixels per word
    // Read asynchronously: the raster's pixel is registered from the
    // address in the same cycle, as the debug display does it, and a
    // registered read would hand the previous word to the first pixel of
    // each new one.
    wire [31:0] show_q = lbuf[{show_bank, show_word}];
    // The pixel: 2 bits, most significant first, in the word as it was in
    // memory -- big-endian, so pixel 0 is bits 31:30.
    wire [3:0]  pix_i = px[3:0];
    wire [4:0]  shift = 5'd30 - {pix_i, 1'b0};
    wire [1:0]  ink   = show_q[shift +: 2];
    wire [1:0]  level = invvid ? ~ink : ink;
    wire [7:0]  gray  = 8'd255 - {level, level, level, level};   // 0,85,170,255

    always @(posedge clk) begin
        hs <= hs_p;
        vs <= vs_p;
        de <= active;
        if (!active)          {r, g, b} <= 24'd0;
        else if (!envid)      {r, g, b} <= 24'h50_50_50;          // panel off
        else if (in_panel)    {r, g, b} <= {gray, gray, gray};
        else                  {r, g, b} <= 24'h30_30_30;          // the bezel
    end

    // ------------------------------------------------------------ the fetch
    // At the start of each raster line, fetch the panel line that the
    // *next* raster line will show, into the other bank. Line -1 (the one
    // before the panel starts) fetches line 0.
    assign vmem_burst = 1'b1;
    wire [9:0]  next_py   = vc + 10'd1 - y0;
    wire        next_in   = (vc + 10'd1 >= y0) && ({1'b0, next_py} < ph_c);
    reg  [9:0]  fetch_line;
    reg  [3:0]  burst;                                 // 0..7
    reg  [1:0]  beat;
    reg         fetching;
    reg         pend;                                  // a line is due
    wire        line_start = (hc == 10'd0) && (pdiv == 2'd3);
    reg  [31:0] line_base;
    // Line base = fb + line * line_bytes. A multiply, once per line, so it
    // is done serially: base is kept and stepped by line_bytes.
    reg  [31:0] next_base;
    // The bank being filled is the one the fetched line will show from.
    wire        fill_bank = fetch_line[0];

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            fetching <= 1'b0; burst <= 4'd0; beat <= 2'd0; vmem_req <= 1'b0;
            vmem_addr <= 32'd0; fetch_line <= 10'd0; pend <= 1'b0;
            line_base <= 32'd0; next_base <= 32'd0;
        end else begin
            // Everything the board sees moves on the core's edges, so the
            // .sdc can give it the same two periods it gives the caches.
            if (line_start) pend <= 1'b1;
            if (pend && cen && !fetching) begin
                pend       <= 1'b0;
                if (envid && next_in) begin
                fetching   <= 1'b1;
                burst      <= 4'd0;
                beat       <= 2'd0;
                fetch_line <= next_py;
                line_base  <= (next_py == 10'd0) ? fb_pa : next_base;
                vmem_addr  <= (next_py == 10'd0) ? fb_pa : next_base;
                vmem_req   <= 1'b1;
                end
            end else if (fetching && cen) begin
                if (vmem_ack) begin
                    lbuf[{fill_bank, burst[2:0], beat}] <= vmem_rdata;
                    beat <= beat + 2'd1;
                    if (beat == 2'd3) begin
                        if (burst == 4'd7) begin
                            fetching  <= 1'b0;
                            vmem_req  <= 1'b0;
                            next_base <= line_base + {21'd0, line_bytes};
                        end else begin
                            burst     <= burst + 4'd1;
                            vmem_addr <= line_base + {24'd0, burst + 4'd1, 4'd0};
                        end
                    end else begin
                        vmem_addr <= {vmem_addr[31:4], beat + 2'd1, 2'b00};
                    end
                end
            end
        end
    end
endmodule

`default_nettype wire
