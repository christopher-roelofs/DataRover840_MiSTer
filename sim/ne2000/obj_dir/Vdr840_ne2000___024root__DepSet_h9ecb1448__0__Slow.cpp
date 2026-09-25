// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdr840_ne2000.h for the primary calling header

#include "Vdr840_ne2000__pch.h"
#include "Vdr840_ne2000___024root.h"

VL_ATTR_COLD void Vdr840_ne2000___024root___eval_static(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vdr840_ne2000___024root___eval_initial(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
}

VL_ATTR_COLD void Vdr840_ne2000___024root___eval_final(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_ne2000___024root___dump_triggers__stl(Vdr840_ne2000___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vdr840_ne2000___024root___eval_phase__stl(Vdr840_ne2000___024root* vlSelf);

VL_ATTR_COLD void Vdr840_ne2000___024root___eval_settle(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vdr840_ne2000___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../../rtl/soc/dr840_ne2000.sv", 22, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vdr840_ne2000___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_ne2000___024root___dump_triggers__stl(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdr840_ne2000___024root___stl_sequent__TOP__0(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___stl_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ dr840_ne2000__DOT__mhash__Vstatic__c;
    dr840_ne2000__DOT__mhash__Vstatic__c = 0;
    CData/*7:0*/ dr840_ne2000__DOT__mhash__Vstatic__by;
    dr840_ne2000__DOT__mhash__Vstatic__by = 0;
    CData/*5:0*/ dr840_ne2000__DOT__o_hash;
    dr840_ne2000__DOT__o_hash = 0;
    SData/*8:0*/ dr840_ne2000__DOT__o_next0;
    dr840_ne2000__DOT__o_next0 = 0;
    CData/*7:0*/ __Vfunc_dr840_ne2000__DOT__space__0__Vfuncout;
    __Vfunc_dr840_ne2000__DOT__space__0__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_dr840_ne2000__DOT__space__0__a;
    __Vfunc_dr840_ne2000__DOT__space__0__a = 0;
    CData/*7:0*/ __Vfunc_dr840_ne2000__DOT__space__0__ram_byte;
    __Vfunc_dr840_ne2000__DOT__space__0__ram_byte = 0;
    CData/*7:0*/ __Vfunc_dr840_ne2000__DOT__space__2__Vfuncout;
    __Vfunc_dr840_ne2000__DOT__space__2__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_dr840_ne2000__DOT__space__2__a;
    __Vfunc_dr840_ne2000__DOT__space__2__a = 0;
    CData/*7:0*/ __Vfunc_dr840_ne2000__DOT__space__2__ram_byte;
    __Vfunc_dr840_ne2000__DOT__space__2__ram_byte = 0;
    CData/*5:0*/ __Vfunc_dr840_ne2000__DOT__mhash__4__Vfuncout;
    __Vfunc_dr840_ne2000__DOT__mhash__4__Vfuncout = 0;
    QData/*47:0*/ __Vfunc_dr840_ne2000__DOT__mhash__4__d;
    __Vfunc_dr840_ne2000__DOT__mhash__4__d = 0;
    // Body
    vlSelf->irq = (0U != (0x7fU & ((IData)(vlSelf->dr840_ne2000__DOT__imr) 
                                   & (IData)(vlSelf->dr840_ne2000__DOT__isr))));
    vlSelf->rx_busy = ((0U != (IData)(vlSelf->dr840_ne2000__DOT__r_st)) 
                       | (IData)(vlSelf->dr840_ne2000__DOT__off_q));
    vlSelf->dr840_ne2000__DOT__dma_wr_ok = (IData)(
                                                   ((0x10U 
                                                     == 
                                                     (0x38U 
                                                      & (IData)(vlSelf->dr840_ne2000__DOT__cr))) 
                                                    & (0U 
                                                       != (IData)(vlSelf->dr840_ne2000__DOT__rbcr))));
    vlSelf->dr840_ne2000__DOT__pb_a = ((IData)(vlSelf->dr840_ne2000__DOT__wb)
                                        ? (IData)(vlSelf->dr840_ne2000__DOT__wb_a)
                                        : (IData)(vlSelf->b_addr));
    vlSelf->b_q = ((IData)(vlSelf->dr840_ne2000__DOT__b_lsb)
                    ? (IData)(vlSelf->dr840_ne2000__DOT__qb_o)
                    : (IData)(vlSelf->dr840_ne2000__DOT__qb_e));
    vlSelf->dr840_ne2000__DOT__o_ring_ok = (1U & (~ 
                                                  ((0x40U 
                                                    > (IData)(vlSelf->dr840_ne2000__DOT__pstart)) 
                                                   | ((0x80U 
                                                       < (IData)(vlSelf->dr840_ne2000__DOT__pstop)) 
                                                      | (((IData)(vlSelf->dr840_ne2000__DOT__pstart) 
                                                          >= (IData)(vlSelf->dr840_ne2000__DOT__pstop)) 
                                                         | (((IData)(vlSelf->dr840_ne2000__DOT__curr) 
                                                             < (IData)(vlSelf->dr840_ne2000__DOT__pstart)) 
                                                            | ((IData)(vlSelf->dr840_ne2000__DOT__curr) 
                                                               >= (IData)(vlSelf->dr840_ne2000__DOT__pstop))))))));
    vlSelf->dr840_ne2000__DOT__o_bnry_in = (((IData)(vlSelf->dr840_ne2000__DOT__bnry) 
                                             >= (IData)(vlSelf->dr840_ne2000__DOT__pstart)) 
                                            & ((IData)(vlSelf->dr840_ne2000__DOT__bnry) 
                                               < (IData)(vlSelf->dr840_ne2000__DOT__pstop)));
    vlSelf->dr840_ne2000__DOT__r_ptr_n = (0xffffU & 
                                          (((0xffffU 
                                             & ((IData)(1U) 
                                                + (IData)(vlSelf->dr840_ne2000__DOT__r_ptr))) 
                                            == ((IData)(vlSelf->dr840_ne2000__DOT__pstop) 
                                                << 8U))
                                            ? ((IData)(vlSelf->dr840_ne2000__DOT__pstart) 
                                               << 8U)
                                            : ((IData)(1U) 
                                               + (IData)(vlSelf->dr840_ne2000__DOT__r_ptr))));
    vlSelf->dr840_ne2000__DOT__o_avail = (0x1ffU & 
                                          (((IData)(vlSelf->dr840_ne2000__DOT__bnry) 
                                            > (IData)(vlSelf->dr840_ne2000__DOT__curr))
                                            ? (0xffU 
                                               & ((IData)(vlSelf->dr840_ne2000__DOT__bnry) 
                                                  - (IData)(vlSelf->dr840_ne2000__DOT__curr)))
                                            : ((0xffU 
                                                & ((IData)(vlSelf->dr840_ne2000__DOT__pstop) 
                                                   - (IData)(vlSelf->dr840_ne2000__DOT__curr))) 
                                               + (0xffU 
                                                  & ((IData)(vlSelf->dr840_ne2000__DOT__bnry) 
                                                     - (IData)(vlSelf->dr840_ne2000__DOT__pstart))))));
    vlSelf->dr840_ne2000__DOT__o_pad = ((0x3cU > (IData)(vlSelf->dr840_ne2000__DOT__off_len))
                                         ? 0x3cU : (IData)(vlSelf->dr840_ne2000__DOT__off_len));
    __Vfunc_dr840_ne2000__DOT__mhash__4__d = vlSelf->dr840_ne2000__DOT__off_dst;
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x28U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (IData)(dr840_ne2000__DOT__mhash__Vstatic__by))
                                             ? 0xfffffffeU
                                             : 0xfb3ee249U);
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x28U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 1U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x28U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 2U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x28U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 3U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x28U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 4U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x28U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 5U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x28U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 6U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x28U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = (((dr840_ne2000__DOT__mhash__Vstatic__c 
                                              >> 0x1fU) 
                                             ^ ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                >> 7U))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x20U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ (IData)(dr840_ne2000__DOT__mhash__Vstatic__by)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x20U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 1U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x20U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 2U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x20U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 3U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x20U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 4U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x20U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 5U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x20U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 6U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x20U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = (((dr840_ne2000__DOT__mhash__Vstatic__c 
                                              >> 0x1fU) 
                                             ^ ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                >> 7U))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x18U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ (IData)(dr840_ne2000__DOT__mhash__Vstatic__by)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x18U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 1U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x18U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 2U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x18U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 3U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x18U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 4U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x18U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 5U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x18U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 6U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x18U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = (((dr840_ne2000__DOT__mhash__Vstatic__c 
                                              >> 0x1fU) 
                                             ^ ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                >> 7U))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x10U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ (IData)(dr840_ne2000__DOT__mhash__Vstatic__by)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x10U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 1U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x10U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 2U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x10U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 3U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x10U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 4U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x10U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 5U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x10U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 6U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 0x10U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = (((dr840_ne2000__DOT__mhash__Vstatic__c 
                                              >> 0x1fU) 
                                             ^ ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                >> 7U))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 8U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ (IData)(dr840_ne2000__DOT__mhash__Vstatic__by)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 8U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 1U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 8U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 2U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 8U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 3U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 8U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 4U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 8U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 5U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 8U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 6U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(
                                                       (__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                                        >> 8U)));
    dr840_ne2000__DOT__mhash__Vstatic__c = (((dr840_ne2000__DOT__mhash__Vstatic__c 
                                              >> 0x1fU) 
                                             ^ ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                >> 7U))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ (IData)(dr840_ne2000__DOT__mhash__Vstatic__by)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 1U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 2U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 3U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 4U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 5U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
    dr840_ne2000__DOT__mhash__Vstatic__c = ((1U & (
                                                   (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                    >> 0x1fU) 
                                                   ^ 
                                                   ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                    >> 6U)))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    dr840_ne2000__DOT__mhash__Vstatic__by = (0xffU 
                                             & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
    dr840_ne2000__DOT__mhash__Vstatic__c = (((dr840_ne2000__DOT__mhash__Vstatic__c 
                                              >> 0x1fU) 
                                             ^ ((IData)(dr840_ne2000__DOT__mhash__Vstatic__by) 
                                                >> 7U))
                                             ? (0x4c11db7U 
                                                ^ (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                   << 1U))
                                             : (dr840_ne2000__DOT__mhash__Vstatic__c 
                                                << 1U));
    __Vfunc_dr840_ne2000__DOT__mhash__4__Vfuncout = 
        (dr840_ne2000__DOT__mhash__Vstatic__c >> 0x1aU);
    dr840_ne2000__DOT__o_hash = __Vfunc_dr840_ne2000__DOT__mhash__4__Vfuncout;
    vlSelf->dr840_ne2000__DOT__dma_rd_ok = (IData)(
                                                   ((8U 
                                                     == 
                                                     (0x38U 
                                                      & (IData)(vlSelf->dr840_ne2000__DOT__cr))) 
                                                    & (0U 
                                                       != (IData)(vlSelf->dr840_ne2000__DOT__rbcr))));
    __Vfunc_dr840_ne2000__DOT__space__0__a = vlSelf->dr840_ne2000__DOT__rsar;
    __Vfunc_dr840_ne2000__DOT__space__0__ram_byte = 
        ((1U & (IData)(vlSelf->dr840_ne2000__DOT__rsar))
          ? (IData)(vlSelf->dr840_ne2000__DOT__qa_o)
          : (IData)(vlSelf->dr840_ne2000__DOT__qa_e));
    __Vfunc_dr840_ne2000__DOT__space__0__Vfuncout = 
        ((0x20U > (IData)(__Vfunc_dr840_ne2000__DOT__space__0__a))
          ? ([&]() {
                vlSelf->__Vfunc_dr840_ne2000__DOT__prom__1__a 
                    = (0x1fU & (IData)(__Vfunc_dr840_ne2000__DOT__space__0__a));
                vlSelf->__Vfunc_dr840_ne2000__DOT__prom__1__Vfuncout 
                    = ((0x10U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__1__a))
                        ? ((8U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__1__a))
                            ? ((4U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__1__a))
                                ? 0x57U : 0U) : 0U)
                        : ((8U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__1__a))
                            ? ((4U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__1__a))
                                ? 0U : ((2U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__1__a))
                                         ? 1U : 0U))
                            : ((4U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__1__a))
                                ? ((2U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__1__a))
                                    ? 0x84U : 0U) : 
                               ((2U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__1__a))
                                 ? 0U : 2U))));
            }(), (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__1__Vfuncout))
          : (((0x4000U <= (IData)(__Vfunc_dr840_ne2000__DOT__space__0__a)) 
              & (0x8000U > (IData)(__Vfunc_dr840_ne2000__DOT__space__0__a)))
              ? (IData)(__Vfunc_dr840_ne2000__DOT__space__0__ram_byte)
              : 0xffU));
    __Vfunc_dr840_ne2000__DOT__space__2__ram_byte = 
        ((1U & (IData)(vlSelf->dr840_ne2000__DOT__rsar))
          ? (IData)(vlSelf->dr840_ne2000__DOT__qa_e)
          : (IData)(vlSelf->dr840_ne2000__DOT__qa_o));
    vlSelf->dr840_ne2000__DOT__b0 = __Vfunc_dr840_ne2000__DOT__space__0__Vfuncout;
    vlSelf->dr840_ne2000__DOT__rsar_n = (0xffffU & 
                                         ((((IData)(vlSelf->dr840_ne2000__DOT__pstop) 
                                            > (IData)(vlSelf->dr840_ne2000__DOT__pstart)) 
                                           & ((0xffffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->dr840_ne2000__DOT__rsar))) 
                                              == ((IData)(vlSelf->dr840_ne2000__DOT__pstop) 
                                                  << 8U)))
                                           ? ((IData)(vlSelf->dr840_ne2000__DOT__pstart) 
                                              << 8U)
                                           : ((IData)(1U) 
                                              + (IData)(vlSelf->dr840_ne2000__DOT__rsar))));
    dr840_ne2000__DOT__o_next0 = (0x1ffU & ((IData)(vlSelf->dr840_ne2000__DOT__curr) 
                                            + (0xffU 
                                               & VL_SHIFTR_III(12,12,32, 
                                                               (0xfffU 
                                                                & ((IData)(0x107U) 
                                                                   + (IData)(vlSelf->dr840_ne2000__DOT__o_pad))), 8U))));
    vlSelf->dr840_ne2000__DOT__o_acc = (1U & ((0xffffffffffffULL 
                                               == vlSelf->dr840_ne2000__DOT__off_dst)
                                               ? ((IData)(vlSelf->dr840_ne2000__DOT__rcr) 
                                                  >> 2U)
                                               : ((1U 
                                                   & (IData)(
                                                             (vlSelf->dr840_ne2000__DOT__off_dst 
                                                              >> 0x28U)))
                                                   ? 
                                                  (((IData)(vlSelf->dr840_ne2000__DOT__rcr) 
                                                    >> 3U) 
                                                   & (vlSelf->dr840_ne2000__DOT__mar
                                                      [
                                                      (7U 
                                                       & ((IData)(dr840_ne2000__DOT__o_hash) 
                                                          >> 3U))] 
                                                      >> 
                                                      (7U 
                                                       & (IData)(dr840_ne2000__DOT__o_hash))))
                                                   : 
                                                  (((IData)(vlSelf->dr840_ne2000__DOT__rcr) 
                                                    >> 4U) 
                                                   | (vlSelf->dr840_ne2000__DOT__off_dst 
                                                      == 
                                                      (((QData)((IData)(
                                                                        vlSelf->dr840_ne2000__DOT__par
                                                                        [0U])) 
                                                        << 0x28U) 
                                                       | (((QData)((IData)(
                                                                           vlSelf->dr840_ne2000__DOT__par
                                                                           [1U])) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(
                                                                            ((vlSelf->dr840_ne2000__DOT__par
                                                                              [2U] 
                                                                              << 0x18U) 
                                                                             | ((vlSelf->dr840_ne2000__DOT__par
                                                                                [3U] 
                                                                                << 0x10U) 
                                                                                | ((vlSelf->dr840_ne2000__DOT__par
                                                                                [4U] 
                                                                                << 8U) 
                                                                                | vlSelf->dr840_ne2000__DOT__par
                                                                                [5U]))))))))))));
    vlSelf->dr840_ne2000__DOT__pa_e = (0x1fffU & ((IData)(vlSelf->dr840_ne2000__DOT__wa_e)
                                                   ? (IData)(vlSelf->dr840_ne2000__DOT__wa_e_i)
                                                   : 
                                                  (((1U 
                                                     & (IData)(vlSelf->dr840_ne2000__DOT__rsar))
                                                     ? (IData)(vlSelf->dr840_ne2000__DOT__rsar_n)
                                                     : (IData)(vlSelf->dr840_ne2000__DOT__rsar)) 
                                                   >> 1U)));
    vlSelf->dr840_ne2000__DOT__pa_o = (0x1fffU & ((IData)(vlSelf->dr840_ne2000__DOT__wa_o)
                                                   ? (IData)(vlSelf->dr840_ne2000__DOT__wa_o_i)
                                                   : 
                                                  (((1U 
                                                     & (IData)(vlSelf->dr840_ne2000__DOT__rsar))
                                                     ? (IData)(vlSelf->dr840_ne2000__DOT__rsar)
                                                     : (IData)(vlSelf->dr840_ne2000__DOT__rsar_n)) 
                                                   >> 1U)));
    __Vfunc_dr840_ne2000__DOT__space__2__a = vlSelf->dr840_ne2000__DOT__rsar_n;
    __Vfunc_dr840_ne2000__DOT__space__2__Vfuncout = 
        ((0x20U > (IData)(__Vfunc_dr840_ne2000__DOT__space__2__a))
          ? ([&]() {
                vlSelf->__Vfunc_dr840_ne2000__DOT__prom__3__a 
                    = (0x1fU & (IData)(__Vfunc_dr840_ne2000__DOT__space__2__a));
                vlSelf->__Vfunc_dr840_ne2000__DOT__prom__3__Vfuncout 
                    = ((0x10U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__3__a))
                        ? ((8U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__3__a))
                            ? ((4U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__3__a))
                                ? 0x57U : 0U) : 0U)
                        : ((8U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__3__a))
                            ? ((4U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__3__a))
                                ? 0U : ((2U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__3__a))
                                         ? 1U : 0U))
                            : ((4U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__3__a))
                                ? ((2U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__3__a))
                                    ? 0x84U : 0U) : 
                               ((2U & (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__3__a))
                                 ? 0U : 2U))));
            }(), (IData)(vlSelf->__Vfunc_dr840_ne2000__DOT__prom__3__Vfuncout))
          : (((0x4000U <= (IData)(__Vfunc_dr840_ne2000__DOT__space__2__a)) 
              & (0x8000U > (IData)(__Vfunc_dr840_ne2000__DOT__space__2__a)))
              ? (IData)(__Vfunc_dr840_ne2000__DOT__space__2__ram_byte)
              : 0xffU));
    vlSelf->dr840_ne2000__DOT__b1 = __Vfunc_dr840_ne2000__DOT__space__2__Vfuncout;
    vlSelf->dr840_ne2000__DOT__o_next = (0xffU & (((IData)(dr840_ne2000__DOT__o_next0) 
                                                   >= (IData)(vlSelf->dr840_ne2000__DOT__pstop))
                                                   ? 
                                                  ((IData)(dr840_ne2000__DOT__o_next0) 
                                                   - 
                                                   ((IData)(vlSelf->dr840_ne2000__DOT__pstop) 
                                                    - (IData)(vlSelf->dr840_ne2000__DOT__pstart)))
                                                   : (IData)(dr840_ne2000__DOT__o_next0)));
    vlSelf->rdata = 0xffU;
    vlSelf->rdata = ((0x10U == (IData)(vlSelf->port))
                      ? ((IData)(vlSelf->wide) ? ((
                                                   ((IData)(vlSelf->dr840_ne2000__DOT__dma_rd_ok)
                                                     ? (IData)(vlSelf->dr840_ne2000__DOT__b0)
                                                     : 0xffU) 
                                                   << 8U) 
                                                  | (((IData)(vlSelf->dr840_ne2000__DOT__dma_rd_ok) 
                                                      & (1U 
                                                         != (IData)(vlSelf->dr840_ne2000__DOT__rbcr)))
                                                      ? (IData)(vlSelf->dr840_ne2000__DOT__b1)
                                                      : 0xffU))
                          : ((IData)(vlSelf->dr840_ne2000__DOT__dma_rd_ok)
                              ? (IData)(vlSelf->dr840_ne2000__DOT__b0)
                              : 0xffU)) : ((IData)(vlSelf->wide)
                                            ? 0xffffU
                                            : ((0x1fU 
                                                == (IData)(vlSelf->port))
                                                ? 0U
                                                : (
                                                   (0U 
                                                    == (IData)(vlSelf->port))
                                                    ? (IData)(vlSelf->dr840_ne2000__DOT__cr)
                                                    : 
                                                   ((0x10U 
                                                     & (IData)(vlSelf->port))
                                                     ? 0xffU
                                                     : 
                                                    ((0U 
                                                      == 
                                                      (3U 
                                                       & ((IData)(vlSelf->dr840_ne2000__DOT__cr) 
                                                          >> 6U)))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelf->port))
                                                       ? 
                                                      ((4U 
                                                        & (IData)(vlSelf->port))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelf->port))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->port))
                                                          ? 
                                                         vlSelf->dr840_ne2000__DOT__tally
                                                         [2U]
                                                          : 
                                                         vlSelf->dr840_ne2000__DOT__tally
                                                         [1U])
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->port))
                                                          ? 
                                                         vlSelf->dr840_ne2000__DOT__tally
                                                         [0U]
                                                          : (IData)(vlSelf->dr840_ne2000__DOT__rsr)))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->port))
                                                         ? 0xffU
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->port))
                                                          ? 
                                                         (0xffU 
                                                          & ((IData)(vlSelf->dr840_ne2000__DOT__rsar) 
                                                             >> 8U))
                                                          : 
                                                         (0xffU 
                                                          & (IData)(vlSelf->dr840_ne2000__DOT__rsar)))))
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->port))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelf->port))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->port))
                                                          ? (IData)(vlSelf->dr840_ne2000__DOT__isr)
                                                          : 0U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->port))
                                                          ? 0U
                                                          : (IData)(vlSelf->dr840_ne2000__DOT__tsr)))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->port))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->port))
                                                          ? (IData)(vlSelf->dr840_ne2000__DOT__bnry)
                                                          : 0xffU)
                                                         : 0xffU)))
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (3U 
                                                        & ((IData)(vlSelf->dr840_ne2000__DOT__cr) 
                                                           >> 6U)))
                                                       ? 
                                                      ((6U 
                                                        >= 
                                                        (0xfU 
                                                         & (IData)(vlSelf->port)))
                                                        ? 
                                                       ((5U 
                                                         >= 
                                                         (7U 
                                                          & ((IData)(vlSelf->port) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        vlSelf->dr840_ne2000__DOT__par
                                                        [
                                                        (7U 
                                                         & ((IData)(vlSelf->port) 
                                                            - (IData)(1U)))]
                                                         : 0U)
                                                        : 
                                                       ((7U 
                                                         == 
                                                         (0xfU 
                                                          & (IData)(vlSelf->port)))
                                                         ? (IData)(vlSelf->dr840_ne2000__DOT__curr)
                                                         : 
                                                        vlSelf->dr840_ne2000__DOT__mar
                                                        [
                                                        (7U 
                                                         & (IData)(vlSelf->port))]))
                                                       : 
                                                      ((2U 
                                                        == 
                                                        (3U 
                                                         & ((IData)(vlSelf->dr840_ne2000__DOT__cr) 
                                                            >> 6U)))
                                                        ? 
                                                       ((8U 
                                                         & (IData)(vlSelf->port))
                                                         ? 
                                                        ((4U 
                                                          & (IData)(vlSelf->port))
                                                          ? 
                                                         ((2U 
                                                           & (IData)(vlSelf->port))
                                                           ? 
                                                          ((1U 
                                                            & (IData)(vlSelf->port))
                                                            ? (IData)(vlSelf->dr840_ne2000__DOT__imr)
                                                            : (IData)(vlSelf->dr840_ne2000__DOT__dcr))
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelf->port))
                                                            ? (IData)(vlSelf->dr840_ne2000__DOT__tcr)
                                                            : (IData)(vlSelf->dr840_ne2000__DOT__rcr)))
                                                          : 0xffU)
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelf->port))
                                                          ? 
                                                         ((2U 
                                                           & (IData)(vlSelf->port))
                                                           ? 0xffU
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelf->port))
                                                            ? 0xffU
                                                            : (IData)(vlSelf->dr840_ne2000__DOT__tpsr)))
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelf->port))
                                                           ? 
                                                          ((1U 
                                                            & (IData)(vlSelf->port))
                                                            ? 0xffU
                                                            : (IData)(vlSelf->dr840_ne2000__DOT__pstop))
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelf->port))
                                                            ? (IData)(vlSelf->dr840_ne2000__DOT__pstart)
                                                            : 0xffU))))
                                                        : 0xffU))))))));
}

