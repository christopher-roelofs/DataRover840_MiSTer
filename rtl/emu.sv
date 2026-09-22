//
// emu.sv - the MiSTer top level.
//
// What exists: the R3900 with its caches, the board's address decode, the
// SDRAM controller, and the ROM arriving from the HPS. What does not: every
// peripheral. The guest therefore cannot draw anything or print anything,
// so the video is a debug display rather than the machine's own -- see
// dr840_hud.sv.
//
module emu
(
    input         CLK_50M,
    input         RESET,
    inout  [48:0] HPS_BUS,

    output        CLK_VIDEO,
    output        CE_PIXEL,

    output [12:0] VIDEO_ARX,
    output [12:0] VIDEO_ARY,

    output  [7:0] VGA_R,
    output  [7:0] VGA_G,
    output  [7:0] VGA_B,
    output        VGA_HS,
    output        VGA_VS,
    output        VGA_DE,
    output        VGA_F1,
    output [1:0]  VGA_SL,
    output        VGA_SCALER,
    output        VGA_DISABLE,

    input  [11:0] HDMI_WIDTH,
    input  [11:0] HDMI_HEIGHT,
    output        HDMI_FREEZE,
    output        HDMI_BLACKOUT,
    output        HDMI_BOB_DEINT,

    output        LED_USER,
    output  [1:0] LED_POWER,
    output  [1:0] LED_DISK,
    output  [1:0] BUTTONS,

    input         CLK_AUDIO,
    output [15:0] AUDIO_L,
    output [15:0] AUDIO_R,
    output        AUDIO_S,
    output  [1:0] AUDIO_MIX,

    inout   [3:0] ADC_BUS,

    output        SD_SCK,
    output        SD_MOSI,
    input         SD_MISO,
    output        SD_CS,
    input         SD_CD,

    output        DDRAM_CLK,
    input         DDRAM_BUSY,
    output  [7:0] DDRAM_BURSTCNT,
    output [28:0] DDRAM_ADDR,
    input  [63:0] DDRAM_DOUT,
    input         DDRAM_DOUT_READY,
    output        DDRAM_RD,
    output [63:0] DDRAM_DIN,
    output  [7:0] DDRAM_BE,
    output        DDRAM_WE,

    output        SDRAM_CLK,
    output        SDRAM_CKE,
    output [12:0] SDRAM_A,
    output  [1:0] SDRAM_BA,
    inout  [15:0] SDRAM_DQ,
    output        SDRAM_DQML,
    output        SDRAM_DQMH,
    output        SDRAM_nCS,
    output        SDRAM_nCAS,
    output        SDRAM_nRAS,
    output        SDRAM_nWE,

    input         UART_CTS,
    output        UART_RTS,
    input         UART_RXD,
    output        UART_TXD,
    output        UART_DTR,
    input         UART_DSR,

    input   [6:0] USER_IN,
    output  [6:0] USER_OUT,

    input         OSD_STATUS,

    // SSH-side debug window: HPS picks one of 8 bytes via DBG_SEL_IN
    // (gp_outr[23:21]) and reads it back from gp_in[27:20] (devmem 0xFF706014).
    input   [2:0] DBG_SEL_IN,
    output  [7:0] DBG_BUS_OUT,

    // SSH-side control: hold the Z80 in reset while this bit is high
    // (driven by gp_outr[24], devmem 0xFF706010 bit 24).
    input         DBG_FORCE_RESET,

    // SSH-side control: suppress T1 IRQ generation (gp_outr[25]) — lets
    // us see what the OS main loop does without periodic ISR pre-emption.
    input         DBG_T1_OFF
);

////////////////////////////////////////////////////////////////////////////

// Nothing drives these yet.
assign VGA_F1      = 0;
assign VGA_SL      = 0;
assign VGA_SCALER  = 0;
assign VGA_DISABLE = 0;
assign HDMI_FREEZE = 0;
assign HDMI_BLACKOUT = 0;
assign HDMI_BOB_DEINT = 0;

assign AUDIO_L   = 0;
assign AUDIO_R   = 0;
assign AUDIO_S   = 0;
assign AUDIO_MIX = 0;

assign LED_USER  = ioctl_download;
assign LED_DISK  = 0;
assign LED_POWER = 0;
assign BUTTONS   = 0;

assign ADC_BUS  = 'Z;
assign SD_SCK   = 0;
assign SD_MOSI  = 0;
assign SD_CS    = 1;
assign UART_RTS = 0;
assign UART_DTR = 0;
// UART A goes to the framework's serial port, which the HPS exposes as a
// tty. The IDT monitor's banner comes out there.
assign USER_OUT = '1;

