// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_board__pch.h"

//============================================================
// Constructors

Vtb_board::Vtb_board(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_board__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , ram_req{vlSymsp->TOP.ram_req}
    , ram_burst{vlSymsp->TOP.ram_burst}
    , ram_we{vlSymsp->TOP.ram_we}
    , ram_be{vlSymsp->TOP.ram_be}
    , ram_ack{vlSymsp->TOP.ram_ack}
    , io_req{vlSymsp->TOP.io_req}
    , io_we{vlSymsp->TOP.io_we}
    , io_be{vlSymsp->TOP.io_be}
    , io_ack{vlSymsp->TOP.io_ack}
    , io_err{vlSymsp->TOP.io_err}
    , irq_in{vlSymsp->TOP.irq_in}
    , retire_valid{vlSymsp->TOP.retire_valid}
    , ram_addr{vlSymsp->TOP.ram_addr}
    , ram_wdata{vlSymsp->TOP.ram_wdata}
    , ram_rdata{vlSymsp->TOP.ram_rdata}
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
    , tb_board{vlSymsp->TOP.tb_board}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_board::Vtb_board(const char* _vcname__)
    : Vtb_board(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_board::~Vtb_board() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_board___024root___eval_debug_assertions(Vtb_board___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_board___024root___eval_static(Vtb_board___024root* vlSelf);
void Vtb_board___024root___eval_initial(Vtb_board___024root* vlSelf);
void Vtb_board___024root___eval_settle(Vtb_board___024root* vlSelf);
void Vtb_board___024root___eval(Vtb_board___024root* vlSelf);

void Vtb_board::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_board::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_board___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_board___024root___eval_static(&(vlSymsp->TOP));
        Vtb_board___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_board___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_board___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_board::eventsPending() { return false; }

uint64_t Vtb_board::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtb_board::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_board___024root___eval_final(Vtb_board___024root* vlSelf);

VL_ATTR_COLD void Vtb_board::final() {
    Vtb_board___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_board::hierName() const { return vlSymsp->name(); }
const char* Vtb_board::modelName() const { return "Vtb_board"; }
unsigned Vtb_board::threads() const { return 1; }
void Vtb_board::prepareClone() const { contextp()->prepareClone(); }
void Vtb_board::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vtb_board::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_board::trace()' called on model that was Verilated without --trace option");
}
