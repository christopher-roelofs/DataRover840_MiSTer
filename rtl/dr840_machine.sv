//
// dr840_machine.sv - the DataRover, as much of it as exists.
//
// One clock. The SDRAM and its controller run at it; the core and its
// caches advance on every second edge, which is the 47.5 MHz they close at.
// See the Clocking section of the README, and the multicycle constraints in
// the .sdc -- without those the fitter has to close the core at the
// memory's rate and cannot.
//
// While the HPS is writing the ROM into the SDRAM the loader owns the
// memory port and the core is held in reset. It writes whole words, because
// the controller has no byte enables and a byte at a time would be a
// read-modify-write for every byte of a four megabyte image.
//
`default_nettype none

module dr840_machine (
    input  wire        clk,          // 92 MHz: SDRAM, and the core halved
    input  wire        rst_n,

    // ---- ROM load, from the HPS. Whole words, big-endian.
    input  wire        load_en,      // the loader owns the memory
    input  wire [24:0] load_addr,
    input  wire [31:0] load_data,
    input  wire        load_req,
    input  wire        load_we,       // and now reads too, in bursts if asked
    input  wire        load_burst,
    output wire        load_ack,
    output wire [31:0] load_rdata,

    // ---- SDRAM
    output wire [12:0] SDRAM_A,
    output wire [1:0]  SDRAM_BA,
    output wire [15:0] SDRAM_DQ_O,
    output wire        SDRAM_DQ_OE,
    input  wire [15:0] SDRAM_DQ_I,
    output wire        SDRAM_DQML,
    output wire        SDRAM_DQMH,
    output wire        SDRAM_nCS,
    output wire        SDRAM_nWE,
    output wire        SDRAM_nRAS,
    output wire        SDRAM_nCAS,
    output wire        SDRAM_CKE,
    output wire        SDRAM_CLK,

    // ---- the debug serial port. UART A is where the monitor prints.
    output wire        uart_txd,
    input  wire        uart_rxd,
    input  wire        boot_monitor,    // option button held at reset

    // The pen, in panel pixels; the pointer is drawn on the panel where
    // it is, and the codec sees it in its own counts.
    input  wire        pen_down,
    input  wire [8:0]  pen_px,          // 0..479
    input  wire [8:0]  pen_py,          // 0..319

    // The panel, as a raster.
    output wire        lcd_ce_pix,
    output wire        lcd_hs,
    output wire        lcd_vs,
    output wire        lcd_de,
    output wire [7:0]  lcd_r,
    output wire [7:0]  lcd_g,
    output wire [7:0]  lcd_b,

    // ---- what a debug display can show
    output wire [31:0] obs_pc,
    output wire [31:0] obs_insn,
    output reg  [31:0] obs_retired,
    output wire [31:0] obs_ihit,
    output wire [31:0] obs_imiss,
    output wire [31:0] obs_dhit,
    output wire [31:0] obs_dmiss,
    output wire [31:0] obs_io,
    output wire [31:0] obs_uart_bytes,
    // How many times the core has been let out of reset, and how many
    // exceptions it has taken: the difference between a machine that was
    // reset and one that restarted itself is exactly the difference
    // between a clean boot and one that finds its memory in use.
    output reg  [31:0] obs_resets,
    output reg  [31:0] obs_exc,
    // Exceptions that are not interrupts, and the last of them: its code
    // in the top byte of the count, its EPC, and Cause.IP at the last
    // interrupt in the top bits of the EPC line's neighbour. An interrupt
    // storm and a fault storm look the same on a screen and are nothing
    // alike.
    output reg  [31:0] obs_faults,
    output reg  [31:0] obs_last_epc,
    output reg  [31:0] obs_last_bad
);

    // The core's clock enable: every second edge of the memory's clock.
    reg cdiv;
    always @(posedge clk or negedge rst_n)
        if (!rst_n) cdiv <= 1'b0; else cdiv <= ~cdiv;
    wire cen = cdiv;

    // The core is held in reset until the ROM is in place.
    wire core_rst_n = rst_n & ~load_en;

    wire [31:0] ia, ird, da, dwd, drd;
    wire        ireq, ibur, iack, ierr, dreq, dbur, dwe, dack, derr;
    wire [3:0]  dbe;
    wire        retire_valid;
    wire        exc_valid;
    wire [4:0]  exc_code;
    wire [31:0] exc_epc;
    wire [5:0]  exc_ip;
    wire [31:0] exc_bad;

    r3900_cached cpu (
        .clk(clk), .cen(cen), .rst_n(core_rst_n),
        .imem_addr(ia), .imem_req(ireq), .imem_burst(ibur),
        .imem_ack(iack), .imem_rdata(ird), .imem_err(ierr),
        .dmem_addr(da), .dmem_req(dreq), .dmem_burst(dbur), .dmem_we(dwe),
        .dmem_be(dbe), .dmem_wdata(dwd), .dmem_ack(dack), .dmem_rdata(drd),
        .dmem_err(derr),
        .irq_in(soc_irq),
        .retire_valid(retire_valid), .retire_pc(obs_pc),
        .retire_insn(obs_insn), .retire_next_pc(),
        .exc_valid(exc_valid), .exc_code(exc_code), .exc_epc(exc_epc), .exc_ip(exc_ip), .exc_bad(exc_bad),
        .ihit_count(obs_ihit), .imiss_count(obs_imiss),
        .dhit_count(obs_dhit), .dmiss_count(obs_dmiss)
    );

    // Retired instructions, counted on the core's own edges: the retire
    // pulse stands for a whole core period, so counting it per memory clock
    // would count everything twice.
    always @(posedge clk or negedge core_rst_n)
        if (!core_rst_n)                obs_retired <= 32'd0;
        else if (cen && retire_valid)   obs_retired <= obs_retired + 32'd1;

    // Neither of these is reset by the core's reset, which is the point.
    reg core_rst_d;
    reg fault_new;
    always @(posedge clk) begin
        core_rst_d <= core_rst_n;
        if (!rst_n) begin
            obs_resets <= 32'd0; obs_exc <= 32'd0; obs_faults <= 32'd0; obs_last_epc <= 32'd0;
            obs_last_bad <= 32'd0; fault_new <= 1'b0;
        end else begin
            if (core_rst_n && !core_rst_d) obs_resets <= obs_resets + 32'd1;
            // The first fault somewhere new. A boot takes a BREAK at one
            // place on the way up, and the OS asserts with BREAK, so the
            // first fault at any other EPC is the assertion or the bus
            // error that starts the trouble; the last fault is only the
            // trouble's consequence. `obs_last_epc` holds the first fault's
            // EPC until a second place is seen, then that one, for good.
            if (cen && exc_valid && core_rst_n && exc_code != 5'd0) begin
                obs_faults[23:0] <= obs_faults[23:0] + 24'd1;
                if (obs_faults[23:0] == 24'd0) begin
                    obs_last_epc <= exc_epc;                  // the known one
                end else if (!fault_new && exc_epc != obs_last_epc) begin
                    fault_new        <= 1'b1;
                    obs_faults[31:24] <= {3'd0, exc_code};
                    obs_last_epc     <= exc_epc;
                    obs_last_bad     <= exc_bad;
                end
            end
            if (cen && retire_valid && core_rst_n &&
                (obs_pc == 32'h8000_0080 || obs_pc == 32'hBFC0_0180))
                obs_exc <= obs_exc + 32'd1;
        end
    end

    wire [24:0] bram_addr;
    wire        bram_req, bram_burst, bram_we, bram_ack, bram_busy;
    wire [3:0]  bram_be;
    wire [31:0] bram_wdata, ram_rdata;

    wire [31:0] io_addr, io_wdata, io_rdata;
    wire        io_req, io_we, io_ack, io_err;
    wire [3:0]  io_be;
    wire [5:0]  soc_irq;
    wire [31:0] vid_ctrl1, vid_ctrl2, vid_ctrl3;

    // Pixel to converter count, on the reference's calibration of this
    // panel: 85..836 across the 480 and 69..791 down the 320. The ratios
    // are 751/479 and 722/319, as 401/256 and 579/256: a count out at the
    // far edge, and the OS calibrates anyway.
    // Registered: a pen moves at a human's speed, and the multiply and
    // the codec's arithmetic behind it were ten nanoseconds in one clock.
    reg  [17:0] pen_xm, pen_ym;
    reg  [9:0]  pen_x, pen_y;
    always @(posedge clk) begin
        pen_xm <= pen_px * 9'd401;
        pen_ym <= pen_py * 9'd579;
        pen_x  <= 10'd85 + pen_xm[17:8];
        pen_y  <= 10'd69 + pen_ym[17:8];
    end

    // The LCD controller: scans the framebuffer out of the SDRAM through
    // the board, onto a 640x480 raster.
    wire [31:0] va, vrd;
    wire        vreq, vack;
    dr840_lcd lcd (
        .clk(clk), .cen(cen), .rst_n(core_rst_n),
        .ctrl1(vid_ctrl1), .ctrl2(vid_ctrl2), .ctrl3(vid_ctrl3),
        .cur_x(pen_px), .cur_y(pen_py), .cur_down(pen_down),
        .vmem_addr(va), .vmem_req(vreq), .vmem_burst(), .vmem_ack(vack), .vmem_rdata(vrd),
        .ce_pix(lcd_ce_pix), .hs(lcd_hs), .vs(lcd_vs), .de(lcd_de),
        .r(lcd_r), .g(lcd_g), .b(lcd_b)
    );

    dr840_mem board (
        .clk(clk), .cen(cen), .rst_n(core_rst_n),
        .imem_addr(ia), .imem_req(ireq), .imem_burst(ibur),
        .imem_ack(iack), .imem_rdata(ird), .imem_err(ierr),
        .dmem_addr(da), .dmem_req(dreq), .dmem_burst(dbur), .dmem_we(dwe),
        .dmem_be(dbe), .dmem_wdata(dwd), .dmem_ack(dack), .dmem_rdata(drd),
        .dmem_err(derr),
        .vmem_addr(va), .vmem_req(vreq), .vmem_ack(vack), .vmem_rdata(vrd),
        .ram_addr(bram_addr), .ram_req(bram_req), .ram_burst(bram_burst),
        .ram_we(bram_we), .ram_be(bram_be), .ram_wdata(bram_wdata),
        .ram_ack(bram_ack), .ram_rdata(ram_rdata), .ram_busy(bram_busy),
        .io_addr(io_addr), .io_req(io_req), .io_we(io_we), .io_be(io_be),
        .io_wdata(io_wdata), .io_ack(io_ack), .io_rdata(io_rdata),
        .io_err(io_err)
    );

    // The interrupt controller, UART A, MBUS and the RTC. Everything else
    // in the block reads back what was written, which is what the ROM
    // needs; everything outside it reads all-ones, which is an empty PC
    // Card slot.
    dr840_tx39 #(.CLK_HZ(92_000_000)) soc (
        .clk(clk), .cen(cen), .rst_n(core_rst_n),
        .io_addr(io_addr), .io_req(io_req), .io_we(io_we), .io_be(io_be),
        .io_wdata(io_wdata), .io_ack(io_ack), .io_rdata(io_rdata),
        .io_err(io_err),
        .boot_monitor(boot_monitor), .uart_txd(uart_txd), .uart_rxd(uart_rxd),
        .pen_down(pen_down), .pen_x(pen_x), .pen_y(pen_y),
        .irq_out(soc_irq),
        .vid_ctrl1(vid_ctrl1), .vid_ctrl2(vid_ctrl2), .vid_ctrl3(vid_ctrl3),
        .dbg_tx_bytes(obs_uart_bytes), .dbg_io_reads(obs_io),
        .dbg_tx_stb(), .dbg_tx_data()
    );

    // The loader takes the memory while it is running; the board has it
    // otherwise. The core is in reset during a load, so the board is not
    // asking for anything.
    wire [24:0] ram_addr  = load_en ? load_addr  : bram_addr;
    wire        ram_req   = load_en ? load_req   : bram_req;
    wire        ram_burst = load_en ? load_burst : bram_burst;
    wire        ram_we    = load_en ? load_we    : bram_we;
    wire [3:0]  ram_be    = load_en ? 4'b1111    : bram_be;
    wire [31:0] ram_wdata = load_en ? load_data  : bram_wdata;
    wire        ram_ack, ram_busy;

    assign bram_ack  = load_en ? 1'b0 : ram_ack;
    assign bram_busy = ram_busy;
    assign load_ack  = load_en ? ram_ack : 1'b0;
    assign load_rdata = ram_rdata;

    wire [26:1] ch1_addr, ch2_addr;
    wire [63:0] ch1_dout;
    wire [31:0] ch2_dout, ch2_din;
    wire        ch1_req, ch1_ready, ch2_req, ch2_rnw, ch2_ready;

    dr840_sdram adapter (
        .clk(clk), .cen(load_en ? 1'b1 : cen), .rst_n(rst_n),
        .ram_addr(ram_addr), .ram_req(ram_req), .ram_burst(ram_burst),
        .ram_we(ram_we), .ram_be(ram_be), .ram_wdata(ram_wdata),
        .ram_ack(ram_ack), .ram_rdata(ram_rdata), .ram_busy(ram_busy),
        .dbg_start(), .dbg_start_addr(), .dbg_start_kind(), .dbg_state(),
        .ch1_addr(ch1_addr), .ch1_dout(ch1_dout), .ch1_req(ch1_req),
        .ch1_ready(ch1_ready),
        .ch2_addr(ch2_addr), .ch2_dout(ch2_dout), .ch2_din(ch2_din),
        .ch2_req(ch2_req), .ch2_rnw(ch2_rnw), .ch2_ready(ch2_ready)
    );

    sdram #(.CLK_MHZ(92)) ctl (
        .init(~rst_n), .clk(clk),
        .SDRAM_DQ_O(SDRAM_DQ_O), .SDRAM_DQ_OE(SDRAM_DQ_OE),
        .SDRAM_DQ_I(SDRAM_DQ_I), .SDRAM_A(SDRAM_A),
        .SDRAM_DQML(SDRAM_DQML), .SDRAM_DQMH(SDRAM_DQMH),
        .SDRAM_BA(SDRAM_BA), .SDRAM_nCS(SDRAM_nCS), .SDRAM_nWE(SDRAM_nWE),
        .SDRAM_nRAS(SDRAM_nRAS), .SDRAM_nCAS(SDRAM_nCAS),
        .SDRAM_CKE(SDRAM_CKE), .SDRAM_CLK(SDRAM_CLK),
        .ch1_addr(ch1_addr), .ch1_dout(ch1_dout), .ch1_din(16'd0),
        .ch1_req(ch1_req), .ch1_rnw(1'b1), .ch1_ready(ch1_ready),
        .ch2_addr(ch2_addr), .ch2_dout(ch2_dout), .ch2_din(ch2_din),
        .ch2_req(ch2_req), .ch2_rnw(ch2_rnw), .ch2_ready(ch2_ready),
        .ch3_addr(24'd0), .ch3_dout(), .ch3_din(16'd0),
        .ch3_req(1'b0), .ch3_rnw(1'b1), .ch3_ready()
    );

endmodule

`default_nettype wire
