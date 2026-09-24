// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdr840_pclink.h for the primary calling header

#include "Vdr840_pclink__pch.h"
#include "Vdr840_pclink___024root.h"

VL_INLINE_OPT void Vdr840_pclink___024root___ico_sequent__TOP__0(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___ico_sequent__TOP__0\n"); );
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
    vlSelf->dr840_pclink__DOT__can_send = ((IData)(vlSelf->uart_on) 
                                           & ((~ (IData)(vlSelf->grx_full)) 
                                              & ((0U 
                                                  == vlSelf->dr840_pclink__DOT__pace) 
                                                 & (2U 
                                                    == (IData)(vlSelf->state)))));
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

void Vdr840_pclink___024root___eval_ico(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vdr840_pclink___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vdr840_pclink___024root___eval_triggers__ico(Vdr840_pclink___024root* vlSelf);

bool Vdr840_pclink___024root___eval_phase__ico(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vdr840_pclink___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vdr840_pclink___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vdr840_pclink___024root___eval_act(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vdr840_pclink___024root___nba_sequent__TOP__0(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdly__dr840_pclink__DOT__idle_cnt = vlSelf->dr840_pclink__DOT__idle_cnt;
    vlSelf->__Vdly__dr840_pclink__DOT__ridx = vlSelf->dr840_pclink__DOT__ridx;
    vlSelf->__Vdly__dr840_pclink__DOT__crc = vlSelf->dr840_pclink__DOT__crc;
    vlSelf->__Vdly__dr840_pclink__DOT__at = vlSelf->dr840_pclink__DOT__at;
    vlSelf->__Vdly__grx_tog = vlSelf->grx_tog;
    vlSelf->__Vdly__dr840_pclink__DOT__tx_st = vlSelf->dr840_pclink__DOT__tx_st;
    vlSelf->__Vdly__dr840_pclink__DOT__pong_pend = vlSelf->dr840_pclink__DOT__pong_pend;
    vlSelf->__Vdly__dr840_pclink__DOT__offered = vlSelf->dr840_pclink__DOT__offered;
    vlSelf->__Vdly__dr840_pclink__DOT__cmd_tag = vlSelf->dr840_pclink__DOT__cmd_tag;
    vlSelf->__Vdly__dr840_pclink__DOT__gshift = vlSelf->dr840_pclink__DOT__gshift;
    vlSelf->__Vdly__dr840_pclink__DOT__rx_rem = vlSelf->dr840_pclink__DOT__rx_rem;
    vlSelf->__Vdly__wr_ack = vlSelf->wr_ack;
    vlSelf->__Vdly__dr840_pclink__DOT__reading = vlSelf->dr840_pclink__DOT__reading;
    vlSelf->__Vdly__state = vlSelf->state;
    vlSelf->__Vdly__dr840_pclink__DOT__pace = vlSelf->dr840_pclink__DOT__pace;
    vlSelf->__Vdly__dr840_pclink__DOT__cmd_idx = vlSelf->dr840_pclink__DOT__cmd_idx;
    vlSelf->__Vdly__dr840_pclink__DOT__seq = vlSelf->dr840_pclink__DOT__seq;
    vlSelf->__Vdly__dr840_pclink__DOT__rx_st = vlSelf->dr840_pclink__DOT__rx_st;
    vlSelf->__Vdly__dr840_pclink__DOT__cmd_rem = vlSelf->dr840_pclink__DOT__cmd_rem;
    vlSelf->__Vdly__dr840_pclink__DOT__mi = vlSelf->dr840_pclink__DOT__mi;
    if (vlSelf->rst_n) {
        if (vlSelf->cen) {
            vlSelf->dr840_pclink__DOT__gtx_q = vlSelf->gtx_tog;
        }
    } else {
        vlSelf->dr840_pclink__DOT__gtx_q = 0U;
    }
}

VL_INLINE_OPT void Vdr840_pclink___024root___nba_sequent__TOP__1(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->__Vdlyvset__dr840_pclink__DOT__blk__v0 = 0U;
    if (vlSelf->cen) {
        if (vlSelf->dr840_pclink__DOT__fill_we) {
            vlSelf->__Vdlyvval__dr840_pclink__DOT__blk__v0 
                = vlSelf->dr840_pclink__DOT__fill_b;
            vlSelf->__Vdlyvset__dr840_pclink__DOT__blk__v0 = 1U;
            vlSelf->__Vdlyvdim0__dr840_pclink__DOT__blk__v0 
                = vlSelf->dr840_pclink__DOT__fill_at;
        }
    }
}

VL_INLINE_OPT void Vdr840_pclink___024root___nba_sequent__TOP__2(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___nba_sequent__TOP__2\n"); );
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
    IData/*31:0*/ __Vfunc_dr840_pclink__DOT__crc8__1__Vfuncout;
    __Vfunc_dr840_pclink__DOT__crc8__1__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_dr840_pclink__DOT__crc8__1__c;
    __Vfunc_dr840_pclink__DOT__crc8__1__c = 0;
    IData/*31:0*/ __Vfunc_dr840_pclink__DOT__crc8__2__Vfuncout;
    __Vfunc_dr840_pclink__DOT__crc8__2__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_dr840_pclink__DOT__crc8__2__c;
    __Vfunc_dr840_pclink__DOT__crc8__2__c = 0;
    CData/*7:0*/ __Vfunc_dr840_pclink__DOT__crc8__2__b;
    __Vfunc_dr840_pclink__DOT__crc8__2__b = 0;
    // Body
    if (vlSelf->rst_n) {
        if (vlSelf->cen) {
            vlSelf->dr840_pclink__DOT__fill_we = 0U;
            if ((0U != vlSelf->dr840_pclink__DOT__pace)) {
                vlSelf->__Vdly__dr840_pclink__DOT__pace 
                    = (0x7fffffU & (vlSelf->dr840_pclink__DOT__pace 
                                    - (IData)(1U)));
            }
            if (vlSelf->pmem_req) {
                if (vlSelf->pmem_ack) {
                    vlSelf->pmem_req = 0U;
                    if (vlSelf->dr840_pclink__DOT__reading) {
                        vlSelf->dr840_pclink__DOT__word 
                            = vlSelf->pmem_rdata;
                        vlSelf->dr840_pclink__DOT__word_ok = 1U;
                        vlSelf->__Vdly__dr840_pclink__DOT__reading = 0U;
                    } else {
                        vlSelf->__Vdly__wr_ack = 1U;
                    }
                }
            } else if (vlSelf->wr_ack) {
                if ((1U & (~ (IData)(vlSelf->wr_req)))) {
                    vlSelf->__Vdly__wr_ack = 0U;
                }
            } else if (vlSelf->wr_req) {
                vlSelf->pmem_addr = (0x1ffffffU & ((IData)(0x1000000U) 
                                                   + 
                                                   (0x1fffffcU 
                                                    & vlSelf->wr_addr)));
                vlSelf->pmem_wdata = vlSelf->wr_data;
                vlSelf->pmem_we = 1U;
                vlSelf->pmem_req = 1U;
                vlSelf->dr840_pclink__DOT__word_ok = 0U;
            } else if ((((1U == (IData)(vlSelf->dr840_pclink__DOT__tx_st)) 
                         & (~ (IData)(vlSelf->dr840_pclink__DOT__have_word))) 
                        & (~ (IData)(vlSelf->dr840_pclink__DOT__reading)))) {
                vlSelf->__Vdly__dr840_pclink__DOT__reading = 1U;
                vlSelf->pmem_addr = (0x1ffffffU & ((IData)(0x1000000U) 
                                                   + 
                                                   (0x1fffffcU 
                                                    & vlSelf->dr840_pclink__DOT__mi)));
                vlSelf->dr840_pclink__DOT__word_addr 
                    = (0x7fffffU & (vlSelf->dr840_pclink__DOT__mi 
                                    >> 2U));
                vlSelf->dr840_pclink__DOT__word_ok = 0U;
                vlSelf->pmem_we = 0U;
                vlSelf->pmem_req = 1U;
            }
            if (((IData)(vlSelf->dr840_pclink__DOT__rx_v) 
                 & (0U != (IData)(vlSelf->state)))) {
                if (vlSelf->dr840_pclink__DOT__greeted) {
                    if ((4U & (IData)(vlSelf->dr840_pclink__DOT__rx_st))) {
                        vlSelf->__Vdly__dr840_pclink__DOT__rx_st 
                            = (7U & ((2U & (IData)(vlSelf->dr840_pclink__DOT__rx_st))
                                      ? ((1U & (IData)(vlSelf->dr840_pclink__DOT__rx_st))
                                          ? ((IData)(1U) 
                                             + (IData)(vlSelf->dr840_pclink__DOT__rx_st))
                                          : 0U) : ((IData)(1U) 
                                                   + (IData)(vlSelf->dr840_pclink__DOT__rx_st))));
                    } else if ((2U & (IData)(vlSelf->dr840_pclink__DOT__rx_st))) {
                        if ((1U & (IData)(vlSelf->dr840_pclink__DOT__rx_st))) {
                            vlSelf->__Vdly__dr840_pclink__DOT__rx_st 
                                = (7U & ((IData)(1U) 
                                         + (IData)(vlSelf->dr840_pclink__DOT__rx_st)));
                        } else {
                            vlSelf->__Vdly__dr840_pclink__DOT__rx_rem 
                                = (0xffffU & ((IData)(vlSelf->dr840_pclink__DOT__rx_rem) 
                                              - (IData)(1U)));
                            if (vlSelf->dr840_pclink__DOT__escaped) {
                                vlSelf->dr840_pclink__DOT__escaped = 0U;
                            } else if ((0x10U == (IData)(vlSelf->gtx_data))) {
                                vlSelf->dr840_pclink__DOT__escaped = 1U;
                            }
                            if ((1U == (IData)(vlSelf->dr840_pclink__DOT__rx_rem))) {
                                vlSelf->__Vdly__dr840_pclink__DOT__rx_st = 3U;
                            }
                        }
                    } else if ((1U & (IData)(vlSelf->dr840_pclink__DOT__rx_st))) {
                        vlSelf->__Vdly__dr840_pclink__DOT__rx_st 
                            = ((0U == ((0xff00U & (IData)(vlSelf->dr840_pclink__DOT__rx_rem)) 
                                       | (IData)(vlSelf->gtx_data)))
                                ? 3U : 2U);
                        vlSelf->__Vdly__dr840_pclink__DOT__rx_rem 
                            = ((0xff00U & (IData)(vlSelf->__Vdly__dr840_pclink__DOT__rx_rem)) 
                               | (IData)(vlSelf->gtx_data));
                    } else {
                        vlSelf->__Vdly__dr840_pclink__DOT__rx_rem 
                            = ((0xffU & (IData)(vlSelf->__Vdly__dr840_pclink__DOT__rx_rem)) 
                               | ((IData)(vlSelf->gtx_data) 
                                  << 8U));
                        vlSelf->__Vdly__dr840_pclink__DOT__rx_st = 1U;
                    }
                } else {
                    vlSelf->__Vdly__dr840_pclink__DOT__gshift 
                        = ((vlSelf->dr840_pclink__DOT__gshift 
                            << 8U) | (IData)(vlSelf->gtx_data));
                    if ((0x43684d61U == ((vlSelf->dr840_pclink__DOT__gshift 
                                          << 8U) | (IData)(vlSelf->gtx_data)))) {
                        vlSelf->dr840_pclink__DOT__greeted = 1U;
                    }
                }
            }
            if (vlSelf->dr840_pclink__DOT__feed_v) {
                if (vlSelf->dr840_pclink__DOT__cmd_skip) {
                    vlSelf->__Vdly__dr840_pclink__DOT__cmd_rem 
                        = (vlSelf->dr840_pclink__DOT__cmd_rem 
                           - (IData)(1U));
                    if ((1U == vlSelf->dr840_pclink__DOT__cmd_rem)) {
                        vlSelf->dr840_pclink__DOT__cmd_skip = 0U;
                    }
                } else {
                    vlSelf->__Vdly__dr840_pclink__DOT__cmd_idx 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->dr840_pclink__DOT__cmd_idx)));
                    if ((4U > (IData)(vlSelf->dr840_pclink__DOT__cmd_idx))) {
                        vlSelf->__Vdly__dr840_pclink__DOT__cmd_tag 
                            = ((vlSelf->dr840_pclink__DOT__cmd_tag 
                                << 8U) | (IData)(vlSelf->gtx_data));
                    } else {
                        vlSelf->__Vdly__dr840_pclink__DOT__cmd_rem 
                            = ((vlSelf->dr840_pclink__DOT__cmd_rem 
                                << 8U) | (IData)(vlSelf->gtx_data));
                    }
                    if ((7U == (IData)(vlSelf->dr840_pclink__DOT__cmd_idx))) {
                        vlSelf->__Vdly__dr840_pclink__DOT__cmd_idx = 0U;
                        if ((0U != vlSelf->dr840_pclink__DOT__cmd_len_now)) {
                            vlSelf->dr840_pclink__DOT__cmd_skip = 1U;
                        }
                    }
                }
            }
            if (vlSelf->dr840_pclink__DOT__dispatch) {
                if ((0x436e6374U == vlSelf->dr840_pclink__DOT__cmd_tag)) {
                    if ((1U & (~ (IData)(vlSelf->dr840_pclink__DOT__offered)))) {
                        vlSelf->__Vdly__dr840_pclink__DOT__offered = 1U;
                        vlSelf->__Vdly__state = 2U;
                        vlSelf->__Vdly__dr840_pclink__DOT__seq = 1U;
                    }
                } else if ((0x50696e67U == vlSelf->dr840_pclink__DOT__cmd_tag)) {
                    if ((0xfU != (IData)(vlSelf->dr840_pclink__DOT__pong_pend))) {
                        vlSelf->__Vdly__dr840_pclink__DOT__pong_pend 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->dr840_pclink__DOT__pong_pend)));
                    }
                } else if ((0x506f6e67U == vlSelf->dr840_pclink__DOT__cmd_tag)) {
                    if ((((((2U == (IData)(vlSelf->state)) 
                            & (IData)(vlSelf->dr840_pclink__DOT__offered)) 
                           & (0U == (IData)(vlSelf->dr840_pclink__DOT__seq))) 
                          & (0U == (IData)(vlSelf->dr840_pclink__DOT__tx_st))) 
                         & (0U == (IData)(vlSelf->dr840_pclink__DOT__pong_pend)))) {
                        vlSelf->__Vdly__state = 3U;
                    }
                } else if (((0x47427965U == vlSelf->dr840_pclink__DOT__cmd_tag) 
                            | (0x41627274U == vlSelf->dr840_pclink__DOT__cmd_tag))) {
                    if (((3U != (IData)(vlSelf->state)) 
                         & (0U != (IData)(vlSelf->state)))) {
                        vlSelf->__Vdly__state = 4U;
                    }
                }
            }
            if ((8U & (IData)(vlSelf->dr840_pclink__DOT__tx_st))) {
                if ((4U & (IData)(vlSelf->dr840_pclink__DOT__tx_st))) {
                    vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 0U;
                } else if ((2U & (IData)(vlSelf->dr840_pclink__DOT__tx_st))) {
                    vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 0U;
                } else if ((1U & (IData)(vlSelf->dr840_pclink__DOT__tx_st))) {
                    vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 0U;
                } else if (vlSelf->dr840_pclink__DOT__can_send) {
                    vlSelf->__Vdly__grx_tog = (1U & 
                                               (~ (IData)(vlSelf->grx_tog)));
                    vlSelf->grx_data = (0xffU & vlSelf->dr840_pclink__DOT__crc);
                    vlSelf->__Vdly__dr840_pclink__DOT__pace 
                        = vlSelf->dr840_pclink__DOT__byte_cen;
                    if ((vlSelf->dr840_pclink__DOT__mi 
                         == vlSelf->dr840_pclink__DOT__msg_len)) {
                        vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 0U;
                    } else {
                        vlSelf->__Vdly__dr840_pclink__DOT__at = 0U;
                        vlSelf->__Vdly__dr840_pclink__DOT__crc = 0xffffffffU;
                        vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 1U;
                    }
                }
            } else if ((4U & (IData)(vlSelf->dr840_pclink__DOT__tx_st))) {
                if ((2U & (IData)(vlSelf->dr840_pclink__DOT__tx_st))) {
                    if ((1U & (IData)(vlSelf->dr840_pclink__DOT__tx_st))) {
                        if (vlSelf->dr840_pclink__DOT__can_send) {
                            vlSelf->__Vdly__grx_tog 
                                = (1U & (~ (IData)(vlSelf->grx_tog)));
                            vlSelf->grx_data = (0xffU 
                                                & (vlSelf->dr840_pclink__DOT__crc 
                                                   >> 8U));
                            vlSelf->__Vdly__dr840_pclink__DOT__pace 
                                = vlSelf->dr840_pclink__DOT__byte_cen;
                            vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 8U;
                        }
                    } else if (vlSelf->dr840_pclink__DOT__can_send) {
                        vlSelf->__Vdly__grx_tog = (1U 
                                                   & (~ (IData)(vlSelf->grx_tog)));
                        vlSelf->grx_data = (0xffU & 
                                            (vlSelf->dr840_pclink__DOT__crc 
                                             >> 0x10U));
                        vlSelf->__Vdly__dr840_pclink__DOT__pace 
                            = vlSelf->dr840_pclink__DOT__byte_cen;
                        vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 7U;
                    }
                } else if ((1U & (IData)(vlSelf->dr840_pclink__DOT__tx_st))) {
                    if (vlSelf->dr840_pclink__DOT__can_send) {
                        vlSelf->__Vdly__grx_tog = (1U 
                                                   & (~ (IData)(vlSelf->grx_tog)));
                        vlSelf->grx_data = (vlSelf->dr840_pclink__DOT__crc 
                                            >> 0x18U);
                        vlSelf->__Vdly__dr840_pclink__DOT__pace 
                            = vlSelf->dr840_pclink__DOT__byte_cen;
                        vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 6U;
                    }
                } else if (vlSelf->dr840_pclink__DOT__can_send) {
                    vlSelf->__Vdly__dr840_pclink__DOT__ridx 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->dr840_pclink__DOT__ridx)));
                    vlSelf->__Vdly__grx_tog = (1U & 
                                               (~ (IData)(vlSelf->grx_tog)));
                    vlSelf->grx_data = vlSelf->dr840_pclink__DOT__blk_q;
                    vlSelf->__Vdly__dr840_pclink__DOT__pace 
                        = vlSelf->dr840_pclink__DOT__byte_cen;
                    if (((0x1ffU & ((IData)(1U) + (IData)(vlSelf->dr840_pclink__DOT__ridx))) 
                         == (IData)(vlSelf->dr840_pclink__DOT__at))) {
                        vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 5U;
                    }
                }
            } else if ((2U & (IData)(vlSelf->dr840_pclink__DOT__tx_st))) {
                if ((1U & (IData)(vlSelf->dr840_pclink__DOT__tx_st))) {
                    if (vlSelf->dr840_pclink__DOT__can_send) {
                        vlSelf->__Vdly__grx_tog = (1U 
                                                   & (~ (IData)(vlSelf->grx_tog)));
                        vlSelf->grx_data = (0xffU & (IData)(vlSelf->dr840_pclink__DOT__at));
                        vlSelf->__Vdly__dr840_pclink__DOT__pace 
                            = vlSelf->dr840_pclink__DOT__byte_cen;
                        vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 4U;
                    }
                } else if (vlSelf->dr840_pclink__DOT__can_send) {
                    vlSelf->__Vdly__grx_tog = (1U & 
                                               (~ (IData)(vlSelf->grx_tog)));
                    vlSelf->grx_data = (1U & ((IData)(vlSelf->dr840_pclink__DOT__at) 
                                              >> 8U));
                    vlSelf->__Vdly__dr840_pclink__DOT__pace 
                        = vlSelf->dr840_pclink__DOT__byte_cen;
                    vlSelf->__Vdly__dr840_pclink__DOT__idle_cnt = 0U;
                    vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 3U;
                }
            } else if ((1U & (IData)(vlSelf->dr840_pclink__DOT__tx_st))) {
                if (vlSelf->dr840_pclink__DOT__have_word) {
                    if ((((0xeU == (IData)(vlSelf->dr840_pclink__DOT__sb)) 
                          | ((0xfU == (IData)(vlSelf->dr840_pclink__DOT__sb)) 
                             | (0x10U == (IData)(vlSelf->dr840_pclink__DOT__sb)))) 
                         & (~ (IData)(vlSelf->dr840_pclink__DOT__q_pend)))) {
                        __Vfunc_dr840_pclink__DOT__crc8__1__c 
                            = vlSelf->dr840_pclink__DOT__crc;
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = (0x10U ^ __Vfunc_dr840_pclink__DOT__crc8__1__c);
                        vlSelf->dr840_pclink__DOT__fill_we = 1U;
                        vlSelf->dr840_pclink__DOT__fill_b = 0x10U;
                        vlSelf->dr840_pclink__DOT__fill_at 
                            = (0xffU & (IData)(vlSelf->dr840_pclink__DOT__at));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->dr840_pclink__DOT__q_pend = 1U;
                        vlSelf->__Vdly__dr840_pclink__DOT__at 
                            = (0x1ffU & ((IData)(1U) 
                                         + (IData)(vlSelf->dr840_pclink__DOT__at)));
                        __Vfunc_dr840_pclink__DOT__crc8__1__Vfuncout 
                            = vlSelf->dr840_pclink__DOT__crc8__Vstatic__x;
                        vlSelf->__Vdly__dr840_pclink__DOT__crc 
                            = __Vfunc_dr840_pclink__DOT__crc8__1__Vfuncout;
                    } else {
                        __Vfunc_dr840_pclink__DOT__crc8__2__b 
                            = vlSelf->dr840_pclink__DOT__sb;
                        __Vfunc_dr840_pclink__DOT__crc8__2__c 
                            = vlSelf->dr840_pclink__DOT__crc;
                        vlSelf->dr840_pclink__DOT__fill_we = 1U;
                        vlSelf->dr840_pclink__DOT__fill_b 
                            = vlSelf->dr840_pclink__DOT__sb;
                        vlSelf->dr840_pclink__DOT__fill_at 
                            = (0xffU & (IData)(vlSelf->dr840_pclink__DOT__at));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = (__Vfunc_dr840_pclink__DOT__crc8__2__c 
                               ^ (IData)(__Vfunc_dr840_pclink__DOT__crc8__2__b));
                        vlSelf->dr840_pclink__DOT__q_pend = 0U;
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->dr840_pclink__DOT__crc8__Vstatic__x 
                            = ((1U & vlSelf->dr840_pclink__DOT__crc8__Vstatic__x)
                                ? (0xedb88320U ^ VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U))
                                : VL_SHIFTR_III(32,32,32, vlSelf->dr840_pclink__DOT__crc8__Vstatic__x, 1U));
                        vlSelf->__Vdly__dr840_pclink__DOT__at 
                            = (0x1ffU & ((IData)(1U) 
                                         + (IData)(vlSelf->dr840_pclink__DOT__at)));
                        vlSelf->__Vdly__dr840_pclink__DOT__mi 
                            = (0x1ffffffU & ((IData)(1U) 
                                             + vlSelf->dr840_pclink__DOT__mi));
                        if ((2U == (IData)(vlSelf->dr840_pclink__DOT__mk))) {
                            vlSelf->sent = (0x1ffffffU 
                                            & ((IData)(1U) 
                                               + vlSelf->dr840_pclink__DOT__mi));
                        }
                        if (((0xffU <= (0x1ffU & ((IData)(1U) 
                                                  + (IData)(vlSelf->dr840_pclink__DOT__at)))) 
                             | ((0x1ffffffU & ((IData)(1U) 
                                               + vlSelf->dr840_pclink__DOT__mi)) 
                                == vlSelf->dr840_pclink__DOT__msg_len))) {
                            vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 2U;
                            vlSelf->__Vdly__dr840_pclink__DOT__ridx = 0U;
                        }
                        __Vfunc_dr840_pclink__DOT__crc8__2__Vfuncout 
                            = vlSelf->dr840_pclink__DOT__crc8__Vstatic__x;
                        vlSelf->__Vdly__dr840_pclink__DOT__crc 
                            = __Vfunc_dr840_pclink__DOT__crc8__2__Vfuncout;
                    }
                }
            } else if ((2U == (IData)(vlSelf->state))) {
                if (vlSelf->dr840_pclink__DOT__next_seq) {
                    vlSelf->dr840_pclink__DOT__mk = vlSelf->dr840_pclink__DOT__seq_kind;
                    vlSelf->dr840_pclink__DOT__msg_len 
                        = vlSelf->dr840_pclink__DOT__kind_len;
                    vlSelf->__Vdly__dr840_pclink__DOT__seq 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->dr840_pclink__DOT__seq)));
                    if ((0U != vlSelf->dr840_pclink__DOT__kind_len)) {
                        vlSelf->__Vdly__dr840_pclink__DOT__mi = 0U;
                        vlSelf->__Vdly__dr840_pclink__DOT__at = 0U;
                        vlSelf->__Vdly__dr840_pclink__DOT__crc = 0xffffffffU;
                        vlSelf->dr840_pclink__DOT__q_pend = 0U;
                        vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 1U;
                    }
                    if ((5U == (IData)(vlSelf->dr840_pclink__DOT__seq))) {
                        vlSelf->__Vdly__dr840_pclink__DOT__seq = 0U;
                    }
                } else if ((0U != (IData)(vlSelf->dr840_pclink__DOT__pong_pend))) {
                    vlSelf->__Vdly__dr840_pclink__DOT__pong_pend 
                        = (0xfU & ((IData)(vlSelf->dr840_pclink__DOT__pong_pend) 
                                   - (IData)(1U)));
                    vlSelf->dr840_pclink__DOT__mk = 4U;
                    vlSelf->dr840_pclink__DOT__msg_len = 8U;
                    vlSelf->__Vdly__dr840_pclink__DOT__mi = 0U;
                    vlSelf->__Vdly__dr840_pclink__DOT__at = 0U;
                    vlSelf->__Vdly__dr840_pclink__DOT__crc = 0xffffffffU;
                    vlSelf->dr840_pclink__DOT__q_pend = 0U;
                    vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 1U;
                } else if ((0x4e20U == (IData)(vlSelf->dr840_pclink__DOT__idle_cnt))) {
                    vlSelf->__Vdly__dr840_pclink__DOT__idle_cnt = 0U;
                    vlSelf->dr840_pclink__DOT__mk = 5U;
                    vlSelf->dr840_pclink__DOT__msg_len = 8U;
                    vlSelf->__Vdly__dr840_pclink__DOT__mi = 0U;
                    vlSelf->__Vdly__dr840_pclink__DOT__at = 0U;
                    vlSelf->__Vdly__dr840_pclink__DOT__crc = 0xffffffffU;
                    vlSelf->dr840_pclink__DOT__q_pend = 0U;
                    vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 1U;
                } else if ((((IData)(vlSelf->uart_on) 
                             & (~ (IData)(vlSelf->grx_full))) 
                            & (0U == vlSelf->dr840_pclink__DOT__pace))) {
                    vlSelf->__Vdly__dr840_pclink__DOT__idle_cnt 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelf->dr840_pclink__DOT__idle_cnt)));
                    vlSelf->__Vdly__dr840_pclink__DOT__pace 
                        = vlSelf->dr840_pclink__DOT__frame_cen;
                }
            }
            if (((IData)(vlSelf->go_tog) != (IData)(vlSelf->dr840_pclink__DOT__go_q))) {
                vlSelf->dr840_pclink__DOT__escaped = 0U;
                vlSelf->__Vdly__state = ((0U != vlSelf->pkg_len)
                                          ? 1U : 0U);
                vlSelf->sent = 0U;
                vlSelf->dr840_pclink__DOT__greeted = 0U;
                vlSelf->__Vdly__dr840_pclink__DOT__gshift = 0U;
                vlSelf->__Vdly__dr840_pclink__DOT__rx_st = 0U;
                vlSelf->__Vdly__dr840_pclink__DOT__cmd_idx = 0U;
                vlSelf->dr840_pclink__DOT__cmd_skip = 0U;
                vlSelf->__Vdly__dr840_pclink__DOT__offered = 0U;
                vlSelf->__Vdly__dr840_pclink__DOT__pong_pend = 0U;
                vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 0U;
                vlSelf->__Vdly__dr840_pclink__DOT__seq = 0U;
                vlSelf->__Vdly__dr840_pclink__DOT__idle_cnt = 0U;
                vlSelf->dr840_pclink__DOT__word_ok = 0U;
            }
            vlSelf->dr840_pclink__DOT__go_q = vlSelf->go_tog;
        }
    } else {
        vlSelf->__Vdly__grx_tog = 0U;
        vlSelf->dr840_pclink__DOT__escaped = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__reading = 0U;
        vlSelf->grx_data = 0U;
        vlSelf->__Vdly__state = 0U;
        vlSelf->sent = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__pace = 0U;
        vlSelf->dr840_pclink__DOT__greeted = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__gshift = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__rx_st = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__rx_rem = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__cmd_idx = 0U;
        vlSelf->dr840_pclink__DOT__cmd_skip = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__cmd_tag = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__cmd_rem = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__offered = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__pong_pend = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__tx_st = 0U;
        vlSelf->dr840_pclink__DOT__mk = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__seq = 0U;
        vlSelf->dr840_pclink__DOT__msg_len = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__mi = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__at = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__ridx = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__crc = 0xffffffffU;
        vlSelf->dr840_pclink__DOT__q_pend = 0U;
        vlSelf->__Vdly__dr840_pclink__DOT__idle_cnt = 0U;
        vlSelf->dr840_pclink__DOT__fill_we = 0U;
        vlSelf->dr840_pclink__DOT__fill_b = 0U;
        vlSelf->dr840_pclink__DOT__fill_at = 0U;
        vlSelf->dr840_pclink__DOT__word = 0U;
        vlSelf->dr840_pclink__DOT__word_addr = 0U;
        vlSelf->dr840_pclink__DOT__word_ok = 0U;
        vlSelf->__Vdly__wr_ack = 0U;
        vlSelf->pmem_addr = 0U;
        vlSelf->pmem_req = 0U;
        vlSelf->pmem_we = 0U;
        vlSelf->pmem_wdata = 0U;
        vlSelf->dr840_pclink__DOT__go_q = 0U;
    }
    vlSelf->dr840_pclink__DOT__reading = vlSelf->__Vdly__dr840_pclink__DOT__reading;
    vlSelf->wr_ack = vlSelf->__Vdly__wr_ack;
    vlSelf->dr840_pclink__DOT__rx_rem = vlSelf->__Vdly__dr840_pclink__DOT__rx_rem;
    vlSelf->dr840_pclink__DOT__gshift = vlSelf->__Vdly__dr840_pclink__DOT__gshift;
    vlSelf->dr840_pclink__DOT__cmd_tag = vlSelf->__Vdly__dr840_pclink__DOT__cmd_tag;
    vlSelf->dr840_pclink__DOT__offered = vlSelf->__Vdly__dr840_pclink__DOT__offered;
    vlSelf->dr840_pclink__DOT__pong_pend = vlSelf->__Vdly__dr840_pclink__DOT__pong_pend;
    vlSelf->dr840_pclink__DOT__tx_st = vlSelf->__Vdly__dr840_pclink__DOT__tx_st;
    vlSelf->grx_tog = vlSelf->__Vdly__grx_tog;
    vlSelf->dr840_pclink__DOT__at = vlSelf->__Vdly__dr840_pclink__DOT__at;
    vlSelf->dr840_pclink__DOT__crc = vlSelf->__Vdly__dr840_pclink__DOT__crc;
    vlSelf->dr840_pclink__DOT__idle_cnt = vlSelf->__Vdly__dr840_pclink__DOT__idle_cnt;
    vlSelf->dr840_pclink__DOT__pace = vlSelf->__Vdly__dr840_pclink__DOT__pace;
    vlSelf->state = vlSelf->__Vdly__state;
    vlSelf->dr840_pclink__DOT__cmd_idx = vlSelf->__Vdly__dr840_pclink__DOT__cmd_idx;
    vlSelf->dr840_pclink__DOT__seq = vlSelf->__Vdly__dr840_pclink__DOT__seq;
    vlSelf->dr840_pclink__DOT__rx_v = ((IData)(vlSelf->gtx_tog) 
                                       != (IData)(vlSelf->dr840_pclink__DOT__gtx_q));
    vlSelf->dr840_pclink__DOT__rx_st = vlSelf->__Vdly__dr840_pclink__DOT__rx_st;
    vlSelf->dr840_pclink__DOT__cmd_rem = vlSelf->__Vdly__dr840_pclink__DOT__cmd_rem;
    vlSelf->dr840_pclink__DOT__mi = vlSelf->__Vdly__dr840_pclink__DOT__mi;
    vlSelf->dr840_pclink__DOT__can_send = ((IData)(vlSelf->uart_on) 
                                           & ((~ (IData)(vlSelf->grx_full)) 
                                              & ((0U 
                                                  == vlSelf->dr840_pclink__DOT__pace) 
                                                 & (2U 
                                                    == (IData)(vlSelf->state)))));
    vlSelf->dr840_pclink__DOT__next_seq = (0U != (IData)(vlSelf->dr840_pclink__DOT__seq));
    vlSelf->dr840_pclink__DOT__seq_kind = ((3U == (IData)(vlSelf->dr840_pclink__DOT__seq))
                                            ? 1U : 
                                           ((4U == (IData)(vlSelf->dr840_pclink__DOT__seq))
                                             ? 2U : 
                                            ((5U == (IData)(vlSelf->dr840_pclink__DOT__seq))
                                              ? 3U : 0U)));
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
    vlSelf->dr840_pclink__DOT__cmd_len_now = ((vlSelf->dr840_pclink__DOT__cmd_rem 
                                               << 8U) 
                                              | (IData)(vlSelf->gtx_data));
    vlSelf->dr840_pclink__DOT__have_word = ((2U != (IData)(vlSelf->dr840_pclink__DOT__mk)) 
                                            | ((IData)(vlSelf->dr840_pclink__DOT__word_ok) 
                                               & (vlSelf->dr840_pclink__DOT__word_addr 
                                                  == 
                                                  (0x7fffffU 
                                                   & (vlSelf->dr840_pclink__DOT__mi 
                                                      >> 2U)))));
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

