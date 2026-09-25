// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_net.h for the primary calling header

#include "Vtb_net__pch.h"
#include "Vtb_net___024root.h"

VL_ATTR_COLD void Vtb_net___024root___eval_static(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_net___024root___eval_initial(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
}

VL_ATTR_COLD void Vtb_net___024root___eval_final(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_net___024root___dump_triggers__stl(Vtb_net___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_net___024root___eval_phase__stl(Vtb_net___024root* vlSelf);

VL_ATTR_COLD void Vtb_net___024root___eval_settle(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___eval_settle\n"); );
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
            Vtb_net___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb_net.sv", 5, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_net___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_net___024root___dump_triggers__stl(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_net___024root___stl_sequent__TOP__0(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___stl_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ tb_net__DOT__nic__DOT__mhash__Vstatic__c;
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = 0;
    CData/*7:0*/ tb_net__DOT__nic__DOT__mhash__Vstatic__by;
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = 0;
    CData/*5:0*/ tb_net__DOT__nic__DOT__o_hash;
    tb_net__DOT__nic__DOT__o_hash = 0;
    SData/*8:0*/ tb_net__DOT__nic__DOT__o_next0;
    tb_net__DOT__nic__DOT__o_next0 = 0;
    CData/*7:0*/ __Vfunc_tb_net__DOT__nic__DOT__space__0__Vfuncout;
    __Vfunc_tb_net__DOT__nic__DOT__space__0__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_tb_net__DOT__nic__DOT__space__0__a;
    __Vfunc_tb_net__DOT__nic__DOT__space__0__a = 0;
    CData/*7:0*/ __Vfunc_tb_net__DOT__nic__DOT__space__0__ram_byte;
    __Vfunc_tb_net__DOT__nic__DOT__space__0__ram_byte = 0;
    CData/*7:0*/ __Vfunc_tb_net__DOT__nic__DOT__space__2__Vfuncout;
    __Vfunc_tb_net__DOT__nic__DOT__space__2__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_tb_net__DOT__nic__DOT__space__2__a;
    __Vfunc_tb_net__DOT__nic__DOT__space__2__a = 0;
    CData/*7:0*/ __Vfunc_tb_net__DOT__nic__DOT__space__2__ram_byte;
    __Vfunc_tb_net__DOT__nic__DOT__space__2__ram_byte = 0;
    CData/*5:0*/ __Vfunc_tb_net__DOT__nic__DOT__mhash__4__Vfuncout;
    __Vfunc_tb_net__DOT__nic__DOT__mhash__4__Vfuncout = 0;
    QData/*47:0*/ __Vfunc_tb_net__DOT__nic__DOT__mhash__4__d;
    __Vfunc_tb_net__DOT__nic__DOT__mhash__4__d = 0;
    // Body
    vlSelf->cen_o = vlSelf->tb_net__DOT__cen;
    vlSelf->tb_net__DOT____Vcellinp__nic__acc = ((IData)(vlSelf->acc) 
                                                 & (IData)(vlSelf->tb_net__DOT__cen));
    vlSelf->irq = (0U != (0x7fU & ((IData)(vlSelf->tb_net__DOT__nic__DOT__imr) 
                                   & (IData)(vlSelf->tb_net__DOT__nic__DOT__isr))));
    vlSelf->tb_net__DOT__rx_busy = ((0U != (IData)(vlSelf->tb_net__DOT__nic__DOT__r_st)) 
                                    | (IData)(vlSelf->tb_net__DOT__nic__DOT__off_q));
    vlSelf->tb_net__DOT__nic__DOT__dma_wr_ok = (IData)(
                                                       ((0x10U 
                                                         == 
                                                         (0x38U 
                                                          & (IData)(vlSelf->tb_net__DOT__nic__DOT__cr))) 
                                                        & (0U 
                                                           != (IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr))));
    vlSelf->tb_net__DOT__nic__DOT__pb_a = ((IData)(vlSelf->tb_net__DOT__nic__DOT__wb)
                                            ? (IData)(vlSelf->tb_net__DOT__nic__DOT__wb_a)
                                            : (IData)(vlSelf->tb_net__DOT__b_addr));
    vlSelf->tb_net__DOT__nic__DOT__o_ring_ok = (1U 
                                                & (~ 
                                                   ((0x40U 
                                                     > (IData)(vlSelf->tb_net__DOT__nic__DOT__pstart)) 
                                                    | ((0x80U 
                                                        < (IData)(vlSelf->tb_net__DOT__nic__DOT__pstop)) 
                                                       | (((IData)(vlSelf->tb_net__DOT__nic__DOT__pstart) 
                                                           >= (IData)(vlSelf->tb_net__DOT__nic__DOT__pstop)) 
                                                          | (((IData)(vlSelf->tb_net__DOT__nic__DOT__curr) 
                                                              < (IData)(vlSelf->tb_net__DOT__nic__DOT__pstart)) 
                                                             | ((IData)(vlSelf->tb_net__DOT__nic__DOT__curr) 
                                                                >= (IData)(vlSelf->tb_net__DOT__nic__DOT__pstop))))))));
    vlSelf->tb_net__DOT__nic__DOT__o_bnry_in = (((IData)(vlSelf->tb_net__DOT__nic__DOT__bnry) 
                                                 >= (IData)(vlSelf->tb_net__DOT__nic__DOT__pstart)) 
                                                & ((IData)(vlSelf->tb_net__DOT__nic__DOT__bnry) 
                                                   < (IData)(vlSelf->tb_net__DOT__nic__DOT__pstop)));
    vlSelf->tb_net__DOT__nic__DOT__r_ptr_n = (0xffffU 
                                              & (((0xffffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->tb_net__DOT__nic__DOT__r_ptr))) 
                                                  == 
                                                  ((IData)(vlSelf->tb_net__DOT__nic__DOT__pstop) 
                                                   << 8U))
                                                  ? 
                                                 ((IData)(vlSelf->tb_net__DOT__nic__DOT__pstart) 
                                                  << 8U)
                                                  : 
                                                 ((IData)(1U) 
                                                  + (IData)(vlSelf->tb_net__DOT__nic__DOT__r_ptr))));
    vlSelf->tb_net__DOT__nic__DOT__o_avail = (0x1ffU 
                                              & (((IData)(vlSelf->tb_net__DOT__nic__DOT__bnry) 
                                                  > (IData)(vlSelf->tb_net__DOT__nic__DOT__curr))
                                                  ? 
                                                 (0xffU 
                                                  & ((IData)(vlSelf->tb_net__DOT__nic__DOT__bnry) 
                                                     - (IData)(vlSelf->tb_net__DOT__nic__DOT__curr)))
                                                  : 
                                                 ((0xffU 
                                                   & ((IData)(vlSelf->tb_net__DOT__nic__DOT__pstop) 
                                                      - (IData)(vlSelf->tb_net__DOT__nic__DOT__curr))) 
                                                  + 
                                                  (0xffU 
                                                   & ((IData)(vlSelf->tb_net__DOT__nic__DOT__bnry) 
                                                      - (IData)(vlSelf->tb_net__DOT__nic__DOT__pstart))))));
    vlSelf->tb_net__DOT__nic__DOT__o_pad = ((0x3cU 
                                             > (IData)(vlSelf->tb_net__DOT__nic__DOT__off_len))
                                             ? 0x3cU
                                             : (IData)(vlSelf->tb_net__DOT__nic__DOT__off_len));
    __Vfunc_tb_net__DOT__nic__DOT__mhash__4__d = vlSelf->tb_net__DOT__nic__DOT__off_dst;
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x28U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & (IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by))
                                                 ? 0xfffffffeU
                                                 : 0xfb3ee249U);
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x28U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 1U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x28U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 2U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x28U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 3U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x28U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 4U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x28U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 5U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x28U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 6U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x28U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = (((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  >> 0x1fU) 
                                                 ^ 
                                                 ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                  >> 7U))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x20U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ (IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x20U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 1U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x20U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 2U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x20U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 3U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x20U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 4U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x20U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 5U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x20U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 6U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x20U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = (((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  >> 0x1fU) 
                                                 ^ 
                                                 ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                  >> 7U))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x18U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ (IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x18U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 1U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x18U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 2U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x18U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 3U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x18U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 4U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x18U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 5U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x18U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 6U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x18U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = (((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  >> 0x1fU) 
                                                 ^ 
                                                 ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                  >> 7U))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x10U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ (IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x10U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 1U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x10U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 2U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x10U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 3U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x10U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 4U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x10U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 5U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x10U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 6U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 0x10U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = (((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  >> 0x1fU) 
                                                 ^ 
                                                 ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                  >> 7U))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 8U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ (IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 8U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 1U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 8U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 2U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 8U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 3U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 8U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 4U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 8U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 5U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 8U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 6U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(
                                                           (__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d 
                                                            >> 8U)));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = (((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  >> 0x1fU) 
                                                 ^ 
                                                 ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                  >> 7U))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ (IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 1U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 2U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 3U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 4U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 5U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = ((1U 
                                                 & ((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                     >> 0x1fU) 
                                                    ^ 
                                                    ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                     >> 6U)))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = (0xffU 
                                                 & (IData)(__Vfunc_tb_net__DOT__nic__DOT__mhash__4__d));
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = (((tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  >> 0x1fU) 
                                                 ^ 
                                                 ((IData)(tb_net__DOT__nic__DOT__mhash__Vstatic__by) 
                                                  >> 7U))
                                                 ? 
                                                (0x4c11db7U 
                                                 ^ 
                                                 (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                  << 1U))
                                                 : 
                                                (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
                                                 << 1U));
    __Vfunc_tb_net__DOT__nic__DOT__mhash__4__Vfuncout 
        = (tb_net__DOT__nic__DOT__mhash__Vstatic__c 
           >> 0x1aU);
    tb_net__DOT__nic__DOT__o_hash = __Vfunc_tb_net__DOT__nic__DOT__mhash__4__Vfuncout;
    vlSelf->tb_net__DOT__nic__DOT__dma_rd_ok = (IData)(
                                                       ((8U 
                                                         == 
                                                         (0x38U 
                                                          & (IData)(vlSelf->tb_net__DOT__nic__DOT__cr))) 
                                                        & (0U 
                                                           != (IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr))));
    __Vfunc_tb_net__DOT__nic__DOT__space__0__a = vlSelf->tb_net__DOT__nic__DOT__rsar;
    __Vfunc_tb_net__DOT__nic__DOT__space__0__ram_byte 
        = ((1U & (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar))
            ? (IData)(vlSelf->tb_net__DOT__nic__DOT__qa_o)
            : (IData)(vlSelf->tb_net__DOT__nic__DOT__qa_e));
    __Vfunc_tb_net__DOT__nic__DOT__space__0__Vfuncout 
        = ((0x20U > (IData)(__Vfunc_tb_net__DOT__nic__DOT__space__0__a))
            ? ([&]() {
                vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__1__a 
                    = (0x1fU & (IData)(__Vfunc_tb_net__DOT__nic__DOT__space__0__a));
                vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__1__Vfuncout 
                    = ((0x10U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__1__a))
                        ? ((8U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__1__a))
                            ? ((4U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__1__a))
                                ? 0x57U : 0U) : 0U)
                        : ((8U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__1__a))
                            ? ((4U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__1__a))
                                ? 0U : ((2U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__1__a))
                                         ? 1U : 0U))
                            : ((4U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__1__a))
                                ? ((2U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__1__a))
                                    ? 0x84U : 0U) : 
                               ((2U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__1__a))
                                 ? 0U : 2U))));
            }(), (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__1__Vfuncout))
            : (((0x4000U <= (IData)(__Vfunc_tb_net__DOT__nic__DOT__space__0__a)) 
                & (0x8000U > (IData)(__Vfunc_tb_net__DOT__nic__DOT__space__0__a)))
                ? (IData)(__Vfunc_tb_net__DOT__nic__DOT__space__0__ram_byte)
                : 0xffU));
    __Vfunc_tb_net__DOT__nic__DOT__space__2__ram_byte 
        = ((1U & (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar))
            ? (IData)(vlSelf->tb_net__DOT__nic__DOT__qa_e)
            : (IData)(vlSelf->tb_net__DOT__nic__DOT__qa_o));
    vlSelf->tb_net__DOT__nic__DOT__b0 = __Vfunc_tb_net__DOT__nic__DOT__space__0__Vfuncout;
    vlSelf->tb_net__DOT__nic__DOT__rsar_n = (0xffffU 
                                             & ((((IData)(vlSelf->tb_net__DOT__nic__DOT__pstop) 
                                                  > (IData)(vlSelf->tb_net__DOT__nic__DOT__pstart)) 
                                                 & ((0xffffU 
                                                     & ((IData)(1U) 
                                                        + (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar))) 
                                                    == 
                                                    ((IData)(vlSelf->tb_net__DOT__nic__DOT__pstop) 
                                                     << 8U)))
                                                 ? 
                                                ((IData)(vlSelf->tb_net__DOT__nic__DOT__pstart) 
                                                 << 8U)
                                                 : 
                                                ((IData)(1U) 
                                                 + (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar))));
    tb_net__DOT__nic__DOT__o_next0 = (0x1ffU & ((IData)(vlSelf->tb_net__DOT__nic__DOT__curr) 
                                                + (0xffU 
                                                   & VL_SHIFTR_III(12,12,32, 
                                                                   (0xfffU 
                                                                    & ((IData)(0x107U) 
                                                                       + (IData)(vlSelf->tb_net__DOT__nic__DOT__o_pad))), 8U))));
    vlSelf->tb_net__DOT__nic__DOT__o_acc = (1U & ((0xffffffffffffULL 
                                                   == vlSelf->tb_net__DOT__nic__DOT__off_dst)
                                                   ? 
                                                  ((IData)(vlSelf->tb_net__DOT__nic__DOT__rcr) 
                                                   >> 2U)
                                                   : 
                                                  ((1U 
                                                    & (IData)(
                                                              (vlSelf->tb_net__DOT__nic__DOT__off_dst 
                                                               >> 0x28U)))
                                                    ? 
                                                   (((IData)(vlSelf->tb_net__DOT__nic__DOT__rcr) 
                                                     >> 3U) 
                                                    & (vlSelf->tb_net__DOT__nic__DOT__mar
                                                       [
                                                       (7U 
                                                        & ((IData)(tb_net__DOT__nic__DOT__o_hash) 
                                                           >> 3U))] 
                                                       >> 
                                                       (7U 
                                                        & (IData)(tb_net__DOT__nic__DOT__o_hash))))
                                                    : 
                                                   (((IData)(vlSelf->tb_net__DOT__nic__DOT__rcr) 
                                                     >> 4U) 
                                                    | (vlSelf->tb_net__DOT__nic__DOT__off_dst 
                                                       == 
                                                       (((QData)((IData)(
                                                                         vlSelf->tb_net__DOT__nic__DOT__par
                                                                         [0U])) 
                                                         << 0x28U) 
                                                        | (((QData)((IData)(
                                                                            vlSelf->tb_net__DOT__nic__DOT__par
                                                                            [1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             ((vlSelf->tb_net__DOT__nic__DOT__par
                                                                               [2U] 
                                                                               << 0x18U) 
                                                                              | ((vlSelf->tb_net__DOT__nic__DOT__par
                                                                                [3U] 
                                                                                << 0x10U) 
                                                                                | ((vlSelf->tb_net__DOT__nic__DOT__par
                                                                                [4U] 
                                                                                << 8U) 
                                                                                | vlSelf->tb_net__DOT__nic__DOT__par
                                                                                [5U]))))))))))));
    vlSelf->tb_net__DOT__nic__DOT__pa_e = (0x1fffU 
                                           & ((IData)(vlSelf->tb_net__DOT__nic__DOT__wa_e)
                                               ? (IData)(vlSelf->tb_net__DOT__nic__DOT__wa_e_i)
                                               : ((
                                                   (1U 
                                                    & (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar))
                                                    ? (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar_n)
                                                    : (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar)) 
                                                  >> 1U)));
    vlSelf->tb_net__DOT__nic__DOT__pa_o = (0x1fffU 
                                           & ((IData)(vlSelf->tb_net__DOT__nic__DOT__wa_o)
                                               ? (IData)(vlSelf->tb_net__DOT__nic__DOT__wa_o_i)
                                               : ((
                                                   (1U 
                                                    & (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar))
                                                    ? (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar)
                                                    : (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar_n)) 
                                                  >> 1U)));
    __Vfunc_tb_net__DOT__nic__DOT__space__2__a = vlSelf->tb_net__DOT__nic__DOT__rsar_n;
    __Vfunc_tb_net__DOT__nic__DOT__space__2__Vfuncout 
        = ((0x20U > (IData)(__Vfunc_tb_net__DOT__nic__DOT__space__2__a))
            ? ([&]() {
                vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__3__a 
                    = (0x1fU & (IData)(__Vfunc_tb_net__DOT__nic__DOT__space__2__a));
                vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__3__Vfuncout 
                    = ((0x10U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__3__a))
                        ? ((8U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__3__a))
                            ? ((4U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__3__a))
                                ? 0x57U : 0U) : 0U)
                        : ((8U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__3__a))
                            ? ((4U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__3__a))
                                ? 0U : ((2U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__3__a))
                                         ? 1U : 0U))
                            : ((4U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__3__a))
                                ? ((2U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__3__a))
                                    ? 0x84U : 0U) : 
                               ((2U & (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__3__a))
                                 ? 0U : 2U))));
            }(), (IData)(vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__3__Vfuncout))
            : (((0x4000U <= (IData)(__Vfunc_tb_net__DOT__nic__DOT__space__2__a)) 
                & (0x8000U > (IData)(__Vfunc_tb_net__DOT__nic__DOT__space__2__a)))
                ? (IData)(__Vfunc_tb_net__DOT__nic__DOT__space__2__ram_byte)
                : 0xffU));
    vlSelf->tb_net__DOT__nic__DOT__b1 = __Vfunc_tb_net__DOT__nic__DOT__space__2__Vfuncout;
    vlSelf->tb_net__DOT__nic__DOT__o_next = (0xffU 
                                             & (((IData)(tb_net__DOT__nic__DOT__o_next0) 
                                                 >= (IData)(vlSelf->tb_net__DOT__nic__DOT__pstop))
                                                 ? 
                                                ((IData)(tb_net__DOT__nic__DOT__o_next0) 
                                                 - 
                                                 ((IData)(vlSelf->tb_net__DOT__nic__DOT__pstop) 
                                                  - (IData)(vlSelf->tb_net__DOT__nic__DOT__pstart)))
                                                 : (IData)(tb_net__DOT__nic__DOT__o_next0)));
    vlSelf->rdata = 0xffU;
    vlSelf->rdata = ((0x10U == (IData)(vlSelf->port))
                      ? ((IData)(vlSelf->wide) ? ((
                                                   ((IData)(vlSelf->tb_net__DOT__nic__DOT__dma_rd_ok)
                                                     ? (IData)(vlSelf->tb_net__DOT__nic__DOT__b0)
                                                     : 0xffU) 
                                                   << 8U) 
                                                  | (((IData)(vlSelf->tb_net__DOT__nic__DOT__dma_rd_ok) 
                                                      & (1U 
                                                         != (IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr)))
                                                      ? (IData)(vlSelf->tb_net__DOT__nic__DOT__b1)
                                                      : 0xffU))
                          : ((IData)(vlSelf->tb_net__DOT__nic__DOT__dma_rd_ok)
                              ? (IData)(vlSelf->tb_net__DOT__nic__DOT__b0)
                              : 0xffU)) : ((IData)(vlSelf->wide)
                                            ? 0xffffU
                                            : ((0x1fU 
                                                == (IData)(vlSelf->port))
                                                ? 0U
                                                : (
                                                   (0U 
                                                    == (IData)(vlSelf->port))
                                                    ? (IData)(vlSelf->tb_net__DOT__nic__DOT__cr)
                                                    : 
                                                   ((0x10U 
                                                     & (IData)(vlSelf->port))
                                                     ? 0xffU
                                                     : 
                                                    ((0U 
                                                      == 
                                                      (3U 
                                                       & ((IData)(vlSelf->tb_net__DOT__nic__DOT__cr) 
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
                                                         vlSelf->tb_net__DOT__nic__DOT__tally
                                                         [2U]
                                                          : 
                                                         vlSelf->tb_net__DOT__nic__DOT__tally
                                                         [1U])
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->port))
                                                          ? 
                                                         vlSelf->tb_net__DOT__nic__DOT__tally
                                                         [0U]
                                                          : (IData)(vlSelf->tb_net__DOT__nic__DOT__rsr)))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->port))
                                                         ? 0xffU
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->port))
                                                          ? 
                                                         (0xffU 
                                                          & ((IData)(vlSelf->tb_net__DOT__nic__DOT__rsar) 
                                                             >> 8U))
                                                          : 
                                                         (0xffU 
                                                          & (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar)))))
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelf->port))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelf->port))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->port))
                                                          ? (IData)(vlSelf->tb_net__DOT__nic__DOT__isr)
                                                          : 0U)
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSelf->port))
                                                          ? 0U
                                                          : (IData)(vlSelf->tb_net__DOT__nic__DOT__tsr)))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelf->port))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelf->port))
                                                          ? (IData)(vlSelf->tb_net__DOT__nic__DOT__bnry)
                                                          : 0xffU)
                                                         : 0xffU)))
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (3U 
                                                        & ((IData)(vlSelf->tb_net__DOT__nic__DOT__cr) 
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
                                                        vlSelf->tb_net__DOT__nic__DOT__par
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
                                                         ? (IData)(vlSelf->tb_net__DOT__nic__DOT__curr)
                                                         : 
                                                        vlSelf->tb_net__DOT__nic__DOT__mar
                                                        [
                                                        (7U 
                                                         & (IData)(vlSelf->port))]))
                                                       : 
                                                      ((2U 
                                                        == 
                                                        (3U 
                                                         & ((IData)(vlSelf->tb_net__DOT__nic__DOT__cr) 
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
                                                            ? (IData)(vlSelf->tb_net__DOT__nic__DOT__imr)
                                                            : (IData)(vlSelf->tb_net__DOT__nic__DOT__dcr))
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelf->port))
                                                            ? (IData)(vlSelf->tb_net__DOT__nic__DOT__tcr)
                                                            : (IData)(vlSelf->tb_net__DOT__nic__DOT__rcr)))
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
                                                            : (IData)(vlSelf->tb_net__DOT__nic__DOT__tpsr)))
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelf->port))
                                                           ? 
                                                          ((1U 
                                                            & (IData)(vlSelf->port))
                                                            ? 0xffU
                                                            : (IData)(vlSelf->tb_net__DOT__nic__DOT__pstop))
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelf->port))
                                                            ? (IData)(vlSelf->tb_net__DOT__nic__DOT__pstart)
                                                            : 0xffU))))
                                                        : 0xffU))))))));
}

