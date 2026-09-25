// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdr840_ne2000__pch.h"

//============================================================
// Constructors

Vdr840_ne2000::Vdr840_ne2000(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdr840_ne2000__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , cen{vlSymsp->TOP.cen}
    , acc{vlSymsp->TOP.acc}
    , we{vlSymsp->TOP.we}
    , port{vlSymsp->TOP.port}
    , wide{vlSymsp->TOP.wide}
    , board_reset{vlSymsp->TOP.board_reset}
    , irq{vlSymsp->TOP.irq}
    , tx_req{vlSymsp->TOP.tx_req}
    , tx_done{vlSymsp->TOP.tx_done}
    , tx_ok{vlSymsp->TOP.tx_ok}
    , rx_offer{vlSymsp->TOP.rx_offer}
    , rx_answer{vlSymsp->TOP.rx_answer}
    , rx_take{vlSymsp->TOP.rx_take}
    , rx_byte{vlSymsp->TOP.rx_byte}
    , rx_data{vlSymsp->TOP.rx_data}
    , rx_busy{vlSymsp->TOP.rx_busy}
    , b_q{vlSymsp->TOP.b_q}
    , wdata{vlSymsp->TOP.wdata}
    , rdata{vlSymsp->TOP.rdata}
    , tx_base{vlSymsp->TOP.tx_base}
    , tx_len{vlSymsp->TOP.tx_len}
    , rx_len{vlSymsp->TOP.rx_len}
    , b_addr{vlSymsp->TOP.b_addr}
    , dbg_tx{vlSymsp->TOP.dbg_tx}
    , dbg_rx{vlSymsp->TOP.dbg_rx}
    , rx_dst{vlSymsp->TOP.rx_dst}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdr840_ne2000::Vdr840_ne2000(const char* _vcname__)
    : Vdr840_ne2000(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdr840_ne2000::~Vdr840_ne2000() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdr840_ne2000___024root___eval_debug_assertions(Vdr840_ne2000___024root* vlSelf);
#endif  // VL_DEBUG
void Vdr840_ne2000___024root___eval_static(Vdr840_ne2000___024root* vlSelf);
void Vdr840_ne2000___024root___eval_initial(Vdr840_ne2000___024root* vlSelf);
void Vdr840_ne2000___024root___eval_settle(Vdr840_ne2000___024root* vlSelf);
void Vdr840_ne2000___024root___eval(Vdr840_ne2000___024root* vlSelf);

void Vdr840_ne2000::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdr840_ne2000::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdr840_ne2000___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdr840_ne2000___024root___eval_static(&(vlSymsp->TOP));
        Vdr840_ne2000___024root___eval_initial(&(vlSymsp->TOP));
        Vdr840_ne2000___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdr840_ne2000___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdr840_ne2000::eventsPending() { return false; }

uint64_t Vdr840_ne2000::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdr840_ne2000::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdr840_ne2000___024root___eval_final(Vdr840_ne2000___024root* vlSelf);

VL_ATTR_COLD void Vdr840_ne2000::final() {
    Vdr840_ne2000___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdr840_ne2000::hierName() const { return vlSymsp->name(); }
const char* Vdr840_ne2000::modelName() const { return "Vdr840_ne2000"; }
unsigned Vdr840_ne2000::threads() const { return 1; }
void Vdr840_ne2000::prepareClone() const { contextp()->prepareClone(); }
void Vdr840_ne2000::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vdr840_ne2000::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vdr840_ne2000::trace()' called on model that was Verilated without --trace option");
}