VL_INLINE_OPT void Vdr840_pclink___024root___nba_sequent__TOP__3(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___nba_sequent__TOP__3\n"); );
    // Body
    if (vlSelf->cen) {
        vlSelf->dr840_pclink__DOT__blk_q = vlSelf->dr840_pclink__DOT__blk
            [(0xffU & (IData)(vlSelf->dr840_pclink__DOT__ridx))];
        vlSelf->dr840_pclink__DOT__byte_cen = ((1U 
                                                == (IData)(vlSelf->speed))
                                                ? (0x3fffffU 
                                                   & (vlSelf->dr840_pclink__DOT__frame_cen 
                                                      >> 1U))
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelf->speed))
                                                    ? vlSelf->dr840_pclink__DOT__frame_cen
                                                    : 
                                                   (0x1fffffU 
                                                    & (vlSelf->dr840_pclink__DOT__frame_cen 
                                                       >> 2U))));
        vlSelf->dr840_pclink__DOT__frame_cen = (0x7fffffU 
                                                & ((vlSelf->bit_clocks 
                                                    << 2U) 
                                                   + vlSelf->bit_clocks));
    }
    if (vlSelf->__Vdlyvset__dr840_pclink__DOT__blk__v0) {
        vlSelf->dr840_pclink__DOT__blk[vlSelf->__Vdlyvdim0__dr840_pclink__DOT__blk__v0] 
            = vlSelf->__Vdlyvval__dr840_pclink__DOT__blk__v0;
    }
}

