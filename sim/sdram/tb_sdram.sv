// The whole memory path: the core and its caches, the board's decode, the
// adapter, Sorgelig's controller, and a model of the SDRAM chip that checks
// the controller as it goes. Only the peripheral bus is left to the
// testbench, because that is the one part no model here could invent.
//
// One clock throughout. On hardware the controller wants to run faster than
// the CPU; that is a clocking decision and does not change whether the
// bytes come back right, which is what this is for.
`default_nettype none

module tb_sdram #(
    parameter RTC_SLOW = 1,          // the RTC ticks this many times slower
    parameter SIB_SLOW = 1           // and the serial bus's frames likewise
) (
    input  wire        clk,
    // How many memory clocks there are to one core clock. 1 runs the core
    // at the memory's rate; 2 is the arrangement a single PLL gives on the
    // DE10-Nano, the SDRAM at twice what the core gets. A port rather than
    // a parameter so one build can be measured at several ratios.
    input  wire [7:0]  clk_div,
    input  wire        rst_n,

    output wire [31:0] io_addr,
    output wire        io_req,
    output wire        io_we,
    output wire [3:0]  io_be,
    output wire [31:0] io_wdata,
    input  wire        io_ack,
    input  wire [31:0] io_rdata,
    input  wire        io_err,

    input  wire [5:0]  irq_in,

    output wire        retire_valid,
    output wire [31:0] retire_pc,
    output wire [31:0] retire_insn,
    output wire [31:0] retire_next_pc,
    output wire [31:0] ihit_count,
    output wire [31:0] imiss_count,
    output wire [31:0] dhit_count,
    output wire [31:0] dmiss_count,

    output wire [31:0] dbg_reads,
    output wire [31:0] dbg_writes,
    output wire [31:0] dbg_refreshes,
    output wire [15:0] dbg_max_refresh_gap,
    output wire [15:0] dbg_violations,

    // Debug only: the memory port, so the testbench can say what was asked
    // for and what came back.
    output wire [24:0] dbg_ram_addr,
    output wire        dbg_ram_ack,
    output wire        dbg_ram_req,
    output wire        dbg_ram_burst,
    output wire [31:0] dbg_ram_rdata,
    output wire [31:0] dbg_last_index,
    output wire [15:0] dbg_last_col,
    output wire [15:0] dbg_last_row,
    output wire [15:0] dbg_last_a,
    output wire [26:1] dbg_ch2_addr,
    output wire        dbg_ch2_req,
    output wire        dbg_dack,
    output wire        dbg_iack,
    output wire        dbg_dreq,
    output wire        dbg_ireq,
    output wire        dbg_start,
    output wire [24:0] dbg_start_addr,
    output wire [1:0]  dbg_start_kind,
    output wire [3:0]  dbg_state,
    output wire        dbg_cen,
    // The TX39 block answers the peripheral bus when this is set, and the
    // testbench does when it is not.
    input  wire        tx39_en,
    input  wire        boot_monitor,
    input  wire        pen_down,
    input  wire [8:0]  pen_px,          // panel pixels, converted as the machine does
    input  wire [8:0]  pen_py,
    output wire        dbg_tx_stb,
    output wire        dbg_ram_we,
    output wire [3:0]  dbg_ram_be,
    output wire [31:0] dbg_ram_wdata,
    output wire [31:0] dbg_vid_ctrl1,
    output wire [31:0] dbg_vid_ctrl3,
    // The registers at a fault. A fault names the load; the registers say
    // where the machine got the address it could not use.
    output wire [31:0] dbg_r2, dbg_r4, dbg_r5, dbg_r16,
    output wire [31:0] dbg_stall_store, dbg_stall_load, dbg_stall_fetch,
    output wire        dbg_pending,
    input  wire        on_button,
    output wire        dbg_stop,
    output wire [5:0]  dbg_irq,
    output wire        dbg_exc_valid,
    output wire [4:0]  dbg_exc_code,
    output wire [31:0] dbg_exc_epc,
    output wire [31:0] dbg_exc_bad,
    output wire        dbg_io_ack,
    output wire [31:0] dbg_io_rdata,
    output wire [7:0]  dbg_tx_data,
    output wire [31:0] dbg_tx_bytes
);
    // The core's clock enable, from the same clock the memory uses.
    reg [7:0] cdiv;
    wire      cen = (clk_div <= 8'd1) || (cdiv == 8'd0);
    always @(posedge clk or negedge rst_n)
        if (!rst_n)                       cdiv <= 8'd0;
        else if (cdiv + 8'd1 >= clk_div)  cdiv <= 8'd0;
        else                              cdiv <= cdiv + 8'd1;

    assign dbg_cen = cen;

    wire [31:0] ia, ird, da, dwd, drd;
    wire        ireq, ibur, iack, ierr, dreq, dbur, dwe, dack, derr;
    wire [3:0]  dbe;

    r3900_cached #(.COUNT_PER_INSN(1'b1)) cpu (
        .clk(clk), .cen(cen), .rst_n(rst_n),
        .imem_addr(ia), .imem_req(ireq), .imem_burst(ibur),
        .imem_ack(iack), .imem_rdata(ird), .imem_err(ierr),
        .dmem_addr(da), .dmem_req(dreq), .dmem_burst(dbur), .dmem_we(dwe),
        .dmem_be(dbe), .dmem_wdata(dwd), .dmem_ack(dack), .dmem_rdata(drd),
        .dmem_err(derr), .irq_in(tx39_en ? t_irq : irq_in), .halt(tx39_en ? t_stop : 1'b0),
        .retire_valid(retire_valid), .retire_pc(retire_pc),
        .retire_insn(retire_insn), .retire_next_pc(retire_next_pc),
        .exc_valid(dbg_exc_valid), .exc_code(dbg_exc_code), .exc_epc(dbg_exc_epc),
        .exc_ip(), .exc_bad(dbg_exc_bad),
        .stall_store(dbg_stall_store), .stall_load(dbg_stall_load),
        .stall_fetch(dbg_stall_fetch),
        .ihit_count(ihit_count), .imiss_count(imiss_count),
        .dhit_count(dhit_count), .dmiss_count(dmiss_count)
    );

    wire [24:0] ram_addr;
    wire        ram_req, ram_burst, ram_we, ram_ack;
    wire [3:0]  ram_be;
    wire [31:0] ram_wdata, ram_rdata;
    wire        ram_busy;

    dr840_mem board (
        .clk(clk), .cen(cen), .rst_n(rst_n),
        .imem_addr(ia), .imem_req(ireq), .imem_burst(ibur),
        .imem_ack(iack), .imem_rdata(ird), .imem_err(ierr),
        .dmem_addr(da), .dmem_req(dreq), .dmem_burst(dbur), .dmem_we(dwe),
        .dmem_be(dbe), .dmem_wdata(dwd), .dmem_ack(dack), .dmem_rdata(drd),
        .dmem_err(derr),
        .vmem_addr(va), .vmem_req(vreq), .vmem_ack(vack), .vmem_rdata(vrd),
        .ram_addr(ram_addr), .ram_req(ram_req), .ram_burst(ram_burst),
        .ram_we(ram_we), .ram_be(ram_be), .ram_wdata(ram_wdata),
        .ram_ack(ram_ack), .ram_rdata(ram_rdata), .ram_busy(ram_busy),
        .io_addr(io_addr), .io_req(io_req), .io_we(io_we), .io_be(io_be),
        .io_wdata(io_wdata), .io_ack(io_ack_mux), .io_rdata(io_rdata_mux),
        .io_err(io_err_mux)
    );

    wire        t_ack, t_err;
    wire [31:0] t_rdata;
    wire [9:0]  pen_x, pen_y;
    dr840_pen pen (.clk(clk), .pen_px(pen_px), .pen_py(pen_py), .pen_x(pen_x), .pen_y(pen_y));
    wire [5:0]  t_irq;
    wire        t_stop;
    assign dbg_stop = t_stop;
    wire [31:0] vid_ctrl2;
    wire [31:0] va, vrd;
    wire        vreq, vack;
    assign dbg_r2  = cpu.cpu.regs[2];
    assign dbg_r4  = cpu.cpu.regs[4];
    assign dbg_r5  = cpu.cpu.regs[5];
    assign dbg_r16 = cpu.cpu.regs[16];

    dr840_lcd lcd (
        .clk(clk), .cen(cen), .rst_n(rst_n),
        .ctrl1(dbg_vid_ctrl1), .ctrl2(vid_ctrl2), .ctrl3(dbg_vid_ctrl3),
        .cur_x(9'd0), .cur_y(9'd0), .cur_down(1'b0),
        .vmem_addr(va), .vmem_req(vreq), .vmem_burst(), .vmem_ack(vack), .vmem_rdata(vrd),
        .ce_pix(), .hs(), .vs(), .de(), .r(), .g(), .b()
    );

    dr840_tx39 #(.CLK_HZ(92_000_000),
                 .RTC_HZ(92_000_000 * RTC_SLOW),
                 .SIB_HZ(92_000_000 * SIB_SLOW)) tx39 (
        .clk(clk), .cen(cen), .rst_n(rst_n),
        .io_addr(io_addr), .io_req(io_req & tx39_en), .io_we(io_we),
        .io_be(io_be), .io_wdata(io_wdata),
        .io_ack(t_ack), .io_rdata(t_rdata), .io_err(t_err),
        .boot_monitor(boot_monitor), .uart_txd(), .uart_rxd(1'b1), .irq_out(t_irq),
        .pen_down(pen_down), .pen_x(pen_x), .pen_y(pen_y), .dbg_pending(dbg_pending),
        .on_button(on_button), .cpu_stop(t_stop),
        .vid_ctrl1(dbg_vid_ctrl1), .vid_ctrl2(vid_ctrl2), .vid_ctrl3(dbg_vid_ctrl3),
        .dbg_tx_bytes(dbg_tx_bytes), .dbg_io_reads(),
        .dbg_tx_stb(dbg_tx_stb), .dbg_tx_data(dbg_tx_data)
    );

    wire        io_ack_mux   = tx39_en ? t_ack   : io_ack;
    wire [31:0] io_rdata_mux = tx39_en ? t_rdata : io_rdata;
    assign dbg_irq       = tx39_en ? t_irq : irq_in;
    assign dbg_ram_we    = ram_we;
    assign dbg_ram_be    = ram_be;
    assign dbg_ram_wdata = ram_wdata;
    assign dbg_io_ack   = io_ack_mux;
    assign dbg_io_rdata = io_rdata_mux;
    wire        io_err_mux   = tx39_en ? t_err   : io_err;

    wire [26:1] ch1_addr, ch2_addr;
    wire [63:0] ch1_dout;
    wire [31:0] ch2_dout, ch2_din;
    wire        ch1_req, ch1_ready, ch2_req, ch2_rnw, ch2_ready;

    assign dbg_dack = dack;
    assign dbg_iack = iack;
    assign dbg_dreq = dreq;
    assign dbg_ireq = ireq;
    assign dbg_ch2_addr = ch2_addr;
    assign dbg_ch2_req  = ch2_req;
    assign dbg_ram_addr  = ram_addr;
    assign dbg_ram_ack   = ram_ack;
    assign dbg_ram_req   = ram_req;
    assign dbg_ram_burst = ram_burst;
    assign dbg_ram_rdata = ram_rdata;

    dr840_sdram adapter (
        .clk(clk), .cen(cen), .rst_n(rst_n),
        .ram_addr(ram_addr), .ram_req(ram_req), .ram_burst(ram_burst),
        .ram_we(ram_we), .ram_be(ram_be), .ram_wdata(ram_wdata),
        .ram_ack(ram_ack), .ram_rdata(ram_rdata), .ram_busy(ram_busy),
        .dbg_start(dbg_start), .dbg_start_addr(dbg_start_addr),
        .dbg_start_kind(dbg_start_kind), .dbg_state(dbg_state),
        .ch1_addr(ch1_addr), .ch1_dout(ch1_dout), .ch1_req(ch1_req),
        .ch1_ready(ch1_ready),
        .ch2_addr(ch2_addr), .ch2_dout(ch2_dout), .ch2_din(ch2_din),
        .ch2_req(ch2_req), .ch2_rnw(ch2_rnw), .ch2_ready(ch2_ready)
    );

    wire [12:0] SDRAM_A;
    wire [1:0]  SDRAM_BA;
    // The data bus, resolved here rather than inside either end. On
    // hardware this is the pin's tristate buffer; a line nobody drives
    // floats high, which is what an undriven SDRAM bus reads as.
    wire [15:0] ctl_dq_o, mdl_dq_o;
    wire        ctl_dq_oe, mdl_dq_oe;
    wire [15:0] dq_bus = ctl_dq_oe ? ctl_dq_o
                       : mdl_dq_oe ? mdl_dq_o : 16'hFFFF;
    wire        SDRAM_DQML, SDRAM_DQMH, SDRAM_nCS, SDRAM_nWE;
    wire        SDRAM_nRAS, SDRAM_nCAS, SDRAM_CKE, SDRAM_CLK;

    // 92 MHz: two periods of it is 21.7 ns, and the core needs 21.2.
    sdram #(.CLK_MHZ(92)) ctl (
        .init(~rst_n), .clk(clk),
        .SDRAM_DQ_O(ctl_dq_o), .SDRAM_DQ_OE(ctl_dq_oe), .SDRAM_DQ_I(dq_bus),
        .SDRAM_A(SDRAM_A),
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

    sdram_mt48lc16m16a2 chip (
        .clk(clk), .rst(~rst_n),
        .SDRAM_nCS(SDRAM_nCS), .SDRAM_nRAS(SDRAM_nRAS),
        .SDRAM_nCAS(SDRAM_nCAS), .SDRAM_nWE(SDRAM_nWE),
        .SDRAM_A(SDRAM_A), .SDRAM_BA(SDRAM_BA),
        .SDRAM_DQML(SDRAM_DQML), .SDRAM_DQMH(SDRAM_DQMH),
        .SDRAM_DQ_I(dq_bus), .SDRAM_DQ_O(mdl_dq_o), .SDRAM_DQ_OE(mdl_dq_oe),
        .dbg_reads(dbg_reads), .dbg_writes(dbg_writes),
        .dbg_refreshes(dbg_refreshes),
        .dbg_max_refresh_gap(dbg_max_refresh_gap),
        .dbg_violations(dbg_violations),
        .dbg_last_index(dbg_last_index), .dbg_last_col(dbg_last_col),
        .dbg_last_row(dbg_last_row), .dbg_last_a(dbg_last_a)
    );
endmodule

`default_nettype wire
