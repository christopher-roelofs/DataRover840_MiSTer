// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdr840_pclink.h for the primary calling header

#include "Vdr840_pclink__pch.h"
#include "Vdr840_pclink___024root.h"

VL_ATTR_COLD void Vdr840_pclink___024root___eval_static(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vdr840_pclink___024root___eval_initial(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
}

VL_ATTR_COLD void Vdr840_pclink___024root___eval_final(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_pclink___024root___dump_triggers__stl(Vdr840_pclink___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vdr840_pclink___024root___eval_phase__stl(Vdr840_pclink___024root* vlSelf);

VL_ATTR_COLD void Vdr840_pclink___024root___eval_settle(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval_settle\n"); );
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
            Vdr840_pclink___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../../rtl/soc/dr840_pclink.sv", 35, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vdr840_pclink___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_pclink___024root___dump_triggers__stl(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdr840_pclink___024root___stl_sequent__TOP__0(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___stl_sequent__TOP__0\n"); );
    // Init
    SData/*11:0*/ dr840_pclink__DOT__src__Vstatic__j;
    dr840_pclink__DOT__src__Vstatic__j = 0;
    CData/*7:0*/ __Vfunc_dr840_pclink__DOT__src__0__Vfuncout;
    __Vfunc_dr840_pclink__DOT__src__0__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_dr840_pclink__DOT__src__0__k;
    __Vfunc_dr840_pclink__DOT__src__0__k = 0;
    IData/*24:0*/ __Vfunc_dr840_pclink__DOT__src__0__i;
    __Vfunc_dr840_pclink__DOT__src__0__i = 0;
    IData/*24:0*/ __Vfunc_dr840_pclink__DOT__src__0__len;
    __Vfunc_dr840_pclink__DOT__src__0__len = 0;
    IData/*31:0*/ __Vfunc_dr840_pclink__DOT__src__0__w;
    __Vfunc_dr840_pclink__DOT__src__0__w = 0;
    // Body
    vlSelf->dr840_pclink__DOT__next_seq = (0U != (IData)(vlSelf->dr840_pclink__DOT__seq));
    vlSelf->dr840_pclink__DOT__can_send = ((IData)(vlSelf->uart_on) 
                                           & ((~ (IData)(vlSelf->grx_full)) 
                                              & ((0U 
                                                  == vlSelf->dr840_pclink__DOT__pace) 
                                                 & (2U 
                                                    == (IData)(vlSelf->state)))));
    vlSelf->dr840_pclink__DOT__have_word = ((2U != (IData)(vlSelf->dr840_pclink__DOT__mk)) 
                                            | ((IData)(vlSelf->dr840_pclink__DOT__word_ok) 
                                               & (vlSelf->dr840_pclink__DOT__word_addr 
                                                  == 
                                                  (0x7fffffU 
                                                   & (vlSelf->dr840_pclink__DOT__mi 
                                                      >> 2U)))));
    vlSelf->dr840_pclink__DOT__seq_kind = ((3U == (IData)(vlSelf->dr840_pclink__DOT__seq))
                                            ? 1U : 
                                           ((4U == (IData)(vlSelf->dr840_pclink__DOT__seq))
                                             ? 2U : 
                                            ((5U == (IData)(vlSelf->dr840_pclink__DOT__seq))
                                              ? 3U : 0U)));
    vlSelf->dr840_pclink__DOT__cmd_len_now = ((vlSelf->dr840_pclink__DOT__cmd_rem 
                                               << 8U) 
                                              | (IData)(vlSelf->gtx_data));
    __Vfunc_dr840_pclink__DOT__src__0__w = vlSelf->dr840_pclink__DOT__word;
    __Vfunc_dr840_pclink__DOT__src__0__len = vlSelf->pkg_len;
    __Vfunc_dr840_pclink__DOT__src__0__i = vlSelf->dr840_pclink__DOT__mi;
    __Vfunc_dr840_pclink__DOT__src__0__k = vlSelf->dr840_pclink__DOT__mk;
    dr840_pclink__DOT__src__Vstatic__j = (0xfffU & 
                                          (__Vfunc_dr840_pclink__DOT__src__0__i 
                                           - (IData)(8U)));
    __Vfunc_dr840_pclink__DOT__src__0__Vfuncout = (0xffU 
                                                   & ((4U 
                                                       & (IData)(__Vfunc_dr840_pclink__DOT__src__0__k))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(__Vfunc_dr840_pclink__DOT__src__0__k))
                                                        ? 
                                                       ((0U 
                                                         == 
                                                         (3U 
                                                          & __Vfunc_dr840_pclink__DOT__src__0__i))
                                                         ? 
                                                        (__Vfunc_dr840_pclink__DOT__src__0__w 
                                                         >> 0x18U)
                                                         : 
                                                        ((1U 
                                                          == 
                                                          (3U 
                                                           & __Vfunc_dr840_pclink__DOT__src__0__i))
                                                          ? 
                                                         (__Vfunc_dr840_pclink__DOT__src__0__w 
                                                          >> 0x10U)
                                                          : 
                                                         ((2U 
                                                           == 
                                                           (3U 
                                                            & __Vfunc_dr840_pclink__DOT__src__0__i))
                                                           ? 
                                                          (__Vfunc_dr840_pclink__DOT__src__0__w 
                                                           >> 8U)
                                                           : __Vfunc_dr840_pclink__DOT__src__0__w)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(__Vfunc_dr840_pclink__DOT__src__0__k))
                                                         ? 
                                                        ((0U 
                                                          == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                          ? 0x50U
                                                          : 
                                                         ((1U 
                                                           == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                           ? 0x69U
                                                           : 
                                                          ((2U 
                                                            == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                            ? 0x6eU
                                                            : 
                                                           ((3U 
                                                             == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                             ? 0x67U
                                                             : 0U))))
                                                         : 
                                                        ((0U 
                                                          == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                          ? 0x50U
                                                          : 
                                                         ((1U 
                                                           == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                           ? 0x6fU
                                                           : 
                                                          ((2U 
                                                            == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                            ? 0x6eU
                                                            : 
                                                           ((3U 
                                                             == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                             ? 0x67U
                                                             : 0U))))))
                                                       : 
                                                      ((2U 
                                                        & (IData)(__Vfunc_dr840_pclink__DOT__src__0__k))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(__Vfunc_dr840_pclink__DOT__src__0__k))
                                                         ? 0U
                                                         : 
                                                        ((0U 
                                                          == 
                                                          (3U 
                                                           & __Vfunc_dr840_pclink__DOT__src__0__i))
                                                          ? 
                                                         (__Vfunc_dr840_pclink__DOT__src__0__w 
                                                          >> 0x18U)
                                                          : 
                                                         ((1U 
                                                           == 
                                                           (3U 
                                                            & __Vfunc_dr840_pclink__DOT__src__0__i))
                                                           ? 
                                                          (__Vfunc_dr840_pclink__DOT__src__0__w 
                                                           >> 0x10U)
                                                           : 
                                                          ((2U 
                                                            == 
                                                            (3U 
                                                             & __Vfunc_dr840_pclink__DOT__src__0__i))
                                                            ? 
                                                           (__Vfunc_dr840_pclink__DOT__src__0__w 
                                                            >> 8U)
                                                            : __Vfunc_dr840_pclink__DOT__src__0__w))))
                                                        : 
                                                       ((1U 
                                                         & (IData)(__Vfunc_dr840_pclink__DOT__src__0__k))
                                                         ? 
                                                        ((4U 
                                                          > __Vfunc_dr840_pclink__DOT__src__0__i)
                                                          ? 
                                                         ((0U 
                                                           == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                           ? 0x53U
                                                           : 
                                                          ((1U 
                                                            == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                            ? 0x50U
                                                            : 
                                                           ((2U 
                                                             == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                             ? 0x6bU
                                                             : 0x67U)))
                                                          : 
                                                         ((8U 
                                                           > __Vfunc_dr840_pclink__DOT__src__0__i)
                                                           ? 
                                                          ((6U 
                                                            == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                            ? 4U
                                                            : 
                                                           ((7U 
                                                             == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                             ? 4U
                                                             : 0U))
                                                           : 
                                                          ((0x800U 
                                                            & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                            ? 0U
                                                            : 
                                                           ((0x400U 
                                                             & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                             ? 0U
                                                             : 
                                                            ((0x200U 
                                                              & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                              ? 0U
                                                              : 
                                                             ((0x100U 
                                                               & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                               ? 0U
                                                               : 
                                                              ((0x80U 
                                                                & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                ? 0U
                                                                : 
                                                               ((0x40U 
                                                                 & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                 ? 0U
                                                                 : 
                                                                ((0x20U 
                                                                  & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                  ? 
                                                                 ((0x10U 
                                                                   & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                   ? 0U
                                                                   : 
                                                                  ((8U 
                                                                    & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                    ? 
                                                                   ((4U 
                                                                     & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                     ? 
                                                                    ((2U 
                                                                      & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                      ? 0U
                                                                      : 
                                                                     ((1U 
                                                                       & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                       ? 0x65U
                                                                       : 0U))
                                                                     : 
                                                                    ((2U 
                                                                      & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                      ? 
                                                                     ((1U 
                                                                       & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                       ? 0x67U
                                                                       : 0U)
                                                                      : 
                                                                     ((1U 
                                                                       & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                       ? 0x61U
                                                                       : 0U)))
                                                                    : 
                                                                   ((4U 
                                                                     & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                     ? 
                                                                    ((2U 
                                                                      & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                      ? 
                                                                     ((1U 
                                                                       & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                       ? 0x6bU
                                                                       : 0U)
                                                                      : 
                                                                     ((1U 
                                                                       & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                       ? 0x63U
                                                                       : 0U))
                                                                     : 
                                                                    ((2U 
                                                                      & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                      ? 
                                                                     ((1U 
                                                                       & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                       ? 0x61U
                                                                       : 0U)
                                                                      : 
                                                                     ((1U 
                                                                       & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                       ? 0x50U
                                                                       : 0U)))))
                                                                  : 
                                                                 ((0x10U 
                                                                   & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                   ? 
                                                                  ((8U 
                                                                    & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                    ? 
                                                                   ((4U 
                                                                     & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                     ? 
                                                                    ((2U 
                                                                      & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                      ? 
                                                                     ((1U 
                                                                       & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                       ? 7U
                                                                       : 0U)
                                                                      : 0U)
                                                                     : 0U)
                                                                    : 
                                                                   ((4U 
                                                                     & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                     ? 
                                                                    ((2U 
                                                                      & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                      ? 0U
                                                                      : 
                                                                     ((1U 
                                                                       & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                       ? 0U
                                                                       : 0x80U))
                                                                     : 0U))
                                                                   : 
                                                                  ((8U 
                                                                    & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                    ? 0U
                                                                    : 
                                                                   ((2U 
                                                                     & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                     ? 
                                                                    ((1U 
                                                                      & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                      ? __Vfunc_dr840_pclink__DOT__src__0__len
                                                                      : 
                                                                     (__Vfunc_dr840_pclink__DOT__src__0__len 
                                                                      >> 8U))
                                                                     : 
                                                                    ((1U 
                                                                      & (IData)(dr840_pclink__DOT__src__Vstatic__j))
                                                                      ? 
                                                                     (__Vfunc_dr840_pclink__DOT__src__0__len 
                                                                      >> 0x10U)
                                                                      : 
                                                                     (1U 
                                                                      & (__Vfunc_dr840_pclink__DOT__src__0__len 
                                                                         >> 0x18U)))))))))))))))
                                                         : 
                                                        ((0U 
                                                          == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                          ? 0x43U
                                                          : 
                                                         ((1U 
                                                           == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                           ? 0x6eU
                                                           : 
                                                          ((2U 
                                                            == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                            ? 0x74U
                                                            : 
                                                           ((3U 
                                                             == __Vfunc_dr840_pclink__DOT__src__0__i)
                                                             ? 0x64U
                                                             : 0U))))))));
    vlSelf->dr840_pclink__DOT__sb = __Vfunc_dr840_pclink__DOT__src__0__Vfuncout;
    vlSelf->dr840_pclink__DOT__rx_v = ((IData)(vlSelf->gtx_tog) 
                                       != (IData)(vlSelf->dr840_pclink__DOT__gtx_q));
    vlSelf->dr840_pclink__DOT__kind_len = ((1U == (IData)(vlSelf->dr840_pclink__DOT__seq_kind))
                                            ? 0x40cU
                                            : ((2U 
                                                == (IData)(vlSelf->dr840_pclink__DOT__seq_kind))
                                                ? vlSelf->pkg_len
                                                : (
                                                   (3U 
                                                    == (IData)(vlSelf->dr840_pclink__DOT__seq_kind))
                                                    ? 4U
                                                    : 8U)));
    vlSelf->dr840_pclink__DOT__feed_v = ((IData)(vlSelf->dr840_pclink__DOT__rx_v) 
                                         & ((IData)(vlSelf->dr840_pclink__DOT__greeted) 
                                            & ((2U 
                                                == (IData)(vlSelf->dr840_pclink__DOT__rx_st)) 
                                               & ((~ 
                                                   ((0x10U 
                                                     == (IData)(vlSelf->gtx_data)) 
                                                    | ((0xeU 
                                                        == (IData)(vlSelf->gtx_data)) 
                                                       | (0xfU 
                                                          == (IData)(vlSelf->gtx_data))))) 
                                                  | (IData)(vlSelf->dr840_pclink__DOT__escaped)))));
    vlSelf->dr840_pclink__DOT__dispatch = ((IData)(vlSelf->dr840_pclink__DOT__feed_v) 
                                           & (((~ (IData)(vlSelf->dr840_pclink__DOT__cmd_skip)) 
                                               & ((7U 
                                                   == (IData)(vlSelf->dr840_pclink__DOT__cmd_idx)) 
                                                  & (0U 
                                                     == vlSelf->dr840_pclink__DOT__cmd_len_now))) 
                                              | ((IData)(vlSelf->dr840_pclink__DOT__cmd_skip) 
                                                 & (1U 
                                                    == vlSelf->dr840_pclink__DOT__cmd_rem))));
}

VL_ATTR_COLD void Vdr840_pclink___024root___eval_stl(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vdr840_pclink___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vdr840_pclink___024root___eval_triggers__stl(Vdr840_pclink___024root* vlSelf);

VL_ATTR_COLD bool Vdr840_pclink___024root___eval_phase__stl(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vdr840_pclink___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vdr840_pclink___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_pclink___024root___dump_triggers__ico(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vdr840_pclink___024root___dump_triggers__act(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___dump_triggers__act\n"); );
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
VL_ATTR_COLD void Vdr840_pclink___024root___dump_triggers__nba(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___dump_triggers__nba\n"); );
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

VL_ATTR_COLD void Vdr840_pclink___024root___ctor_var_reset(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->cen = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->go_tog = VL_RAND_RESET_I(1);
    vlSelf->pkg_len = VL_RAND_RESET_I(25);
    vlSelf->wr_addr = VL_RAND_RESET_I(25);
    vlSelf->wr_data = VL_RAND_RESET_I(32);
    vlSelf->wr_req = VL_RAND_RESET_I(1);
    vlSelf->wr_ack = VL_RAND_RESET_I(1);
    vlSelf->pmem_addr = VL_RAND_RESET_I(25);
    vlSelf->pmem_req = VL_RAND_RESET_I(1);
    vlSelf->pmem_we = VL_RAND_RESET_I(1);
    vlSelf->pmem_wdata = VL_RAND_RESET_I(32);
    vlSelf->pmem_ack = VL_RAND_RESET_I(1);
    vlSelf->pmem_rdata = VL_RAND_RESET_I(32);
    vlSelf->gtx_tog = VL_RAND_RESET_I(1);
    vlSelf->gtx_data = VL_RAND_RESET_I(8);
    vlSelf->grx_tog = VL_RAND_RESET_I(1);
    vlSelf->grx_data = VL_RAND_RESET_I(8);
    vlSelf->grx_full = VL_RAND_RESET_I(1);
    vlSelf->uart_on = VL_RAND_RESET_I(1);
    vlSelf->bit_clocks = VL_RAND_RESET_I(20);
    vlSelf->state = VL_RAND_RESET_I(3);
    vlSelf->sent = VL_RAND_RESET_I(25);
    vlSelf->dr840_pclink__DOT__crc8__Vstatic__x = VL_RAND_RESET_I(32);
    vlSelf->dr840_pclink__DOT__frame_cen = VL_RAND_RESET_I(23);
    vlSelf->dr840_pclink__DOT__pace = VL_RAND_RESET_I(23);
    vlSelf->dr840_pclink__DOT__gtx_q = VL_RAND_RESET_I(1);
    vlSelf->dr840_pclink__DOT__rx_v = VL_RAND_RESET_I(1);
    vlSelf->dr840_pclink__DOT__greeted = VL_RAND_RESET_I(1);
    vlSelf->dr840_pclink__DOT__gshift = VL_RAND_RESET_I(32);
    vlSelf->dr840_pclink__DOT__rx_st = VL_RAND_RESET_I(3);
    vlSelf->dr840_pclink__DOT__rx_rem = VL_RAND_RESET_I(16);
    vlSelf->dr840_pclink__DOT__escaped = VL_RAND_RESET_I(1);
    vlSelf->dr840_pclink__DOT__cmd_idx = VL_RAND_RESET_I(3);
    vlSelf->dr840_pclink__DOT__cmd_skip = VL_RAND_RESET_I(1);
    vlSelf->dr840_pclink__DOT__cmd_tag = VL_RAND_RESET_I(32);
    vlSelf->dr840_pclink__DOT__cmd_rem = VL_RAND_RESET_I(32);
    vlSelf->dr840_pclink__DOT__offered = VL_RAND_RESET_I(1);
    vlSelf->dr840_pclink__DOT__pong_pend = VL_RAND_RESET_I(4);
    vlSelf->dr840_pclink__DOT__feed_v = VL_RAND_RESET_I(1);
    vlSelf->dr840_pclink__DOT__cmd_len_now = VL_RAND_RESET_I(32);
    vlSelf->dr840_pclink__DOT__dispatch = VL_RAND_RESET_I(1);
    vlSelf->dr840_pclink__DOT__tx_st = VL_RAND_RESET_I(4);
    vlSelf->dr840_pclink__DOT__mk = VL_RAND_RESET_I(3);
    vlSelf->dr840_pclink__DOT__seq = VL_RAND_RESET_I(3);
    vlSelf->dr840_pclink__DOT__msg_len = VL_RAND_RESET_I(25);
    vlSelf->dr840_pclink__DOT__mi = VL_RAND_RESET_I(25);
    vlSelf->dr840_pclink__DOT__at = VL_RAND_RESET_I(9);
    vlSelf->dr840_pclink__DOT__ridx = VL_RAND_RESET_I(9);
    vlSelf->dr840_pclink__DOT__crc = VL_RAND_RESET_I(32);
    vlSelf->dr840_pclink__DOT__q_pend = VL_RAND_RESET_I(1);
    vlSelf->dr840_pclink__DOT__idle_cnt = VL_RAND_RESET_I(16);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->dr840_pclink__DOT__blk[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->dr840_pclink__DOT__blk_q = VL_RAND_RESET_I(8);
    vlSelf->dr840_pclink__DOT__fill_we = VL_RAND_RESET_I(1);
    vlSelf->dr840_pclink__DOT__fill_b = VL_RAND_RESET_I(8);
    vlSelf->dr840_pclink__DOT__fill_at = VL_RAND_RESET_I(8);
    vlSelf->dr840_pclink__DOT__word = VL_RAND_RESET_I(32);
    vlSelf->dr840_pclink__DOT__word_addr = VL_RAND_RESET_I(23);
    vlSelf->dr840_pclink__DOT__word_ok = VL_RAND_RESET_I(1);
    vlSelf->dr840_pclink__DOT__reading = VL_RAND_RESET_I(1);
    vlSelf->dr840_pclink__DOT__sb = VL_RAND_RESET_I(8);
    vlSelf->dr840_pclink__DOT__have_word = VL_RAND_RESET_I(1);
    vlSelf->dr840_pclink__DOT__can_send = VL_RAND_RESET_I(1);
    vlSelf->dr840_pclink__DOT__next_seq = VL_RAND_RESET_I(1);
    vlSelf->dr840_pclink__DOT__seq_kind = VL_RAND_RESET_I(3);
    vlSelf->dr840_pclink__DOT__kind_len = VL_RAND_RESET_I(25);
    vlSelf->dr840_pclink__DOT__go_q = VL_RAND_RESET_I(1);
    vlSelf->__Vdlyvdim0__dr840_pclink__DOT__blk__v0 = 0;
    vlSelf->__Vdlyvval__dr840_pclink__DOT__blk__v0 = VL_RAND_RESET_I(8);
    vlSelf->__Vdlyvset__dr840_pclink__DOT__blk__v0 = 0;
    vlSelf->__Vdly__dr840_pclink__DOT__pace = VL_RAND_RESET_I(23);
    vlSelf->__Vdly__dr840_pclink__DOT__reading = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__wr_ack = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__dr840_pclink__DOT__rx_st = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__dr840_pclink__DOT__rx_rem = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__dr840_pclink__DOT__gshift = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__dr840_pclink__DOT__cmd_rem = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__dr840_pclink__DOT__cmd_idx = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__dr840_pclink__DOT__cmd_tag = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__dr840_pclink__DOT__offered = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__state = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__dr840_pclink__DOT__seq = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__dr840_pclink__DOT__pong_pend = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__dr840_pclink__DOT__tx_st = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__grx_tog = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__dr840_pclink__DOT__at = VL_RAND_RESET_I(9);
    vlSelf->__Vdly__dr840_pclink__DOT__crc = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__dr840_pclink__DOT__ridx = VL_RAND_RESET_I(9);
    vlSelf->__Vdly__dr840_pclink__DOT__idle_cnt = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__dr840_pclink__DOT__mi = VL_RAND_RESET_I(25);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
}
