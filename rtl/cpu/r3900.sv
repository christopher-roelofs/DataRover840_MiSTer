//
// r3900.sv - Toshiba TX39 (R3900) integer core, as fitted to the Oki
// DataRover 840 as part of the TMPR3902U.
//
// Five stages: IF, ID, EX, MEM, WB. Branches resolve in ID, which is what
// makes the delay slot architectural rather than a thing to squash around:
// when a branch sits in ID the delay slot is already the address IF is
// fetching, so the redirect lands on the fetch after it and the core never
// runs down a wrong path. Fetches equal retires, exactly.
//
// The architectural model is magicrecomp's, whose C core this is validated
// against instruction by instruction (sim/cosim). Where the R3900 differs
// from a generic MIPS-I part, the difference is called out where it matters:
//
//   - big-endian
//   - no TLB: kseg0/kseg1 mask the top three bits, everything else maps
//     straight through
//   - no architectural load delay slot; the part scoreboards, so a load
//     result is available to the very next instruction and the pipeline
//     interlocks instead of exposing the slot
//   - CP0 Config is $3, not $16
//   - Status.PE (bit 20) is a write-one-to-clear latch, not a stored bit
//   - PRId reads 0x2200, which the ROM branches on
//   - only the two software interrupt bits of Cause are writable
//   - CACHE (opcode 0x2F) exists and is counted
//
// Anything outside MIPS-I + CACHE + RFE raises Reserved Instruction rather
// than becoming a NOP, which is also what the reference does: the two have
// to disagree about nothing, including what they refuse. The MADD family the
// R3900 also has is deliberately absent for the same reason.
//
// Control is decoded afresh in each stage from the instruction word rather
// than carried as a bundle of pipelined control bits. Decode is a few gates
// for a fixed-width ISA, and it removes a whole class of bug where a control
// signal is pipelined one stage short.
//
`default_nettype none

module r3900 #(
    // CP0 Count. The reference ticks it once per two retired instructions
    // and says in its own source that this is a placeholder, not a
    // measurement. Lockstep has to agree with it, so the cosim build sets
    // this; a real build counts cycles, which is what the hardware does.
    parameter bit COUNT_PER_INSN = 1'b0
) (
    input  wire        clk,
    input  wire        rst_n,

    output wire [31:0] ibus_addr,
    output wire        ibus_req,
    input  wire        ibus_ack,
    input  wire [31:0] ibus_rdata,
    input  wire        ibus_err,

    // Big-endian byte lanes: be[3] is bits 31:24, the byte at the word
    // address itself.
    output wire [31:0] dbus_addr,
    output wire        dbus_req,
    output wire        dbus_we,
    output wire [3:0]  dbus_be,
    output wire [31:0] dbus_wdata,
    input  wire        dbus_ack,
    input  wire [31:0] dbus_rdata,
    input  wire        dbus_err,

    input  wire [5:0]  irq_in,          // IP2..IP7 into Cause.IP[7:2]

    // Retire observation: one cycle per instruction as it commits, with the
    // architectural state it produced already visible. The comparison point
    // against the reference; it carries no logic.
    output wire        retire_valid,
    output wire [31:0] retire_pc,
    output wire [31:0] retire_insn,
    output wire [31:0] retire_next_pc
);

    // =================================================== architectural state

    reg [31:0] regs [0:31] /* verilator public */;
    reg [31:0] hi          /* verilator public */;
    reg [31:0] lo          /* verilator public */;
    reg [31:0] cp0 [0:31];

    reg [63:0] insn_count  /* verilator public */;
    reg [63:0] cycle_count /* verilator public */;
    reg [63:0] cache_ops   /* verilator public */;
    reg [63:0] exc_count   /* verilator public */;

    localparam CP0_INDEX  = 5'd0,  CP0_RANDOM = 5'd1,  CP0_CONFIG  = 5'd3;
    localparam CP0_BADVADDR = 5'd8, CP0_COUNT = 5'd9,  CP0_COMPARE = 5'd11;
    localparam CP0_STATUS = 5'd12, CP0_CAUSE  = 5'd13, CP0_EPC     = 5'd14;
    localparam CP0_PRID   = 5'd15;

    localparam [31:0] SR_PE  = 32'h0010_0000;

    localparam EXC_INT = 5'd0,  EXC_ADEL = 5'd4,  EXC_ADES = 5'd5;
    localparam EXC_IBE = 5'd6,  EXC_DBE  = 5'd7,  EXC_SYS  = 5'd8;
    localparam EXC_BP  = 5'd9,  EXC_RI   = 5'd10, EXC_OV   = 5'd12;

    // No TLB.
    function [31:0] phys(input [31:0] va);
        phys = (va >= 32'h8000_0000 && va < 32'hC000_0000)
             ? (va & 32'h1FFF_FFFF) : va;
    endfunction

    // ============================================== pipeline registers

    // IF/ID
    reg        id_v;
    reg [31:0] id_pc, id_insn;
    reg        id_ds;                 // sits in a branch delay slot
    reg [4:0]  id_exc_code;
    reg        id_exc_v;
    reg [31:0] id_exc_bad;
    reg        id_exc_bad_v;

    // ID/EX
    reg        ex_v;
    reg [31:0] ex_pc, ex_insn, ex_next_pc;
    reg [31:0] ex_rs_raw, ex_rt_raw;
    reg        ex_ds;
    reg        ex_exc_v;
    reg [4:0]  ex_exc_code;
    reg [31:0] ex_exc_bad;
    reg        ex_exc_bad_v;

    // EX/MEM
    reg        me_v;
    reg [31:0] me_pc, me_insn, me_next_pc;
    reg [31:0] me_result;             // ALU result, or the address for a load
    reg [31:0] me_rt;                 // store data source, post-forwarding
    reg [31:0] me_va;                 // the untranslated effective address
    reg [31:0] me_hi, me_lo;
    reg        me_hilo_we;
    reg        me_ds;
    reg        me_exc_v;
    reg [4:0]  me_exc_code;
    reg [31:0] me_exc_bad;
    reg        me_exc_bad_v;

    // MEM/WB
    reg        wb_v;
    reg [31:0] wb_pc, wb_insn, wb_next_pc;
    reg [31:0] wb_value;
    reg [4:0]  wb_wa;
    reg        wb_we;
    reg [31:0] wb_hi, wb_lo;
    reg        wb_hilo_we;
    reg        wb_cp0_we;
    reg [4:0]  wb_cp0_a;
    reg [31:0] wb_cp0_d;
    reg        wb_cache;

    // ============================================== decode (pure functions)

    `define OP(i)    (i[31:26])
    `define RS(i)    (i[25:21])
    `define RT(i)    (i[20:16])
    `define RD(i)    (i[15:11])
    `define SA(i)    (i[10:6])
    `define FN(i)    (i[5:0])

    // Does this encoding write a GPR, and which one?
    function is_load(input [31:0] i);
        is_load = (`OP(i) == 6'h20) || (`OP(i) == 6'h21) || (`OP(i) == 6'h23)
               || (`OP(i) == 6'h24) || (`OP(i) == 6'h25)
               || (`OP(i) == 6'h22) || (`OP(i) == 6'h26);
    endfunction
    function is_store(input [31:0] i);
        is_store = (`OP(i) == 6'h28) || (`OP(i) == 6'h29) || (`OP(i) == 6'h2B)
                || (`OP(i) == 6'h2A) || (`OP(i) == 6'h2E);
    endfunction
    // SWL/SWR read the word before merging into it, so they are two accesses.
    function is_rmw(input [31:0] i);
        is_rmw = (`OP(i) == 6'h2A) || (`OP(i) == 6'h2E);
    endfunction
    function is_mem(input [31:0] i);
        is_mem = is_load(i) || is_store(i);
    endfunction

    function [4:0] dest_reg(input [31:0] i);
        case (`OP(i))
        6'h00: dest_reg = (`FN(i) == 6'h09) ? ((`RD(i) == 5'd0) ? 5'd31 : `RD(i))
                                            : `RD(i);
        6'h01: dest_reg = 5'd31;                       // only the AL forms
        6'h03: dest_reg = 5'd31;                       // JAL
        6'h10: dest_reg = `RT(i);                      // MFC0
        default: dest_reg = `RT(i);
        endcase
    endfunction

    function writes_gpr(input [31:0] i);
        case (`OP(i))
        6'h00: case (`FN(i))
               6'h08, 6'h0C, 6'h0D,                      // JR, SYSCALL, BREAK
               6'h11, 6'h13,                             // MTHI, MTLO
               6'h18, 6'h19, 6'h1A, 6'h1B:               // MULT/MULTU/DIV/DIVU
                   writes_gpr = 1'b0;
               default: writes_gpr = 1'b1;
               endcase
        6'h01: writes_gpr = (`RT(i) == 5'h10) || (`RT(i) == 5'h11);
        6'h02: writes_gpr = 1'b0;                        // J
        6'h03: writes_gpr = 1'b1;                        // JAL
        6'h04, 6'h05, 6'h06, 6'h07: writes_gpr = 1'b0;   // branches
        6'h10: writes_gpr = (`RS(i) == 5'h00);           // MFC0 only
        6'h2F: writes_gpr = 1'b0;                        // CACHE
        default: writes_gpr = !is_store(i);
        endcase
    endfunction

    // CP0 and HI/LO are committed in WB, so a reader behind a writer
    // interlocks rather than forwards. Both are rare enough -- 1.3% of the
    // ROM's instructions -- that the stall costs almost nothing, and an
    // interlock cannot be subtly wrong the way a forwarding path can.
    function touches_cp0(input [31:0] i);
        touches_cp0 = (`OP(i) == 6'h10);
    endfunction
    function touches_hilo(input [31:0] i);
        touches_hilo = (`OP(i) == 6'h00) &&
                       (`FN(i) >= 6'h10) && (`FN(i) <= 6'h1B);
    endfunction
    function writes_cp0_or_hilo(input [31:0] i);
        writes_cp0_or_hilo =
            ((`OP(i) == 6'h10) && ((`RS(i) == 5'h04) || (`RS(i) == 5'h10))) ||
            ((`OP(i) == 6'h00) && (((`FN(i) == 6'h11) || (`FN(i) == 6'h13)) ||
                                   ((`FN(i) >= 6'h18) && (`FN(i) <= 6'h1B))));
    endfunction

    function reads_rs(input [31:0] i);
        case (`OP(i))
        6'h00: reads_rs = !((`FN(i) == 6'h00) || (`FN(i) == 6'h02) ||
                            (`FN(i) == 6'h03) || (`FN(i) == 6'h10) ||
                            (`FN(i) == 6'h12));
        6'h02, 6'h03: reads_rs = 1'b0;                   // J, JAL
        6'h0F: reads_rs = 1'b0;                          // LUI
        6'h10: reads_rs = 1'b0;                          // COP0
        default: reads_rs = 1'b1;
        endcase
    endfunction

    function reads_rt(input [31:0] i);
        case (`OP(i))
        6'h00: reads_rt = !((`FN(i) == 6'h08) || (`FN(i) == 6'h09) ||
                            (`FN(i) == 6'h10) || (`FN(i) == 6'h11) ||
                            (`FN(i) == 6'h12) || (`FN(i) == 6'h13));
        6'h04, 6'h05: reads_rt = 1'b1;                   // BEQ, BNE
        6'h10: reads_rt = (`RS(i) == 5'h04);             // MTC0
        default: reads_rt = is_store(i);                 // SB/SH/SW/SWL/SWR
        endcase
    endfunction

    // Branches and jumps resolve in ID, so their operands are needed there.
    function is_branch(input [31:0] i);
        case (`OP(i))
        6'h00: is_branch = (`FN(i) == 6'h08) || (`FN(i) == 6'h09);
        6'h01: is_branch = 1'b1;
        6'h02, 6'h03, 6'h04, 6'h05, 6'h06, 6'h07: is_branch = 1'b1;
        default: is_branch = 1'b0;
        endcase
    endfunction

    // Encodings this core refuses, matching the reference exactly.
    function illegal(input [31:0] i);
        case (`OP(i))
        6'h00: case (`FN(i))
               6'h00, 6'h02, 6'h03, 6'h04, 6'h06, 6'h07,
               6'h08, 6'h09, 6'h0C, 6'h0D,
               6'h10, 6'h11, 6'h12, 6'h13,
               6'h18, 6'h19, 6'h1A, 6'h1B,
               6'h20, 6'h21, 6'h22, 6'h23, 6'h24, 6'h25, 6'h26, 6'h27,
               6'h2A, 6'h2B: illegal = 1'b0;
               default:      illegal = 1'b1;
               endcase
        6'h01: illegal = !((`RT(i) == 5'h00) || (`RT(i) == 5'h01) ||
                           (`RT(i) == 5'h10) || (`RT(i) == 5'h11));
        6'h10: illegal = !((`RS(i) == 5'h00) || (`RS(i) == 5'h04) ||
                           ((`RS(i) == 5'h10) && (`FN(i) == 6'h10)));
        6'h02, 6'h03, 6'h04, 6'h05, 6'h06, 6'h07,
        6'h08, 6'h09, 6'h0A, 6'h0B, 6'h0C, 6'h0D, 6'h0E, 6'h0F,
        6'h20, 6'h21, 6'h22, 6'h23, 6'h24, 6'h25, 6'h26,
        6'h28, 6'h29, 6'h2A, 6'h2B, 6'h2E, 6'h2F: illegal = 1'b0;
        default: illegal = 1'b1;
        endcase
    endfunction

    // ================================================== CP0 read

    wire [31:0] cause_live = (cp0[CP0_CAUSE] & ~32'h0000_FC00)
                           | ({26'd0, irq_in} << 10);

    // Read by MFC0 in EX. Written as a mux rather than a function because a
    // function that reads module state is a place where synthesis and
    // simulation are allowed to disagree, and forwarding paths are exactly
    // where that must not happen.
    wire [4:0]  cp0_ra = ex_insn[15:11];
    wire [31:0] cp0_rd_val =
        (cp0_ra == CP0_CAUSE) ? cause_live :
        (cp0_ra == CP0_COUNT) ? (COUNT_PER_INSN ? cycle_count[32:1]
                                                : cp0[CP0_COUNT])
                              : cp0[cp0_ra];

    // ================================================== stall and flush

    wire stall_mem;
    wire stall_ex;
    wire exc_flush;

    wire adv_mem = !stall_mem;
    wire adv_ex  = !stall_mem && !stall_ex;
    wire id_hazard;
    wire adv_id  = adv_ex && !id_hazard;

    // =========================================================== IF

    reg [31:0] fpc;
    reg        redir_v;
    reg [31:0] redir_pc;

    wire        id_redirect;
    wire [31:0] id_target;

    assign ibus_addr = phys(fpc);
    // Fetch whenever ID can take the result. Nothing is fetched speculatively
    // past a branch, so there is no wrong path to squash.
    assign ibus_req  = adv_id && !exc_flush;
    wire fetch_ok    = ibus_req && ibus_ack;

    // =========================================================== ID

    wire [31:0] i_id   = id_insn;
    wire [4:0]  id_rs  = `RS(i_id);
    wire [4:0]  id_rt  = `RT(i_id);
    wire [15:0] id_imm = i_id[15:0];
    wire [31:0] id_simm = {{16{id_imm[15]}}, id_imm};

    // Architectural pc pair, kept exactly as the reference keeps it, so that
    // next_pc means the same thing on both sides: the address two
    // instructions ahead with branches applied.
    //
    // Only a_next_pc feeds anything: a_pc exists to be checked against the
    // address actually fetched, which is a simulation-only assertion at the
    // bottom of this file. Synthesis therefore reports it as written but
    // never read and optimises it away, which is correct and expected.
    reg [31:0] a_pc, a_next_pc;

    // Register read with the WB write bypassed in, plus forwarding for the
    // branch comparison: the value may still be in EX or MEM.
    wire [31:0] rf_rs = (id_rs == 5'd0) ? 32'd0 : regs[id_rs];
    wire [31:0] rf_rt = (id_rt == 5'd0) ? 32'd0 : regs[id_rt];

    wire [31:0] ex_alu_out;   // combinational result of whatever is in EX

    // Forwarding. Three producers can be ahead of a reader: the instruction
    // in EX (its result is still combinational), the one in MEM, and the one
    // in WB. Priority is youngest first, because the youngest producer is
    // the one whose value the reader is supposed to see.
    //
    // ID needs this too, not just EX, because branches resolve here.
    wire       ex_writes = ex_v && writes_gpr(ex_insn);
    wire       me_writes = me_v && writes_gpr(me_insn);
    wire [4:0] ex_wa     = dest_reg(ex_insn);
    wire [4:0] me_wa     = dest_reg(me_insn);

    wire id_ex_hit_rs = ex_writes && (ex_wa != 5'd0) && (ex_wa == id_rs);
    wire id_me_hit_rs = me_writes && (me_wa != 5'd0) && (me_wa == id_rs);
    wire id_wb_hit_rs = wb_v && wb_we && (wb_wa != 5'd0) && (wb_wa == id_rs);
    wire id_ex_hit_rt = ex_writes && (ex_wa != 5'd0) && (ex_wa == id_rt);
    wire id_me_hit_rt = me_writes && (me_wa != 5'd0) && (me_wa == id_rt);
    wire id_wb_hit_rt = wb_v && wb_we && (wb_wa != 5'd0) && (wb_wa == id_rt);

    wire [31:0] id_s = (id_rs == 5'd0) ? 32'd0 :
                       id_ex_hit_rs    ? ex_alu_out :
                       id_me_hit_rs    ? me_result  :
                       id_wb_hit_rs    ? wb_value   : rf_rs;
    wire [31:0] id_t = (id_rt == 5'd0) ? 32'd0 :
                       id_ex_hit_rt    ? ex_alu_out :
                       id_me_hit_rt    ? me_result  :
                       id_wb_hit_rt    ? wb_value   : rf_rt;

    // Branch resolution.
    wire [31:0] id_btarget = (id_pc + 32'd4) + {id_simm[29:0], 2'b00};
    wire [31:0] id_jtarget = {id_pc[31:28], i_id[25:0], 2'b00};

    reg  id_taken;
    reg [31:0] id_tgt;
    always @(*) begin
        id_taken = 1'b0;
        id_tgt   = id_btarget;
        case (`OP(i_id))
        6'h00: if ((`FN(i_id) == 6'h08) || (`FN(i_id) == 6'h09)) begin
                   id_taken = 1'b1; id_tgt = id_s;            // JR, JALR
               end
        6'h01: case (`RT(i_id))
               5'h00, 5'h10: id_taken = id_s[31];             // BLTZ, BLTZAL
               5'h01, 5'h11: id_taken = ~id_s[31];            // BGEZ, BGEZAL
               default: ;
               endcase
        6'h02, 6'h03: begin id_taken = 1'b1; id_tgt = id_jtarget; end
        6'h04: id_taken = (id_s == id_t);
        6'h05: id_taken = (id_s != id_t);
        6'h06: id_taken = id_s[31] || (id_s == 32'd0);
        6'h07: id_taken = !id_s[31] && (id_s != 32'd0);
        default: ;
        endcase
    end

    assign id_redirect = adv_id && id_v && id_taken && !exc_flush;
    assign id_target   = id_tgt;

    wire [31:0] id_next_pc = id_taken ? id_tgt : (a_next_pc + 32'd4);

    // ------------------------------------------------ hazards

    // Load-use. The part has no architectural load delay slot, so this
    // interlocks: one cycle, after which the value forwards from MEM/WB.
    wire       ex_is_load  = ex_v && is_load(ex_insn);
    wire [4:0] ex_dest     = ex_wa;
    wire       id_needs_rs = id_v && reads_rs(i_id);
    wire       id_needs_rt = id_v && reads_rt(i_id);

    wire load_use = ex_is_load && writes_gpr(ex_insn) && (ex_dest != 5'd0) &&
                    ((id_needs_rs && (id_rs == ex_dest)) ||
                     (id_needs_rt && (id_rt == ex_dest)));

    // A branch needs its operands in ID, a stage earlier than everyone else,
    // so a load two ahead of it has to drain one stage further.
    wire       me_is_load = me_v && is_load(me_insn);
    wire [4:0] me_dest    = me_wa;
    wire branch_load_use = id_v && is_branch(i_id) && me_is_load &&
                           writes_gpr(me_insn) && (me_dest != 5'd0) &&
                           ((id_needs_rs && (id_rs == me_dest)) ||
                            (id_needs_rt && (id_rt == me_dest)));

    wire special_inflight = (ex_v && writes_cp0_or_hilo(ex_insn)) ||
                            (me_v && writes_cp0_or_hilo(me_insn)) ||
                            (wb_v && (wb_cp0_we || wb_hilo_we));
    wire special_hazard = id_v && (touches_cp0(i_id) || touches_hilo(i_id)) &&
                          special_inflight;

    assign id_hazard = load_use | branch_load_use | special_hazard;

    // ------------------------------------------------ interrupts

    // Taken in place of an instruction, never alongside one. Checked here
    // with committed CP0 state, which the interlock above guarantees is not
    // stale behind an in-flight MTC0.
    wire irq_pending = cp0[CP0_STATUS][0] &&
                       |(cause_live[15:8] & cp0[CP0_STATUS][15:8]) &&
                       !special_inflight;

    wire id_take_irq = id_v && irq_pending && !id_exc_v;

    // =========================================================== EX

    wire [31:0] i_ex  = ex_insn;
    wire [4:0]  ex_rs = `RS(i_ex);
    wire [4:0]  ex_rt = `RT(i_ex);
    wire [15:0] ex_imm = i_ex[15:0];
    wire [31:0] ex_simm = {{16{ex_imm[15]}}, ex_imm};
    wire [31:0] ex_zimm = {16'd0, ex_imm};

    // A load is never in MEM while something that needs its result is in EX:
    // the load-use interlock in ID has already held the consumer back a
    // cycle, so by the time it reaches EX the load is in WB. That is why
    // forwarding from MEM can use the ALU result without caring that a load
    // has nothing there yet.
    wire ex_me_hit_rs = me_writes && (me_wa != 5'd0) && (me_wa == ex_rs);
    wire ex_wb_hit_rs = wb_v && wb_we && (wb_wa != 5'd0) && (wb_wa == ex_rs);
    wire ex_me_hit_rt = me_writes && (me_wa != 5'd0) && (me_wa == ex_rt);
    wire ex_wb_hit_rt = wb_v && wb_we && (wb_wa != 5'd0) && (wb_wa == ex_rt);

    wire [31:0] s = (ex_rs == 5'd0) ? 32'd0 :
                    ex_me_hit_rs    ? me_result :
                    ex_wb_hit_rs    ? wb_value  : ex_rs_raw;
    wire [31:0] t = (ex_rt == 5'd0) ? 32'd0 :
                    ex_me_hit_rt    ? me_result :
                    ex_wb_hit_rt    ? wb_value  : ex_rt_raw;

    wire [31:0] add_r  = s + t;
    wire [31:0] sub_r  = s - t;
    wire [31:0] addi_r = s + ex_simm;
    wire add_ovf  = (s[31] == t[31])       && (add_r[31]  != s[31]);
    wire sub_ovf  = (s[31] != t[31])       && (sub_r[31]  != s[31]);
    wire addi_ovf = (s[31] == ex_simm[31]) && (addi_r[31] != s[31]);

    // SLLV/SRLV/SRAV (funct bit 2 set) take the amount from rs.
    wire [4:0]  shamt = i_ex[2] ? s[4:0] : `SA(i_ex);
    wire [31:0] ex_va = s + ex_simm;

    reg [31:0] alu;
    always @(*) begin
        alu = 32'd0;
        case (`OP(i_ex))
        6'h00: case (`FN(i_ex))
               6'h00, 6'h04: alu = t << shamt;
               6'h02, 6'h06: alu = t >> shamt;
               6'h03, 6'h07: alu = $signed(t) >>> shamt;
               6'h09:        alu = ex_pc + 32'd8;          // JALR link
               6'h10:        alu = hi;
               6'h12:        alu = lo;
               6'h20, 6'h21: alu = add_r;
               6'h22, 6'h23: alu = sub_r;
               6'h24:        alu = s & t;
               6'h25:        alu = s | t;
               6'h26:        alu = s ^ t;
               6'h27:        alu = ~(s | t);
               6'h2A:        alu = {31'd0, $signed(s) < $signed(t)};
               6'h2B:        alu = {31'd0, s < t};
               default: ;
               endcase
        6'h01: alu = ex_pc + 32'd8;                        // BLTZAL/BGEZAL link
        6'h03: alu = ex_pc + 32'd8;                        // JAL link
        6'h08, 6'h09: alu = addi_r;
        6'h0A: alu = {31'd0, $signed(s) < $signed(ex_simm)};
        6'h0B: alu = {31'd0, s < ex_simm};
        6'h0C: alu = s & ex_zimm;
        6'h0D: alu = s | ex_zimm;
        6'h0E: alu = s ^ ex_zimm;
        6'h0F: alu = {ex_imm, 16'd0};
        6'h10: alu = cp0_rd_val;                           // MFC0
        default: alu = ex_va;                              // loads and stores
        endcase
    end
    assign ex_alu_out = alu;

    // ------------------------------------------------ multiply and divide

    // Multiply is one cycle: the DSP blocks are there and a 32x32 product
    // closes timing far above the clock this part runs at. Divide cannot be
    // inferred that way, so it is a restoring divider over 32 cycles on
    // magnitudes, with the signs reapplied at the end. The divide-by-zero
    // and 0x80000000 / -1 results are not "undefined" here: they are
    // whatever the reference produces, because lockstep compares them.
    wire [63:0] mul_s = $signed(s) * $signed(t);
    wire [63:0] mul_u = s * t;

    reg [63:0] md_rq;
    reg [31:0] md_d;
    reg [5:0]  md_count;
    reg        md_run, md_neg_q, md_neg_r, md_skip;
    reg [31:0] md_fix_hi, md_fix_lo;

    wire [63:0] md_shifted = {md_rq[62:0], 1'b0};
    wire [32:0] md_diff    = {1'b0, md_shifted[63:32]} - {1'b0, md_d};

    wire [31:0] s_mag = s[31] ? (~s + 32'd1) : s;
    wire [31:0] t_mag = t[31] ? (~t + 32'd1) : t;

    wire ex_is_div = ex_v && (`OP(i_ex) == 6'h00) &&
                     ((`FN(i_ex) == 6'h1A) || (`FN(i_ex) == 6'h1B));
    // md_run distinguishes "this divide has been set up" from "md_count
    // happens to be zero because the last one finished". Without it the
    // first cycle of a divide reads as already done and the instruction
    // leaves EX before the divider has taken a single step.
    wire div_done   = md_run && (md_skip || (md_count == 6'd0));
    assign stall_ex = ex_is_div && !div_done;

    wire [31:0] div_q = md_neg_q ? (~md_rq[31:0]  + 32'd1) : md_rq[31:0];
    wire [31:0] div_r = md_neg_r ? (~md_rq[63:32] + 32'd1) : md_rq[63:32];

    // ------------------------------------------------ EX exceptions

    wire ex_ov = ex_v &&
                 (((`OP(i_ex) == 6'h00) && (`FN(i_ex) == 6'h20) && add_ovf) ||
                  ((`OP(i_ex) == 6'h00) && (`FN(i_ex) == 6'h22) && sub_ovf) ||
                  ((`OP(i_ex) == 6'h08) && addi_ovf));
    wire ex_half = (`OP(i_ex) == 6'h21) || (`OP(i_ex) == 6'h25) ||
                   (`OP(i_ex) == 6'h29);
    wire ex_word = (`OP(i_ex) == 6'h23) || (`OP(i_ex) == 6'h2B);
    wire ex_misaligned = ex_v && ((ex_half && ex_va[0]) ||
                                  (ex_word && |ex_va[1:0]));
    wire ex_sys = ex_v && (`OP(i_ex) == 6'h00) && (`FN(i_ex) == 6'h0C);
    wire ex_bp  = ex_v && (`OP(i_ex) == 6'h00) && (`FN(i_ex) == 6'h0D);

    reg        ex_new_exc;
    reg [4:0]  ex_new_code;
    reg        ex_new_bad_v;
    always @(*) begin
        ex_new_exc = 1'b0; ex_new_code = 5'd0; ex_new_bad_v = 1'b0;
        if (ex_misaligned) begin
            ex_new_exc = 1'b1; ex_new_bad_v = 1'b1;
            ex_new_code = is_store(i_ex) ? EXC_ADES : EXC_ADEL;
        end else if (ex_ov) begin
            ex_new_exc = 1'b1; ex_new_code = EXC_OV;
        end else if (ex_sys) begin
            ex_new_exc = 1'b1; ex_new_code = EXC_SYS;
        end else if (ex_bp) begin
            ex_new_exc = 1'b1; ex_new_code = EXC_BP;
        end
    end

    wire       ex_exc_out_v    = ex_exc_v | ex_new_exc;
    wire [4:0] ex_exc_out_code = ex_exc_v ? ex_exc_code : ex_new_code;
    wire [31:0] ex_exc_out_bad = ex_exc_v ? ex_exc_bad  : ex_va;
    wire       ex_exc_out_badv = ex_exc_v ? ex_exc_bad_v : ex_new_bad_v;

    // =========================================================== MEM

    wire [31:0] i_me = me_insn;
    wire [1:0]  me_bsel = me_va[1:0];
    reg         me_phase;             // 0: the read, 1: the merged write-back
    reg [31:0]  me_rmw_word;

    wire me_needs_mem = me_v && is_mem(i_me) && !me_exc_v;
    wire me_last_beat = is_rmw(i_me) ? me_phase : 1'b1;

    assign dbus_req  = me_needs_mem;
    assign dbus_we   = is_rmw(i_me) ? me_phase : is_store(i_me);
    assign dbus_addr = phys(me_va) & 32'hFFFF_FFFC;

    reg [3:0] me_be;
    always @(*) begin
        case (`OP(i_me))
        6'h20, 6'h24, 6'h28: me_be = 4'b1000 >> me_bsel;     // byte
        6'h21, 6'h25, 6'h29: me_be = me_va[1] ? 4'b0011 : 4'b1100;
        default:             me_be = 4'b1111;                // word and the
        endcase                                              // unaligned forms
    end
    assign dbus_be = me_be;

    // Big-endian merges, written per byte position rather than as shifts so
    // the shift-by-32 corner cases cannot bite.
    reg [31:0] lwl_r, lwr_r, swl_r, swr_r;
    always @(*) begin
        case (me_bsel)
        2'b00: lwl_r = dbus_rdata;
        2'b01: lwl_r = {dbus_rdata[23:0], me_rt[7:0]};
        2'b10: lwl_r = {dbus_rdata[15:0], me_rt[15:0]};
        2'b11: lwl_r = {dbus_rdata[7:0],  me_rt[23:0]};
        endcase
        case (me_bsel)
        2'b00: lwr_r = {me_rt[31:8],  dbus_rdata[31:24]};
        2'b01: lwr_r = {me_rt[31:16], dbus_rdata[31:16]};
        2'b10: lwr_r = {me_rt[31:24], dbus_rdata[31:8]};
        2'b11: lwr_r = dbus_rdata;
        endcase
        case (me_bsel)
        2'b00: swl_r = me_rt;
        2'b01: swl_r = {me_rmw_word[31:24], me_rt[31:8]};
        2'b10: swl_r = {me_rmw_word[31:16], me_rt[31:16]};
        2'b11: swl_r = {me_rmw_word[31:8],  me_rt[31:24]};
        endcase
        case (me_bsel)
        2'b00: swr_r = {me_rt[7:0],  me_rmw_word[23:0]};
        2'b01: swr_r = {me_rt[15:0], me_rmw_word[15:0]};
        2'b10: swr_r = {me_rt[23:0], me_rmw_word[7:0]};
        2'b11: swr_r = me_rt;
        endcase
    end

    reg [31:0] store_word;
    always @(*) begin
        case (`OP(i_me))
        6'h28: store_word = {4{me_rt[7:0]}};
        6'h29: store_word = {2{me_rt[15:0]}};
        6'h2A: store_word = swl_r;
        6'h2E: store_word = swr_r;
        default: store_word = me_rt;
        endcase
    end
    assign dbus_wdata = store_word;

    // Byte-lane extraction. Big-endian: byte 0 of a word is the most
    // significant one.
    reg [7:0]  lb_byte;
    reg [15:0] lh_half;
    always @(*) begin
        case (me_bsel)
        2'b00: lb_byte = dbus_rdata[31:24];
        2'b01: lb_byte = dbus_rdata[23:16];
        2'b10: lb_byte = dbus_rdata[15:8];
        2'b11: lb_byte = dbus_rdata[7:0];
        endcase
        lh_half = me_va[1] ? dbus_rdata[15:0] : dbus_rdata[31:16];
    end

    reg [31:0] load_value;
    always @(*) begin
        case (`OP(i_me))
        6'h20: load_value = {{24{lb_byte[7]}},  lb_byte};
        6'h24: load_value = {24'd0, lb_byte};
        6'h21: load_value = {{16{lh_half[15]}}, lh_half};
        6'h25: load_value = {16'd0, lh_half};
        6'h22: load_value = lwl_r;
        6'h26: load_value = lwr_r;
        default: load_value = dbus_rdata;
        endcase
    end

    wire me_dbe = me_needs_mem && dbus_ack && dbus_err;
    assign stall_mem = me_needs_mem && !(dbus_ack && me_last_beat) && !me_dbe;

    wire        me_exc_out_v    = me_exc_v | me_dbe;
    wire [4:0]  me_exc_out_code = me_exc_v ? me_exc_code : EXC_DBE;
    wire [31:0] me_exc_out_bad  = me_exc_v ? me_exc_bad  : me_va;
    wire        me_exc_out_badv = me_exc_v ? me_exc_bad_v : 1'b1;

    // All exceptions are committed here, at one point in the pipeline, so
    // that the oldest instruction always wins without a priority network.
    assign exc_flush = me_v && me_exc_out_v && adv_mem;

    wire [31:0] exc_vector = cp0[CP0_STATUS][22] ? 32'hBFC0_0180 : 32'h8000_0080;

    // =========================================================== WB

    // One edge behind WB on purpose: the register file write for an
    // instruction in WB happens on the edge that ends its WB cycle, so
    // naming it while it is still in WB would point at state it has not
    // written yet. Observers compare after the edge.
    reg        rt_v;
    reg [31:0] rt_pc, rt_insn, rt_next_pc;

    assign retire_valid   = rt_v;
    assign retire_pc      = rt_pc;
    assign retire_insn    = rt_insn;
    assign retire_next_pc = rt_next_pc;

    // =========================================================== sequencing

    always @(posedge clk or negedge rst_n) begin : sequencing
        integer k;
        if (!rst_n) begin
            for (k = 0; k < 32; k = k + 1) begin
                regs[k] <= 32'd0;
                cp0[k]  <= 32'd0;
            end
            hi <= 32'd0; lo <= 32'd0;
            // Architectural reset: BEV set, interrupts off, kernel mode.
            cp0[CP0_STATUS] <= 32'h0040_0000;
            cp0[CP0_PRID]   <= 32'h0000_2200;
            cp0[CP0_RANDOM] <= 32'd31;
            fpc      <= 32'hBFC0_0000;
            a_pc     <= 32'hBFC0_0000;
            a_next_pc<= 32'hBFC0_0004;
            redir_v  <= 1'b0;
            id_v     <= 1'b0; ex_v <= 1'b0; me_v <= 1'b0; wb_v <= 1'b0;
            rt_v     <= 1'b0;
            id_ds    <= 1'b0;
            id_exc_v <= 1'b0; ex_exc_v <= 1'b0; me_exc_v <= 1'b0;
            me_phase <= 1'b0;
            md_count <= 6'd0; md_run <= 1'b0; md_skip <= 1'b0;
            insn_count <= 64'd0; cycle_count <= 64'd0;
            cache_ops  <= 64'd0; exc_count   <= 64'd0;
        end else begin
            if (!COUNT_PER_INSN) cp0[CP0_COUNT] <= cp0[CP0_COUNT] + 32'd1;

            // ------------------------------------------------ WB commit
            rt_v <= wb_v;
            if (wb_v) begin
                rt_pc      <= wb_pc;
                rt_insn    <= wb_insn;
                rt_next_pc <= wb_next_pc;
            end
            if (wb_v) begin
                if (wb_we && (wb_wa != 5'd0)) regs[wb_wa] <= wb_value;
                if (wb_hilo_we) begin hi <= wb_hi; lo <= wb_lo; end
                if (wb_cp0_we) begin
                    case (wb_cp0_a)
                    // PE is a latch the cache sets and software clears by
                    // writing a one. Nothing here sets it, so it must read
                    // back zero; storing it verbatim makes the ROM's monitor
                    // report a parity error after every character.
                    CP0_STATUS: cp0[CP0_STATUS] <= wb_cp0_d & ~SR_PE;
                    // Only the two software interrupt bits of Cause are
                    // writable; the hardware lines belong to the ICU.
                    CP0_CAUSE:  cp0[CP0_CAUSE] <= (cp0[CP0_CAUSE] & ~32'h300)
                                                | (wb_cp0_d & 32'h300);
                    CP0_PRID, CP0_RANDOM, CP0_BADVADDR: ;
                    CP0_COUNT:  cycle_count <= {wb_cp0_d, 1'b0};
                    5'd31:      cp0[CP0_STATUS] <= (cp0[CP0_STATUS] & ~32'hF)
                                                 | ((cp0[CP0_STATUS] >> 2) & 32'hF);
                    default:    cp0[wb_cp0_a] <= wb_cp0_d;
                    endcase
                end
                if (wb_cache) cache_ops <= cache_ops + 64'd1;
                insn_count  <= insn_count  + 64'd1;
                cycle_count <= cycle_count + 64'd1;
            end

            // ------------------------------------------------ MEM -> WB
            wb_v <= adv_mem ? (me_v && !me_exc_out_v) : 1'b0;
            if (adv_mem) begin
                wb_pc      <= me_pc;
                wb_insn    <= me_insn;
                wb_next_pc <= me_next_pc;
                wb_we      <= writes_gpr(i_me);
                wb_wa      <= dest_reg(i_me);
                wb_value   <= is_load(i_me) ? load_value : me_result;
                wb_hi      <= me_hi;
                wb_lo      <= me_lo;
                wb_hilo_we <= me_hilo_we;
                wb_cache   <= (`OP(i_me) == 6'h2F);
                wb_cp0_we  <= (`OP(i_me) == 6'h10) &&
                              ((`RS(i_me) == 5'h04) || (`RS(i_me) == 5'h10));
                wb_cp0_a   <= (`RS(i_me) == 5'h10) ? 5'd31 : `RD(i_me);
                wb_cp0_d   <= me_rt;
                me_phase   <= 1'b0;
            end else if (me_needs_mem && dbus_ack && !dbus_err && is_rmw(i_me)
                         && !me_phase) begin
                // The read half of SWL/SWR landed; merge and write it back.
                me_rmw_word <= dbus_rdata;
                me_phase    <= 1'b1;
            end

            // ------------------------------------------------ EX -> MEM
            if (adv_mem) begin
                me_v         <= ex_v && !exc_flush;
                me_pc        <= ex_pc;
                me_insn      <= ex_insn;
                me_next_pc   <= ex_next_pc;
                me_result    <= alu;
                me_rt        <= t;
                me_va        <= ex_va;
                me_ds        <= ex_ds;
                me_exc_v     <= ex_exc_out_v;
                me_exc_code  <= ex_exc_out_code;
                me_exc_bad   <= ex_exc_out_bad;
                me_exc_bad_v <= ex_exc_out_badv;
                me_hilo_we   <= 1'b0;
                if (ex_v && (`OP(i_ex) == 6'h00)) begin
                    case (`FN(i_ex))
                    6'h11: begin me_hilo_we <= 1'b1; me_hi <= s;  me_lo <= lo; end
                    6'h13: begin me_hilo_we <= 1'b1; me_hi <= hi; me_lo <= s;  end
                    6'h18: begin me_hilo_we <= 1'b1;
                                 me_hi <= mul_s[63:32]; me_lo <= mul_s[31:0]; end
                    6'h19: begin me_hilo_we <= 1'b1;
                                 me_hi <= mul_u[63:32]; me_lo <= mul_u[31:0]; end
                    6'h1A, 6'h1B: begin me_hilo_we <= 1'b1;
                                 me_hi <= md_skip ? md_fix_hi : div_r;
                                 me_lo <= md_skip ? md_fix_lo : div_q; end
                    default: ;
                    endcase
                end
                if (!adv_ex) me_v <= 1'b0;      // EX is busy; insert a bubble
            end

            // ------------------------------------------------ divide engine
            if (ex_is_div && !md_run) begin
                md_run <= 1'b1;
                md_count <= 6'd32;
                if (`FN(i_ex) == 6'h1B) begin                      // DIVU
                    md_rq <= {32'd0, s};  md_d <= t;
                    md_neg_q <= 1'b0; md_neg_r <= 1'b0;
                    md_skip  <= (t == 32'd0);
                    md_fix_lo <= 32'hFFFF_FFFF; md_fix_hi <= s;
                end else begin                                     // DIV
                    md_rq <= {32'd0, s_mag}; md_d <= t_mag;
                    md_neg_q <= s[31] ^ t[31];
                    md_neg_r <= s[31];
                    if (t == 32'd0) begin
                        md_skip <= 1'b1;
                        md_fix_lo <= s[31] ? 32'd1 : 32'hFFFF_FFFF;
                        md_fix_hi <= s;
                    end else if (s == 32'h8000_0000 && t == 32'hFFFF_FFFF) begin
                        md_skip <= 1'b1;
                        md_fix_lo <= 32'h8000_0000; md_fix_hi <= 32'd0;
                    end else md_skip <= 1'b0;
                end
            end else if (md_run && !md_skip && md_count != 6'd0) begin
                md_rq    <= md_diff[32] ? md_shifted
                                        : {md_diff[31:0], md_shifted[31:1], 1'b1};
                md_count <= md_count - 6'd1;
            end
            if (adv_ex) begin md_run <= 1'b0; md_skip <= 1'b0; md_count <= 6'd0; end

            // ------------------------------------------------ ID -> EX
            if (adv_ex) begin
                ex_v         <= adv_id && id_v && !exc_flush && !id_take_irq;
                ex_pc        <= id_pc;
                ex_insn      <= id_insn;
                ex_next_pc   <= id_next_pc;
                ex_rs_raw    <= id_s;
                ex_rt_raw    <= id_t;
                ex_ds        <= id_ds;
                ex_exc_bad   <= id_exc_bad;
                ex_exc_bad_v <= id_exc_bad_v;
                if (id_exc_v) begin
                    ex_exc_v <= 1'b1; ex_exc_code <= id_exc_code;
                end else if (id_take_irq) begin
                    ex_v <= adv_id && id_v && !exc_flush;
                    ex_exc_v <= 1'b1; ex_exc_code <= EXC_INT;
                    ex_exc_bad_v <= 1'b0;
                end else if (id_v && illegal(id_insn)) begin
                    ex_exc_v <= 1'b1; ex_exc_code <= EXC_RI;
                    ex_exc_bad_v <= 1'b0;
                end else begin
                    ex_exc_v <= 1'b0;
                end
                if (!adv_id) ex_v <= 1'b0;      // ID is stalled; bubble
            end

            // ------------------------------------------------ IF -> ID
            if (adv_id) begin
                id_v <= fetch_ok && !exc_flush;
                if (fetch_ok) begin
                    id_pc        <= fpc;
                    id_insn      <= ibus_rdata;
                    id_ds        <= id_v && is_branch(i_id) && id_taken;
                    id_exc_v     <= ibus_err;
                    id_exc_code  <= EXC_IBE;
                    id_exc_bad   <= fpc;
                    id_exc_bad_v <= ibus_err;
                    // Architectural pc pair advances with the instruction
                    // leaving ID, not with the fetch.
                end
            end

            // The architectural pair tracks committed decode order.
            if (adv_id && id_v && !exc_flush) begin
                a_pc      <= a_next_pc;
                a_next_pc <= id_next_pc;
            end

            // ------------------------------------------------ IF
            if (fetch_ok && !exc_flush) begin
                fpc <= redir_v ? redir_pc
                     : (id_redirect ? id_target : (fpc + 32'd4));
                if (redir_v) redir_v <= 1'b0;
            end else if (id_redirect && !exc_flush) begin
                // The delay slot has not been fetched yet; remember where to
                // go once it has.
                redir_v  <= 1'b1;
                redir_pc <= id_target;
            end

            // ------------------------------------------------ exception
            if (exc_flush) begin
                exc_count <= exc_count + 64'd1;
                // EPC names the branch when the faulting instruction sat in
                // its delay slot, and Cause.BD says so.
                cp0[CP0_EPC] <= me_ds ? (me_pc - 32'd4) : me_pc;
                cp0[CP0_CAUSE] <= (cause_live & ~32'h0000_007C & ~32'h8000_0000)
                                | ({27'd0, me_exc_out_code} << 2)
                                | (me_ds ? 32'h8000_0000 : 32'd0);
                if (me_exc_out_badv) cp0[CP0_BADVADDR] <= me_exc_out_bad;
                // MIPS-I: shift the KU/IE stack left, entering kernel mode
                // with interrupts disabled.
                cp0[CP0_STATUS] <= (cp0[CP0_STATUS] & ~32'h3F)
                                 | ((cp0[CP0_STATUS] << 2) & 32'h3C);
                fpc       <= exc_vector;
                a_pc      <= exc_vector;
                a_next_pc <= exc_vector + 32'd4;
                redir_v   <= 1'b0;
                id_v      <= 1'b0;
                ex_v      <= 1'b0;
                me_v      <= 1'b0;
                id_ds     <= 1'b0;
                id_exc_v  <= 1'b0;
                ex_exc_v  <= 1'b0;
                me_exc_v  <= 1'b0;
                me_phase  <= 1'b0;
            end
        end
    end

`ifdef SIMULATION
    // The architectural pc pair exists to produce next_pc. If it ever
    // disagrees with what was actually fetched, next_pc is meaningless and
    // so is every comparison made against it.
    always @(posedge clk) if (rst_n && adv_id && id_v && !exc_flush)
        if (a_pc !== id_pc) begin
            $display("r3900: architectural pc %08X != fetched pc %08X", a_pc, id_pc);
            $stop;
        end
`endif

endmodule

`default_nettype wire