VL_ATTR_COLD void Vtb_net___024root___eval_stl(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_net___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_net___024root___eval_triggers__stl(Vtb_net___024root* vlSelf);

VL_ATTR_COLD bool Vtb_net___024root___eval_phase__stl(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_net___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_net___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_net___024root___dump_triggers__ico(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vtb_net___024root___dump_triggers__act(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_net___024root___dump_triggers__nba(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_net___024root___ctor_var_reset(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->enable = VL_RAND_RESET_I(1);
    vlSelf->acc = VL_RAND_RESET_I(1);
    vlSelf->we = VL_RAND_RESET_I(1);
    vlSelf->wide = VL_RAND_RESET_I(1);
    vlSelf->port = VL_RAND_RESET_I(5);
    vlSelf->wdata = VL_RAND_RESET_I(16);
    vlSelf->rdata = VL_RAND_RESET_I(16);
    vlSelf->irq = VL_RAND_RESET_I(1);
    vlSelf->ddr_busy = VL_RAND_RESET_I(1);
    vlSelf->ddr_addr = VL_RAND_RESET_I(29);
    vlSelf->ddr_rd = VL_RAND_RESET_I(1);
    vlSelf->ddr_we = VL_RAND_RESET_I(1);
    vlSelf->ddr_din = VL_RAND_RESET_Q(64);
    vlSelf->ddr_dout = VL_RAND_RESET_Q(64);
    vlSelf->ddr_dout_ready = VL_RAND_RESET_I(1);
    vlSelf->link = VL_RAND_RESET_I(1);
    vlSelf->frames_tx = VL_RAND_RESET_I(32);
    vlSelf->frames_rx = VL_RAND_RESET_I(32);
    vlSelf->cen_o = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__cen = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__tx_req = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__tx_done = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__tx_ok = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__rx_offer = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__rx_answer = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__rx_take = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__rx_byte = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__rx_busy = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__tx_base = VL_RAND_RESET_I(14);
    vlSelf->tb_net__DOT__b_addr = VL_RAND_RESET_I(14);
    vlSelf->tb_net__DOT__tx_len = VL_RAND_RESET_I(11);
    vlSelf->tb_net__DOT__rx_len = VL_RAND_RESET_I(11);
    vlSelf->tb_net__DOT__rx_dst = VL_RAND_RESET_Q(48);
    vlSelf->tb_net__DOT__rx_data = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT____Vcellinp__nic__acc = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT__dbg_tx = VL_RAND_RESET_I(32);
    vlSelf->tb_net__DOT__nic__DOT__dbg_rx = VL_RAND_RESET_I(32);
    vlSelf->tb_net__DOT__nic__DOT__cr = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__isr = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__imr = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__dcr = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__rcr = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__tcr = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__tsr = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__rsr = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__pstart = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__pstop = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__bnry = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__curr = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__tpsr = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->tb_net__DOT__nic__DOT__par[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_net__DOT__nic__DOT__mar[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_net__DOT__nic__DOT__rsar = VL_RAND_RESET_I(16);
    vlSelf->tb_net__DOT__nic__DOT__rbcr = VL_RAND_RESET_I(16);
    vlSelf->tb_net__DOT__nic__DOT__tbcr = VL_RAND_RESET_I(16);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->tb_net__DOT__nic__DOT__tally[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_net__DOT__nic__DOT__tx_pending = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->tb_net__DOT__nic__DOT__ram_e[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->tb_net__DOT__nic__DOT__ram_o[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_net__DOT__nic__DOT__rsar_n = VL_RAND_RESET_I(16);
    vlSelf->tb_net__DOT__nic__DOT__qa_e = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__qa_o = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__wa_e = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT__wa_o = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT__wa_e_i = VL_RAND_RESET_I(13);
    vlSelf->tb_net__DOT__nic__DOT__wa_o_i = VL_RAND_RESET_I(13);
    vlSelf->tb_net__DOT__nic__DOT__wa_e_d = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__wa_o_d = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__wb = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT__wb_a = VL_RAND_RESET_I(14);
    vlSelf->tb_net__DOT__nic__DOT__wb_d = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__qb_e = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__qb_o = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__b_lsb = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT__pb_a = VL_RAND_RESET_I(14);
    vlSelf->tb_net__DOT__nic__DOT__pa_e = VL_RAND_RESET_I(13);
    vlSelf->tb_net__DOT__nic__DOT__pa_o = VL_RAND_RESET_I(13);
    vlSelf->tb_net__DOT__nic__DOT__b0 = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__b1 = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__dma_rd_ok = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT__dma_wr_ok = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x = VL_RAND_RESET_I(32);
    vlSelf->tb_net__DOT__nic__DOT__off_q = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT__off_len = VL_RAND_RESET_I(11);
    vlSelf->tb_net__DOT__nic__DOT__off_dst = VL_RAND_RESET_Q(48);
    vlSelf->tb_net__DOT__nic__DOT__o_acc = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT__o_pad = VL_RAND_RESET_I(11);
    vlSelf->tb_net__DOT__nic__DOT__o_ring_ok = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT__o_bnry_in = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT__o_avail = VL_RAND_RESET_I(9);
    vlSelf->tb_net__DOT__nic__DOT__o_next = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__r_st = VL_RAND_RESET_I(3);
    vlSelf->tb_net__DOT__nic__DOT__r_ptr = VL_RAND_RESET_I(16);
    vlSelf->tb_net__DOT__nic__DOT__r_n = VL_RAND_RESET_I(11);
    vlSelf->tb_net__DOT__nic__DOT__r_len = VL_RAND_RESET_I(11);
    vlSelf->tb_net__DOT__nic__DOT__r_pad = VL_RAND_RESET_I(11);
    vlSelf->tb_net__DOT__nic__DOT__r_cnt = VL_RAND_RESET_I(12);
    vlSelf->tb_net__DOT__nic__DOT__r_next = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__r_page = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__r_group = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT__r_crc = VL_RAND_RESET_I(32);
    vlSelf->tb_net__DOT__nic__DOT__r_k = VL_RAND_RESET_I(2);
    vlSelf->tb_net__DOT__nic__DOT__r_ptr_n = VL_RAND_RESET_I(16);
    vlSelf->tb_net__DOT__nic__DOT__tx_wait = VL_RAND_RESET_I(16);
    vlSelf->tb_net__DOT__nic__DOT__tx_copied = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT__tx_copied_ok = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT__v = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__started = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT__iset = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__iclr = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT__nreset = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__nic__DOT____Vlvbound_h66bf5d70__0 = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__nic__DOT____Vlvbound_h9fb8493e__0 = VL_RAND_RESET_I(8);
    vlSelf->tb_net__DOT__br__DOT__st = VL_RAND_RESET_I(5);
    vlSelf->tb_net__DOT__br__DOT__ret = VL_RAND_RESET_I(5);
    vlSelf->tb_net__DOT__br__DOT__tx_head = VL_RAND_RESET_I(32);
    vlSelf->tb_net__DOT__br__DOT__tx_tail = VL_RAND_RESET_I(32);
    vlSelf->tb_net__DOT__br__DOT__rx_head = VL_RAND_RESET_I(32);
    vlSelf->tb_net__DOT__br__DOT__rx_tail = VL_RAND_RESET_I(32);
    vlSelf->tb_net__DOT__br__DOT__poll_cnt = VL_RAND_RESET_I(20);
    vlSelf->tb_net__DOT__br__DOT__n = VL_RAND_RESET_I(11);
    vlSelf->tb_net__DOT__br__DOT__acc = VL_RAND_RESET_Q(64);
    vlSelf->tb_net__DOT__br__DOT__bw = VL_RAND_RESET_I(2);
    vlSelf->tb_net__DOT__br__DOT__lanes = VL_RAND_RESET_I(3);
    vlSelf->tb_net__DOT__br__DOT__pulse_wait = VL_RAND_RESET_I(1);
    vlSelf->tb_net__DOT__br__DOT__magic_ok = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_net__DOT__br__DOT__tq[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->tb_net__DOT__br__DOT__tq_w = VL_RAND_RESET_I(6);
    vlSelf->tb_net__DOT__br__DOT__tq_r = VL_RAND_RESET_I(6);
    vlSelf->tb_net__DOT__br__DOT__t_count = VL_RAND_RESET_I(32);
    vlSelf->tb_net__DOT__br__DOT__epoch = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__1__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__1__a = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__3__Vfuncout = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_tb_net__DOT__nic__DOT__prom__3__a = VL_RAND_RESET_I(5);
    vlSelf->__Vdly__tb_net__DOT__cen = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__rbcr = VL_RAND_RESET_I(16);
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v0 = 0;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__cr = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_pending = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_net__DOT__tx_req = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_wait = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_copied = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__rcr = VL_RAND_RESET_I(8);
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__par__v0 = 0;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__curr = VL_RAND_RESET_I(8);
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__mar__v0 = 0;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_copied_ok = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__off_q = VL_RAND_RESET_I(1);
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v1 = 0;
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v2 = 0;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_st = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_len = VL_RAND_RESET_I(11);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_n = VL_RAND_RESET_I(11);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_pad = VL_RAND_RESET_I(11);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_cnt = VL_RAND_RESET_I(12);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_next = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_page = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_group = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_crc = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_k = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_ptr = VL_RAND_RESET_I(16);
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v3 = 0;
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v6 = 0;
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__par__v1 = 0;
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__par__v2 = 0;
    vlSelf->__Vdly__tb_net__DOT__tx_done = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_net__DOT__rx_offer = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_net__DOT__rx_byte = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tb_net__DOT__rx_data = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__tb_net__DOT__rx_dst = VL_RAND_RESET_Q(48);
    vlSelf->__Vdly__tb_net__DOT__rx_len = VL_RAND_RESET_I(11);
    vlSelf->__Vdly__tb_net__DOT__tx_ok = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
}
