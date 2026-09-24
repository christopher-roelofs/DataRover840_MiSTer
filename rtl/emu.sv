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

wire signed [15:0] audio;
assign AUDIO_L   = audio;
assign AUDIO_R   = audio;
assign AUDIO_S   = 1;         // signed
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

// The panel is 3:2; the bezel raster and the debug display are 4:3.
wire native = ~status[14] & ~status[3];
assign VIDEO_ARX = native ? 13'd3 : 13'd4;
assign VIDEO_ARY = native ? 13'd2 : 13'd3;

localparam CONF_STR = {
    "DataRover840;;",
    "-;",
    // MiSTer parses this extension field in three-character chunks, so a
    // longer one silently becomes two filters that match nothing. The
    // device's own images are named .image; .ima is what three characters
    // of that actually is, and .rom is what anyone would reach for.
    // FS: a file with a save, which the MiSTer keeps as
    // saves/DataRover840/<name>.sav and mounts on the image slot itself,
    // so a ROM picked from the browser brings its own RAM.
    "FS1,ROMIMABIN,Load DataRover ROM;",
    "-;",
    // The option button, held at reset, takes the ROM to the IDT monitor
    // instead of Magic Cap. Takes effect on the next reset.
    "O[2],Boot,Magic Cap,IDT monitor;",
    "O[3],Display,LCD,Debug;",
    "O[9:8],Panel,Off,Grey,Green;",
    // The panel's own 480x320 for the framework's scaler -- its video
    // settings choose the size, and shadow_masks/ has the LCD grid for
    // 3x and 4x -- or the old 640x480 with the panel in a bezel.
    "O[14],Screen,480x320 (3:2),640x480 with bezel;",
    // A Magic Bus AT keyboard, driven by the PS/2 keyboard; its discovery
    // by the ROM matches the reference's access for access.
    "O[4],Keyboard,On,Off;",
    "-;",
    // The RAM, kept. A DataRover's four megabytes are battery-backed and
    // hold everything the user has; here they are an image on the card,
    // read in before the core starts and written back when Magic Cap turns
    // the machine off, or on request. The .mgl mounts it.
    "S0,SAV,Mount RAM image;",
    // A memory card in slot 2: a raw image of its common memory, the
    // reference emulator's own format, formatted by Magic Cap itself. A
    // blank one needs the option key held as it goes in, which is what the
    // re-insert entry does.
    "S1,IMG,Mount card (slot 2);",
    "T[10],Re-insert card with option;",
    // A package to install: the file is read into the SDRAM and offered
    // over the serial port as the computer WinPcLink runs on; in Magic
    // Cap, go to the Storeroom and tap the computer. Offered again on
    // request, for another RAM image.
    "F2,PKG,Install package;",
    "T[11],Offer package again;",
    // The device's UART runs the link at 19200 baud, which a real PC
    // could not change either; this link is not a wire, and hands the
    // bytes over four times as fast, which is as fast as Magic Cap keeps
    // up with (dr840_pclink.sv). Slower, if a package ever needs it.
    "O[13:12],Package link speed,4x,2x,19200 as the device;",
    "T[5],Save RAM now;",
    // A reset that ignores the save: the RAM cleared, Magic Cap set up
    // from nothing. The save is overwritten by the next one.
    "T[15],Start fresh (clear RAM);",
    // Magic Cap turns the machine off after it has sat idle. A MiSTer has
    // no battery to save, so by default the core presses the ON button
    // for it once the RAM has been written: an autosave and a blink,
    // rather than a dark screen.
    "O[6],After idle power-off,Wake at once,Stay off;",
    // The AC adaptor, plugged in or not: Magic Cap's battery gauge shows
    // a lightning bolt while it is, and it never turns itself off when
    // idle -- which is how to have a machine that does not sleep. On
    // Battery it sleeps, and the option above says what happens then.
    "O[16],Power,AC adaptor,Battery;",
    // As the console cores do it: opening the OSD saves, if anything in
    // the RAM has changed since the last save. Off by default: a save is
    // two seconds with the machine held, which is not what opening a menu
    // should cost.
    "O[7],Autosave on OSD,Off,On;",
    "-;",
    "T[0],Reset;",
    "R[0],Reset and close OSD;",
    // A joystick is the pen too: the stick moves it, A touches, B touches
    // with the option key held, and the third button is the ON button.
    "J1,Touch,Touch with option,ON;",
    "V,v",`BUILD_DATE
};

wire [127:0] status;
wire   [1:0] buttons;
wire  [24:0] ps2_mouse;
wire  [10:0] ps2_key;
wire  [31:0] joystick_0;

// The ON button: the joystick's ON button, or F4 on the keyboard (the
// key the reference uses). Magic Cap turns the machine off after it has
// sat idle, and this is what turns it back on.
reg f4_down;
always @(posedge clk_sys) begin
    if (ps2_key[7:0] == 8'h0C && !ps2_key[8]) f4_down <= ps2_key[9];
end

// Two seconds after reset, the mouse's right button is the option key.
reg [27:0] opt_cnt; reg opt_ok;
always @(posedge clk_sys or negedge rst_n) begin
    if (!rst_n) begin opt_cnt <= 28'd0; opt_ok <= 1'b0; end
    else if (!opt_ok) begin
        opt_cnt <= opt_cnt + 28'd1;
        if (opt_cnt == 28'd184_000_000) opt_ok <= 1'b1;
    end
end

// The keyboard, on the Magic Bus. The framework's PS/2 keyboard already
// speaks AT set 2: [7:0] the code, [8] extended, [9] pressed, [10] a
// toggle per event.
reg key_tog, key_ext, key_down; reg [7:0] key_code; reg key_seen;
always @(posedge clk_sys) begin
    if (ps2_key[10] != key_seen) begin
        key_seen <= ps2_key[10];
        // F4 is the ON button, not a key the guest sees; F12 is the
        // framework's and never arrives. Everything else is the guest's:
        // its driver ignores what it does not know.
        if (!(ps2_key[7:0] == 8'h0C && !ps2_key[8])) begin
            key_code <= ps2_key[7:0]; key_ext <= ps2_key[8]; key_down <= ps2_key[9];
            key_tog  <= ~key_tog;
        end
    end
end

// The mouse is the pen. A mouse moves and a pen is somewhere, so the
// movements are summed into a place on the panel, held inside it, and the
// left button is the touch. The panel draws a pointer there, since a
// touch screen shows nothing of its own.
// A joystick moves it too: a pixel every 4 ms while a direction is held
// (250 a second, the panel's width in two), and two after a second.
reg  [8:0] pen_px, pen_py;
reg        mouse_tog;
reg [18:0] joy_tick;
reg [7:0]  joy_held;
wire       joy_any = |joystick_0[3:0];
wire [8:0] joy_step = (joy_held == 8'd255) ? 9'd2 : 9'd1;
always @(posedge clk_sys or negedge rst_n) begin
    if (!rst_n) begin
        pen_px <= 9'd240; pen_py <= 9'd160; mouse_tog <= 1'b0; joy_tick <= 19'd0; joy_held <= 8'd0;
    end else if (ps2_mouse[24] != mouse_tog) begin
        mouse_tog <= ps2_mouse[24];
        // PS/2: byte 1 flags (bit 4, 5 the signs), byte 2 dx, byte 3 dy,
        // y upward.
        pen_px <= clamp_x(pen_px, {ps2_mouse[4], ps2_mouse[15:8]});
        pen_py <= clamp_y(pen_py, {ps2_mouse[5], ps2_mouse[23:16]});
    end else begin
        joy_tick <= (joy_tick == 19'd368_000) ? 19'd0 : joy_tick + 19'd1;
        if (!joy_any) joy_held <= 8'd0;
        else if (joy_tick == 19'd0) begin
            if (joy_held != 8'd255) joy_held <= joy_held + 8'd1;
            // right, left, down, up; the mouse's y is upward, so down is
            // a negative step there.
            if (joystick_0[0])      pen_px <= clamp_x(pen_px, joy_step);
            else if (joystick_0[1]) pen_px <= clamp_x(pen_px, -joy_step);
            if (joystick_0[2])      pen_py <= clamp_y(pen_py, -joy_step);
            else if (joystick_0[3]) pen_py <= clamp_y(pen_py, joy_step);
        end
    end
end
function [8:0] clamp_x(input [8:0] p, input [8:0] d);
    reg signed [10:0] n;
    begin
        n = $signed({2'b00, p}) + $signed({{2{d[8]}}, d});
        clamp_x = (n < 0) ? 9'd0 : (n > 479) ? 9'd479 : n[8:0];
    end
endfunction
function [8:0] clamp_y(input [8:0] p, input [8:0] d);
    reg signed [10:0] n;
    begin
        n = $signed({2'b00, p}) - $signed({{2{d[8]}}, d});
        clamp_y = (n < 0) ? 9'd0 : (n > 319) ? 9'd319 : n[8:0];
    end
endfunction
// A left click is a touch; a right click is a touch with the option key
// held, which is what "hold option and touch" means with a mouse.
// The joystick's A and B likewise.
wire pen_down   = ps2_mouse[0] | ps2_mouse[1] | joystick_0[4] | joystick_0[5];
wire option_key = ps2_mouse[1] | joystick_0[5];
wire         ioctl_download, ioctl_wr;
reg   [31:0] sd_lba;
reg    [1:0] sd_rd, sd_wr;             // slot 0 the RAM image, slot 1 the card
wire   [1:0] sd_ack, img_mounted;
wire         sd_buff_wr, img_readonly;
wire  [13:0] sd_buff_addr;
wire   [7:0] sd_buff_dout;
wire   [7:0] sd_buff_din;
wire  [63:0] img_size;
wire         osd_open = OSD_STATUS;      // the framework's: the menu is open
reg          osd_d, ram_dirty, cimg_d, reins_d;
wire         ram_written, card_written;
wire  [24:0] ioctl_addr;
wire   [7:0] ioctl_dout;
wire         ioctl_wait;
wire  [15:0] ioctl_index;

hps_io #(.CONF_STR(CONF_STR), .VDNUM(2)) hps_io
(
    .clk_sys        (clk_sys),
    .HPS_BUS        (HPS_BUS),
    .buttons        (buttons),
    .status         (status),
    .ps2_mouse      (ps2_mouse),
    .ps2_key        (ps2_key),
    .joystick_0     (joystick_0),
    .ioctl_download (ioctl_download),
    .ioctl_index    (ioctl_index),
    .ioctl_wr       (ioctl_wr),
    .ioctl_addr     (ioctl_addr),
    .ioctl_dout     (ioctl_dout),
    .ioctl_wait     (ioctl_wait),
    .sd_lba         ('{sd_lba, sd_lba}),
    .sd_blk_cnt     ('{6'd31, 6'd31}),     // 16 KB a request: 256 of them for the RAM image
    .sd_rd          (sd_rd),
    .sd_wr          (sd_wr),
    .sd_ack         (sd_ack),
    .sd_buff_addr   (sd_buff_addr),
    .sd_buff_dout   (sd_buff_dout),
    .sd_buff_din    ('{sd_buff_din, sd_buff_din}),
    .sd_buff_wr     (sd_buff_wr),
    .img_mounted    (img_mounted),
    .img_readonly   (img_readonly),
    .img_size       (img_size)
);

wire clk_sys, pll_locked;
pll pll (.refclk(CLK_50M), .rst(1'b0), .outclk_0(clk_sys), .locked(pll_locked));

// "Start fresh": a reset into cleared RAM, the save left unread. It is
// the machine's next save that replaces the file.
reg  fresh_pulse;
wire reset = RESET | status[0] | buttons[1] | ~pll_locked | DBG_FORCE_RESET | fresh_pulse;
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

localparam [24:0] ROM_BASE  = 25'h000_0000;
localparam [24:0] DRAM_BASE = 25'h080_0000;
localparam [24:0] DRAM_END  = 25'h0C0_0000;   // 4 MB fitted

reg  [31:0] word_buf;
reg  [24:0] load_addr;
reg  [31:0] load_data;
reg         load_req, load_busy, dl_d;
reg         load_we, load_burst;
wire        load_ack;
wire [31:0] load_rdata;

// How much ROM has actually been written, and whether any has. Without
// this the core starts on whatever the SDRAM powered up holding -- zeroes,
// which decode as NOP, so it runs forward through blank memory for ever.
// On the display that looks exactly like a working machine: the pc climbs
// and the retired count climbs. It is worth being able to tell those apart.
reg [31:0] rom_words;
reg        rom_present;
// The sum of every word written, shown on the debug display. The HPS
// streams the image with its own pacing and the loader answers with
// back-pressure; a byte lost between them is a wrong word somewhere in
// four and a half megabytes, which the guest finds by executing it, later,
// and looks like anything at all. The sum says whether the load was good
// before anything runs.
reg [31:0] rom_sum;

// And the memory is cleared before the core is let go.
//
// Nothing else clears it. Magic Cap keeps its whole world in RAM and
// expects to find it there after a power cycle -- the real machine's RAM
// is battery-backed -- so what it finds on a MiSTer is the last run's
// memory, or whatever the SDRAM powered up holding. It recognises that as
// its own world, damaged, and spends the boot on "Cleaning up" instead of
// starting. The simulation never saw it: a model's memory begins as
// zeroes, and zeroes are what this makes.
//
// A reset asks for the same walk, because a reset the guest can tell from
// a power cycle is not much of a reset.
reg        clr_run;
reg [24:0] clr_addr;
reg        rst_d;
wire       rom_ok = rom_present & ~clr_run;

// Before the clear, a test. Every boot on the hardware that has gone
// wrong went wrong by using a corrupt word as a pointer, and no
// simulation of the same design has ever taken a fault, so the one thing
// no simulation can vouch for -- the real chip giving back what it was
// given -- is checked here: the four megabytes written with a pattern one
// word at a time, read back with the same sixteen-byte bursts the caches
// use, and every mismatch counted. The count and the first bad address
// are on the status line. It costs half a second at boot.
localparam [2:0] MT_WRITE = 3'd0, MT_READ = 3'd1, MT_ROM = 3'd2, MT_CLEAR = 3'd3,
                 MT_LOAD = 3'd4, MT_SAVE = 3'd5;

// The RAM image: 8192 sectors of 512 bytes through the framework's SD
// interface, a sector at a time through a buffer here. Loading, the HPS
// fills the byte buffer and the loader writes it out a word at a time;
// saving, the loader reads the memory in the caches' bursts into a word
// buffer and the HPS takes bytes from it.
// In 16 KB chunks -- thirty-two sectors a request -- because a request is
// a round trip through the HPS, and one a sector made a save take
// twenty-seven seconds with the core held.
reg  [7:0]  secb [0:16383];           // in: what the HPS wrote
reg  [31:0] secw [0:4095];            // out: what the memory holds
reg  [7:0]  secb_q;
reg  [31:0] secw_q;
reg  [7:0]  chunk;                    // 0..255, of 16 KB
reg         fresh, fresh_d;
reg  [3:0]  fresh_cnt;
// Which image the sector machine is moving: 0 the RAM, 1 the card; where
// it lives in the SDRAM; and how many chunks it is.
reg         cur;
localparam [24:0] CARD2_BASE = 25'h0E0_0000;
reg  [4:0]  card_log2;                // the card's size, 16..21
reg         card_in;                  // in the slot, as the machine sees it
reg         card_dirty;               // written since it was last saved
reg         want_ram_save, want_card_save, want_card_load;
reg  [1:0]  xfer_kind;                // what the borrow is for: 0 RAM save, 1 card save, 2 card load
reg  [27:0] reins_cnt;
reg  [1:0]  reins_st;
reg         opt_force;                // the option key, held by the core for a re-insertion
wire [24:0] xfer_base  = cur ? CARD2_BASE : DRAM_BASE;
wire [7:0]  chunk_last = cur ? (8'd1 << (card_log2 - 5'd14)) - 8'd1 : 8'd255;
wire        sd_ack_c   = cur ? sd_ack[1] : sd_ack[0];
reg  [11:0] wi;                       // word within the chunk
reg  [1:0]  bi;                       // byte within the word
reg  [2:0]  ss;                       // the sector's own state
reg  [31:0] gather;
reg         img_ok;                   // a four-megabyte image is mounted
reg         img_new;                  // an empty one: nothing to load, room to save
reg         img_d;
reg         save_run;                 // the save walk, without a reset
reg         halt_req;                 // hold the core for it
reg  [1:0]  save_st;
reg  [4:0]  idle_cnt;
reg         stop_d, savebtn_d;
reg  [27:0] sd_wait;                  // how long the card has been asked
reg         img_ro;                   // mounted read-only: no saving into it
reg  [7:0]  save_fail;                // saves that timed out, on the status line
wire        mem_idle, stopped;
// The ON button pressed by the core itself, after a power-off it has
// saved through: two seconds after the stop, or when the save is done.
reg        wake_pend, wake;
reg [27:0] wake_cnt;
always @(posedge clk_sys or negedge rst_n) begin
    if (!rst_n) begin wake_pend <= 1'b0; wake <= 1'b0; wake_cnt <= 28'd0; end
    else begin
        if (stopped && !stop_d && !status[6]) begin wake_pend <= 1'b1; wake_cnt <= 28'd0; end
        if (wake_pend) begin
            if (wake_cnt != 28'd184_000_000) wake_cnt <= wake_cnt + 28'd1;
            else if (save_st == 2'd0 && !save_run) begin wake_pend <= 1'b0; wake <= 1'b1; wake_cnt <= 28'd0; end
        end else if (wake) begin
            wake_cnt <= wake_cnt + 28'd1;
            if (wake_cnt == 28'd9_200_000) begin wake <= 1'b0; wake_cnt <= 28'd0; end   // held 100 ms
        end
    end
end
wire on_button = joystick_0[6] | f4_down | wake;
always @(posedge clk_sys) begin
    if (sd_buff_wr) secb[sd_buff_addr[13:0]] <= sd_buff_dout;
    secb_q <= secb[{wi, bi}];
    secw_q <= secw[sd_buff_addr[13:2]];
end
// Big-endian, as the memory is: byte 0 of the word is its top.
assign sd_buff_din = (sd_buff_addr[1:0] == 2'd0) ? secw_q[31:24]
                   : (sd_buff_addr[1:0] == 2'd1) ? secw_q[23:16]
                   : (sd_buff_addr[1:0] == 2'd2) ? secw_q[15:8] : secw_q[7:0];
reg  [2:0]  mt_phase;
// The ROM read back out of the memory and summed again. `rom_sum` is what
// the loader was given; this is what the machine will actually execute,
// and until now nothing had compared the two.
reg  [31:0] rom_back;
wire [24:0] rom_end = {rom_words[22:0], 2'b00};
reg  [1:0]  mt_beat;
reg  [31:0] mt_errors, mt_first;
function [31:0] mt_pattern(input [24:0] a);
    mt_pattern = {a[24:0], 7'd0} ^ ~{7'd0, a[24:0]} ^ 32'hA5A5_A5A5;
endfunction

// Deliberately not reset by the OSD's reset. What this block knows -- that
// a ROM has been loaded -- is not something a reset may forget: forgetting
// it holds the core in reset for ever, with no download coming to let go.
wire hard_rst_n = pll_locked & ~RESET;

////////////////////////////////////////////////////////////////////////////
// A package. Index 2 of the file loader is not a ROM: it goes into the
// SDRAM beyond the cards through the package link's own port, while the
// machine runs -- the user has just walked to the Storeroom and is not
// to be reset -- and is then offered.
wire pkg_dl = ioctl_download && (ioctl_index[5:0] == 6'd2);
wire rom_dl = ioctl_download && !pkg_dl;
// For the machine's load gate, a clock later: from the framework's index
// through this decode into the core's cache was a clock with nothing to
// spare. A ROM's first word is several clocks behind the download's start.
reg  rom_dl_q;
always @(posedge clk_sys) rom_dl_q <= rom_dl;
reg         pdl_d, pkg_wreq, pkg_go_tog;
reg  [24:0] pkg_waddr, pkg_len;
reg  [31:0] pkg_wdata, pkg_sum;
reg  [23:0] pbuf;
wire        pkg_wack;
wire [2:0]  pkg_state;
wire [24:0] pkg_sent;
reg         offer_d;
always @(posedge clk_sys or negedge hard_rst_n) begin
    if (!hard_rst_n) begin
        pdl_d <= 0; pkg_wreq <= 0; pkg_go_tog <= 0; pkg_waddr <= 0; pkg_len <= 0;
        pkg_wdata <= 0; pkg_sum <= 0; pbuf <= 0; offer_d <= 0;
    end else begin
        pdl_d <= pkg_dl; offer_d <= status[11];
        if (pkg_wreq && pkg_wack) pkg_wreq <= 1'b0;
        if (pkg_dl && !pdl_d) begin pkg_len <= 25'd0; pkg_sum <= 32'd0; end
        if (pkg_dl && ioctl_wr) begin
            case (ioctl_addr[1:0])
            // The bytes behind the first are cleared as it arrives, so a
            // tail that is not a whole word sums the same here as there.
            2'd0: pbuf        <= {ioctl_dout, 16'd0};
            2'd1: pbuf[15:0]  <= {ioctl_dout, 8'd0};
            2'd2: pbuf[7:0]   <= ioctl_dout;
            2'd3: begin
                pkg_wdata <= {pbuf, ioctl_dout}; pkg_sum <= pkg_sum + {pbuf, ioctl_dout};
                pkg_waddr <= {ioctl_addr[24:2], 2'b00}; pkg_wreq <= 1'b1;
            end
            endcase
        end else if (pdl_d && !pkg_dl) begin
            // The tail of a package that is not a whole number of words,
            // and the length; then the offer.
            if (ioctl_addr[1:0] != 2'd0) begin
                pkg_wdata <= {pbuf, 8'd0}; pkg_sum <= pkg_sum + {pbuf, 8'd0};
                pkg_waddr <= {ioctl_addr[24:2], 2'b00}; pkg_wreq <= 1'b1;
            end
            pkg_len <= ioctl_addr;
            pkg_go_tog <= ~pkg_go_tog;
        end
        if (status[11] && !offer_d && pkg_len != 25'd0) pkg_go_tog <= ~pkg_go_tog;
    end
end

always @(posedge clk_sys or negedge hard_rst_n) begin
    if (!hard_rst_n) begin
        load_req <= 0; load_busy <= 0; dl_d <= 0; rst_d <= 0;
        rom_words <= 0; rom_present <= 0; clr_run <= 0; clr_addr <= 0; rom_sum <= 0;
        load_we <= 1; load_burst <= 0; mt_phase <= MT_WRITE; mt_beat <= 0; rom_back <= 0;
        sd_lba <= 0; sd_rd <= 0; sd_wr <= 0; chunk <= 0; wi <= 0; bi <= 0; ss <= 0; gather <= 0;
        cur <= 0; card_log2 <= 5'd21; card_in <= 0; card_dirty <= 0; xfer_kind <= 0;
        want_ram_save <= 0; want_card_save <= 0; want_card_load <= 0;
        reins_cnt <= 0; reins_st <= 0; opt_force <= 0;
        img_ok <= 0; img_new <= 0; img_d <= 0; save_run <= 0; halt_req <= 0; save_st <= 0; idle_cnt <= 0;
        sd_wait <= 0; img_ro <= 0; save_fail <= 0; osd_d <= 0; ram_dirty <= 0; cimg_d <= 0; reins_d <= 0;
        stop_d <= 0; savebtn_d <= 0;
        fresh <= 0; fresh_d <= 0; fresh_cnt <= 0; fresh_pulse <= 0;
        mt_errors <= 0; mt_first <= 32'hFFFF_FFFF;
    end else begin
        dl_d  <= rom_dl;
        rst_d <= reset;
        fresh_d <= status[15];
        if (status[15] && !fresh_d && rom_present) begin fresh <= 1'b1; fresh_cnt <= 4'd15; end
        fresh_pulse <= (fresh_cnt != 4'd0);
        if (fresh_cnt != 4'd0) fresh_cnt <= fresh_cnt - 4'd1;
        if (load_busy) begin
            if (load_ack) begin
                if (!clr_run && !save_run) begin
                    load_req  <= 0;
                    load_busy <= 0;
                    rom_words <= rom_words + 32'd1;
                    rom_sum   <= rom_sum + load_data;
                end else if (mt_phase == MT_READ || mt_phase == MT_ROM || mt_phase == MT_SAVE) begin
                    // Four beats to a burst; the request holds through them.
                    if (mt_phase == MT_SAVE) begin
                        secw[{wi[11:2], mt_beat}] <= load_rdata;
                    end else if (mt_phase == MT_ROM) begin
                        if (clr_addr + {mt_beat, 2'b00} < rom_end)
                            rom_back <= rom_back + load_rdata;
                    end else if (load_rdata != mt_pattern(clr_addr + {mt_beat, 2'b00})) begin
                        mt_errors <= mt_errors + 32'd1;
                        if (mt_first == 32'hFFFF_FFFF)
                            mt_first <= {7'd0, clr_addr + {mt_beat, 2'b00}};
                    end
                    mt_beat <= mt_beat + 2'd1;
                    if (mt_beat == 2'd3) begin
                        load_req  <= 0;
                        load_busy <= 0;
                        clr_addr  <= clr_addr + 25'd16;
                        wi        <= wi + 12'd4;
                    end
                end else begin
                    load_req  <= 0;
                    load_busy <= 0;
                end
            end
        end else if (mt_phase == MT_LOAD && (clr_run || save_run)) begin
            // A sector in from the image, then out to the memory.
            case (ss)
            3'd0: begin sd_lba <= {19'd0, chunk, 5'd0}; sd_rd <= cur ? 2'b10 : 2'b01; sd_wait <= 28'd0; ss <= 3'd1; end
            3'd1: if (sd_ack_c) begin sd_rd <= 2'b00; ss <= 3'd2; end
                  else if (sd_wait == 28'd92_000_000) begin
                      // A second without the card answering. For the RAM:
                      // nothing to load, so the memory is cleared instead
                      // and the machine starts clean rather than never.
                      // For a card: it is not there after all.
                      sd_rd <= 2'b00;
                      if (cur) begin save_run <= 1'b0; card_in <= 1'b0; end
                      else begin img_ok <= 1'b0; mt_phase <= MT_CLEAR; clr_addr <= DRAM_BASE; end
                  end else sd_wait <= sd_wait + 28'd1;
            3'd2: if (!sd_ack_c) begin wi <= 12'd0; bi <= 2'd0; ss <= 3'd3; end
            3'd3: ss <= 3'd4;                          // the byte's read is a cycle behind
            3'd4: ss <= 3'd5;
            3'd5: begin
                gather <= {gather[23:0], secb_q};
                bi <= bi + 2'd1;
                ss <= (bi == 2'd3) ? 3'd6 : 3'd3;
            end
            3'd6: begin
                load_addr  <= xfer_base + {3'd0, chunk, wi, 2'b00};
                load_data  <= gather;
                load_we    <= 1'b1;
                load_burst <= 1'b0;
                load_req   <= 1'b1;
                load_busy  <= 1'b1;
                wi <= wi + 12'd1;
                if (wi == 12'd4095) begin
                    chunk <= chunk + 8'd1;
                    ss    <= 3'd0;
                    if (chunk == chunk_last) begin
                        if (clr_run) clr_run <= 1'b0;
                        else begin save_run <= 1'b0; card_in <= 1'b1; card_dirty <= 1'b0; end
                    end
                end else ss <= 3'd3;
            end
            default: ss <= 3'd0;
            endcase
        end else if (mt_phase == MT_SAVE && save_run) begin
            // A sector out of the memory in bursts, then away to the image.
            case (ss)
            3'd0: begin
                // A burst of four words; after the last of the sector's
                // thirty-two, the sector goes to the image.
                load_addr  <= xfer_base + {3'd0, chunk, wi, 2'b00};
                load_we    <= 1'b0;
                load_burst <= 1'b1;
                mt_beat    <= 2'd0;
                load_req   <= 1'b1;
                load_busy  <= 1'b1;
                if (wi == 12'd4092) ss <= 3'd7;
            end
            3'd7: begin sd_lba <= {19'd0, chunk, 5'd0}; sd_wr <= cur ? 2'b10 : 2'b01; sd_wait <= 28'd0; ss <= 3'd1; end
            3'd1: if (sd_ack_c) begin sd_wr <= 2'b00; ss <= 3'd2; end
                  else if (sd_wait == 28'd92_000_000) begin
                      // The card is not taking it: give the machine back.
                      sd_wr <= 2'b00; save_run <= 1'b0; save_fail <= save_fail + 8'd1;
                  end else sd_wait <= sd_wait + 28'd1;
            3'd2: if (!sd_ack_c) begin
                wi <= 12'd0;
                chunk <= chunk + 8'd1;
                ss  <= 3'd0;
                if (chunk == chunk_last) begin save_run <= 1'b0; if (cur) card_dirty <= 1'b0; end
            end
            default: ss <= 3'd0;
            endcase
        end else if (clr_run) begin
            if (clr_addr == ((mt_phase == MT_ROM) ? ((rom_end + 25'd15) & ~25'd15)
                                                  : DRAM_END)) begin
                case (mt_phase)
                MT_WRITE: begin mt_phase <= MT_READ;  clr_addr <= DRAM_BASE; end
                MT_READ:  begin mt_phase <= MT_ROM;   clr_addr <= 25'd0;     end
                MT_ROM:   begin
                    // What the memory held last time, if there is an image;
                    // otherwise nothing.
                    if (img_ok && !fresh) begin mt_phase <= MT_LOAD; cur <= 1'b0; chunk <= 8'd0; ss <= 3'd0; end
                    else begin mt_phase <= MT_CLEAR; clr_addr <= DRAM_BASE; end
                    fresh <= 1'b0;
                end
                default:  clr_run <= 1'b0;
                endcase
            end else begin
                load_addr  <= clr_addr;
                load_data  <= (mt_phase == MT_WRITE) ? mt_pattern(clr_addr) : 32'd0;
                load_we    <= (mt_phase == MT_WRITE) || (mt_phase == MT_CLEAR);
                load_burst <= (mt_phase == MT_READ)  || (mt_phase == MT_ROM);
                mt_beat    <= 2'd0;
                load_req   <= 1'b1;
                load_busy  <= 1'b1;
                if (mt_phase == MT_WRITE || mt_phase == MT_CLEAR)
                    clr_addr <= clr_addr + 25'd4;
            end
        end else if (rom_dl && ioctl_wr) begin
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
        end else if (dl_d && !rom_dl && (ioctl_addr[1:0] != 2'd0)) begin
            // The image need not be a whole number of words -- this one is
            // 4,528,151 bytes -- so the tail is flushed rather than lost.
            load_data <= word_buf;
            load_addr <= ROM_BASE + {ioctl_addr[24:2], 2'b00};
            load_req  <= 1'b1;
            load_busy <= 1'b1;
        end
        // A download that wrote something is a ROM, and then the memory
        // is walked before the core sees any of it.
        if (rom_dl && !dl_d) begin rom_words <= 32'd0; rom_sum <= 32'd0; end
        if (dl_d && !rom_dl && (rom_words != 0)) begin
            rom_present <= 1'b1;
            clr_run     <= 1'b1;
            clr_addr    <= DRAM_BASE;
            mt_phase    <= MT_WRITE;
            mt_errors   <= 32'd0; mt_first <= 32'hFFFF_FFFF; rom_back <= 32'd0;
        end else if (rst_d && !reset && rom_present) begin
            clr_run  <= 1'b1;
            clr_addr <= DRAM_BASE;
            mt_phase <= MT_WRITE;
            save_run <= 1'b0; halt_req <= 1'b0; save_st <= 2'd0;
            sd_rd <= 2'b00; sd_wr <= 2'b00; ss <= 3'd0; chunk <= 8'd0; wi <= 12'd0; cur <= 1'b0;
            want_ram_save <= 1'b0; want_card_save <= 1'b0;
            mt_errors <= 32'd0; mt_first <= 32'hFFFF_FFFF; rom_back <= 32'd0;
        end
        // The loader's own writes are whole words, not bursts.
        if (rom_dl) begin load_we <= 1'b1; load_burst <= 1'b0; end

        // An image mounted: remembered, and if the machine is already
        // running, loaded now -- which is a power cycle into it.
        img_d <= img_mounted[0]; cimg_d <= img_mounted[1];
        if (img_mounted[0] && !img_d) begin
            img_ok  <= (img_size == 64'd4194304);
            img_new <= (img_size == 64'd0);
            img_ro  <= img_readonly;
            if (img_size == 64'd4194304 && rom_present && !ioctl_download && !clr_run && !save_run) begin
                clr_run <= 1'b1; mt_phase <= MT_LOAD; cur <= 1'b0; chunk <= 8'd0; ss <= 3'd0;
            end
        end
        // A card: a power of two from 64 KiB to 2 MiB, loaded into the
        // card region through the borrow and then present; anything else,
        // or nothing, is the slot empty.
        if (img_mounted[1] && !cimg_d) begin
            card_in <= 1'b0; want_card_load <= 1'b0; want_card_save <= 1'b0;
            if (img_size >= 64'd65536 && img_size <= 64'd2097152 && (img_size & (img_size - 64'd1)) == 64'd0) begin
                card_log2 <= (img_size == 64'd65536) ? 5'd16 : (img_size == 64'd131072) ? 5'd17
                           : (img_size == 64'd262144) ? 5'd18 : (img_size == 64'd524288) ? 5'd19
                           : (img_size == 64'd1048576) ? 5'd20 : 5'd21;
                want_card_load <= 1'b1;
            end
        end

        // A save: when the ROM turns the machine off, or on request. The
        // core is held, the memory waited for, and then borrowed.
        stop_d <= stopped; savebtn_d <= status[5]; osd_d <= osd_open;
        if (ram_written)  ram_dirty  <= 1'b1;
        if (card_written) card_dirty <= 1'b1;
        // What wants doing: the RAM saved when the ROM turns the machine
        // off or on request (and, if the option says, when the OSD opens);
        // the card saved along with it, and always when the OSD opens
        // with it written to, since the OSD is where a card is ejected.
        if ((stopped && !stop_d) || (status[5] && !savebtn_d) ||
            (osd_open && !osd_d && ram_dirty && status[7])) begin
            want_ram_save <= 1'b1;
            if (card_in && card_dirty) want_card_save <= 1'b1;
        end
        if (osd_open && !osd_d && card_in && card_dirty) want_card_save <= 1'b1;
        // One at a time, with the core held and the memory waited for.
        case (save_st)
        2'd0: if (rom_ok && !clr_run && !ioctl_download &&
                  (want_card_load || (want_ram_save && (img_ok || img_new) && !img_ro) || want_card_save)) begin
                  xfer_kind <= want_card_load ? 2'd2 : want_ram_save ? 2'd0 : 2'd1;
                  halt_req <= 1'b1; idle_cnt <= 5'd0; save_st <= 2'd1;
              end
        2'd1: begin
                  idle_cnt <= mem_idle ? idle_cnt + 5'd1 : 5'd0;
                  if (idle_cnt == 5'd31) begin
                      save_run <= 1'b1; chunk <= 8'd0; wi <= 12'd0; ss <= 3'd0; save_st <= 2'd2;
                      case (xfer_kind)
                      2'd0: begin mt_phase <= MT_SAVE; cur <= 1'b0; want_ram_save <= 1'b0; ram_dirty <= 1'b0; end
                      2'd1: begin mt_phase <= MT_SAVE; cur <= 1'b1; want_card_save <= 1'b0; end
                      default: begin mt_phase <= MT_LOAD; cur <= 1'b1; want_card_load <= 1'b0; end
                      endcase
                  end
              end
        2'd2: if (!save_run && !load_busy) begin halt_req <= 1'b0; save_st <= 2'd0; end
        default: save_st <= 2'd0;
        endcase

        // Re-insertion with the option key held: out for a tenth of a
        // second, then in with the key down for three, which is how a
        // blank card is offered for setting up.
        reins_d <= status[10];
        case (reins_st)
        2'd0: if (status[10] && !reins_d && card_in) begin card_in <= 1'b0; reins_cnt <= 28'd0; reins_st <= 2'd1; end
        2'd1: begin reins_cnt <= reins_cnt + 28'd1;
                    if (reins_cnt == 28'd9_200_000) begin opt_force <= 1'b1; reins_cnt <= 28'd0; reins_st <= 2'd2; end end
        2'd2: begin reins_cnt <= reins_cnt + 28'd1;
                    if (reins_cnt == 28'd4_600_000) card_in <= 1'b1;            // in, half a second after the key
                    if (reins_cnt == 28'd260_000_000) begin opt_force <= 1'b0; reins_st <= 2'd0; end end   // ~2.8 s: the count's width
        default: reins_st <= 2'd0;
        endcase
    end
end

assign ioctl_wait = load_busy | pkg_wreq | pkg_wack;

////////////////////////////////////////////////////////////////////////////

wire [31:0] obs_pc, obs_insn, obs_retired;
wire [31:0] obs_ihit, obs_imiss, obs_dhit, obs_dmiss, obs_io, obs_uart;
wire [31:0] obs_resets, obs_exc, obs_faults, obs_last_epc, obs_last_bad;
wire [31:0] dbg_pen;     // M on the status line: the pen, while the memory test stays clean
wire [15:0] sdram_dq_o, sdram_dq_i;
wire        sdram_dq_oe;

assign SDRAM_DQ = sdram_dq_oe ? sdram_dq_o : 16'bZ;
assign sdram_dq_i = SDRAM_DQ;

// How far a save or load has got, for the bar the panel shows meanwhile:
// the RAM is 256 chunks of 16 KB, a card 2^(log2 - 14) of them.
wire [7:0] xfer_prog = !save_run ? 8'd0 : !cur ? chunk : (chunk << (5'd22 - card_log2));

dr840_machine machine (
    // The option key: IOCTRL pin 3, low while held. The right mouse button
    // is it, as in the reference's window. On the device the same button
    // held at power-on takes the ROM to the monitor; here that is the OSD's
    // Boot option alone, so a mouse resting on its button across a reset
    // cannot do it by accident: the button counts only once the ROM has
    // been running for two seconds.
    .clk(clk_sys), .rst_n(rst_n), .boot_monitor(status[2] | (option_key & opt_ok) | opt_force),
    .pen_down(pen_down), .pen_px(pen_px), .pen_py(pen_py), .on_button(on_button), .ac_in(~status[16]),
    .kbd_attached(~status[4]),
    .card_present({card_in, 1'b0}), .card_log2_0(5'd21), .card_log2_1(card_log2), .key_tog(key_tog), .key_code(key_code), .key_ext(key_ext), .key_down(key_down),
    // Held in reset until there is a ROM to run. The loader owns the
    // memory while it is arriving, and before that there is nothing to do.
    .load_en(rom_dl_q | (load_busy & ~save_run) | ~rom_ok),
    .pkg_go_tog(pkg_go_tog), .pkg_speed(status[13:12]), .pkg_len(pkg_len), .pkg_waddr(pkg_waddr), .pkg_wdata(pkg_wdata),
    .pkg_wreq(pkg_wreq), .pkg_wack(pkg_wack), .pkg_state(pkg_state), .pkg_sent(pkg_sent),
    .mem_borrow(save_run), .hold(halt_req), .blank(save_run | halt_req), .progress(xfer_prog), .tint(status[9:8]), .native(native),
    .mem_idle(mem_idle), .stopped(stopped), .ram_written(ram_written), .card_written(card_written),
    .load_addr(load_addr), .load_data(load_data),
    .load_we(load_we), .load_burst(load_burst), .load_rdata(load_rdata),
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
    .obs_uart_bytes(obs_uart), .obs_resets(obs_resets), .obs_exc(obs_exc),
    .obs_faults(obs_faults), .obs_last_epc(obs_last_epc), .obs_last_bad(obs_last_bad),
    .dbg_pen(dbg_pen), .audio(audio),
    .uart_txd(guest_txd), .uart_rxd(UART_RXD),
    .lcd_ce_pix(lcd_ce), .lcd_hs(lcd_hs), .lcd_vs(lcd_vs), .lcd_de(lcd_de),
    .lcd_r(lcd_r), .lcd_g(lcd_g), .lcd_b(lcd_b)
);

// The serial port is the guest's when the guest is the monitor, which
// talks on it. Magic Cap never does, so then it carries the machine's own
// status line instead (rtl/dr840_status.sv), which scripts/serial reads.
wire guest_txd, status_txd;
dr840_status #(.CLK_HZ(92_000_000)) status_line (
    .clk(clk_sys), .rst_n(rst_n),
    .v0(obs_resets), .v1(obs_exc), .v2(rom_sum), .v3(obs_pc), .v4(obs_retired),
    .v5(obs_faults), .v6(obs_last_epc), .v7(obs_last_bad),
    .v8(mt_errors != 32'd0 ? mt_errors : dbg_pen),
    // A: the RAM image's state -- mounted, read-only, the walk's phase and
    // sector state, the card handshake, saves that failed, and the sector.
    .v9({img_ok, img_ro, clr_run, save_run, halt_req, save_st, mt_phase[2:0], ss, |sd_rd, |sd_wr, sd_ack_c, save_fail[2:0],
         // and whether the ROM read back as it was sent: a 6 MB image once
         // arrived with one bit wrong, and ran to a white screen.
         (rom_back != rom_sum), card_in, card_dirty, 2'd0, chunk}),
    // K, L: the package link's state and the package's length, and the
    // package summed as it was loaded.
    .v10({pkg_state, 4'd0, pkg_len}), .v11(pkg_sum),
    .txd(status_txd)
);
assign UART_TXD = status[2] ? guest_txd : status_txd;

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
    .v0(obs_pc), .v1(obs_insn), .v2(obs_retired), .v3(obs_resets),
    .v4(obs_exc), .v5(rom_sum), .v6(obs_dmiss), .v7(obs_io),
    .v8(rom_words), .v9(obs_uart)
);

endmodule
