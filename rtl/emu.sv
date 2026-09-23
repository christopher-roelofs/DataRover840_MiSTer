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
    // A Magic Bus AT keyboard, driven by the PS/2 keyboard. Off until it
    // has been argued into agreement with the reference.
    "O[4],Keyboard,Off,On;",
    "-;",
    "T[0],Reset;",
    "R[0],Reset and close OSD;",
    "V,v",`BUILD_DATE
};

wire [127:0] status;
wire   [1:0] buttons;
wire  [24:0] ps2_mouse;
wire  [10:0] ps2_key;
wire  [31:0] joystick_0;

// The ON button: the first joystick button, or F4 on the keyboard (the
// key the reference uses). Magic Cap turns the machine off after it has
// sat idle, and this is what turns it back on.
reg f4_down;
always @(posedge clk_sys) begin
    if (ps2_key[7:0] == 8'h0C && !ps2_key[8]) f4_down <= ps2_key[9];
end
wire on_button = joystick_0[4] | f4_down;

// The keyboard, on the Magic Bus. The framework's PS/2 keyboard already
// speaks AT set 2: [7:0] the code, [8] extended, [9] pressed, [10] a
// toggle per event.
reg key_tog, key_ext, key_down; reg [7:0] key_code; reg key_seen;
always @(posedge clk_sys) begin
    if (ps2_key[10] != key_seen) begin
        key_seen <= ps2_key[10];
        key_code <= ps2_key[7:0]; key_ext <= ps2_key[8]; key_down <= ps2_key[9];
        key_tog  <= ~key_tog;
    end
end

// The mouse is the pen. A mouse moves and a pen is somewhere, so the
// movements are summed into a place on the panel, held inside it, and the
// left button is the touch. The panel draws a pointer there, since a
// touch screen shows nothing of its own.
reg  [8:0] pen_px, pen_py;
reg        mouse_tog;
always @(posedge clk_sys or negedge rst_n) begin
    if (!rst_n) begin
        pen_px <= 9'd240; pen_py <= 9'd160; mouse_tog <= 1'b0;
    end else if (ps2_mouse[24] != mouse_tog) begin
        mouse_tog <= ps2_mouse[24];
        // PS/2: byte 1 flags (bit 4, 5 the signs), byte 2 dx, byte 3 dy,
        // y upward.
        pen_px <= clamp_x(pen_px, {ps2_mouse[4], ps2_mouse[15:8]});
        pen_py <= clamp_y(pen_py, {ps2_mouse[5], ps2_mouse[23:16]});
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
wire pen_down = ps2_mouse[0];
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
    .ps2_mouse      (ps2_mouse),
    .ps2_key        (ps2_key),
    .joystick_0     (joystick_0),
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
localparam [2:0] MT_WRITE = 3'd0, MT_READ = 3'd1, MT_ROM = 3'd2, MT_CLEAR = 3'd3;
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

always @(posedge clk_sys or negedge hard_rst_n) begin
    if (!hard_rst_n) begin
        load_req <= 0; load_busy <= 0; dl_d <= 0; rst_d <= 0;
        rom_words <= 0; rom_present <= 0; clr_run <= 0; clr_addr <= 0; rom_sum <= 0;
        load_we <= 1; load_burst <= 0; mt_phase <= MT_WRITE; mt_beat <= 0; rom_back <= 0;
        mt_errors <= 0; mt_first <= 32'hFFFF_FFFF;
    end else begin
        dl_d  <= ioctl_download;
        rst_d <= reset;
        if (load_busy) begin
            if (load_ack) begin
                if (!clr_run) begin
                    load_req  <= 0;
                    load_busy <= 0;
                    rom_words <= rom_words + 32'd1;
                    rom_sum   <= rom_sum + load_data;
                end else if (mt_phase == MT_READ || mt_phase == MT_ROM) begin
                    // Four beats to a burst; the request holds through them.
                    if (mt_phase == MT_ROM) begin
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
                    end
                end else begin
                    load_req  <= 0;
                    load_busy <= 0;
                end
            end
        end else if (clr_run) begin
            if (clr_addr == ((mt_phase == MT_ROM) ? ((rom_end + 25'd15) & ~25'd15)
                                                  : DRAM_END)) begin
                case (mt_phase)
                MT_WRITE: begin mt_phase <= MT_READ;  clr_addr <= DRAM_BASE; end
                MT_READ:  begin mt_phase <= MT_ROM;   clr_addr <= 25'd0;     end
                MT_ROM:   begin mt_phase <= MT_CLEAR; clr_addr <= DRAM_BASE; end
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
        // A download that wrote something is a ROM, and then the memory
        // is walked before the core sees any of it.
        if (ioctl_download && !dl_d) begin rom_words <= 32'd0; rom_sum <= 32'd0; end
        if (dl_d && !ioctl_download && (rom_words != 0)) begin
            rom_present <= 1'b1;
            clr_run     <= 1'b1;
            clr_addr    <= DRAM_BASE;
            mt_phase    <= MT_WRITE;
            mt_errors   <= 32'd0; mt_first <= 32'hFFFF_FFFF; rom_back <= 32'd0;
        end else if (rst_d && !reset && rom_present) begin
            clr_run  <= 1'b1;
            clr_addr <= DRAM_BASE;
            mt_phase <= MT_WRITE;
            mt_errors <= 32'd0; mt_first <= 32'hFFFF_FFFF; rom_back <= 32'd0;
        end
        // The loader's own writes are whole words, not bursts.
        if (ioctl_download) begin load_we <= 1'b1; load_burst <= 1'b0; end
    end
end

assign ioctl_wait = load_busy;

////////////////////////////////////////////////////////////////////////////

wire [31:0] obs_pc, obs_insn, obs_retired;
wire [31:0] obs_ihit, obs_imiss, obs_dhit, obs_dmiss, obs_io, obs_uart;
wire [31:0] obs_resets, obs_exc, obs_faults, obs_last_epc, obs_last_bad;
wire [31:0] dbg_pen;     // M on the status line: the pen, while the memory test stays clean
wire [15:0] sdram_dq_o, sdram_dq_i;
wire        sdram_dq_oe;

assign SDRAM_DQ = sdram_dq_oe ? sdram_dq_o : 16'bZ;
assign sdram_dq_i = SDRAM_DQ;

dr840_machine machine (
    .clk(clk_sys), .rst_n(rst_n), .boot_monitor(status[2]),
    .pen_down(pen_down), .pen_px(pen_px), .pen_py(pen_py), .on_button(on_button),
    .kbd_attached(status[4]), .key_tog(key_tog), .key_code(key_code), .key_ext(key_ext), .key_down(key_down),
    // Held in reset until there is a ROM to run. The loader owns the
    // memory while it is arriving, and before that there is nothing to do.
    .load_en(ioctl_download | load_busy | ~rom_ok),
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
    .v8(mt_errors != 32'd0 ? mt_errors : dbg_pen), .v9(rom_back),
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