VL_ATTR_COLD void Vdr840_ne2000___024root___eval_stl(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vdr840_ne2000___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vdr840_ne2000___024root___eval_triggers__stl(Vdr840_ne2000___024root* vlSelf);

VL_ATTR_COLD bool Vdr840_ne2000___024root___eval_phase__stl(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vdr840_ne2000___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vdr840_ne2000___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_ne2000___024root___dump_triggers__ico(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_ne2000___024root___dump_triggers__act(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_ne2000___024root___dump_triggers__nba(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdr840_ne2000___024root___ctor_var_reset(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->cen = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->acc = VL_RAND_RESET_I(1);
    vlSelf->we = VL_RAND_RESET_I(1);
    vlSelf->port = VL_RAND_RESET_I(5);
    vlSelf->wide = VL_RAND_RESET_I(1);
    vlSelf->wdata = VL_RAND_RESET_I(16);
    vlSelf->rdata = VL_RAND_RESET_I(16);
    vlSelf->board_reset = VL_RAND_RESET_I(1);
    vlSelf->irq = VL_RAND_RESET_I(1);
    vlSelf->tx_req = VL_RAND_RESET_I(1);
    vlSelf->tx_base = VL_RAND_RESET_I(14);
    vlSelf->tx_len = VL_RAND_RESET_I(11);
    vlSelf->tx_done = VL_RAND_RESET_I(1);
    vlSelf->tx_ok = VL_RAND_RESET_I(1);
    vlSelf->rx_offer = VL_RAND_RESET_I(1);
    vlSelf->rx_len = VL_RAND_RESET_I(11);
    vlSelf->rx_dst = VL_RAND_RESET_Q(48);
    vlSelf->rx_answer = VL_RAND_RESET_I(1);
    vlSelf->rx_take = VL_RAND_RESET_I(1);
    vlSelf->rx_byte = VL_RAND_RESET_I(1);
    vlSelf->rx_data = VL_RAND_RESET_I(8);
    vlSelf->rx_busy = VL_RAND_RESET_I(1);
    vlSelf->b_addr = VL_RAND_RESET_I(14);
    vlSelf->b_q = VL_RAND_RESET_I(8);
    vlSelf->dbg_tx = VL_RAND_RESET_I(32);
    vlSelf->dbg_rx = VL_RAND_RESET_I(32);
    vlSelf->dr840_ne2000__DOT__cr = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__isr = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__imr = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__dcr = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__rcr = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__tcr = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__tsr = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__rsr = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__pstart = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__pstop = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__bnry = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__curr = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__tpsr = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->dr840_ne2000__DOT__par[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->dr840_ne2000__DOT__mar[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->dr840_ne2000__DOT__rsar = VL_RAND_RESET_I(16);
    vlSelf->dr840_ne2000__DOT__rbcr = VL_RAND_RESET_I(16);
    vlSelf->dr840_ne2000__DOT__tbcr = VL_RAND_RESET_I(16);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->dr840_ne2000__DOT__tally[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->dr840_ne2000__DOT__tx_pending = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->dr840_ne2000__DOT__ram_e[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->dr840_ne2000__DOT__ram_o[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->dr840_ne2000__DOT__rsar_n = VL_RAND_RESET_I(16);
    vlSelf->dr840_ne2000__DOT__qa_e = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__qa_o = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__wa_e = VL_RAND_RESET_I(1);
    vlSelf->dr840_ne2000__DOT__wa_o = VL_RAND_RESET_I(1);
    vlSelf->dr840_ne2000__DOT__wa_e_i = VL_RAND_RESET_I(13);
    vlSelf->dr840_ne2000__DOT__wa_o_i = VL_RAND_RESET_I(13);
    vlSelf->dr840_ne2000__DOT__wa_e_d = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__wa_o_d = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__wb = VL_RAND_RESET_I(1);
    vlSelf->dr840_ne2000__DOT__wb_a = VL_RAND_RESET_I(14);
    vlSelf->dr840_ne2000__DOT__wb_d = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__qb_e = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__qb_o = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__b_lsb = VL_RAND_RESET_I(1);
    vlSelf->dr840_ne2000__DOT__pb_a = VL_RAND_RESET_I(14);
    vlSelf->dr840_ne2000__DOT__pa_e = VL_RAND_RESET_I(13);
    vlSelf->dr840_ne2000__DOT__pa_o = VL_RAND_RESET_I(13);
    vlSelf->dr840_ne2000__DOT__b0 = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__b1 = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__dma_rd_ok = VL_RAND_RESET_I(1);
    vlSelf->dr840_ne2000__DOT__dma_wr_ok = VL_RAND_RESET_I(1);
    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x = VL_RAND_RESET_I(32);
    vlSelf->dr840_ne2000__DOT__off_q = VL_RAND_RESET_I(1);
    vlSelf->dr840_ne2000__DOT__off_len = VL_RAND_RESET_I(11);
    vlSelf->dr840_ne2000__DOT__off_dst = VL_RAND_RESET_Q(48);
    vlSelf->dr840_ne2000__DOT__o_acc = VL_RAND_RESET_I(1);
    vlSelf->dr840_ne2000__DOT__o_pad = VL_RAND_RESET_I(11);
    vlSelf->dr840_ne2000__DOT__o_ring_ok = VL_RAND_RESET_I(1);
    vlSelf->dr840_ne2000__DOT__o_bnry_in = VL_RAND_RESET_I(1);
    vlSelf->dr840_ne2000__DOT__o_avail = VL_RAND_RESET_I(9);
    vlSelf->dr840_ne2000__DOT__o_next = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__r_st = VL_RAND_RESET_I(3);
    vlSelf->dr840_ne2000__DOT__r_ptr = VL_RAND_RESET_I(16);
    vlSelf->dr840_ne2000__DOT__r_n = VL_RAND_RESET_I(11);
    vlSelf->dr840_ne2000__DOT__r_len = VL_RAND_RESET_I(11);
    vlSelf->dr840_ne2000__DOT__r_pad = VL_RAND_RESET_I(11);
    vlSelf->dr840_ne2000__DOT__r_cnt = VL_RAND_RESET_I(12);
    vlSelf->dr840_ne2000__DOT__r_next = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__r_page = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__r_group = VL_RAND_RESET_I(1);
    vlSelf->dr840_ne2000__DOT__r_crc = VL_RAND_RESET_I(32);
    vlSelf->dr840_ne2000__DOT__r_k = VL_RAND_RESET_I(2);
    vlSelf->dr840_ne2000__DOT__r_ptr_n = VL_RAND_RESET_I(16);
    vlSelf->dr840_ne2000__DOT__tx_wait = VL_RAND_RESET_I(16);
    vlSelf->dr840_ne2000__DOT__tx_copied = VL_RAND_RESET_I(1);
    vlSelf->dr840_ne2000__DOT__tx_copied_ok = VL_RAND_RESET_I(1);
    vlSelf->dr840_ne2000__DOT__v = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__started = VL_RAND_RESET_I(1);
    vlSelf->dr840_ne2000__DOT__iset = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__iclr = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT__nreset = VL_RAND_RESET_I(1);
    vlSelf->dr840_ne2000__DOT____Vlvbound_h66bf5d70__0 = VL_RAND_RESET_I(8);
    vlSelf->dr840_ne2000__DOT____Vlvbound_h9fb8493e__0 = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_dr840_ne2000__DOT__prom__1__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_dr840_ne2000__DOT__prom__1__a = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_dr840_ne2000__DOT__prom__3__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_dr840_ne2000__DOT__prom__3__a = VL_RAND_RESET_I(5);
    vlSelf->__Vdly__dr840_ne2000__DOT__rbcr = VL_RAND_RESET_I(16);
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v0 = 0;
    vlSelf->__Vdly__dr840_ne2000__DOT__cr = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__dr840_ne2000__DOT__tx_pending = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tx_req = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__dr840_ne2000__DOT__tx_wait = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__dr840_ne2000__DOT__tx_copied = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__dr840_ne2000__DOT__rcr = VL_RAND_RESET_I(8);
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__par__v0 = 0;
    vlSelf->__Vdly__dr840_ne2000__DOT__curr = VL_RAND_RESET_I(8);
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__mar__v0 = 0;
    vlSelf->__Vdly__dr840_ne2000__DOT__tx_copied_ok = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__dr840_ne2000__DOT__off_q = VL_RAND_RESET_I(1);
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v1 = 0;
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v2 = 0;
    vlSelf->__Vdly__dr840_ne2000__DOT__r_st = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__dr840_ne2000__DOT__r_len = VL_RAND_RESET_I(11);
    vlSelf->__Vdly__dr840_ne2000__DOT__r_n = VL_RAND_RESET_I(11);
    vlSelf->__Vdly__dr840_ne2000__DOT__r_pad = VL_RAND_RESET_I(11);
    vlSelf->__Vdly__dr840_ne2000__DOT__r_cnt = VL_RAND_RESET_I(12);
    vlSelf->__Vdly__dr840_ne2000__DOT__r_next = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__dr840_ne2000__DOT__r_page = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__dr840_ne2000__DOT__r_group = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__dr840_ne2000__DOT__r_crc = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__dr840_ne2000__DOT__r_k = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__dr840_ne2000__DOT__r_ptr = VL_RAND_RESET_I(16);
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v3 = 0;
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v6 = 0;
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__par__v1 = 0;
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__par__v2 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
}
