// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdr840_ne2000.h for the primary calling header

#include "Vdr840_ne2000__pch.h"
#include "Vdr840_ne2000___024root.h"

VL_INLINE_OPT void Vdr840_ne2000___024root___ico_sequent__TOP__0(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->dr840_ne2000__DOT__pb_a = ((IData)(vlSelf->dr840_ne2000__DOT__wb)
                                        ? (IData)(vlSelf->dr840_ne2000__DOT__wb_a)
                                        : (IData)(vlSelf->b_addr));
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

void Vdr840_ne2000___024root___eval_ico(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vdr840_ne2000___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vdr840_ne2000___024root___eval_triggers__ico(Vdr840_ne2000___024root* vlSelf);

bool Vdr840_ne2000___024root___eval_phase__ico(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vdr840_ne2000___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vdr840_ne2000___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vdr840_ne2000___024root___eval_act(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vdr840_ne2000___024root___nba_sequent__TOP__0(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*5:0*/ __Vfunc_dr840_ne2000__DOT__mhash__4__Vfuncout;
    __Vfunc_dr840_ne2000__DOT__mhash__4__Vfuncout = 0;
    QData/*47:0*/ __Vfunc_dr840_ne2000__DOT__mhash__4__d;
    __Vfunc_dr840_ne2000__DOT__mhash__4__d = 0;
    // Body
    vlSelf->__Vdly__dr840_ne2000__DOT__r_k = vlSelf->dr840_ne2000__DOT__r_k;
    vlSelf->__Vdly__dr840_ne2000__DOT__r_crc = vlSelf->dr840_ne2000__DOT__r_crc;
    vlSelf->__Vdly__dr840_ne2000__DOT__r_group = vlSelf->dr840_ne2000__DOT__r_group;
    vlSelf->__Vdly__dr840_ne2000__DOT__r_page = vlSelf->dr840_ne2000__DOT__r_page;
    vlSelf->__Vdly__dr840_ne2000__DOT__r_next = vlSelf->dr840_ne2000__DOT__r_next;
    vlSelf->__Vdly__dr840_ne2000__DOT__r_cnt = vlSelf->dr840_ne2000__DOT__r_cnt;
    vlSelf->__Vdly__dr840_ne2000__DOT__r_pad = vlSelf->dr840_ne2000__DOT__r_pad;
    vlSelf->__Vdly__dr840_ne2000__DOT__r_n = vlSelf->dr840_ne2000__DOT__r_n;
    vlSelf->__Vdly__dr840_ne2000__DOT__r_len = vlSelf->dr840_ne2000__DOT__r_len;
    vlSelf->__Vdly__dr840_ne2000__DOT__tx_copied_ok 
        = vlSelf->dr840_ne2000__DOT__tx_copied_ok;
    vlSelf->__Vdly__dr840_ne2000__DOT__tx_copied = vlSelf->dr840_ne2000__DOT__tx_copied;
    vlSelf->__Vdly__dr840_ne2000__DOT__tx_wait = vlSelf->dr840_ne2000__DOT__tx_wait;
    vlSelf->__Vdly__tx_req = vlSelf->tx_req;
    vlSelf->__Vdly__dr840_ne2000__DOT__tx_pending = vlSelf->dr840_ne2000__DOT__tx_pending;
    vlSelf->__Vdly__dr840_ne2000__DOT__r_st = vlSelf->dr840_ne2000__DOT__r_st;
    vlSelf->__Vdly__dr840_ne2000__DOT__off_q = vlSelf->dr840_ne2000__DOT__off_q;
    vlSelf->__Vdly__dr840_ne2000__DOT__r_ptr = vlSelf->dr840_ne2000__DOT__r_ptr;
    vlSelf->__Vdly__dr840_ne2000__DOT__rcr = vlSelf->dr840_ne2000__DOT__rcr;
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v0 = 0U;
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v1 = 0U;
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v2 = 0U;
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v3 = 0U;
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v6 = 0U;
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__mar__v0 = 0U;
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__par__v0 = 0U;
    vlSelf->__Vdly__dr840_ne2000__DOT__curr = vlSelf->dr840_ne2000__DOT__curr;
    vlSelf->__Vdly__dr840_ne2000__DOT__cr = vlSelf->dr840_ne2000__DOT__cr;
    vlSelf->__Vdly__dr840_ne2000__DOT__rbcr = vlSelf->dr840_ne2000__DOT__rbcr;
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__par__v1 = 0U;
    vlSelf->__Vdlyvset__dr840_ne2000__DOT__par__v2 = 0U;
    if (vlSelf->rst_n) {
        if (vlSelf->cen) {
            if (((IData)(vlSelf->rx_offer) & (~ (IData)(vlSelf->rx_busy)))) {
                __Vfunc_dr840_ne2000__DOT__mhash__4__d 
                    = vlSelf->rx_dst;
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x28U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & (IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by))
                        ? 0xfffffffeU : 0xfb3ee249U);
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x28U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 1U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x28U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 2U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x28U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 3U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x28U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 4U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x28U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 5U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x28U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 6U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x28U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = (((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                         >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                      >> 7U)) ? (0x4c11db7U 
                                                 ^ 
                                                 (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                                  << 1U))
                        : (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                           << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x20U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ (IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x20U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 1U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x20U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 2U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x20U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 3U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x20U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 4U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x20U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 5U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x20U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 6U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x20U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = (((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                         >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                      >> 7U)) ? (0x4c11db7U 
                                                 ^ 
                                                 (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                                  << 1U))
                        : (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                           << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x18U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ (IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x18U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 1U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x18U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 2U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x18U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 3U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x18U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 4U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x18U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 5U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x18U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 6U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x18U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = (((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                         >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                      >> 7U)) ? (0x4c11db7U 
                                                 ^ 
                                                 (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                                  << 1U))
                        : (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                           << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x10U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ (IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x10U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 1U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x10U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 2U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x10U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 3U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x10U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 4U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x10U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 5U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x10U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 6U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 0x10U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = (((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                         >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                      >> 7U)) ? (0x4c11db7U 
                                                 ^ 
                                                 (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                                  << 1U))
                        : (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                           << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 8U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ (IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 8U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 1U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 8U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 2U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 8U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 3U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 8U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 4U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 8U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 5U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 8U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 6U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)((__Vfunc_dr840_ne2000__DOT__mhash__4__d 
                                        >> 8U)));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = (((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                         >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                      >> 7U)) ? (0x4c11db7U 
                                                 ^ 
                                                 (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                                  << 1U))
                        : (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                           << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ (IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 1U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 2U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 3U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 4U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 5U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = ((1U & ((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                               >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                            >> 6U)))
                        ? (0x4c11db7U ^ (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                         << 1U)) : 
                       (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                        << 1U));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by 
                    = (0xffU & (IData)(__Vfunc_dr840_ne2000__DOT__mhash__4__d));
                vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                    = (((vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                         >> 0x1fU) ^ ((IData)(vlSelf->dr840_ne2000__DOT__mhash__Vstatic__by) 
                                      >> 7U)) ? (0x4c11db7U 
                                                 ^ 
                                                 (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                                                  << 1U))
                        : (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                           << 1U));
                __Vfunc_dr840_ne2000__DOT__mhash__4__Vfuncout 
                    = (vlSelf->dr840_ne2000__DOT__mhash__Vstatic__c 
                       >> 0x1aU);
                vlSelf->dr840_ne2000__DOT__off_hash 
                    = __Vfunc_dr840_ne2000__DOT__mhash__4__Vfuncout;
            }
        }
    } else {
        vlSelf->dr840_ne2000__DOT__off_hash = 0U;
    }
}

VL_INLINE_OPT void Vdr840_ne2000___024root___nba_sequent__TOP__1(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___nba_sequent__TOP__1\n"); );
    // Init
    SData/*12:0*/ __Vdlyvdim0__dr840_ne2000__DOT__ram_e__v0;
    __Vdlyvdim0__dr840_ne2000__DOT__ram_e__v0 = 0;
    CData/*7:0*/ __Vdlyvval__dr840_ne2000__DOT__ram_e__v0;
    __Vdlyvval__dr840_ne2000__DOT__ram_e__v0 = 0;
    CData/*0:0*/ __Vdlyvset__dr840_ne2000__DOT__ram_e__v0;
    __Vdlyvset__dr840_ne2000__DOT__ram_e__v0 = 0;
    SData/*12:0*/ __Vdlyvdim0__dr840_ne2000__DOT__ram_o__v0;
    __Vdlyvdim0__dr840_ne2000__DOT__ram_o__v0 = 0;
    CData/*7:0*/ __Vdlyvval__dr840_ne2000__DOT__ram_o__v0;
    __Vdlyvval__dr840_ne2000__DOT__ram_o__v0 = 0;
    CData/*0:0*/ __Vdlyvset__dr840_ne2000__DOT__ram_o__v0;
    __Vdlyvset__dr840_ne2000__DOT__ram_o__v0 = 0;
    SData/*12:0*/ __Vdlyvdim0__dr840_ne2000__DOT__ram_e__v1;
    __Vdlyvdim0__dr840_ne2000__DOT__ram_e__v1 = 0;
    CData/*7:0*/ __Vdlyvval__dr840_ne2000__DOT__ram_e__v1;
    __Vdlyvval__dr840_ne2000__DOT__ram_e__v1 = 0;
    CData/*0:0*/ __Vdlyvset__dr840_ne2000__DOT__ram_e__v1;
    __Vdlyvset__dr840_ne2000__DOT__ram_e__v1 = 0;
    SData/*12:0*/ __Vdlyvdim0__dr840_ne2000__DOT__ram_o__v1;
    __Vdlyvdim0__dr840_ne2000__DOT__ram_o__v1 = 0;
    CData/*7:0*/ __Vdlyvval__dr840_ne2000__DOT__ram_o__v1;
    __Vdlyvval__dr840_ne2000__DOT__ram_o__v1 = 0;
    CData/*0:0*/ __Vdlyvset__dr840_ne2000__DOT__ram_o__v1;
    __Vdlyvset__dr840_ne2000__DOT__ram_o__v1 = 0;
    // Body
    __Vdlyvset__dr840_ne2000__DOT__ram_o__v0 = 0U;
    __Vdlyvset__dr840_ne2000__DOT__ram_e__v0 = 0U;
    __Vdlyvset__dr840_ne2000__DOT__ram_o__v1 = 0U;
    __Vdlyvset__dr840_ne2000__DOT__ram_e__v1 = 0U;
    if (vlSelf->dr840_ne2000__DOT__wa_o) {
        __Vdlyvval__dr840_ne2000__DOT__ram_o__v0 = vlSelf->dr840_ne2000__DOT__wa_o_d;
        __Vdlyvset__dr840_ne2000__DOT__ram_o__v0 = 1U;
        __Vdlyvdim0__dr840_ne2000__DOT__ram_o__v0 = vlSelf->dr840_ne2000__DOT__pa_o;
    }
    if (vlSelf->dr840_ne2000__DOT__wa_e) {
        __Vdlyvval__dr840_ne2000__DOT__ram_e__v0 = vlSelf->dr840_ne2000__DOT__wa_e_d;
        __Vdlyvset__dr840_ne2000__DOT__ram_e__v0 = 1U;
        __Vdlyvdim0__dr840_ne2000__DOT__ram_e__v0 = vlSelf->dr840_ne2000__DOT__pa_e;
    }
    if (((IData)(vlSelf->dr840_ne2000__DOT__wb) & (IData)(vlSelf->dr840_ne2000__DOT__wb_a))) {
        __Vdlyvval__dr840_ne2000__DOT__ram_o__v1 = vlSelf->dr840_ne2000__DOT__wb_d;
        __Vdlyvset__dr840_ne2000__DOT__ram_o__v1 = 1U;
        __Vdlyvdim0__dr840_ne2000__DOT__ram_o__v1 = 
            (0x1fffU & ((IData)(vlSelf->dr840_ne2000__DOT__pb_a) 
                        >> 1U));
    }
    if (((IData)(vlSelf->dr840_ne2000__DOT__wb) & (~ (IData)(vlSelf->dr840_ne2000__DOT__wb_a)))) {
        __Vdlyvval__dr840_ne2000__DOT__ram_e__v1 = vlSelf->dr840_ne2000__DOT__wb_d;
        __Vdlyvset__dr840_ne2000__DOT__ram_e__v1 = 1U;
        __Vdlyvdim0__dr840_ne2000__DOT__ram_e__v1 = 
            (0x1fffU & ((IData)(vlSelf->dr840_ne2000__DOT__pb_a) 
                        >> 1U));
    }
    vlSelf->dr840_ne2000__DOT__b_lsb = (1U & (IData)(vlSelf->dr840_ne2000__DOT__pb_a));
    vlSelf->dr840_ne2000__DOT__qb_o = vlSelf->dr840_ne2000__DOT__ram_o
        [(0x1fffU & ((IData)(vlSelf->dr840_ne2000__DOT__pb_a) 
                     >> 1U))];
    vlSelf->dr840_ne2000__DOT__qb_e = vlSelf->dr840_ne2000__DOT__ram_e
        [(0x1fffU & ((IData)(vlSelf->dr840_ne2000__DOT__pb_a) 
                     >> 1U))];
    vlSelf->dr840_ne2000__DOT__qa_o = vlSelf->dr840_ne2000__DOT__ram_o
        [vlSelf->dr840_ne2000__DOT__pa_o];
    vlSelf->dr840_ne2000__DOT__qa_e = vlSelf->dr840_ne2000__DOT__ram_e
        [vlSelf->dr840_ne2000__DOT__pa_e];
    if (__Vdlyvset__dr840_ne2000__DOT__ram_o__v0) {
        vlSelf->dr840_ne2000__DOT__ram_o[__Vdlyvdim0__dr840_ne2000__DOT__ram_o__v0] 
            = __Vdlyvval__dr840_ne2000__DOT__ram_o__v0;
    }
    if (__Vdlyvset__dr840_ne2000__DOT__ram_o__v1) {
        vlSelf->dr840_ne2000__DOT__ram_o[__Vdlyvdim0__dr840_ne2000__DOT__ram_o__v1] 
            = __Vdlyvval__dr840_ne2000__DOT__ram_o__v1;
    }
    if (__Vdlyvset__dr840_ne2000__DOT__ram_e__v0) {
        vlSelf->dr840_ne2000__DOT__ram_e[__Vdlyvdim0__dr840_ne2000__DOT__ram_e__v0] 
            = __Vdlyvval__dr840_ne2000__DOT__ram_e__v0;
    }
    if (__Vdlyvset__dr840_ne2000__DOT__ram_e__v1) {
        vlSelf->dr840_ne2000__DOT__ram_e[__Vdlyvdim0__dr840_ne2000__DOT__ram_e__v1] 
            = __Vdlyvval__dr840_ne2000__DOT__ram_e__v1;
    }
    vlSelf->b_q = ((IData)(vlSelf->dr840_ne2000__DOT__b_lsb)
                    ? (IData)(vlSelf->dr840_ne2000__DOT__qb_o)
                    : (IData)(vlSelf->dr840_ne2000__DOT__qb_e));
}

VL_INLINE_OPT void Vdr840_ne2000___024root___nba_sequent__TOP__2(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___nba_sequent__TOP__2\n"); );
    // Init
    SData/*8:0*/ dr840_ne2000__DOT__o_next0;
    dr840_ne2000__DOT__o_next0 = 0;
    IData/*31:0*/ __Vfunc_dr840_ne2000__DOT__crc8__5__Vfuncout;
    __Vfunc_dr840_ne2000__DOT__crc8__5__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_dr840_ne2000__DOT__crc8__5__c;
    __Vfunc_dr840_ne2000__DOT__crc8__5__c = 0;
    IData/*31:0*/ __Vfunc_dr840_ne2000__DOT__crc8__6__Vfuncout;
    __Vfunc_dr840_ne2000__DOT__crc8__6__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_dr840_ne2000__DOT__crc8__6__c;
    __Vfunc_dr840_ne2000__DOT__crc8__6__c = 0;
    CData/*7:0*/ __Vfunc_dr840_ne2000__DOT__crc8__6__b;
    __Vfunc_dr840_ne2000__DOT__crc8__6__b = 0;
    CData/*1:0*/ __Vdlyvdim0__dr840_ne2000__DOT__tally__v0;
    __Vdlyvdim0__dr840_ne2000__DOT__tally__v0 = 0;
    CData/*7:0*/ __Vdlyvval__dr840_ne2000__DOT__tally__v0;
    __Vdlyvval__dr840_ne2000__DOT__tally__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__dr840_ne2000__DOT__par__v0;
    __Vdlyvdim0__dr840_ne2000__DOT__par__v0 = 0;
    CData/*7:0*/ __Vdlyvval__dr840_ne2000__DOT__par__v0;
    __Vdlyvval__dr840_ne2000__DOT__par__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__dr840_ne2000__DOT__mar__v0;
    __Vdlyvdim0__dr840_ne2000__DOT__mar__v0 = 0;
    CData/*7:0*/ __Vdlyvval__dr840_ne2000__DOT__mar__v0;
    __Vdlyvval__dr840_ne2000__DOT__mar__v0 = 0;
    CData/*7:0*/ __Vdlyvval__dr840_ne2000__DOT__tally__v1;
    __Vdlyvval__dr840_ne2000__DOT__tally__v1 = 0;
    CData/*7:0*/ __Vdlyvval__dr840_ne2000__DOT__tally__v2;
    __Vdlyvval__dr840_ne2000__DOT__tally__v2 = 0;
    // Body
    if (vlSelf->rst_n) {
        vlSelf->dr840_ne2000__DOT__wa_e = 0U;
        vlSelf->dr840_ne2000__DOT__wa_o = 0U;
        vlSelf->dr840_ne2000__DOT__wb = 0U;
        if (vlSelf->cen) {
            vlSelf->rx_answer = 0U;
            vlSelf->dr840_ne2000__DOT__iset = 0U;
            vlSelf->dr840_ne2000__DOT__iclr = 0U;
            vlSelf->dr840_ne2000__DOT__nreset = 0U;
            if (vlSelf->acc) {
                if ((0x10U == (IData)(vlSelf->port))) {
                    if (vlSelf->we) {
                        if (vlSelf->dr840_ne2000__DOT__dma_wr_ok) {
                            if (((0x4000U <= (IData)(vlSelf->dr840_ne2000__DOT__rsar)) 
                                 & (0x8000U > (IData)(vlSelf->dr840_ne2000__DOT__rsar)))) {
                                if ((1U & (IData)(vlSelf->dr840_ne2000__DOT__rsar))) {
                                    vlSelf->dr840_ne2000__DOT__wa_o = 1U;
                                    vlSelf->dr840_ne2000__DOT__wa_o_i 
                                        = (0x1fffU 
                                           & ((IData)(vlSelf->dr840_ne2000__DOT__rsar) 
                                              >> 1U));
                                    vlSelf->dr840_ne2000__DOT__wa_o_d 
                                        = (0xffU & 
                                           ((IData)(vlSelf->wide)
                                             ? ((IData)(vlSelf->wdata) 
                                                >> 8U)
                                             : (IData)(vlSelf->wdata)));
                                } else {
                                    vlSelf->dr840_ne2000__DOT__wa_e = 1U;
                                    vlSelf->dr840_ne2000__DOT__wa_e_i 
                                        = (0x1fffU 
                                           & ((IData)(vlSelf->dr840_ne2000__DOT__rsar) 
                                              >> 1U));
                                    vlSelf->dr840_ne2000__DOT__wa_e_d 
                                        = (0xffU & 
                                           ((IData)(vlSelf->wide)
                                             ? ((IData)(vlSelf->wdata) 
                                                >> 8U)
                                             : (IData)(vlSelf->wdata)));
                                }
                            }
                            if (((IData)(vlSelf->wide) 
                                 & (1U != (IData)(vlSelf->dr840_ne2000__DOT__rbcr)))) {
                                vlSelf->__Vdly__dr840_ne2000__DOT__rbcr 
                                    = (0xffffU & ((IData)(vlSelf->dr840_ne2000__DOT__rbcr) 
                                                  - (IData)(2U)));
                                if ((2U == (IData)(vlSelf->dr840_ne2000__DOT__rbcr))) {
                                    vlSelf->dr840_ne2000__DOT__iset 
                                        = (0x40U | (IData)(vlSelf->dr840_ne2000__DOT__iset));
                                }
                                if (((0x4000U <= (IData)(vlSelf->dr840_ne2000__DOT__rsar_n)) 
                                     & (0x8000U > (IData)(vlSelf->dr840_ne2000__DOT__rsar_n)))) {
                                    if ((1U & (IData)(vlSelf->dr840_ne2000__DOT__rsar_n))) {
                                        vlSelf->dr840_ne2000__DOT__wa_o = 1U;
                                        vlSelf->dr840_ne2000__DOT__wa_o_i 
                                            = (0x1fffU 
                                               & ((IData)(vlSelf->dr840_ne2000__DOT__rsar_n) 
                                                  >> 1U));
                                        vlSelf->dr840_ne2000__DOT__wa_o_d 
                                            = (0xffU 
                                               & (IData)(vlSelf->wdata));
                                    } else {
                                        vlSelf->dr840_ne2000__DOT__wa_e = 1U;
                                        vlSelf->dr840_ne2000__DOT__wa_e_i 
                                            = (0x1fffU 
                                               & ((IData)(vlSelf->dr840_ne2000__DOT__rsar_n) 
                                                  >> 1U));
                                        vlSelf->dr840_ne2000__DOT__wa_e_d 
                                            = (0xffU 
                                               & (IData)(vlSelf->wdata));
                                    }
                                }
                                vlSelf->dr840_ne2000__DOT__rsar 
                                    = (0xffffU & ((
                                                   ((IData)(vlSelf->dr840_ne2000__DOT__pstop) 
                                                    > (IData)(vlSelf->dr840_ne2000__DOT__pstart)) 
                                                   & ((0xffffU 
                                                       & ((IData)(1U) 
                                                          + (IData)(vlSelf->dr840_ne2000__DOT__rsar_n))) 
                                                      == 
                                                      ((IData)(vlSelf->dr840_ne2000__DOT__pstop) 
                                                       << 8U)))
                                                   ? 
                                                  ((IData)(vlSelf->dr840_ne2000__DOT__pstart) 
                                                   << 8U)
                                                   : 
                                                  ((IData)(1U) 
                                                   + (IData)(vlSelf->dr840_ne2000__DOT__rsar_n))));
                            } else {
                                vlSelf->__Vdly__dr840_ne2000__DOT__rbcr 
                                    = (0xffffU & ((IData)(vlSelf->dr840_ne2000__DOT__rbcr) 
                                                  - (IData)(1U)));
                                if ((1U == (IData)(vlSelf->dr840_ne2000__DOT__rbcr))) {
                                    vlSelf->dr840_ne2000__DOT__iset 
                                        = (0x40U | (IData)(vlSelf->dr840_ne2000__DOT__iset));
                                }
                                vlSelf->dr840_ne2000__DOT__rsar 
                                    = vlSelf->dr840_ne2000__DOT__rsar_n;
                            }
                        }
                    } else if (vlSelf->dr840_ne2000__DOT__dma_rd_ok) {
                        if (((IData)(vlSelf->wide) 
                             & (1U != (IData)(vlSelf->dr840_ne2000__DOT__rbcr)))) {
                            vlSelf->__Vdly__dr840_ne2000__DOT__rbcr 
                                = (0xffffU & ((IData)(vlSelf->dr840_ne2000__DOT__rbcr) 
                                              - (IData)(2U)));
                            if ((2U == (IData)(vlSelf->dr840_ne2000__DOT__rbcr))) {
                                vlSelf->dr840_ne2000__DOT__iset 
                                    = (0x40U | (IData)(vlSelf->dr840_ne2000__DOT__iset));
                            }
                            vlSelf->dr840_ne2000__DOT__rsar 
                                = (0xffffU & ((((IData)(vlSelf->dr840_ne2000__DOT__pstop) 
                                                > (IData)(vlSelf->dr840_ne2000__DOT__pstart)) 
                                               & ((0xffffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->dr840_ne2000__DOT__rsar_n))) 
                                                  == 
                                                  ((IData)(vlSelf->dr840_ne2000__DOT__pstop) 
                                                   << 8U)))
                                               ? ((IData)(vlSelf->dr840_ne2000__DOT__pstart) 
                                                  << 8U)
                                               : ((IData)(1U) 
                                                  + (IData)(vlSelf->dr840_ne2000__DOT__rsar_n))));
                        } else {
                            vlSelf->__Vdly__dr840_ne2000__DOT__rbcr 
                                = (0xffffU & ((IData)(vlSelf->dr840_ne2000__DOT__rbcr) 
                                              - (IData)(1U)));
                            if ((1U == (IData)(vlSelf->dr840_ne2000__DOT__rbcr))) {
                                vlSelf->dr840_ne2000__DOT__iset 
                                    = (0x40U | (IData)(vlSelf->dr840_ne2000__DOT__iset));
                            }
                            vlSelf->dr840_ne2000__DOT__rsar 
                                = vlSelf->dr840_ne2000__DOT__rsar_n;
                        }
                    }
                } else if ((((~ (IData)(vlSelf->we)) 
                             & (~ (IData)(vlSelf->wide))) 
                            & (0x1fU == (IData)(vlSelf->port)))) {
                    vlSelf->dr840_ne2000__DOT__nreset = 1U;
                } else if ((((((~ (IData)(vlSelf->we)) 
                               & (~ (IData)(vlSelf->wide))) 
                              & (0xcU == (0x1cU & (IData)(vlSelf->port)))) 
                             & (0U == (0xc0U & (IData)(vlSelf->dr840_ne2000__DOT__cr)))) 
                            & (0U != (3U & (IData)(vlSelf->port))))) {
                    vlSelf->dr840_ne2000__DOT____Vlvbound_h66bf5d70__0 = 0U;
                    if ((2U >= (3U & ((IData)(vlSelf->port) 
                                      - (IData)(1U))))) {
                        __Vdlyvval__dr840_ne2000__DOT__tally__v0 
                            = vlSelf->dr840_ne2000__DOT____Vlvbound_h66bf5d70__0;
                        vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v0 = 1U;
                        __Vdlyvdim0__dr840_ne2000__DOT__tally__v0 
                            = (3U & ((IData)(vlSelf->port) 
                                     - (IData)(1U)));
                    }
                } else if ((((IData)(vlSelf->we) & 
                             (~ (IData)(vlSelf->wide))) 
                            & (0U == (IData)(vlSelf->port)))) {
                    vlSelf->dr840_ne2000__DOT__v = 
                        (0xffU & (IData)(vlSelf->wdata));
                    vlSelf->dr840_ne2000__DOT__started 
                        = (1U & ((IData)(vlSelf->dr840_ne2000__DOT__cr) 
                                 >> 1U));
                    vlSelf->__Vdly__dr840_ne2000__DOT__cr 
                        = (((0xfbU & (IData)(vlSelf->dr840_ne2000__DOT__v)) 
                            | ((IData)(vlSelf->dr840_ne2000__DOT__tx_pending)
                                ? 4U : 0U)) | ((1U 
                                                & (IData)(vlSelf->dr840_ne2000__DOT__v))
                                                ? ((IData)(vlSelf->dr840_ne2000__DOT__started) 
                                                   << 1U)
                                                : 0U));
                    if ((1U & (IData)(vlSelf->dr840_ne2000__DOT__v))) {
                        if ((1U & (~ (IData)(vlSelf->dr840_ne2000__DOT__tx_pending)))) {
                            vlSelf->dr840_ne2000__DOT__iset 
                                = (0x80U | (IData)(vlSelf->dr840_ne2000__DOT__iset));
                        }
                    } else if ((2U & (IData)(vlSelf->dr840_ne2000__DOT__v))) {
                        vlSelf->dr840_ne2000__DOT__iclr 
                            = (0x80U | (IData)(vlSelf->dr840_ne2000__DOT__iclr));
                    }
                    if ((IData)(((8U == (0x38U & (IData)(vlSelf->dr840_ne2000__DOT__v))) 
                                 & (0U == (IData)(vlSelf->dr840_ne2000__DOT__rbcr))))) {
                        vlSelf->dr840_ne2000__DOT__iset 
                            = (0x40U | (IData)(vlSelf->dr840_ne2000__DOT__iset));
                    }
                    if (((((IData)(vlSelf->dr840_ne2000__DOT__v) 
                           >> 2U) & (2U == (3U & ((0xfbU 
                                                   & (IData)(vlSelf->dr840_ne2000__DOT__v)) 
                                                  | ((1U 
                                                      & (IData)(vlSelf->dr840_ne2000__DOT__v))
                                                      ? 
                                                     ((IData)(vlSelf->dr840_ne2000__DOT__started) 
                                                      << 1U)
                                                      : 0U))))) 
                         & (~ (IData)(vlSelf->dr840_ne2000__DOT__tx_pending)))) {
                        if (((((0x4000U > ((IData)(vlSelf->dr840_ne2000__DOT__tpsr) 
                                           << 8U)) 
                               | (0x8000U < (0xffffU 
                                             & (((IData)(vlSelf->dr840_ne2000__DOT__tpsr) 
                                                 << 8U) 
                                                + (IData)(vlSelf->dr840_ne2000__DOT__tbcr))))) 
                              | (0xeU > (IData)(vlSelf->dr840_ne2000__DOT__tbcr))) 
                             | (0x5eeU < (IData)(vlSelf->dr840_ne2000__DOT__tbcr)))) {
                            vlSelf->dr840_ne2000__DOT__iset 
                                = (8U | (IData)(vlSelf->dr840_ne2000__DOT__iset));
                            vlSelf->dr840_ne2000__DOT__tsr = 8U;
                            vlSelf->__Vdly__dr840_ne2000__DOT__cr 
                                = ((0xfbU & (IData)(vlSelf->dr840_ne2000__DOT__v)) 
                                   | ((1U & (IData)(vlSelf->dr840_ne2000__DOT__v))
                                       ? ((IData)(vlSelf->dr840_ne2000__DOT__started) 
                                          << 1U) : 0U));
                        } else {
                            vlSelf->__Vdly__dr840_ne2000__DOT__cr 
                                = (4U | ((0xfbU & (IData)(vlSelf->dr840_ne2000__DOT__v)) 
                                         | ((1U & (IData)(vlSelf->dr840_ne2000__DOT__v))
                                             ? ((IData)(vlSelf->dr840_ne2000__DOT__started) 
                                                << 1U)
                                             : 0U)));
                            vlSelf->__Vdly__dr840_ne2000__DOT__tx_pending = 1U;
                            vlSelf->__Vdly__tx_req = 1U;
                            vlSelf->tx_base = (0x3f00U 
                                               & ((IData)(vlSelf->dr840_ne2000__DOT__tpsr) 
                                                  << 8U));
                            vlSelf->tx_len = (0x7ffU 
                                              & (IData)(vlSelf->dr840_ne2000__DOT__tbcr));
                            vlSelf->__Vdly__dr840_ne2000__DOT__tx_wait 
                                = (0xffffU & ((IData)(0x25U) 
                                              * (0xffffU 
                                                 & ((IData)(0x18U) 
                                                    + (IData)(vlSelf->dr840_ne2000__DOT__tbcr)))));
                            vlSelf->__Vdly__dr840_ne2000__DOT__tx_copied = 0U;
                        }
                    }
                } else if ((((IData)(vlSelf->we) & 
                             (~ (IData)(vlSelf->wide))) 
                            & (~ ((IData)(vlSelf->port) 
                                  >> 4U)))) {
                    vlSelf->dr840_ne2000__DOT__v = 
                        (0xffU & (IData)(vlSelf->wdata));
                    if ((0U == (3U & ((IData)(vlSelf->dr840_ne2000__DOT__cr) 
                                      >> 6U)))) {
                        if ((8U & (IData)(vlSelf->port))) {
                            if ((4U & (IData)(vlSelf->port))) {
                                if ((2U & (IData)(vlSelf->port))) {
                                    if ((1U & (IData)(vlSelf->port))) {
                                        vlSelf->dr840_ne2000__DOT__imr 
                                            = (0x7fU 
                                               & (IData)(vlSelf->dr840_ne2000__DOT__v));
                                    } else {
                                        vlSelf->dr840_ne2000__DOT__dcr 
                                            = vlSelf->dr840_ne2000__DOT__v;
                                    }
                                } else if ((1U & (IData)(vlSelf->port))) {
                                    vlSelf->dr840_ne2000__DOT__tcr 
                                        = vlSelf->dr840_ne2000__DOT__v;
                                } else {
                                    vlSelf->__Vdly__dr840_ne2000__DOT__rcr 
                                        = vlSelf->dr840_ne2000__DOT__v;
                                }
                            } else if ((2U & (IData)(vlSelf->port))) {
                                vlSelf->__Vdly__dr840_ne2000__DOT__rbcr 
                                    = ((1U & (IData)(vlSelf->port))
                                        ? ((0xffU & (IData)(vlSelf->__Vdly__dr840_ne2000__DOT__rbcr)) 
                                           | ((IData)(vlSelf->dr840_ne2000__DOT__v) 
                                              << 8U))
                                        : ((0xff00U 
                                            & (IData)(vlSelf->__Vdly__dr840_ne2000__DOT__rbcr)) 
                                           | (IData)(vlSelf->dr840_ne2000__DOT__v)));
                            } else {
                                vlSelf->dr840_ne2000__DOT__rsar 
                                    = ((1U & (IData)(vlSelf->port))
                                        ? ((0xffU & (IData)(vlSelf->dr840_ne2000__DOT__rsar)) 
                                           | ((IData)(vlSelf->dr840_ne2000__DOT__v) 
                                              << 8U))
                                        : ((0xff00U 
                                            & (IData)(vlSelf->dr840_ne2000__DOT__rsar)) 
                                           | (IData)(vlSelf->dr840_ne2000__DOT__v)));
                            }
                        } else if ((4U & (IData)(vlSelf->port))) {
                            if ((2U & (IData)(vlSelf->port))) {
                                if ((1U & (IData)(vlSelf->port))) {
                                    vlSelf->dr840_ne2000__DOT__iclr 
                                        = ((IData)(vlSelf->dr840_ne2000__DOT__iclr) 
                                           | (0x7fU 
                                              & (IData)(vlSelf->dr840_ne2000__DOT__v)));
                                } else {
                                    vlSelf->dr840_ne2000__DOT__tbcr 
                                        = ((0xffU & (IData)(vlSelf->dr840_ne2000__DOT__tbcr)) 
                                           | ((IData)(vlSelf->dr840_ne2000__DOT__v) 
                                              << 8U));
                                }
                            } else if ((1U & (IData)(vlSelf->port))) {
                                vlSelf->dr840_ne2000__DOT__tbcr 
                                    = ((0xff00U & (IData)(vlSelf->dr840_ne2000__DOT__tbcr)) 
                                       | (IData)(vlSelf->dr840_ne2000__DOT__v));
                            } else {
                                vlSelf->dr840_ne2000__DOT__tpsr 
                                    = vlSelf->dr840_ne2000__DOT__v;
                            }
                        } else if ((2U & (IData)(vlSelf->port))) {
                            if ((1U & (IData)(vlSelf->port))) {
                                vlSelf->dr840_ne2000__DOT__bnry 
                                    = vlSelf->dr840_ne2000__DOT__v;
                            } else {
                                vlSelf->dr840_ne2000__DOT__pstop 
                                    = vlSelf->dr840_ne2000__DOT__v;
                            }
                        } else if ((1U & (IData)(vlSelf->port))) {
                            vlSelf->dr840_ne2000__DOT__pstart 
                                = vlSelf->dr840_ne2000__DOT__v;
                        }
                    } else if ((1U == (3U & ((IData)(vlSelf->dr840_ne2000__DOT__cr) 
                                             >> 6U)))) {
                        if (((1U <= (0xfU & (IData)(vlSelf->port))) 
                             & (6U >= (0xfU & (IData)(vlSelf->port))))) {
                            vlSelf->dr840_ne2000__DOT____Vlvbound_h9fb8493e__0 
                                = vlSelf->dr840_ne2000__DOT__v;
                            if ((5U >= (7U & ((IData)(vlSelf->port) 
                                              - (IData)(1U))))) {
                                __Vdlyvval__dr840_ne2000__DOT__par__v0 
                                    = vlSelf->dr840_ne2000__DOT____Vlvbound_h9fb8493e__0;
                                vlSelf->__Vdlyvset__dr840_ne2000__DOT__par__v0 = 1U;
                                __Vdlyvdim0__dr840_ne2000__DOT__par__v0 
                                    = (7U & ((IData)(vlSelf->port) 
                                             - (IData)(1U)));
                            }
                        } else if ((7U == (0xfU & (IData)(vlSelf->port)))) {
                            vlSelf->__Vdly__dr840_ne2000__DOT__curr 
                                = vlSelf->dr840_ne2000__DOT__v;
                        } else if ((8U <= (0xfU & (IData)(vlSelf->port)))) {
                            __Vdlyvval__dr840_ne2000__DOT__mar__v0 
                                = vlSelf->dr840_ne2000__DOT__v;
                            vlSelf->__Vdlyvset__dr840_ne2000__DOT__mar__v0 = 1U;
                            __Vdlyvdim0__dr840_ne2000__DOT__mar__v0 
                                = (7U & (IData)(vlSelf->port));
                        }
                    }
                }
            }
            if (vlSelf->board_reset) {
                vlSelf->dr840_ne2000__DOT__nreset = 1U;
            }
            if (((IData)(vlSelf->tx_req) & (IData)(vlSelf->tx_done))) {
                vlSelf->__Vdly__tx_req = 0U;
                vlSelf->__Vdly__dr840_ne2000__DOT__tx_copied = 1U;
                vlSelf->__Vdly__dr840_ne2000__DOT__tx_copied_ok 
                    = vlSelf->tx_ok;
            }
            if (((IData)(vlSelf->dr840_ne2000__DOT__tx_pending) 
                 & (0U != (IData)(vlSelf->dr840_ne2000__DOT__tx_wait)))) {
                vlSelf->__Vdly__dr840_ne2000__DOT__tx_wait 
                    = (0xffffU & ((IData)(vlSelf->dr840_ne2000__DOT__tx_wait) 
                                  - (IData)(1U)));
            }
            if (((((IData)(vlSelf->dr840_ne2000__DOT__tx_pending) 
                   & (IData)(vlSelf->dr840_ne2000__DOT__tx_copied)) 
                  & (0U == (IData)(vlSelf->dr840_ne2000__DOT__tx_wait))) 
                 & (~ (((IData)(vlSelf->acc) & (IData)(vlSelf->we)) 
                       & (0U == (IData)(vlSelf->port)))))) {
                vlSelf->__Vdly__dr840_ne2000__DOT__cr 
                    = (0xfbU & (IData)(vlSelf->dr840_ne2000__DOT__cr));
                vlSelf->__Vdly__dr840_ne2000__DOT__tx_pending = 0U;
                vlSelf->__Vdly__dr840_ne2000__DOT__tx_copied = 0U;
                if (vlSelf->dr840_ne2000__DOT__tx_copied_ok) {
                    vlSelf->dr840_ne2000__DOT__tsr = 1U;
                    vlSelf->dbg_tx = ((IData)(1U) + vlSelf->dbg_tx);
                } else {
                    vlSelf->dr840_ne2000__DOT__tsr = 0x10U;
                }
                vlSelf->dr840_ne2000__DOT__iset = (
                                                   ((IData)(vlSelf->dr840_ne2000__DOT__iset) 
                                                    | ((IData)(vlSelf->dr840_ne2000__DOT__tx_copied_ok)
                                                        ? 2U
                                                        : 8U)) 
                                                   | ((1U 
                                                       & (IData)(vlSelf->dr840_ne2000__DOT__cr))
                                                       ? 0x80U
                                                       : 0U));
            }
            if (((IData)(vlSelf->rx_offer) & (~ (IData)(vlSelf->rx_busy)))) {
                vlSelf->__Vdly__dr840_ne2000__DOT__off_q = 1U;
            }
            if (vlSelf->dr840_ne2000__DOT__off_q) {
                vlSelf->__Vdly__dr840_ne2000__DOT__off_q = 0U;
                vlSelf->rx_answer = 1U;
                vlSelf->rx_take = 0U;
                if ((1U & (~ (((2U != (3U & (IData)(vlSelf->dr840_ne2000__DOT__cr))) 
                               | (0xeU > (IData)(vlSelf->dr840_ne2000__DOT__off_len))) 
                              | (0x5eeU < (IData)(vlSelf->dr840_ne2000__DOT__off_len)))))) {
                    if (vlSelf->dr840_ne2000__DOT__o_acc) {
                        if ((0x20U & (IData)(vlSelf->dr840_ne2000__DOT__rcr))) {
                            if ((0x7fU == vlSelf->dr840_ne2000__DOT__tally
                                 [2U])) {
                                vlSelf->dr840_ne2000__DOT__iset 
                                    = (0x20U | (IData)(vlSelf->dr840_ne2000__DOT__iset));
                            }
                            __Vdlyvval__dr840_ne2000__DOT__tally__v1 
                                = (0xffU & ((IData)(1U) 
                                            + vlSelf->dr840_ne2000__DOT__tally
                                            [2U]));
                            vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v1 = 1U;
                        } else if (vlSelf->dr840_ne2000__DOT__o_ring_ok) {
                            if ((1U & (((IData)(vlSelf->dr840_ne2000__DOT__isr) 
                                        >> 4U) | ((IData)(vlSelf->dr840_ne2000__DOT__o_bnry_in) 
                                                  & ((0xffU 
                                                      & VL_SHIFTR_III(12,12,32, 
                                                                      (0xfffU 
                                                                       & ((IData)(0x107U) 
                                                                          + (IData)(vlSelf->dr840_ne2000__DOT__o_pad))), 8U)) 
                                                     >= (IData)(vlSelf->dr840_ne2000__DOT__o_avail)))))) {
                                vlSelf->dr840_ne2000__DOT__iset 
                                    = (0x10U | (IData)(vlSelf->dr840_ne2000__DOT__iset));
                                vlSelf->dr840_ne2000__DOT__rsr = 0x10U;
                                if ((0x7fU == vlSelf->dr840_ne2000__DOT__tally
                                     [2U])) {
                                    vlSelf->dr840_ne2000__DOT__iset 
                                        = (0x20U | (IData)(vlSelf->dr840_ne2000__DOT__iset));
                                }
                                __Vdlyvval__dr840_ne2000__DOT__tally__v2 
                                    = (0xffU & ((IData)(1U) 
                                                + vlSelf->dr840_ne2000__DOT__tally
                                                [2U]));
                                vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v2 = 1U;
                            } else {
                                vlSelf->rx_take = 1U;
                                vlSelf->__Vdly__dr840_ne2000__DOT__r_st = 1U;
                                vlSelf->__Vdly__dr840_ne2000__DOT__r_len 
                                    = vlSelf->dr840_ne2000__DOT__off_len;
                                vlSelf->__Vdly__dr840_ne2000__DOT__r_n = 0U;
                                vlSelf->__Vdly__dr840_ne2000__DOT__r_pad 
                                    = vlSelf->dr840_ne2000__DOT__o_pad;
                                vlSelf->__Vdly__dr840_ne2000__DOT__r_cnt 
                                    = (0xfffU & ((IData)(4U) 
                                                 + (IData)(vlSelf->dr840_ne2000__DOT__o_pad)));
                                vlSelf->__Vdly__dr840_ne2000__DOT__r_next 
                                    = vlSelf->dr840_ne2000__DOT__o_next;
                                vlSelf->__Vdly__dr840_ne2000__DOT__r_page 
                                    = vlSelf->dr840_ne2000__DOT__curr;
                                vlSelf->__Vdly__dr840_ne2000__DOT__r_group 
                                    = (1U & (IData)(
                                                    (vlSelf->dr840_ne2000__DOT__off_dst 
                                                     >> 0x28U)));
                                vlSelf->__Vdly__dr840_ne2000__DOT__r_crc = 0xffffffffU;
                                vlSelf->__Vdly__dr840_ne2000__DOT__r_k = 0U;
                                vlSelf->__Vdly__dr840_ne2000__DOT__r_ptr 
                                    = (4U | ((IData)(vlSelf->dr840_ne2000__DOT__curr) 
                                             << 8U));
                            }
                        }
                    }
                }
            }
            if (((IData)(vlSelf->rx_offer) & (~ (IData)(vlSelf->rx_busy)))) {
                vlSelf->dr840_ne2000__DOT__off_dst 
                    = vlSelf->rx_dst;
                vlSelf->dr840_ne2000__DOT__off_len 
                    = vlSelf->rx_len;
            }
            if ((4U & (IData)(vlSelf->dr840_ne2000__DOT__r_st))) {
                if ((1U & (~ ((IData)(vlSelf->dr840_ne2000__DOT__r_st) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelf->dr840_ne2000__DOT__r_st)))) {
                        vlSelf->dr840_ne2000__DOT__wb = 1U;
                        vlSelf->dr840_ne2000__DOT__wb_a 
                            = ((0x3f00U & ((IData)(vlSelf->dr840_ne2000__DOT__r_page) 
                                           << 8U)) 
                               | (IData)(vlSelf->dr840_ne2000__DOT__r_k));
                        vlSelf->dr840_ne2000__DOT__wb_d 
                            = (0xffU & ((0U == (IData)(vlSelf->dr840_ne2000__DOT__r_k))
                                         ? (1U | ((IData)(vlSelf->dr840_ne2000__DOT__r_group)
                                                   ? 0x20U
                                                   : 0U))
                                         : ((1U == (IData)(vlSelf->dr840_ne2000__DOT__r_k))
                                             ? (IData)(vlSelf->dr840_ne2000__DOT__r_next)
                                             : ((2U 
                                                 == (IData)(vlSelf->dr840_ne2000__DOT__r_k))
                                                 ? (IData)(vlSelf->dr840_ne2000__DOT__r_cnt)
                                                 : 
                                                (0xfU 
                                                 & ((IData)(vlSelf->dr840_ne2000__DOT__r_cnt) 
                                                    >> 8U))))));
                        vlSelf->__Vdly__dr840_ne2000__DOT__r_k 
                            = (3U & ((IData)(1U) + (IData)(vlSelf->dr840_ne2000__DOT__r_k)));
                        if ((3U == (IData)(vlSelf->dr840_ne2000__DOT__r_k))) {
                            vlSelf->dr840_ne2000__DOT__iset 
                                = (1U | (IData)(vlSelf->dr840_ne2000__DOT__iset));
                            vlSelf->dbg_rx = ((IData)(1U) 
                                              + vlSelf->dbg_rx);
                            vlSelf->__Vdly__dr840_ne2000__DOT__r_st = 0U;
                            vlSelf->__Vdly__dr840_ne2000__DOT__curr 
                                = vlSelf->dr840_ne2000__DOT__r_next;
                            vlSelf->dr840_ne2000__DOT__rsr 
                                = (1U | ((IData)(vlSelf->dr840_ne2000__DOT__r_group)
                                          ? 0x20U : 0U));
                        }
                    }
                }
            } else if ((2U & (IData)(vlSelf->dr840_ne2000__DOT__r_st))) {
                if ((1U & (IData)(vlSelf->dr840_ne2000__DOT__r_st))) {
                    vlSelf->dr840_ne2000__DOT__wb = 1U;
                    vlSelf->dr840_ne2000__DOT__wb_a 
                        = (0x3fffU & (IData)(vlSelf->dr840_ne2000__DOT__r_ptr));
                    vlSelf->dr840_ne2000__DOT__wb_d 
                        = (0xffU & (~ (vlSelf->dr840_ne2000__DOT__r_crc 
                                       >> (0x1fU & 
                                           VL_SHIFTL_III(5,32,32, (IData)(vlSelf->dr840_ne2000__DOT__r_k), 3U)))));
                    vlSelf->__Vdly__dr840_ne2000__DOT__r_ptr 
                        = vlSelf->dr840_ne2000__DOT__r_ptr_n;
                    vlSelf->__Vdly__dr840_ne2000__DOT__r_k 
                        = (3U & ((IData)(1U) + (IData)(vlSelf->dr840_ne2000__DOT__r_k)));
                    if ((3U == (IData)(vlSelf->dr840_ne2000__DOT__r_k))) {
                        vlSelf->__Vdly__dr840_ne2000__DOT__r_st = 4U;
                        vlSelf->__Vdly__dr840_ne2000__DOT__r_k = 0U;
                    }
                } else {
                    __Vfunc_dr840_ne2000__DOT__crc8__5__c 
                        = vlSelf->dr840_ne2000__DOT__r_crc;
                    vlSelf->__Vdly__dr840_ne2000__DOT__r_n 
                        = (0x7ffU & ((IData)(1U) + (IData)(vlSelf->dr840_ne2000__DOT__r_n)));
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = __Vfunc_dr840_ne2000__DOT__crc8__5__c;
                    vlSelf->dr840_ne2000__DOT__wb = 1U;
                    vlSelf->dr840_ne2000__DOT__wb_a 
                        = (0x3fffU & (IData)(vlSelf->dr840_ne2000__DOT__r_ptr));
                    vlSelf->dr840_ne2000__DOT__wb_d = 0U;
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    if (((0x7ffU & ((IData)(1U) + (IData)(vlSelf->dr840_ne2000__DOT__r_n))) 
                         == (IData)(vlSelf->dr840_ne2000__DOT__r_pad))) {
                        vlSelf->__Vdly__dr840_ne2000__DOT__r_st = 3U;
                    }
                    vlSelf->__Vdly__dr840_ne2000__DOT__r_ptr 
                        = vlSelf->dr840_ne2000__DOT__r_ptr_n;
                    __Vfunc_dr840_ne2000__DOT__crc8__5__Vfuncout 
                        = vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x;
                    vlSelf->__Vdly__dr840_ne2000__DOT__r_crc 
                        = __Vfunc_dr840_ne2000__DOT__crc8__5__Vfuncout;
                }
            } else if ((1U & (IData)(vlSelf->dr840_ne2000__DOT__r_st))) {
                if (vlSelf->rx_byte) {
                    __Vfunc_dr840_ne2000__DOT__crc8__6__b 
                        = vlSelf->rx_data;
                    vlSelf->__Vdly__dr840_ne2000__DOT__r_n 
                        = (0x7ffU & ((IData)(1U) + (IData)(vlSelf->dr840_ne2000__DOT__r_n)));
                    __Vfunc_dr840_ne2000__DOT__crc8__6__c 
                        = vlSelf->dr840_ne2000__DOT__r_crc;
                    vlSelf->dr840_ne2000__DOT__wb = 1U;
                    vlSelf->dr840_ne2000__DOT__wb_a 
                        = (0x3fffU & (IData)(vlSelf->dr840_ne2000__DOT__r_ptr));
                    vlSelf->dr840_ne2000__DOT__wb_d 
                        = vlSelf->rx_data;
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = (__Vfunc_dr840_ne2000__DOT__crc8__6__c 
                           ^ (IData)(__Vfunc_dr840_ne2000__DOT__crc8__6__b));
                    if (((0x7ffU & ((IData)(1U) + (IData)(vlSelf->dr840_ne2000__DOT__r_n))) 
                         == (IData)(vlSelf->dr840_ne2000__DOT__r_len))) {
                        vlSelf->__Vdly__dr840_ne2000__DOT__r_st 
                            = (((IData)(vlSelf->dr840_ne2000__DOT__r_len) 
                                < (IData)(vlSelf->dr840_ne2000__DOT__r_pad))
                                ? 2U : 3U);
                    }
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->__Vdly__dr840_ne2000__DOT__r_ptr 
                        = vlSelf->dr840_ne2000__DOT__r_ptr_n;
                    __Vfunc_dr840_ne2000__DOT__crc8__6__Vfuncout 
                        = vlSelf->dr840_ne2000__DOT__crc8__Vstatic__x;
                    vlSelf->__Vdly__dr840_ne2000__DOT__r_crc 
                        = __Vfunc_dr840_ne2000__DOT__crc8__6__Vfuncout;
                }
            }
            vlSelf->dr840_ne2000__DOT__isr = (((IData)(vlSelf->dr840_ne2000__DOT__isr) 
                                               & (~ (IData)(vlSelf->dr840_ne2000__DOT__iclr))) 
                                              | (IData)(vlSelf->dr840_ne2000__DOT__iset));
            if (vlSelf->dr840_ne2000__DOT__nreset) {
                vlSelf->__Vdly__dr840_ne2000__DOT__cr = 0x21U;
                vlSelf->dr840_ne2000__DOT__isr = 0x80U;
                vlSelf->dr840_ne2000__DOT__imr = 0U;
                vlSelf->__Vdly__dr840_ne2000__DOT__rbcr = 0U;
                vlSelf->dr840_ne2000__DOT__tsr = 0U;
                vlSelf->dr840_ne2000__DOT__rsr = 0U;
                vlSelf->__Vdly__dr840_ne2000__DOT__tx_pending = 0U;
                vlSelf->__Vdly__tx_req = 0U;
                vlSelf->__Vdly__dr840_ne2000__DOT__tx_copied = 0U;
                vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v3 = 1U;
            }
        }
    } else {
        vlSelf->__Vdly__dr840_ne2000__DOT__curr = 0U;
        vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v6 = 1U;
        vlSelf->__Vdly__tx_req = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__tx_copied = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__off_q = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__r_st = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__r_ptr = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__r_n = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__r_crc = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__r_k = 0U;
        vlSelf->dbg_rx = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__cr = 0x21U;
        vlSelf->dr840_ne2000__DOT__isr = 0x80U;
        vlSelf->dr840_ne2000__DOT__imr = 0U;
        vlSelf->dr840_ne2000__DOT__dcr = 4U;
        vlSelf->__Vdly__dr840_ne2000__DOT__rcr = 0U;
        vlSelf->dr840_ne2000__DOT__tcr = 0U;
        vlSelf->dr840_ne2000__DOT__tsr = 0U;
        vlSelf->dr840_ne2000__DOT__rsr = 0U;
        vlSelf->dr840_ne2000__DOT__pstart = 0U;
        vlSelf->dr840_ne2000__DOT__pstop = 0U;
        vlSelf->dr840_ne2000__DOT__bnry = 0U;
        vlSelf->dr840_ne2000__DOT__tpsr = 0U;
        vlSelf->dr840_ne2000__DOT__rsar = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__rbcr = 0U;
        vlSelf->dr840_ne2000__DOT__tbcr = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__tx_pending = 0U;
        vlSelf->__Vdlyvset__dr840_ne2000__DOT__par__v1 = 1U;
        vlSelf->dr840_ne2000__DOT__wa_e = 0U;
        vlSelf->dr840_ne2000__DOT__wa_o = 0U;
        vlSelf->dr840_ne2000__DOT__wa_e_i = 0U;
        vlSelf->dr840_ne2000__DOT__wa_o_i = 0U;
        vlSelf->dr840_ne2000__DOT__wa_e_d = 0U;
        vlSelf->dr840_ne2000__DOT__wa_o_d = 0U;
        vlSelf->dr840_ne2000__DOT__wb = 0U;
        vlSelf->dr840_ne2000__DOT__wb_a = 0U;
        vlSelf->dr840_ne2000__DOT__wb_d = 0U;
        vlSelf->tx_base = 0U;
        vlSelf->tx_len = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__tx_wait = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__tx_copied_ok = 0U;
        vlSelf->rx_answer = 0U;
        vlSelf->rx_take = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__r_len = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__r_pad = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__r_cnt = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__r_next = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__r_page = 0U;
        vlSelf->__Vdly__dr840_ne2000__DOT__r_group = 0U;
        vlSelf->dbg_tx = 0U;
        vlSelf->__Vdlyvset__dr840_ne2000__DOT__par__v2 = 1U;
        vlSelf->dr840_ne2000__DOT__off_dst = 0ULL;
        vlSelf->dr840_ne2000__DOT__off_len = 0U;
    }
    vlSelf->dr840_ne2000__DOT__tx_pending = vlSelf->__Vdly__dr840_ne2000__DOT__tx_pending;
    vlSelf->tx_req = vlSelf->__Vdly__tx_req;
    vlSelf->dr840_ne2000__DOT__tx_wait = vlSelf->__Vdly__dr840_ne2000__DOT__tx_wait;
    vlSelf->dr840_ne2000__DOT__tx_copied = vlSelf->__Vdly__dr840_ne2000__DOT__tx_copied;
    vlSelf->dr840_ne2000__DOT__tx_copied_ok = vlSelf->__Vdly__dr840_ne2000__DOT__tx_copied_ok;
    vlSelf->dr840_ne2000__DOT__r_len = vlSelf->__Vdly__dr840_ne2000__DOT__r_len;
    vlSelf->dr840_ne2000__DOT__r_n = vlSelf->__Vdly__dr840_ne2000__DOT__r_n;
    vlSelf->dr840_ne2000__DOT__r_pad = vlSelf->__Vdly__dr840_ne2000__DOT__r_pad;
    vlSelf->dr840_ne2000__DOT__r_cnt = vlSelf->__Vdly__dr840_ne2000__DOT__r_cnt;
    vlSelf->dr840_ne2000__DOT__r_next = vlSelf->__Vdly__dr840_ne2000__DOT__r_next;
    vlSelf->dr840_ne2000__DOT__r_page = vlSelf->__Vdly__dr840_ne2000__DOT__r_page;
    vlSelf->dr840_ne2000__DOT__r_group = vlSelf->__Vdly__dr840_ne2000__DOT__r_group;
    vlSelf->dr840_ne2000__DOT__r_crc = vlSelf->__Vdly__dr840_ne2000__DOT__r_crc;
    vlSelf->dr840_ne2000__DOT__r_k = vlSelf->__Vdly__dr840_ne2000__DOT__r_k;
    vlSelf->dr840_ne2000__DOT__off_q = vlSelf->__Vdly__dr840_ne2000__DOT__off_q;
    vlSelf->dr840_ne2000__DOT__r_st = vlSelf->__Vdly__dr840_ne2000__DOT__r_st;
    vlSelf->dr840_ne2000__DOT__r_ptr = vlSelf->__Vdly__dr840_ne2000__DOT__r_ptr;
    vlSelf->dr840_ne2000__DOT__rcr = vlSelf->__Vdly__dr840_ne2000__DOT__rcr;
    vlSelf->dr840_ne2000__DOT__curr = vlSelf->__Vdly__dr840_ne2000__DOT__curr;
    vlSelf->dr840_ne2000__DOT__rbcr = vlSelf->__Vdly__dr840_ne2000__DOT__rbcr;
    vlSelf->dr840_ne2000__DOT__cr = vlSelf->__Vdly__dr840_ne2000__DOT__cr;
    if (vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v0) {
        vlSelf->dr840_ne2000__DOT__tally[__Vdlyvdim0__dr840_ne2000__DOT__tally__v0] 
            = __Vdlyvval__dr840_ne2000__DOT__tally__v0;
    }
    if (vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v1) {
        vlSelf->dr840_ne2000__DOT__tally[2U] = __Vdlyvval__dr840_ne2000__DOT__tally__v1;
    }
    if (vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v2) {
        vlSelf->dr840_ne2000__DOT__tally[2U] = __Vdlyvval__dr840_ne2000__DOT__tally__v2;
    }
    if (vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v3) {
        vlSelf->dr840_ne2000__DOT__tally[0U] = 0U;
        vlSelf->dr840_ne2000__DOT__tally[1U] = 0U;
        vlSelf->dr840_ne2000__DOT__tally[2U] = 0U;
    }
    if (vlSelf->__Vdlyvset__dr840_ne2000__DOT__tally__v6) {
        vlSelf->dr840_ne2000__DOT__tally[0U] = 0U;
    }
    if (vlSelf->__Vdlyvset__dr840_ne2000__DOT__mar__v0) {
        vlSelf->dr840_ne2000__DOT__mar[__Vdlyvdim0__dr840_ne2000__DOT__mar__v0] 
            = __Vdlyvval__dr840_ne2000__DOT__mar__v0;
    }
    if (vlSelf->__Vdlyvset__dr840_ne2000__DOT__par__v1) {
        vlSelf->dr840_ne2000__DOT__tally[1U] = 0U;
        vlSelf->dr840_ne2000__DOT__mar[0U] = 0U;
    }
    if (vlSelf->__Vdlyvset__dr840_ne2000__DOT__par__v0) {
        vlSelf->dr840_ne2000__DOT__par[__Vdlyvdim0__dr840_ne2000__DOT__par__v0] 
            = __Vdlyvval__dr840_ne2000__DOT__par__v0;
    }
    if (vlSelf->__Vdlyvset__dr840_ne2000__DOT__par__v1) {
        vlSelf->dr840_ne2000__DOT__par[0U] = 0U;
    }
    if (vlSelf->__Vdlyvset__dr840_ne2000__DOT__par__v2) {
        vlSelf->dr840_ne2000__DOT__tally[2U] = 0U;
        vlSelf->dr840_ne2000__DOT__mar[1U] = 0U;
        vlSelf->dr840_ne2000__DOT__mar[2U] = 0U;
        vlSelf->dr840_ne2000__DOT__mar[3U] = 0U;
        vlSelf->dr840_ne2000__DOT__mar[4U] = 0U;
        vlSelf->dr840_ne2000__DOT__mar[5U] = 0U;
        vlSelf->dr840_ne2000__DOT__mar[6U] = 0U;
        vlSelf->dr840_ne2000__DOT__mar[7U] = 0U;
        vlSelf->dr840_ne2000__DOT__par[1U] = 0U;
        vlSelf->dr840_ne2000__DOT__par[2U] = 0U;
        vlSelf->dr840_ne2000__DOT__par[3U] = 0U;
        vlSelf->dr840_ne2000__DOT__par[4U] = 0U;
        vlSelf->dr840_ne2000__DOT__par[5U] = 0U;
    }
    vlSelf->dr840_ne2000__DOT__pb_a = ((IData)(vlSelf->dr840_ne2000__DOT__wb)
                                        ? (IData)(vlSelf->dr840_ne2000__DOT__wb_a)
                                        : (IData)(vlSelf->b_addr));
    vlSelf->irq = (0U != (0x7fU & ((IData)(vlSelf->dr840_ne2000__DOT__imr) 
                                   & (IData)(vlSelf->dr840_ne2000__DOT__isr))));
    vlSelf->dr840_ne2000__DOT__dma_wr_ok = (IData)(
                                                   ((0x10U 
                                                     == 
                                                     (0x38U 
                                                      & (IData)(vlSelf->dr840_ne2000__DOT__cr))) 
                                                    & (0U 
                                                       != (IData)(vlSelf->dr840_ne2000__DOT__rbcr))));
    vlSelf->dr840_ne2000__DOT__dma_rd_ok = (IData)(
                                                   ((8U 
                                                     == 
                                                     (0x38U 
                                                      & (IData)(vlSelf->dr840_ne2000__DOT__cr))) 
                                                    & (0U 
                                                       != (IData)(vlSelf->dr840_ne2000__DOT__rbcr))));
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
    vlSelf->rx_busy = ((0U != (IData)(vlSelf->dr840_ne2000__DOT__r_st)) 
                       | (IData)(vlSelf->dr840_ne2000__DOT__off_q));
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
                                                       & ((IData)(vlSelf->dr840_ne2000__DOT__off_hash) 
                                                          >> 3U))] 
                                                      >> 
                                                      (7U 
                                                       & (IData)(vlSelf->dr840_ne2000__DOT__off_hash))))
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
    vlSelf->dr840_ne2000__DOT__o_pad = ((0x3cU > (IData)(vlSelf->dr840_ne2000__DOT__off_len))
                                         ? 0x3cU : (IData)(vlSelf->dr840_ne2000__DOT__off_len));
    dr840_ne2000__DOT__o_next0 = (0x1ffU & ((IData)(vlSelf->dr840_ne2000__DOT__curr) 
                                            + (0xffU 
                                               & VL_SHIFTR_III(12,12,32, 
                                                               (0xfffU 
                                                                & ((IData)(0x107U) 
                                                                   + (IData)(vlSelf->dr840_ne2000__DOT__o_pad))), 8U))));
    vlSelf->dr840_ne2000__DOT__o_next = (0xffU & (((IData)(dr840_ne2000__DOT__o_next0) 
                                                   >= (IData)(vlSelf->dr840_ne2000__DOT__pstop))
                                                   ? 
                                                  ((IData)(dr840_ne2000__DOT__o_next0) 
                                                   - 
                                                   ((IData)(vlSelf->dr840_ne2000__DOT__pstop) 
                                                    - (IData)(vlSelf->dr840_ne2000__DOT__pstart)))
                                                   : (IData)(dr840_ne2000__DOT__o_next0)));
}

VL_INLINE_OPT void Vdr840_ne2000___024root___nba_comb__TOP__0(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___nba_comb__TOP__0\n"); );
    // Init
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
    // Body
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

void Vdr840_ne2000___024root___eval_nba(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vdr840_ne2000___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vdr840_ne2000___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vdr840_ne2000___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vdr840_ne2000___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vdr840_ne2000___024root___eval_triggers__act(Vdr840_ne2000___024root* vlSelf);

bool Vdr840_ne2000___024root___eval_phase__act(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vdr840_ne2000___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vdr840_ne2000___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vdr840_ne2000___024root___eval_phase__nba(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vdr840_ne2000___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_ne2000___024root___dump_triggers__ico(Vdr840_ne2000___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_ne2000___024root___dump_triggers__nba(Vdr840_ne2000___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_ne2000___024root___dump_triggers__act(Vdr840_ne2000___024root* vlSelf);
#endif  // VL_DEBUG

void Vdr840_ne2000___024root___eval(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vdr840_ne2000___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../../rtl/soc/dr840_ne2000.sv", 22, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vdr840_ne2000___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vdr840_ne2000___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../../rtl/soc/dr840_ne2000.sv", 22, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vdr840_ne2000___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../../rtl/soc/dr840_ne2000.sv", 22, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vdr840_ne2000___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vdr840_ne2000___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vdr840_ne2000___024root___eval_debug_assertions(Vdr840_ne2000___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_ne2000__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_ne2000___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->cen & 0xfeU))) {
        Verilated::overWidthError("cen");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->acc & 0xfeU))) {
        Verilated::overWidthError("acc");}
    if (VL_UNLIKELY((vlSelf->we & 0xfeU))) {
        Verilated::overWidthError("we");}
    if (VL_UNLIKELY((vlSelf->port & 0xe0U))) {
        Verilated::overWidthError("port");}
    if (VL_UNLIKELY((vlSelf->wide & 0xfeU))) {
        Verilated::overWidthError("wide");}
    if (VL_UNLIKELY((vlSelf->board_reset & 0xfeU))) {
        Verilated::overWidthError("board_reset");}
    if (VL_UNLIKELY((vlSelf->tx_done & 0xfeU))) {
        Verilated::overWidthError("tx_done");}
    if (VL_UNLIKELY((vlSelf->tx_ok & 0xfeU))) {
        Verilated::overWidthError("tx_ok");}
    if (VL_UNLIKELY((vlSelf->rx_offer & 0xfeU))) {
        Verilated::overWidthError("rx_offer");}
    if (VL_UNLIKELY((vlSelf->rx_len & 0xf800U))) {
        Verilated::overWidthError("rx_len");}
    if (VL_UNLIKELY((vlSelf->rx_dst & 0ULL))) {
        Verilated::overWidthError("rx_dst");}
    if (VL_UNLIKELY((vlSelf->rx_byte & 0xfeU))) {
        Verilated::overWidthError("rx_byte");}
    if (VL_UNLIKELY((vlSelf->b_addr & 0xc000U))) {
        Verilated::overWidthError("b_addr");}
}
#endif  // VL_DEBUG
