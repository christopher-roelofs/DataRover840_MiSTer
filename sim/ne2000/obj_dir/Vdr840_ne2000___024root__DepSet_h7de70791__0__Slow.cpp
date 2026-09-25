// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdr840_ne2000.h for the primary calling header

#include "Vdr840_ne2000__pch.h"
#include "Vdr840_ne2000__Syms.h"
#include "Vdr840_ne2000___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_ne2000___024root___dump_triggers__stl(Vdr840_ne2000___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdr840_ne2000___024root___eval_triggers__stl(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdr840_ne2000___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
