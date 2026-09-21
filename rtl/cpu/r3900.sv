//
// r3900.sv - Toshiba TX39 (R3900) integer core, as fitted to the Oki
// DataRover 840 as part of the TMPR3902U.
//
// The architectural model here is the one established by magicrecomp, whose
// C core is the reference this is validated against instruction by
// instruction (see sim/cosim). Where the R3900 differs from a generic
// MIPS-I part, the difference is called out at the point it matters:
//
//   - big-endian
//   - no TLB: kseg0/kseg1 mask the top three bits, everything else maps
//     straight through
//   - no architectural load delay slot; the part scoreboards instead, so a
//     load result is available to the very next instruction
//   - CP0 Config is $3, not $16
//   - Status.PE (bit 20) is a write-one-to-clear latch, not a stored bit
//   - PRId reads 0x2200, which the ROM branches on
//   - CACHE (opcode 0x2F) exists and is counted
//
// Anything outside MIPS-I + CACHE + RFE raises Reserved Instruction rather
// than being treated as a NOP, matching the reference exactly. The MADD
// family the R3900 also has is deliberately absent: the reference does not
// implement it either, and this ROM does not use it. Adding it here without
// adding it there would break lockstep for no gain.
//
// This is the correctness-first sequencing: one instruction at a time,
// through an explicit state machine. It retires roughly one instruction per
// four cycles, which is not enough to stand in for a 36.864 MHz part at one
// instruction per cycle. Pipelining is the next step; the retire port below
// is what lets that happen without changing how the core is validated.
//
`default_nettype none

module r3900 #(
    // CP0 Count.
    //
    // The reference core ticks Count once per two retired instructions and
    // says in its own source that this is a placeholder, not a measurement.
    // Lockstep has to agree with it, so the cosim build sets this; a real
    // build counts cycles, which is what the hardware does. Either way the
    // ROM barely reads it -- 21 mfc0 in the first million instructions.
    parameter bit COUNT_PER_INSN = 1'b0
) (
    input  wire        clk,
    input  wire        rst_n,

    // Instruction fetch. Physical address; the core does its own segment
    // mapping. Single outstanding request, held until ack.
    output wire [31:0] ibus_addr,
    output wire        ibus_req,
    input  wire        ibus_ack,
    input  wire [31:0] ibus_rdata,
    input  wire        ibus_err,

    // Data. Big-endian byte lanes: be[3] is bits 31:24, the byte at the
    // word address itself.
    output wire [31:0] dbus_addr,
    output wire        dbus_req,
    output wire        dbus_we,
    output wire [3:0]  dbus_be,
    output wire [31:0] dbus_wdata,
    input  wire        dbus_ack,
    input  wire [31:0] dbus_rdata,
    input  wire        dbus_err,

    // Hardware interrupt lines IP2..IP7, into Cause.IP[7:2].
    input  wire [5:0]  irq_in,

    // Retire observation. Valid for one cycle as each instruction commits,
    // with the architectural state it produced already visible. This is the
    // comparison point against the reference core; it carries no logic.
    output wire        retire_valid,
    output wire [31:0] retire_pc,
    output wire [31:0] retire_insn,
    output wire [31:0] retire_next_pc
);

    // ---------------------------------------------------------------- state

    reg [31:0] regs [0:31] /* verilator public */;
    reg [31:0] hi /* verilator public */;
    reg [31:0] lo /* verilator public */;

    // The reference's three-address model, kept verbatim so that the delay
    // slot needs no special case: pc is what runs next, next_pc is what runs
    // after that, and a taken branch simply rewrites next_pc.
    reg [31:0] pc      /* verilator public */;
    reg [31:0] next_pc /* verilator public */;
    reg [31:0] cur_pc;
    reg        branch_pending;
    reg        in_delay;

    reg [31:0] cp0 [0:31];

    reg [31:0] insn;
    reg [63:0] insn_count  /* verilator public */;
    reg [63:0] cycle_count /* verilator public */;
    reg [63:0] cache_ops  /* verilator public */;
    reg [63:0] exc_count  /* verilator public */;

    // ------------------------------------------------------- CP0 definitions

    localparam CP0_INDEX    = 5'd0,  CP0_RANDOM  = 5'd1,  CP0_ENTRYLO = 5'd2;
    localparam CP0_CONFIG   = 5'd3,  CP0_CONTEXT = 5'd4,  CP0_BADVADDR= 5'd8;
    localparam CP0_COUNT    = 5'd9,  CP0_ENTRYHI = 5'd10, CP0_COMPARE = 5'd11;
    localparam CP0_STATUS   = 5'd12, CP0_CAUSE   = 5'd13, CP0_EPC     = 5'd14;
    localparam CP0_PRID     = 5'd15;

    localparam [31:0] SR_IEc = 32'h0000_0001;
    localparam [31:0] SR_PE  = 32'h0010_0000;
    localparam [31:0] SR_BEV = 32'h0040_0000;

    localparam EXC_INT = 5'd0,  EXC_ADEL = 5'd4,  EXC_ADES = 5'd5;
    localparam EXC_IBE = 5'd6,  EXC_DBE  = 5'd7,  EXC_SYS  = 5'd8;
    localparam EXC_BP  = 5'd9,  EXC_RI   = 5'd10, EXC_OV   = 5'd12;

    // ------------------------------------------------------------- decode

    wire [5:0]  op    = insn[31:26];
    wire [4:0]  rs    = insn[25:21];
    wire [4:0]  rt    = insn[20:16];
    wire [4:0]  rd    = insn[15:11];
    wire [4:0]  sa    = insn[10:6];
    wire [5:0]  funct = insn[5:0];
    wire [15:0] imm   = insn[15:0];
    wire [31:0] simm  = {{16{imm[15]}}, imm};
    wire [31:0] zimm  = {16'd0, imm};

    wire [31:0] rs_val = (rs == 5'd0) ? 32'd0 : regs[rs];
    wire [31:0] rt_val = (rt == 5'd0) ? 32'd0 : regs[rt];

    // Jump target: the delay slot's address supplies the upper four bits,
    // which is pc, not cur_pc, at the point a jump executes.
    wire [31:0] jump_target   = {pc[31:28], insn[25:0], 2'b00};
    wire [31:0] branch_target = pc + {simm[29:0], 2'b00};

    // ------------------------------------------------------- address mapping

    // No TLB. kseg0 and kseg1 mask off the top three bits; kuseg, kseg2 and
    // kseg3 map straight through. Established from the ROM, not assumed --
    // see docs/HARDWARE.md in magicrecomp.
    function [31:0] phys(input [31:0] va);
        phys = (va >= 32'h8000_0000 && va < 32'hC000_0000)
             ? (va & 32'h1FFF_FFFF) : va;
    endfunction

    // ----------------------------------------------------------------- ALU

    wire [31:0] add_result  = rs_val + rt_val;
    wire [31:0] sub_result  = rs_val - rt_val;
    wire [31:0] addi_result = rs_val + simm;

    wire add_ovf  = (rs_val[31] == rt_val[31]) && (add_result[31] != rs_val[31]);
    wire sub_ovf  = (rs_val[31] != rt_val[31]) && (sub_result[31] != rs_val[31]);
    wire addi_ovf = (rs_val[31] == simm[31])   && (addi_result[31] != rs_val[31]);

    wire slt_rr  = ($signed(rs_val) < $signed(rt_val));
    wire sltu_rr = (rs_val < rt_val);
    wire slt_ri  = ($signed(rs_val) < $signed(simm));
    wire sltu_ri = (rs_val < simm);

    wire [4:0]  shamt   = (funct[2]) ? rs_val[4:0] : sa;   // 04/06/07 use rs
    wire [31:0] sll_res = rt_val << shamt;
    wire [31:0] srl_res = rt_val >> shamt;
    wire [31:0] sra_res = $signed(rt_val) >>> shamt;

    // ------------------------------------------------------- multiply/divide

    // Multiply is one cycle: Cyclone V has DSP blocks and a 32x32 product
    // closes timing far above the clock this part runs at. Divide cannot be
    // inferred that way, so it is a restoring divider over 32 cycles,
    // operating on magnitudes with the signs reapplied at the end.
    //
    // The divide-by-zero and 0x80000000 / -1 results are not "undefined" as
    // far as this core is concerned: they are whatever the reference
    // produces, because lockstep compares them.
    wire [63:0] mul_signed   = $signed(rs_val) * $signed(rt_val);
    wire [63:0] mul_unsigned = rs_val * rt_val;

    reg [63:0] md_rq;        // {remainder, quotient} shifting left
    reg [31:0] md_d;         // divisor magnitude
    reg [5:0]  md_count;
    reg        md_neg_q, md_neg_r, md_skip;
    reg [31:0] md_fix_hi, md_fix_lo;

    wire [63:0] md_shifted = {md_rq[62:0], 1'b0};
    wire [32:0] md_diff    = {1'b0, md_shifted[63:32]} - {1'b0, md_d};

    wire [31:0] rs_mag = rs_val[31] ? (~rs_val + 32'd1) : rs_val;
    wire [31:0] rt_mag = rt_val[31] ? (~rt_val + 32'd1) : rt_val;

    // -------------------------------------------------------- load/store aux

    wire [31:0] mem_va   = rs_val + simm;
    wire [1:0]  byte_sel = mem_va[1:0];

    reg [31:0] load_result;
    reg [3:0]  store_be;
    reg [31:0] store_data;

    // LWL/LWR/SWL/SWR. All four start with a word read at the aligned
    // address; the two stores then write the merged word back, so they take
    // two bus accesses and a second memory phase.
    reg        mem_phase;      // 0: the read, 1: the write-back of a S*L/S*R
    wire       is_lwl = (op == 6'h22);
    wire       is_lwr = (op == 6'h26);
    wire       is_swl = (op == 6'h2A);
    wire       is_swr = (op == 6'h2E);
    wire       is_unaligned = is_lwl | is_lwr | is_swl | is_swr;

    // Big-endian merges, written out per byte position rather than as
    // shifts, so the shift-by-32 corner cases cannot bite.
    reg [31:0] lwl_result, lwr_result, swl_result, swr_result;
    always @(*) begin
        case (byte_sel)
        2'b00: lwl_result = dbus_rdata;
        2'b01: lwl_result = {dbus_rdata[23:0], rt_val[7:0]};
        2'b10: lwl_result = {dbus_rdata[15:0], rt_val[15:0]};
        2'b11: lwl_result = {dbus_rdata[7:0],  rt_val[23:0]};
        endcase
        case (byte_sel)
        2'b00: lwr_result = {rt_val[31:8],  dbus_rdata[31:24]};
        2'b01: lwr_result = {rt_val[31:16], dbus_rdata[31:16]};
        2'b10: lwr_result = {rt_val[31:24], dbus_rdata[31:8]};
        2'b11: lwr_result = dbus_rdata;
        endcase
        case (byte_sel)
        2'b00: swl_result = rt_val;
        2'b01: swl_result = {dbus_rdata[31:24], rt_val[31:8]};
        2'b10: swl_result = {dbus_rdata[31:16], rt_val[31:16]};
        2'b11: swl_result = {dbus_rdata[31:8],  rt_val[31:24]};
        endcase
        case (byte_sel)
        2'b00: swr_result = {rt_val[7:0],  dbus_rdata[23:0]};
        2'b01: swr_result = {rt_val[15:0], dbus_rdata[15:0]};
        2'b10: swr_result = {rt_val[23:0], dbus_rdata[7:0]};
        2'b11: swr_result = rt_val;
        endcase
    end

    // ------------------------------------------------------------ sequencing

    localparam S_RESET = 3'd0, S_FETCH = 3'd1, S_EXEC = 3'd2,
               S_MEM   = 3'd3, S_MULDIV = 3'd4, S_TRAP = 3'd5;

    reg [2:0] state;
    reg [4:0] trap_code;
    reg [31:0] trap_bad;
    reg        trap_have_bad;

    reg        r_valid;
    reg [31:0] r_pc, r_insn, r_next_pc;

    assign retire_valid   = r_valid;
    assign retire_pc      = r_pc;
    assign retire_insn    = r_insn;
    assign retire_next_pc = r_next_pc;

    assign ibus_addr = phys(pc);
    assign ibus_req  = (state == S_FETCH);

    reg        d_req;
    reg        d_we;
    reg [31:0] d_addr;
    assign dbus_req   = d_req;
    assign dbus_we    = d_we;
    assign dbus_addr  = d_addr;
    assign dbus_be    = store_be;
    assign dbus_wdata = store_data;

    // An interrupt is taken in place of an instruction, never alongside one.
    wire [31:0] cause_live = (cp0[CP0_CAUSE] & ~32'h0000_FC00)
                           | ({26'd0, irq_in} << 10);
    wire irq_taken = cp0[CP0_STATUS][0]
                  && |(cause_live[15:8] & cp0[CP0_STATUS][15:8]);

    integer i;

    // -------------------------------------------------------- CP0 read/write

    function [31:0] cp0_read(input [4:0] n);
        case (n)
            CP0_CAUSE: cp0_read = cause_live;
            CP0_COUNT: cp0_read = COUNT_PER_INSN ? cycle_count[32:1] : cp0[CP0_COUNT];
            default:   cp0_read = cp0[n];
        endcase
    endfunction

    task cp0_write(input [4:0] n, input [31:0] v);
        begin
            case (n)
                // PE is a latch the cache sets and software clears by
                // writing a one. Nothing here sets it, so it must always
                // read back zero; storing it verbatim makes the ROM's
                // monitor report a parity error after every character.
                CP0_STATUS: cp0[CP0_STATUS] <= v & ~SR_PE;
                // Only the two software interrupt bits of Cause are
                // writable; the hardware lines belong to the ICU.
                CP0_CAUSE:  cp0[CP0_CAUSE] <= (cp0[CP0_CAUSE] & ~32'h300)
                                            | (v & 32'h300);
                CP0_PRID, CP0_RANDOM, CP0_BADVADDR: ;   // read-only
                CP0_COUNT:  cycle_count <= {v, 1'b0};
                default:    cp0[n] <= v;
            endcase
        end
    endtask

    // ------------------------------------------------------------- execution

    // Advance to the next instruction, honouring a pending branch. Mirrors
    // the reference: pc takes next_pc, next_pc runs on, and a branch taken
    // this instruction has already rewritten next_pc.
    task retire_seq;
        begin
            cycle_count <= cycle_count + 64'd1;
            r_valid   <= 1'b1;
            r_pc      <= cur_pc;
            r_insn    <= insn;
            r_next_pc <= next_pc;
            insn_count <= insn_count + 1;
            state     <= S_FETCH;
        end
    endtask

    task do_branch(input cond, input [31:0] target);
        begin
            if (cond) begin
                next_pc        <= target;
                branch_pending <= 1'b1;
                r_next_pc      <= target;   // retire shows the taken target
            end
        end
    endtask

    // Jumps are unconditional, so they share the same path.
    task do_jump(input [31:0] target);
        begin
            next_pc        <= target;
            branch_pending <= 1'b1;
            r_next_pc      <= target;
        end
    endtask

    task wr(input [4:0] n, input [31:0] v);
        begin
            if (n != 5'd0) regs[n] <= v;
        end
    endtask

    task raise(input [4:0] code, input [31:0] bad, input have_bad);
        begin
            trap_code     <= code;
            trap_bad      <= bad;
            trap_have_bad <= have_bad;
            state         <= S_TRAP;
        end
    endtask

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (i = 0; i < 32; i = i + 1) regs[i] <= 32'd0;
            for (i = 0; i < 32; i = i + 1) cp0[i]  <= 32'd0;
            hi <= 32'd0; lo <= 32'd0;
            // Architectural reset: BEV set, interrupts off, kernel mode.
            cp0[CP0_STATUS] <= SR_BEV;
            cp0[CP0_PRID]   <= 32'h0000_2200;
            cp0[CP0_RANDOM] <= 32'd31;
            pc      <= 32'hBFC0_0000;
            next_pc <= 32'hBFC0_0004;
            cur_pc  <= 32'hBFC0_0000;
            branch_pending <= 1'b0;
            in_delay       <= 1'b0;
            insn_count  <= 64'd0;
            cycle_count <= 64'd0;
            cache_ops   <= 64'd0;
            mem_phase   <= 1'b0;
            exc_count  <= 64'd0;
            md_skip    <= 1'b0;
            d_req      <= 1'b0;
            r_valid    <= 1'b0;
            state      <= S_FETCH;
        end else begin
            r_valid <= 1'b0;
            if (!COUNT_PER_INSN) cp0[CP0_COUNT] <= cp0[CP0_COUNT] + 32'd1;

            case (state)

            // ------------------------------------------------------ fetch
            S_FETCH: begin
                cur_pc   <= pc;
                in_delay <= branch_pending;
                if (irq_taken) begin
                    cur_pc   <= pc;
                    in_delay <= branch_pending;
                    raise(EXC_INT, 32'd0, 1'b0);
                end else if (pc[1:0] != 2'b00) begin
                    cur_pc <= pc;
                    raise(EXC_ADEL, pc, 1'b1);
                end else if (ibus_ack) begin
                    insn           <= ibus_rdata;
                    branch_pending <= 1'b0;
                    pc             <= next_pc;
                    next_pc        <= next_pc + 4;
                    if (ibus_err) raise(EXC_IBE, pc, 1'b1);
                    else          state <= S_EXEC;
                end
            end

            // ---------------------------------------------------- execute
            S_EXEC: begin
                state <= S_FETCH;
                r_valid   <= 1'b1;
                r_pc      <= cur_pc;
                r_insn    <= insn;
                r_next_pc <= next_pc;
                insn_count  <= insn_count + 64'd1;
                cycle_count <= cycle_count + 64'd1;

                case (op)
                6'h00: begin // SPECIAL
                    case (funct)
                    6'h00: wr(rd, sll_res);
                    6'h02: wr(rd, srl_res);
                    6'h03: wr(rd, sra_res);
                    6'h04: wr(rd, sll_res);
                    6'h06: wr(rd, srl_res);
                    6'h07: wr(rd, sra_res);
                    6'h08: do_jump(rs_val);                       // JR
                    6'h09: begin                                  // JALR
                        wr(rd == 5'd0 ? 5'd31 : rd, pc + 4);
                        do_jump(rs_val);
                    end
                    6'h0C: begin r_valid <= 1'b0; insn_count <= insn_count; cycle_count <= cycle_count;
                                 raise(EXC_SYS, 32'd0, 1'b0); end
                    6'h0D: begin r_valid <= 1'b0; insn_count <= insn_count; cycle_count <= cycle_count;
                                 raise(EXC_BP,  32'd0, 1'b0); end
                    6'h10: wr(rd, hi);
                    6'h11: hi <= rs_val;
                    6'h12: wr(rd, lo);
                    6'h13: lo <= rs_val;
                    6'h18: begin lo <= mul_signed[31:0];   hi <= mul_signed[63:32];   end
                    6'h19: begin lo <= mul_unsigned[31:0]; hi <= mul_unsigned[63:32]; end
                    6'h1A, 6'h1B: begin // DIV / DIVU
                        r_valid <= 1'b0; insn_count <= insn_count; cycle_count <= cycle_count;
                        state   <= S_MULDIV;
                        md_count <= 6'd32;
                        if (funct[0]) begin                       // DIVU
                            md_rq    <= {32'd0, rs_val};
                            md_d     <= rt_val;
                            md_neg_q <= 1'b0;
                            md_neg_r <= 1'b0;
                            md_skip  <= (rt_val == 32'd0);
                            md_fix_lo <= 32'hFFFF_FFFF;
                            md_fix_hi <= rs_val;
                        end else begin                            // DIV
                            md_rq    <= {32'd0, rs_mag};
                            md_d     <= rt_mag;
                            md_neg_q <= rs_val[31] ^ rt_val[31];
                            md_neg_r <= rs_val[31];
                            if (rt_val == 32'd0) begin
                                md_skip   <= 1'b1;
                                md_fix_lo <= rs_val[31] ? 32'd1 : 32'hFFFF_FFFF;
                                md_fix_hi <= rs_val;
                            end else if (rs_val == 32'h8000_0000 &&
                                         rt_val == 32'hFFFF_FFFF) begin
                                md_skip   <= 1'b1;
                                md_fix_lo <= 32'h8000_0000;
                                md_fix_hi <= 32'd0;
                            end else begin
                                md_skip <= 1'b0;
                            end
                        end
                    end
                    6'h20: if (add_ovf) begin
                               r_valid <= 1'b0; insn_count <= insn_count; cycle_count <= cycle_count;
                               raise(EXC_OV, 32'd0, 1'b0);
                           end else wr(rd, add_result);
                    6'h21: wr(rd, add_result);
                    6'h22: if (sub_ovf) begin
                               r_valid <= 1'b0; insn_count <= insn_count; cycle_count <= cycle_count;
                               raise(EXC_OV, 32'd0, 1'b0);
                           end else wr(rd, sub_result);
                    6'h23: wr(rd, sub_result);
                    6'h24: wr(rd, rs_val & rt_val);
                    6'h25: wr(rd, rs_val | rt_val);
                    6'h26: wr(rd, rs_val ^ rt_val);
                    6'h27: wr(rd, ~(rs_val | rt_val));
                    6'h2A: wr(rd, {31'd0, slt_rr});
                    6'h2B: wr(rd, {31'd0, sltu_rr});
                    default: begin r_valid <= 1'b0; insn_count <= insn_count; cycle_count <= cycle_count;
                                   raise(EXC_RI, 32'd0, 1'b0); end
                    endcase
                end

                6'h01: begin // REGIMM
                    case (rt)
                    5'h00: do_branch($signed(rs_val) <  0, branch_target);
                    5'h01: do_branch($signed(rs_val) >= 0, branch_target);
                    5'h10: begin wr(5'd31, pc + 4);
                                 do_branch($signed(rs_val) <  0, branch_target); end
                    5'h11: begin wr(5'd31, pc + 4);
                                 do_branch($signed(rs_val) >= 0, branch_target); end
                    default: begin r_valid <= 1'b0; insn_count <= insn_count; cycle_count <= cycle_count;
                                   raise(EXC_RI, 32'd0, 1'b0); end
                    endcase
                end

                6'h02: do_jump(jump_target);                      // J
                6'h03: begin wr(5'd31, pc + 4); do_jump(jump_target); end  // JAL

                6'h04: do_branch(rs_val == rt_val, branch_target);
                6'h05: do_branch(rs_val != rt_val, branch_target);
                6'h06: do_branch($signed(rs_val) <= 0, branch_target);
                6'h07: do_branch($signed(rs_val) >  0, branch_target);

                6'h08: if (addi_ovf) begin
                           r_valid <= 1'b0; insn_count <= insn_count; cycle_count <= cycle_count;
                           raise(EXC_OV, 32'd0, 1'b0);
                       end else wr(rt, addi_result);
                6'h09: wr(rt, addi_result);
                6'h0A: wr(rt, {31'd0, slt_ri});
                6'h0B: wr(rt, {31'd0, sltu_ri});
                6'h0C: wr(rt, rs_val & zimm);
                6'h0D: wr(rt, rs_val | zimm);
                6'h0E: wr(rt, rs_val ^ zimm);
                6'h0F: wr(rt, {imm, 16'd0});

                6'h10: begin // COP0
                    case (rs)
                    5'h00: wr(rt, cp0_read(rd));
                    5'h04: cp0_write(rd, rt_val);
                    5'h10: begin
                        if (funct == 6'h10) // RFE: pop the KU/IE stack
                            cp0[CP0_STATUS] <= (cp0[CP0_STATUS] & ~32'hF)
                                             | ((cp0[CP0_STATUS] >> 2) & 32'hF);
                        else begin
                            r_valid <= 1'b0; insn_count <= insn_count; cycle_count <= cycle_count;
                            raise(EXC_RI, 32'd0, 1'b0);
                        end
                    end
                    default: begin r_valid <= 1'b0; insn_count <= insn_count; cycle_count <= cycle_count;
                                   raise(EXC_RI, 32'd0, 1'b0); end
                    endcase
                end

                // Loads and stores hand off to S_MEM; nothing retires here.
                6'h20, 6'h21, 6'h23, 6'h24, 6'h25,
                6'h28, 6'h29, 6'h2B,
                6'h22, 6'h26, 6'h2A, 6'h2E: begin
                    r_valid <= 1'b0; insn_count <= insn_count; cycle_count <= cycle_count;
                    state   <= S_MEM;
                    mem_phase <= 1'b0;
                    // Word-aligned with byte lanes, the shape the rest of
                    // the machine wants. The lane itself comes from the low
                    // two address bits, big-endian: lane 3 is the byte at
                    // the word address.
                    d_addr  <= phys(mem_va) & 32'hFFFF_FFFC;
                    d_req   <= 1'b1;
                    d_we    <= is_unaligned ? 1'b0 : op[3];
                    // Lanes follow the access width, for loads as well as
                    // stores: the bus wants to know which bytes are being
                    // asked for either way.
                    case (op)
                    6'h20, 6'h24, 6'h28:  // LB, LBU, SB
                        store_be <= 4'b1000 >> byte_sel;
                    6'h21, 6'h25, 6'h29:  // LH, LHU, SH
                        store_be <= mem_va[1] ? 4'b0011 : 4'b1100;
                    default:              // LW, SW, and the unaligned forms
                        store_be <= 4'b1111;
                    endcase
                    case (op)
                    6'h28: store_data <= {4{rt_val[7:0]}};
                    6'h29: store_data <= {2{rt_val[15:0]}};
                    default: store_data <= rt_val;
                    endcase
                    // Alignment is checked before the access is issued.
                    // LWL/LWR/SWL/SWR are exempt: misalignment is the point.
                    if (is_unaligned) begin
                        // already set up as an aligned word read
                    end else if ((op == 6'h21 || op == 6'h25 || op == 6'h29) && mem_va[0]) begin
                        d_req <= 1'b0; state <= S_EXEC;
                        raise(op[3] ? EXC_ADES : EXC_ADEL, mem_va, 1'b1);
                    end else if ((op == 6'h23 || op == 6'h2B) && |mem_va[1:0]) begin
                        d_req <= 1'b0; state <= S_EXEC;
                        raise(op[3] ? EXC_ADES : EXC_ADEL, mem_va, 1'b1);
                    end
                end

                6'h2F: cache_ops <= cache_ops + 1;   // CACHE: no cache modelled

                default: begin r_valid <= 1'b0; insn_count <= insn_count; cycle_count <= cycle_count;
                               raise(EXC_RI, 32'd0, 1'b0); end
                endcase
            end

            // ------------------------------------------------------ memory
            S_MEM: begin
                if (dbus_ack) begin
                    d_req <= 1'b0;
                    if (dbus_err) begin
                        raise(d_we ? EXC_DBE : EXC_ADEL, d_addr, 1'b1);
                    end else if (!mem_phase && (is_swl || is_swr)) begin
                        // Read-modify-write: the merged word goes back to
                        // the same aligned address.
                        store_data <= is_swl ? swl_result : swr_result;
                        store_be   <= 4'b1111;
                        d_we       <= 1'b1;
                        d_req      <= 1'b1;
                        mem_phase  <= 1'b1;
                    end else begin
                        if (!d_we) begin
                            case (op)
                            6'h20: wr(rt, {{24{load_result[7]}},  load_result[7:0]});
                            6'h24: wr(rt, {24'd0, load_result[7:0]});
                            6'h21: wr(rt, {{16{load_result[15]}}, load_result[15:0]});
                            6'h25: wr(rt, {16'd0, load_result[15:0]});
                            6'h22: wr(rt, lwl_result);
                            6'h26: wr(rt, lwr_result);
                            default: wr(rt, dbus_rdata);
                            endcase
                        end
                        mem_phase <= 1'b0;
                        retire_seq();
                    end
                end
            end

            // ------------------------------------------------ multiply/divide
            S_MULDIV: begin
                if (md_skip) begin
                    lo <= md_fix_lo;
                    hi <= md_fix_hi;
                    retire_seq();
                end else if (md_count == 6'd0) begin
                    // Truncating quotient, remainder taking the sign of the
                    // dividend -- C's semantics, which is what the reference
                    // uses and therefore what lockstep expects.
                    lo <= md_neg_q ? (~md_rq[31:0]  + 32'd1) : md_rq[31:0];
                    hi <= md_neg_r ? (~md_rq[63:32] + 32'd1) : md_rq[63:32];
                    retire_seq();
                end else begin
                    md_rq    <= md_diff[32] ? md_shifted
                                            : {md_diff[31:0], md_shifted[31:1], 1'b1};
                    md_count <= md_count - 6'd1;
                end
            end

            // --------------------------------------------------- exception
            S_TRAP: begin
                exc_count <= exc_count + 1;
                // EPC names the branch when the faulting instruction sat in
                // its delay slot, and Cause.BD says so.
                if (in_delay) begin
                    cp0[CP0_EPC]   <= cur_pc - 4;
                    cp0[CP0_CAUSE] <= (cause_live & ~32'h0000_007C & ~32'h8000_0000)
                                    | ({27'd0, trap_code} << 2) | 32'h8000_0000;
                end else begin
                    cp0[CP0_EPC]   <= cur_pc;
                    cp0[CP0_CAUSE] <= (cause_live & ~32'h0000_007C & ~32'h8000_0000)
                                    | ({27'd0, trap_code} << 2);
                end
                if (trap_have_bad) cp0[CP0_BADVADDR] <= trap_bad;
                // MIPS-I: shift the KU/IE stack left, entering kernel mode
                // with interrupts disabled.
                cp0[CP0_STATUS] <= (cp0[CP0_STATUS] & ~32'h3F)
                                 | ((cp0[CP0_STATUS] << 2) & 32'h3C);
                pc      <= cp0[CP0_STATUS][22] ? 32'hBFC0_0180 : 32'h8000_0080;
                next_pc <= (cp0[CP0_STATUS][22] ? 32'hBFC0_0180 : 32'h8000_0080) + 32'd4;
                branch_pending <= 1'b0;
                state   <= S_FETCH;
            end

            default: state <= S_FETCH;
            endcase
        end
    end

    // Byte-lane extraction for sub-word loads. Big-endian: byte 0 of the
    // word is the most significant one.
    always @(*) begin
        case (byte_sel)
        2'b00: load_result = {24'd0, dbus_rdata[31:24]};
        2'b01: load_result = {24'd0, dbus_rdata[23:16]};
        2'b10: load_result = {24'd0, dbus_rdata[15:8]};
        2'b11: load_result = {24'd0, dbus_rdata[7:0]};
        endcase
        if (op == 6'h21 || op == 6'h25)
            load_result = mem_va[1] ? {16'd0, dbus_rdata[15:0]}
                                    : {16'd0, dbus_rdata[31:16]};
    end

endmodule

`default_nettype wire
