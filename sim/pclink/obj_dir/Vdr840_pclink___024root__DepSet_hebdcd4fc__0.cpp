// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdr840_pclink.h for the primary calling header

#include "Vdr840_pclink__pch.h"
#include "Vdr840_pclink__Syms.h"
#include "Vdr840_pclink___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_pclink___024root___dump_triggers__ico(Vdr840_pclink___024root* vlSelf);
#endif  // VL_DEBUG

void Vdr840_pclink___024root___eval_triggers__ico(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdr840_pclink___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_pclink___024root___dump_triggers__act(Vdr840_pclink___024root* vlSelf);
#endif  // VL_DEBUG

void Vdr840_pclink___024root___eval_triggers__act(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__VactTriggered.set(1U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((~ (IData)(vlSelf->rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__rst_n__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdr840_pclink___024root___dump_triggers__act(vlSelf);
    }
#endif
}
