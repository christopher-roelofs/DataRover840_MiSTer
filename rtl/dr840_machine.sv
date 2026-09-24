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
    // Or borrows it: the same port, but the core is held rather than reset,
    // and gets the memory back afterwards with everything as it was. For
    // saving the RAM while the machine is off.
    input  wire        mem_borrow,
    input  wire        hold,         // and held beforehand, while the memory drains
    input  wire        blank,        // the panel shown off meanwhile
    input  wire [1:0]  tint,         // the panel's colour: off, grey, green
    // The PC Cards in the two slots: present, and the size as log2.
    input  wire [1:0]  card_present,
    input  wire [4:0]  card_log2_0,
    input  wire [4:0]  card_log2_1,
    output wire        mem_idle,     // nothing of the board's in the memory
    output wire        stopped,      // the core, held by the ROM's power-off
    output reg         ram_written,  // a word of the RAM changed just now
    output reg         card_written, // or of the card's memory
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

    // ---- the package link: the computer on the serial port that
    // Magic Cap installs packages from. The package is written into the
    // SDRAM a word at a time, and offered by a flip of pkg_go_tog.
    input  wire        pkg_go_tog,
    input  wire [24:0] pkg_len,
    input  wire [24:0] pkg_waddr,
    input  wire [31:0] pkg_wdata,
    input  wire        pkg_wreq,
    output wire        pkg_wack,
    output wire [2:0]  pkg_state,
    output wire [24:0] pkg_sent,

    // The pen, in panel pixels; the pointer is drawn on the panel where
    // it is, and the codec sees it in its own counts.
    input  wire        on_button,      // the ON button
    // The Magic Bus keyboard.
    input  wire        kbd_attached,
    input  wire        key_tog,
    input  wire [7:0]  key_code,
    input  wire        key_ext,
    input  wire        key_down,
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
    output reg  [31:0] obs_last_bad,
    // The pen as the codec is given it: down, and the raw counts.
    output wire [31:0] dbg_pen,
    // The sound, signed 16-bit mono, a sample a frame.
    output wire signed [15:0] audio
);

    // The core's clock enable: every second edge of the memory's clock.
    reg cdiv;
    always @(posedge clk or negedge rst_n)
        if (!rst_n) cdiv <= 1'b0; else cdiv <= ~cdiv;
    wire cen = cdiv;

    // The core is held in reset until the ROM is in place.
    // Registered, twice: it is the asynchronous reset of everything below,
    // and from the loader's flags through the AND it was a recovery path
    // that lost by a sixth of a nanosecond once enough else was placed
    // near it. Two flops make it a clean net from a flop, released two
    // clocks late, which nothing notices.
    reg [1:0] core_rst_q;
    always @(posedge clk or negedge rst_n)
        if (!rst_n) core_rst_q <= 2'b00;
        else        core_rst_q <= {core_rst_q[0], ~load_en};
    wire core_rst_n = core_rst_q[1];
    // Bit 31 the pen, bit 30 the option key as the block sees it.
    assign dbg_pen = {pen_down, boot_monitor, 4'd0, pen_x, 6'd0, pen_y};

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
        .irq_in(soc_irq), .halt(cpu_stop | mem_borrow | hold),
        .retire_valid(retire_valid), .retire_pc(obs_pc),
        .retire_insn(obs_insn), .retire_next_pc(),
        .exc_valid(exc_valid), .exc_code(exc_code), .exc_epc(exc_epc), .exc_ip(exc_ip), .exc_bad(exc_bad),
        .stall_store(), .stall_load(), .stall_fetch(),
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
    wire        cpu_stop;
    wire        snd_tog;
    wire [31:0] snd_addr;
    wire [15:0] codec_b;
    wire [31:0] ka, kwd;
    wire        kreq, kwe, kack;
    wire [31:0] aa, ard;
    wire        areq, aack;
    wire [24:0] pa;
    wire [31:0] pwd, prd;
    wire        preq, pwe, pack;
    wire        u_tx_tog, u_rx_tog, u_rx_full, u_on;
    wire [7:0]  u_tx_data, u_rx_data;
    wire [19:0] u_bit_clocks;
    // Across the guest's resets: the package stays offered.
    dr840_pclink pclink (
        .clk(clk), .cen(cen), .rst_n(rst_n),
        .go_tog(pkg_go_tog), .pkg_len(pkg_len),
        .wr_addr(pkg_waddr), .wr_data(pkg_wdata), .wr_req(pkg_wreq), .wr_ack(pkg_wack),
        .pmem_addr(pa), .pmem_req(preq), .pmem_we(pwe), .pmem_wdata(pwd), .pmem_ack(pack), .pmem_rdata(prd),
        .gtx_tog(u_tx_tog), .gtx_data(u_tx_data), .grx_tog(u_rx_tog), .grx_data(u_rx_data),
        .grx_full(u_rx_full), .uart_on(u_on), .bit_clocks(u_bit_clocks),
        .state(pkg_state), .sent(pkg_sent)
    );
    dr840_snd snd (
        .clk(clk), .cen(cen), .rst_n(core_rst_n),
        .snd_tog(snd_tog), .snd_addr(snd_addr), .codec_b(codec_b),
        .amem_addr(aa), .amem_req(areq), .amem_ack(aack), .amem_rdata(ard),
        .audio(audio)
    );
    wire [31:0] vid_ctrl1, vid_ctrl2, vid_ctrl3;

    // Pixel to converter count, on the reference's calibration of this
    // panel: 85..836 across the 480 and 69..791 down the 320. The ratios
    // are 751/479 and 722/319, as 401/256 and 579/256: a count out at the
    // far edge, and the OS calibrates anyway.
    // In the converter's counts; see dr840_pen.
    wire [9:0] pen_x, pen_y;
    dr840_pen pen (.clk(clk), .pen_px(pen_px), .pen_py(pen_py), .pen_x(pen_x), .pen_y(pen_y));

    // The LCD controller: scans the framebuffer out of the SDRAM through
    // the board, onto a 640x480 raster.
    wire [31:0] va, vrd;
    wire        vreq, vack;
    dr840_lcd lcd (
        .clk(clk), .cen(cen), .rst_n(core_rst_n),
        .ctrl1(vid_ctrl1), .ctrl2(vid_ctrl2), .ctrl3(vid_ctrl3),
        .cur_x(pen_px), .cur_y(pen_py), .cur_down(pen_down), .blank(blank), .tint(tint),
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
        .amem_addr(aa), .amem_req(areq), .amem_ack(aack), .amem_rdata(ard),
        .kmem_addr(ka), .kmem_req(kreq), .kmem_we(kwe), .kmem_wdata(kwd), .kmem_ack(kack),
        .pmem_addr(pa), .pmem_req(preq), .pmem_we(pwe), .pmem_wdata(pwd), .pmem_ack(pack), .pmem_rdata(prd),
        .card_present(card_present), .card_mask0((22'd1 << card_log2_0) - 22'd1),
        .card_mask1((22'd1 << card_log2_1) - 22'd1),
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
        .tx_tog(u_tx_tog), .rx_in_tog(u_rx_tog), .rx_in_data(u_rx_data),
        .rx_full(u_rx_full), .uart_on(u_on), .bit_clocks(u_bit_clocks),
        .pen_down(pen_down), .pen_x(pen_x), .pen_y(pen_y),
        .on_button(on_button), .cpu_stop(cpu_stop),
        .kbd_attached(kbd_attached), .key_tog(key_tog), .key_code(key_code),
        .key_ext(key_ext), .key_down(key_down),
        .kmem_addr(ka), .kmem_req(kreq), .kmem_we(kwe), .kmem_wdata(kwd), .kmem_ack(kack),
        .card_present(card_present), .card_log2_0(card_log2_0), .card_log2_1(card_log2_1),
        .snd_tog(snd_tog), .snd_addr(snd_addr), .codec_b(codec_b),
        .irq_out(soc_irq), .dbg_pending(),
        .vid_ctrl1(vid_ctrl1), .vid_ctrl2(vid_ctrl2), .vid_ctrl3(vid_ctrl3),
        .dbg_tx_bytes(obs_uart_bytes), .dbg_io_reads(obs_io),
        .dbg_tx_stb(), .dbg_tx_data(u_tx_data)
    );

    // The loader takes the memory while it is running; the board has it
    // otherwise. The core is in reset during a load, so the board is not
    // asking for anything.
    wire        lend      = load_en | mem_borrow;
    wire [24:0] ram_addr  = lend ? load_addr  : bram_addr;
    wire        ram_req   = lend ? load_req   : bram_req;
    wire        ram_burst = lend ? load_burst : bram_burst;
    wire        ram_we    = lend ? load_we    : bram_we;
    wire [3:0]  ram_be    = lend ? 4'b1111    : bram_be;
    wire [31:0] ram_wdata = lend ? load_data  : bram_wdata;
    wire        ram_ack, ram_busy;

    assign bram_ack  = lend ? 1'b0 : ram_ack;
    assign bram_busy = ram_busy;
    assign load_ack  = lend ? ram_ack : 1'b0;
    assign mem_idle  = !ram_busy && !bram_req;
    assign stopped   = cpu_stop;
    // Registered on the core's edges: from the core's MEM address through
    // the board's decode into the top level's flags in one period was a
    // third of a nanosecond over.
    always @(posedge clk) if (cen) begin
        ram_written  <= !lend && bram_req && bram_we && ram_ack && bram_addr < 25'h0C0_0000;
        card_written <= !lend && bram_req && bram_we && ram_ack && bram_addr >= 25'h0C0_0000
                        && bram_addr < 25'h100_0000;
    end
    assign load_rdata = ram_rdata;

    wire [26:1] ch1_addr, ch2_addr;
    wire [63:0] ch1_dout;
    wire [31:0] ch2_dout, ch2_din;
    wire        ch1_req, ch1_ready, ch2_req, ch2_rnw, ch2_ready;

    dr840_sdram adapter (
        .clk(clk), .cen(lend ? 1'b1 : cen), .rst_n(rst_n),
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
