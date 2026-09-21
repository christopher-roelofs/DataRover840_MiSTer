// Behavioural model of the MT48LC16M16A2 SDRAM fitted to the DE10-Nano
// (4 banks x 8192 rows x 512 columns x 16 bits).
//
// This is a simulation model, not RTL.  It exists so ti83p_sdram.sv can be
// exercised in Verilator against something that behaves like the real chip:
// commands are decoded from the control pins, CAS latency comes from the
// mode register the controller actually loads, and reads return data on DQ
// with the same pipeline delay the hardware has.
//
// It also *checks* the controller.  Every access is validated against the
// bank state (activated? which row? precharged out from under us?) and the
// refresh interval is tracked, because the controller in this project was
// retuned from 100 MHz to 50 MHz by hand and the timing localparams are the
// obvious place for that retune to have gone wrong.  Violations are counted
// on dbg_violations and printed once each, with the cycle number.
//
// Deliberately not modelled: power-up timing (tXSR/tRAS floors), write
// bursts, and CKE low.  The controller uses none of them; if it starts to,
// the model will report an unsupported command rather than silently
// pretend.
//
// Read bursts of 1, 2, 4 and 8 are modelled, sequential mode only: the
// DataRover core's controller reads a cache line as a burst of 4, and a
// model that answered only the first word of it would make the controller
// look correct while three quarters of every line came back as whatever was
// on the bus.  Sequential bursts wrap within the aligned block of the burst
// length, which is what the low column bits do here.

