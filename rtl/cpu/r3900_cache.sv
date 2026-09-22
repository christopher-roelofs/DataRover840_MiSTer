//
// r3900_cache.sv - the TMPR3902U's two caches.
//
// 4 KB of instruction cache and 1 KB of data cache, both direct-mapped with
// 16-byte lines. Those are not guesses: the IDT monitor prints both sizes,
// and the ROM's cache-invalidation loops at 0x83C008AC and 0x83C008D4 walk
// exactly those sizes in 16-byte lines.
//
// The data cache is write-through with no write allocate, which is what the
// TX39 family documents. It is also what keeps this testable: every store
// still reaches memory in program order, so a store can go on being checked
// against the reference one for one. Only reads are filtered, and a read
// that hits is a read the reference made and this core did not -- which is
// the whole point.
//
// A hit costs no cycles. That is why the core hands over a lookahead
// address: the tag and data RAMs are read with the address the port will
// present *next* cycle, so a synchronous RAM read is already finished by
// the time the access is asked for. Addressing them with the current
// address instead would make every hit take two cycles and halve the IPC
// the pipeline was built for.
//
// What lockstep can and cannot say about this file: a cache is
// architecturally invisible in a machine with one master, so the reference
// agrees with any policy. These tests show the caches break nothing. They
// cannot show the cacheability rule is the part's own.
//
`default_nettype none

module r3900_cache #(
    parameter ISETS = 256,      // 4 KB / 16 B
    parameter DSETS = 64        // 1 KB / 16 B
) (
    input  wire        clk,
    input  wire        cen,           // see r3900.sv; the core's rate
    input  wire        rst_n,

    // ---- core side, instruction
    input  wire [31:0] ibus_addr,
    input  wire [31:0] ibus_addr_la,
    input  wire        ibus_cached,
    input  wire        ibus_req,
    output wire        ibus_ack,
    output wire [31:0] ibus_rdata,
    output wire        ibus_err,

    // ---- core side, data
    input  wire [31:0] dbus_addr,
    input  wire [31:0] dbus_addr_la,
    input  wire        dbus_cached,
    input  wire        dbus_req,
    input  wire        dbus_we,
    input  wire [3:0]  dbus_be,
    input  wire [31:0] dbus_wdata,
    output wire        dbus_ack,
    output wire [31:0] dbus_rdata,
    output wire        dbus_err,

    // ---- memory side, instruction
    output wire [31:0] imem_addr,
    output wire        imem_req,
    // High for the whole of a line refill. A refill is four consecutive
    // words and SDRAM answers that as one burst -- address once, then a
    // word per cycle. Asking as four separate reads pays the access latency
    // four times, which throws away most of what a cache is for.
    output wire        imem_burst,
    input  wire        imem_ack,
    input  wire [31:0] imem_rdata,
    input  wire        imem_err,

    // ---- memory side, data
    output wire [31:0] dmem_addr,
    output wire        dmem_req,
    output wire        dmem_burst,
    output wire        dmem_we,
    output wire [3:0]  dmem_be,
    output wire [31:0] dmem_wdata,
    input  wire        dmem_ack,
    input  wire [31:0] dmem_rdata,
    input  wire        dmem_err,

    input  wire        cache_op,
    input  wire [31:0] cache_op_addr,

    output reg  [31:0] ihit_count,
    output reg  [31:0] imiss_count,
    output reg  [31:0] dhit_count,
    output reg  [31:0] dmiss_count
);

    localparam IIDX = $clog2(ISETS);        // 8
    localparam DIDX = $clog2(DSETS);        // 6
    localparam ITAGW = 32 - IIDX - 4;       // 20
    localparam DTAGW = 32 - DIDX - 4;       // 22

    localparam S_IDLE = 2'd0, S_FILL = 2'd1, S_REPLAY = 2'd2;

    // ================================================== instruction cache

    // The valid bit lives in the tag RAM rather than in a register vector
    // of its own. As registers it needs a 256-to-1 multiplexer to read,
    // and that multiplexer turned out to be the critical path of the whole
    // core -- reached, through the stall network, all the way from the data
    // cache's tag RAM. In the tag RAM it is just another bit of a
    // synchronous read. The cost is that the RAM cannot be reset in one
    // cycle, so the caches walk themselves invalid at reset instead.
    reg [31:0]    idata [0:ISETS*4-1];
    reg [ITAGW:0] itagv [0:ISETS-1];     // {valid, tag}

    wire [IIDX-1:0]  i_idx_la = ibus_addr_la[IIDX+3:4];
    wire [1:0]       i_wof_la = ibus_addr_la[3:2];
    wire [ITAGW-1:0] i_tag    = ibus_addr[31:IIDX+4];

    reg [1:0]  istate;
    reg [1:0]  icnt;
    reg [31:0] iline;                       // line base being filled

    // The RAMs are always read with the lookahead address. While a miss is
    // outstanding the core holds its request, so the lookahead is that same
    // address -- which is why S_REPLAY needs no address of its own. It
    // exists to give one clean read cycle after the refill's writes, rather
    // than depending on what a block RAM returns for a read and a write of
    // one address in the same cycle.
    wire [IIDX+1:0] iram_ra = {i_idx_la, i_wof_la};
    wire [IIDX-1:0] itag_ra = i_idx_la;

    // Every write to these arrays goes through one port. Three separate
    // write sites -- the refill, the CACHE instruction and the reset walk --
    // stop Quartus inferring block RAM at all, and it builds the tags out of
    // flip-flops instead: 10,507 registers and 9,631 ALMs, against 3,826 and
    // 3,545 when they infer. One muxed port is the difference.
    reg              idata_we;
    reg [IIDX+1:0]   idata_wa;
    reg [31:0]       idata_wd;
    reg              itag_we;
    reg [IIDX-1:0]   itag_wa;
    reg [ITAGW:0]    itag_wd;

    reg [31:0]    iram_q;
    reg [ITAGW:0] itagv_q;
    always @(posedge clk) if (cen) begin
        iram_q  <= idata[iram_ra];
        itagv_q <= itagv[itag_ra];
        if (idata_we) idata[idata_wa] <= idata_wd;
        if (itag_we)  itagv[itag_wa]  <= itag_wd;
    end
    wire             ivalid_q = itagv_q[ITAGW];
    wire [ITAGW-1:0] itag_q   = itagv_q[ITAGW-1:0];

    // A hit only counts while idle: mid-refill the tag RAM output describes
    // the line being filled, not the one being asked for.
    reg [IIDX:0] init_cnt;
    wire init_busy = !init_cnt[IIDX];

    wire i_idle   = (istate == S_IDLE) && !init_busy;
    wire i_hit    = ibus_req && ibus_cached && i_idle && ivalid_q &&
                    (itag_q == i_tag);
    // Uncached fetches go straight out, with no state of their own: the
    // reset vector and the early ROM run from kseg1.
    wire i_thru   = ibus_req && !ibus_cached && i_idle;
    wire i_filling = (istate == S_FILL);
    wire i_miss    = ibus_req && ibus_cached && i_idle && !i_hit;

    assign imem_req   = i_filling | i_thru;
    assign imem_burst = i_filling;
    assign imem_addr = i_filling ? {iline[31:4], icnt, 2'b00} : ibus_addr;

    wire i_fill_fail = i_filling && imem_ack && imem_err;
    assign ibus_ack   = i_hit | (i_thru & imem_ack) | i_fill_fail;
    assign ibus_rdata = i_hit ? iram_q : imem_rdata;
    assign ibus_err   = (i_thru & imem_ack & imem_err) | i_fill_fail;

    // ========================================================= data cache

    reg [31:0]    ddata [0:DSETS*4-1];
    reg [DTAGW:0] dtagv [0:DSETS-1];     // {valid, tag}

    wire [DIDX-1:0]  d_idx_la = dbus_addr_la[DIDX+3:4];
    wire [1:0]       d_wof_la = dbus_addr_la[3:2];
    wire [DIDX-1:0]  d_idx    = dbus_addr[DIDX+3:4];
    wire [DTAGW-1:0] d_tag    = dbus_addr[31:DIDX+4];

    reg [1:0]  dstate;
    reg [1:0]  dcnt;
    reg [31:0] dline;

    wire [DIDX+1:0] dram_ra = {d_idx_la, d_wof_la};
    wire [DIDX-1:0] dtag_ra = d_idx_la;

    reg              ddata_we;
    reg [DIDX+1:0]   ddata_wa;
    reg [31:0]       ddata_wd;
    reg              dtag_we;
    reg [DIDX-1:0]   dtag_wa;
    reg [DTAGW:0]    dtag_wd;

    reg [31:0]     dram_q;
    reg [DTAGW:0]  dtagv_q;
    reg [DIDX+1:0] dram_ra_q;
    always @(posedge clk) if (cen) begin
        dram_q    <= ddata[dram_ra];
        dtagv_q   <= dtagv[dtag_ra];
        dram_ra_q <= dram_ra;
        if (ddata_we) ddata[ddata_wa] <= ddata_wd;
        if (dtag_we)  dtagv[dtag_wa]  <= dtag_wd;
    end
    wire             dvalid_q = dtagv_q[DTAGW];
    wire [DTAGW-1:0] dtag_q   = dtagv_q[DTAGW-1:0];

    // A store that hits writes the line at the end of its cycle, but the
    // read issued in that same cycle has already sampled the old word. A
    // load of the address just stored -- a push then a pop, which is
    // everywhere -- would otherwise read what was there before. One cycle
    // of forwarding covers it: by the following cycle the RAM itself has
    // the new value.
    reg            stf_v;
    reg [DIDX+1:0] stf_a;
    reg [31:0]     stf_d;
    wire [31:0]    dram_eff = (stf_v && (stf_a == dram_ra_q)) ? stf_d : dram_q;

    wire d_idle      = (dstate == S_IDLE) && !init_busy;
    wire d_tag_match = d_idle && dvalid_q && (dtag_q == d_tag);
    wire d_read_hit  = dbus_req && dbus_cached && !dbus_we && d_tag_match;
    // Write-through with no allocate, and uncached reads: both go straight
    // to memory. Every store therefore still reaches the bus in program
    // order, which is what keeps a store checkable against the reference.
    wire d_thru      = dbus_req && d_idle && (dbus_we || !dbus_cached);
    wire d_filling   = (dstate == S_FILL);
    wire d_miss      = dbus_req && dbus_cached && !dbus_we && d_idle &&
                       !d_read_hit;

    assign dmem_req   = d_filling | d_thru;
    assign dmem_burst = d_filling;
    assign dmem_addr  = d_filling ? {dline[31:4], dcnt, 2'b00} : dbus_addr;
    assign dmem_we    = d_filling ? 1'b0 : dbus_we;
    assign dmem_be    = d_filling ? 4'b1111 : dbus_be;
    assign dmem_wdata = dbus_wdata;

    wire [31:0] d_merged = {
        dbus_be[3] ? dbus_wdata[31:24] : dram_eff[31:24],
        dbus_be[2] ? dbus_wdata[23:16] : dram_eff[23:16],
        dbus_be[1] ? dbus_wdata[15:8]  : dram_eff[15:8],
        dbus_be[0] ? dbus_wdata[7:0]   : dram_eff[7:0]
    };
    wire d_store_hit = dbus_req && dbus_we && dbus_cached && d_tag_match;

    wire d_fill_fail = d_filling && dmem_ack && dmem_err;
    assign dbus_ack   = d_read_hit | (d_thru & dmem_ack) | d_fill_fail;
    assign dbus_rdata = d_read_hit ? dram_eff : dmem_rdata;
    assign dbus_err   = (d_thru & dmem_ack & dmem_err) | d_fill_fail;

    // What each port writes this cycle. The reset walk comes first because
    // nothing may be served until it is done; then software invalidation,
    // then the refill, then a store updating a line it hit.
    // Data and tag are separate arrays with separate ports, and only the
    // tags have competing writers. Putting the data write in the same
    // priority chain lets a CACHE instruction suppress a refill beat while
    // its counter still advances, which leaves a hole in the line -- a
    // wrong instruction, served as if it were right.
    wire i_fill_beat = (istate == S_FILL) && imem_ack && !imem_err;
    wire d_fill_beat = (dstate == S_FILL) && dmem_ack && !dmem_err;

    always @(*) begin
        idata_we = i_fill_beat;
        idata_wa = {iline[IIDX+3:4], icnt};
        idata_wd = imem_rdata;
    end

    // A store hit needs the cache idle, and a refill means it is not, so
    // these two can never want the port in the same cycle.
    always @(*) begin
        ddata_we = d_fill_beat | d_store_hit;
        ddata_wa = d_fill_beat ? {dline[DIDX+3:4], dcnt}
                               : {d_idx, dbus_addr[3:2]};
        ddata_wd = d_fill_beat ? dmem_rdata : d_merged;
    end

    // The tags: the reset walk first, because nothing may be served until it
    // is done, then software invalidation, then a completed refill. A CACHE
    // instruction landing on the last beat of a refill simply leaves the
    // line invalid, which costs a miss and nothing else.
    always @(*) begin
        itag_we  = 1'b0;
        itag_wa  = iline[IIDX+3:4];
        itag_wd  = {1'b1, iline[31:IIDX+4]};
        if (init_busy) begin
            itag_we = 1'b1; itag_wa = init_cnt[IIDX-1:0];
            itag_wd = {(ITAGW+1){1'b0}};
        end else if (cache_op) begin
            itag_we = 1'b1; itag_wa = cache_op_addr[IIDX+3:4];
            itag_wd = {(ITAGW+1){1'b0}};
        end else if (i_fill_beat && (icnt == 2'd3)) begin
            itag_we = 1'b1;
        end
    end

    always @(*) begin
        dtag_we  = 1'b0;
        dtag_wa  = dline[DIDX+3:4];
        dtag_wd  = {1'b1, dline[31:DIDX+4]};
        if (init_busy) begin
            dtag_we = 1'b1; dtag_wa = init_cnt[DIDX-1:0];
            dtag_wd = {(DTAGW+1){1'b0}};
        end else if (cache_op) begin
            dtag_we = 1'b1; dtag_wa = cache_op_addr[DIDX+3:4];
            dtag_wd = {(DTAGW+1){1'b0}};
        end else if (d_fill_beat && (dcnt == 2'd3)) begin
            dtag_we = 1'b1;
        end
    end

    // ============================================================ sequencing

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            init_cnt <= {(IIDX+1){1'b0}};
            istate <= S_IDLE; dstate <= S_IDLE;
            icnt <= 2'd0; dcnt <= 2'd0;
            ihit_count <= 32'd0; imiss_count <= 32'd0;
            dhit_count <= 32'd0; dmiss_count <= 32'd0;
            stf_v <= 1'b0;
        end else if (cen && init_busy) begin
            // Walk both tag RAMs invalid. A couple of hundred cycles at
            // reset, before the first fetch can be answered.
            init_cnt <= init_cnt + 1'b1;
        end else if (cen) begin
            stf_v <= d_store_hit;
            stf_a <= {d_idx, dbus_addr[3:2]};
            stf_d <= d_merged;

            // Software-driven invalidation, which is how MIPS keeps its
            // caches coherent with code it has written. Done by index
            // without a tag compare: dropping a line that did not need
            // dropping costs a refill, never correctness, and needs no
            // second port on either tag RAM.
            // ------------------------------------------- instruction side
            case (istate)
            S_REPLAY: istate <= S_IDLE;
            S_IDLE: begin
                if (i_hit) ihit_count <= ihit_count + 32'd1;
                else if (i_miss) begin
                    istate      <= S_FILL;
                    icnt        <= 2'd0;
                    iline       <= {ibus_addr[31:4], 4'd0};
                    imiss_count <= imiss_count + 32'd1;
                end
            end
            S_FILL: if (imem_ack) begin
                if (imem_err) begin
                    // A line that faulted must never look present, so the
                    // valid bit is simply not set.
                    istate <= S_IDLE;
                end else begin
                    icnt <= icnt + 2'd1;
                    if (icnt == 2'd3) istate <= S_REPLAY;
                end
            end
            default: istate <= S_IDLE;
            endcase

            // -------------------------------------------------- data side
            case (dstate)
            S_REPLAY: dstate <= S_IDLE;
            S_IDLE: begin
                if (dbus_req && dbus_we) begin
                    // A store that hits also updates the line; the write
                    // port above does it.
                end else if (d_read_hit) begin
                    dhit_count <= dhit_count + 32'd1;
                end else if (d_miss) begin
                    dstate      <= S_FILL;
                    dcnt        <= 2'd0;
                    dline       <= {dbus_addr[31:4], 4'd0};
                    dmiss_count <= dmiss_count + 32'd1;
                end
            end
            S_FILL: if (dmem_ack) begin
                if (dmem_err) begin
                    dstate <= S_IDLE;
                end else begin
                    dcnt <= dcnt + 2'd1;
                    if (dcnt == 2'd3) dstate <= S_REPLAY;
                end
            end
            default: dstate <= S_IDLE;
            endcase
        end
    end

endmodule

//
// The core with its caches, presenting a memory-side interface only.
//
module r3900_cached #(
    parameter bit COUNT_PER_INSN = 1'b0
) (
    input  wire        clk,
    input  wire        cen,
    input  wire        rst_n,

    output wire [31:0] imem_addr,
    output wire        imem_req,
    output wire        imem_burst,
    input  wire        imem_ack,
    input  wire [31:0] imem_rdata,
    input  wire        imem_err,

    output wire [31:0] dmem_addr,
    output wire        dmem_req,
    output wire        dmem_burst,
    output wire        dmem_we,
    output wire [3:0]  dmem_be,
    output wire [31:0] dmem_wdata,
    input  wire        dmem_ack,
    input  wire [31:0] dmem_rdata,
    input  wire        dmem_err,

    input  wire [5:0]  irq_in,

    output wire        retire_valid,
    output wire [31:0] retire_pc,
    output wire [31:0] retire_insn,
    output wire [31:0] retire_next_pc,
    output wire        exc_valid,
    output wire [4:0]  exc_code,
    output wire [31:0] exc_epc,
    output wire [5:0]  exc_ip,
    output wire [31:0] exc_bad,

    output wire [31:0] ihit_count,
    output wire [31:0] imiss_count,
    output wire [31:0] dhit_count,
    output wire [31:0] dmiss_count
);

    wire [31:0] ia, ila, ird;
    wire        ic, ireq, iack, ierr;
    wire [31:0] da, dla, dwd, drd;
    wire [3:0]  dbe;
    wire        dc, dreq, dwe, dack, derr;
    wire        cop;
    wire [31:0] cop_addr;

    r3900 #(.COUNT_PER_INSN(COUNT_PER_INSN)) cpu (
        .clk(clk), .cen(cen), .rst_n(rst_n),
        .ibus_addr(ia), .ibus_req(ireq), .ibus_addr_la(ila),
        .ibus_cached(ic), .ibus_ack(iack), .ibus_rdata(ird), .ibus_err(ierr),
        .dbus_addr(da), .dbus_req(dreq), .dbus_addr_la(dla),
        .dbus_cached(dc), .dbus_we(dwe), .dbus_be(dbe), .dbus_wdata(dwd),
        .dbus_ack(dack), .dbus_rdata(drd), .dbus_err(derr),
        .irq_in(irq_in), .cache_op(cop), .cache_op_addr(cop_addr),
        .retire_valid(retire_valid), .retire_pc(retire_pc),
        .retire_insn(retire_insn), .retire_next_pc(retire_next_pc),
        .exc_valid(exc_valid), .exc_code(exc_code), .exc_epc(exc_epc), .exc_ip(exc_ip), .exc_bad(exc_bad)
    );

    r3900_cache cache (
        .clk(clk), .cen(cen), .rst_n(rst_n),
        .ibus_addr(ia), .ibus_addr_la(ila), .ibus_cached(ic),
        .ibus_req(ireq), .ibus_ack(iack), .ibus_rdata(ird), .ibus_err(ierr),
        .dbus_addr(da), .dbus_addr_la(dla), .dbus_cached(dc),
        .dbus_req(dreq), .dbus_we(dwe), .dbus_be(dbe), .dbus_wdata(dwd),
        .dbus_ack(dack), .dbus_rdata(drd), .dbus_err(derr),
        .imem_addr(imem_addr), .imem_req(imem_req), .imem_burst(imem_burst),
        .imem_ack(imem_ack), .imem_rdata(imem_rdata), .imem_err(imem_err),
        .dmem_addr(dmem_addr), .dmem_req(dmem_req), .dmem_burst(dmem_burst),
        .dmem_we(dmem_we),
        .dmem_be(dmem_be), .dmem_wdata(dmem_wdata), .dmem_ack(dmem_ack),
        .dmem_rdata(dmem_rdata), .dmem_err(dmem_err),
        .cache_op(cop), .cache_op_addr(cop_addr),
        .ihit_count(ihit_count), .imiss_count(imiss_count),
        .dhit_count(dhit_count), .dmiss_count(dmiss_count)
    );

endmodule

`default_nettype wire
