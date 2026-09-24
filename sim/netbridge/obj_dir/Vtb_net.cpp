// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_net__pch.h"

//============================================================
// Constructors

Vtb_net::Vtb_net(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_net__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , enable{vlSymsp->TOP.enable}
    , acc{vlSymsp->TOP.acc}
    , we{vlSymsp->TOP.we}
    , wide{vlSymsp->TOP.wide}
    , port{vlSymsp->TOP.port}
    , irq{vlSymsp->TOP.irq}
    , ddr_busy{vlSymsp->TOP.ddr_busy}
    , ddr_rd{vlSymsp->TOP.ddr_rd}
    , ddr_we{vlSymsp->TOP.ddr_we}
    , ddr_dout_ready{vlSymsp->TOP.ddr_dout_ready}
    , link{vlSymsp->TOP.link}
    , cen_o{vlSymsp->TOP.cen_o}
    , wdata{vlSymsp->TOP.wdata}
    , rdata{vlSymsp->TOP.rdata}
    , ddr_addr{vlSymsp->TOP.ddr_addr}
    , frames_tx{vlSymsp->TOP.frames_tx}
    , frames_rx{vlSymsp->TOP.frames_rx}
    , ddr_din{vlSymsp->TOP.ddr_din}
    , ddr_dout{vlSymsp->TOP.ddr_dout}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_net::Vtb_net(const char* _vcname__)
    : Vtb_net(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_net::~Vtb_net() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_net___024root___eval_debug_assertions(Vtb_net___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_net___024root___eval_static(Vtb_net___024root* vlSelf);
void Vtb_net___024root___eval_initial(Vtb_net___024root* vlSelf);
void Vtb_net___024root___eval_settle(Vtb_net___024root* vlSelf);
void Vtb_net___024root___eval(Vtb_net___024root* vlSelf);

void Vtb_net::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_net::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_net___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_net___024root___eval_static(&(vlSymsp->TOP));
        Vtb_net___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_net___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_net___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_net::eventsPending() { return false; }

uint64_t Vtb_net::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtb_net::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_net___024root___eval_final(Vtb_net___024root* vlSelf);

VL_ATTR_COLD void Vtb_net::final() {
    Vtb_net___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_net::hierName() const { return vlSymsp->name(); }
const char* Vtb_net::modelName() const { return "Vtb_net"; }
unsigned Vtb_net::threads() const { return 1; }
void Vtb_net::prepareClone() const { contextp()->prepareClone(); }
void Vtb_net::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vtb_net::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_net::trace()' called on model that was Verilated without --trace option");
}