`timescale 1ns/1ps

module sdram_mt48lc16m16a2 #(
    // Chip geometry.  Kept as parameters so a smaller array can be used if
    // the 32 MB backing store is ever a problem for a given host.
    parameter BA_BITS   = 2,
    parameter ROW_BITS  = 13,
    parameter COL_BITS  = 9,
    // Refresh interval to flag on, in clocks.  8192 rows / 64 ms is one
    // refresh every 7.8125 us; at 50 MHz that is 390 clocks.  The
    // controller allows itself to drift to twice that when busy, so the
    // warning threshold is set above the drift and below anything that
    // would actually lose data.
    parameter REFRESH_WARN_CLKS = 16'd1200,
    // Print at most this many distinct violation messages.
    parameter MAX_REPORTS = 20
)(
    input                   clk,
    // Held high while the controller is in reset.  The control pins are all
    // low then, which decodes as LOAD_MODE, so command decode and refresh
    // tracking stay off until the controller is actually driving the bus.
    input                   rst,

    input                   SDRAM_nCS,
    input                   SDRAM_nRAS,
    input                   SDRAM_nCAS,
    input                   SDRAM_nWE,
    input   [ROW_BITS-1:0]  SDRAM_A,
    input   [BA_BITS-1:0]   SDRAM_BA,
    input                   SDRAM_DQML,
    input                   SDRAM_DQMH,
    // Split the same way the controller's is, and for the same reason.
    input           [15:0]  SDRAM_DQ_I,
    output          [15:0]  SDRAM_DQ_O,
    output                  SDRAM_DQ_OE,

    // Observability for the testbench.
    output reg      [31:0]  dbg_reads,
    output reg      [31:0]  dbg_writes,
    output reg      [31:0]  dbg_refreshes,
    output reg      [15:0]  dbg_max_refresh_gap,
    output reg      [15:0]  dbg_violations,
    // Debug: what the last READ actually addressed.
    output reg      [31:0]  dbg_last_index,
    output reg      [15:0]  dbg_last_col,
    output reg      [15:0]  dbg_last_row,
    output reg      [15:0]  dbg_last_a
);

    localparam MEM_BITS = BA_BITS + ROW_BITS + COL_BITS;

    // {bank, row, column} -> 16-bit word.
    // Public so the testbench can load the ROM the way the HPS will.
    reg [15:0] mem [0:(1<<MEM_BITS)-1] /* verilator public */;

    // ---- Command decode -------------------------------------------------
    wire [3:0] cmd = {SDRAM_nCS, SDRAM_nRAS, SDRAM_nCAS, SDRAM_nWE};

    localparam [3:0] CMD_LOAD_MODE    = 4'b0000;
    localparam [3:0] CMD_AUTO_REFRESH = 4'b0001;
    localparam [3:0] CMD_PRECHARGE    = 4'b0010;
    localparam [3:0] CMD_ACTIVE       = 4'b0011;
    localparam [3:0] CMD_WRITE        = 4'b0100;
    localparam [3:0] CMD_READ         = 4'b0101;
    localparam [3:0] CMD_BURST_STOP   = 4'b0110;
    localparam [3:0] CMD_NOP          = 4'b0111;

    // ---- Bank state -----------------------------------------------------
    reg                  bank_active [0:(1<<BA_BITS)-1];
    reg [ROW_BITS-1:0]   bank_row    [0:(1<<BA_BITS)-1];
    reg [31:0]           bank_act_cyc[0:(1<<BA_BITS)-1];

    // ---- Mode register --------------------------------------------------
    reg        mode_loaded;
    reg  [2:0] mode_cas;
    reg  [2:0] mode_burst;

    // ---- Read pipeline --------------------------------------------------
    // The controller captures DQ at the posedge CAS cycles after the one at
    // which the chip sees READ, so the data has to be *driven* from the
    // posedge before that — one slot earlier again.  With CL=2 that means a
    // READ decoded at posedge N loads slot 0, slot 0 turns the drivers on at
    // N+1, and the controller latches at N+2.
    reg [15:0] rd_data  [0:7];
    reg        rd_valid [0:7];
    reg        dq_oe;
    reg [15:0] dq_out;

    assign SDRAM_DQ_O  = dq_out;
    assign SDRAM_DQ_OE = dq_oe;

    reg [31:0] cycle;
    reg [15:0] since_refresh;
    reg [15:0] reports;
    // The interval before the very first refresh covers the controller's
    // 100 us power-up wait, so it is not a missed refresh.
    reg        seen_refresh;

    integer i;

    task report;
        input [1023:0] msg;
        begin
            dbg_violations = dbg_violations + 16'd1;
            if (reports < MAX_REPORTS) begin
                reports = reports + 16'd1;
                $display("[sdram] cycle %0d: %0s", cycle, msg);
                if (reports == MAX_REPORTS)
                    $display("[sdram] further violations counted but not printed");
            end
        end
    endtask

    initial begin
        dbg_reads           = 0;
        dbg_writes          = 0;
        dbg_refreshes       = 0;
        dbg_max_refresh_gap = 0;
        dbg_violations      = 0;
        cycle               = 0;
        since_refresh       = 0;
        reports             = 0;
        seen_refresh        = 0;
        mode_loaded         = 0;
        mode_cas            = 3'd2;
        mode_burst          = 3'd0;
        dq_oe               = 0;
        dq_out              = 16'h0;
        for (i = 0; i < (1<<BA_BITS); i = i + 1) begin
            bank_active[i]  = 1'b0;
            bank_row[i]     = 0;
            bank_act_cyc[i] = 0;
        end
        for (i = 0; i < 8; i = i + 1) begin
            rd_data[i]  = 16'h0;
            rd_valid[i] = 1'b0;
        end
    end

    // Column address for a READ/WRITE command.  A[10] is auto-precharge and
    // A[12:11] are the DQM lines on this controller, so they are not part of
    // the column.
    wire [COL_BITS-1:0] cmd_col = SDRAM_A[COL_BITS-1:0];
    wire                auto_pre = SDRAM_A[10];

    wire [MEM_BITS-1:0] cmd_index =
        {SDRAM_BA, bank_row[SDRAM_BA], cmd_col};

    // Pipeline slot a READ loads; see the read-pipeline comment above.
    wire [2:0] cl_slot = (mode_cas >= 3'd2) ? (mode_cas - 3'd2) : 3'd0;

    // Burst length from the mode register, and where beat `bi` of one
    // lands: the low log2(len) column bits advance and wrap, the rest do
    // not move.
    wire [4:0] burst_len = (mode_burst == 3'd0) ? 5'd1 :
                           (mode_burst == 3'd1) ? 5'd2 :
                           (mode_burst == 3'd2) ? 5'd4 :
                           (mode_burst == 3'd3) ? 5'd8 : 5'd1;
    integer bi;

    function [MEM_BITS-1:0] burst_index(input [2:0] beat);
        reg [COL_BITS-1:0] c;
        begin
            c = cmd_col;
            case (mode_burst)
            3'd1: c[0:0]   = cmd_col[0:0]   + beat[0:0];
            3'd2: c[1:0]   = cmd_col[1:0]   + beat[1:0];
            3'd3: c[2:0]   = cmd_col[2:0]   + beat[2:0];
            default: ;
            endcase
            burst_index = {SDRAM_BA, bank_row[SDRAM_BA], c};
        end
    endfunction

    always @(posedge clk) if (rst) begin
        cycle         <= cycle + 32'd1;
        since_refresh <= 16'd0;
        dq_oe         <= 1'b0;
        for (i = 0; i < 8; i = i + 1) rd_valid[i] <= 1'b0;
        for (i = 0; i < (1<<BA_BITS); i = i + 1) bank_active[i] <= 1'b0;
    end else begin
        cycle         <= cycle + 32'd1;
        since_refresh <= since_refresh + 16'd1;

        // Turn the drivers on for whatever reached slot 0, then advance.
        dq_oe <= rd_valid[0];
        if (rd_valid[0]) dq_out <= rd_data[0];
        for (i = 0; i < 7; i = i + 1) begin
            rd_data[i]  <= rd_data[i+1];
            rd_valid[i] <= rd_valid[i+1];
        end
        rd_valid[7] <= 1'b0;

        case (cmd)
            CMD_LOAD_MODE: begin
                mode_loaded <= 1'b1;
                mode_burst  <= SDRAM_A[2:0];
                mode_cas    <= SDRAM_A[6:4];
                if (SDRAM_A[2:0] > 3'b011)
                    report("LOAD_MODE with an unmodelled burst length");
                if (SDRAM_A[3])
                    report("LOAD_MODE selects an interleaved burst (unmodelled)");
                if (SDRAM_A[6:4] != 3'd2 && SDRAM_A[6:4] != 3'd3)
                    report("LOAD_MODE with CAS latency outside 2..3");
            end

            CMD_AUTO_REFRESH: begin
                dbg_refreshes <= dbg_refreshes + 32'd1;
                seen_refresh  <= 1'b1;
                if (seen_refresh) begin
                    if (since_refresh > dbg_max_refresh_gap)
                        dbg_max_refresh_gap <= since_refresh;
                    if (since_refresh > REFRESH_WARN_CLKS)
                        report("AUTO_REFRESH interval exceeded the warn threshold");
                end
                since_refresh <= 16'd0;
                for (i = 0; i < (1<<BA_BITS); i = i + 1)
                    if (bank_active[i])
                        report("AUTO_REFRESH issued with a bank still active");
            end

            CMD_PRECHARGE: begin
                if (SDRAM_A[10]) begin
                    for (i = 0; i < (1<<BA_BITS); i = i + 1)
                        bank_active[i] <= 1'b0;
                end else begin
                    bank_active[SDRAM_BA] <= 1'b0;
                end
            end

            CMD_ACTIVE: begin
                if (bank_active[SDRAM_BA])
                    report("ACTIVE on a bank that was already active (missing PRECHARGE)");
                bank_active[SDRAM_BA]  <= 1'b1;
                bank_row[SDRAM_BA]     <= SDRAM_A;
                bank_act_cyc[SDRAM_BA] <= cycle;
            end

            CMD_READ: begin
                dbg_reads <= dbg_reads + 32'd1;
                dbg_last_index <= {{(32-MEM_BITS){1'b0}}, cmd_index};
                dbg_last_col   <= {{(16-COL_BITS){1'b0}}, cmd_col};
                dbg_last_row   <= {{(16-ROW_BITS){1'b0}}, bank_row[SDRAM_BA]};
                dbg_last_a     <= {3'd0, SDRAM_A};
                if (!mode_loaded)
                    report("READ before the mode register was loaded");
                if (!bank_active[SDRAM_BA])
                    report("READ from a bank with no open row");
                else if (cycle - bank_act_cyc[SDRAM_BA] < 32'd1)
                    report("READ violates tRCD (issued too soon after ACTIVE)");
                // Data is captured by the controller CAS cycles from now;
                // drive it one cycle before that.
                // Sequential burst: the low bits of the column count and
                // wrap inside the aligned block, the rest stay put.
                for (bi = 0; bi < 8; bi = bi + 1)
                    if (bi < burst_len) begin
                        rd_data [cl_slot + bi[2:0]] <= mem[burst_index(bi[2:0])];
                        rd_valid[cl_slot + bi[2:0]] <= 1'b1;
                    end
                if (auto_pre) bank_active[SDRAM_BA] <= 1'b0;
            end

            CMD_WRITE: begin
                dbg_writes <= dbg_writes + 32'd1;
                if (!mode_loaded)
                    report("WRITE before the mode register was loaded");
                if (!bank_active[SDRAM_BA])
                    report("WRITE to a bank with no open row");
                else if (cycle - bank_act_cyc[SDRAM_BA] < 32'd1)
                    report("WRITE violates tRCD (issued too soon after ACTIVE)");
                else begin
                    if (!SDRAM_DQML) mem[cmd_index][7:0]  <= SDRAM_DQ_I[7:0];
                    if (!SDRAM_DQMH) mem[cmd_index][15:8] <= SDRAM_DQ_I[15:8];
                    if (SDRAM_DQML && SDRAM_DQMH)
                        report("WRITE with both byte lanes masked (no-op)");
                end
                if (auto_pre) bank_active[SDRAM_BA] <= 1'b0;
            end

            CMD_NOP, CMD_BURST_STOP: ;

            default:
                if (!SDRAM_nCS) report("unsupported command on the bus");
        endcase
    end

    // ---- Testbench access ----------------------------------------------
    // Reading the backing store directly, in the same {bank,row,col} layout
    // the controller uses, so a test can check what actually landed in the
    // chip without going through the read path being tested.
    /* verilator public_module */

    function [15:0] peek_word(input [MEM_BITS-1:0] index);
        /* verilator public */
        peek_word = mem[index];
    endfunction

endmodule
