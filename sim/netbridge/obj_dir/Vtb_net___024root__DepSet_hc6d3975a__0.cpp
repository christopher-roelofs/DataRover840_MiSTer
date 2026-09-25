// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_net.h for the primary calling header

#include "Vtb_net__pch.h"
#include "Vtb_net___024root.h"

VL_INLINE_OPT void Vtb_net___024root___ico_sequent__TOP__0(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->tb_net__DOT____Vcellinp__nic__acc = ((IData)(vlSelf->acc) 
                                                 & (IData)(vlSelf->tb_net__DOT__cen));
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

void Vtb_net___024root___eval_ico(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vtb_net___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtb_net___024root___eval_triggers__ico(Vtb_net___024root* vlSelf);

bool Vtb_net___024root___eval_phase__ico(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtb_net___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vtb_net___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtb_net___024root___eval_act(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtb_net___024root___nba_sequent__TOP__0(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*28:0*/ __Vfunc_tb_net__DOT__br__DOT__slot_word__7__Vfuncout;
    __Vfunc_tb_net__DOT__br__DOT__slot_word__7__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_net__DOT__br__DOT__slot_word__7__ctr;
    __Vfunc_tb_net__DOT__br__DOT__slot_word__7__ctr = 0;
    SData/*10:0*/ __Vfunc_tb_net__DOT__br__DOT__slot_word__7__byte_off;
    __Vfunc_tb_net__DOT__br__DOT__slot_word__7__byte_off = 0;
    IData/*28:0*/ __Vfunc_tb_net__DOT__br__DOT__slot_word__8__Vfuncout;
    __Vfunc_tb_net__DOT__br__DOT__slot_word__8__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_net__DOT__br__DOT__slot_word__8__ctr;
    __Vfunc_tb_net__DOT__br__DOT__slot_word__8__ctr = 0;
    IData/*28:0*/ __Vfunc_tb_net__DOT__br__DOT__slot_word__9__Vfuncout;
    __Vfunc_tb_net__DOT__br__DOT__slot_word__9__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_net__DOT__br__DOT__slot_word__9__ctr;
    __Vfunc_tb_net__DOT__br__DOT__slot_word__9__ctr = 0;
    IData/*28:0*/ __Vfunc_tb_net__DOT__br__DOT__slot_word__10__Vfuncout;
    __Vfunc_tb_net__DOT__br__DOT__slot_word__10__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_net__DOT__br__DOT__slot_word__10__ctr;
    __Vfunc_tb_net__DOT__br__DOT__slot_word__10__ctr = 0;
    SData/*10:0*/ __Vfunc_tb_net__DOT__br__DOT__slot_word__10__byte_off;
    __Vfunc_tb_net__DOT__br__DOT__slot_word__10__byte_off = 0;
    IData/*28:0*/ __Vfunc_tb_net__DOT__br__DOT__slot_word__11__Vfuncout;
    __Vfunc_tb_net__DOT__br__DOT__slot_word__11__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_net__DOT__br__DOT__slot_word__11__ctr;
    __Vfunc_tb_net__DOT__br__DOT__slot_word__11__ctr = 0;
    CData/*4:0*/ __Vdly__tb_net__DOT__br__DOT__st;
    __Vdly__tb_net__DOT__br__DOT__st = 0;
    IData/*31:0*/ __Vdly__tb_net__DOT__br__DOT__t_count;
    __Vdly__tb_net__DOT__br__DOT__t_count = 0;
    CData/*5:0*/ __Vdly__tb_net__DOT__br__DOT__tq_r;
    __Vdly__tb_net__DOT__br__DOT__tq_r = 0;
    CData/*4:0*/ __Vdly__tb_net__DOT__br__DOT__ret;
    __Vdly__tb_net__DOT__br__DOT__ret = 0;
    CData/*0:0*/ __Vdly__ddr_rd;
    __Vdly__ddr_rd = 0;
    CData/*0:0*/ __Vdly__link;
    __Vdly__link = 0;
    QData/*63:0*/ __Vdly__tb_net__DOT__br__DOT__acc;
    __Vdly__tb_net__DOT__br__DOT__acc = 0;
    IData/*31:0*/ __Vdly__tb_net__DOT__br__DOT__rx_tail;
    __Vdly__tb_net__DOT__br__DOT__rx_tail = 0;
    SData/*10:0*/ __Vdly__tb_net__DOT__br__DOT__n;
    __Vdly__tb_net__DOT__br__DOT__n = 0;
    CData/*2:0*/ __Vdly__tb_net__DOT__br__DOT__lanes;
    __Vdly__tb_net__DOT__br__DOT__lanes = 0;
    IData/*31:0*/ __Vdly__tb_net__DOT__br__DOT__tx_head;
    __Vdly__tb_net__DOT__br__DOT__tx_head = 0;
    CData/*1:0*/ __Vdly__tb_net__DOT__br__DOT__bw;
    __Vdly__tb_net__DOT__br__DOT__bw = 0;
    IData/*31:0*/ __Vdly__tb_net__DOT__br__DOT__rx_head;
    __Vdly__tb_net__DOT__br__DOT__rx_head = 0;
    IData/*31:0*/ __Vdly__tb_net__DOT__br__DOT__tx_tail;
    __Vdly__tb_net__DOT__br__DOT__tx_tail = 0;
    IData/*19:0*/ __Vdly__tb_net__DOT__br__DOT__poll_cnt;
    __Vdly__tb_net__DOT__br__DOT__poll_cnt = 0;
    // Body
    vlSelf->__Vdly__tb_net__DOT__cen = vlSelf->tb_net__DOT__cen;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_k = vlSelf->tb_net__DOT__nic__DOT__r_k;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_crc = vlSelf->tb_net__DOT__nic__DOT__r_crc;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_group 
        = vlSelf->tb_net__DOT__nic__DOT__r_group;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_page = vlSelf->tb_net__DOT__nic__DOT__r_page;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_next = vlSelf->tb_net__DOT__nic__DOT__r_next;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_cnt = vlSelf->tb_net__DOT__nic__DOT__r_cnt;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_pad = vlSelf->tb_net__DOT__nic__DOT__r_pad;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_n = vlSelf->tb_net__DOT__nic__DOT__r_n;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_len = vlSelf->tb_net__DOT__nic__DOT__r_len;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_copied_ok 
        = vlSelf->tb_net__DOT__nic__DOT__tx_copied_ok;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_copied 
        = vlSelf->tb_net__DOT__nic__DOT__tx_copied;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_wait 
        = vlSelf->tb_net__DOT__nic__DOT__tx_wait;
    vlSelf->__Vdly__tb_net__DOT__tx_req = vlSelf->tb_net__DOT__tx_req;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_pending 
        = vlSelf->tb_net__DOT__nic__DOT__tx_pending;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_st = vlSelf->tb_net__DOT__nic__DOT__r_st;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__off_q = vlSelf->tb_net__DOT__nic__DOT__off_q;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_ptr = vlSelf->tb_net__DOT__nic__DOT__r_ptr;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__rcr = vlSelf->tb_net__DOT__nic__DOT__rcr;
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v0 = 0U;
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v1 = 0U;
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v2 = 0U;
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v3 = 0U;
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v6 = 0U;
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__mar__v0 = 0U;
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__par__v0 = 0U;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__curr = vlSelf->tb_net__DOT__nic__DOT__curr;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__cr = vlSelf->tb_net__DOT__nic__DOT__cr;
    vlSelf->__Vdly__tb_net__DOT__nic__DOT__rbcr = vlSelf->tb_net__DOT__nic__DOT__rbcr;
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__par__v1 = 0U;
    vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__par__v2 = 0U;
    __Vdly__tb_net__DOT__br__DOT__poll_cnt = vlSelf->tb_net__DOT__br__DOT__poll_cnt;
    __Vdly__tb_net__DOT__br__DOT__tx_tail = vlSelf->tb_net__DOT__br__DOT__tx_tail;
    __Vdly__tb_net__DOT__br__DOT__rx_head = vlSelf->tb_net__DOT__br__DOT__rx_head;
    __Vdly__tb_net__DOT__br__DOT__bw = vlSelf->tb_net__DOT__br__DOT__bw;
    __Vdly__tb_net__DOT__br__DOT__tx_head = vlSelf->tb_net__DOT__br__DOT__tx_head;
    vlSelf->__Vdly__tb_net__DOT__tx_ok = vlSelf->tb_net__DOT__tx_ok;
    vlSelf->__Vdly__tb_net__DOT__rx_len = vlSelf->tb_net__DOT__rx_len;
    vlSelf->__Vdly__tb_net__DOT__rx_dst = vlSelf->tb_net__DOT__rx_dst;
    vlSelf->__Vdly__tb_net__DOT__rx_data = vlSelf->tb_net__DOT__rx_data;
    __Vdly__tb_net__DOT__br__DOT__lanes = vlSelf->tb_net__DOT__br__DOT__lanes;
    __Vdly__tb_net__DOT__br__DOT__n = vlSelf->tb_net__DOT__br__DOT__n;
    __Vdly__tb_net__DOT__br__DOT__rx_tail = vlSelf->tb_net__DOT__br__DOT__rx_tail;
    __Vdly__tb_net__DOT__br__DOT__acc = vlSelf->tb_net__DOT__br__DOT__acc;
    __Vdly__link = vlSelf->link;
    __Vdly__ddr_rd = vlSelf->ddr_rd;
    __Vdly__tb_net__DOT__br__DOT__ret = vlSelf->tb_net__DOT__br__DOT__ret;
    __Vdly__tb_net__DOT__br__DOT__tq_r = vlSelf->tb_net__DOT__br__DOT__tq_r;
    __Vdly__tb_net__DOT__br__DOT__t_count = vlSelf->tb_net__DOT__br__DOT__t_count;
    __Vdly__tb_net__DOT__br__DOT__st = vlSelf->tb_net__DOT__br__DOT__st;
    vlSelf->__Vdly__tb_net__DOT__rx_byte = vlSelf->tb_net__DOT__rx_byte;
    vlSelf->__Vdly__tb_net__DOT__rx_offer = vlSelf->tb_net__DOT__rx_offer;
    vlSelf->__Vdly__tb_net__DOT__tx_done = vlSelf->tb_net__DOT__tx_done;
    if (vlSelf->rst_n) {
        vlSelf->__Vdly__tb_net__DOT__cen = (1U & (~ (IData)(vlSelf->tb_net__DOT__cen)));
        if (vlSelf->tb_net__DOT__cen) {
            vlSelf->__Vdly__tb_net__DOT__tx_done = 0U;
            vlSelf->__Vdly__tb_net__DOT__rx_offer = 0U;
            vlSelf->__Vdly__tb_net__DOT__rx_byte = 0U;
        }
        if (vlSelf->enable) {
            if ((0x10U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                if ((8U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                    __Vdly__tb_net__DOT__br__DOT__st = 0U;
                } else if ((4U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                    if ((2U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                        if ((1U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                            __Vdly__tb_net__DOT__br__DOT__t_count 
                                = ((IData)(1U) + vlSelf->tb_net__DOT__br__DOT__t_count);
                            __Vdly__tb_net__DOT__br__DOT__tq_r 
                                = (0x3fU & ((IData)(1U) 
                                            + (IData)(vlSelf->tb_net__DOT__br__DOT__tq_r)));
                            vlSelf->ddr_addr = 0x7000007U;
                            vlSelf->ddr_din = (QData)((IData)(
                                                              ((IData)(1U) 
                                                               + vlSelf->tb_net__DOT__br__DOT__t_count)));
                            vlSelf->ddr_we = 1U;
                            __Vdly__tb_net__DOT__br__DOT__st = 0x12U;
                            __Vdly__tb_net__DOT__br__DOT__ret = 0U;
                        } else {
                            vlSelf->ddr_addr = 0x7000005U;
                            __Vdly__ddr_rd = 1U;
                            __Vdly__tb_net__DOT__br__DOT__st = 0x11U;
                            __Vdly__tb_net__DOT__br__DOT__ret = 0x13U;
                        }
                    } else if ((1U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                        __Vdly__link = ((IData)(vlSelf->tb_net__DOT__br__DOT__magic_ok) 
                                        & ((IData)(vlSelf->tb_net__DOT__br__DOT__acc) 
                                           == vlSelf->tb_net__DOT__br__DOT__epoch));
                        vlSelf->ddr_addr = 0x7000002U;
                        __Vdly__ddr_rd = 1U;
                        __Vdly__tb_net__DOT__br__DOT__st = 0x11U;
                        __Vdly__tb_net__DOT__br__DOT__ret = 2U;
                    } else {
                        __Vdly__tb_net__DOT__br__DOT__st = 0U;
                    }
                } else if ((2U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                    if ((1U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                        vlSelf->tb_net__DOT__br__DOT__epoch 
                            = ((IData)(1U) + (IData)(vlSelf->tb_net__DOT__br__DOT__acc));
                        vlSelf->ddr_addr = 0x7000005U;
                        vlSelf->ddr_din = (QData)((IData)(
                                                          ((IData)(1U) 
                                                           + (IData)(vlSelf->tb_net__DOT__br__DOT__acc))));
                        vlSelf->ddr_we = 1U;
                        __Vdly__tb_net__DOT__br__DOT__st = 0x12U;
                        __Vdly__tb_net__DOT__br__DOT__ret = 0U;
                    } else if ((1U & (~ (IData)(vlSelf->ddr_busy)))) {
                        vlSelf->ddr_we = 0U;
                        __Vdly__tb_net__DOT__br__DOT__st 
                            = vlSelf->tb_net__DOT__br__DOT__ret;
                    }
                } else if ((1U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                    if (((IData)(vlSelf->ddr_rd) & 
                         (~ (IData)(vlSelf->ddr_busy)))) {
                        __Vdly__ddr_rd = 0U;
                    }
                    if (vlSelf->ddr_dout_ready) {
                        __Vdly__tb_net__DOT__br__DOT__acc 
                            = vlSelf->ddr_dout;
                        __Vdly__tb_net__DOT__br__DOT__st 
                            = vlSelf->tb_net__DOT__br__DOT__ret;
                    }
                } else if ((1U & (~ (IData)(vlSelf->tb_net__DOT__rx_busy)))) {
                    vlSelf->frames_rx = ((IData)(1U) 
                                         + vlSelf->frames_rx);
                    vlSelf->ddr_addr = 0x7000004U;
                    vlSelf->ddr_din = (QData)((IData)(
                                                      ((IData)(1U) 
                                                       + vlSelf->tb_net__DOT__br__DOT__rx_tail)));
                    vlSelf->ddr_we = 1U;
                    __Vdly__tb_net__DOT__br__DOT__st = 0x12U;
                    __Vdly__tb_net__DOT__br__DOT__ret = 0U;
                    __Vdly__tb_net__DOT__br__DOT__rx_tail 
                        = ((IData)(1U) + vlSelf->tb_net__DOT__br__DOT__rx_tail);
                }
            } else if ((8U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                if ((4U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                    if ((2U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                        if ((1U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                            if (vlSelf->tb_net__DOT__br__DOT__pulse_wait) {
                                if (vlSelf->tb_net__DOT__cen) {
                                    __Vdly__tb_net__DOT__br__DOT__n 
                                        = (0x7ffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->tb_net__DOT__br__DOT__n)));
                                    __Vdly__tb_net__DOT__br__DOT__lanes 
                                        = (7U & ((IData)(1U) 
                                                 + (IData)(vlSelf->tb_net__DOT__br__DOT__lanes)));
                                    vlSelf->tb_net__DOT__br__DOT__pulse_wait = 0U;
                                    if (((0x7ffU & 
                                          ((IData)(1U) 
                                           + (IData)(vlSelf->tb_net__DOT__br__DOT__n))) 
                                         == (IData)(vlSelf->tb_net__DOT__rx_len))) {
                                        __Vdly__tb_net__DOT__br__DOT__st = 0x10U;
                                    } else if ((7U 
                                                == (IData)(vlSelf->tb_net__DOT__br__DOT__lanes))) {
                                        __Vdly__tb_net__DOT__br__DOT__st = 0xeU;
                                    }
                                }
                            } else {
                                vlSelf->__Vdly__tb_net__DOT__rx_data 
                                    = (0xffU & (IData)(
                                                       (vlSelf->tb_net__DOT__br__DOT__acc 
                                                        >> 
                                                        (0x3fU 
                                                         & VL_SHIFTL_III(6,32,32, (IData)(vlSelf->tb_net__DOT__br__DOT__lanes), 3U)))));
                                vlSelf->__Vdly__tb_net__DOT__rx_byte = 1U;
                                vlSelf->tb_net__DOT__br__DOT__pulse_wait = 1U;
                            }
                        } else {
                            __Vfunc_tb_net__DOT__br__DOT__slot_word__7__byte_off 
                                = (0x7ffU & ((IData)(8U) 
                                             + (IData)(vlSelf->tb_net__DOT__br__DOT__n)));
                            __Vfunc_tb_net__DOT__br__DOT__slot_word__7__ctr 
                                = vlSelf->tb_net__DOT__br__DOT__rx_tail;
                            __Vfunc_tb_net__DOT__br__DOT__slot_word__7__Vfuncout 
                                = (0x1fffffffU & ((IData)(0x7001200U) 
                                                  + 
                                                  ((0xf00U 
                                                    & (__Vfunc_tb_net__DOT__br__DOT__slot_word__7__ctr 
                                                       << 8U)) 
                                                   + 
                                                   (0xffU 
                                                    & ((IData)(__Vfunc_tb_net__DOT__br__DOT__slot_word__7__byte_off) 
                                                       >> 3U)))));
                            __Vdly__ddr_rd = 1U;
                            __Vdly__tb_net__DOT__br__DOT__st = 0x11U;
                            __Vdly__tb_net__DOT__br__DOT__ret = 0xfU;
                            vlSelf->ddr_addr = __Vfunc_tb_net__DOT__br__DOT__slot_word__7__Vfuncout;
                        }
                    } else if ((1U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                        if (vlSelf->tb_net__DOT__rx_answer) {
                            if (((IData)(vlSelf->tb_net__DOT__rx_take) 
                                 & (0U != (IData)(vlSelf->tb_net__DOT__rx_len)))) {
                                __Vdly__tb_net__DOT__br__DOT__n = 0U;
                                __Vdly__tb_net__DOT__br__DOT__lanes = 0U;
                                __Vdly__tb_net__DOT__br__DOT__st = 0xfU;
                            } else {
                                __Vdly__tb_net__DOT__br__DOT__st = 0x10U;
                            }
                        }
                    } else if (vlSelf->tb_net__DOT__cen) {
                        __Vdly__tb_net__DOT__br__DOT__st = 0xdU;
                    }
                } else if ((2U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                    if ((1U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                        vlSelf->__Vdly__tb_net__DOT__rx_dst 
                            = (((QData)((IData)((((IData)(vlSelf->tb_net__DOT__br__DOT__acc) 
                                                  << 0x18U) 
                                                 | ((0xff0000U 
                                                     & ((IData)(
                                                                (vlSelf->tb_net__DOT__br__DOT__acc 
                                                                 >> 8U)) 
                                                        << 0x10U)) 
                                                    | ((0xff00U 
                                                        & ((IData)(
                                                                   (vlSelf->tb_net__DOT__br__DOT__acc 
                                                                    >> 0x10U)) 
                                                           << 8U)) 
                                                       | (0xffU 
                                                          & (IData)(
                                                                    (vlSelf->tb_net__DOT__br__DOT__acc 
                                                                     >> 0x18U)))))))) 
                                << 0x10U) | (QData)((IData)(
                                                            ((0xff00U 
                                                              & ((IData)(
                                                                         (vlSelf->tb_net__DOT__br__DOT__acc 
                                                                          >> 0x20U)) 
                                                                 << 8U)) 
                                                             | (0xffU 
                                                                & (IData)(
                                                                          (vlSelf->tb_net__DOT__br__DOT__acc 
                                                                           >> 0x28U)))))));
                        vlSelf->__Vdly__tb_net__DOT__rx_offer = 1U;
                        __Vdly__tb_net__DOT__br__DOT__st = 0xcU;
                    } else {
                        __Vfunc_tb_net__DOT__br__DOT__slot_word__8__ctr 
                            = vlSelf->tb_net__DOT__br__DOT__rx_tail;
                        __Vfunc_tb_net__DOT__br__DOT__slot_word__8__Vfuncout 
                            = (0x1fffffffU & ((IData)(0x7001201U) 
                                              + (0xf00U 
                                                 & (__Vfunc_tb_net__DOT__br__DOT__slot_word__8__ctr 
                                                    << 8U))));
                        vlSelf->__Vdly__tb_net__DOT__rx_len 
                            = ((0x5eeU < (0x7ffU & (IData)(vlSelf->tb_net__DOT__br__DOT__acc)))
                                ? 0x5eeU : (0x7ffU 
                                            & (IData)(vlSelf->tb_net__DOT__br__DOT__acc)));
                        vlSelf->ddr_addr = __Vfunc_tb_net__DOT__br__DOT__slot_word__8__Vfuncout;
                        __Vdly__ddr_rd = 1U;
                        __Vdly__tb_net__DOT__br__DOT__st = 0x11U;
                        __Vdly__tb_net__DOT__br__DOT__ret = 0xbU;
                    }
                } else if ((1U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                    if ((1U & ((~ (IData)(vlSelf->tb_net__DOT__tx_done)) 
                               & (~ (IData)(vlSelf->tb_net__DOT__tx_req))))) {
                        __Vdly__tb_net__DOT__br__DOT__st = 0U;
                    }
                } else {
                    vlSelf->frames_tx = ((IData)(1U) 
                                         + vlSelf->frames_tx);
                    vlSelf->ddr_addr = 0x7000001U;
                    vlSelf->ddr_din = (QData)((IData)(
                                                      ((IData)(1U) 
                                                       + vlSelf->tb_net__DOT__br__DOT__tx_head)));
                    vlSelf->ddr_we = 1U;
                    __Vdly__tb_net__DOT__br__DOT__st = 0x12U;
                    __Vdly__tb_net__DOT__br__DOT__ret = 9U;
                    vlSelf->__Vdly__tb_net__DOT__tx_ok = 1U;
                    vlSelf->__Vdly__tb_net__DOT__tx_done = 1U;
                    __Vdly__tb_net__DOT__br__DOT__tx_head 
                        = ((IData)(1U) + vlSelf->tb_net__DOT__br__DOT__tx_head);
                }
            } else if ((4U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                if ((2U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                    if ((1U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                        __Vfunc_tb_net__DOT__br__DOT__slot_word__9__ctr 
                            = vlSelf->tb_net__DOT__br__DOT__tx_head;
                        __Vfunc_tb_net__DOT__br__DOT__slot_word__9__Vfuncout 
                            = (0x1fffffffU & ((IData)(0x7000200U) 
                                              + (0xf00U 
                                                 & (__Vfunc_tb_net__DOT__br__DOT__slot_word__9__ctr 
                                                    << 8U))));
                        vlSelf->ddr_addr = __Vfunc_tb_net__DOT__br__DOT__slot_word__9__Vfuncout;
                        vlSelf->ddr_din = (QData)((IData)(vlSelf->tb_net__DOT__tx_len));
                        vlSelf->ddr_we = 1U;
                        __Vdly__tb_net__DOT__br__DOT__st = 0x12U;
                        __Vdly__tb_net__DOT__br__DOT__ret = 8U;
                    } else {
                        __Vfunc_tb_net__DOT__br__DOT__slot_word__10__byte_off 
                            = (0x7ffU & ((IData)(8U) 
                                         + ((IData)(vlSelf->tb_net__DOT__br__DOT__n) 
                                            - (IData)(1U))));
                        __Vfunc_tb_net__DOT__br__DOT__slot_word__10__ctr 
                            = vlSelf->tb_net__DOT__br__DOT__tx_head;
                        __Vfunc_tb_net__DOT__br__DOT__slot_word__10__Vfuncout 
                            = (0x1fffffffU & ((IData)(0x7000200U) 
                                              + ((0xf00U 
                                                  & (__Vfunc_tb_net__DOT__br__DOT__slot_word__10__ctr 
                                                     << 8U)) 
                                                 + 
                                                 (0xffU 
                                                  & ((IData)(__Vfunc_tb_net__DOT__br__DOT__slot_word__10__byte_off) 
                                                     >> 3U)))));
                        vlSelf->ddr_din = vlSelf->tb_net__DOT__br__DOT__acc;
                        vlSelf->ddr_we = 1U;
                        __Vdly__tb_net__DOT__br__DOT__st = 0x12U;
                        __Vdly__tb_net__DOT__br__DOT__lanes = 0U;
                        vlSelf->ddr_addr = __Vfunc_tb_net__DOT__br__DOT__slot_word__10__Vfuncout;
                        __Vdly__tb_net__DOT__br__DOT__ret 
                            = (((IData)(vlSelf->tb_net__DOT__br__DOT__n) 
                                == (IData)(vlSelf->tb_net__DOT__tx_len))
                                ? 7U : 4U);
                        __Vdly__tb_net__DOT__br__DOT__acc = 0ULL;
                    }
                } else if ((1U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                    __Vdly__tb_net__DOT__br__DOT__st = 0U;
                } else {
                    __Vdly__tb_net__DOT__br__DOT__bw 
                        = (3U & ((IData)(1U) + (IData)(vlSelf->tb_net__DOT__br__DOT__bw)));
                    if ((2U == (IData)(vlSelf->tb_net__DOT__br__DOT__bw))) {
                        vlSelf->tb_net__DOT__b_addr 
                            = (0x3fffU & ((IData)(1U) 
                                          + (IData)(vlSelf->tb_net__DOT__b_addr)));
                        __Vdly__tb_net__DOT__br__DOT__acc 
                            = (((~ (0xffULL << (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(vlSelf->tb_net__DOT__br__DOT__lanes), 3U)))) 
                                & __Vdly__tb_net__DOT__br__DOT__acc) 
                               | ((QData)((IData)(((IData)(vlSelf->tb_net__DOT__nic__DOT__b_lsb)
                                                    ? (IData)(vlSelf->tb_net__DOT__nic__DOT__qb_o)
                                                    : (IData)(vlSelf->tb_net__DOT__nic__DOT__qb_e)))) 
                                  << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelf->tb_net__DOT__br__DOT__lanes), 3U))));
                        __Vdly__tb_net__DOT__br__DOT__bw = 0U;
                        __Vdly__tb_net__DOT__br__DOT__n 
                            = (0x7ffU & ((IData)(1U) 
                                         + (IData)(vlSelf->tb_net__DOT__br__DOT__n)));
                        __Vdly__tb_net__DOT__br__DOT__lanes 
                            = (7U & ((IData)(1U) + (IData)(vlSelf->tb_net__DOT__br__DOT__lanes)));
                        if (((7U == (IData)(vlSelf->tb_net__DOT__br__DOT__lanes)) 
                             | ((0x7ffU & ((IData)(1U) 
                                           + (IData)(vlSelf->tb_net__DOT__br__DOT__n))) 
                                == (IData)(vlSelf->tb_net__DOT__tx_len)))) {
                            __Vdly__tb_net__DOT__br__DOT__st = 6U;
                        }
                    }
                }
            } else if ((2U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                if ((1U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                    if ((1U & (~ (IData)(vlSelf->link)))) {
                        __Vdly__tb_net__DOT__br__DOT__tx_head = 0U;
                        __Vdly__tb_net__DOT__br__DOT__rx_tail = 0U;
                    }
                    __Vdly__tb_net__DOT__br__DOT__rx_head 
                        = (IData)(vlSelf->tb_net__DOT__br__DOT__acc);
                    __Vdly__tb_net__DOT__br__DOT__st = 0U;
                } else {
                    __Vdly__tb_net__DOT__br__DOT__tx_tail 
                        = (IData)(vlSelf->tb_net__DOT__br__DOT__acc);
                    vlSelf->ddr_addr = 0x7000003U;
                    __Vdly__ddr_rd = 1U;
                    __Vdly__tb_net__DOT__br__DOT__st = 0x11U;
                    __Vdly__tb_net__DOT__br__DOT__ret = 3U;
                }
            } else if ((1U & (IData)(vlSelf->tb_net__DOT__br__DOT__st))) {
                vlSelf->tb_net__DOT__br__DOT__magic_ok 
                    = (0x454e5244U == (IData)(vlSelf->tb_net__DOT__br__DOT__acc));
                vlSelf->ddr_addr = 0x7000006U;
                __Vdly__ddr_rd = 1U;
                __Vdly__tb_net__DOT__br__DOT__st = 0x11U;
                __Vdly__tb_net__DOT__br__DOT__ret = 0x15U;
            } else {
                __Vdly__tb_net__DOT__br__DOT__poll_cnt 
                    = (0xfffffU & ((IData)(1U) + vlSelf->tb_net__DOT__br__DOT__poll_cnt));
                if (((((IData)(vlSelf->tb_net__DOT__tx_req) 
                       & (~ (IData)(vlSelf->tb_net__DOT__tx_done))) 
                      & (IData)(vlSelf->link)) & (0x10U 
                                                  > 
                                                  (vlSelf->tb_net__DOT__br__DOT__tx_head 
                                                   - vlSelf->tb_net__DOT__br__DOT__tx_tail)))) {
                    vlSelf->tb_net__DOT__b_addr = vlSelf->tb_net__DOT__tx_base;
                    __Vdly__tb_net__DOT__br__DOT__n = 0U;
                    __Vdly__tb_net__DOT__br__DOT__lanes = 0U;
                    __Vdly__tb_net__DOT__br__DOT__acc = 0ULL;
                    __Vdly__tb_net__DOT__br__DOT__bw = 0U;
                    __Vdly__tb_net__DOT__br__DOT__st = 4U;
                } else if ((((IData)(vlSelf->tb_net__DOT__tx_req) 
                             & (~ (IData)(vlSelf->tb_net__DOT__tx_done))) 
                            & (~ (IData)(vlSelf->link)))) {
                    vlSelf->__Vdly__tb_net__DOT__tx_ok = 0U;
                    vlSelf->__Vdly__tb_net__DOT__tx_done = 1U;
                    __Vdly__tb_net__DOT__br__DOT__st = 9U;
                } else if ((((IData)(vlSelf->link) 
                             & (vlSelf->tb_net__DOT__br__DOT__rx_head 
                                != vlSelf->tb_net__DOT__br__DOT__rx_tail)) 
                            & (~ (IData)(vlSelf->tb_net__DOT__rx_busy)))) {
                    __Vfunc_tb_net__DOT__br__DOT__slot_word__11__ctr 
                        = vlSelf->tb_net__DOT__br__DOT__rx_tail;
                    __Vfunc_tb_net__DOT__br__DOT__slot_word__11__Vfuncout 
                        = (0x1fffffffU & ((IData)(0x7001200U) 
                                          + (0xf00U 
                                             & (__Vfunc_tb_net__DOT__br__DOT__slot_word__11__ctr 
                                                << 8U))));
                    vlSelf->ddr_addr = __Vfunc_tb_net__DOT__br__DOT__slot_word__11__Vfuncout;
                    __Vdly__ddr_rd = 1U;
                    __Vdly__tb_net__DOT__br__DOT__st = 0x11U;
                    __Vdly__tb_net__DOT__br__DOT__ret = 0xaU;
                } else if (((IData)(vlSelf->tb_net__DOT__br__DOT__tq_r) 
                            != (IData)(vlSelf->tb_net__DOT__br__DOT__tq_w))) {
                    vlSelf->ddr_addr = (0x1fffffffU 
                                        & ((IData)(0x7020000U) 
                                           + (0x1fffU 
                                              & vlSelf->tb_net__DOT__br__DOT__t_count)));
                    vlSelf->ddr_din = vlSelf->tb_net__DOT__br__DOT__tq
                        [vlSelf->tb_net__DOT__br__DOT__tq_r];
                    vlSelf->ddr_we = 1U;
                    __Vdly__tb_net__DOT__br__DOT__st = 0x12U;
                    __Vdly__tb_net__DOT__br__DOT__ret = 0x17U;
                } else if ((0U == (0xffffU & vlSelf->tb_net__DOT__br__DOT__poll_cnt))) {
                    vlSelf->ddr_addr = 0x7000000U;
                    __Vdly__ddr_rd = 1U;
                    __Vdly__tb_net__DOT__br__DOT__st = 0x11U;
                    __Vdly__tb_net__DOT__br__DOT__ret = 1U;
                }
            }
        } else {
            __Vdly__tb_net__DOT__br__DOT__tx_head = 0U;
            __Vdly__tb_net__DOT__br__DOT__rx_tail = 0U;
            __Vdly__tb_net__DOT__br__DOT__st = 0x16U;
            __Vdly__link = 0U;
            __Vdly__ddr_rd = 0U;
            vlSelf->ddr_we = 0U;
        }
    } else {
        vlSelf->__Vdly__tb_net__DOT__cen = 0U;
        vlSelf->__Vdly__tb_net__DOT__tx_done = 0U;
        vlSelf->tb_net__DOT__b_addr = 0U;
        vlSelf->frames_tx = 0U;
        vlSelf->frames_rx = 0U;
        __Vdly__tb_net__DOT__br__DOT__tx_head = 0U;
        __Vdly__tb_net__DOT__br__DOT__rx_tail = 0U;
        __Vdly__tb_net__DOT__br__DOT__tq_r = 0U;
        __Vdly__tb_net__DOT__br__DOT__st = 0x16U;
        __Vdly__tb_net__DOT__br__DOT__ret = 0U;
        vlSelf->__Vdly__tb_net__DOT__tx_ok = 0U;
        vlSelf->__Vdly__tb_net__DOT__rx_offer = 0U;
        vlSelf->__Vdly__tb_net__DOT__rx_len = 0U;
        vlSelf->__Vdly__tb_net__DOT__rx_dst = 0ULL;
        vlSelf->__Vdly__tb_net__DOT__rx_byte = 0U;
        vlSelf->__Vdly__tb_net__DOT__rx_data = 0U;
        vlSelf->ddr_addr = 0U;
        __Vdly__ddr_rd = 0U;
        vlSelf->ddr_we = 0U;
        vlSelf->ddr_din = 0ULL;
        __Vdly__link = 0U;
        __Vdly__tb_net__DOT__br__DOT__tx_tail = 0U;
        __Vdly__tb_net__DOT__br__DOT__rx_head = 0U;
        __Vdly__tb_net__DOT__br__DOT__poll_cnt = 0U;
        __Vdly__tb_net__DOT__br__DOT__n = 0U;
        __Vdly__tb_net__DOT__br__DOT__acc = 0ULL;
        __Vdly__tb_net__DOT__br__DOT__bw = 0U;
        __Vdly__tb_net__DOT__br__DOT__lanes = 0U;
        vlSelf->tb_net__DOT__br__DOT__pulse_wait = 0U;
        vlSelf->tb_net__DOT__br__DOT__magic_ok = 0U;
        vlSelf->tb_net__DOT__br__DOT__epoch = 0U;
        __Vdly__tb_net__DOT__br__DOT__t_count = 0U;
    }
    vlSelf->tb_net__DOT__br__DOT__st = __Vdly__tb_net__DOT__br__DOT__st;
    vlSelf->tb_net__DOT__br__DOT__t_count = __Vdly__tb_net__DOT__br__DOT__t_count;
    vlSelf->tb_net__DOT__br__DOT__tq_r = __Vdly__tb_net__DOT__br__DOT__tq_r;
    vlSelf->tb_net__DOT__br__DOT__ret = __Vdly__tb_net__DOT__br__DOT__ret;
    vlSelf->ddr_rd = __Vdly__ddr_rd;
    vlSelf->link = __Vdly__link;
    vlSelf->tb_net__DOT__br__DOT__acc = __Vdly__tb_net__DOT__br__DOT__acc;
    vlSelf->tb_net__DOT__br__DOT__rx_tail = __Vdly__tb_net__DOT__br__DOT__rx_tail;
    vlSelf->tb_net__DOT__br__DOT__n = __Vdly__tb_net__DOT__br__DOT__n;
    vlSelf->tb_net__DOT__br__DOT__lanes = __Vdly__tb_net__DOT__br__DOT__lanes;
    vlSelf->tb_net__DOT__br__DOT__tx_head = __Vdly__tb_net__DOT__br__DOT__tx_head;
    vlSelf->tb_net__DOT__br__DOT__bw = __Vdly__tb_net__DOT__br__DOT__bw;
    vlSelf->tb_net__DOT__br__DOT__rx_head = __Vdly__tb_net__DOT__br__DOT__rx_head;
    vlSelf->tb_net__DOT__br__DOT__tx_tail = __Vdly__tb_net__DOT__br__DOT__tx_tail;
    vlSelf->tb_net__DOT__br__DOT__poll_cnt = __Vdly__tb_net__DOT__br__DOT__poll_cnt;
    if ((1U & (~ (IData)(vlSelf->rst_n)))) {
        vlSelf->tb_net__DOT__br__DOT__tq_w = 0U;
    }
}

VL_INLINE_OPT void Vtb_net___024root___nba_sequent__TOP__1(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___nba_sequent__TOP__1\n"); );
    // Init
    SData/*12:0*/ __Vdlyvdim0__tb_net__DOT__nic__DOT__ram_e__v0;
    __Vdlyvdim0__tb_net__DOT__nic__DOT__ram_e__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_net__DOT__nic__DOT__ram_e__v0;
    __Vdlyvval__tb_net__DOT__nic__DOT__ram_e__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_net__DOT__nic__DOT__ram_e__v0;
    __Vdlyvset__tb_net__DOT__nic__DOT__ram_e__v0 = 0;
    SData/*12:0*/ __Vdlyvdim0__tb_net__DOT__nic__DOT__ram_o__v0;
    __Vdlyvdim0__tb_net__DOT__nic__DOT__ram_o__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_net__DOT__nic__DOT__ram_o__v0;
    __Vdlyvval__tb_net__DOT__nic__DOT__ram_o__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_net__DOT__nic__DOT__ram_o__v0;
    __Vdlyvset__tb_net__DOT__nic__DOT__ram_o__v0 = 0;
    SData/*12:0*/ __Vdlyvdim0__tb_net__DOT__nic__DOT__ram_e__v1;
    __Vdlyvdim0__tb_net__DOT__nic__DOT__ram_e__v1 = 0;
    CData/*7:0*/ __Vdlyvval__tb_net__DOT__nic__DOT__ram_e__v1;
    __Vdlyvval__tb_net__DOT__nic__DOT__ram_e__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_net__DOT__nic__DOT__ram_e__v1;
    __Vdlyvset__tb_net__DOT__nic__DOT__ram_e__v1 = 0;
    SData/*12:0*/ __Vdlyvdim0__tb_net__DOT__nic__DOT__ram_o__v1;
    __Vdlyvdim0__tb_net__DOT__nic__DOT__ram_o__v1 = 0;
    CData/*7:0*/ __Vdlyvval__tb_net__DOT__nic__DOT__ram_o__v1;
    __Vdlyvval__tb_net__DOT__nic__DOT__ram_o__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_net__DOT__nic__DOT__ram_o__v1;
    __Vdlyvset__tb_net__DOT__nic__DOT__ram_o__v1 = 0;
    // Body
    __Vdlyvset__tb_net__DOT__nic__DOT__ram_o__v0 = 0U;
    __Vdlyvset__tb_net__DOT__nic__DOT__ram_e__v0 = 0U;
    __Vdlyvset__tb_net__DOT__nic__DOT__ram_o__v1 = 0U;
    __Vdlyvset__tb_net__DOT__nic__DOT__ram_e__v1 = 0U;
    if (vlSelf->tb_net__DOT__nic__DOT__wa_o) {
        __Vdlyvval__tb_net__DOT__nic__DOT__ram_o__v0 
            = vlSelf->tb_net__DOT__nic__DOT__wa_o_d;
        __Vdlyvset__tb_net__DOT__nic__DOT__ram_o__v0 = 1U;
        __Vdlyvdim0__tb_net__DOT__nic__DOT__ram_o__v0 
            = vlSelf->tb_net__DOT__nic__DOT__pa_o;
    }
    if (vlSelf->tb_net__DOT__nic__DOT__wa_e) {
        __Vdlyvval__tb_net__DOT__nic__DOT__ram_e__v0 
            = vlSelf->tb_net__DOT__nic__DOT__wa_e_d;
        __Vdlyvset__tb_net__DOT__nic__DOT__ram_e__v0 = 1U;
        __Vdlyvdim0__tb_net__DOT__nic__DOT__ram_e__v0 
            = vlSelf->tb_net__DOT__nic__DOT__pa_e;
    }
    if (((IData)(vlSelf->tb_net__DOT__nic__DOT__wb) 
         & (IData)(vlSelf->tb_net__DOT__nic__DOT__wb_a))) {
        __Vdlyvval__tb_net__DOT__nic__DOT__ram_o__v1 
            = vlSelf->tb_net__DOT__nic__DOT__wb_d;
        __Vdlyvset__tb_net__DOT__nic__DOT__ram_o__v1 = 1U;
        __Vdlyvdim0__tb_net__DOT__nic__DOT__ram_o__v1 
            = (0x1fffU & ((IData)(vlSelf->tb_net__DOT__nic__DOT__pb_a) 
                          >> 1U));
    }
    if (((IData)(vlSelf->tb_net__DOT__nic__DOT__wb) 
         & (~ (IData)(vlSelf->tb_net__DOT__nic__DOT__wb_a)))) {
        __Vdlyvval__tb_net__DOT__nic__DOT__ram_e__v1 
            = vlSelf->tb_net__DOT__nic__DOT__wb_d;
        __Vdlyvset__tb_net__DOT__nic__DOT__ram_e__v1 = 1U;
        __Vdlyvdim0__tb_net__DOT__nic__DOT__ram_e__v1 
            = (0x1fffU & ((IData)(vlSelf->tb_net__DOT__nic__DOT__pb_a) 
                          >> 1U));
    }
    vlSelf->tb_net__DOT__nic__DOT__qa_o = vlSelf->tb_net__DOT__nic__DOT__ram_o
        [vlSelf->tb_net__DOT__nic__DOT__pa_o];
    vlSelf->tb_net__DOT__nic__DOT__qa_e = vlSelf->tb_net__DOT__nic__DOT__ram_e
        [vlSelf->tb_net__DOT__nic__DOT__pa_e];
    vlSelf->tb_net__DOT__nic__DOT__b_lsb = (1U & (IData)(vlSelf->tb_net__DOT__nic__DOT__pb_a));
    vlSelf->tb_net__DOT__nic__DOT__qb_o = vlSelf->tb_net__DOT__nic__DOT__ram_o
        [(0x1fffU & ((IData)(vlSelf->tb_net__DOT__nic__DOT__pb_a) 
                     >> 1U))];
    vlSelf->tb_net__DOT__nic__DOT__qb_e = vlSelf->tb_net__DOT__nic__DOT__ram_e
        [(0x1fffU & ((IData)(vlSelf->tb_net__DOT__nic__DOT__pb_a) 
                     >> 1U))];
    if (__Vdlyvset__tb_net__DOT__nic__DOT__ram_o__v0) {
        vlSelf->tb_net__DOT__nic__DOT__ram_o[__Vdlyvdim0__tb_net__DOT__nic__DOT__ram_o__v0] 
            = __Vdlyvval__tb_net__DOT__nic__DOT__ram_o__v0;
    }
    if (__Vdlyvset__tb_net__DOT__nic__DOT__ram_o__v1) {
        vlSelf->tb_net__DOT__nic__DOT__ram_o[__Vdlyvdim0__tb_net__DOT__nic__DOT__ram_o__v1] 
            = __Vdlyvval__tb_net__DOT__nic__DOT__ram_o__v1;
    }
    if (__Vdlyvset__tb_net__DOT__nic__DOT__ram_e__v0) {
        vlSelf->tb_net__DOT__nic__DOT__ram_e[__Vdlyvdim0__tb_net__DOT__nic__DOT__ram_e__v0] 
            = __Vdlyvval__tb_net__DOT__nic__DOT__ram_e__v0;
    }
    if (__Vdlyvset__tb_net__DOT__nic__DOT__ram_e__v1) {
        vlSelf->tb_net__DOT__nic__DOT__ram_e[__Vdlyvdim0__tb_net__DOT__nic__DOT__ram_e__v1] 
            = __Vdlyvval__tb_net__DOT__nic__DOT__ram_e__v1;
    }
}

VL_INLINE_OPT void Vtb_net___024root___nba_sequent__TOP__2(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___nba_sequent__TOP__2\n"); );
    // Init
    IData/*31:0*/ tb_net__DOT__nic__DOT__mhash__Vstatic__c;
    tb_net__DOT__nic__DOT__mhash__Vstatic__c = 0;
    CData/*7:0*/ tb_net__DOT__nic__DOT__mhash__Vstatic__by;
    tb_net__DOT__nic__DOT__mhash__Vstatic__by = 0;
    CData/*5:0*/ tb_net__DOT__nic__DOT__o_hash;
    tb_net__DOT__nic__DOT__o_hash = 0;
    SData/*8:0*/ tb_net__DOT__nic__DOT__o_next0;
    tb_net__DOT__nic__DOT__o_next0 = 0;
    CData/*5:0*/ __Vfunc_tb_net__DOT__nic__DOT__mhash__4__Vfuncout;
    __Vfunc_tb_net__DOT__nic__DOT__mhash__4__Vfuncout = 0;
    QData/*47:0*/ __Vfunc_tb_net__DOT__nic__DOT__mhash__4__d;
    __Vfunc_tb_net__DOT__nic__DOT__mhash__4__d = 0;
    IData/*31:0*/ __Vfunc_tb_net__DOT__nic__DOT__crc8__5__Vfuncout;
    __Vfunc_tb_net__DOT__nic__DOT__crc8__5__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_net__DOT__nic__DOT__crc8__5__c;
    __Vfunc_tb_net__DOT__nic__DOT__crc8__5__c = 0;
    IData/*31:0*/ __Vfunc_tb_net__DOT__nic__DOT__crc8__6__Vfuncout;
    __Vfunc_tb_net__DOT__nic__DOT__crc8__6__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_net__DOT__nic__DOT__crc8__6__c;
    __Vfunc_tb_net__DOT__nic__DOT__crc8__6__c = 0;
    CData/*7:0*/ __Vfunc_tb_net__DOT__nic__DOT__crc8__6__b;
    __Vfunc_tb_net__DOT__nic__DOT__crc8__6__b = 0;
    CData/*1:0*/ __Vdlyvdim0__tb_net__DOT__nic__DOT__tally__v0;
    __Vdlyvdim0__tb_net__DOT__nic__DOT__tally__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_net__DOT__nic__DOT__tally__v0;
    __Vdlyvval__tb_net__DOT__nic__DOT__tally__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_net__DOT__nic__DOT__par__v0;
    __Vdlyvdim0__tb_net__DOT__nic__DOT__par__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_net__DOT__nic__DOT__par__v0;
    __Vdlyvval__tb_net__DOT__nic__DOT__par__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__tb_net__DOT__nic__DOT__mar__v0;
    __Vdlyvdim0__tb_net__DOT__nic__DOT__mar__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_net__DOT__nic__DOT__mar__v0;
    __Vdlyvval__tb_net__DOT__nic__DOT__mar__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_net__DOT__nic__DOT__tally__v1;
    __Vdlyvval__tb_net__DOT__nic__DOT__tally__v1 = 0;
    CData/*7:0*/ __Vdlyvval__tb_net__DOT__nic__DOT__tally__v2;
    __Vdlyvval__tb_net__DOT__nic__DOT__tally__v2 = 0;
    // Body
    if (vlSelf->rst_n) {
        vlSelf->tb_net__DOT__nic__DOT__wa_e = 0U;
        vlSelf->tb_net__DOT__nic__DOT__wa_o = 0U;
        vlSelf->tb_net__DOT__nic__DOT__wb = 0U;
        if (vlSelf->tb_net__DOT__cen) {
            vlSelf->tb_net__DOT__rx_answer = 0U;
            vlSelf->tb_net__DOT__nic__DOT__iset = 0U;
            vlSelf->tb_net__DOT__nic__DOT__iclr = 0U;
            vlSelf->tb_net__DOT__nic__DOT__nreset = 0U;
            if (vlSelf->tb_net__DOT____Vcellinp__nic__acc) {
                if ((0x10U == (IData)(vlSelf->port))) {
                    if (vlSelf->we) {
                        if (vlSelf->tb_net__DOT__nic__DOT__dma_wr_ok) {
                            if (((0x4000U <= (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar)) 
                                 & (0x8000U > (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar)))) {
                                if ((1U & (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar))) {
                                    vlSelf->tb_net__DOT__nic__DOT__wa_o = 1U;
                                    vlSelf->tb_net__DOT__nic__DOT__wa_o_i 
                                        = (0x1fffU 
                                           & ((IData)(vlSelf->tb_net__DOT__nic__DOT__rsar) 
                                              >> 1U));
                                    vlSelf->tb_net__DOT__nic__DOT__wa_o_d 
                                        = (0xffU & 
                                           ((IData)(vlSelf->wide)
                                             ? ((IData)(vlSelf->wdata) 
                                                >> 8U)
                                             : (IData)(vlSelf->wdata)));
                                } else {
                                    vlSelf->tb_net__DOT__nic__DOT__wa_e = 1U;
                                    vlSelf->tb_net__DOT__nic__DOT__wa_e_i 
                                        = (0x1fffU 
                                           & ((IData)(vlSelf->tb_net__DOT__nic__DOT__rsar) 
                                              >> 1U));
                                    vlSelf->tb_net__DOT__nic__DOT__wa_e_d 
                                        = (0xffU & 
                                           ((IData)(vlSelf->wide)
                                             ? ((IData)(vlSelf->wdata) 
                                                >> 8U)
                                             : (IData)(vlSelf->wdata)));
                                }
                            }
                            if (((IData)(vlSelf->wide) 
                                 & (1U != (IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr)))) {
                                vlSelf->__Vdly__tb_net__DOT__nic__DOT__rbcr 
                                    = (0xffffU & ((IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr) 
                                                  - (IData)(2U)));
                                if ((2U == (IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr))) {
                                    vlSelf->tb_net__DOT__nic__DOT__iset 
                                        = (0x40U | (IData)(vlSelf->tb_net__DOT__nic__DOT__iset));
                                }
                                if (((0x4000U <= (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar_n)) 
                                     & (0x8000U > (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar_n)))) {
                                    if ((1U & (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar_n))) {
                                        vlSelf->tb_net__DOT__nic__DOT__wa_o = 1U;
                                        vlSelf->tb_net__DOT__nic__DOT__wa_o_i 
                                            = (0x1fffU 
                                               & ((IData)(vlSelf->tb_net__DOT__nic__DOT__rsar_n) 
                                                  >> 1U));
                                        vlSelf->tb_net__DOT__nic__DOT__wa_o_d 
                                            = (0xffU 
                                               & (IData)(vlSelf->wdata));
                                    } else {
                                        vlSelf->tb_net__DOT__nic__DOT__wa_e = 1U;
                                        vlSelf->tb_net__DOT__nic__DOT__wa_e_i 
                                            = (0x1fffU 
                                               & ((IData)(vlSelf->tb_net__DOT__nic__DOT__rsar_n) 
                                                  >> 1U));
                                        vlSelf->tb_net__DOT__nic__DOT__wa_e_d 
                                            = (0xffU 
                                               & (IData)(vlSelf->wdata));
                                    }
                                }
                                vlSelf->tb_net__DOT__nic__DOT__rsar 
                                    = (0xffffU & ((
                                                   ((IData)(vlSelf->tb_net__DOT__nic__DOT__pstop) 
                                                    > (IData)(vlSelf->tb_net__DOT__nic__DOT__pstart)) 
                                                   & ((0xffffU 
                                                       & ((IData)(1U) 
                                                          + (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar_n))) 
                                                      == 
                                                      ((IData)(vlSelf->tb_net__DOT__nic__DOT__pstop) 
                                                       << 8U)))
                                                   ? 
                                                  ((IData)(vlSelf->tb_net__DOT__nic__DOT__pstart) 
                                                   << 8U)
                                                   : 
                                                  ((IData)(1U) 
                                                   + (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar_n))));
                            } else {
                                vlSelf->__Vdly__tb_net__DOT__nic__DOT__rbcr 
                                    = (0xffffU & ((IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr) 
                                                  - (IData)(1U)));
                                if ((1U == (IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr))) {
                                    vlSelf->tb_net__DOT__nic__DOT__iset 
                                        = (0x40U | (IData)(vlSelf->tb_net__DOT__nic__DOT__iset));
                                }
                                vlSelf->tb_net__DOT__nic__DOT__rsar 
                                    = vlSelf->tb_net__DOT__nic__DOT__rsar_n;
                            }
                        }
                    } else if (vlSelf->tb_net__DOT__nic__DOT__dma_rd_ok) {
                        if (((IData)(vlSelf->wide) 
                             & (1U != (IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr)))) {
                            vlSelf->__Vdly__tb_net__DOT__nic__DOT__rbcr 
                                = (0xffffU & ((IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr) 
                                              - (IData)(2U)));
                            if ((2U == (IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr))) {
                                vlSelf->tb_net__DOT__nic__DOT__iset 
                                    = (0x40U | (IData)(vlSelf->tb_net__DOT__nic__DOT__iset));
                            }
                            vlSelf->tb_net__DOT__nic__DOT__rsar 
                                = (0xffffU & ((((IData)(vlSelf->tb_net__DOT__nic__DOT__pstop) 
                                                > (IData)(vlSelf->tb_net__DOT__nic__DOT__pstart)) 
                                               & ((0xffffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar_n))) 
                                                  == 
                                                  ((IData)(vlSelf->tb_net__DOT__nic__DOT__pstop) 
                                                   << 8U)))
                                               ? ((IData)(vlSelf->tb_net__DOT__nic__DOT__pstart) 
                                                  << 8U)
                                               : ((IData)(1U) 
                                                  + (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar_n))));
                        } else {
                            vlSelf->__Vdly__tb_net__DOT__nic__DOT__rbcr 
                                = (0xffffU & ((IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr) 
                                              - (IData)(1U)));
                            if ((1U == (IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr))) {
                                vlSelf->tb_net__DOT__nic__DOT__iset 
                                    = (0x40U | (IData)(vlSelf->tb_net__DOT__nic__DOT__iset));
                            }
                            vlSelf->tb_net__DOT__nic__DOT__rsar 
                                = vlSelf->tb_net__DOT__nic__DOT__rsar_n;
                        }
                    }
                } else if ((((~ (IData)(vlSelf->we)) 
                             & (~ (IData)(vlSelf->wide))) 
                            & (0x1fU == (IData)(vlSelf->port)))) {
                    vlSelf->tb_net__DOT__nic__DOT__nreset = 1U;
                } else if ((((((~ (IData)(vlSelf->we)) 
                               & (~ (IData)(vlSelf->wide))) 
                              & (0xcU == (0x1cU & (IData)(vlSelf->port)))) 
                             & (0U == (0xc0U & (IData)(vlSelf->tb_net__DOT__nic__DOT__cr)))) 
                            & (0U != (3U & (IData)(vlSelf->port))))) {
                    vlSelf->tb_net__DOT__nic__DOT____Vlvbound_h66bf5d70__0 = 0U;
                    if ((2U >= (3U & ((IData)(vlSelf->port) 
                                      - (IData)(1U))))) {
                        __Vdlyvval__tb_net__DOT__nic__DOT__tally__v0 
                            = vlSelf->tb_net__DOT__nic__DOT____Vlvbound_h66bf5d70__0;
                        vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v0 = 1U;
                        __Vdlyvdim0__tb_net__DOT__nic__DOT__tally__v0 
                            = (3U & ((IData)(vlSelf->port) 
                                     - (IData)(1U)));
                    }
                } else if ((((IData)(vlSelf->we) & 
                             (~ (IData)(vlSelf->wide))) 
                            & (0U == (IData)(vlSelf->port)))) {
                    vlSelf->tb_net__DOT__nic__DOT__v 
                        = (0xffU & (IData)(vlSelf->wdata));
                    vlSelf->tb_net__DOT__nic__DOT__started 
                        = (1U & ((IData)(vlSelf->tb_net__DOT__nic__DOT__cr) 
                                 >> 1U));
                    vlSelf->__Vdly__tb_net__DOT__nic__DOT__cr 
                        = (((0xfbU & (IData)(vlSelf->tb_net__DOT__nic__DOT__v)) 
                            | ((IData)(vlSelf->tb_net__DOT__nic__DOT__tx_pending)
                                ? 4U : 0U)) | ((1U 
                                                & (IData)(vlSelf->tb_net__DOT__nic__DOT__v))
                                                ? ((IData)(vlSelf->tb_net__DOT__nic__DOT__started) 
                                                   << 1U)
                                                : 0U));
                    if ((1U & (IData)(vlSelf->tb_net__DOT__nic__DOT__v))) {
                        if ((1U & (~ (IData)(vlSelf->tb_net__DOT__nic__DOT__tx_pending)))) {
                            vlSelf->tb_net__DOT__nic__DOT__iset 
                                = (0x80U | (IData)(vlSelf->tb_net__DOT__nic__DOT__iset));
                        }
                    } else if ((2U & (IData)(vlSelf->tb_net__DOT__nic__DOT__v))) {
                        vlSelf->tb_net__DOT__nic__DOT__iclr 
                            = (0x80U | (IData)(vlSelf->tb_net__DOT__nic__DOT__iclr));
                    }
                    if ((IData)(((8U == (0x38U & (IData)(vlSelf->tb_net__DOT__nic__DOT__v))) 
                                 & (0U == (IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr))))) {
                        vlSelf->tb_net__DOT__nic__DOT__iset 
                            = (0x40U | (IData)(vlSelf->tb_net__DOT__nic__DOT__iset));
                    }
                    if (((((IData)(vlSelf->tb_net__DOT__nic__DOT__v) 
                           >> 2U) & (2U == (3U & ((0xfbU 
                                                   & (IData)(vlSelf->tb_net__DOT__nic__DOT__v)) 
                                                  | ((1U 
                                                      & (IData)(vlSelf->tb_net__DOT__nic__DOT__v))
                                                      ? 
                                                     ((IData)(vlSelf->tb_net__DOT__nic__DOT__started) 
                                                      << 1U)
                                                      : 0U))))) 
                         & (~ (IData)(vlSelf->tb_net__DOT__nic__DOT__tx_pending)))) {
                        if (((((0x4000U > ((IData)(vlSelf->tb_net__DOT__nic__DOT__tpsr) 
                                           << 8U)) 
                               | (0x8000U < (0xffffU 
                                             & (((IData)(vlSelf->tb_net__DOT__nic__DOT__tpsr) 
                                                 << 8U) 
                                                + (IData)(vlSelf->tb_net__DOT__nic__DOT__tbcr))))) 
                              | (0xeU > (IData)(vlSelf->tb_net__DOT__nic__DOT__tbcr))) 
                             | (0x5eeU < (IData)(vlSelf->tb_net__DOT__nic__DOT__tbcr)))) {
                            vlSelf->tb_net__DOT__nic__DOT__iset 
                                = (8U | (IData)(vlSelf->tb_net__DOT__nic__DOT__iset));
                            vlSelf->tb_net__DOT__nic__DOT__tsr = 8U;
                            vlSelf->__Vdly__tb_net__DOT__nic__DOT__cr 
                                = ((0xfbU & (IData)(vlSelf->tb_net__DOT__nic__DOT__v)) 
                                   | ((1U & (IData)(vlSelf->tb_net__DOT__nic__DOT__v))
                                       ? ((IData)(vlSelf->tb_net__DOT__nic__DOT__started) 
                                          << 1U) : 0U));
                        } else {
                            vlSelf->__Vdly__tb_net__DOT__nic__DOT__cr 
                                = (4U | ((0xfbU & (IData)(vlSelf->tb_net__DOT__nic__DOT__v)) 
                                         | ((1U & (IData)(vlSelf->tb_net__DOT__nic__DOT__v))
                                             ? ((IData)(vlSelf->tb_net__DOT__nic__DOT__started) 
                                                << 1U)
                                             : 0U)));
                            vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_pending = 1U;
                            vlSelf->__Vdly__tb_net__DOT__tx_req = 1U;
                            vlSelf->tb_net__DOT__tx_base 
                                = (0x3f00U & ((IData)(vlSelf->tb_net__DOT__nic__DOT__tpsr) 
                                              << 8U));
                            vlSelf->tb_net__DOT__tx_len 
                                = (0x7ffU & (IData)(vlSelf->tb_net__DOT__nic__DOT__tbcr));
                            vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_wait 
                                = (0xffffU & ((IData)(0x25U) 
                                              * (0xffffU 
                                                 & ((IData)(0x18U) 
                                                    + (IData)(vlSelf->tb_net__DOT__nic__DOT__tbcr)))));
                            vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_copied = 0U;
                        }
                    }
                } else if ((((IData)(vlSelf->we) & 
                             (~ (IData)(vlSelf->wide))) 
                            & (~ ((IData)(vlSelf->port) 
                                  >> 4U)))) {
                    vlSelf->tb_net__DOT__nic__DOT__v 
                        = (0xffU & (IData)(vlSelf->wdata));
                    if ((0U == (3U & ((IData)(vlSelf->tb_net__DOT__nic__DOT__cr) 
                                      >> 6U)))) {
                        if ((8U & (IData)(vlSelf->port))) {
                            if ((4U & (IData)(vlSelf->port))) {
                                if ((2U & (IData)(vlSelf->port))) {
                                    if ((1U & (IData)(vlSelf->port))) {
                                        vlSelf->tb_net__DOT__nic__DOT__imr 
                                            = (0x7fU 
                                               & (IData)(vlSelf->tb_net__DOT__nic__DOT__v));
                                    } else {
                                        vlSelf->tb_net__DOT__nic__DOT__dcr 
                                            = vlSelf->tb_net__DOT__nic__DOT__v;
                                    }
                                } else if ((1U & (IData)(vlSelf->port))) {
                                    vlSelf->tb_net__DOT__nic__DOT__tcr 
                                        = vlSelf->tb_net__DOT__nic__DOT__v;
                                } else {
                                    vlSelf->__Vdly__tb_net__DOT__nic__DOT__rcr 
                                        = vlSelf->tb_net__DOT__nic__DOT__v;
                                }
                            } else if ((2U & (IData)(vlSelf->port))) {
                                vlSelf->__Vdly__tb_net__DOT__nic__DOT__rbcr 
                                    = ((1U & (IData)(vlSelf->port))
                                        ? ((0xffU & (IData)(vlSelf->__Vdly__tb_net__DOT__nic__DOT__rbcr)) 
                                           | ((IData)(vlSelf->tb_net__DOT__nic__DOT__v) 
                                              << 8U))
                                        : ((0xff00U 
                                            & (IData)(vlSelf->__Vdly__tb_net__DOT__nic__DOT__rbcr)) 
                                           | (IData)(vlSelf->tb_net__DOT__nic__DOT__v)));
                            } else {
                                vlSelf->tb_net__DOT__nic__DOT__rsar 
                                    = ((1U & (IData)(vlSelf->port))
                                        ? ((0xffU & (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar)) 
                                           | ((IData)(vlSelf->tb_net__DOT__nic__DOT__v) 
                                              << 8U))
                                        : ((0xff00U 
                                            & (IData)(vlSelf->tb_net__DOT__nic__DOT__rsar)) 
                                           | (IData)(vlSelf->tb_net__DOT__nic__DOT__v)));
                            }
                        } else if ((4U & (IData)(vlSelf->port))) {
                            if ((2U & (IData)(vlSelf->port))) {
                                if ((1U & (IData)(vlSelf->port))) {
                                    vlSelf->tb_net__DOT__nic__DOT__iclr 
                                        = ((IData)(vlSelf->tb_net__DOT__nic__DOT__iclr) 
                                           | (0x7fU 
                                              & (IData)(vlSelf->tb_net__DOT__nic__DOT__v)));
                                } else {
                                    vlSelf->tb_net__DOT__nic__DOT__tbcr 
                                        = ((0xffU & (IData)(vlSelf->tb_net__DOT__nic__DOT__tbcr)) 
                                           | ((IData)(vlSelf->tb_net__DOT__nic__DOT__v) 
                                              << 8U));
                                }
                            } else if ((1U & (IData)(vlSelf->port))) {
                                vlSelf->tb_net__DOT__nic__DOT__tbcr 
                                    = ((0xff00U & (IData)(vlSelf->tb_net__DOT__nic__DOT__tbcr)) 
                                       | (IData)(vlSelf->tb_net__DOT__nic__DOT__v));
                            } else {
                                vlSelf->tb_net__DOT__nic__DOT__tpsr 
                                    = vlSelf->tb_net__DOT__nic__DOT__v;
                            }
                        } else if ((2U & (IData)(vlSelf->port))) {
                            if ((1U & (IData)(vlSelf->port))) {
                                vlSelf->tb_net__DOT__nic__DOT__bnry 
                                    = vlSelf->tb_net__DOT__nic__DOT__v;
                            } else {
                                vlSelf->tb_net__DOT__nic__DOT__pstop 
                                    = vlSelf->tb_net__DOT__nic__DOT__v;
                            }
                        } else if ((1U & (IData)(vlSelf->port))) {
                            vlSelf->tb_net__DOT__nic__DOT__pstart 
                                = vlSelf->tb_net__DOT__nic__DOT__v;
                        }
                    } else if ((1U == (3U & ((IData)(vlSelf->tb_net__DOT__nic__DOT__cr) 
                                             >> 6U)))) {
                        if (((1U <= (0xfU & (IData)(vlSelf->port))) 
                             & (6U >= (0xfU & (IData)(vlSelf->port))))) {
                            vlSelf->tb_net__DOT__nic__DOT____Vlvbound_h9fb8493e__0 
                                = vlSelf->tb_net__DOT__nic__DOT__v;
                            if ((5U >= (7U & ((IData)(vlSelf->port) 
                                              - (IData)(1U))))) {
                                __Vdlyvval__tb_net__DOT__nic__DOT__par__v0 
                                    = vlSelf->tb_net__DOT__nic__DOT____Vlvbound_h9fb8493e__0;
                                vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__par__v0 = 1U;
                                __Vdlyvdim0__tb_net__DOT__nic__DOT__par__v0 
                                    = (7U & ((IData)(vlSelf->port) 
                                             - (IData)(1U)));
                            }
                        } else if ((7U == (0xfU & (IData)(vlSelf->port)))) {
                            vlSelf->__Vdly__tb_net__DOT__nic__DOT__curr 
                                = vlSelf->tb_net__DOT__nic__DOT__v;
                        } else if ((8U <= (0xfU & (IData)(vlSelf->port)))) {
                            __Vdlyvval__tb_net__DOT__nic__DOT__mar__v0 
                                = vlSelf->tb_net__DOT__nic__DOT__v;
                            vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__mar__v0 = 1U;
                            __Vdlyvdim0__tb_net__DOT__nic__DOT__mar__v0 
                                = (7U & (IData)(vlSelf->port));
                        }
                    }
                }
            }
            if (((IData)(vlSelf->tb_net__DOT__tx_req) 
                 & (IData)(vlSelf->tb_net__DOT__tx_done))) {
                vlSelf->__Vdly__tb_net__DOT__tx_req = 0U;
                vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_copied = 1U;
                vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_copied_ok 
                    = vlSelf->tb_net__DOT__tx_ok;
            }
            if (((IData)(vlSelf->tb_net__DOT__nic__DOT__tx_pending) 
                 & (0U != (IData)(vlSelf->tb_net__DOT__nic__DOT__tx_wait)))) {
                vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_wait 
                    = (0xffffU & ((IData)(vlSelf->tb_net__DOT__nic__DOT__tx_wait) 
                                  - (IData)(1U)));
            }
            if (((((IData)(vlSelf->tb_net__DOT__nic__DOT__tx_pending) 
                   & (IData)(vlSelf->tb_net__DOT__nic__DOT__tx_copied)) 
                  & (0U == (IData)(vlSelf->tb_net__DOT__nic__DOT__tx_wait))) 
                 & (~ (((IData)(vlSelf->tb_net__DOT____Vcellinp__nic__acc) 
                        & (IData)(vlSelf->we)) & (0U 
                                                  == (IData)(vlSelf->port)))))) {
                vlSelf->__Vdly__tb_net__DOT__nic__DOT__cr 
                    = (0xfbU & (IData)(vlSelf->tb_net__DOT__nic__DOT__cr));
                vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_pending = 0U;
                vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_copied = 0U;
                if (vlSelf->tb_net__DOT__nic__DOT__tx_copied_ok) {
                    vlSelf->tb_net__DOT__nic__DOT__tsr = 1U;
                    vlSelf->tb_net__DOT__nic__DOT__dbg_tx 
                        = ((IData)(1U) + vlSelf->tb_net__DOT__nic__DOT__dbg_tx);
                } else {
                    vlSelf->tb_net__DOT__nic__DOT__tsr = 0x10U;
                }
                vlSelf->tb_net__DOT__nic__DOT__iset 
                    = (((IData)(vlSelf->tb_net__DOT__nic__DOT__iset) 
                        | ((IData)(vlSelf->tb_net__DOT__nic__DOT__tx_copied_ok)
                            ? 2U : 8U)) | ((1U & (IData)(vlSelf->tb_net__DOT__nic__DOT__cr))
                                            ? 0x80U
                                            : 0U));
            }
            if (((IData)(vlSelf->tb_net__DOT__rx_offer) 
                 & (~ (IData)(vlSelf->tb_net__DOT__rx_busy)))) {
                vlSelf->__Vdly__tb_net__DOT__nic__DOT__off_q = 1U;
            }
            if (vlSelf->tb_net__DOT__nic__DOT__off_q) {
                vlSelf->__Vdly__tb_net__DOT__nic__DOT__off_q = 0U;
                vlSelf->tb_net__DOT__rx_answer = 1U;
                vlSelf->tb_net__DOT__rx_take = 0U;
                if ((1U & (~ (((2U != (3U & (IData)(vlSelf->tb_net__DOT__nic__DOT__cr))) 
                               | (0xeU > (IData)(vlSelf->tb_net__DOT__nic__DOT__off_len))) 
                              | (0x5eeU < (IData)(vlSelf->tb_net__DOT__nic__DOT__off_len)))))) {
                    if (vlSelf->tb_net__DOT__nic__DOT__o_acc) {
                        if ((0x20U & (IData)(vlSelf->tb_net__DOT__nic__DOT__rcr))) {
                            if ((0x7fU == vlSelf->tb_net__DOT__nic__DOT__tally
                                 [2U])) {
                                vlSelf->tb_net__DOT__nic__DOT__iset 
                                    = (0x20U | (IData)(vlSelf->tb_net__DOT__nic__DOT__iset));
                            }
                            __Vdlyvval__tb_net__DOT__nic__DOT__tally__v1 
                                = (0xffU & ((IData)(1U) 
                                            + vlSelf->tb_net__DOT__nic__DOT__tally
                                            [2U]));
                            vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v1 = 1U;
                        } else if (vlSelf->tb_net__DOT__nic__DOT__o_ring_ok) {
                            if ((1U & (((IData)(vlSelf->tb_net__DOT__nic__DOT__isr) 
                                        >> 4U) | ((IData)(vlSelf->tb_net__DOT__nic__DOT__o_bnry_in) 
                                                  & ((0xffU 
                                                      & VL_SHIFTR_III(12,12,32, 
                                                                      (0xfffU 
                                                                       & ((IData)(0x107U) 
                                                                          + (IData)(vlSelf->tb_net__DOT__nic__DOT__o_pad))), 8U)) 
                                                     >= (IData)(vlSelf->tb_net__DOT__nic__DOT__o_avail)))))) {
                                vlSelf->tb_net__DOT__nic__DOT__iset 
                                    = (0x10U | (IData)(vlSelf->tb_net__DOT__nic__DOT__iset));
                                vlSelf->tb_net__DOT__nic__DOT__rsr = 0x10U;
                                if ((0x7fU == vlSelf->tb_net__DOT__nic__DOT__tally
                                     [2U])) {
                                    vlSelf->tb_net__DOT__nic__DOT__iset 
                                        = (0x20U | (IData)(vlSelf->tb_net__DOT__nic__DOT__iset));
                                }
                                __Vdlyvval__tb_net__DOT__nic__DOT__tally__v2 
                                    = (0xffU & ((IData)(1U) 
                                                + vlSelf->tb_net__DOT__nic__DOT__tally
                                                [2U]));
                                vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v2 = 1U;
                            } else {
                                vlSelf->tb_net__DOT__rx_take = 1U;
                                vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_st = 1U;
                                vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_len 
                                    = vlSelf->tb_net__DOT__nic__DOT__off_len;
                                vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_n = 0U;
                                vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_pad 
                                    = vlSelf->tb_net__DOT__nic__DOT__o_pad;
                                vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_cnt 
                                    = (0xfffU & ((IData)(4U) 
                                                 + (IData)(vlSelf->tb_net__DOT__nic__DOT__o_pad)));
                                vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_next 
                                    = vlSelf->tb_net__DOT__nic__DOT__o_next;
                                vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_page 
                                    = vlSelf->tb_net__DOT__nic__DOT__curr;
                                vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_group 
                                    = (1U & (IData)(
                                                    (vlSelf->tb_net__DOT__nic__DOT__off_dst 
                                                     >> 0x28U)));
                                vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_crc = 0xffffffffU;
                                vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_k = 0U;
                                vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_ptr 
                                    = (4U | ((IData)(vlSelf->tb_net__DOT__nic__DOT__curr) 
                                             << 8U));
                            }
                        }
                    }
                }
            }
            if (((IData)(vlSelf->tb_net__DOT__rx_offer) 
                 & (~ (IData)(vlSelf->tb_net__DOT__rx_busy)))) {
                vlSelf->tb_net__DOT__nic__DOT__off_len 
                    = vlSelf->tb_net__DOT__rx_len;
                vlSelf->tb_net__DOT__nic__DOT__off_dst 
                    = vlSelf->tb_net__DOT__rx_dst;
            }
            if ((4U & (IData)(vlSelf->tb_net__DOT__nic__DOT__r_st))) {
                if ((1U & (~ ((IData)(vlSelf->tb_net__DOT__nic__DOT__r_st) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelf->tb_net__DOT__nic__DOT__r_st)))) {
                        vlSelf->tb_net__DOT__nic__DOT__wb = 1U;
                        vlSelf->tb_net__DOT__nic__DOT__wb_a 
                            = ((0x3f00U & ((IData)(vlSelf->tb_net__DOT__nic__DOT__r_page) 
                                           << 8U)) 
                               | (IData)(vlSelf->tb_net__DOT__nic__DOT__r_k));
                        vlSelf->tb_net__DOT__nic__DOT__wb_d 
                            = (0xffU & ((0U == (IData)(vlSelf->tb_net__DOT__nic__DOT__r_k))
                                         ? (1U | ((IData)(vlSelf->tb_net__DOT__nic__DOT__r_group)
                                                   ? 0x20U
                                                   : 0U))
                                         : ((1U == (IData)(vlSelf->tb_net__DOT__nic__DOT__r_k))
                                             ? (IData)(vlSelf->tb_net__DOT__nic__DOT__r_next)
                                             : ((2U 
                                                 == (IData)(vlSelf->tb_net__DOT__nic__DOT__r_k))
                                                 ? (IData)(vlSelf->tb_net__DOT__nic__DOT__r_cnt)
                                                 : 
                                                (0xfU 
                                                 & ((IData)(vlSelf->tb_net__DOT__nic__DOT__r_cnt) 
                                                    >> 8U))))));
                        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_k 
                            = (3U & ((IData)(1U) + (IData)(vlSelf->tb_net__DOT__nic__DOT__r_k)));
                        if ((3U == (IData)(vlSelf->tb_net__DOT__nic__DOT__r_k))) {
                            vlSelf->tb_net__DOT__nic__DOT__iset 
                                = (1U | (IData)(vlSelf->tb_net__DOT__nic__DOT__iset));
                            vlSelf->tb_net__DOT__nic__DOT__dbg_rx 
                                = ((IData)(1U) + vlSelf->tb_net__DOT__nic__DOT__dbg_rx);
                            vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_st = 0U;
                            vlSelf->__Vdly__tb_net__DOT__nic__DOT__curr 
                                = vlSelf->tb_net__DOT__nic__DOT__r_next;
                            vlSelf->tb_net__DOT__nic__DOT__rsr 
                                = (1U | ((IData)(vlSelf->tb_net__DOT__nic__DOT__r_group)
                                          ? 0x20U : 0U));
                        }
                    }
                }
            } else if ((2U & (IData)(vlSelf->tb_net__DOT__nic__DOT__r_st))) {
                if ((1U & (IData)(vlSelf->tb_net__DOT__nic__DOT__r_st))) {
                    vlSelf->tb_net__DOT__nic__DOT__wb = 1U;
                    vlSelf->tb_net__DOT__nic__DOT__wb_a 
                        = (0x3fffU & (IData)(vlSelf->tb_net__DOT__nic__DOT__r_ptr));
                    vlSelf->tb_net__DOT__nic__DOT__wb_d 
                        = (0xffU & (~ (vlSelf->tb_net__DOT__nic__DOT__r_crc 
                                       >> (0x1fU & 
                                           VL_SHIFTL_III(5,32,32, (IData)(vlSelf->tb_net__DOT__nic__DOT__r_k), 3U)))));
                    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_ptr 
                        = vlSelf->tb_net__DOT__nic__DOT__r_ptr_n;
                    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_k 
                        = (3U & ((IData)(1U) + (IData)(vlSelf->tb_net__DOT__nic__DOT__r_k)));
                    if ((3U == (IData)(vlSelf->tb_net__DOT__nic__DOT__r_k))) {
                        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_st = 4U;
                        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_k = 0U;
                    }
                } else {
                    __Vfunc_tb_net__DOT__nic__DOT__crc8__5__c 
                        = vlSelf->tb_net__DOT__nic__DOT__r_crc;
                    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_n 
                        = (0x7ffU & ((IData)(1U) + (IData)(vlSelf->tb_net__DOT__nic__DOT__r_n)));
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = __Vfunc_tb_net__DOT__nic__DOT__crc8__5__c;
                    vlSelf->tb_net__DOT__nic__DOT__wb = 1U;
                    vlSelf->tb_net__DOT__nic__DOT__wb_a 
                        = (0x3fffU & (IData)(vlSelf->tb_net__DOT__nic__DOT__r_ptr));
                    vlSelf->tb_net__DOT__nic__DOT__wb_d = 0U;
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    if (((0x7ffU & ((IData)(1U) + (IData)(vlSelf->tb_net__DOT__nic__DOT__r_n))) 
                         == (IData)(vlSelf->tb_net__DOT__nic__DOT__r_pad))) {
                        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_st = 3U;
                    }
                    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_ptr 
                        = vlSelf->tb_net__DOT__nic__DOT__r_ptr_n;
                    __Vfunc_tb_net__DOT__nic__DOT__crc8__5__Vfuncout 
                        = vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x;
                    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_crc 
                        = __Vfunc_tb_net__DOT__nic__DOT__crc8__5__Vfuncout;
                }
            } else if ((1U & (IData)(vlSelf->tb_net__DOT__nic__DOT__r_st))) {
                if (vlSelf->tb_net__DOT__rx_byte) {
                    __Vfunc_tb_net__DOT__nic__DOT__crc8__6__b 
                        = vlSelf->tb_net__DOT__rx_data;
                    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_n 
                        = (0x7ffU & ((IData)(1U) + (IData)(vlSelf->tb_net__DOT__nic__DOT__r_n)));
                    __Vfunc_tb_net__DOT__nic__DOT__crc8__6__c 
                        = vlSelf->tb_net__DOT__nic__DOT__r_crc;
                    vlSelf->tb_net__DOT__nic__DOT__wb = 1U;
                    vlSelf->tb_net__DOT__nic__DOT__wb_a 
                        = (0x3fffU & (IData)(vlSelf->tb_net__DOT__nic__DOT__r_ptr));
                    vlSelf->tb_net__DOT__nic__DOT__wb_d 
                        = vlSelf->tb_net__DOT__rx_data;
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = (__Vfunc_tb_net__DOT__nic__DOT__crc8__6__c 
                           ^ (IData)(__Vfunc_tb_net__DOT__nic__DOT__crc8__6__b));
                    if (((0x7ffU & ((IData)(1U) + (IData)(vlSelf->tb_net__DOT__nic__DOT__r_n))) 
                         == (IData)(vlSelf->tb_net__DOT__nic__DOT__r_len))) {
                        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_st 
                            = (((IData)(vlSelf->tb_net__DOT__nic__DOT__r_len) 
                                < (IData)(vlSelf->tb_net__DOT__nic__DOT__r_pad))
                                ? 2U : 3U);
                    }
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x 
                        = ((1U & vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x)
                            ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U))
                            : VL_SHIFTR_III(32,32,32, vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x, 1U));
                    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_ptr 
                        = vlSelf->tb_net__DOT__nic__DOT__r_ptr_n;
                    __Vfunc_tb_net__DOT__nic__DOT__crc8__6__Vfuncout 
                        = vlSelf->tb_net__DOT__nic__DOT__crc8__Vstatic__x;
                    vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_crc 
                        = __Vfunc_tb_net__DOT__nic__DOT__crc8__6__Vfuncout;
                }
            }
            vlSelf->tb_net__DOT__nic__DOT__isr = (((IData)(vlSelf->tb_net__DOT__nic__DOT__isr) 
                                                   & (~ (IData)(vlSelf->tb_net__DOT__nic__DOT__iclr))) 
                                                  | (IData)(vlSelf->tb_net__DOT__nic__DOT__iset));
            if (vlSelf->tb_net__DOT__nic__DOT__nreset) {
                vlSelf->__Vdly__tb_net__DOT__nic__DOT__cr = 0x21U;
                vlSelf->tb_net__DOT__nic__DOT__isr = 0x80U;
                vlSelf->tb_net__DOT__nic__DOT__imr = 0U;
                vlSelf->__Vdly__tb_net__DOT__nic__DOT__rbcr = 0U;
                vlSelf->tb_net__DOT__nic__DOT__tsr = 0U;
                vlSelf->tb_net__DOT__nic__DOT__rsr = 0U;
                vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_pending = 0U;
                vlSelf->__Vdly__tb_net__DOT__tx_req = 0U;
                vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_copied = 0U;
                vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v3 = 1U;
            }
        }
    } else {
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__curr = 0U;
        vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v6 = 1U;
        vlSelf->__Vdly__tb_net__DOT__tx_req = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_copied = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__off_q = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_st = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_ptr = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_n = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_crc = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_k = 0U;
        vlSelf->tb_net__DOT__nic__DOT__dbg_rx = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__cr = 0x21U;
        vlSelf->tb_net__DOT__nic__DOT__isr = 0x80U;
        vlSelf->tb_net__DOT__nic__DOT__imr = 0U;
        vlSelf->tb_net__DOT__nic__DOT__dcr = 4U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__rcr = 0U;
        vlSelf->tb_net__DOT__nic__DOT__tcr = 0U;
        vlSelf->tb_net__DOT__nic__DOT__tsr = 0U;
        vlSelf->tb_net__DOT__nic__DOT__rsr = 0U;
        vlSelf->tb_net__DOT__nic__DOT__pstart = 0U;
        vlSelf->tb_net__DOT__nic__DOT__pstop = 0U;
        vlSelf->tb_net__DOT__nic__DOT__bnry = 0U;
        vlSelf->tb_net__DOT__nic__DOT__tpsr = 0U;
        vlSelf->tb_net__DOT__nic__DOT__rsar = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__rbcr = 0U;
        vlSelf->tb_net__DOT__nic__DOT__tbcr = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_pending = 0U;
        vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__par__v1 = 1U;
        vlSelf->tb_net__DOT__nic__DOT__wa_e = 0U;
        vlSelf->tb_net__DOT__nic__DOT__wa_o = 0U;
        vlSelf->tb_net__DOT__nic__DOT__wa_e_i = 0U;
        vlSelf->tb_net__DOT__nic__DOT__wa_o_i = 0U;
        vlSelf->tb_net__DOT__nic__DOT__wa_e_d = 0U;
        vlSelf->tb_net__DOT__nic__DOT__wa_o_d = 0U;
        vlSelf->tb_net__DOT__nic__DOT__wb = 0U;
        vlSelf->tb_net__DOT__nic__DOT__wb_a = 0U;
        vlSelf->tb_net__DOT__nic__DOT__wb_d = 0U;
        vlSelf->tb_net__DOT__tx_base = 0U;
        vlSelf->tb_net__DOT__tx_len = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_wait = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_copied_ok = 0U;
        vlSelf->tb_net__DOT__rx_answer = 0U;
        vlSelf->tb_net__DOT__rx_take = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_len = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_pad = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_cnt = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_next = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_page = 0U;
        vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_group = 0U;
        vlSelf->tb_net__DOT__nic__DOT__dbg_tx = 0U;
        vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__par__v2 = 1U;
        vlSelf->tb_net__DOT__nic__DOT__off_len = 0U;
        vlSelf->tb_net__DOT__nic__DOT__off_dst = 0ULL;
    }
    vlSelf->tb_net__DOT__tx_ok = vlSelf->__Vdly__tb_net__DOT__tx_ok;
    vlSelf->tb_net__DOT__rx_byte = vlSelf->__Vdly__tb_net__DOT__rx_byte;
    vlSelf->tb_net__DOT__rx_data = vlSelf->__Vdly__tb_net__DOT__rx_data;
    vlSelf->tb_net__DOT__nic__DOT__tx_pending = vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_pending;
    vlSelf->tb_net__DOT__nic__DOT__tx_wait = vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_wait;
    vlSelf->tb_net__DOT__nic__DOT__tx_copied = vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_copied;
    vlSelf->tb_net__DOT__tx_req = vlSelf->__Vdly__tb_net__DOT__tx_req;
    vlSelf->tb_net__DOT__tx_done = vlSelf->__Vdly__tb_net__DOT__tx_done;
    vlSelf->tb_net__DOT__nic__DOT__tx_copied_ok = vlSelf->__Vdly__tb_net__DOT__nic__DOT__tx_copied_ok;
    vlSelf->tb_net__DOT__nic__DOT__r_len = vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_len;
    vlSelf->tb_net__DOT__nic__DOT__r_n = vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_n;
    vlSelf->tb_net__DOT__nic__DOT__r_pad = vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_pad;
    vlSelf->tb_net__DOT__nic__DOT__r_cnt = vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_cnt;
    vlSelf->tb_net__DOT__nic__DOT__r_next = vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_next;
    vlSelf->tb_net__DOT__nic__DOT__r_page = vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_page;
    vlSelf->tb_net__DOT__nic__DOT__r_group = vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_group;
    vlSelf->tb_net__DOT__nic__DOT__r_crc = vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_crc;
    vlSelf->tb_net__DOT__nic__DOT__r_k = vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_k;
    vlSelf->tb_net__DOT__nic__DOT__off_q = vlSelf->__Vdly__tb_net__DOT__nic__DOT__off_q;
    vlSelf->tb_net__DOT__nic__DOT__r_st = vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_st;
    vlSelf->tb_net__DOT__nic__DOT__r_ptr = vlSelf->__Vdly__tb_net__DOT__nic__DOT__r_ptr;
    vlSelf->tb_net__DOT__nic__DOT__rcr = vlSelf->__Vdly__tb_net__DOT__nic__DOT__rcr;
    vlSelf->tb_net__DOT__nic__DOT__curr = vlSelf->__Vdly__tb_net__DOT__nic__DOT__curr;
    vlSelf->tb_net__DOT__nic__DOT__rbcr = vlSelf->__Vdly__tb_net__DOT__nic__DOT__rbcr;
    vlSelf->tb_net__DOT__nic__DOT__cr = vlSelf->__Vdly__tb_net__DOT__nic__DOT__cr;
    if (vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v0) {
        vlSelf->tb_net__DOT__nic__DOT__tally[__Vdlyvdim0__tb_net__DOT__nic__DOT__tally__v0] 
            = __Vdlyvval__tb_net__DOT__nic__DOT__tally__v0;
    }
    if (vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v1) {
        vlSelf->tb_net__DOT__nic__DOT__tally[2U] = __Vdlyvval__tb_net__DOT__nic__DOT__tally__v1;
    }
    if (vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v2) {
        vlSelf->tb_net__DOT__nic__DOT__tally[2U] = __Vdlyvval__tb_net__DOT__nic__DOT__tally__v2;
    }
    if (vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v3) {
        vlSelf->tb_net__DOT__nic__DOT__tally[0U] = 0U;
        vlSelf->tb_net__DOT__nic__DOT__tally[1U] = 0U;
        vlSelf->tb_net__DOT__nic__DOT__tally[2U] = 0U;
    }
    if (vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__tally__v6) {
        vlSelf->tb_net__DOT__nic__DOT__tally[0U] = 0U;
    }
    if (vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__mar__v0) {
        vlSelf->tb_net__DOT__nic__DOT__mar[__Vdlyvdim0__tb_net__DOT__nic__DOT__mar__v0] 
            = __Vdlyvval__tb_net__DOT__nic__DOT__mar__v0;
    }
    if (vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__par__v1) {
        vlSelf->tb_net__DOT__nic__DOT__tally[1U] = 0U;
        vlSelf->tb_net__DOT__nic__DOT__mar[0U] = 0U;
    }
    if (vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__par__v0) {
        vlSelf->tb_net__DOT__nic__DOT__par[__Vdlyvdim0__tb_net__DOT__nic__DOT__par__v0] 
            = __Vdlyvval__tb_net__DOT__nic__DOT__par__v0;
    }
    if (vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__par__v1) {
        vlSelf->tb_net__DOT__nic__DOT__par[0U] = 0U;
    }
    if (vlSelf->__Vdlyvset__tb_net__DOT__nic__DOT__par__v2) {
        vlSelf->tb_net__DOT__nic__DOT__tally[2U] = 0U;
        vlSelf->tb_net__DOT__nic__DOT__mar[1U] = 0U;
        vlSelf->tb_net__DOT__nic__DOT__mar[2U] = 0U;
        vlSelf->tb_net__DOT__nic__DOT__mar[3U] = 0U;
        vlSelf->tb_net__DOT__nic__DOT__mar[4U] = 0U;
        vlSelf->tb_net__DOT__nic__DOT__mar[5U] = 0U;
        vlSelf->tb_net__DOT__nic__DOT__mar[6U] = 0U;
        vlSelf->tb_net__DOT__nic__DOT__mar[7U] = 0U;
        vlSelf->tb_net__DOT__nic__DOT__par[1U] = 0U;
        vlSelf->tb_net__DOT__nic__DOT__par[2U] = 0U;
        vlSelf->tb_net__DOT__nic__DOT__par[3U] = 0U;
        vlSelf->tb_net__DOT__nic__DOT__par[4U] = 0U;
        vlSelf->tb_net__DOT__nic__DOT__par[5U] = 0U;
    }
    vlSelf->tb_net__DOT__nic__DOT__pb_a = ((IData)(vlSelf->tb_net__DOT__nic__DOT__wb)
                                            ? (IData)(vlSelf->tb_net__DOT__nic__DOT__wb_a)
                                            : (IData)(vlSelf->tb_net__DOT__b_addr));
    vlSelf->irq = (0U != (0x7fU & ((IData)(vlSelf->tb_net__DOT__nic__DOT__imr) 
                                   & (IData)(vlSelf->tb_net__DOT__nic__DOT__isr))));
    vlSelf->tb_net__DOT__nic__DOT__dma_wr_ok = (IData)(
                                                       ((0x10U 
                                                         == 
                                                         (0x38U 
                                                          & (IData)(vlSelf->tb_net__DOT__nic__DOT__cr))) 
                                                        & (0U 
                                                           != (IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr))));
    vlSelf->tb_net__DOT__nic__DOT__dma_rd_ok = (IData)(
                                                       ((8U 
                                                         == 
                                                         (0x38U 
                                                          & (IData)(vlSelf->tb_net__DOT__nic__DOT__cr))) 
                                                        & (0U 
                                                           != (IData)(vlSelf->tb_net__DOT__nic__DOT__rbcr))));
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
    vlSelf->tb_net__DOT__rx_len = vlSelf->__Vdly__tb_net__DOT__rx_len;
    vlSelf->tb_net__DOT__rx_dst = vlSelf->__Vdly__tb_net__DOT__rx_dst;
    vlSelf->tb_net__DOT__rx_offer = vlSelf->__Vdly__tb_net__DOT__rx_offer;
    vlSelf->tb_net__DOT__rx_busy = ((0U != (IData)(vlSelf->tb_net__DOT__nic__DOT__r_st)) 
                                    | (IData)(vlSelf->tb_net__DOT__nic__DOT__off_q));
    vlSelf->tb_net__DOT__cen = vlSelf->__Vdly__tb_net__DOT__cen;
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
    vlSelf->tb_net__DOT__nic__DOT__o_pad = ((0x3cU 
                                             > (IData)(vlSelf->tb_net__DOT__nic__DOT__off_len))
                                             ? 0x3cU
                                             : (IData)(vlSelf->tb_net__DOT__nic__DOT__off_len));
    vlSelf->cen_o = vlSelf->tb_net__DOT__cen;
    vlSelf->tb_net__DOT____Vcellinp__nic__acc = ((IData)(vlSelf->acc) 
                                                 & (IData)(vlSelf->tb_net__DOT__cen));
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
    vlSelf->tb_net__DOT__nic__DOT__o_next = (0xffU 
                                             & (((IData)(tb_net__DOT__nic__DOT__o_next0) 
                                                 >= (IData)(vlSelf->tb_net__DOT__nic__DOT__pstop))
                                                 ? 
                                                ((IData)(tb_net__DOT__nic__DOT__o_next0) 
                                                 - 
                                                 ((IData)(vlSelf->tb_net__DOT__nic__DOT__pstop) 
                                                  - (IData)(vlSelf->tb_net__DOT__nic__DOT__pstart)))
                                                 : (IData)(tb_net__DOT__nic__DOT__o_next0)));
}

VL_INLINE_OPT void Vtb_net___024root___nba_comb__TOP__0(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___nba_comb__TOP__0\n"); );
    // Init
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
    // Body
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

void Vtb_net___024root___eval_nba(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_net___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_net___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_net___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_net___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vtb_net___024root___eval_triggers__act(Vtb_net___024root* vlSelf);

bool Vtb_net___024root___eval_phase__act(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_net___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_net___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_net___024root___eval_phase__nba(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_net___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_net___024root___dump_triggers__ico(Vtb_net___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_net___024root___dump_triggers__nba(Vtb_net___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_net___024root___dump_triggers__act(Vtb_net___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_net___024root___eval(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___eval\n"); );
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
            Vtb_net___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("tb_net.sv", 5, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtb_net___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_net___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb_net.sv", 5, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_net___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb_net.sv", 5, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_net___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_net___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_net___024root___eval_debug_assertions(Vtb_net___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_net__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_net___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->enable & 0xfeU))) {
        Verilated::overWidthError("enable");}
    if (VL_UNLIKELY((vlSelf->acc & 0xfeU))) {
        Verilated::overWidthError("acc");}
    if (VL_UNLIKELY((vlSelf->we & 0xfeU))) {
        Verilated::overWidthError("we");}
    if (VL_UNLIKELY((vlSelf->wide & 0xfeU))) {
        Verilated::overWidthError("wide");}
    if (VL_UNLIKELY((vlSelf->port & 0xe0U))) {
        Verilated::overWidthError("port");}
    if (VL_UNLIKELY((vlSelf->ddr_busy & 0xfeU))) {
        Verilated::overWidthError("ddr_busy");}
    if (VL_UNLIKELY((vlSelf->ddr_dout_ready & 0xfeU))) {
        Verilated::overWidthError("ddr_dout_ready");}
}
#endif  // VL_DEBUG