VL_INLINE_OPT void Vdr840_pclink___024root___nba_sequent__TOP__4(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___nba_sequent__TOP__4\n"); );
    // Body
    vlSelf->dr840_pclink__DOT__ridx = vlSelf->__Vdly__dr840_pclink__DOT__ridx;
}

void Vdr840_pclink___024root___eval_nba(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vdr840_pclink___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vdr840_pclink___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vdr840_pclink___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vdr840_pclink___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vdr840_pclink___024root___nba_sequent__TOP__4(vlSelf);
    }
}

void Vdr840_pclink___024root___eval_triggers__act(Vdr840_pclink___024root* vlSelf);

bool Vdr840_pclink___024root___eval_phase__act(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vdr840_pclink___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vdr840_pclink___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vdr840_pclink___024root___eval_phase__nba(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vdr840_pclink___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_pclink___024root___dump_triggers__ico(Vdr840_pclink___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_pclink___024root___dump_triggers__nba(Vdr840_pclink___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdr840_pclink___024root___dump_triggers__act(Vdr840_pclink___024root* vlSelf);
#endif  // VL_DEBUG

void Vdr840_pclink___024root___eval(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval\n"); );
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
            Vdr840_pclink___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../../rtl/soc/dr840_pclink.sv", 35, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vdr840_pclink___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vdr840_pclink___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../../rtl/soc/dr840_pclink.sv", 35, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vdr840_pclink___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../../rtl/soc/dr840_pclink.sv", 35, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vdr840_pclink___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vdr840_pclink___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vdr840_pclink___024root___eval_debug_assertions(Vdr840_pclink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdr840_pclink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdr840_pclink___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->cen & 0xfeU))) {
        Verilated::overWidthError("cen");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->go_tog & 0xfeU))) {
        Verilated::overWidthError("go_tog");}
    if (VL_UNLIKELY((vlSelf->pkg_len & 0xfe000000U))) {
        Verilated::overWidthError("pkg_len");}
    if (VL_UNLIKELY((vlSelf->wr_addr & 0xfe000000U))) {
        Verilated::overWidthError("wr_addr");}
    if (VL_UNLIKELY((vlSelf->wr_req & 0xfeU))) {
        Verilated::overWidthError("wr_req");}
    if (VL_UNLIKELY((vlSelf->pmem_ack & 0xfeU))) {
        Verilated::overWidthError("pmem_ack");}
    if (VL_UNLIKELY((vlSelf->gtx_tog & 0xfeU))) {
        Verilated::overWidthError("gtx_tog");}
    if (VL_UNLIKELY((vlSelf->grx_full & 0xfeU))) {
        Verilated::overWidthError("grx_full");}
    if (VL_UNLIKELY((vlSelf->uart_on & 0xfeU))) {
        Verilated::overWidthError("uart_on");}
    if (VL_UNLIKELY((vlSelf->bit_clocks & 0xfff00000U))) {
        Verilated::overWidthError("bit_clocks");}
    if (VL_UNLIKELY((vlSelf->speed & 0xfcU))) {
        Verilated::overWidthError("speed");}
}
#endif  // VL_DEBUG
