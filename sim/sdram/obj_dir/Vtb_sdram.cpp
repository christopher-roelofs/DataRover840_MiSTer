// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_sdram__pch.h"

//============================================================
// Constructors

Vtb_sdram::Vtb_sdram(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_sdram__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , io_req{vlSymsp->TOP.io_req}
    , io_we{vlSymsp->TOP.io_we}
    , io_be{vlSymsp->TOP.io_be}
    , io_ack{vlSymsp->TOP.io_ack}
    , io_err{vlSymsp->TOP.io_err}
    , irq_in{vlSymsp->TOP.irq_in}
    , retire_valid{vlSymsp->TOP.retire_valid}
    , dbg_ram_ack{vlSymsp->TOP.dbg_ram_ack}
    , dbg_ram_req{vlSymsp->TOP.dbg_ram_req}
    , dbg_ram_burst{vlSymsp->TOP.dbg_ram_burst}
    , dbg_ch2_req{vlSymsp->TOP.dbg_ch2_req}
    , dbg_dack{vlSymsp->TOP.dbg_dack}
    , dbg_iack{vlSymsp->TOP.dbg_iack}
    , dbg_dreq{vlSymsp->TOP.dbg_dreq}
    , dbg_ireq{vlSymsp->TOP.dbg_ireq}
    , dbg_max_refresh_gap{vlSymsp->TOP.dbg_max_refresh_gap}
    , dbg_violations{vlSymsp->TOP.dbg_violations}
    , dbg_last_col{vlSymsp->TOP.dbg_last_col}
    , dbg_last_row{vlSymsp->TOP.dbg_last_row}
    , dbg_last_a{vlSymsp->TOP.dbg_last_a}
    , io_addr{vlSymsp->TOP.io_addr}
    , io_wdata{vlSymsp->TOP.io_wdata}
    , io_rdata{vlSymsp->TOP.io_rdata}
    , retire_pc{vlSymsp->TOP.retire_pc}
    , retire_insn{vlSymsp->TOP.retire_insn}
    , retire_next_pc{vlSymsp->TOP.retire_next_pc}
    , ihit_count{vlSymsp->TOP.ihit_count}
    , imiss_count{vlSymsp->TOP.imiss_count}
    , dhit_count{vlSymsp->TOP.dhit_count}
    , dmiss_count{vlSymsp->TOP.dmiss_count}
    , dbg_reads{vlSymsp->TOP.dbg_reads}
    , dbg_writes{vlSymsp->TOP.dbg_writes}
    , dbg_refreshes{vlSymsp->TOP.dbg_refreshes}
    , dbg_ram_addr{vlSymsp->TOP.dbg_ram_addr}
    , dbg_ram_rdata{vlSymsp->TOP.dbg_ram_rdata}
    , dbg_last_index{vlSymsp->TOP.dbg_last_index}
    , dbg_ch2_addr{vlSymsp->TOP.dbg_ch2_addr}
    , tb_sdram{vlSymsp->TOP.tb_sdram}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_sdram::Vtb_sdram(const char* _vcname__)
    : Vtb_sdram(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_sdram::~Vtb_sdram() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_sdram___024root___eval_debug_assertions(Vtb_sdram___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_sdram___024root___eval_static(Vtb_sdram___024root* vlSelf);
void Vtb_sdram___024root___eval_initial(Vtb_sdram___024root* vlSelf);
void Vtb_sdram___024root___eval_settle(Vtb_sdram___024root* vlSelf);
void Vtb_sdram___024root___eval(Vtb_sdram___024root* vlSelf);

void Vtb_sdram::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_sdram::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_sdram___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_sdram___024root___eval_static(&(vlSymsp->TOP));
        Vtb_sdram___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_sdram___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_sdram___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_sdram::eventsPending() { return false; }

uint64_t Vtb_sdram::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtb_sdram::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_sdram___024root___eval_final(Vtb_sdram___024root* vlSelf);

VL_ATTR_COLD void Vtb_sdram::final() {
    Vtb_sdram___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_sdram::hierName() const { return vlSymsp->name(); }
const char* Vtb_sdram::modelName() const { return "Vtb_sdram"; }
unsigned Vtb_sdram::threads() const { return 1; }
void Vtb_sdram::prepareClone() const { contextp()->prepareClone(); }
void Vtb_sdram::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vtb_sdram::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_sdram::trace()' called on model that was Verilated without --trace option");
}
