// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdr840_pclink__pch.h"

//============================================================
// Constructors

Vdr840_pclink::Vdr840_pclink(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdr840_pclink__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , cen{vlSymsp->TOP.cen}
    , go_tog{vlSymsp->TOP.go_tog}
    , wr_req{vlSymsp->TOP.wr_req}
    , wr_ack{vlSymsp->TOP.wr_ack}
    , pmem_req{vlSymsp->TOP.pmem_req}
    , pmem_we{vlSymsp->TOP.pmem_we}
    , pmem_ack{vlSymsp->TOP.pmem_ack}
    , gtx_tog{vlSymsp->TOP.gtx_tog}
    , gtx_data{vlSymsp->TOP.gtx_data}
    , grx_tog{vlSymsp->TOP.grx_tog}
    , grx_data{vlSymsp->TOP.grx_data}
    , grx_full{vlSymsp->TOP.grx_full}
    , uart_on{vlSymsp->TOP.uart_on}
    , state{vlSymsp->TOP.state}
    , pkg_len{vlSymsp->TOP.pkg_len}
    , wr_addr{vlSymsp->TOP.wr_addr}
    , wr_data{vlSymsp->TOP.wr_data}
    , pmem_addr{vlSymsp->TOP.pmem_addr}
    , pmem_wdata{vlSymsp->TOP.pmem_wdata}
    , pmem_rdata{vlSymsp->TOP.pmem_rdata}
    , bit_clocks{vlSymsp->TOP.bit_clocks}
    , sent{vlSymsp->TOP.sent}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdr840_pclink::Vdr840_pclink(const char* _vcname__)
    : Vdr840_pclink(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdr840_pclink::~Vdr840_pclink() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdr840_pclink___024root___eval_debug_assertions(Vdr840_pclink___024root* vlSelf);
#endif  // VL_DEBUG
void Vdr840_pclink___024root___eval_static(Vdr840_pclink___024root* vlSelf);
void Vdr840_pclink___024root___eval_initial(Vdr840_pclink___024root* vlSelf);
void Vdr840_pclink___024root___eval_settle(Vdr840_pclink___024root* vlSelf);
void Vdr840_pclink___024root___eval(Vdr840_pclink___024root* vlSelf);

void Vdr840_pclink::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdr840_pclink::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdr840_pclink___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdr840_pclink___024root___eval_static(&(vlSymsp->TOP));
        Vdr840_pclink___024root___eval_initial(&(vlSymsp->TOP));
        Vdr840_pclink___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdr840_pclink___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdr840_pclink::eventsPending() { return false; }

uint64_t Vdr840_pclink::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdr840_pclink::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdr840_pclink___024root___eval_final(Vdr840_pclink___024root* vlSelf);

VL_ATTR_COLD void Vdr840_pclink::final() {
    Vdr840_pclink___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdr840_pclink::hierName() const { return vlSymsp->name(); }
const char* Vdr840_pclink::modelName() const { return "Vdr840_pclink"; }
unsigned Vdr840_pclink::threads() const { return 1; }
void Vdr840_pclink::prepareClone() const { contextp()->prepareClone(); }
void Vdr840_pclink::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vdr840_pclink::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vdr840_pclink::trace()' called on model that was Verilated without --trace option");
}