assign DDRAM_CLK      = 0;
assign DDRAM_ADDR     = 0;
assign DDRAM_BURSTCNT = 0;
assign DDRAM_RD       = 0;
assign DDRAM_DIN      = 0;
assign DDRAM_BE       = 0;
assign DDRAM_WE       = 0;

assign SDRAM2_DQ   = 'Z;
assign SDRAM2_A    = 0;
assign SDRAM2_BA   = 0;
assign SDRAM2_nCS  = 1;
assign SDRAM2_nWE  = 1;
assign SDRAM2_nRAS = 1;
assign SDRAM2_nCAS = 1;
assign SDRAM2_CLK  = 0;
assign SDRAM2_EN   = 0;

assign FB_EN = 0; assign FB_FORMAT = 0; assign FB_WIDTH = 0;
assign FB_HEIGHT = 0; assign FB_BASE = 0; assign FB_STRIDE = 0;
assign FB_FORCE_BLANK = 0; assign FB_PAL_CLK = 0; assign FB_PAL_ADDR = 0;
assign FB_PAL_DIN = 0; assign FB_PAL_WR = 0;

assign DBG_BUS_OUT = 0;

assign VIDEO_ARX = 4;
assign VIDEO_ARY = 3;

localparam CONF_STR = {
    "DataRover840;;",
    "-;",
    // MiSTer parses this extension field in three-character chunks, so a
    // longer one silently becomes two filters that match nothing. The
    // device's own images are named .image; .ima is what three characters
    // of that actually is, and .rom is what anyone would reach for.
    "F1,ROMIMABIN,Load DataRover ROM;",
    "-;",
    // The option button, held at reset, takes the ROM to the IDT monitor
    // instead of Magic Cap. Takes effect on the next reset.
    "O[2],Boot,Magic Cap,IDT monitor;",
    "O[3],Display,LCD,Debug;",
    "-;",
    "T[0],Reset;",
    "R[0],Reset and close OSD;",
    "V,v",`BUILD_DATE
};

wire [127:0] status;
wire   [1:0] buttons;
wire         ioctl_download, ioctl_wr;
wire  [24:0] ioctl_addr;
wire   [7:0] ioctl_dout;
wire         ioctl_wait;

hps_io #(.CONF_STR(CONF_STR)) hps_io
(
    .clk_sys        (clk_sys),
    .HPS_BUS        (HPS_BUS),
    .buttons        (buttons),
    .status         (status),
    .ioctl_download (ioctl_download),
    .ioctl_wr       (ioctl_wr),
    .ioctl_addr     (ioctl_addr),
    .ioctl_dout     (ioctl_dout),
    .ioctl_wait     (ioctl_wait)
);

wire clk_sys, pll_locked;
pll pll (.refclk(CLK_50M), .rst(1'b0), .outclk_0(clk_sys), .locked(pll_locked));

wire reset = RESET | status[0] | buttons[1] | ~pll_locked | DBG_FORCE_RESET;
wire rst_n = ~reset;

////////////////////////////////////////////////////////////////////////////
// ROM load.
//
// The HPS sends bytes; the controller has no byte enables, so bytes are
// assembled into whole words before anything is written. That is also four
// times fewer transactions for a four megabyte image.
//
// ioctl_wait is the part that matters. The stream is faster than the SDRAM,
// and without back-pressure the writes that do not fit are simply lost --
// a ROM with holes in it, which looks like a CPU bug.

localparam [24:0] ROM_BASE = 25'h000_0000;

reg  [31:0] word_buf;
reg  [24:0] load_addr;
reg  [31:0] load_data;
reg         load_req, load_busy, dl_d;
wire        load_ack;

// How much ROM has actually been written, and whether any has. Without
// this the core starts on whatever the SDRAM powered up holding -- zeroes,
// which decode as NOP, so it runs forward through blank memory for ever.
// On the display that looks exactly like a working machine: the pc climbs
// and the retired count climbs. It is worth being able to tell those apart.
reg [31:0] rom_words;
reg        rom_ok;

always @(posedge clk_sys or negedge rst_n) begin
    if (!rst_n) begin
        load_req <= 0; load_busy <= 0; dl_d <= 0;
        rom_words <= 0; rom_ok <= 0;
    end else begin
        dl_d <= ioctl_download;
        if (load_busy) begin
            if (load_ack) begin
                load_req  <= 0;
                load_busy <= 0;
                rom_words <= rom_words + 32'd1;
            end
        end else if (ioctl_download && ioctl_wr) begin
            case (ioctl_addr[1:0])
            2'd0: word_buf[31:24] <= ioctl_dout;
            2'd1: word_buf[23:16] <= ioctl_dout;
            2'd2: word_buf[15:8]  <= ioctl_dout;
            2'd3: begin
                load_data <= {word_buf[31:8], ioctl_dout};
                load_addr <= ROM_BASE + {ioctl_addr[24:2], 2'b00};
                load_req  <= 1'b1;
                load_busy <= 1'b1;
            end
            endcase
        end else if (dl_d && !ioctl_download && (ioctl_addr[1:0] != 2'd0)) begin
            // The image need not be a whole number of words -- this one is
            // 4,528,151 bytes -- so the tail is flushed rather than lost.
            load_data <= word_buf;
            load_addr <= ROM_BASE + {ioctl_addr[24:2], 2'b00};
            load_req  <= 1'b1;
            load_busy <= 1'b1;
        end
        // A download that wrote something is a ROM. Latched, so a later
        // reset from the OSD does not throw it away.
        if (dl_d && !ioctl_download && (rom_words != 0)) rom_ok <= 1'b1;
    end
end

assign ioctl_wait = load_busy;

////////////////////////////////////////////////////////////////////////////

wire [31:0] obs_pc, obs_insn, obs_retired;
wire [31:0] obs_ihit, obs_imiss, obs_dhit, obs_dmiss, obs_io, obs_uart;
wire [15:0] sdram_dq_o, sdram_dq_i;
wire        sdram_dq_oe;

assign SDRAM_DQ = sdram_dq_oe ? sdram_dq_o : 16'bZ;
assign sdram_dq_i = SDRAM_DQ;

dr840_machine machine (
    .clk(clk_sys), .rst_n(rst_n), .boot_monitor(status[2]),
    // Held in reset until there is a ROM to run. The loader owns the
    // memory while it is arriving, and before that there is nothing to do.
    .load_en(ioctl_download | load_busy | ~rom_ok),
    .load_addr(load_addr), .load_data(load_data),
    .load_req(load_req), .load_ack(load_ack),
    .SDRAM_A(SDRAM_A), .SDRAM_BA(SDRAM_BA),
    .SDRAM_DQ_O(sdram_dq_o), .SDRAM_DQ_OE(sdram_dq_oe),
    .SDRAM_DQ_I(sdram_dq_i),
    .SDRAM_DQML(SDRAM_DQML), .SDRAM_DQMH(SDRAM_DQMH),
    .SDRAM_nCS(SDRAM_nCS), .SDRAM_nWE(SDRAM_nWE),
    .SDRAM_nRAS(SDRAM_nRAS), .SDRAM_nCAS(SDRAM_nCAS),
    .SDRAM_CKE(SDRAM_CKE), .SDRAM_CLK(SDRAM_CLK),
    .obs_pc(obs_pc), .obs_insn(obs_insn), .obs_retired(obs_retired),
    .obs_ihit(obs_ihit), .obs_imiss(obs_imiss),
    .obs_dhit(obs_dhit), .obs_dmiss(obs_dmiss), .obs_io(obs_io),
    .obs_uart_bytes(obs_uart),
    .uart_txd(UART_TXD), .uart_rxd(UART_RXD),
    .lcd_ce_pix(lcd_ce), .lcd_hs(lcd_hs), .lcd_vs(lcd_vs), .lcd_de(lcd_de),
    .lcd_r(lcd_r), .lcd_g(lcd_g), .lcd_b(lcd_b)
);

assign CLK_VIDEO = clk_sys;

// The machine's own screen, or the debug display over it. Both run the
// same 640x480 raster from the same clock, so switching is a mux.
wire       lcd_ce, lcd_hs, lcd_vs, lcd_de, hud_ce, hud_hs, hud_vs, hud_de;
wire [7:0] lcd_r, lcd_g, lcd_b, hud_r, hud_g, hud_b;
wire       show_hud = status[3];
assign CE_PIXEL = show_hud ? hud_ce : lcd_ce;
assign VGA_HS   = show_hud ? hud_hs : lcd_hs;
assign VGA_VS   = show_hud ? hud_vs : lcd_vs;
assign VGA_DE   = show_hud ? hud_de : lcd_de;
assign VGA_R    = show_hud ? hud_r  : lcd_r;
assign VGA_G    = show_hud ? hud_g  : lcd_g;
assign VGA_B    = show_hud ? hud_b  : lcd_b;

dr840_hud hud (
    .clk(clk_sys), .rst_n(rst_n),
    .ce_pix(hud_ce), .hs(hud_hs), .vs(hud_vs), .de(hud_de),
    .r(hud_r), .g(hud_g), .b(hud_b),
    .v0(obs_pc), .v1(obs_insn), .v2(obs_retired), .v3(obs_ihit),
    .v4(obs_imiss), .v5(obs_dhit), .v6(obs_dmiss), .v7(obs_io),
    .v8(rom_words), .v9(obs_uart)
);

endmodule
