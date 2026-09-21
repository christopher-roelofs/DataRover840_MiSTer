// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_board.h for the primary calling header

#include "Vtb_board__pch.h"
#include "Vtb_board__Syms.h"
#include "Vtb_board_r3900__Cz2.h"

VL_INLINE_OPT void Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__0(Vtb_board_r3900__Cz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__0\n"); );
    // Body
    vlSelf->__PVT__cause_live = ((0xffff03ffU & vlSelf->__PVT__cp0
                                  [0xdU]) | VL_SHIFTL_III(32,32,32, (IData)(vlSymsp->TOP.irq_in), 0xaU));
    vlSelf->__PVT__id_take_irq = ((IData)(vlSelf->__PVT__id_v) 
                                  & ((~ (IData)(vlSelf->__PVT__id_exc_v)) 
                                     & (vlSelf->__PVT__cp0
                                        [0xcU] & ((~ (IData)(vlSelf->__PVT__special_inflight)) 
                                                  & (0U 
                                                     != 
                                                     (0xffU 
                                                      & ((vlSelf->__PVT__cause_live 
                                                          & vlSelf->__PVT__cp0
                                                          [0xcU]) 
                                                         >> 8U)))))));
}

VL_INLINE_OPT void Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__1(Vtb_board_r3900__Cz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__1\n"); );
    // Init
    IData/*31:0*/ __PVT__me_fwd;
    __PVT__me_fwd = 0;
    IData/*31:0*/ __PVT__add_r;
    __PVT__add_r = 0;
    IData/*31:0*/ __PVT__sub_r;
    __PVT__sub_r = 0;
    CData/*4:0*/ __PVT__shamt;
    __PVT__shamt = 0;
    CData/*0:0*/ __PVT__ex_ov;
    __PVT__ex_ov = 0;
    CData/*0:0*/ __PVT__ex_misaligned;
    __PVT__ex_misaligned = 0;
    CData/*0:0*/ __PVT__ex_new_exc;
    __PVT__ex_new_exc = 0;
    CData/*4:0*/ __PVT__ex_new_code;
    __PVT__ex_new_code = 0;
    CData/*0:0*/ __PVT__ex_new_bad_v;
    __PVT__ex_new_bad_v = 0;
    CData/*7:0*/ __PVT__lb_byte;
    __PVT__lb_byte = 0;
    SData/*15:0*/ __PVT__lh_half;
    __PVT__lh_half = 0;
    CData/*0:0*/ __PVT__me_dbe;
    __PVT__me_dbe = 0;
    CData/*0:0*/ __VdfgExtracted_h61748c33__0;
    __VdfgExtracted_h61748c33__0 = 0;
    IData/*31:0*/ __VdfgExtracted_hbfd80901__0;
    __VdfgExtracted_hbfd80901__0 = 0;
    IData/*31:0*/ __VdfgTmp_hfb8405e1__0;
    __VdfgTmp_hfb8405e1__0 = 0;
    IData/*31:0*/ __VdfgTmp_heea4471d__0;
    __VdfgTmp_heea4471d__0 = 0;
    IData/*31:0*/ __VdfgTmp_hed7a7ef0__0;
    __VdfgTmp_hed7a7ef0__0 = 0;
    CData/*0:0*/ __VdfgTmp_hdf83ee26__0;
    __VdfgTmp_hdf83ee26__0 = 0;
    CData/*0:0*/ __VdfgTmp_h0f5f749b__0;
    __VdfgTmp_h0f5f749b__0 = 0;
    // Body
    if ((2U & vlSelf->__PVT__me_va)) {
        __PVT__lb_byte = (0xffU & ((1U & vlSelf->__PVT__me_va)
                                    ? vlSymsp->TOP__tb_board__cpu.__PVT__drd
                                    : (vlSymsp->TOP__tb_board__cpu.__PVT__drd 
                                       >> 8U)));
        __PVT__lh_half = (0xffffU & vlSymsp->TOP__tb_board__cpu.__PVT__drd);
    } else {
        __PVT__lb_byte = (0xffU & ((1U & vlSelf->__PVT__me_va)
                                    ? (vlSymsp->TOP__tb_board__cpu.__PVT__drd 
                                       >> 0x10U) : 
                                   (vlSymsp->TOP__tb_board__cpu.__PVT__drd 
                                    >> 0x18U)));
        __PVT__lh_half = (0xffffU & (vlSymsp->TOP__tb_board__cpu.__PVT__drd 
                                     >> 0x10U));
    }
    __PVT__me_dbe = ((IData)(vlSelf->__PVT__me_needs_mem) 
                     & ((IData)(vlSymsp->TOP__tb_board__cpu.__PVT__dack) 
                        & (IData)(vlSymsp->TOP__tb_board__cpu.__PVT__derr)));
    vlSelf->__PVT__load_value = ((vlSelf->__PVT__me_insn 
                                  >> 0x1fU) ? ((0x40000000U 
                                                & vlSelf->__PVT__me_insn)
                                                ? vlSymsp->TOP__tb_board__cpu.__PVT__drd
                                                : (
                                                   (0x20000000U 
                                                    & vlSelf->__PVT__me_insn)
                                                    ? vlSymsp->TOP__tb_board__cpu.__PVT__drd
                                                    : 
                                                   ((0x10000000U 
                                                     & vlSelf->__PVT__me_insn)
                                                     ? 
                                                    ((0x8000000U 
                                                      & vlSelf->__PVT__me_insn)
                                                      ? 
                                                     ((0x4000000U 
                                                       & vlSelf->__PVT__me_insn)
                                                       ? vlSymsp->TOP__tb_board__cpu.__PVT__drd
                                                       : 
                                                      ((2U 
                                                        & vlSelf->__PVT__me_va)
                                                        ? 
                                                       ((1U 
                                                         & vlSelf->__PVT__me_va)
                                                         ? vlSymsp->TOP__tb_board__cpu.__PVT__drd
                                                         : 
                                                        ((0xff000000U 
                                                          & vlSelf->__PVT__me_rt) 
                                                         | (vlSymsp->TOP__tb_board__cpu.__PVT__drd 
                                                            >> 8U)))
                                                        : 
                                                       ((1U 
                                                         & vlSelf->__PVT__me_va)
                                                         ? 
                                                        ((0xffff0000U 
                                                          & vlSelf->__PVT__me_rt) 
                                                         | (vlSymsp->TOP__tb_board__cpu.__PVT__drd 
                                                            >> 0x10U))
                                                         : 
                                                        ((0xffffff00U 
                                                          & vlSelf->__PVT__me_rt) 
                                                         | (vlSymsp->TOP__tb_board__cpu.__PVT__drd 
                                                            >> 0x18U)))))
                                                      : 
                                                     ((0x4000000U 
                                                       & vlSelf->__PVT__me_insn)
                                                       ? (IData)(__PVT__lh_half)
                                                       : (IData)(__PVT__lb_byte)))
                                                     : 
                                                    ((0x8000000U 
                                                      & vlSelf->__PVT__me_insn)
                                                      ? 
                                                     ((0x4000000U 
                                                       & vlSelf->__PVT__me_insn)
                                                       ? vlSymsp->TOP__tb_board__cpu.__PVT__drd
                                                       : 
                                                      ((2U 
                                                        & vlSelf->__PVT__me_va)
                                                        ? 
                                                       ((1U 
                                                         & vlSelf->__PVT__me_va)
                                                         ? 
                                                        ((vlSymsp->TOP__tb_board__cpu.__PVT__drd 
                                                          << 0x18U) 
                                                         | (0xffffffU 
                                                            & vlSelf->__PVT__me_rt))
                                                         : 
                                                        ((vlSymsp->TOP__tb_board__cpu.__PVT__drd 
                                                          << 0x10U) 
                                                         | (0xffffU 
                                                            & vlSelf->__PVT__me_rt)))
                                                        : 
                                                       ((1U 
                                                         & vlSelf->__PVT__me_va)
                                                         ? 
                                                        ((vlSymsp->TOP__tb_board__cpu.__PVT__drd 
                                                          << 8U) 
                                                         | (0xffU 
                                                            & vlSelf->__PVT__me_rt))
                                                         : vlSymsp->TOP__tb_board__cpu.__PVT__drd)))
                                                      : 
                                                     ((0x4000000U 
                                                       & vlSelf->__PVT__me_insn)
                                                       ? 
                                                      (((- (IData)(
                                                                   (1U 
                                                                    & ((IData)(__PVT__lh_half) 
                                                                       >> 0xfU)))) 
                                                        << 0x10U) 
                                                       | (IData)(__PVT__lh_half))
                                                       : 
                                                      (((- (IData)(
                                                                   (1U 
                                                                    & ((IData)(__PVT__lb_byte) 
                                                                       >> 7U)))) 
                                                        << 8U) 
                                                       | (IData)(__PVT__lb_byte)))))))
                                  : vlSymsp->TOP__tb_board__cpu.__PVT__drd);
    vlSelf->__PVT__me_exc_out_v = ((IData)(vlSelf->__PVT__me_exc_v) 
                                   | (IData)(__PVT__me_dbe));
    vlSelf->__PVT__adv_mem = (1U & (~ ((~ (((IData)(vlSymsp->TOP__tb_board__cpu.__PVT__dack) 
                                            & (IData)(vlSelf->__PVT__me_last_beat)) 
                                           | (IData)(__PVT__me_dbe))) 
                                       & (IData)(vlSelf->__PVT__me_needs_mem))));
    __PVT__me_fwd = (([&]() {
                vlSelf->__Vfunc_is_load__29__i = vlSelf->__PVT__me_insn;
                vlSelf->__Vfunc_is_load__29__Vfuncout 
                    = (((((((0x20U == (vlSelf->__Vfunc_is_load__29__i 
                                       >> 0x1aU)) | 
                            (0x21U == (vlSelf->__Vfunc_is_load__29__i 
                                       >> 0x1aU))) 
                           | (0x23U == (vlSelf->__Vfunc_is_load__29__i 
                                        >> 0x1aU))) 
                          | (0x24U == (vlSelf->__Vfunc_is_load__29__i 
                                       >> 0x1aU))) 
                         | (0x25U == (vlSelf->__Vfunc_is_load__29__i 
                                      >> 0x1aU))) | 
                        (0x22U == (vlSelf->__Vfunc_is_load__29__i 
                                   >> 0x1aU))) | (0x26U 
                                                  == 
                                                  (vlSelf->__Vfunc_is_load__29__i 
                                                   >> 0x1aU)));
            }(), (IData)(vlSelf->__Vfunc_is_load__29__Vfuncout))
                      ? vlSelf->__PVT__load_value : vlSelf->__PVT__me_result);
    vlSelf->__PVT__cache_op = ((IData)(vlSelf->__PVT__me_v) 
                               & ((0x2fU == (vlSelf->__PVT__me_insn 
                                             >> 0x1aU)) 
                                  & ((~ (IData)(vlSelf->__PVT__me_exc_v)) 
                                     & (IData)(vlSelf->__PVT__adv_mem))));
    vlSelf->__PVT__adv_ex = ((IData)(vlSelf->__PVT__adv_mem) 
                             & (~ ((~ ((IData)(vlSelf->__PVT__md_run) 
                                       & ((IData)(vlSelf->__PVT__md_skip) 
                                          | (0U == (IData)(vlSelf->__PVT__md_count))))) 
                                   & (IData)(vlSelf->__PVT__ex_is_div))));
    vlSelf->__PVT__exc_flush = ((IData)(vlSelf->__PVT__me_v) 
                                & ((IData)(vlSelf->__PVT__adv_mem) 
                                   & (IData)(vlSelf->__PVT__me_exc_out_v)));
    __VdfgTmp_hed7a7ef0__0 = (((IData)(vlSelf->__VdfgTmp_hc5c1aa8c__0) 
                               & ((IData)(vlSelf->__PVT__me_wa) 
                                  == (0x1fU & (vlSelf->__PVT__ex_insn 
                                               >> 0x10U))))
                               ? __PVT__me_fwd : (((IData)(vlSelf->__VdfgTmp_h42ed6c05__0) 
                                                   & ((IData)(vlSelf->__PVT__wb_wa) 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->__PVT__ex_insn 
                                                          >> 0x10U))))
                                                   ? vlSelf->__PVT__wb_value
                                                   : vlSelf->__PVT__ex_rt_raw));
    __VdfgTmp_heea4471d__0 = (((IData)(vlSelf->__VdfgTmp_hc5c1aa8c__0) 
                               & ((IData)(vlSelf->__PVT__me_wa) 
                                  == (0x1fU & (vlSelf->__PVT__ex_insn 
                                               >> 0x15U))))
                               ? __PVT__me_fwd : (((IData)(vlSelf->__VdfgTmp_h42ed6c05__0) 
                                                   & ((IData)(vlSelf->__PVT__wb_wa) 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->__PVT__ex_insn 
                                                          >> 0x15U))))
                                                   ? vlSelf->__PVT__wb_value
                                                   : vlSelf->__PVT__ex_rs_raw));
    vlSelf->__PVT__adv_id = ((~ ((IData)(vlSelf->__PVT__load_use) 
                                 | ((IData)(vlSelf->__PVT__branch_load_use) 
                                    | ((IData)(vlSelf->__PVT__special_hazard) 
                                       | ((IData)(vlSelf->__PVT__cp0_write_inflight) 
                                          & (IData)(vlSelf->__PVT__id_v)))))) 
                             & (IData)(vlSelf->__PVT__adv_ex));
    __VdfgTmp_h0f5f749b__0 = ((0U != (0x1fU & (vlSelf->__PVT__ex_insn 
                                               >> 0x10U))) 
                              & (__VdfgTmp_hed7a7ef0__0 
                                 >> 0x1fU));
    vlSelf->__PVT__t = ((0U == (0x1fU & (vlSelf->__PVT__ex_insn 
                                         >> 0x10U)))
                         ? 0U : __VdfgTmp_hed7a7ef0__0);
    __VdfgTmp_hdf83ee26__0 = ((0U != (0x1fU & (vlSelf->__PVT__ex_insn 
                                               >> 0x15U))) 
                              & (__VdfgTmp_heea4471d__0 
                                 >> 0x1fU));
    __PVT__shamt = (0x1fU & ((4U & vlSelf->__PVT__ex_insn)
                              ? ((0U == (0x1fU & (vlSelf->__PVT__ex_insn 
                                                  >> 0x15U)))
                                  ? 0U : __VdfgTmp_heea4471d__0)
                              : (vlSelf->__PVT__ex_insn 
                                 >> 6U)));
    vlSelf->__PVT__s = ((0U == (0x1fU & (vlSelf->__PVT__ex_insn 
                                         >> 0x15U)))
                         ? 0U : __VdfgTmp_heea4471d__0);
    vlSelf->__PVT__ibus_req = ((~ (IData)(vlSelf->__PVT__exc_flush)) 
                               & (IData)(vlSelf->__PVT__adv_id));
    vlSelf->__PVT__t_mag = ((IData)(__VdfgTmp_h0f5f749b__0)
                             ? ((IData)(1U) + ((0U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->__PVT__ex_insn 
                                                    >> 0x10U)))
                                                ? 0xffffffffU
                                                : (~ __VdfgTmp_hed7a7ef0__0)))
                             : vlSelf->__PVT__t);
    vlSelf->__PVT__mul_s = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, vlSelf->__PVT__s), 
                                       VL_EXTENDS_QI(64,32, vlSelf->__PVT__t));
    vlSelf->__PVT__mul_u = ((QData)((IData)(vlSelf->__PVT__s)) 
                            * (QData)((IData)(vlSelf->__PVT__t)));
    vlSelf->__PVT__s_mag = ((IData)(__VdfgTmp_hdf83ee26__0)
                             ? ((IData)(1U) + ((0U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->__PVT__ex_insn 
                                                    >> 0x15U)))
                                                ? 0xffffffffU
                                                : (~ __VdfgTmp_heea4471d__0)))
                             : vlSelf->__PVT__s);
    __VdfgExtracted_hbfd80901__0 = (vlSelf->__PVT__s 
                                    | vlSelf->__PVT__t);
    __PVT__add_r = (vlSelf->__PVT__s + vlSelf->__PVT__t);
    __PVT__sub_r = (vlSelf->__PVT__s - vlSelf->__PVT__t);
    vlSelf->__PVT__addi_r = (vlSelf->__PVT__s + vlSelf->__PVT__ex_simm);
    vlSelf->__PVT__ex_exc_out_bad = ((IData)(vlSelf->__PVT__ex_exc_v)
                                      ? vlSelf->__PVT__ex_exc_bad
                                      : vlSelf->__PVT__addi_r);
    vlSelf->__PVT__dbus_addr_la = (0xfffffffcU & ((IData)(vlSelf->__PVT__adv_mem)
                                                   ? 
                                                  ([&]() {
                    vlSelf->__Vfunc_phys__81__va = vlSelf->__PVT__addi_r;
                    vlSelf->__Vfunc_phys__81__Vfuncout 
                        = (((0x80000000U <= vlSelf->__Vfunc_phys__81__va) 
                            & (0xc0000000U > vlSelf->__Vfunc_phys__81__va))
                            ? (0x1fffffffU & vlSelf->__Vfunc_phys__81__va)
                            : vlSelf->__Vfunc_phys__81__va);
                }(), vlSelf->__Vfunc_phys__81__Vfuncout)
                                                   : 
                                                  ([&]() {
                    vlSelf->__Vfunc_phys__82__va = vlSelf->__PVT__me_va;
                    vlSelf->__Vfunc_phys__82__Vfuncout 
                        = (((0x80000000U <= vlSelf->__Vfunc_phys__82__va) 
                            & (0xc0000000U > vlSelf->__Vfunc_phys__82__va))
                            ? (0x1fffffffU & vlSelf->__Vfunc_phys__82__va)
                            : vlSelf->__Vfunc_phys__82__va);
                }(), vlSelf->__Vfunc_phys__82__Vfuncout)));
    __PVT__ex_ov = ((IData)(vlSelf->__PVT__ex_v) & 
                    ((IData)(((0x20U == (0xfc00003fU 
                                         & vlSelf->__PVT__ex_insn)) 
                              & (((IData)(__VdfgTmp_hdf83ee26__0) 
                                  == (IData)(__VdfgTmp_h0f5f749b__0)) 
                                 & ((__PVT__add_r >> 0x1fU) 
                                    != (IData)(__VdfgTmp_hdf83ee26__0))))) 
                     | ((IData)(((0x22U == (0xfc00003fU 
                                            & vlSelf->__PVT__ex_insn)) 
                                 & (((IData)(__VdfgTmp_hdf83ee26__0) 
                                     != (IData)(__VdfgTmp_h0f5f749b__0)) 
                                    & ((__PVT__sub_r 
                                        >> 0x1fU) != (IData)(__VdfgTmp_hdf83ee26__0))))) 
                        | ((8U == (vlSelf->__PVT__ex_insn 
                                   >> 0x1aU)) & (((IData)(__VdfgTmp_hdf83ee26__0) 
                                                  == 
                                                  (1U 
                                                   & (vlSelf->__PVT__ex_insn 
                                                      >> 0xfU))) 
                                                 & ((vlSelf->__PVT__addi_r 
                                                     >> 0x1fU) 
                                                    != (IData)(__VdfgTmp_hdf83ee26__0)))))));
    __PVT__ex_misaligned = ((IData)(vlSelf->__PVT__ex_v) 
                            & ((((0x21U == (vlSelf->__PVT__ex_insn 
                                            >> 0x1aU)) 
                                 | ((0x25U == (vlSelf->__PVT__ex_insn 
                                               >> 0x1aU)) 
                                    | (0x29U == (vlSelf->__PVT__ex_insn 
                                                 >> 0x1aU)))) 
                                & vlSelf->__PVT__addi_r) 
                               | (((0x23U == (vlSelf->__PVT__ex_insn 
                                              >> 0x1aU)) 
                                   | (0x2bU == (vlSelf->__PVT__ex_insn 
                                                >> 0x1aU))) 
                                  & (0U != (3U & vlSelf->__PVT__addi_r)))));
    vlSelf->__PVT__alu = 0U;
    if ((vlSelf->__PVT__ex_insn >> 0x1fU)) {
        vlSelf->__PVT__alu = vlSelf->__PVT__addi_r;
    } else if ((0x40000000U & vlSelf->__PVT__ex_insn)) {
        vlSelf->__PVT__alu = ((0x20000000U & vlSelf->__PVT__ex_insn)
                               ? vlSelf->__PVT__addi_r
                               : ((0x10000000U & vlSelf->__PVT__ex_insn)
                                   ? vlSelf->__PVT__addi_r
                                   : ((0x8000000U & vlSelf->__PVT__ex_insn)
                                       ? vlSelf->__PVT__addi_r
                                       : ((0x4000000U 
                                           & vlSelf->__PVT__ex_insn)
                                           ? vlSelf->__PVT__addi_r
                                           : ((0xdU 
                                               == (0x1fU 
                                                   & (vlSelf->__PVT__ex_insn 
                                                      >> 0xbU)))
                                               ? vlSelf->__PVT__cause_live
                                               : ((9U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->__PVT__ex_insn 
                                                       >> 0xbU)))
                                                   ? (IData)(
                                                             (vlSelf->cycle_count 
                                                              >> 1U))
                                                   : 
                                                  vlSelf->__PVT__cp0
                                                  [
                                                  (0x1fU 
                                                   & (vlSelf->__PVT__ex_insn 
                                                      >> 0xbU))]))))));
    } else if ((0x20000000U & vlSelf->__PVT__ex_insn)) {
        vlSelf->__PVT__alu = ((0x10000000U & vlSelf->__PVT__ex_insn)
                               ? ((0x8000000U & vlSelf->__PVT__ex_insn)
                                   ? ((0x4000000U & vlSelf->__PVT__ex_insn)
                                       ? VL_SHIFTL_III(32,32,32, vlSelf->__PVT__ex_insn, 0x10U)
                                       : (vlSelf->__PVT__s 
                                          ^ (0xffffU 
                                             & vlSelf->__PVT__ex_insn)))
                                   : ((0x4000000U & vlSelf->__PVT__ex_insn)
                                       ? (vlSelf->__PVT__s 
                                          | (0xffffU 
                                             & vlSelf->__PVT__ex_insn))
                                       : (0xffffU & 
                                          (vlSelf->__PVT__s 
                                           & vlSelf->__PVT__ex_insn))))
                               : ((0x8000000U & vlSelf->__PVT__ex_insn)
                                   ? ((0x4000000U & vlSelf->__PVT__ex_insn)
                                       ? (vlSelf->__PVT__s 
                                          < vlSelf->__PVT__ex_simm)
                                       : VL_LTS_III(32, vlSelf->__PVT__s, vlSelf->__PVT__ex_simm))
                                   : vlSelf->__PVT__addi_r));
    } else if ((0x10000000U & vlSelf->__PVT__ex_insn)) {
        vlSelf->__PVT__alu = vlSelf->__PVT__addi_r;
    } else if ((0x8000000U & vlSelf->__PVT__ex_insn)) {
        vlSelf->__PVT__alu = ((0x4000000U & vlSelf->__PVT__ex_insn)
                               ? ((IData)(8U) + vlSelf->__PVT__ex_pc)
                               : vlSelf->__PVT__addi_r);
    } else if ((0x4000000U & vlSelf->__PVT__ex_insn)) {
        vlSelf->__PVT__alu = ((IData)(8U) + vlSelf->__PVT__ex_pc);
    } else if ((0x20U & vlSelf->__PVT__ex_insn)) {
        if ((1U & (~ (vlSelf->__PVT__ex_insn >> 4U)))) {
            if ((8U & vlSelf->__PVT__ex_insn)) {
                if ((1U & (~ (vlSelf->__PVT__ex_insn 
                              >> 2U)))) {
                    if ((2U & vlSelf->__PVT__ex_insn)) {
                        vlSelf->__PVT__alu = ((1U & vlSelf->__PVT__ex_insn)
                                               ? (vlSelf->__PVT__s 
                                                  < vlSelf->__PVT__t)
                                               : VL_LTS_III(32, vlSelf->__PVT__s, vlSelf->__PVT__t));
                    }
                }
            } else {
                vlSelf->__PVT__alu = ((4U & vlSelf->__PVT__ex_insn)
                                       ? ((2U & vlSelf->__PVT__ex_insn)
                                           ? ((1U & vlSelf->__PVT__ex_insn)
                                               ? (~ __VdfgExtracted_hbfd80901__0)
                                               : (vlSelf->__PVT__s 
                                                  ^ vlSelf->__PVT__t))
                                           : ((1U & vlSelf->__PVT__ex_insn)
                                               ? __VdfgExtracted_hbfd80901__0
                                               : (vlSelf->__PVT__s 
                                                  & vlSelf->__PVT__t)))
                                       : ((2U & vlSelf->__PVT__ex_insn)
                                           ? __PVT__sub_r
                                           : __PVT__add_r));
            }
        }
    } else if ((0x10U & vlSelf->__PVT__ex_insn)) {
        if ((1U & (~ (vlSelf->__PVT__ex_insn >> 3U)))) {
            if ((1U & (~ (vlSelf->__PVT__ex_insn >> 2U)))) {
                if ((2U & vlSelf->__PVT__ex_insn)) {
                    if ((1U & (~ vlSelf->__PVT__ex_insn))) {
                        vlSelf->__PVT__alu = vlSelf->lo;
                    }
                } else if ((1U & (~ vlSelf->__PVT__ex_insn))) {
                    vlSelf->__PVT__alu = vlSelf->hi;
                }
            }
        }
    } else if ((8U & vlSelf->__PVT__ex_insn)) {
        if ((1U & (~ (vlSelf->__PVT__ex_insn >> 2U)))) {
            if ((1U & (~ (vlSelf->__PVT__ex_insn >> 1U)))) {
                if ((1U & vlSelf->__PVT__ex_insn)) {
                    vlSelf->__PVT__alu = ((IData)(8U) 
                                          + vlSelf->__PVT__ex_pc);
                }
            }
        }
    } else if ((2U & vlSelf->__PVT__ex_insn)) {
        vlSelf->__PVT__alu = ((1U & vlSelf->__PVT__ex_insn)
                               ? VL_SHIFTRS_III(32,32,5, vlSelf->__PVT__t, (IData)(__PVT__shamt))
                               : (vlSelf->__PVT__t 
                                  >> (IData)(__PVT__shamt)));
    } else if ((1U & (~ vlSelf->__PVT__ex_insn))) {
        vlSelf->__PVT__alu = (vlSelf->__PVT__t << (IData)(__PVT__shamt));
    }
    __PVT__ex_new_bad_v = 0U;
    __PVT__ex_new_exc = 0U;
    __PVT__ex_new_code = 0U;
    if (__PVT__ex_misaligned) {
        __PVT__ex_new_bad_v = 1U;
        __PVT__ex_new_exc = 1U;
        __PVT__ex_new_code = vlSelf->__VdfgExtracted_h9d8030ea__0;
    } else if (__PVT__ex_ov) {
        __PVT__ex_new_exc = 1U;
        __PVT__ex_new_code = 0xcU;
    } else if (vlSelf->__PVT__ex_sys) {
        __PVT__ex_new_exc = 1U;
        __PVT__ex_new_code = 8U;
    } else if (vlSelf->__PVT__ex_bp) {
        __PVT__ex_new_exc = 1U;
        __PVT__ex_new_code = 9U;
    }
    if (vlSelf->__PVT__ex_exc_v) {
        vlSelf->__PVT__ex_exc_out_badv = vlSelf->__PVT__ex_exc_bad_v;
        vlSelf->__PVT__ex_exc_out_code = vlSelf->__PVT__ex_exc_code;
    } else {
        vlSelf->__PVT__ex_exc_out_badv = __PVT__ex_new_bad_v;
        vlSelf->__PVT__ex_exc_out_code = __PVT__ex_new_code;
    }
    vlSelf->__PVT__id_t = ((0U == (0x1fU & (vlSelf->__PVT__id_insn 
                                            >> 0x10U)))
                            ? 0U : (((IData)(vlSelf->__VdfgTmp_hcfa842a8__0) 
                                     & ((IData)(vlSelf->__PVT__ex_wa) 
                                        == (0x1fU & 
                                            (vlSelf->__PVT__id_insn 
                                             >> 0x10U))))
                                     ? vlSelf->__PVT__alu
                                     : (((IData)(vlSelf->__VdfgTmp_hc5c1aa8c__0) 
                                         & ((IData)(vlSelf->__PVT__me_wa) 
                                            == (0x1fU 
                                                & (vlSelf->__PVT__id_insn 
                                                   >> 0x10U))))
                                         ? __PVT__me_fwd
                                         : (((IData)(vlSelf->__VdfgTmp_h42ed6c05__0) 
                                             & ((IData)(vlSelf->__PVT__wb_wa) 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->__PVT__id_insn 
                                                    >> 0x10U))))
                                             ? vlSelf->__PVT__wb_value
                                             : ((0U 
                                                 == 
                                                 (0x1fU 
                                                  & (vlSelf->__PVT__id_insn 
                                                     >> 0x10U)))
                                                 ? 0U
                                                 : 
                                                vlSelf->regs
                                                [(0x1fU 
                                                  & (vlSelf->__PVT__id_insn 
                                                     >> 0x10U))])))));
    __VdfgTmp_hfb8405e1__0 = (((IData)(vlSelf->__VdfgTmp_hcfa842a8__0) 
                               & ((IData)(vlSelf->__PVT__ex_wa) 
                                  == (0x1fU & (vlSelf->__PVT__id_insn 
                                               >> 0x15U))))
                               ? vlSelf->__PVT__alu
                               : (((IData)(vlSelf->__VdfgTmp_hc5c1aa8c__0) 
                                   & ((IData)(vlSelf->__PVT__me_wa) 
                                      == (0x1fU & (vlSelf->__PVT__id_insn 
                                                   >> 0x15U))))
                                   ? __PVT__me_fwd : 
                                  (((IData)(vlSelf->__VdfgTmp_h42ed6c05__0) 
                                    & ((IData)(vlSelf->__PVT__wb_wa) 
                                       == (0x1fU & 
                                           (vlSelf->__PVT__id_insn 
                                            >> 0x15U))))
                                    ? vlSelf->__PVT__wb_value
                                    : ((0U == (0x1fU 
                                               & (vlSelf->__PVT__id_insn 
                                                  >> 0x15U)))
                                        ? 0U : vlSelf->regs
                                       [(0x1fU & (vlSelf->__PVT__id_insn 
                                                  >> 0x15U))]))));
    vlSelf->__PVT__ex_exc_out_v = ((IData)(vlSelf->__PVT__ex_exc_v) 
                                   | (IData)(__PVT__ex_new_exc));
    __VdfgExtracted_h61748c33__0 = ((0U != (0x1fU & 
                                            (vlSelf->__PVT__id_insn 
                                             >> 0x15U))) 
                                    & (__VdfgTmp_hfb8405e1__0 
                                       >> 0x1fU));
    vlSelf->__PVT__id_s = ((0U == (0x1fU & (vlSelf->__PVT__id_insn 
                                            >> 0x15U)))
                            ? 0U : __VdfgTmp_hfb8405e1__0);
    vlSelf->__PVT__id_tgt = ((IData)(4U) + (vlSelf->__PVT__id_pc 
                                            + VL_SHIFTL_III(32,32,32, 
                                                            (((- (IData)(
                                                                         (1U 
                                                                          & (vlSelf->__PVT__id_insn 
                                                                             >> 0xfU)))) 
                                                              << 0x10U) 
                                                             | (0xffffU 
                                                                & vlSelf->__PVT__id_insn)), 2U)));
    vlSelf->__PVT__id_taken = 0U;
    if ((1U & (~ (vlSelf->__PVT__id_insn >> 0x1fU)))) {
        if ((1U & (~ (vlSelf->__PVT__id_insn >> 0x1eU)))) {
            if ((1U & (~ (vlSelf->__PVT__id_insn >> 0x1dU)))) {
                if ((1U & (~ (vlSelf->__PVT__id_insn 
                              >> 0x1cU)))) {
                    if ((0x8000000U & vlSelf->__PVT__id_insn)) {
                        vlSelf->__PVT__id_tgt = ((0xf0000000U 
                                                  & vlSelf->__PVT__id_pc) 
                                                 | (0xffffffcU 
                                                    & (vlSelf->__PVT__id_insn 
                                                       << 2U)));
                    } else if ((1U & (~ (vlSelf->__PVT__id_insn 
                                         >> 0x1aU)))) {
                        if (vlSelf->__VdfgExtracted_h84f92045__0) {
                            vlSelf->__PVT__id_tgt = vlSelf->__PVT__id_s;
                        }
                    }
                }
                if ((0x10000000U & vlSelf->__PVT__id_insn)) {
                    vlSelf->__PVT__id_taken = ((0x8000000U 
                                                & vlSelf->__PVT__id_insn)
                                                ? (
                                                   (0x4000000U 
                                                    & vlSelf->__PVT__id_insn)
                                                    ? 
                                                   ((~ (IData)(__VdfgExtracted_h61748c33__0)) 
                                                    & (0U 
                                                       != vlSelf->__PVT__id_s))
                                                    : 
                                                   ((IData)(__VdfgExtracted_h61748c33__0) 
                                                    | (0U 
                                                       == vlSelf->__PVT__id_s)))
                                                : (
                                                   (0x4000000U 
                                                    & vlSelf->__PVT__id_insn)
                                                    ? 
                                                   (vlSelf->__PVT__id_s 
                                                    != vlSelf->__PVT__id_t)
                                                    : 
                                                   (vlSelf->__PVT__id_s 
                                                    == vlSelf->__PVT__id_t)));
                } else if ((0x8000000U & vlSelf->__PVT__id_insn)) {
                    vlSelf->__PVT__id_taken = 1U;
                } else if ((0x4000000U & vlSelf->__PVT__id_insn)) {
                    if ((1U & (~ (vlSelf->__PVT__id_insn 
                                  >> 0x13U)))) {
                        if ((1U & (~ (vlSelf->__PVT__id_insn 
                                      >> 0x12U)))) {
                            if ((1U & (~ (vlSelf->__PVT__id_insn 
                                          >> 0x11U)))) {
                                vlSelf->__PVT__id_taken 
                                    = (1U & ((0x10000U 
                                              & vlSelf->__PVT__id_insn)
                                              ? (~ (IData)(__VdfgExtracted_h61748c33__0))
                                              : (IData)(__VdfgExtracted_h61748c33__0)));
                            }
                        }
                    }
                } else if (vlSelf->__VdfgExtracted_h84f92045__0) {
                    vlSelf->__PVT__id_taken = 1U;
                }
            }
        }
    }
    vlSelf->__PVT__id_next_pc = ((IData)(vlSelf->__PVT__id_taken)
                                  ? vlSelf->__PVT__id_tgt
                                  : ((IData)(4U) + vlSelf->__PVT__a_next_pc));
    vlSelf->__PVT__id_redirect = ((IData)(vlSelf->__PVT__adv_id) 
                                  & ((IData)(vlSelf->__PVT__id_v) 
                                     & ((~ (IData)(vlSelf->__PVT__exc_flush)) 
                                        & (IData)(vlSelf->__PVT__id_taken))));
    vlSelf->__PVT__fpc_nxt = ((IData)(vlSelf->__PVT__redir_v)
                               ? vlSelf->__PVT__redir_pc
                               : ((IData)(vlSelf->__PVT__id_redirect)
                                   ? vlSelf->__PVT__id_tgt
                                   : ((IData)(4U) + vlSelf->__PVT__fpc)));
}

VL_INLINE_OPT void Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__2(Vtb_board_r3900__Cz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__2\n"); );
    // Body
    vlSelf->__PVT__fetch_ok = ((IData)(vlSelf->__PVT__ibus_req) 
                               & ((IData)(vlSymsp->TOP__tb_board__cpu.__PVT__cache__DOT__i_hit) 
                                  | ((IData)(vlSymsp->TOP__tb_board__cpu.cache__DOT____VdfgTmp_h6d079f16__0) 
                                     | (IData)(vlSymsp->TOP__tb_board__cpu.__PVT__cache__DOT__i_fill_fail))));
    vlSelf->__PVT__ibus_addr_la = ((IData)(vlSelf->__PVT__exc_flush)
                                    ? ([&]() {
                vlSelf->__Vfunc_phys__2__va = ((0x400000U 
                                                & vlSelf->__PVT__cp0
                                                [0xcU])
                                                ? 0xbfc00180U
                                                : 0x80000080U);
                vlSelf->__Vfunc_phys__2__Vfuncout = 
                    (((0x80000000U <= vlSelf->__Vfunc_phys__2__va) 
                      & (0xc0000000U > vlSelf->__Vfunc_phys__2__va))
                      ? (0x1fffffffU & vlSelf->__Vfunc_phys__2__va)
                      : vlSelf->__Vfunc_phys__2__va);
            }(), vlSelf->__Vfunc_phys__2__Vfuncout)
                                    : ((IData)(vlSelf->__PVT__fetch_ok)
                                        ? ([&]() {
                    vlSelf->__Vfunc_phys__3__va = vlSelf->__PVT__fpc_nxt;
                    vlSelf->__Vfunc_phys__3__Vfuncout 
                        = (((0x80000000U <= vlSelf->__Vfunc_phys__3__va) 
                            & (0xc0000000U > vlSelf->__Vfunc_phys__3__va))
                            ? (0x1fffffffU & vlSelf->__Vfunc_phys__3__va)
                            : vlSelf->__Vfunc_phys__3__va);
                }(), vlSelf->__Vfunc_phys__3__Vfuncout)
                                        : ([&]() {
                    vlSelf->__Vfunc_phys__4__va = vlSelf->__PVT__fpc;
                    vlSelf->__Vfunc_phys__4__Vfuncout 
                        = (((0x80000000U <= vlSelf->__Vfunc_phys__4__va) 
                            & (0xc0000000U > vlSelf->__Vfunc_phys__4__va))
                            ? (0x1fffffffU & vlSelf->__Vfunc_phys__4__va)
                            : vlSelf->__Vfunc_phys__4__va);
                }(), vlSelf->__Vfunc_phys__4__Vfuncout)));
}

VL_INLINE_OPT void Vtb_board_r3900__Cz2___nba_sequent__TOP__tb_board__cpu__cpu__0(Vtb_board_r3900__Cz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_board_r3900__Cz2___nba_sequent__TOP__tb_board__cpu__cpu__0\n"); );
    // Body
    if (((((IData)(vlSymsp->TOP.rst_n) & (IData)(vlSelf->__PVT__adv_id)) 
          & (IData)(vlSelf->__PVT__id_v)) & (~ (IData)(vlSelf->__PVT__exc_flush)))) {
        if (VL_UNLIKELY((vlSelf->__PVT__a_pc != vlSelf->__PVT__id_pc))) {
            VL_WRITEF("r3900: architectural pc %08x != fetched pc %08x\n",
                      32,vlSelf->__PVT__a_pc,32,vlSelf->__PVT__id_pc);
            VL_STOP_MT("../../rtl/cpu/r3900.sv", 1054, "");
        }
    }
}

VL_INLINE_OPT void Vtb_board_r3900__Cz2___nba_sequent__TOP__tb_board__cpu__cpu__1(Vtb_board_r3900__Cz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_board_r3900__Cz2___nba_sequent__TOP__tb_board__cpu__cpu__1\n"); );
    // Init
    CData/*0:0*/ __PVT__ex_writes;
    __PVT__ex_writes = 0;
    CData/*0:0*/ __PVT__me_writes;
    __PVT__me_writes = 0;
    CData/*0:0*/ __PVT__ex_is_load;
    __PVT__ex_is_load = 0;
    CData/*0:0*/ __PVT__id_needs_rs;
    __PVT__id_needs_rs = 0;
    CData/*0:0*/ __PVT__id_needs_rt;
    __PVT__id_needs_rt = 0;
    CData/*0:0*/ __PVT__me_is_load;
    __PVT__me_is_load = 0;
    CData/*0:0*/ __VdfgTmp_hc3cd8cde__0;
    __VdfgTmp_hc3cd8cde__0 = 0;
    IData/*31:0*/ __Vfunc_phys__0__Vfuncout;
    __Vfunc_phys__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_phys__0__va;
    __Vfunc_phys__0__va = 0;
    CData/*0:0*/ __Vfunc_cacheable__1__Vfuncout;
    __Vfunc_cacheable__1__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_cacheable__1__va;
    __Vfunc_cacheable__1__va = 0;
    CData/*4:0*/ __Vfunc_dest_reg__27__Vfuncout;
    __Vfunc_dest_reg__27__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_dest_reg__27__i;
    __Vfunc_dest_reg__27__i = 0;
    CData/*4:0*/ __Vfunc_dest_reg__28__Vfuncout;
    __Vfunc_dest_reg__28__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_dest_reg__28__i;
    __Vfunc_dest_reg__28__i = 0;
    CData/*0:0*/ __Vfunc_cacheable__79__Vfuncout;
    __Vfunc_cacheable__79__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_cacheable__79__va;
    __Vfunc_cacheable__79__va = 0;
    IData/*31:0*/ __Vfunc_phys__80__Vfuncout;
    __Vfunc_phys__80__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_phys__80__va;
    __Vfunc_phys__80__va = 0;
    CData/*0:0*/ __Vfunc_writes_gpr__83__Vfuncout;
    __Vfunc_writes_gpr__83__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_writes_gpr__83__i;
    __Vfunc_writes_gpr__83__i = 0;
    CData/*0:0*/ __Vfunc_is_store__84__Vfuncout;
    __Vfunc_is_store__84__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_store__84__i;
    __Vfunc_is_store__84__i = 0;
    CData/*0:0*/ __Vfunc_is_store__85__Vfuncout;
    __Vfunc_is_store__85__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_store__85__i;
    __Vfunc_is_store__85__i = 0;
    CData/*0:0*/ __Vfunc_is_store__86__Vfuncout;
    __Vfunc_is_store__86__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_store__86__i;
    __Vfunc_is_store__86__i = 0;
    CData/*0:0*/ __Vfunc_is_store__87__Vfuncout;
    __Vfunc_is_store__87__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_store__87__i;
    __Vfunc_is_store__87__i = 0;
    CData/*0:0*/ __Vfunc_is_store__88__Vfuncout;
    __Vfunc_is_store__88__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_store__88__i;
    __Vfunc_is_store__88__i = 0;
    CData/*0:0*/ __Vfunc_is_store__89__Vfuncout;
    __Vfunc_is_store__89__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_store__89__i;
    __Vfunc_is_store__89__i = 0;
    CData/*0:0*/ __Vfunc_is_store__90__Vfuncout;
    __Vfunc_is_store__90__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_store__90__i;
    __Vfunc_is_store__90__i = 0;
    CData/*0:0*/ __Vfunc_is_store__91__Vfuncout;
    __Vfunc_is_store__91__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_store__91__i;
    __Vfunc_is_store__91__i = 0;
    CData/*0:0*/ __Vfunc_is_store__92__Vfuncout;
    __Vfunc_is_store__92__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_store__92__i;
    __Vfunc_is_store__92__i = 0;
    CData/*0:0*/ __Vfunc_is_store__93__Vfuncout;
    __Vfunc_is_store__93__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_store__93__i;
    __Vfunc_is_store__93__i = 0;
    CData/*4:0*/ __Vfunc_dest_reg__94__Vfuncout;
    __Vfunc_dest_reg__94__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_dest_reg__94__i;
    __Vfunc_dest_reg__94__i = 0;
    CData/*0:0*/ __Vfunc_is_load__95__Vfuncout;
    __Vfunc_is_load__95__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_load__95__i;
    __Vfunc_is_load__95__i = 0;
    CData/*0:0*/ __Vfunc_is_rmw__96__Vfuncout;
    __Vfunc_is_rmw__96__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_rmw__96__i;
    __Vfunc_is_rmw__96__i = 0;
    CData/*0:0*/ __Vfunc_illegal__97__Vfuncout;
    __Vfunc_illegal__97__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_illegal__97__i;
    __Vfunc_illegal__97__i = 0;
    CData/*0:0*/ __Vfunc_is_branch__98__Vfuncout;
    __Vfunc_is_branch__98__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_branch__98__i;
    __Vfunc_is_branch__98__i = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v0;
    __Vdlyvval__cp0__v0 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v0;
    __Vdlyvset__cp0__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__cp0__v1;
    __Vdlyvdim0__cp0__v1 = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v1;
    __Vdlyvval__cp0__v1 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v1;
    __Vdlyvset__cp0__v1 = 0;
    CData/*4:0*/ __Vdlyvdim0__cp0__v2;
    __Vdlyvdim0__cp0__v2 = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v2;
    __Vdlyvval__cp0__v2 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v2;
    __Vdlyvset__cp0__v2 = 0;
    CData/*4:0*/ __Vdlyvdim0__cp0__v3;
    __Vdlyvdim0__cp0__v3 = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v3;
    __Vdlyvval__cp0__v3 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v3;
    __Vdlyvset__cp0__v3 = 0;
    CData/*4:0*/ __Vdlyvdim0__cp0__v4;
    __Vdlyvdim0__cp0__v4 = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v4;
    __Vdlyvval__cp0__v4 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v4;
    __Vdlyvset__cp0__v4 = 0;
    CData/*4:0*/ __Vdlyvdim0__cp0__v5;
    __Vdlyvdim0__cp0__v5 = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v5;
    __Vdlyvval__cp0__v5 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v5;
    __Vdlyvset__cp0__v5 = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v6;
    __Vdlyvval__cp0__v6 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v6;
    __Vdlyvset__cp0__v6 = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v7;
    __Vdlyvval__cp0__v7 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v7;
    __Vdlyvset__cp0__v7 = 0;
    CData/*4:0*/ __Vdlyvdim0__cp0__v8;
    __Vdlyvdim0__cp0__v8 = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v8;
    __Vdlyvval__cp0__v8 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v8;
    __Vdlyvset__cp0__v8 = 0;
    QData/*63:0*/ __Vdly__cycle_count;
    __Vdly__cycle_count = 0;
    CData/*4:0*/ __Vdlyvdim0__cp0__v9;
    __Vdlyvdim0__cp0__v9 = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v9;
    __Vdlyvval__cp0__v9 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v9;
    __Vdlyvset__cp0__v9 = 0;
    CData/*4:0*/ __Vdlyvdim0__cp0__v10;
    __Vdlyvdim0__cp0__v10 = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v10;
    __Vdlyvval__cp0__v10 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v10;
    __Vdlyvset__cp0__v10 = 0;
    CData/*4:0*/ __Vdlyvdim0__cp0__v11;
    __Vdlyvdim0__cp0__v11 = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v11;
    __Vdlyvval__cp0__v11 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v11;
    __Vdlyvset__cp0__v11 = 0;
    CData/*4:0*/ __Vdlyvdim0__regs__v0;
    __Vdlyvdim0__regs__v0 = 0;
    IData/*31:0*/ __Vdlyvval__regs__v0;
    __Vdlyvval__regs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__regs__v0;
    __Vdlyvset__regs__v0 = 0;
    IData/*31:0*/ __Vdly__hi;
    __Vdly__hi = 0;
    IData/*31:0*/ __Vdly__lo;
    __Vdly__lo = 0;
    CData/*0:0*/ __Vdly__me_phase;
    __Vdly__me_phase = 0;
    IData/*31:0*/ __Vdly__me_pc;
    __Vdly__me_pc = 0;
    CData/*0:0*/ __Vdly__me_ds;
    __Vdly__me_ds = 0;
    CData/*0:0*/ __Vdly__md_run;
    __Vdly__md_run = 0;
    CData/*5:0*/ __Vdly__md_count;
    __Vdly__md_count = 0;
    CData/*0:0*/ __Vdly__md_skip;
    __Vdly__md_skip = 0;
    CData/*0:0*/ __Vdly__id_v;
    __Vdly__id_v = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v12;
    __Vdlyvval__cp0__v12 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v12;
    __Vdlyvset__cp0__v12 = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v13;
    __Vdlyvval__cp0__v13 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v13;
    __Vdlyvset__cp0__v13 = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v14;
    __Vdlyvval__cp0__v14 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v14;
    __Vdlyvset__cp0__v14 = 0;
    IData/*31:0*/ __Vdlyvval__cp0__v15;
    __Vdlyvval__cp0__v15 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v15;
    __Vdlyvset__cp0__v15 = 0;
    CData/*0:0*/ __Vdlyvset__cp0__v16;
    __Vdlyvset__cp0__v16 = 0;
    CData/*0:0*/ __Vdlyvset__regs__v1;
    __Vdlyvset__regs__v1 = 0;
    CData/*0:0*/ __Vdlyvset__regs__v2;
    __Vdlyvset__regs__v2 = 0;
    // Body
    __Vdly__me_ds = vlSelf->__PVT__me_ds;
    __Vdly__me_pc = vlSelf->__PVT__me_pc;
    __Vdlyvset__regs__v0 = 0U;
    __Vdly__lo = vlSelf->lo;
    __Vdly__hi = vlSelf->hi;
    __Vdly__cycle_count = vlSelf->cycle_count;
    __Vdly__md_skip = vlSelf->__PVT__md_skip;
    __Vdly__md_count = vlSelf->__PVT__md_count;
    __Vdly__md_run = vlSelf->__PVT__md_run;
    __Vdlyvset__cp0__v0 = 0U;
    __Vdlyvset__cp0__v1 = 0U;
    __Vdlyvset__cp0__v2 = 0U;
    __Vdlyvset__cp0__v3 = 0U;
    __Vdlyvset__cp0__v4 = 0U;
    __Vdlyvset__cp0__v5 = 0U;
    __Vdlyvset__cp0__v6 = 0U;
    __Vdlyvset__cp0__v7 = 0U;
    __Vdlyvset__cp0__v8 = 0U;
    __Vdlyvset__cp0__v9 = 0U;
    __Vdlyvset__cp0__v10 = 0U;
    __Vdlyvset__cp0__v11 = 0U;
    __Vdlyvset__cp0__v12 = 0U;
    __Vdlyvset__cp0__v13 = 0U;
    __Vdlyvset__cp0__v14 = 0U;
    __Vdlyvset__cp0__v15 = 0U;
    __Vdlyvset__cp0__v16 = 0U;
    __Vdlyvset__regs__v1 = 0U;
    __Vdlyvset__regs__v2 = 0U;
    __Vdly__id_v = vlSelf->__PVT__id_v;
    __Vdly__me_phase = vlSelf->__PVT__me_phase;
    if (vlSymsp->TOP.rst_n) {
        if (vlSelf->__PVT__wb_v) {
            vlSelf->__PVT__rt_v = 1U;
            vlSelf->__PVT__rt_pc = vlSelf->__PVT__wb_pc;
            vlSelf->__PVT__rt_insn = vlSelf->__PVT__wb_insn;
            vlSelf->__PVT__rt_next_pc = vlSelf->__PVT__wb_next_pc;
            if (vlSelf->__PVT__wb_cp0_we) {
                if ((0x10U & (IData)(vlSelf->__PVT__wb_cp0_a))) {
                    if ((8U & (IData)(vlSelf->__PVT__wb_cp0_a))) {
                        if ((4U & (IData)(vlSelf->__PVT__wb_cp0_a))) {
                            if ((2U & (IData)(vlSelf->__PVT__wb_cp0_a))) {
                                if ((1U & (IData)(vlSelf->__PVT__wb_cp0_a))) {
                                    __Vdlyvval__cp0__v0 
                                        = ((0xfffffff0U 
                                            & vlSelf->__PVT__cp0
                                            [0xcU]) 
                                           | (0xfU 
                                              & VL_SHIFTR_III(32,32,32, 
                                                              vlSelf->__PVT__cp0
                                                              [0xcU], 2U)));
                                    __Vdlyvset__cp0__v0 = 1U;
                                } else {
                                    __Vdlyvval__cp0__v1 
                                        = vlSelf->__PVT__wb_cp0_d;
                                    __Vdlyvset__cp0__v1 = 1U;
                                    __Vdlyvdim0__cp0__v1 
                                        = vlSelf->__PVT__wb_cp0_a;
                                }
                            } else {
                                __Vdlyvval__cp0__v2 
                                    = vlSelf->__PVT__wb_cp0_d;
                                __Vdlyvset__cp0__v2 = 1U;
                                __Vdlyvdim0__cp0__v2 
                                    = vlSelf->__PVT__wb_cp0_a;
                            }
                        } else {
                            __Vdlyvval__cp0__v3 = vlSelf->__PVT__wb_cp0_d;
                            __Vdlyvset__cp0__v3 = 1U;
                            __Vdlyvdim0__cp0__v3 = vlSelf->__PVT__wb_cp0_a;
                        }
                    } else {
                        __Vdlyvval__cp0__v4 = vlSelf->__PVT__wb_cp0_d;
                        __Vdlyvset__cp0__v4 = 1U;
                        __Vdlyvdim0__cp0__v4 = vlSelf->__PVT__wb_cp0_a;
                    }
                } else if ((8U & (IData)(vlSelf->__PVT__wb_cp0_a))) {
                    if ((4U & (IData)(vlSelf->__PVT__wb_cp0_a))) {
                        if ((2U & (IData)(vlSelf->__PVT__wb_cp0_a))) {
                            if ((1U & (~ (IData)(vlSelf->__PVT__wb_cp0_a)))) {
                                __Vdlyvval__cp0__v5 
                                    = vlSelf->__PVT__wb_cp0_d;
                                __Vdlyvset__cp0__v5 = 1U;
                                __Vdlyvdim0__cp0__v5 
                                    = vlSelf->__PVT__wb_cp0_a;
                            }
                        } else if ((1U & (IData)(vlSelf->__PVT__wb_cp0_a))) {
                            __Vdlyvval__cp0__v6 = (
                                                   (0xfffffcffU 
                                                    & vlSelf->__PVT__cp0
                                                    [0xdU]) 
                                                   | (0x300U 
                                                      & vlSelf->__PVT__wb_cp0_d));
                            __Vdlyvset__cp0__v6 = 1U;
                        } else {
                            __Vdlyvval__cp0__v7 = (0xffefffffU 
                                                   & vlSelf->__PVT__wb_cp0_d);
                            __Vdlyvset__cp0__v7 = 1U;
                        }
                    } else if ((2U & (IData)(vlSelf->__PVT__wb_cp0_a))) {
                        __Vdlyvval__cp0__v8 = vlSelf->__PVT__wb_cp0_d;
                        __Vdlyvset__cp0__v8 = 1U;
                        __Vdlyvdim0__cp0__v8 = vlSelf->__PVT__wb_cp0_a;
                    } else if ((1U & (IData)(vlSelf->__PVT__wb_cp0_a))) {
                        __Vdly__cycle_count = ((QData)((IData)(vlSelf->__PVT__wb_cp0_d)) 
                                               << 1U);
                    }
                } else if ((4U & (IData)(vlSelf->__PVT__wb_cp0_a))) {
                    __Vdlyvval__cp0__v9 = vlSelf->__PVT__wb_cp0_d;
                    __Vdlyvset__cp0__v9 = 1U;
                    __Vdlyvdim0__cp0__v9 = vlSelf->__PVT__wb_cp0_a;
                } else if ((2U & (IData)(vlSelf->__PVT__wb_cp0_a))) {
                    __Vdlyvval__cp0__v10 = vlSelf->__PVT__wb_cp0_d;
                    __Vdlyvset__cp0__v10 = 1U;
                    __Vdlyvdim0__cp0__v10 = vlSelf->__PVT__wb_cp0_a;
                } else if ((1U & (~ (IData)(vlSelf->__PVT__wb_cp0_a)))) {
                    __Vdlyvval__cp0__v11 = vlSelf->__PVT__wb_cp0_d;
                    __Vdlyvset__cp0__v11 = 1U;
                    __Vdlyvdim0__cp0__v11 = vlSelf->__PVT__wb_cp0_a;
                }
            }
            if (vlSelf->__PVT__wb_cache) {
                vlSelf->cache_ops = (1ULL + vlSelf->cache_ops);
            }
            vlSelf->insn_count = (1ULL + vlSelf->insn_count);
            if (((IData)(vlSelf->__PVT__wb_we) & (0U 
                                                  != (IData)(vlSelf->__PVT__wb_wa)))) {
                __Vdlyvval__regs__v0 = vlSelf->__PVT__wb_value;
                __Vdlyvset__regs__v0 = 1U;
                __Vdlyvdim0__regs__v0 = vlSelf->__PVT__wb_wa;
            }
            if (vlSelf->__PVT__wb_hilo_we) {
                __Vdly__hi = vlSelf->__PVT__wb_hi;
                __Vdly__lo = vlSelf->__PVT__wb_lo;
            }
            __Vdly__cycle_count = (1ULL + vlSelf->cycle_count);
        } else {
            vlSelf->__PVT__rt_v = 0U;
        }
        vlSelf->__PVT__wb_v = ((IData)(vlSelf->__PVT__adv_mem) 
                               & ((IData)(vlSelf->__PVT__me_v) 
                                  & ((~ (IData)(vlSelf->__PVT__me_exc_out_v)) 
                                     | (IData)(vlSelf->__PVT__me_exc_out_ret))));
        if (vlSelf->__PVT__adv_mem) {
            __Vfunc_dest_reg__94__i = vlSelf->__PVT__i_me;
            __Vfunc_dest_reg__94__Vfuncout = (0x1fU 
                                              & ((__Vfunc_dest_reg__94__i 
                                                  >> 0x1fU)
                                                  ? 
                                                 (__Vfunc_dest_reg__94__i 
                                                  >> 0x10U)
                                                  : 
                                                 ((0x40000000U 
                                                   & __Vfunc_dest_reg__94__i)
                                                   ? 
                                                  ((0x20000000U 
                                                    & __Vfunc_dest_reg__94__i)
                                                    ? 
                                                   (__Vfunc_dest_reg__94__i 
                                                    >> 0x10U)
                                                    : 
                                                   ((0x10000000U 
                                                     & __Vfunc_dest_reg__94__i)
                                                     ? 
                                                    (__Vfunc_dest_reg__94__i 
                                                     >> 0x10U)
                                                     : 
                                                    ((0x8000000U 
                                                      & __Vfunc_dest_reg__94__i)
                                                      ? 
                                                     (__Vfunc_dest_reg__94__i 
                                                      >> 0x10U)
                                                      : 
                                                     ((0x4000000U 
                                                       & __Vfunc_dest_reg__94__i)
                                                       ? 
                                                      (__Vfunc_dest_reg__94__i 
                                                       >> 0x10U)
                                                       : 
                                                      (__Vfunc_dest_reg__94__i 
                                                       >> 0x10U)))))
                                                   : 
                                                  ((0x20000000U 
                                                    & __Vfunc_dest_reg__94__i)
                                                    ? 
                                                   (__Vfunc_dest_reg__94__i 
                                                    >> 0x10U)
                                                    : 
                                                   ((0x10000000U 
                                                     & __Vfunc_dest_reg__94__i)
                                                     ? 
                                                    (__Vfunc_dest_reg__94__i 
                                                     >> 0x10U)
                                                     : 
                                                    ((0x8000000U 
                                                      & __Vfunc_dest_reg__94__i)
                                                      ? 
                                                     ((0x4000000U 
                                                       & __Vfunc_dest_reg__94__i)
                                                       ? 0x1fU
                                                       : 
                                                      (__Vfunc_dest_reg__94__i 
                                                       >> 0x10U))
                                                      : 
                                                     ((0x4000000U 
                                                       & __Vfunc_dest_reg__94__i)
                                                       ? 0x1fU
                                                       : 
                                                      ((9U 
                                                        == 
                                                        (0x3fU 
                                                         & __Vfunc_dest_reg__94__i))
                                                        ? 
                                                       ((0U 
                                                         == 
                                                         (0x1fU 
                                                          & (__Vfunc_dest_reg__94__i 
                                                             >> 0xbU)))
                                                         ? 0x1fU
                                                         : 
                                                        (__Vfunc_dest_reg__94__i 
                                                         >> 0xbU))
                                                        : 
                                                       (__Vfunc_dest_reg__94__i 
                                                        >> 0xbU)))))))));
            vlSelf->__PVT__wb_pc = vlSelf->__PVT__me_pc;
            vlSelf->__PVT__wb_insn = vlSelf->__PVT__me_insn;
            vlSelf->__PVT__wb_next_pc = ((IData)(vlSelf->__PVT__me_exc_out_v)
                                          ? ((IData)(4U) 
                                             + vlSelf->__PVT__exc_vector)
                                          : vlSelf->__PVT__me_next_pc);
            vlSelf->__PVT__wb_we = (([&]() {
                        __Vfunc_writes_gpr__83__i = vlSelf->__PVT__i_me;
                        __Vfunc_writes_gpr__83__Vfuncout 
                            = (1U & ((__Vfunc_writes_gpr__83__i 
                                      >> 0x1fU) ? (
                                                   (0x40000000U 
                                                    & __Vfunc_writes_gpr__83__i)
                                                    ? 
                                                   (~ 
                                                    ([&]() {
                                                __Vfunc_is_store__84__i 
                                                    = __Vfunc_writes_gpr__83__i;
                                                __Vfunc_is_store__84__Vfuncout 
                                                    = 
                                                    (((((0x28U 
                                                         == 
                                                         (__Vfunc_is_store__84__i 
                                                          >> 0x1aU)) 
                                                        | (0x29U 
                                                           == 
                                                           (__Vfunc_is_store__84__i 
                                                            >> 0x1aU))) 
                                                       | (0x2bU 
                                                          == 
                                                          (__Vfunc_is_store__84__i 
                                                           >> 0x1aU))) 
                                                      | (0x2aU 
                                                         == 
                                                         (__Vfunc_is_store__84__i 
                                                          >> 0x1aU))) 
                                                     | (0x2eU 
                                                        == 
                                                        (__Vfunc_is_store__84__i 
                                                         >> 0x1aU)));
                                            }(), (IData)(__Vfunc_is_store__84__Vfuncout)))
                                                    : 
                                                   ((0x20000000U 
                                                     & __Vfunc_writes_gpr__83__i)
                                                     ? 
                                                    ((0x10000000U 
                                                      & __Vfunc_writes_gpr__83__i)
                                                      ? 
                                                     ((0x8000000U 
                                                       & __Vfunc_writes_gpr__83__i)
                                                       ? 
                                                      ((1U 
                                                        & (~ 
                                                           (__Vfunc_writes_gpr__83__i 
                                                            >> 0x1aU))) 
                                                       && (1U 
                                                           & (~ 
                                                              ([&]() {
                                                                    __Vfunc_is_store__85__i 
                                                                        = __Vfunc_writes_gpr__83__i;
                                                                    __Vfunc_is_store__85__Vfuncout 
                                                                        = 
                                                                        (((((0x28U 
                                                                             == 
                                                                             (__Vfunc_is_store__85__i 
                                                                              >> 0x1aU)) 
                                                                            | (0x29U 
                                                                               == 
                                                                               (__Vfunc_is_store__85__i 
                                                                                >> 0x1aU))) 
                                                                           | (0x2bU 
                                                                              == 
                                                                              (__Vfunc_is_store__85__i 
                                                                               >> 0x1aU))) 
                                                                          | (0x2aU 
                                                                             == 
                                                                             (__Vfunc_is_store__85__i 
                                                                              >> 0x1aU))) 
                                                                         | (0x2eU 
                                                                            == 
                                                                            (__Vfunc_is_store__85__i 
                                                                             >> 0x1aU)));
                                                                }(), (IData)(__Vfunc_is_store__85__Vfuncout)))))
                                                       : 
                                                      (~ 
                                                       ([&]() {
                                                            __Vfunc_is_store__86__i 
                                                                = __Vfunc_writes_gpr__83__i;
                                                            __Vfunc_is_store__86__Vfuncout 
                                                                = 
                                                                (((((0x28U 
                                                                     == 
                                                                     (__Vfunc_is_store__86__i 
                                                                      >> 0x1aU)) 
                                                                    | (0x29U 
                                                                       == 
                                                                       (__Vfunc_is_store__86__i 
                                                                        >> 0x1aU))) 
                                                                   | (0x2bU 
                                                                      == 
                                                                      (__Vfunc_is_store__86__i 
                                                                       >> 0x1aU))) 
                                                                  | (0x2aU 
                                                                     == 
                                                                     (__Vfunc_is_store__86__i 
                                                                      >> 0x1aU))) 
                                                                 | (0x2eU 
                                                                    == 
                                                                    (__Vfunc_is_store__86__i 
                                                                     >> 0x1aU)));
                                                        }(), (IData)(__Vfunc_is_store__86__Vfuncout))))
                                                      : 
                                                     (~ 
                                                      ([&]() {
                                                        __Vfunc_is_store__87__i 
                                                            = __Vfunc_writes_gpr__83__i;
                                                        __Vfunc_is_store__87__Vfuncout 
                                                            = 
                                                            (((((0x28U 
                                                                 == 
                                                                 (__Vfunc_is_store__87__i 
                                                                  >> 0x1aU)) 
                                                                | (0x29U 
                                                                   == 
                                                                   (__Vfunc_is_store__87__i 
                                                                    >> 0x1aU))) 
                                                               | (0x2bU 
                                                                  == 
                                                                  (__Vfunc_is_store__87__i 
                                                                   >> 0x1aU))) 
                                                              | (0x2aU 
                                                                 == 
                                                                 (__Vfunc_is_store__87__i 
                                                                  >> 0x1aU))) 
                                                             | (0x2eU 
                                                                == 
                                                                (__Vfunc_is_store__87__i 
                                                                 >> 0x1aU)));
                                                    }(), (IData)(__Vfunc_is_store__87__Vfuncout))))
                                                     : 
                                                    (~ 
                                                     ([&]() {
                                                    __Vfunc_is_store__88__i 
                                                        = __Vfunc_writes_gpr__83__i;
                                                    __Vfunc_is_store__88__Vfuncout 
                                                        = 
                                                        (((((0x28U 
                                                             == 
                                                             (__Vfunc_is_store__88__i 
                                                              >> 0x1aU)) 
                                                            | (0x29U 
                                                               == 
                                                               (__Vfunc_is_store__88__i 
                                                                >> 0x1aU))) 
                                                           | (0x2bU 
                                                              == 
                                                              (__Vfunc_is_store__88__i 
                                                               >> 0x1aU))) 
                                                          | (0x2aU 
                                                             == 
                                                             (__Vfunc_is_store__88__i 
                                                              >> 0x1aU))) 
                                                         | (0x2eU 
                                                            == 
                                                            (__Vfunc_is_store__88__i 
                                                             >> 0x1aU)));
                                                }(), (IData)(__Vfunc_is_store__88__Vfuncout)))))
                                      : ((0x40000000U 
                                          & __Vfunc_writes_gpr__83__i)
                                          ? ((0x20000000U 
                                              & __Vfunc_writes_gpr__83__i)
                                              ? (~ 
                                                 ([&]() {
                                                    __Vfunc_is_store__89__i 
                                                        = __Vfunc_writes_gpr__83__i;
                                                    __Vfunc_is_store__89__Vfuncout 
                                                        = 
                                                        (((((0x28U 
                                                             == 
                                                             (__Vfunc_is_store__89__i 
                                                              >> 0x1aU)) 
                                                            | (0x29U 
                                                               == 
                                                               (__Vfunc_is_store__89__i 
                                                                >> 0x1aU))) 
                                                           | (0x2bU 
                                                              == 
                                                              (__Vfunc_is_store__89__i 
                                                               >> 0x1aU))) 
                                                          | (0x2aU 
                                                             == 
                                                             (__Vfunc_is_store__89__i 
                                                              >> 0x1aU))) 
                                                         | (0x2eU 
                                                            == 
                                                            (__Vfunc_is_store__89__i 
                                                             >> 0x1aU)));
                                                }(), (IData)(__Vfunc_is_store__89__Vfuncout)))
                                              : ((0x10000000U 
                                                  & __Vfunc_writes_gpr__83__i)
                                                  ? 
                                                 (~ 
                                                  ([&]() {
                                                        __Vfunc_is_store__90__i 
                                                            = __Vfunc_writes_gpr__83__i;
                                                        __Vfunc_is_store__90__Vfuncout 
                                                            = 
                                                            (((((0x28U 
                                                                 == 
                                                                 (__Vfunc_is_store__90__i 
                                                                  >> 0x1aU)) 
                                                                | (0x29U 
                                                                   == 
                                                                   (__Vfunc_is_store__90__i 
                                                                    >> 0x1aU))) 
                                                               | (0x2bU 
                                                                  == 
                                                                  (__Vfunc_is_store__90__i 
                                                                   >> 0x1aU))) 
                                                              | (0x2aU 
                                                                 == 
                                                                 (__Vfunc_is_store__90__i 
                                                                  >> 0x1aU))) 
                                                             | (0x2eU 
                                                                == 
                                                                (__Vfunc_is_store__90__i 
                                                                 >> 0x1aU)));
                                                    }(), (IData)(__Vfunc_is_store__90__Vfuncout)))
                                                  : 
                                                 ((0x8000000U 
                                                   & __Vfunc_writes_gpr__83__i)
                                                   ? 
                                                  (~ 
                                                   ([&]() {
                                                            __Vfunc_is_store__91__i 
                                                                = __Vfunc_writes_gpr__83__i;
                                                            __Vfunc_is_store__91__Vfuncout 
                                                                = 
                                                                (((((0x28U 
                                                                     == 
                                                                     (__Vfunc_is_store__91__i 
                                                                      >> 0x1aU)) 
                                                                    | (0x29U 
                                                                       == 
                                                                       (__Vfunc_is_store__91__i 
                                                                        >> 0x1aU))) 
                                                                   | (0x2bU 
                                                                      == 
                                                                      (__Vfunc_is_store__91__i 
                                                                       >> 0x1aU))) 
                                                                  | (0x2aU 
                                                                     == 
                                                                     (__Vfunc_is_store__91__i 
                                                                      >> 0x1aU))) 
                                                                 | (0x2eU 
                                                                    == 
                                                                    (__Vfunc_is_store__91__i 
                                                                     >> 0x1aU)));
                                                        }(), (IData)(__Vfunc_is_store__91__Vfuncout)))
                                                   : 
                                                  ((0x4000000U 
                                                    & __Vfunc_writes_gpr__83__i)
                                                    ? 
                                                   (~ 
                                                    ([&]() {
                                                                __Vfunc_is_store__92__i 
                                                                    = __Vfunc_writes_gpr__83__i;
                                                                __Vfunc_is_store__92__Vfuncout 
                                                                    = 
                                                                    (((((0x28U 
                                                                         == 
                                                                         (__Vfunc_is_store__92__i 
                                                                          >> 0x1aU)) 
                                                                        | (0x29U 
                                                                           == 
                                                                           (__Vfunc_is_store__92__i 
                                                                            >> 0x1aU))) 
                                                                       | (0x2bU 
                                                                          == 
                                                                          (__Vfunc_is_store__92__i 
                                                                           >> 0x1aU))) 
                                                                      | (0x2aU 
                                                                         == 
                                                                         (__Vfunc_is_store__92__i 
                                                                          >> 0x1aU))) 
                                                                     | (0x2eU 
                                                                        == 
                                                                        (__Vfunc_is_store__92__i 
                                                                         >> 0x1aU)));
                                                            }(), (IData)(__Vfunc_is_store__92__Vfuncout)))
                                                    : 
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & (__Vfunc_writes_gpr__83__i 
                                                        >> 0x15U)))))))
                                          : ((0x20000000U 
                                              & __Vfunc_writes_gpr__83__i)
                                              ? (~ 
                                                 ([&]() {
                                                    __Vfunc_is_store__93__i 
                                                        = __Vfunc_writes_gpr__83__i;
                                                    __Vfunc_is_store__93__Vfuncout 
                                                        = 
                                                        (((((0x28U 
                                                             == 
                                                             (__Vfunc_is_store__93__i 
                                                              >> 0x1aU)) 
                                                            | (0x29U 
                                                               == 
                                                               (__Vfunc_is_store__93__i 
                                                                >> 0x1aU))) 
                                                           | (0x2bU 
                                                              == 
                                                              (__Vfunc_is_store__93__i 
                                                               >> 0x1aU))) 
                                                          | (0x2aU 
                                                             == 
                                                             (__Vfunc_is_store__93__i 
                                                              >> 0x1aU))) 
                                                         | (0x2eU 
                                                            == 
                                                            (__Vfunc_is_store__93__i 
                                                             >> 0x1aU)));
                                                }(), (IData)(__Vfunc_is_store__93__Vfuncout)))
                                              : ((1U 
                                                  & (~ 
                                                     (__Vfunc_writes_gpr__83__i 
                                                      >> 0x1cU))) 
                                                 && (1U 
                                                     & ((0x8000000U 
                                                         & __Vfunc_writes_gpr__83__i)
                                                         ? 
                                                        (__Vfunc_writes_gpr__83__i 
                                                         >> 0x1aU)
                                                         : 
                                                        ((0x4000000U 
                                                          & __Vfunc_writes_gpr__83__i)
                                                          ? 
                                                         ((0x10U 
                                                           == 
                                                           (0x1fU 
                                                            & (__Vfunc_writes_gpr__83__i 
                                                               >> 0x10U))) 
                                                          | (0x11U 
                                                             == 
                                                             (0x1fU 
                                                              & (__Vfunc_writes_gpr__83__i 
                                                                 >> 0x10U))))
                                                          : 
                                                         ((1U 
                                                           & (__Vfunc_writes_gpr__83__i 
                                                              >> 5U)) 
                                                          || (1U 
                                                              & ((0x10U 
                                                                  & __Vfunc_writes_gpr__83__i)
                                                                  ? 
                                                                 ((8U 
                                                                   & __Vfunc_writes_gpr__83__i)
                                                                   ? 
                                                                  (__Vfunc_writes_gpr__83__i 
                                                                   >> 2U)
                                                                   : 
                                                                  ((1U 
                                                                    & (__Vfunc_writes_gpr__83__i 
                                                                       >> 2U)) 
                                                                   || (1U 
                                                                       & (~ __Vfunc_writes_gpr__83__i))))
                                                                  : 
                                                                 ((1U 
                                                                   & (~ 
                                                                      (__Vfunc_writes_gpr__83__i 
                                                                       >> 3U))) 
                                                                  || (1U 
                                                                      & ((4U 
                                                                          & __Vfunc_writes_gpr__83__i)
                                                                          ? 
                                                                         (__Vfunc_writes_gpr__83__i 
                                                                          >> 1U)
                                                                          : 
                                                                         ((1U 
                                                                           & (__Vfunc_writes_gpr__83__i 
                                                                              >> 1U)) 
                                                                          || (1U 
                                                                              & __Vfunc_writes_gpr__83__i))))))))))))))));
                    }(), (IData)(__Vfunc_writes_gpr__83__Vfuncout)) 
                                    & (~ (IData)(vlSelf->__PVT__me_exc_out_v)));
            vlSelf->__PVT__wb_wa = __Vfunc_dest_reg__94__Vfuncout;
            vlSelf->__PVT__wb_hi = vlSelf->__PVT__me_hi;
            vlSelf->__PVT__wb_lo = vlSelf->__PVT__me_lo;
            vlSelf->__PVT__wb_hilo_we = ((IData)(vlSelf->__PVT__me_hilo_we) 
                                         & (~ (IData)(vlSelf->__PVT__me_exc_out_v)));
            vlSelf->__PVT__wb_cache = ((0x2fU == (vlSelf->__PVT__i_me 
                                                  >> 0x1aU)) 
                                       & (~ (IData)(vlSelf->__PVT__me_exc_out_v)));
            vlSelf->__PVT__wb_cp0_we = (((0x10U == 
                                          (vlSelf->__PVT__i_me 
                                           >> 0x1aU)) 
                                         & (~ (IData)(vlSelf->__PVT__me_exc_out_v))) 
                                        & ((4U == (0x1fU 
                                                   & (vlSelf->__PVT__i_me 
                                                      >> 0x15U))) 
                                           | (0x10U 
                                              == (0x1fU 
                                                  & (vlSelf->__PVT__i_me 
                                                     >> 0x15U)))));
            vlSelf->__PVT__wb_cp0_a = ((0x10U == (0x1fU 
                                                  & (vlSelf->__PVT__i_me 
                                                     >> 0x15U)))
                                        ? 0x1fU : (0x1fU 
                                                   & (vlSelf->__PVT__i_me 
                                                      >> 0xbU)));
            vlSelf->__PVT__wb_cp0_d = vlSelf->__PVT__me_rt;
            __Vdly__me_phase = 0U;
            vlSelf->__PVT__wb_value = (([&]() {
                        __Vfunc_is_load__95__i = vlSelf->__PVT__i_me;
                        __Vfunc_is_load__95__Vfuncout 
                            = (((((((0x20U == (__Vfunc_is_load__95__i 
                                               >> 0x1aU)) 
                                    | (0x21U == (__Vfunc_is_load__95__i 
                                                 >> 0x1aU))) 
                                   | (0x23U == (__Vfunc_is_load__95__i 
                                                >> 0x1aU))) 
                                  | (0x24U == (__Vfunc_is_load__95__i 
                                               >> 0x1aU))) 
                                 | (0x25U == (__Vfunc_is_load__95__i 
                                              >> 0x1aU))) 
                                | (0x22U == (__Vfunc_is_load__95__i 
                                             >> 0x1aU))) 
                               | (0x26U == (__Vfunc_is_load__95__i 
                                            >> 0x1aU)));
                    }(), (IData)(__Vfunc_is_load__95__Vfuncout))
                                        ? vlSelf->__PVT__load_value
                                        : vlSelf->__PVT__me_result);
        } else if ((((((IData)(vlSelf->__PVT__me_needs_mem) 
                       & (IData)(vlSymsp->TOP__tb_board__cpu.__PVT__dack)) 
                      & (~ (IData)(vlSymsp->TOP__tb_board__cpu.__PVT__derr))) 
                     & ([&]() {
                            __Vfunc_is_rmw__96__i = vlSelf->__PVT__i_me;
                            __Vfunc_is_rmw__96__Vfuncout 
                                = ((0x2aU == (__Vfunc_is_rmw__96__i 
                                              >> 0x1aU)) 
                                   | (0x2eU == (__Vfunc_is_rmw__96__i 
                                                >> 0x1aU)));
                        }(), (IData)(__Vfunc_is_rmw__96__Vfuncout))) 
                    & (~ (IData)(vlSelf->__PVT__me_phase)))) {
            vlSelf->__PVT__me_rmw_word = vlSymsp->TOP__tb_board__cpu.__PVT__drd;
            __Vdly__me_phase = 1U;
        }
        if (vlSelf->__PVT__adv_mem) {
            vlSelf->__PVT__me_v = ((IData)(vlSelf->__PVT__ex_v) 
                                   & (~ (IData)(vlSelf->__PVT__exc_flush)));
            __Vdly__me_pc = vlSelf->__PVT__ex_pc;
            vlSelf->__PVT__me_insn = vlSelf->__PVT__ex_insn;
            vlSelf->__PVT__me_next_pc = vlSelf->__PVT__ex_next_pc;
            vlSelf->__PVT__me_result = vlSelf->__PVT__alu;
            vlSelf->__PVT__me_rt = vlSelf->__PVT__t;
            vlSelf->__PVT__me_va = vlSelf->__PVT__addi_r;
            __Vdly__me_ds = vlSelf->__PVT__ex_ds;
            vlSelf->__PVT__me_exc_v = vlSelf->__PVT__ex_exc_out_v;
            vlSelf->__PVT__me_exc_code = vlSelf->__PVT__ex_exc_out_code;
            vlSelf->__PVT__me_exc_bad = vlSelf->__PVT__ex_exc_out_bad;
            vlSelf->__PVT__me_exc_bad_v = vlSelf->__PVT__ex_exc_out_badv;
            vlSelf->__PVT__me_exc_ret = vlSelf->__PVT__ex_exc_out_ret;
            vlSelf->__PVT__me_hilo_we = 0U;
            if (((IData)(vlSelf->__PVT__ex_v) & (0U 
                                                 == 
                                                 (vlSelf->__PVT__i_ex 
                                                  >> 0x1aU)))) {
                if ((1U & (~ (vlSelf->__PVT__i_ex >> 5U)))) {
                    if ((0x10U & vlSelf->__PVT__i_ex)) {
                        if ((8U & vlSelf->__PVT__i_ex)) {
                            if ((1U & (~ (vlSelf->__PVT__i_ex 
                                          >> 2U)))) {
                                if ((2U & vlSelf->__PVT__i_ex)) {
                                    vlSelf->__PVT__me_hilo_we = 1U;
                                    if (vlSelf->__PVT__md_skip) {
                                        vlSelf->__PVT__me_hi 
                                            = vlSelf->__PVT__md_fix_hi;
                                        vlSelf->__PVT__me_lo 
                                            = vlSelf->__PVT__md_fix_lo;
                                    } else {
                                        vlSelf->__PVT__me_hi 
                                            = vlSelf->__PVT__div_r;
                                        vlSelf->__PVT__me_lo 
                                            = vlSelf->__PVT__div_q;
                                    }
                                } else if ((1U & vlSelf->__PVT__i_ex)) {
                                    vlSelf->__PVT__me_hilo_we = 1U;
                                    vlSelf->__PVT__me_hi 
                                        = (IData)((vlSelf->__PVT__mul_u 
                                                   >> 0x20U));
                                    vlSelf->__PVT__me_lo 
                                        = (IData)(vlSelf->__PVT__mul_u);
                                } else {
                                    vlSelf->__PVT__me_hilo_we = 1U;
                                    vlSelf->__PVT__me_hi 
                                        = (IData)((vlSelf->__PVT__mul_s 
                                                   >> 0x20U));
                                    vlSelf->__PVT__me_lo 
                                        = (IData)(vlSelf->__PVT__mul_s);
                                }
                            }
                        } else if ((1U & (~ (vlSelf->__PVT__i_ex 
                                             >> 2U)))) {
                            if ((2U & vlSelf->__PVT__i_ex)) {
                                if ((1U & vlSelf->__PVT__i_ex)) {
                                    vlSelf->__PVT__me_hilo_we = 1U;
                                    vlSelf->__PVT__me_hi 
                                        = vlSelf->hi;
                                    vlSelf->__PVT__me_lo 
                                        = vlSelf->__PVT__s;
                                }
                            } else if ((1U & vlSelf->__PVT__i_ex)) {
                                vlSelf->__PVT__me_hilo_we = 1U;
                                vlSelf->__PVT__me_hi 
                                    = vlSelf->__PVT__s;
                                vlSelf->__PVT__me_lo 
                                    = vlSelf->lo;
                            }
                        }
                    }
                }
            }
            if ((1U & (~ (IData)(vlSelf->__PVT__adv_ex)))) {
                vlSelf->__PVT__me_v = 0U;
            }
        }
        if (((IData)(vlSelf->__PVT__ex_is_div) & (~ (IData)(vlSelf->__PVT__md_run)))) {
            __Vdly__md_run = 1U;
            __Vdly__md_count = 0x20U;
            if ((0x1bU == (0x3fU & vlSelf->__PVT__i_ex))) {
                vlSelf->__PVT__md_rq = (QData)((IData)(vlSelf->__PVT__s));
                vlSelf->__PVT__md_d = vlSelf->__PVT__t;
                vlSelf->__PVT__md_neg_q = 0U;
                vlSelf->__PVT__md_neg_r = 0U;
                __Vdly__md_skip = (0U == vlSelf->__PVT__t);
                vlSelf->__PVT__md_fix_lo = 0xffffffffU;
                vlSelf->__PVT__md_fix_hi = vlSelf->__PVT__s;
            } else {
                vlSelf->__PVT__md_rq = (QData)((IData)(vlSelf->__PVT__s_mag));
                vlSelf->__PVT__md_d = vlSelf->__PVT__t_mag;
                vlSelf->__PVT__md_neg_q = ((vlSelf->__PVT__s 
                                            ^ vlSelf->__PVT__t) 
                                           >> 0x1fU);
                vlSelf->__PVT__md_neg_r = (vlSelf->__PVT__s 
                                           >> 0x1fU);
                if ((0U == vlSelf->__PVT__t)) {
                    __Vdly__md_skip = 1U;
                    vlSelf->__PVT__md_fix_lo = ((vlSelf->__PVT__s 
                                                 >> 0x1fU)
                                                 ? 1U
                                                 : 0xffffffffU);
                    vlSelf->__PVT__md_fix_hi = vlSelf->__PVT__s;
                } else if (((0x80000000U == vlSelf->__PVT__s) 
                            & (0xffffffffU == vlSelf->__PVT__t))) {
                    __Vdly__md_skip = 1U;
                    vlSelf->__PVT__md_fix_lo = 0x80000000U;
                    vlSelf->__PVT__md_fix_hi = 0U;
                } else {
                    __Vdly__md_skip = 0U;
                }
            }
        } else if ((((IData)(vlSelf->__PVT__md_run) 
                     & (~ (IData)(vlSelf->__PVT__md_skip))) 
                    & (0U != (IData)(vlSelf->__PVT__md_count)))) {
            __Vdly__md_count = (0x3fU & ((IData)(vlSelf->__PVT__md_count) 
                                         - (IData)(1U)));
            vlSelf->__PVT__md_rq = ((1U & (IData)((vlSelf->__PVT__md_diff 
                                                   >> 0x20U)))
                                     ? vlSelf->__PVT__md_shifted
                                     : (((QData)((IData)(vlSelf->__PVT__md_diff)) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          (1U 
                                                           | ((IData)(
                                                                      (vlSelf->__PVT__md_shifted 
                                                                       >> 1U)) 
                                                              << 1U))))));
        }
        if (vlSelf->__PVT__adv_ex) {
            __Vdly__md_run = 0U;
            __Vdly__md_skip = 0U;
            __Vdly__md_count = 0U;
        }
        if (vlSelf->__PVT__adv_ex) {
            vlSelf->__PVT__ex_v = ((((IData)(vlSelf->__PVT__adv_id) 
                                     & (IData)(vlSelf->__PVT__id_v)) 
                                    & (~ (IData)(vlSelf->__PVT__exc_flush))) 
                                   & (~ (IData)(vlSelf->__PVT__id_take_irq)));
            vlSelf->__PVT__ex_pc = vlSelf->__PVT__id_pc;
            vlSelf->__PVT__ex_insn = vlSelf->__PVT__id_insn;
            vlSelf->__PVT__ex_next_pc = vlSelf->__PVT__id_next_pc;
            vlSelf->__PVT__ex_rs_raw = vlSelf->__PVT__id_s;
            vlSelf->__PVT__ex_rt_raw = vlSelf->__PVT__id_t;
            vlSelf->__PVT__ex_ds = vlSelf->__PVT__id_ds;
            vlSelf->__PVT__ex_exc_bad = vlSelf->__PVT__id_exc_bad;
            vlSelf->__PVT__ex_exc_bad_v = vlSelf->__PVT__id_exc_bad_v;
            if (vlSelf->__PVT__id_exc_v) {
                vlSelf->__PVT__ex_exc_v = 1U;
                vlSelf->__PVT__ex_exc_code = vlSelf->__PVT__id_exc_code;
                vlSelf->__PVT__ex_exc_ret = 0U;
            } else if (vlSelf->__PVT__id_take_irq) {
                vlSelf->__PVT__ex_v = (((IData)(vlSelf->__PVT__adv_id) 
                                        & (IData)(vlSelf->__PVT__id_v)) 
                                       & (~ (IData)(vlSelf->__PVT__exc_flush)));
                vlSelf->__PVT__ex_exc_v = 1U;
                vlSelf->__PVT__ex_exc_code = 0U;
                vlSelf->__PVT__ex_exc_bad_v = 0U;
                vlSelf->__PVT__ex_exc_ret = 0U;
            } else if (((IData)(vlSelf->__PVT__id_v) 
                        & ([&]() {
                            __Vfunc_illegal__97__i 
                                = vlSelf->__PVT__id_insn;
                            __Vfunc_illegal__97__Vfuncout 
                                = ((__Vfunc_illegal__97__i 
                                    >> 0x1fU) ? ((1U 
                                                  & (__Vfunc_illegal__97__i 
                                                     >> 0x1eU)) 
                                                 || ((0x20000000U 
                                                      & __Vfunc_illegal__97__i)
                                                      ? 
                                                     ((1U 
                                                       & (__Vfunc_illegal__97__i 
                                                          >> 0x1cU)) 
                                                      && (1U 
                                                          & (~ 
                                                             (__Vfunc_illegal__97__i 
                                                              >> 0x1bU))))
                                                      : 
                                                     ((1U 
                                                       & (__Vfunc_illegal__97__i 
                                                          >> 0x1cU)) 
                                                      && ((1U 
                                                           & (__Vfunc_illegal__97__i 
                                                              >> 0x1bU)) 
                                                          && (1U 
                                                              & (__Vfunc_illegal__97__i 
                                                                 >> 0x1aU))))))
                                    : ((0x40000000U 
                                        & __Vfunc_illegal__97__i)
                                        ? ((1U & (__Vfunc_illegal__97__i 
                                                  >> 0x1dU)) 
                                           || ((1U 
                                                & (__Vfunc_illegal__97__i 
                                                   >> 0x1cU)) 
                                               || ((1U 
                                                    & (__Vfunc_illegal__97__i 
                                                       >> 0x1bU)) 
                                                   || ((1U 
                                                        & (__Vfunc_illegal__97__i 
                                                           >> 0x1aU)) 
                                                       || (1U 
                                                           & (~ 
                                                              (((0U 
                                                                 == 
                                                                 (0x1fU 
                                                                  & (__Vfunc_illegal__97__i 
                                                                     >> 0x15U))) 
                                                                | (4U 
                                                                   == 
                                                                   (0x1fU 
                                                                    & (__Vfunc_illegal__97__i 
                                                                       >> 0x15U)))) 
                                                               | (IData)(
                                                                         (0x2000010U 
                                                                          == 
                                                                          (0x3e0003fU 
                                                                           & __Vfunc_illegal__97__i))))))))))
                                        : ((1U & (~ 
                                                  (__Vfunc_illegal__97__i 
                                                   >> 0x1dU))) 
                                           && ((1U 
                                                & (~ 
                                                   (__Vfunc_illegal__97__i 
                                                    >> 0x1cU))) 
                                               && ((1U 
                                                    & (~ 
                                                       (__Vfunc_illegal__97__i 
                                                        >> 0x1bU))) 
                                                   && (1U 
                                                       & ((0x4000000U 
                                                           & __Vfunc_illegal__97__i)
                                                           ? 
                                                          (~ 
                                                           ((((0U 
                                                               == 
                                                               (0x1fU 
                                                                & (__Vfunc_illegal__97__i 
                                                                   >> 0x10U))) 
                                                              | (1U 
                                                                 == 
                                                                 (0x1fU 
                                                                  & (__Vfunc_illegal__97__i 
                                                                     >> 0x10U)))) 
                                                             | (0x10U 
                                                                == 
                                                                (0x1fU 
                                                                 & (__Vfunc_illegal__97__i 
                                                                    >> 0x10U)))) 
                                                            | (0x11U 
                                                               == 
                                                               (0x1fU 
                                                                & (__Vfunc_illegal__97__i 
                                                                   >> 0x10U)))))
                                                           : 
                                                          ((0x20U 
                                                            & __Vfunc_illegal__97__i)
                                                            ? 
                                                           ((1U 
                                                             & (__Vfunc_illegal__97__i 
                                                                >> 4U)) 
                                                            || ((1U 
                                                                 & (__Vfunc_illegal__97__i 
                                                                    >> 3U)) 
                                                                && ((1U 
                                                                     & (__Vfunc_illegal__97__i 
                                                                        >> 2U)) 
                                                                    || (1U 
                                                                        & (~ 
                                                                           (__Vfunc_illegal__97__i 
                                                                            >> 1U))))))
                                                            : 
                                                           ((0x10U 
                                                             & __Vfunc_illegal__97__i)
                                                             ? 
                                                            (__Vfunc_illegal__97__i 
                                                             >> 2U)
                                                             : 
                                                            ((8U 
                                                              & __Vfunc_illegal__97__i)
                                                              ? 
                                                             (__Vfunc_illegal__97__i 
                                                              >> 1U)
                                                              : 
                                                             ((1U 
                                                               & (~ 
                                                                  (__Vfunc_illegal__97__i 
                                                                   >> 1U))) 
                                                              && (1U 
                                                                  & __Vfunc_illegal__97__i))))))))))));
                        }(), (IData)(__Vfunc_illegal__97__Vfuncout)))) {
                vlSelf->__PVT__ex_exc_v = 1U;
                vlSelf->__PVT__ex_exc_code = 0xaU;
                vlSelf->__PVT__ex_exc_bad_v = 0U;
                vlSelf->__PVT__ex_exc_ret = 1U;
            } else {
                vlSelf->__PVT__ex_exc_v = 0U;
                vlSelf->__PVT__ex_exc_ret = 1U;
            }
            if ((1U & (~ (IData)(vlSelf->__PVT__adv_id)))) {
                vlSelf->__PVT__ex_v = 0U;
            }
        }
        if (vlSelf->__PVT__adv_id) {
            if (vlSelf->__PVT__fetch_ok) {
                vlSelf->__PVT__id_pc = vlSelf->__PVT__fpc;
                vlSelf->__PVT__id_insn = ((IData)(vlSymsp->TOP__tb_board__cpu.__PVT__cache__DOT__i_hit)
                                           ? vlSymsp->TOP__tb_board__cpu.__PVT__cache__DOT__iram_q
                                           : vlSymsp->TOP__tb_board.__PVT__ird);
                vlSelf->__PVT__id_ds = (((IData)(vlSelf->__PVT__id_v) 
                                         & ([&]() {
                                __Vfunc_is_branch__98__i 
                                    = vlSelf->__PVT__i_id;
                                __Vfunc_is_branch__98__Vfuncout 
                                    = ((1U & (~ (__Vfunc_is_branch__98__i 
                                                 >> 0x1fU))) 
                                       && ((1U & (~ 
                                                  (__Vfunc_is_branch__98__i 
                                                   >> 0x1eU))) 
                                           && ((1U 
                                                & (~ 
                                                   (__Vfunc_is_branch__98__i 
                                                    >> 0x1dU))) 
                                               && ((1U 
                                                    & (__Vfunc_is_branch__98__i 
                                                       >> 0x1cU)) 
                                                   || ((1U 
                                                        & (__Vfunc_is_branch__98__i 
                                                           >> 0x1bU)) 
                                                       || ((1U 
                                                            & (__Vfunc_is_branch__98__i 
                                                               >> 0x1aU)) 
                                                           || ((8U 
                                                                == 
                                                                (0x3fU 
                                                                 & __Vfunc_is_branch__98__i)) 
                                                               | (9U 
                                                                  == 
                                                                  (0x3fU 
                                                                   & __Vfunc_is_branch__98__i)))))))));
                            }(), (IData)(__Vfunc_is_branch__98__Vfuncout))) 
                                        & (IData)(vlSelf->__PVT__id_taken));
                vlSelf->__PVT__id_exc_v = (((IData)(vlSymsp->TOP__tb_board__cpu.cache__DOT____VdfgTmp_h6d079f16__0) 
                                            & (IData)(vlSymsp->TOP__tb_board.__PVT__ierr)) 
                                           | (IData)(vlSymsp->TOP__tb_board__cpu.__PVT__cache__DOT__i_fill_fail));
                vlSelf->__PVT__id_exc_code = 6U;
                vlSelf->__PVT__id_exc_bad = vlSelf->__PVT__fpc;
                vlSelf->__PVT__id_exc_bad_v = (((IData)(vlSymsp->TOP__tb_board__cpu.cache__DOT____VdfgTmp_h6d079f16__0) 
                                                & (IData)(vlSymsp->TOP__tb_board.__PVT__ierr)) 
                                               | (IData)(vlSymsp->TOP__tb_board__cpu.__PVT__cache__DOT__i_fill_fail));
            }
            __Vdly__id_v = ((IData)(vlSelf->__PVT__fetch_ok) 
                            & (~ (IData)(vlSelf->__PVT__exc_flush)));
        }
        if ((((IData)(vlSelf->__PVT__adv_id) & (IData)(vlSelf->__PVT__id_v)) 
             & (~ (IData)(vlSelf->__PVT__exc_flush)))) {
            vlSelf->__PVT__a_pc = vlSelf->__PVT__a_next_pc;
            vlSelf->__PVT__a_next_pc = vlSelf->__PVT__id_next_pc;
        }
        if (((IData)(vlSelf->__PVT__fetch_ok) & (~ (IData)(vlSelf->__PVT__exc_flush)))) {
            if (vlSelf->__PVT__redir_v) {
                vlSelf->__PVT__redir_v = 0U;
            }
            vlSelf->__PVT__fpc = vlSelf->__PVT__fpc_nxt;
        } else if (((IData)(vlSelf->__PVT__id_redirect) 
                    & (~ (IData)(vlSelf->__PVT__exc_flush)))) {
            vlSelf->__PVT__redir_v = 1U;
            vlSelf->__PVT__redir_pc = vlSelf->__PVT__id_tgt;
        }
        if (vlSelf->__PVT__exc_flush) {
            vlSelf->exc_count = (1ULL + vlSelf->exc_count);
            __Vdlyvval__cp0__v12 = ((IData)(vlSelf->__PVT__me_ds)
                                     ? (vlSelf->__PVT__me_pc 
                                        - (IData)(4U))
                                     : vlSelf->__PVT__me_pc);
            __Vdlyvset__cp0__v12 = 1U;
            vlSelf->__PVT__redir_v = 0U;
            __Vdlyvval__cp0__v13 = (((0x7fffff83U & vlSelf->__PVT__cause_live) 
                                     | VL_SHIFTL_III(32,32,32, (IData)(vlSelf->__PVT__me_exc_out_code), 2U)) 
                                    | ((IData)(vlSelf->__PVT__me_ds)
                                        ? 0x80000000U
                                        : 0U));
            __Vdlyvset__cp0__v13 = 1U;
            vlSelf->__PVT__fpc = vlSelf->__PVT__exc_vector;
            vlSelf->__PVT__a_pc = vlSelf->__PVT__exc_vector;
            vlSelf->__PVT__a_next_pc = ((IData)(4U) 
                                        + vlSelf->__PVT__exc_vector);
            __Vdly__id_v = 0U;
            vlSelf->__PVT__ex_v = 0U;
            vlSelf->__PVT__me_v = 0U;
            vlSelf->__PVT__id_ds = 0U;
            vlSelf->__PVT__id_exc_v = 0U;
            vlSelf->__PVT__ex_exc_v = 0U;
            vlSelf->__PVT__me_exc_v = 0U;
            __Vdly__me_phase = 0U;
            if (vlSelf->__PVT__me_exc_out_badv) {
                __Vdlyvval__cp0__v14 = vlSelf->__PVT__me_exc_out_bad;
                __Vdlyvset__cp0__v14 = 1U;
            }
            __Vdlyvval__cp0__v15 = ((0xffffffc0U & 
                                     vlSelf->__PVT__cp0
                                     [0xcU]) | (0x3cU 
                                                & VL_SHIFTL_III(32,32,32, 
                                                                vlSelf->__PVT__cp0
                                                                [0xcU], 2U)));
            __Vdlyvset__cp0__v15 = 1U;
        }
    } else {
        __Vdlyvset__cp0__v16 = 1U;
        vlSelf->__PVT__redir_v = 0U;
        vlSelf->insn_count = 0ULL;
        __Vdly__cycle_count = 0ULL;
        vlSelf->cache_ops = 0ULL;
        vlSelf->exc_count = 0ULL;
        __Vdlyvset__regs__v1 = 1U;
        __Vdly__hi = 0U;
        __Vdly__lo = 0U;
        vlSelf->__PVT__fpc = 0xbfc00000U;
        vlSelf->__PVT__a_pc = 0xbfc00000U;
        vlSelf->__PVT__a_next_pc = 0xbfc00004U;
        __Vdly__id_v = 0U;
        vlSelf->__PVT__ex_v = 0U;
        vlSelf->__PVT__me_v = 0U;
        vlSelf->__PVT__wb_v = 0U;
        vlSelf->__PVT__rt_v = 0U;
        vlSelf->__PVT__id_ds = 0U;
        vlSelf->__PVT__id_exc_v = 0U;
        vlSelf->__PVT__ex_exc_v = 0U;
        vlSelf->__PVT__me_exc_v = 0U;
        vlSelf->__PVT__ex_exc_ret = 1U;
        vlSelf->__PVT__me_exc_ret = 1U;
        __Vdly__me_phase = 0U;
        __Vdly__md_count = 0U;
        __Vdly__md_run = 0U;
        __Vdly__md_skip = 0U;
        __Vdlyvset__regs__v2 = 1U;
    }
    vlSelf->__PVT__me_pc = __Vdly__me_pc;
    vlSelf->__PVT__me_ds = __Vdly__me_ds;
    vlSelf->cycle_count = __Vdly__cycle_count;
    vlSelf->hi = __Vdly__hi;
    vlSelf->lo = __Vdly__lo;
    vlSelf->__PVT__md_run = __Vdly__md_run;
    vlSelf->__PVT__md_count = __Vdly__md_count;
    vlSelf->__PVT__md_skip = __Vdly__md_skip;
    if (__Vdlyvset__regs__v0) {
        vlSelf->regs[__Vdlyvdim0__regs__v0] = __Vdlyvval__regs__v0;
    }
    if (__Vdlyvset__regs__v1) {
        vlSelf->regs[0U] = 0U;
    }
    if (__Vdlyvset__cp0__v0) {
        vlSelf->__PVT__cp0[0xcU] = __Vdlyvval__cp0__v0;
    }
    if (__Vdlyvset__cp0__v1) {
        vlSelf->__PVT__cp0[__Vdlyvdim0__cp0__v1] = __Vdlyvval__cp0__v1;
    }
    if (__Vdlyvset__cp0__v2) {
        vlSelf->__PVT__cp0[__Vdlyvdim0__cp0__v2] = __Vdlyvval__cp0__v2;
    }
    if (__Vdlyvset__cp0__v3) {
        vlSelf->__PVT__cp0[__Vdlyvdim0__cp0__v3] = __Vdlyvval__cp0__v3;
    }
    if (__Vdlyvset__cp0__v4) {
        vlSelf->__PVT__cp0[__Vdlyvdim0__cp0__v4] = __Vdlyvval__cp0__v4;
    }
    if (__Vdlyvset__cp0__v5) {
        vlSelf->__PVT__cp0[__Vdlyvdim0__cp0__v5] = __Vdlyvval__cp0__v5;
    }
    if (__Vdlyvset__cp0__v6) {
        vlSelf->__PVT__cp0[0xdU] = __Vdlyvval__cp0__v6;
    }
    if (__Vdlyvset__cp0__v7) {
        vlSelf->__PVT__cp0[0xcU] = __Vdlyvval__cp0__v7;
    }
    if (__Vdlyvset__cp0__v8) {
        vlSelf->__PVT__cp0[__Vdlyvdim0__cp0__v8] = __Vdlyvval__cp0__v8;
    }
    if (__Vdlyvset__cp0__v9) {
        vlSelf->__PVT__cp0[__Vdlyvdim0__cp0__v9] = __Vdlyvval__cp0__v9;
    }
    if (__Vdlyvset__cp0__v10) {
        vlSelf->__PVT__cp0[__Vdlyvdim0__cp0__v10] = __Vdlyvval__cp0__v10;
    }
    if (__Vdlyvset__cp0__v11) {
        vlSelf->__PVT__cp0[__Vdlyvdim0__cp0__v11] = __Vdlyvval__cp0__v11;
    }
    if (__Vdlyvset__cp0__v12) {
        vlSelf->__PVT__cp0[0xeU] = __Vdlyvval__cp0__v12;
    }
    if (__Vdlyvset__cp0__v13) {
        vlSelf->__PVT__cp0[0xdU] = __Vdlyvval__cp0__v13;
    }
    if (__Vdlyvset__cp0__v14) {
        vlSelf->__PVT__cp0[8U] = __Vdlyvval__cp0__v14;
    }
    if (__Vdlyvset__cp0__v15) {
        vlSelf->__PVT__cp0[0xcU] = __Vdlyvval__cp0__v15;
    }
    if (__Vdlyvset__cp0__v16) {
        vlSelf->__PVT__cp0[0U] = 0U;
    }
    if (__Vdlyvset__regs__v1) {
        vlSelf->__PVT__cp0[1U] = 0U;
    }
    if (__Vdlyvset__regs__v2) {
        vlSelf->regs[1U] = 0U;
        vlSelf->regs[2U] = 0U;
        vlSelf->regs[3U] = 0U;
        vlSelf->regs[4U] = 0U;
        vlSelf->regs[5U] = 0U;
        vlSelf->regs[6U] = 0U;
        vlSelf->regs[7U] = 0U;
        vlSelf->regs[8U] = 0U;
        vlSelf->regs[9U] = 0U;
        vlSelf->regs[0xaU] = 0U;
        vlSelf->regs[0xbU] = 0U;
        vlSelf->regs[0xcU] = 0U;
        vlSelf->regs[0xdU] = 0U;
        vlSelf->regs[0xeU] = 0U;
        vlSelf->regs[0xfU] = 0U;
        vlSelf->regs[0x10U] = 0U;
        vlSelf->regs[0x11U] = 0U;
        vlSelf->regs[0x12U] = 0U;
        vlSelf->regs[0x13U] = 0U;
        vlSelf->regs[0x14U] = 0U;
        vlSelf->regs[0x15U] = 0U;
        vlSelf->regs[0x16U] = 0U;
        vlSelf->regs[0x17U] = 0U;
        vlSelf->regs[0x18U] = 0U;
        vlSelf->regs[0x19U] = 0U;
        vlSelf->regs[0x1aU] = 0U;
        vlSelf->regs[0x1bU] = 0U;
        vlSelf->regs[0x1cU] = 0U;
        vlSelf->regs[0x1dU] = 0U;
        vlSelf->regs[0x1eU] = 0U;
        vlSelf->regs[0x1fU] = 0U;
        vlSelf->__PVT__cp0[2U] = 0U;
        vlSelf->__PVT__cp0[3U] = 0U;
        vlSelf->__PVT__cp0[4U] = 0U;
        vlSelf->__PVT__cp0[5U] = 0U;
        vlSelf->__PVT__cp0[6U] = 0U;
        vlSelf->__PVT__cp0[7U] = 0U;
        vlSelf->__PVT__cp0[8U] = 0U;
        vlSelf->__PVT__cp0[9U] = 0U;
        vlSelf->__PVT__cp0[0xaU] = 0U;
        vlSelf->__PVT__cp0[0xbU] = 0U;
        vlSelf->__PVT__cp0[0xcU] = 0U;
        vlSelf->__PVT__cp0[0xdU] = 0U;
        vlSelf->__PVT__cp0[0xeU] = 0U;
        vlSelf->__PVT__cp0[0xfU] = 0U;
        vlSelf->__PVT__cp0[0x10U] = 0U;
        vlSelf->__PVT__cp0[0x11U] = 0U;
        vlSelf->__PVT__cp0[0x12U] = 0U;
        vlSelf->__PVT__cp0[0x13U] = 0U;
        vlSelf->__PVT__cp0[0x14U] = 0U;
        vlSelf->__PVT__cp0[0x15U] = 0U;
        vlSelf->__PVT__cp0[0x16U] = 0U;
        vlSelf->__PVT__cp0[0x17U] = 0U;
        vlSelf->__PVT__cp0[0x18U] = 0U;
        vlSelf->__PVT__cp0[0x19U] = 0U;
        vlSelf->__PVT__cp0[0x1aU] = 0U;
        vlSelf->__PVT__cp0[0x1bU] = 0U;
        vlSelf->__PVT__cp0[0x1cU] = 0U;
        vlSelf->__PVT__cp0[0x1dU] = 0U;
        vlSelf->__PVT__cp0[0x1eU] = 0U;
        vlSelf->__PVT__cp0[0x1fU] = 0U;
        vlSelf->__PVT__cp0[0xcU] = 0x400000U;
        vlSelf->__PVT__cp0[0xfU] = 0x2200U;
        vlSelf->__PVT__cp0[1U] = 0x1fU;
    }
    vlSelf->__PVT__id_v = __Vdly__id_v;
    vlSelf->__PVT__me_phase = __Vdly__me_phase;
    vlSelf->__PVT__md_shifted = VL_SHIFTL_QQI(64,64,32, vlSelf->__PVT__md_rq, 1U);
    vlSelf->__PVT__div_r = ((IData)(vlSelf->__PVT__md_neg_r)
                             ? ((IData)(1U) + (~ (IData)(
                                                         (vlSelf->__PVT__md_rq 
                                                          >> 0x20U))))
                             : (IData)((vlSelf->__PVT__md_rq 
                                        >> 0x20U)));
    vlSelf->__PVT__div_q = ((IData)(vlSelf->__PVT__md_neg_q)
                             ? ((IData)(1U) + (~ (IData)(vlSelf->__PVT__md_rq)))
                             : (IData)(vlSelf->__PVT__md_rq));
    vlSelf->__PVT__md_diff = (0x1ffffffffULL & ((QData)((IData)(
                                                                (VL_SHIFTL_QQI(64,64,32, vlSelf->__PVT__md_rq, 1U) 
                                                                 >> 0x20U))) 
                                                - (QData)((IData)(vlSelf->__PVT__md_d))));
    vlSelf->__PVT__ex_exc_out_ret = (1U & ((~ (IData)(vlSelf->__PVT__ex_exc_v)) 
                                           | (IData)(vlSelf->__PVT__ex_exc_ret)));
    vlSelf->__PVT__exc_vector = ((0x400000U & vlSelf->__PVT__cp0
                                  [0xcU]) ? 0xbfc00180U
                                  : 0x80000080U);
    vlSelf->__PVT__cause_live = ((0xffff03ffU & vlSelf->__PVT__cp0
                                  [0xdU]) | VL_SHIFTL_III(32,32,32, (IData)(vlSymsp->TOP.irq_in), 0xaU));
    __Vfunc_phys__0__va = vlSelf->__PVT__fpc;
    __Vfunc_phys__0__Vfuncout = (((0x80000000U <= __Vfunc_phys__0__va) 
                                  & (0xc0000000U > __Vfunc_phys__0__va))
                                  ? (0x1fffffffU & __Vfunc_phys__0__va)
                                  : __Vfunc_phys__0__va);
    vlSelf->__PVT__ibus_addr = __Vfunc_phys__0__Vfuncout;
    __Vfunc_cacheable__1__va = vlSelf->__PVT__fpc;
    __Vfunc_cacheable__1__Vfuncout = (0xa0000000U > __Vfunc_cacheable__1__va);
    vlSelf->__PVT__ibus_cached = __Vfunc_cacheable__1__Vfuncout;
    vlSelf->__PVT__i_id = vlSelf->__PVT__id_insn;
    vlSelf->__VdfgExtracted_h84f92045__0 = ((8U == 
                                             (0x3fU 
                                              & vlSelf->__PVT__id_insn)) 
                                            | (9U == 
                                               (0x3fU 
                                                & vlSelf->__PVT__id_insn)));
    __PVT__id_needs_rs = ((IData)(vlSelf->__PVT__id_v) 
                          & ([&]() {
                vlSelf->__Vfunc_reads_rs__31__i = vlSelf->__PVT__id_insn;
                vlSelf->__Vfunc_reads_rs__31__Vfuncout 
                    = ((vlSelf->__Vfunc_reads_rs__31__i 
                        >> 0x1fU) || ((0x40000000U 
                                       & vlSelf->__Vfunc_reads_rs__31__i)
                                       ? ((1U & (vlSelf->__Vfunc_reads_rs__31__i 
                                                 >> 0x1dU)) 
                                          || ((1U & 
                                               (vlSelf->__Vfunc_reads_rs__31__i 
                                                >> 0x1cU)) 
                                              || ((1U 
                                                   & (vlSelf->__Vfunc_reads_rs__31__i 
                                                      >> 0x1bU)) 
                                                  || (1U 
                                                      & (vlSelf->__Vfunc_reads_rs__31__i 
                                                         >> 0x1aU)))))
                                       : ((0x20000000U 
                                           & vlSelf->__Vfunc_reads_rs__31__i)
                                           ? ((1U & 
                                               (~ (vlSelf->__Vfunc_reads_rs__31__i 
                                                   >> 0x1cU))) 
                                              || ((1U 
                                                   & (~ 
                                                      (vlSelf->__Vfunc_reads_rs__31__i 
                                                       >> 0x1bU))) 
                                                  || (1U 
                                                      & (~ 
                                                         (vlSelf->__Vfunc_reads_rs__31__i 
                                                          >> 0x1aU)))))
                                           : ((1U & 
                                               (vlSelf->__Vfunc_reads_rs__31__i 
                                                >> 0x1cU)) 
                                              || ((1U 
                                                   & (~ 
                                                      (vlSelf->__Vfunc_reads_rs__31__i 
                                                       >> 0x1bU))) 
                                                  && ((1U 
                                                       & (vlSelf->__Vfunc_reads_rs__31__i 
                                                          >> 0x1aU)) 
                                                      || (1U 
                                                          & (~ 
                                                             (((((0U 
                                                                  == 
                                                                  (0x3fU 
                                                                   & vlSelf->__Vfunc_reads_rs__31__i)) 
                                                                 | (2U 
                                                                    == 
                                                                    (0x3fU 
                                                                     & vlSelf->__Vfunc_reads_rs__31__i))) 
                                                                | (3U 
                                                                   == 
                                                                   (0x3fU 
                                                                    & vlSelf->__Vfunc_reads_rs__31__i))) 
                                                               | (0x10U 
                                                                  == 
                                                                  (0x3fU 
                                                                   & vlSelf->__Vfunc_reads_rs__31__i))) 
                                                              | (0x12U 
                                                                 == 
                                                                 (0x3fU 
                                                                  & vlSelf->__Vfunc_reads_rs__31__i)))))))))));
            }(), (IData)(vlSelf->__Vfunc_reads_rs__31__Vfuncout)));
    __PVT__id_needs_rt = ((IData)(vlSelf->__PVT__id_v) 
                          & ([&]() {
                vlSelf->__Vfunc_reads_rt__32__i = vlSelf->__PVT__id_insn;
                if ((vlSelf->__Vfunc_reads_rt__32__i 
                     >> 0x1fU)) {
                    vlSelf->__Vfunc_is_store__33__i 
                        = vlSelf->__Vfunc_reads_rt__32__i;
                    vlSelf->__Vfunc_is_store__33__Vfuncout 
                        = (((((0x28U == (vlSelf->__Vfunc_is_store__33__i 
                                         >> 0x1aU)) 
                              | (0x29U == (vlSelf->__Vfunc_is_store__33__i 
                                           >> 0x1aU))) 
                             | (0x2bU == (vlSelf->__Vfunc_is_store__33__i 
                                          >> 0x1aU))) 
                            | (0x2aU == (vlSelf->__Vfunc_is_store__33__i 
                                         >> 0x1aU))) 
                           | (0x2eU == (vlSelf->__Vfunc_is_store__33__i 
                                        >> 0x1aU)));
                    vlSelf->__Vfunc_reads_rt__32__Vfuncout 
                        = vlSelf->__Vfunc_is_store__33__Vfuncout;
                } else if ((0x40000000U & vlSelf->__Vfunc_reads_rt__32__i)) {
                    if ((0x20000000U & vlSelf->__Vfunc_reads_rt__32__i)) {
                        vlSelf->__Vfunc_is_store__34__i 
                            = vlSelf->__Vfunc_reads_rt__32__i;
                        vlSelf->__Vfunc_is_store__34__Vfuncout 
                            = (((((0x28U == (vlSelf->__Vfunc_is_store__34__i 
                                             >> 0x1aU)) 
                                  | (0x29U == (vlSelf->__Vfunc_is_store__34__i 
                                               >> 0x1aU))) 
                                 | (0x2bU == (vlSelf->__Vfunc_is_store__34__i 
                                              >> 0x1aU))) 
                                | (0x2aU == (vlSelf->__Vfunc_is_store__34__i 
                                             >> 0x1aU))) 
                               | (0x2eU == (vlSelf->__Vfunc_is_store__34__i 
                                            >> 0x1aU)));
                        vlSelf->__Vfunc_reads_rt__32__Vfuncout 
                            = vlSelf->__Vfunc_is_store__34__Vfuncout;
                    } else if ((0x10000000U & vlSelf->__Vfunc_reads_rt__32__i)) {
                        vlSelf->__Vfunc_is_store__35__i 
                            = vlSelf->__Vfunc_reads_rt__32__i;
                        vlSelf->__Vfunc_is_store__35__Vfuncout 
                            = (((((0x28U == (vlSelf->__Vfunc_is_store__35__i 
                                             >> 0x1aU)) 
                                  | (0x29U == (vlSelf->__Vfunc_is_store__35__i 
                                               >> 0x1aU))) 
                                 | (0x2bU == (vlSelf->__Vfunc_is_store__35__i 
                                              >> 0x1aU))) 
                                | (0x2aU == (vlSelf->__Vfunc_is_store__35__i 
                                             >> 0x1aU))) 
                               | (0x2eU == (vlSelf->__Vfunc_is_store__35__i 
                                            >> 0x1aU)));
                        vlSelf->__Vfunc_reads_rt__32__Vfuncout 
                            = vlSelf->__Vfunc_is_store__35__Vfuncout;
                    } else if ((0x8000000U & vlSelf->__Vfunc_reads_rt__32__i)) {
                        vlSelf->__Vfunc_is_store__36__i 
                            = vlSelf->__Vfunc_reads_rt__32__i;
                        vlSelf->__Vfunc_is_store__36__Vfuncout 
                            = (((((0x28U == (vlSelf->__Vfunc_is_store__36__i 
                                             >> 0x1aU)) 
                                  | (0x29U == (vlSelf->__Vfunc_is_store__36__i 
                                               >> 0x1aU))) 
                                 | (0x2bU == (vlSelf->__Vfunc_is_store__36__i 
                                              >> 0x1aU))) 
                                | (0x2aU == (vlSelf->__Vfunc_is_store__36__i 
                                             >> 0x1aU))) 
                               | (0x2eU == (vlSelf->__Vfunc_is_store__36__i 
                                            >> 0x1aU)));
                        vlSelf->__Vfunc_reads_rt__32__Vfuncout 
                            = vlSelf->__Vfunc_is_store__36__Vfuncout;
                    } else if ((0x4000000U & vlSelf->__Vfunc_reads_rt__32__i)) {
                        vlSelf->__Vfunc_is_store__37__i 
                            = vlSelf->__Vfunc_reads_rt__32__i;
                        vlSelf->__Vfunc_is_store__37__Vfuncout 
                            = (((((0x28U == (vlSelf->__Vfunc_is_store__37__i 
                                             >> 0x1aU)) 
                                  | (0x29U == (vlSelf->__Vfunc_is_store__37__i 
                                               >> 0x1aU))) 
                                 | (0x2bU == (vlSelf->__Vfunc_is_store__37__i 
                                              >> 0x1aU))) 
                                | (0x2aU == (vlSelf->__Vfunc_is_store__37__i 
                                             >> 0x1aU))) 
                               | (0x2eU == (vlSelf->__Vfunc_is_store__37__i 
                                            >> 0x1aU)));
                        vlSelf->__Vfunc_reads_rt__32__Vfuncout 
                            = vlSelf->__Vfunc_is_store__37__Vfuncout;
                    } else {
                        vlSelf->__Vfunc_reads_rt__32__Vfuncout 
                            = (4U == (0x1fU & (vlSelf->__Vfunc_reads_rt__32__i 
                                               >> 0x15U)));
                    }
                } else if ((0x20000000U & vlSelf->__Vfunc_reads_rt__32__i)) {
                    vlSelf->__Vfunc_is_store__38__i 
                        = vlSelf->__Vfunc_reads_rt__32__i;
                    vlSelf->__Vfunc_is_store__38__Vfuncout 
                        = (((((0x28U == (vlSelf->__Vfunc_is_store__38__i 
                                         >> 0x1aU)) 
                              | (0x29U == (vlSelf->__Vfunc_is_store__38__i 
                                           >> 0x1aU))) 
                             | (0x2bU == (vlSelf->__Vfunc_is_store__38__i 
                                          >> 0x1aU))) 
                            | (0x2aU == (vlSelf->__Vfunc_is_store__38__i 
                                         >> 0x1aU))) 
                           | (0x2eU == (vlSelf->__Vfunc_is_store__38__i 
                                        >> 0x1aU)));
                    vlSelf->__Vfunc_reads_rt__32__Vfuncout 
                        = vlSelf->__Vfunc_is_store__38__Vfuncout;
                } else if ((0x10000000U & vlSelf->__Vfunc_reads_rt__32__i)) {
                    if ((0x8000000U & vlSelf->__Vfunc_reads_rt__32__i)) {
                        vlSelf->__Vfunc_is_store__39__i 
                            = vlSelf->__Vfunc_reads_rt__32__i;
                        vlSelf->__Vfunc_is_store__39__Vfuncout 
                            = (((((0x28U == (vlSelf->__Vfunc_is_store__39__i 
                                             >> 0x1aU)) 
                                  | (0x29U == (vlSelf->__Vfunc_is_store__39__i 
                                               >> 0x1aU))) 
                                 | (0x2bU == (vlSelf->__Vfunc_is_store__39__i 
                                              >> 0x1aU))) 
                                | (0x2aU == (vlSelf->__Vfunc_is_store__39__i 
                                             >> 0x1aU))) 
                               | (0x2eU == (vlSelf->__Vfunc_is_store__39__i 
                                            >> 0x1aU)));
                        vlSelf->__Vfunc_reads_rt__32__Vfuncout 
                            = vlSelf->__Vfunc_is_store__39__Vfuncout;
                    } else {
                        vlSelf->__Vfunc_reads_rt__32__Vfuncout = 1U;
                    }
                } else if ((0x8000000U & vlSelf->__Vfunc_reads_rt__32__i)) {
                    vlSelf->__Vfunc_is_store__40__i 
                        = vlSelf->__Vfunc_reads_rt__32__i;
                    vlSelf->__Vfunc_is_store__40__Vfuncout 
                        = (((((0x28U == (vlSelf->__Vfunc_is_store__40__i 
                                         >> 0x1aU)) 
                              | (0x29U == (vlSelf->__Vfunc_is_store__40__i 
                                           >> 0x1aU))) 
                             | (0x2bU == (vlSelf->__Vfunc_is_store__40__i 
                                          >> 0x1aU))) 
                            | (0x2aU == (vlSelf->__Vfunc_is_store__40__i 
                                         >> 0x1aU))) 
                           | (0x2eU == (vlSelf->__Vfunc_is_store__40__i 
                                        >> 0x1aU)));
                    vlSelf->__Vfunc_reads_rt__32__Vfuncout 
                        = vlSelf->__Vfunc_is_store__40__Vfuncout;
                } else if ((0x4000000U & vlSelf->__Vfunc_reads_rt__32__i)) {
                    vlSelf->__Vfunc_is_store__41__i 
                        = vlSelf->__Vfunc_reads_rt__32__i;
                    vlSelf->__Vfunc_is_store__41__Vfuncout 
                        = (((((0x28U == (vlSelf->__Vfunc_is_store__41__i 
                                         >> 0x1aU)) 
                              | (0x29U == (vlSelf->__Vfunc_is_store__41__i 
                                           >> 0x1aU))) 
                             | (0x2bU == (vlSelf->__Vfunc_is_store__41__i 
                                          >> 0x1aU))) 
                            | (0x2aU == (vlSelf->__Vfunc_is_store__41__i 
                                         >> 0x1aU))) 
                           | (0x2eU == (vlSelf->__Vfunc_is_store__41__i 
                                        >> 0x1aU)));
                    vlSelf->__Vfunc_reads_rt__32__Vfuncout 
                        = vlSelf->__Vfunc_is_store__41__Vfuncout;
                } else {
                    vlSelf->__Vfunc_reads_rt__32__Vfuncout 
                        = (1U & (~ ((((((8U == (0x3fU 
                                                & vlSelf->__Vfunc_reads_rt__32__i)) 
                                        | (9U == (0x3fU 
                                                  & vlSelf->__Vfunc_reads_rt__32__i))) 
                                       | (0x10U == 
                                          (0x3fU & vlSelf->__Vfunc_reads_rt__32__i))) 
                                      | (0x11U == (0x3fU 
                                                   & vlSelf->__Vfunc_reads_rt__32__i))) 
                                     | (0x12U == (0x3fU 
                                                  & vlSelf->__Vfunc_reads_rt__32__i))) 
                                    | (0x13U == (0x3fU 
                                                 & vlSelf->__Vfunc_reads_rt__32__i)))));
                }
            }(), (IData)(vlSelf->__Vfunc_reads_rt__32__Vfuncout)));
    vlSelf->__VdfgTmp_h42ed6c05__0 = ((IData)(vlSelf->__PVT__wb_v) 
                                      & ((IData)(vlSelf->__PVT__wb_we) 
                                         & (0U != (IData)(vlSelf->__PVT__wb_wa))));
    vlSelf->__PVT__i_ex = vlSelf->__PVT__ex_insn;
    vlSelf->__VdfgExtracted_h9d8030ea__0 = (([&]() {
                vlSelf->__Vfunc_is_store__99__i = vlSelf->__PVT__ex_insn;
                vlSelf->__Vfunc_is_store__99__Vfuncout 
                    = (((((0x28U == (vlSelf->__Vfunc_is_store__99__i 
                                     >> 0x1aU)) | (0x29U 
                                                   == 
                                                   (vlSelf->__Vfunc_is_store__99__i 
                                                    >> 0x1aU))) 
                         | (0x2bU == (vlSelf->__Vfunc_is_store__99__i 
                                      >> 0x1aU))) | 
                        (0x2aU == (vlSelf->__Vfunc_is_store__99__i 
                                   >> 0x1aU))) | (0x2eU 
                                                  == 
                                                  (vlSelf->__Vfunc_is_store__99__i 
                                                   >> 0x1aU)));
            }(), (IData)(vlSelf->__Vfunc_is_store__99__Vfuncout))
                                             ? 5U : 4U);
    __PVT__ex_writes = ((IData)(vlSelf->__PVT__ex_v) 
                        & ([&]() {
                vlSelf->__Vfunc_writes_gpr__5__i = vlSelf->__PVT__ex_insn;
                vlSelf->__Vfunc_writes_gpr__5__Vfuncout 
                    = (1U & ((vlSelf->__Vfunc_writes_gpr__5__i 
                              >> 0x1fU) ? ((0x40000000U 
                                            & vlSelf->__Vfunc_writes_gpr__5__i)
                                            ? (~ ([&]() {
                                        vlSelf->__Vfunc_is_store__6__i 
                                            = vlSelf->__Vfunc_writes_gpr__5__i;
                                        vlSelf->__Vfunc_is_store__6__Vfuncout 
                                            = (((((0x28U 
                                                   == 
                                                   (vlSelf->__Vfunc_is_store__6__i 
                                                    >> 0x1aU)) 
                                                  | (0x29U 
                                                     == 
                                                     (vlSelf->__Vfunc_is_store__6__i 
                                                      >> 0x1aU))) 
                                                 | (0x2bU 
                                                    == 
                                                    (vlSelf->__Vfunc_is_store__6__i 
                                                     >> 0x1aU))) 
                                                | (0x2aU 
                                                   == 
                                                   (vlSelf->__Vfunc_is_store__6__i 
                                                    >> 0x1aU))) 
                                               | (0x2eU 
                                                  == 
                                                  (vlSelf->__Vfunc_is_store__6__i 
                                                   >> 0x1aU)));
                                    }(), (IData)(vlSelf->__Vfunc_is_store__6__Vfuncout)))
                                            : ((0x20000000U 
                                                & vlSelf->__Vfunc_writes_gpr__5__i)
                                                ? (
                                                   (0x10000000U 
                                                    & vlSelf->__Vfunc_writes_gpr__5__i)
                                                    ? 
                                                   ((0x8000000U 
                                                     & vlSelf->__Vfunc_writes_gpr__5__i)
                                                     ? 
                                                    ((1U 
                                                      & (~ 
                                                         (vlSelf->__Vfunc_writes_gpr__5__i 
                                                          >> 0x1aU))) 
                                                     && (1U 
                                                         & (~ 
                                                            ([&]() {
                                                            vlSelf->__Vfunc_is_store__7__i 
                                                                = vlSelf->__Vfunc_writes_gpr__5__i;
                                                            vlSelf->__Vfunc_is_store__7__Vfuncout 
                                                                = 
                                                                (((((0x28U 
                                                                     == 
                                                                     (vlSelf->__Vfunc_is_store__7__i 
                                                                      >> 0x1aU)) 
                                                                    | (0x29U 
                                                                       == 
                                                                       (vlSelf->__Vfunc_is_store__7__i 
                                                                        >> 0x1aU))) 
                                                                   | (0x2bU 
                                                                      == 
                                                                      (vlSelf->__Vfunc_is_store__7__i 
                                                                       >> 0x1aU))) 
                                                                  | (0x2aU 
                                                                     == 
                                                                     (vlSelf->__Vfunc_is_store__7__i 
                                                                      >> 0x1aU))) 
                                                                 | (0x2eU 
                                                                    == 
                                                                    (vlSelf->__Vfunc_is_store__7__i 
                                                                     >> 0x1aU)));
                                                        }(), (IData)(vlSelf->__Vfunc_is_store__7__Vfuncout)))))
                                                     : 
                                                    (~ 
                                                     ([&]() {
                                                    vlSelf->__Vfunc_is_store__8__i 
                                                        = vlSelf->__Vfunc_writes_gpr__5__i;
                                                    vlSelf->__Vfunc_is_store__8__Vfuncout 
                                                        = 
                                                        (((((0x28U 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__8__i 
                                                              >> 0x1aU)) 
                                                            | (0x29U 
                                                               == 
                                                               (vlSelf->__Vfunc_is_store__8__i 
                                                                >> 0x1aU))) 
                                                           | (0x2bU 
                                                              == 
                                                              (vlSelf->__Vfunc_is_store__8__i 
                                                               >> 0x1aU))) 
                                                          | (0x2aU 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__8__i 
                                                              >> 0x1aU))) 
                                                         | (0x2eU 
                                                            == 
                                                            (vlSelf->__Vfunc_is_store__8__i 
                                                             >> 0x1aU)));
                                                }(), (IData)(vlSelf->__Vfunc_is_store__8__Vfuncout))))
                                                    : 
                                                   (~ 
                                                    ([&]() {
                                                vlSelf->__Vfunc_is_store__9__i 
                                                    = vlSelf->__Vfunc_writes_gpr__5__i;
                                                vlSelf->__Vfunc_is_store__9__Vfuncout 
                                                    = 
                                                    (((((0x28U 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__9__i 
                                                          >> 0x1aU)) 
                                                        | (0x29U 
                                                           == 
                                                           (vlSelf->__Vfunc_is_store__9__i 
                                                            >> 0x1aU))) 
                                                       | (0x2bU 
                                                          == 
                                                          (vlSelf->__Vfunc_is_store__9__i 
                                                           >> 0x1aU))) 
                                                      | (0x2aU 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__9__i 
                                                          >> 0x1aU))) 
                                                     | (0x2eU 
                                                        == 
                                                        (vlSelf->__Vfunc_is_store__9__i 
                                                         >> 0x1aU)));
                                            }(), (IData)(vlSelf->__Vfunc_is_store__9__Vfuncout))))
                                                : (~ 
                                                   ([&]() {
                                            vlSelf->__Vfunc_is_store__10__i 
                                                = vlSelf->__Vfunc_writes_gpr__5__i;
                                            vlSelf->__Vfunc_is_store__10__Vfuncout 
                                                = (
                                                   ((((0x28U 
                                                       == 
                                                       (vlSelf->__Vfunc_is_store__10__i 
                                                        >> 0x1aU)) 
                                                      | (0x29U 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__10__i 
                                                          >> 0x1aU))) 
                                                     | (0x2bU 
                                                        == 
                                                        (vlSelf->__Vfunc_is_store__10__i 
                                                         >> 0x1aU))) 
                                                    | (0x2aU 
                                                       == 
                                                       (vlSelf->__Vfunc_is_store__10__i 
                                                        >> 0x1aU))) 
                                                   | (0x2eU 
                                                      == 
                                                      (vlSelf->__Vfunc_is_store__10__i 
                                                       >> 0x1aU)));
                                        }(), (IData)(vlSelf->__Vfunc_is_store__10__Vfuncout)))))
                              : ((0x40000000U & vlSelf->__Vfunc_writes_gpr__5__i)
                                  ? ((0x20000000U & vlSelf->__Vfunc_writes_gpr__5__i)
                                      ? (~ ([&]() {
                                            vlSelf->__Vfunc_is_store__11__i 
                                                = vlSelf->__Vfunc_writes_gpr__5__i;
                                            vlSelf->__Vfunc_is_store__11__Vfuncout 
                                                = (
                                                   ((((0x28U 
                                                       == 
                                                       (vlSelf->__Vfunc_is_store__11__i 
                                                        >> 0x1aU)) 
                                                      | (0x29U 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__11__i 
                                                          >> 0x1aU))) 
                                                     | (0x2bU 
                                                        == 
                                                        (vlSelf->__Vfunc_is_store__11__i 
                                                         >> 0x1aU))) 
                                                    | (0x2aU 
                                                       == 
                                                       (vlSelf->__Vfunc_is_store__11__i 
                                                        >> 0x1aU))) 
                                                   | (0x2eU 
                                                      == 
                                                      (vlSelf->__Vfunc_is_store__11__i 
                                                       >> 0x1aU)));
                                        }(), (IData)(vlSelf->__Vfunc_is_store__11__Vfuncout)))
                                      : ((0x10000000U 
                                          & vlSelf->__Vfunc_writes_gpr__5__i)
                                          ? (~ ([&]() {
                                                vlSelf->__Vfunc_is_store__12__i 
                                                    = vlSelf->__Vfunc_writes_gpr__5__i;
                                                vlSelf->__Vfunc_is_store__12__Vfuncout 
                                                    = 
                                                    (((((0x28U 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__12__i 
                                                          >> 0x1aU)) 
                                                        | (0x29U 
                                                           == 
                                                           (vlSelf->__Vfunc_is_store__12__i 
                                                            >> 0x1aU))) 
                                                       | (0x2bU 
                                                          == 
                                                          (vlSelf->__Vfunc_is_store__12__i 
                                                           >> 0x1aU))) 
                                                      | (0x2aU 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__12__i 
                                                          >> 0x1aU))) 
                                                     | (0x2eU 
                                                        == 
                                                        (vlSelf->__Vfunc_is_store__12__i 
                                                         >> 0x1aU)));
                                            }(), (IData)(vlSelf->__Vfunc_is_store__12__Vfuncout)))
                                          : ((0x8000000U 
                                              & vlSelf->__Vfunc_writes_gpr__5__i)
                                              ? (~ 
                                                 ([&]() {
                                                    vlSelf->__Vfunc_is_store__13__i 
                                                        = vlSelf->__Vfunc_writes_gpr__5__i;
                                                    vlSelf->__Vfunc_is_store__13__Vfuncout 
                                                        = 
                                                        (((((0x28U 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__13__i 
                                                              >> 0x1aU)) 
                                                            | (0x29U 
                                                               == 
                                                               (vlSelf->__Vfunc_is_store__13__i 
                                                                >> 0x1aU))) 
                                                           | (0x2bU 
                                                              == 
                                                              (vlSelf->__Vfunc_is_store__13__i 
                                                               >> 0x1aU))) 
                                                          | (0x2aU 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__13__i 
                                                              >> 0x1aU))) 
                                                         | (0x2eU 
                                                            == 
                                                            (vlSelf->__Vfunc_is_store__13__i 
                                                             >> 0x1aU)));
                                                }(), (IData)(vlSelf->__Vfunc_is_store__13__Vfuncout)))
                                              : ((0x4000000U 
                                                  & vlSelf->__Vfunc_writes_gpr__5__i)
                                                  ? 
                                                 (~ 
                                                  ([&]() {
                                                        vlSelf->__Vfunc_is_store__14__i 
                                                            = vlSelf->__Vfunc_writes_gpr__5__i;
                                                        vlSelf->__Vfunc_is_store__14__Vfuncout 
                                                            = 
                                                            (((((0x28U 
                                                                 == 
                                                                 (vlSelf->__Vfunc_is_store__14__i 
                                                                  >> 0x1aU)) 
                                                                | (0x29U 
                                                                   == 
                                                                   (vlSelf->__Vfunc_is_store__14__i 
                                                                    >> 0x1aU))) 
                                                               | (0x2bU 
                                                                  == 
                                                                  (vlSelf->__Vfunc_is_store__14__i 
                                                                   >> 0x1aU))) 
                                                              | (0x2aU 
                                                                 == 
                                                                 (vlSelf->__Vfunc_is_store__14__i 
                                                                  >> 0x1aU))) 
                                                             | (0x2eU 
                                                                == 
                                                                (vlSelf->__Vfunc_is_store__14__i 
                                                                 >> 0x1aU)));
                                                    }(), (IData)(vlSelf->__Vfunc_is_store__14__Vfuncout)))
                                                  : 
                                                 (0U 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelf->__Vfunc_writes_gpr__5__i 
                                                      >> 0x15U)))))))
                                  : ((0x20000000U & vlSelf->__Vfunc_writes_gpr__5__i)
                                      ? (~ ([&]() {
                                            vlSelf->__Vfunc_is_store__15__i 
                                                = vlSelf->__Vfunc_writes_gpr__5__i;
                                            vlSelf->__Vfunc_is_store__15__Vfuncout 
                                                = (
                                                   ((((0x28U 
                                                       == 
                                                       (vlSelf->__Vfunc_is_store__15__i 
                                                        >> 0x1aU)) 
                                                      | (0x29U 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__15__i 
                                                          >> 0x1aU))) 
                                                     | (0x2bU 
                                                        == 
                                                        (vlSelf->__Vfunc_is_store__15__i 
                                                         >> 0x1aU))) 
                                                    | (0x2aU 
                                                       == 
                                                       (vlSelf->__Vfunc_is_store__15__i 
                                                        >> 0x1aU))) 
                                                   | (0x2eU 
                                                      == 
                                                      (vlSelf->__Vfunc_is_store__15__i 
                                                       >> 0x1aU)));
                                        }(), (IData)(vlSelf->__Vfunc_is_store__15__Vfuncout)))
                                      : ((1U & (~ (vlSelf->__Vfunc_writes_gpr__5__i 
                                                   >> 0x1cU))) 
                                         && (1U & (
                                                   (0x8000000U 
                                                    & vlSelf->__Vfunc_writes_gpr__5__i)
                                                    ? 
                                                   (vlSelf->__Vfunc_writes_gpr__5__i 
                                                    >> 0x1aU)
                                                    : 
                                                   ((0x4000000U 
                                                     & vlSelf->__Vfunc_writes_gpr__5__i)
                                                     ? 
                                                    ((0x10U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->__Vfunc_writes_gpr__5__i 
                                                          >> 0x10U))) 
                                                     | (0x11U 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelf->__Vfunc_writes_gpr__5__i 
                                                            >> 0x10U))))
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->__Vfunc_writes_gpr__5__i 
                                                         >> 5U)) 
                                                     || (1U 
                                                         & ((0x10U 
                                                             & vlSelf->__Vfunc_writes_gpr__5__i)
                                                             ? 
                                                            ((8U 
                                                              & vlSelf->__Vfunc_writes_gpr__5__i)
                                                              ? 
                                                             (vlSelf->__Vfunc_writes_gpr__5__i 
                                                              >> 2U)
                                                              : 
                                                             ((1U 
                                                               & (vlSelf->__Vfunc_writes_gpr__5__i 
                                                                  >> 2U)) 
                                                              || (1U 
                                                                  & (~ vlSelf->__Vfunc_writes_gpr__5__i))))
                                                             : 
                                                            ((1U 
                                                              & (~ 
                                                                 (vlSelf->__Vfunc_writes_gpr__5__i 
                                                                  >> 3U))) 
                                                             || (1U 
                                                                 & ((4U 
                                                                     & vlSelf->__Vfunc_writes_gpr__5__i)
                                                                     ? 
                                                                    (vlSelf->__Vfunc_writes_gpr__5__i 
                                                                     >> 1U)
                                                                     : 
                                                                    ((1U 
                                                                      & (vlSelf->__Vfunc_writes_gpr__5__i 
                                                                         >> 1U)) 
                                                                     || (1U 
                                                                         & vlSelf->__Vfunc_writes_gpr__5__i))))))))))))))));
            }(), (IData)(vlSelf->__Vfunc_writes_gpr__5__Vfuncout)));
    vlSelf->__PVT__ex_simm = (((- (IData)((1U & (vlSelf->__PVT__ex_insn 
                                                 >> 0xfU)))) 
                               << 0x10U) | (0xffffU 
                                            & vlSelf->__PVT__ex_insn));
    __PVT__ex_is_load = ((IData)(vlSelf->__PVT__ex_v) 
                         & ([&]() {
                vlSelf->__Vfunc_is_load__30__i = vlSelf->__PVT__ex_insn;
                vlSelf->__Vfunc_is_load__30__Vfuncout 
                    = (((((((0x20U == (vlSelf->__Vfunc_is_load__30__i 
                                       >> 0x1aU)) | 
                            (0x21U == (vlSelf->__Vfunc_is_load__30__i 
                                       >> 0x1aU))) 
                           | (0x23U == (vlSelf->__Vfunc_is_load__30__i 
                                        >> 0x1aU))) 
                          | (0x24U == (vlSelf->__Vfunc_is_load__30__i 
                                       >> 0x1aU))) 
                         | (0x25U == (vlSelf->__Vfunc_is_load__30__i 
                                      >> 0x1aU))) | 
                        (0x22U == (vlSelf->__Vfunc_is_load__30__i 
                                   >> 0x1aU))) | (0x26U 
                                                  == 
                                                  (vlSelf->__Vfunc_is_load__30__i 
                                                   >> 0x1aU)));
            }(), (IData)(vlSelf->__Vfunc_is_load__30__Vfuncout)));
    __VdfgTmp_hc3cd8cde__0 = ((IData)(vlSelf->__PVT__ex_v) 
                              & (0U == (vlSelf->__PVT__ex_insn 
                                        >> 0x1aU)));
    __Vfunc_dest_reg__27__i = vlSelf->__PVT__ex_insn;
    __Vfunc_dest_reg__27__Vfuncout = (0x1fU & ((__Vfunc_dest_reg__27__i 
                                                >> 0x1fU)
                                                ? (__Vfunc_dest_reg__27__i 
                                                   >> 0x10U)
                                                : (
                                                   (0x40000000U 
                                                    & __Vfunc_dest_reg__27__i)
                                                    ? 
                                                   ((0x20000000U 
                                                     & __Vfunc_dest_reg__27__i)
                                                     ? 
                                                    (__Vfunc_dest_reg__27__i 
                                                     >> 0x10U)
                                                     : 
                                                    ((0x10000000U 
                                                      & __Vfunc_dest_reg__27__i)
                                                      ? 
                                                     (__Vfunc_dest_reg__27__i 
                                                      >> 0x10U)
                                                      : 
                                                     ((0x8000000U 
                                                       & __Vfunc_dest_reg__27__i)
                                                       ? 
                                                      (__Vfunc_dest_reg__27__i 
                                                       >> 0x10U)
                                                       : 
                                                      ((0x4000000U 
                                                        & __Vfunc_dest_reg__27__i)
                                                        ? 
                                                       (__Vfunc_dest_reg__27__i 
                                                        >> 0x10U)
                                                        : 
                                                       (__Vfunc_dest_reg__27__i 
                                                        >> 0x10U)))))
                                                    : 
                                                   ((0x20000000U 
                                                     & __Vfunc_dest_reg__27__i)
                                                     ? 
                                                    (__Vfunc_dest_reg__27__i 
                                                     >> 0x10U)
                                                     : 
                                                    ((0x10000000U 
                                                      & __Vfunc_dest_reg__27__i)
                                                      ? 
                                                     (__Vfunc_dest_reg__27__i 
                                                      >> 0x10U)
                                                      : 
                                                     ((0x8000000U 
                                                       & __Vfunc_dest_reg__27__i)
                                                       ? 
                                                      ((0x4000000U 
                                                        & __Vfunc_dest_reg__27__i)
                                                        ? 0x1fU
                                                        : 
                                                       (__Vfunc_dest_reg__27__i 
                                                        >> 0x10U))
                                                       : 
                                                      ((0x4000000U 
                                                        & __Vfunc_dest_reg__27__i)
                                                        ? 0x1fU
                                                        : 
                                                       ((9U 
                                                         == 
                                                         (0x3fU 
                                                          & __Vfunc_dest_reg__27__i))
                                                         ? 
                                                        ((0U 
                                                          == 
                                                          (0x1fU 
                                                           & (__Vfunc_dest_reg__27__i 
                                                              >> 0xbU)))
                                                          ? 0x1fU
                                                          : 
                                                         (__Vfunc_dest_reg__27__i 
                                                          >> 0xbU))
                                                         : 
                                                        (__Vfunc_dest_reg__27__i 
                                                         >> 0xbU)))))))));
    vlSelf->__PVT__ex_wa = __Vfunc_dest_reg__27__Vfuncout;
    vlSelf->__PVT__me_exc_out_ret = (1U & ((~ (IData)(vlSelf->__PVT__me_exc_v)) 
                                           | (IData)(vlSelf->__PVT__me_exc_ret)));
    if (vlSelf->__PVT__me_exc_v) {
        vlSelf->__PVT__me_exc_out_code = vlSelf->__PVT__me_exc_code;
        vlSelf->__PVT__me_exc_out_bad = vlSelf->__PVT__me_exc_bad;
    } else {
        vlSelf->__PVT__me_exc_out_code = 7U;
        vlSelf->__PVT__me_exc_out_bad = vlSelf->__PVT__me_va;
    }
    vlSelf->__PVT__me_exc_out_badv = (1U & ((~ (IData)(vlSelf->__PVT__me_exc_v)) 
                                            | (IData)(vlSelf->__PVT__me_exc_bad_v)));
    __Vfunc_phys__80__va = vlSelf->__PVT__me_va;
    __Vfunc_phys__80__Vfuncout = (((0x80000000U <= __Vfunc_phys__80__va) 
                                   & (0xc0000000U > __Vfunc_phys__80__va))
                                   ? (0x1fffffffU & __Vfunc_phys__80__va)
                                   : __Vfunc_phys__80__va);
    vlSelf->__PVT__cache_op_addr = __Vfunc_phys__80__Vfuncout;
    vlSelf->__PVT__dbus_addr = (0xfffffffcU & ([&]() {
                vlSelf->__Vfunc_phys__78__va = vlSelf->__PVT__me_va;
                vlSelf->__Vfunc_phys__78__Vfuncout 
                    = (((0x80000000U <= vlSelf->__Vfunc_phys__78__va) 
                        & (0xc0000000U > vlSelf->__Vfunc_phys__78__va))
                        ? (0x1fffffffU & vlSelf->__Vfunc_phys__78__va)
                        : vlSelf->__Vfunc_phys__78__va);
            }(), vlSelf->__Vfunc_phys__78__Vfuncout));
    __Vfunc_cacheable__79__va = vlSelf->__PVT__me_va;
    __Vfunc_cacheable__79__Vfuncout = (0xa0000000U 
                                       > __Vfunc_cacheable__79__va);
    vlSelf->__PVT__dbus_cached = __Vfunc_cacheable__79__Vfuncout;
    vlSelf->__PVT__i_me = vlSelf->__PVT__me_insn;
    if ((vlSelf->__PVT__me_insn >> 0x1fU)) {
        if ((0x40000000U & vlSelf->__PVT__me_insn)) {
            vlSelf->__PVT__store_word = vlSelf->__PVT__me_rt;
            vlSelf->__PVT__me_be = 0xfU;
        } else if ((0x20000000U & vlSelf->__PVT__me_insn)) {
            if ((0x10000000U & vlSelf->__PVT__me_insn)) {
                vlSelf->__PVT__store_word = ((0x8000000U 
                                              & vlSelf->__PVT__me_insn)
                                              ? ((0x4000000U 
                                                  & vlSelf->__PVT__me_insn)
                                                  ? vlSelf->__PVT__me_rt
                                                  : 
                                                 ((2U 
                                                   & vlSelf->__PVT__me_va)
                                                   ? 
                                                  ((1U 
                                                    & vlSelf->__PVT__me_va)
                                                    ? vlSelf->__PVT__me_rt
                                                    : 
                                                   ((vlSelf->__PVT__me_rt 
                                                     << 8U) 
                                                    | (0xffU 
                                                       & vlSelf->__PVT__me_rmw_word)))
                                                   : 
                                                  ((1U 
                                                    & vlSelf->__PVT__me_va)
                                                    ? 
                                                   ((vlSelf->__PVT__me_rt 
                                                     << 0x10U) 
                                                    | (0xffffU 
                                                       & vlSelf->__PVT__me_rmw_word))
                                                    : 
                                                   ((vlSelf->__PVT__me_rt 
                                                     << 0x18U) 
                                                    | (0xffffffU 
                                                       & vlSelf->__PVT__me_rmw_word)))))
                                              : vlSelf->__PVT__me_rt);
                vlSelf->__PVT__me_be = (0xfU & 0xfU);
            } else if ((0x8000000U & vlSelf->__PVT__me_insn)) {
                vlSelf->__PVT__store_word = ((0x4000000U 
                                              & vlSelf->__PVT__me_insn)
                                              ? vlSelf->__PVT__me_rt
                                              : ((2U 
                                                  & vlSelf->__PVT__me_va)
                                                  ? 
                                                 ((1U 
                                                   & vlSelf->__PVT__me_va)
                                                   ? 
                                                  ((0xffffff00U 
                                                    & vlSelf->__PVT__me_rmw_word) 
                                                   | (vlSelf->__PVT__me_rt 
                                                      >> 0x18U))
                                                   : 
                                                  ((0xffff0000U 
                                                    & vlSelf->__PVT__me_rmw_word) 
                                                   | (vlSelf->__PVT__me_rt 
                                                      >> 0x10U)))
                                                  : 
                                                 ((1U 
                                                   & vlSelf->__PVT__me_va)
                                                   ? 
                                                  ((0xff000000U 
                                                    & vlSelf->__PVT__me_rmw_word) 
                                                   | (vlSelf->__PVT__me_rt 
                                                      >> 8U))
                                                   : vlSelf->__PVT__me_rt)));
                vlSelf->__PVT__me_be = (0xfU & 0xfU);
            } else if ((0x4000000U & vlSelf->__PVT__me_insn)) {
                vlSelf->__PVT__store_word = ((vlSelf->__PVT__me_rt 
                                              << 0x10U) 
                                             | (0xffffU 
                                                & vlSelf->__PVT__me_rt));
                vlSelf->__PVT__me_be = (0xfU & ((2U 
                                                 & vlSelf->__PVT__me_va)
                                                 ? 3U
                                                 : 0xcU));
            } else {
                vlSelf->__PVT__store_word = ((vlSelf->__PVT__me_rt 
                                              << 0x18U) 
                                             | ((0xff0000U 
                                                 & (vlSelf->__PVT__me_rt 
                                                    << 0x10U)) 
                                                | ((0xff00U 
                                                    & (vlSelf->__PVT__me_rt 
                                                       << 8U)) 
                                                   | (0xffU 
                                                      & vlSelf->__PVT__me_rt))));
                vlSelf->__PVT__me_be = (0xfU & (8U 
                                                >> 
                                                (3U 
                                                 & vlSelf->__PVT__me_va)));
            }
        } else {
            vlSelf->__PVT__store_word = vlSelf->__PVT__me_rt;
            vlSelf->__PVT__me_be = (0xfU & ((0x8000000U 
                                             & vlSelf->__PVT__me_insn)
                                             ? 0xfU
                                             : ((0x4000000U 
                                                 & vlSelf->__PVT__me_insn)
                                                 ? 
                                                ((2U 
                                                  & vlSelf->__PVT__me_va)
                                                  ? 3U
                                                  : 0xcU)
                                                 : 
                                                (8U 
                                                 >> 
                                                 (3U 
                                                  & vlSelf->__PVT__me_va)))));
        }
    } else {
        vlSelf->__PVT__store_word = vlSelf->__PVT__me_rt;
        vlSelf->__PVT__me_be = 0xfU;
    }
    vlSelf->__PVT__cp0_write_inflight = (((((IData)(vlSelf->__PVT__ex_v) 
                                            & ([&]() {
                            vlSelf->__Vfunc_touches_cp0__70__i 
                                = vlSelf->__PVT__ex_insn;
                            vlSelf->__Vfunc_touches_cp0__70__Vfuncout 
                                = (0x10U == (vlSelf->__Vfunc_touches_cp0__70__i 
                                             >> 0x1aU));
                        }(), (IData)(vlSelf->__Vfunc_touches_cp0__70__Vfuncout))) 
                                           & ((4U == 
                                               (0x1fU 
                                                & (vlSelf->__PVT__ex_insn 
                                                   >> 0x15U))) 
                                              | (0x10U 
                                                 == 
                                                 (0x1fU 
                                                  & (vlSelf->__PVT__ex_insn 
                                                     >> 0x15U))))) 
                                          | (((IData)(vlSelf->__PVT__me_v) 
                                              & ([&]() {
                            vlSelf->__Vfunc_touches_cp0__71__i 
                                = vlSelf->__PVT__me_insn;
                            vlSelf->__Vfunc_touches_cp0__71__Vfuncout 
                                = (0x10U == (vlSelf->__Vfunc_touches_cp0__71__i 
                                             >> 0x1aU));
                        }(), (IData)(vlSelf->__Vfunc_touches_cp0__71__Vfuncout))) 
                                             & ((4U 
                                                 == 
                                                 (0x1fU 
                                                  & (vlSelf->__PVT__me_insn 
                                                     >> 0x15U))) 
                                                | (0x10U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->__PVT__me_insn 
                                                       >> 0x15U)))))) 
                                         | ((IData)(vlSelf->__PVT__wb_v) 
                                            & (IData)(vlSelf->__PVT__wb_cp0_we)));
    vlSelf->__PVT__special_inflight = ((((IData)(vlSelf->__PVT__ex_v) 
                                         & ([&]() {
                        vlSelf->__Vfunc_writes_cp0_or_hilo__66__i 
                            = vlSelf->__PVT__ex_insn;
                        vlSelf->__Vfunc_writes_cp0_or_hilo__66__Vfuncout 
                            = (((0x10U == (vlSelf->__Vfunc_writes_cp0_or_hilo__66__i 
                                           >> 0x1aU)) 
                                & ((4U == (0x1fU & 
                                           (vlSelf->__Vfunc_writes_cp0_or_hilo__66__i 
                                            >> 0x15U))) 
                                   | (0x10U == (0x1fU 
                                                & (vlSelf->__Vfunc_writes_cp0_or_hilo__66__i 
                                                   >> 0x15U))))) 
                               | ((0U == (vlSelf->__Vfunc_writes_cp0_or_hilo__66__i 
                                          >> 0x1aU)) 
                                  & (((0x11U == (0x3fU 
                                                 & vlSelf->__Vfunc_writes_cp0_or_hilo__66__i)) 
                                      | (0x13U == (0x3fU 
                                                   & vlSelf->__Vfunc_writes_cp0_or_hilo__66__i))) 
                                     | ((0x18U <= (0x3fU 
                                                   & vlSelf->__Vfunc_writes_cp0_or_hilo__66__i)) 
                                        & (0x1bU >= 
                                           (0x3fU & vlSelf->__Vfunc_writes_cp0_or_hilo__66__i))))));
                    }(), (IData)(vlSelf->__Vfunc_writes_cp0_or_hilo__66__Vfuncout))) 
                                        | ((IData)(vlSelf->__PVT__me_v) 
                                           & ([&]() {
                        vlSelf->__Vfunc_writes_cp0_or_hilo__67__i 
                            = vlSelf->__PVT__me_insn;
                        vlSelf->__Vfunc_writes_cp0_or_hilo__67__Vfuncout 
                            = (((0x10U == (vlSelf->__Vfunc_writes_cp0_or_hilo__67__i 
                                           >> 0x1aU)) 
                                & ((4U == (0x1fU & 
                                           (vlSelf->__Vfunc_writes_cp0_or_hilo__67__i 
                                            >> 0x15U))) 
                                   | (0x10U == (0x1fU 
                                                & (vlSelf->__Vfunc_writes_cp0_or_hilo__67__i 
                                                   >> 0x15U))))) 
                               | ((0U == (vlSelf->__Vfunc_writes_cp0_or_hilo__67__i 
                                          >> 0x1aU)) 
                                  & (((0x11U == (0x3fU 
                                                 & vlSelf->__Vfunc_writes_cp0_or_hilo__67__i)) 
                                      | (0x13U == (0x3fU 
                                                   & vlSelf->__Vfunc_writes_cp0_or_hilo__67__i))) 
                                     | ((0x18U <= (0x3fU 
                                                   & vlSelf->__Vfunc_writes_cp0_or_hilo__67__i)) 
                                        & (0x1bU >= 
                                           (0x3fU & vlSelf->__Vfunc_writes_cp0_or_hilo__67__i))))));
                    }(), (IData)(vlSelf->__Vfunc_writes_cp0_or_hilo__67__Vfuncout)))) 
                                       | ((IData)(vlSelf->__PVT__wb_v) 
                                          & ((IData)(vlSelf->__PVT__wb_cp0_we) 
                                             | (IData)(vlSelf->__PVT__wb_hilo_we))));
    __PVT__me_is_load = ((IData)(vlSelf->__PVT__me_v) 
                         & ([&]() {
                vlSelf->__Vfunc_is_load__53__i = vlSelf->__PVT__me_insn;
                vlSelf->__Vfunc_is_load__53__Vfuncout 
                    = (((((((0x20U == (vlSelf->__Vfunc_is_load__53__i 
                                       >> 0x1aU)) | 
                            (0x21U == (vlSelf->__Vfunc_is_load__53__i 
                                       >> 0x1aU))) 
                           | (0x23U == (vlSelf->__Vfunc_is_load__53__i 
                                        >> 0x1aU))) 
                          | (0x24U == (vlSelf->__Vfunc_is_load__53__i 
                                       >> 0x1aU))) 
                         | (0x25U == (vlSelf->__Vfunc_is_load__53__i 
                                      >> 0x1aU))) | 
                        (0x22U == (vlSelf->__Vfunc_is_load__53__i 
                                   >> 0x1aU))) | (0x26U 
                                                  == 
                                                  (vlSelf->__Vfunc_is_load__53__i 
                                                   >> 0x1aU)));
            }(), (IData)(vlSelf->__Vfunc_is_load__53__Vfuncout)));
    vlSelf->__PVT__me_last_beat = (1U & ((~ ([&]() {
                        vlSelf->__Vfunc_is_rmw__75__i 
                            = vlSelf->__PVT__me_insn;
                        vlSelf->__Vfunc_is_rmw__75__Vfuncout 
                            = ((0x2aU == (vlSelf->__Vfunc_is_rmw__75__i 
                                          >> 0x1aU)) 
                               | (0x2eU == (vlSelf->__Vfunc_is_rmw__75__i 
                                            >> 0x1aU)));
                    }(), (IData)(vlSelf->__Vfunc_is_rmw__75__Vfuncout))) 
                                         | (IData)(vlSelf->__PVT__me_phase)));
    __PVT__me_writes = ((IData)(vlSelf->__PVT__me_v) 
                        & ([&]() {
                vlSelf->__Vfunc_writes_gpr__16__i = vlSelf->__PVT__me_insn;
                vlSelf->__Vfunc_writes_gpr__16__Vfuncout 
                    = (1U & ((vlSelf->__Vfunc_writes_gpr__16__i 
                              >> 0x1fU) ? ((0x40000000U 
                                            & vlSelf->__Vfunc_writes_gpr__16__i)
                                            ? (~ ([&]() {
                                        vlSelf->__Vfunc_is_store__17__i 
                                            = vlSelf->__Vfunc_writes_gpr__16__i;
                                        vlSelf->__Vfunc_is_store__17__Vfuncout 
                                            = (((((0x28U 
                                                   == 
                                                   (vlSelf->__Vfunc_is_store__17__i 
                                                    >> 0x1aU)) 
                                                  | (0x29U 
                                                     == 
                                                     (vlSelf->__Vfunc_is_store__17__i 
                                                      >> 0x1aU))) 
                                                 | (0x2bU 
                                                    == 
                                                    (vlSelf->__Vfunc_is_store__17__i 
                                                     >> 0x1aU))) 
                                                | (0x2aU 
                                                   == 
                                                   (vlSelf->__Vfunc_is_store__17__i 
                                                    >> 0x1aU))) 
                                               | (0x2eU 
                                                  == 
                                                  (vlSelf->__Vfunc_is_store__17__i 
                                                   >> 0x1aU)));
                                    }(), (IData)(vlSelf->__Vfunc_is_store__17__Vfuncout)))
                                            : ((0x20000000U 
                                                & vlSelf->__Vfunc_writes_gpr__16__i)
                                                ? (
                                                   (0x10000000U 
                                                    & vlSelf->__Vfunc_writes_gpr__16__i)
                                                    ? 
                                                   ((0x8000000U 
                                                     & vlSelf->__Vfunc_writes_gpr__16__i)
                                                     ? 
                                                    ((1U 
                                                      & (~ 
                                                         (vlSelf->__Vfunc_writes_gpr__16__i 
                                                          >> 0x1aU))) 
                                                     && (1U 
                                                         & (~ 
                                                            ([&]() {
                                                            vlSelf->__Vfunc_is_store__18__i 
                                                                = vlSelf->__Vfunc_writes_gpr__16__i;
                                                            vlSelf->__Vfunc_is_store__18__Vfuncout 
                                                                = 
                                                                (((((0x28U 
                                                                     == 
                                                                     (vlSelf->__Vfunc_is_store__18__i 
                                                                      >> 0x1aU)) 
                                                                    | (0x29U 
                                                                       == 
                                                                       (vlSelf->__Vfunc_is_store__18__i 
                                                                        >> 0x1aU))) 
                                                                   | (0x2bU 
                                                                      == 
                                                                      (vlSelf->__Vfunc_is_store__18__i 
                                                                       >> 0x1aU))) 
                                                                  | (0x2aU 
                                                                     == 
                                                                     (vlSelf->__Vfunc_is_store__18__i 
                                                                      >> 0x1aU))) 
                                                                 | (0x2eU 
                                                                    == 
                                                                    (vlSelf->__Vfunc_is_store__18__i 
                                                                     >> 0x1aU)));
                                                        }(), (IData)(vlSelf->__Vfunc_is_store__18__Vfuncout)))))
                                                     : 
                                                    (~ 
                                                     ([&]() {
                                                    vlSelf->__Vfunc_is_store__19__i 
                                                        = vlSelf->__Vfunc_writes_gpr__16__i;
                                                    vlSelf->__Vfunc_is_store__19__Vfuncout 
                                                        = 
                                                        (((((0x28U 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__19__i 
                                                              >> 0x1aU)) 
                                                            | (0x29U 
                                                               == 
                                                               (vlSelf->__Vfunc_is_store__19__i 
                                                                >> 0x1aU))) 
                                                           | (0x2bU 
                                                              == 
                                                              (vlSelf->__Vfunc_is_store__19__i 
                                                               >> 0x1aU))) 
                                                          | (0x2aU 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__19__i 
                                                              >> 0x1aU))) 
                                                         | (0x2eU 
                                                            == 
                                                            (vlSelf->__Vfunc_is_store__19__i 
                                                             >> 0x1aU)));
                                                }(), (IData)(vlSelf->__Vfunc_is_store__19__Vfuncout))))
                                                    : 
                                                   (~ 
                                                    ([&]() {
                                                vlSelf->__Vfunc_is_store__20__i 
                                                    = vlSelf->__Vfunc_writes_gpr__16__i;
                                                vlSelf->__Vfunc_is_store__20__Vfuncout 
                                                    = 
                                                    (((((0x28U 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__20__i 
                                                          >> 0x1aU)) 
                                                        | (0x29U 
                                                           == 
                                                           (vlSelf->__Vfunc_is_store__20__i 
                                                            >> 0x1aU))) 
                                                       | (0x2bU 
                                                          == 
                                                          (vlSelf->__Vfunc_is_store__20__i 
                                                           >> 0x1aU))) 
                                                      | (0x2aU 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__20__i 
                                                          >> 0x1aU))) 
                                                     | (0x2eU 
                                                        == 
                                                        (vlSelf->__Vfunc_is_store__20__i 
                                                         >> 0x1aU)));
                                            }(), (IData)(vlSelf->__Vfunc_is_store__20__Vfuncout))))
                                                : (~ 
                                                   ([&]() {
                                            vlSelf->__Vfunc_is_store__21__i 
                                                = vlSelf->__Vfunc_writes_gpr__16__i;
                                            vlSelf->__Vfunc_is_store__21__Vfuncout 
                                                = (
                                                   ((((0x28U 
                                                       == 
                                                       (vlSelf->__Vfunc_is_store__21__i 
                                                        >> 0x1aU)) 
                                                      | (0x29U 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__21__i 
                                                          >> 0x1aU))) 
                                                     | (0x2bU 
                                                        == 
                                                        (vlSelf->__Vfunc_is_store__21__i 
                                                         >> 0x1aU))) 
                                                    | (0x2aU 
                                                       == 
                                                       (vlSelf->__Vfunc_is_store__21__i 
                                                        >> 0x1aU))) 
                                                   | (0x2eU 
                                                      == 
                                                      (vlSelf->__Vfunc_is_store__21__i 
                                                       >> 0x1aU)));
                                        }(), (IData)(vlSelf->__Vfunc_is_store__21__Vfuncout)))))
                              : ((0x40000000U & vlSelf->__Vfunc_writes_gpr__16__i)
                                  ? ((0x20000000U & vlSelf->__Vfunc_writes_gpr__16__i)
                                      ? (~ ([&]() {
                                            vlSelf->__Vfunc_is_store__22__i 
                                                = vlSelf->__Vfunc_writes_gpr__16__i;
                                            vlSelf->__Vfunc_is_store__22__Vfuncout 
                                                = (
                                                   ((((0x28U 
                                                       == 
                                                       (vlSelf->__Vfunc_is_store__22__i 
                                                        >> 0x1aU)) 
                                                      | (0x29U 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__22__i 
                                                          >> 0x1aU))) 
                                                     | (0x2bU 
                                                        == 
                                                        (vlSelf->__Vfunc_is_store__22__i 
                                                         >> 0x1aU))) 
                                                    | (0x2aU 
                                                       == 
                                                       (vlSelf->__Vfunc_is_store__22__i 
                                                        >> 0x1aU))) 
                                                   | (0x2eU 
                                                      == 
                                                      (vlSelf->__Vfunc_is_store__22__i 
                                                       >> 0x1aU)));
                                        }(), (IData)(vlSelf->__Vfunc_is_store__22__Vfuncout)))
                                      : ((0x10000000U 
                                          & vlSelf->__Vfunc_writes_gpr__16__i)
                                          ? (~ ([&]() {
                                                vlSelf->__Vfunc_is_store__23__i 
                                                    = vlSelf->__Vfunc_writes_gpr__16__i;
                                                vlSelf->__Vfunc_is_store__23__Vfuncout 
                                                    = 
                                                    (((((0x28U 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__23__i 
                                                          >> 0x1aU)) 
                                                        | (0x29U 
                                                           == 
                                                           (vlSelf->__Vfunc_is_store__23__i 
                                                            >> 0x1aU))) 
                                                       | (0x2bU 
                                                          == 
                                                          (vlSelf->__Vfunc_is_store__23__i 
                                                           >> 0x1aU))) 
                                                      | (0x2aU 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__23__i 
                                                          >> 0x1aU))) 
                                                     | (0x2eU 
                                                        == 
                                                        (vlSelf->__Vfunc_is_store__23__i 
                                                         >> 0x1aU)));
                                            }(), (IData)(vlSelf->__Vfunc_is_store__23__Vfuncout)))
                                          : ((0x8000000U 
                                              & vlSelf->__Vfunc_writes_gpr__16__i)
                                              ? (~ 
                                                 ([&]() {
                                                    vlSelf->__Vfunc_is_store__24__i 
                                                        = vlSelf->__Vfunc_writes_gpr__16__i;
                                                    vlSelf->__Vfunc_is_store__24__Vfuncout 
                                                        = 
                                                        (((((0x28U 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__24__i 
                                                              >> 0x1aU)) 
                                                            | (0x29U 
                                                               == 
                                                               (vlSelf->__Vfunc_is_store__24__i 
                                                                >> 0x1aU))) 
                                                           | (0x2bU 
                                                              == 
                                                              (vlSelf->__Vfunc_is_store__24__i 
                                                               >> 0x1aU))) 
                                                          | (0x2aU 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__24__i 
                                                              >> 0x1aU))) 
                                                         | (0x2eU 
                                                            == 
                                                            (vlSelf->__Vfunc_is_store__24__i 
                                                             >> 0x1aU)));
                                                }(), (IData)(vlSelf->__Vfunc_is_store__24__Vfuncout)))
                                              : ((0x4000000U 
                                                  & vlSelf->__Vfunc_writes_gpr__16__i)
                                                  ? 
                                                 (~ 
                                                  ([&]() {
                                                        vlSelf->__Vfunc_is_store__25__i 
                                                            = vlSelf->__Vfunc_writes_gpr__16__i;
                                                        vlSelf->__Vfunc_is_store__25__Vfuncout 
                                                            = 
                                                            (((((0x28U 
                                                                 == 
                                                                 (vlSelf->__Vfunc_is_store__25__i 
                                                                  >> 0x1aU)) 
                                                                | (0x29U 
                                                                   == 
                                                                   (vlSelf->__Vfunc_is_store__25__i 
                                                                    >> 0x1aU))) 
                                                               | (0x2bU 
                                                                  == 
                                                                  (vlSelf->__Vfunc_is_store__25__i 
                                                                   >> 0x1aU))) 
                                                              | (0x2aU 
                                                                 == 
                                                                 (vlSelf->__Vfunc_is_store__25__i 
                                                                  >> 0x1aU))) 
                                                             | (0x2eU 
                                                                == 
                                                                (vlSelf->__Vfunc_is_store__25__i 
                                                                 >> 0x1aU)));
                                                    }(), (IData)(vlSelf->__Vfunc_is_store__25__Vfuncout)))
                                                  : 
                                                 (0U 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelf->__Vfunc_writes_gpr__16__i 
                                                      >> 0x15U)))))))
                                  : ((0x20000000U & vlSelf->__Vfunc_writes_gpr__16__i)
                                      ? (~ ([&]() {
                                            vlSelf->__Vfunc_is_store__26__i 
                                                = vlSelf->__Vfunc_writes_gpr__16__i;
                                            vlSelf->__Vfunc_is_store__26__Vfuncout 
                                                = (
                                                   ((((0x28U 
                                                       == 
                                                       (vlSelf->__Vfunc_is_store__26__i 
                                                        >> 0x1aU)) 
                                                      | (0x29U 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__26__i 
                                                          >> 0x1aU))) 
                                                     | (0x2bU 
                                                        == 
                                                        (vlSelf->__Vfunc_is_store__26__i 
                                                         >> 0x1aU))) 
                                                    | (0x2aU 
                                                       == 
                                                       (vlSelf->__Vfunc_is_store__26__i 
                                                        >> 0x1aU))) 
                                                   | (0x2eU 
                                                      == 
                                                      (vlSelf->__Vfunc_is_store__26__i 
                                                       >> 0x1aU)));
                                        }(), (IData)(vlSelf->__Vfunc_is_store__26__Vfuncout)))
                                      : ((1U & (~ (vlSelf->__Vfunc_writes_gpr__16__i 
                                                   >> 0x1cU))) 
                                         && (1U & (
                                                   (0x8000000U 
                                                    & vlSelf->__Vfunc_writes_gpr__16__i)
                                                    ? 
                                                   (vlSelf->__Vfunc_writes_gpr__16__i 
                                                    >> 0x1aU)
                                                    : 
                                                   ((0x4000000U 
                                                     & vlSelf->__Vfunc_writes_gpr__16__i)
                                                     ? 
                                                    ((0x10U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->__Vfunc_writes_gpr__16__i 
                                                          >> 0x10U))) 
                                                     | (0x11U 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelf->__Vfunc_writes_gpr__16__i 
                                                            >> 0x10U))))
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->__Vfunc_writes_gpr__16__i 
                                                         >> 5U)) 
                                                     || (1U 
                                                         & ((0x10U 
                                                             & vlSelf->__Vfunc_writes_gpr__16__i)
                                                             ? 
                                                            ((8U 
                                                              & vlSelf->__Vfunc_writes_gpr__16__i)
                                                              ? 
                                                             (vlSelf->__Vfunc_writes_gpr__16__i 
                                                              >> 2U)
                                                              : 
                                                             ((1U 
                                                               & (vlSelf->__Vfunc_writes_gpr__16__i 
                                                                  >> 2U)) 
                                                              || (1U 
                                                                  & (~ vlSelf->__Vfunc_writes_gpr__16__i))))
                                                             : 
                                                            ((1U 
                                                              & (~ 
                                                                 (vlSelf->__Vfunc_writes_gpr__16__i 
                                                                  >> 3U))) 
                                                             || (1U 
                                                                 & ((4U 
                                                                     & vlSelf->__Vfunc_writes_gpr__16__i)
                                                                     ? 
                                                                    (vlSelf->__Vfunc_writes_gpr__16__i 
                                                                     >> 1U)
                                                                     : 
                                                                    ((1U 
                                                                      & (vlSelf->__Vfunc_writes_gpr__16__i 
                                                                         >> 1U)) 
                                                                     || (1U 
                                                                         & vlSelf->__Vfunc_writes_gpr__16__i))))))))))))))));
            }(), (IData)(vlSelf->__Vfunc_writes_gpr__16__Vfuncout)));
    __Vfunc_dest_reg__28__i = vlSelf->__PVT__me_insn;
    __Vfunc_dest_reg__28__Vfuncout = (0x1fU & ((__Vfunc_dest_reg__28__i 
                                                >> 0x1fU)
                                                ? (__Vfunc_dest_reg__28__i 
                                                   >> 0x10U)
                                                : (
                                                   (0x40000000U 
                                                    & __Vfunc_dest_reg__28__i)
                                                    ? 
                                                   ((0x20000000U 
                                                     & __Vfunc_dest_reg__28__i)
                                                     ? 
                                                    (__Vfunc_dest_reg__28__i 
                                                     >> 0x10U)
                                                     : 
                                                    ((0x10000000U 
                                                      & __Vfunc_dest_reg__28__i)
                                                      ? 
                                                     (__Vfunc_dest_reg__28__i 
                                                      >> 0x10U)
                                                      : 
                                                     ((0x8000000U 
                                                       & __Vfunc_dest_reg__28__i)
                                                       ? 
                                                      (__Vfunc_dest_reg__28__i 
                                                       >> 0x10U)
                                                       : 
                                                      ((0x4000000U 
                                                        & __Vfunc_dest_reg__28__i)
                                                        ? 
                                                       (__Vfunc_dest_reg__28__i 
                                                        >> 0x10U)
                                                        : 
                                                       (__Vfunc_dest_reg__28__i 
                                                        >> 0x10U)))))
                                                    : 
                                                   ((0x20000000U 
                                                     & __Vfunc_dest_reg__28__i)
                                                     ? 
                                                    (__Vfunc_dest_reg__28__i 
                                                     >> 0x10U)
                                                     : 
                                                    ((0x10000000U 
                                                      & __Vfunc_dest_reg__28__i)
                                                      ? 
                                                     (__Vfunc_dest_reg__28__i 
                                                      >> 0x10U)
                                                      : 
                                                     ((0x8000000U 
                                                       & __Vfunc_dest_reg__28__i)
                                                       ? 
                                                      ((0x4000000U 
                                                        & __Vfunc_dest_reg__28__i)
                                                        ? 0x1fU
                                                        : 
                                                       (__Vfunc_dest_reg__28__i 
                                                        >> 0x10U))
                                                       : 
                                                      ((0x4000000U 
                                                        & __Vfunc_dest_reg__28__i)
                                                        ? 0x1fU
                                                        : 
                                                       ((9U 
                                                         == 
                                                         (0x3fU 
                                                          & __Vfunc_dest_reg__28__i))
                                                         ? 
                                                        ((0U 
                                                          == 
                                                          (0x1fU 
                                                           & (__Vfunc_dest_reg__28__i 
                                                              >> 0xbU)))
                                                          ? 0x1fU
                                                          : 
                                                         (__Vfunc_dest_reg__28__i 
                                                          >> 0xbU))
                                                         : 
                                                        (__Vfunc_dest_reg__28__i 
                                                         >> 0xbU)))))))));
    vlSelf->__PVT__me_wa = __Vfunc_dest_reg__28__Vfuncout;
    vlSelf->__PVT__dbus_we = (([&]() {
                vlSelf->__Vfunc_is_rmw__76__i = vlSelf->__PVT__me_insn;
                vlSelf->__Vfunc_is_rmw__76__Vfuncout 
                    = ((0x2aU == (vlSelf->__Vfunc_is_rmw__76__i 
                                  >> 0x1aU)) | (0x2eU 
                                                == 
                                                (vlSelf->__Vfunc_is_rmw__76__i 
                                                 >> 0x1aU)));
            }(), (IData)(vlSelf->__Vfunc_is_rmw__76__Vfuncout))
                               ? (IData)(vlSelf->__PVT__me_phase)
                               : ([&]() {
                vlSelf->__Vfunc_is_store__77__i = vlSelf->__PVT__me_insn;
                vlSelf->__Vfunc_is_store__77__Vfuncout 
                    = (((((0x28U == (vlSelf->__Vfunc_is_store__77__i 
                                     >> 0x1aU)) | (0x29U 
                                                   == 
                                                   (vlSelf->__Vfunc_is_store__77__i 
                                                    >> 0x1aU))) 
                         | (0x2bU == (vlSelf->__Vfunc_is_store__77__i 
                                      >> 0x1aU))) | 
                        (0x2aU == (vlSelf->__Vfunc_is_store__77__i 
                                   >> 0x1aU))) | (0x2eU 
                                                  == 
                                                  (vlSelf->__Vfunc_is_store__77__i 
                                                   >> 0x1aU)));
            }(), (IData)(vlSelf->__Vfunc_is_store__77__Vfuncout)));
    vlSelf->__PVT__me_needs_mem = (((IData)(vlSelf->__PVT__me_v) 
                                    & ([&]() {
                    vlSelf->__Vfunc_is_mem__72__i = vlSelf->__PVT__me_insn;
                    vlSelf->__Vfunc_is_mem__72__Vfuncout 
                        = (([&]() {
                                vlSelf->__Vfunc_is_load__73__i 
                                    = vlSelf->__Vfunc_is_mem__72__i;
                                vlSelf->__Vfunc_is_load__73__Vfuncout 
                                    = (((((((0x20U 
                                             == (vlSelf->__Vfunc_is_load__73__i 
                                                 >> 0x1aU)) 
                                            | (0x21U 
                                               == (vlSelf->__Vfunc_is_load__73__i 
                                                   >> 0x1aU))) 
                                           | (0x23U 
                                              == (vlSelf->__Vfunc_is_load__73__i 
                                                  >> 0x1aU))) 
                                          | (0x24U 
                                             == (vlSelf->__Vfunc_is_load__73__i 
                                                 >> 0x1aU))) 
                                         | (0x25U == 
                                            (vlSelf->__Vfunc_is_load__73__i 
                                             >> 0x1aU))) 
                                        | (0x22U == 
                                           (vlSelf->__Vfunc_is_load__73__i 
                                            >> 0x1aU))) 
                                       | (0x26U == 
                                          (vlSelf->__Vfunc_is_load__73__i 
                                           >> 0x1aU)));
                            }(), (IData)(vlSelf->__Vfunc_is_load__73__Vfuncout)) 
                           | ([&]() {
                                vlSelf->__Vfunc_is_store__74__i 
                                    = vlSelf->__Vfunc_is_mem__72__i;
                                vlSelf->__Vfunc_is_store__74__Vfuncout 
                                    = (((((0x28U == 
                                           (vlSelf->__Vfunc_is_store__74__i 
                                            >> 0x1aU)) 
                                          | (0x29U 
                                             == (vlSelf->__Vfunc_is_store__74__i 
                                                 >> 0x1aU))) 
                                         | (0x2bU == 
                                            (vlSelf->__Vfunc_is_store__74__i 
                                             >> 0x1aU))) 
                                        | (0x2aU == 
                                           (vlSelf->__Vfunc_is_store__74__i 
                                            >> 0x1aU))) 
                                       | (0x2eU == 
                                          (vlSelf->__Vfunc_is_store__74__i 
                                           >> 0x1aU)));
                            }(), (IData)(vlSelf->__Vfunc_is_store__74__Vfuncout)));
                }(), (IData)(vlSelf->__Vfunc_is_mem__72__Vfuncout))) 
                                   & (~ (IData)(vlSelf->__PVT__me_exc_v)));
    vlSelf->__PVT__ex_sys = ((IData)(__VdfgTmp_hc3cd8cde__0) 
                             & (0xcU == (0x3fU & vlSelf->__PVT__ex_insn)));
    vlSelf->__PVT__ex_bp = ((IData)(__VdfgTmp_hc3cd8cde__0) 
                            & (0xdU == (0x3fU & vlSelf->__PVT__ex_insn)));
    vlSelf->__PVT__ex_is_div = ((IData)(__VdfgTmp_hc3cd8cde__0) 
                                & ((0x1aU == (0x3fU 
                                              & vlSelf->__PVT__ex_insn)) 
                                   | (0x1bU == (0x3fU 
                                                & vlSelf->__PVT__ex_insn))));
    vlSelf->__VdfgTmp_hcfa842a8__0 = ((IData)(__PVT__ex_writes) 
                                      & (0U != (IData)(vlSelf->__PVT__ex_wa)));
    vlSelf->__PVT__load_use = ((((IData)(__PVT__ex_is_load) 
                                 & ([&]() {
                        vlSelf->__Vfunc_writes_gpr__42__i 
                            = vlSelf->__PVT__ex_insn;
                        vlSelf->__Vfunc_writes_gpr__42__Vfuncout 
                            = (1U & ((vlSelf->__Vfunc_writes_gpr__42__i 
                                      >> 0x1fU) ? (
                                                   (0x40000000U 
                                                    & vlSelf->__Vfunc_writes_gpr__42__i)
                                                    ? 
                                                   (~ 
                                                    ([&]() {
                                                vlSelf->__Vfunc_is_store__43__i 
                                                    = vlSelf->__Vfunc_writes_gpr__42__i;
                                                vlSelf->__Vfunc_is_store__43__Vfuncout 
                                                    = 
                                                    (((((0x28U 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__43__i 
                                                          >> 0x1aU)) 
                                                        | (0x29U 
                                                           == 
                                                           (vlSelf->__Vfunc_is_store__43__i 
                                                            >> 0x1aU))) 
                                                       | (0x2bU 
                                                          == 
                                                          (vlSelf->__Vfunc_is_store__43__i 
                                                           >> 0x1aU))) 
                                                      | (0x2aU 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__43__i 
                                                          >> 0x1aU))) 
                                                     | (0x2eU 
                                                        == 
                                                        (vlSelf->__Vfunc_is_store__43__i 
                                                         >> 0x1aU)));
                                            }(), (IData)(vlSelf->__Vfunc_is_store__43__Vfuncout)))
                                                    : 
                                                   ((0x20000000U 
                                                     & vlSelf->__Vfunc_writes_gpr__42__i)
                                                     ? 
                                                    ((0x10000000U 
                                                      & vlSelf->__Vfunc_writes_gpr__42__i)
                                                      ? 
                                                     ((0x8000000U 
                                                       & vlSelf->__Vfunc_writes_gpr__42__i)
                                                       ? 
                                                      ((1U 
                                                        & (~ 
                                                           (vlSelf->__Vfunc_writes_gpr__42__i 
                                                            >> 0x1aU))) 
                                                       && (1U 
                                                           & (~ 
                                                              ([&]() {
                                                                    vlSelf->__Vfunc_is_store__44__i 
                                                                        = vlSelf->__Vfunc_writes_gpr__42__i;
                                                                    vlSelf->__Vfunc_is_store__44__Vfuncout 
                                                                        = 
                                                                        (((((0x28U 
                                                                             == 
                                                                             (vlSelf->__Vfunc_is_store__44__i 
                                                                              >> 0x1aU)) 
                                                                            | (0x29U 
                                                                               == 
                                                                               (vlSelf->__Vfunc_is_store__44__i 
                                                                                >> 0x1aU))) 
                                                                           | (0x2bU 
                                                                              == 
                                                                              (vlSelf->__Vfunc_is_store__44__i 
                                                                               >> 0x1aU))) 
                                                                          | (0x2aU 
                                                                             == 
                                                                             (vlSelf->__Vfunc_is_store__44__i 
                                                                              >> 0x1aU))) 
                                                                         | (0x2eU 
                                                                            == 
                                                                            (vlSelf->__Vfunc_is_store__44__i 
                                                                             >> 0x1aU)));
                                                                }(), (IData)(vlSelf->__Vfunc_is_store__44__Vfuncout)))))
                                                       : 
                                                      (~ 
                                                       ([&]() {
                                                            vlSelf->__Vfunc_is_store__45__i 
                                                                = vlSelf->__Vfunc_writes_gpr__42__i;
                                                            vlSelf->__Vfunc_is_store__45__Vfuncout 
                                                                = 
                                                                (((((0x28U 
                                                                     == 
                                                                     (vlSelf->__Vfunc_is_store__45__i 
                                                                      >> 0x1aU)) 
                                                                    | (0x29U 
                                                                       == 
                                                                       (vlSelf->__Vfunc_is_store__45__i 
                                                                        >> 0x1aU))) 
                                                                   | (0x2bU 
                                                                      == 
                                                                      (vlSelf->__Vfunc_is_store__45__i 
                                                                       >> 0x1aU))) 
                                                                  | (0x2aU 
                                                                     == 
                                                                     (vlSelf->__Vfunc_is_store__45__i 
                                                                      >> 0x1aU))) 
                                                                 | (0x2eU 
                                                                    == 
                                                                    (vlSelf->__Vfunc_is_store__45__i 
                                                                     >> 0x1aU)));
                                                        }(), (IData)(vlSelf->__Vfunc_is_store__45__Vfuncout))))
                                                      : 
                                                     (~ 
                                                      ([&]() {
                                                        vlSelf->__Vfunc_is_store__46__i 
                                                            = vlSelf->__Vfunc_writes_gpr__42__i;
                                                        vlSelf->__Vfunc_is_store__46__Vfuncout 
                                                            = 
                                                            (((((0x28U 
                                                                 == 
                                                                 (vlSelf->__Vfunc_is_store__46__i 
                                                                  >> 0x1aU)) 
                                                                | (0x29U 
                                                                   == 
                                                                   (vlSelf->__Vfunc_is_store__46__i 
                                                                    >> 0x1aU))) 
                                                               | (0x2bU 
                                                                  == 
                                                                  (vlSelf->__Vfunc_is_store__46__i 
                                                                   >> 0x1aU))) 
                                                              | (0x2aU 
                                                                 == 
                                                                 (vlSelf->__Vfunc_is_store__46__i 
                                                                  >> 0x1aU))) 
                                                             | (0x2eU 
                                                                == 
                                                                (vlSelf->__Vfunc_is_store__46__i 
                                                                 >> 0x1aU)));
                                                    }(), (IData)(vlSelf->__Vfunc_is_store__46__Vfuncout))))
                                                     : 
                                                    (~ 
                                                     ([&]() {
                                                    vlSelf->__Vfunc_is_store__47__i 
                                                        = vlSelf->__Vfunc_writes_gpr__42__i;
                                                    vlSelf->__Vfunc_is_store__47__Vfuncout 
                                                        = 
                                                        (((((0x28U 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__47__i 
                                                              >> 0x1aU)) 
                                                            | (0x29U 
                                                               == 
                                                               (vlSelf->__Vfunc_is_store__47__i 
                                                                >> 0x1aU))) 
                                                           | (0x2bU 
                                                              == 
                                                              (vlSelf->__Vfunc_is_store__47__i 
                                                               >> 0x1aU))) 
                                                          | (0x2aU 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__47__i 
                                                              >> 0x1aU))) 
                                                         | (0x2eU 
                                                            == 
                                                            (vlSelf->__Vfunc_is_store__47__i 
                                                             >> 0x1aU)));
                                                }(), (IData)(vlSelf->__Vfunc_is_store__47__Vfuncout)))))
                                      : ((0x40000000U 
                                          & vlSelf->__Vfunc_writes_gpr__42__i)
                                          ? ((0x20000000U 
                                              & vlSelf->__Vfunc_writes_gpr__42__i)
                                              ? (~ 
                                                 ([&]() {
                                                    vlSelf->__Vfunc_is_store__48__i 
                                                        = vlSelf->__Vfunc_writes_gpr__42__i;
                                                    vlSelf->__Vfunc_is_store__48__Vfuncout 
                                                        = 
                                                        (((((0x28U 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__48__i 
                                                              >> 0x1aU)) 
                                                            | (0x29U 
                                                               == 
                                                               (vlSelf->__Vfunc_is_store__48__i 
                                                                >> 0x1aU))) 
                                                           | (0x2bU 
                                                              == 
                                                              (vlSelf->__Vfunc_is_store__48__i 
                                                               >> 0x1aU))) 
                                                          | (0x2aU 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__48__i 
                                                              >> 0x1aU))) 
                                                         | (0x2eU 
                                                            == 
                                                            (vlSelf->__Vfunc_is_store__48__i 
                                                             >> 0x1aU)));
                                                }(), (IData)(vlSelf->__Vfunc_is_store__48__Vfuncout)))
                                              : ((0x10000000U 
                                                  & vlSelf->__Vfunc_writes_gpr__42__i)
                                                  ? 
                                                 (~ 
                                                  ([&]() {
                                                        vlSelf->__Vfunc_is_store__49__i 
                                                            = vlSelf->__Vfunc_writes_gpr__42__i;
                                                        vlSelf->__Vfunc_is_store__49__Vfuncout 
                                                            = 
                                                            (((((0x28U 
                                                                 == 
                                                                 (vlSelf->__Vfunc_is_store__49__i 
                                                                  >> 0x1aU)) 
                                                                | (0x29U 
                                                                   == 
                                                                   (vlSelf->__Vfunc_is_store__49__i 
                                                                    >> 0x1aU))) 
                                                               | (0x2bU 
                                                                  == 
                                                                  (vlSelf->__Vfunc_is_store__49__i 
                                                                   >> 0x1aU))) 
                                                              | (0x2aU 
                                                                 == 
                                                                 (vlSelf->__Vfunc_is_store__49__i 
                                                                  >> 0x1aU))) 
                                                             | (0x2eU 
                                                                == 
                                                                (vlSelf->__Vfunc_is_store__49__i 
                                                                 >> 0x1aU)));
                                                    }(), (IData)(vlSelf->__Vfunc_is_store__49__Vfuncout)))
                                                  : 
                                                 ((0x8000000U 
                                                   & vlSelf->__Vfunc_writes_gpr__42__i)
                                                   ? 
                                                  (~ 
                                                   ([&]() {
                                                            vlSelf->__Vfunc_is_store__50__i 
                                                                = vlSelf->__Vfunc_writes_gpr__42__i;
                                                            vlSelf->__Vfunc_is_store__50__Vfuncout 
                                                                = 
                                                                (((((0x28U 
                                                                     == 
                                                                     (vlSelf->__Vfunc_is_store__50__i 
                                                                      >> 0x1aU)) 
                                                                    | (0x29U 
                                                                       == 
                                                                       (vlSelf->__Vfunc_is_store__50__i 
                                                                        >> 0x1aU))) 
                                                                   | (0x2bU 
                                                                      == 
                                                                      (vlSelf->__Vfunc_is_store__50__i 
                                                                       >> 0x1aU))) 
                                                                  | (0x2aU 
                                                                     == 
                                                                     (vlSelf->__Vfunc_is_store__50__i 
                                                                      >> 0x1aU))) 
                                                                 | (0x2eU 
                                                                    == 
                                                                    (vlSelf->__Vfunc_is_store__50__i 
                                                                     >> 0x1aU)));
                                                        }(), (IData)(vlSelf->__Vfunc_is_store__50__Vfuncout)))
                                                   : 
                                                  ((0x4000000U 
                                                    & vlSelf->__Vfunc_writes_gpr__42__i)
                                                    ? 
                                                   (~ 
                                                    ([&]() {
                                                                vlSelf->__Vfunc_is_store__51__i 
                                                                    = vlSelf->__Vfunc_writes_gpr__42__i;
                                                                vlSelf->__Vfunc_is_store__51__Vfuncout 
                                                                    = 
                                                                    (((((0x28U 
                                                                         == 
                                                                         (vlSelf->__Vfunc_is_store__51__i 
                                                                          >> 0x1aU)) 
                                                                        | (0x29U 
                                                                           == 
                                                                           (vlSelf->__Vfunc_is_store__51__i 
                                                                            >> 0x1aU))) 
                                                                       | (0x2bU 
                                                                          == 
                                                                          (vlSelf->__Vfunc_is_store__51__i 
                                                                           >> 0x1aU))) 
                                                                      | (0x2aU 
                                                                         == 
                                                                         (vlSelf->__Vfunc_is_store__51__i 
                                                                          >> 0x1aU))) 
                                                                     | (0x2eU 
                                                                        == 
                                                                        (vlSelf->__Vfunc_is_store__51__i 
                                                                         >> 0x1aU)));
                                                            }(), (IData)(vlSelf->__Vfunc_is_store__51__Vfuncout)))
                                                    : 
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->__Vfunc_writes_gpr__42__i 
                                                        >> 0x15U)))))))
                                          : ((0x20000000U 
                                              & vlSelf->__Vfunc_writes_gpr__42__i)
                                              ? (~ 
                                                 ([&]() {
                                                    vlSelf->__Vfunc_is_store__52__i 
                                                        = vlSelf->__Vfunc_writes_gpr__42__i;
                                                    vlSelf->__Vfunc_is_store__52__Vfuncout 
                                                        = 
                                                        (((((0x28U 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__52__i 
                                                              >> 0x1aU)) 
                                                            | (0x29U 
                                                               == 
                                                               (vlSelf->__Vfunc_is_store__52__i 
                                                                >> 0x1aU))) 
                                                           | (0x2bU 
                                                              == 
                                                              (vlSelf->__Vfunc_is_store__52__i 
                                                               >> 0x1aU))) 
                                                          | (0x2aU 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__52__i 
                                                              >> 0x1aU))) 
                                                         | (0x2eU 
                                                            == 
                                                            (vlSelf->__Vfunc_is_store__52__i 
                                                             >> 0x1aU)));
                                                }(), (IData)(vlSelf->__Vfunc_is_store__52__Vfuncout)))
                                              : ((1U 
                                                  & (~ 
                                                     (vlSelf->__Vfunc_writes_gpr__42__i 
                                                      >> 0x1cU))) 
                                                 && (1U 
                                                     & ((0x8000000U 
                                                         & vlSelf->__Vfunc_writes_gpr__42__i)
                                                         ? 
                                                        (vlSelf->__Vfunc_writes_gpr__42__i 
                                                         >> 0x1aU)
                                                         : 
                                                        ((0x4000000U 
                                                          & vlSelf->__Vfunc_writes_gpr__42__i)
                                                          ? 
                                                         ((0x10U 
                                                           == 
                                                           (0x1fU 
                                                            & (vlSelf->__Vfunc_writes_gpr__42__i 
                                                               >> 0x10U))) 
                                                          | (0x11U 
                                                             == 
                                                             (0x1fU 
                                                              & (vlSelf->__Vfunc_writes_gpr__42__i 
                                                                 >> 0x10U))))
                                                          : 
                                                         ((1U 
                                                           & (vlSelf->__Vfunc_writes_gpr__42__i 
                                                              >> 5U)) 
                                                          || (1U 
                                                              & ((0x10U 
                                                                  & vlSelf->__Vfunc_writes_gpr__42__i)
                                                                  ? 
                                                                 ((8U 
                                                                   & vlSelf->__Vfunc_writes_gpr__42__i)
                                                                   ? 
                                                                  (vlSelf->__Vfunc_writes_gpr__42__i 
                                                                   >> 2U)
                                                                   : 
                                                                  ((1U 
                                                                    & (vlSelf->__Vfunc_writes_gpr__42__i 
                                                                       >> 2U)) 
                                                                   || (1U 
                                                                       & (~ vlSelf->__Vfunc_writes_gpr__42__i))))
                                                                  : 
                                                                 ((1U 
                                                                   & (~ 
                                                                      (vlSelf->__Vfunc_writes_gpr__42__i 
                                                                       >> 3U))) 
                                                                  || (1U 
                                                                      & ((4U 
                                                                          & vlSelf->__Vfunc_writes_gpr__42__i)
                                                                          ? 
                                                                         (vlSelf->__Vfunc_writes_gpr__42__i 
                                                                          >> 1U)
                                                                          : 
                                                                         ((1U 
                                                                           & (vlSelf->__Vfunc_writes_gpr__42__i 
                                                                              >> 1U)) 
                                                                          || (1U 
                                                                              & vlSelf->__Vfunc_writes_gpr__42__i))))))))))))))));
                    }(), (IData)(vlSelf->__Vfunc_writes_gpr__42__Vfuncout))) 
                                & (0U != (IData)(vlSelf->__PVT__ex_wa))) 
                               & (((IData)(__PVT__id_needs_rs) 
                                   & ((0x1fU & (vlSelf->__PVT__id_insn 
                                                >> 0x15U)) 
                                      == (IData)(vlSelf->__PVT__ex_wa))) 
                                  | ((IData)(__PVT__id_needs_rt) 
                                     & ((0x1fU & (vlSelf->__PVT__id_insn 
                                                  >> 0x10U)) 
                                        == (IData)(vlSelf->__PVT__ex_wa)))));
    vlSelf->__PVT__id_take_irq = ((IData)(vlSelf->__PVT__id_v) 
                                  & ((~ (IData)(vlSelf->__PVT__id_exc_v)) 
                                     & (vlSelf->__PVT__cp0
                                        [0xcU] & ((~ (IData)(vlSelf->__PVT__special_inflight)) 
                                                  & (0U 
                                                     != 
                                                     (0xffU 
                                                      & ((vlSelf->__PVT__cause_live 
                                                          & vlSelf->__PVT__cp0
                                                          [0xcU]) 
                                                         >> 8U)))))));
    vlSelf->__PVT__special_hazard = (((IData)(vlSelf->__PVT__id_v) 
                                      & (([&]() {
                        vlSelf->__Vfunc_touches_cp0__68__i 
                            = vlSelf->__PVT__id_insn;
                        vlSelf->__Vfunc_touches_cp0__68__Vfuncout 
                            = (0x10U == (vlSelf->__Vfunc_touches_cp0__68__i 
                                         >> 0x1aU));
                    }(), (IData)(vlSelf->__Vfunc_touches_cp0__68__Vfuncout)) 
                                         | ([&]() {
                        vlSelf->__Vfunc_touches_hilo__69__i 
                            = vlSelf->__PVT__id_insn;
                        vlSelf->__Vfunc_touches_hilo__69__Vfuncout 
                            = (((0U == (vlSelf->__Vfunc_touches_hilo__69__i 
                                        >> 0x1aU)) 
                                & (0x10U <= (0x3fU 
                                             & vlSelf->__Vfunc_touches_hilo__69__i))) 
                               & (0x1bU >= (0x3fU & vlSelf->__Vfunc_touches_hilo__69__i)));
                    }(), (IData)(vlSelf->__Vfunc_touches_hilo__69__Vfuncout)))) 
                                     & (IData)(vlSelf->__PVT__special_inflight));
    vlSelf->__PVT__branch_load_use = ((((((IData)(vlSelf->__PVT__id_v) 
                                          & ([&]() {
                                vlSelf->__Vfunc_is_branch__54__i 
                                    = vlSelf->__PVT__id_insn;
                                vlSelf->__Vfunc_is_branch__54__Vfuncout 
                                    = ((1U & (~ (vlSelf->__Vfunc_is_branch__54__i 
                                                 >> 0x1fU))) 
                                       && ((1U & (~ 
                                                  (vlSelf->__Vfunc_is_branch__54__i 
                                                   >> 0x1eU))) 
                                           && ((1U 
                                                & (~ 
                                                   (vlSelf->__Vfunc_is_branch__54__i 
                                                    >> 0x1dU))) 
                                               && ((1U 
                                                    & (vlSelf->__Vfunc_is_branch__54__i 
                                                       >> 0x1cU)) 
                                                   || ((1U 
                                                        & (vlSelf->__Vfunc_is_branch__54__i 
                                                           >> 0x1bU)) 
                                                       || ((1U 
                                                            & (vlSelf->__Vfunc_is_branch__54__i 
                                                               >> 0x1aU)) 
                                                           || ((8U 
                                                                == 
                                                                (0x3fU 
                                                                 & vlSelf->__Vfunc_is_branch__54__i)) 
                                                               | (9U 
                                                                  == 
                                                                  (0x3fU 
                                                                   & vlSelf->__Vfunc_is_branch__54__i)))))))));
                            }(), (IData)(vlSelf->__Vfunc_is_branch__54__Vfuncout))) 
                                         & (IData)(__PVT__me_is_load)) 
                                        & ([&]() {
                        vlSelf->__Vfunc_writes_gpr__55__i 
                            = vlSelf->__PVT__me_insn;
                        vlSelf->__Vfunc_writes_gpr__55__Vfuncout 
                            = (1U & ((vlSelf->__Vfunc_writes_gpr__55__i 
                                      >> 0x1fU) ? (
                                                   (0x40000000U 
                                                    & vlSelf->__Vfunc_writes_gpr__55__i)
                                                    ? 
                                                   (~ 
                                                    ([&]() {
                                                vlSelf->__Vfunc_is_store__56__i 
                                                    = vlSelf->__Vfunc_writes_gpr__55__i;
                                                vlSelf->__Vfunc_is_store__56__Vfuncout 
                                                    = 
                                                    (((((0x28U 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__56__i 
                                                          >> 0x1aU)) 
                                                        | (0x29U 
                                                           == 
                                                           (vlSelf->__Vfunc_is_store__56__i 
                                                            >> 0x1aU))) 
                                                       | (0x2bU 
                                                          == 
                                                          (vlSelf->__Vfunc_is_store__56__i 
                                                           >> 0x1aU))) 
                                                      | (0x2aU 
                                                         == 
                                                         (vlSelf->__Vfunc_is_store__56__i 
                                                          >> 0x1aU))) 
                                                     | (0x2eU 
                                                        == 
                                                        (vlSelf->__Vfunc_is_store__56__i 
                                                         >> 0x1aU)));
                                            }(), (IData)(vlSelf->__Vfunc_is_store__56__Vfuncout)))
                                                    : 
                                                   ((0x20000000U 
                                                     & vlSelf->__Vfunc_writes_gpr__55__i)
                                                     ? 
                                                    ((0x10000000U 
                                                      & vlSelf->__Vfunc_writes_gpr__55__i)
                                                      ? 
                                                     ((0x8000000U 
                                                       & vlSelf->__Vfunc_writes_gpr__55__i)
                                                       ? 
                                                      ((1U 
                                                        & (~ 
                                                           (vlSelf->__Vfunc_writes_gpr__55__i 
                                                            >> 0x1aU))) 
                                                       && (1U 
                                                           & (~ 
                                                              ([&]() {
                                                                    vlSelf->__Vfunc_is_store__57__i 
                                                                        = vlSelf->__Vfunc_writes_gpr__55__i;
                                                                    vlSelf->__Vfunc_is_store__57__Vfuncout 
                                                                        = 
                                                                        (((((0x28U 
                                                                             == 
                                                                             (vlSelf->__Vfunc_is_store__57__i 
                                                                              >> 0x1aU)) 
                                                                            | (0x29U 
                                                                               == 
                                                                               (vlSelf->__Vfunc_is_store__57__i 
                                                                                >> 0x1aU))) 
                                                                           | (0x2bU 
                                                                              == 
                                                                              (vlSelf->__Vfunc_is_store__57__i 
                                                                               >> 0x1aU))) 
                                                                          | (0x2aU 
                                                                             == 
                                                                             (vlSelf->__Vfunc_is_store__57__i 
                                                                              >> 0x1aU))) 
                                                                         | (0x2eU 
                                                                            == 
                                                                            (vlSelf->__Vfunc_is_store__57__i 
                                                                             >> 0x1aU)));
                                                                }(), (IData)(vlSelf->__Vfunc_is_store__57__Vfuncout)))))
                                                       : 
                                                      (~ 
                                                       ([&]() {
                                                            vlSelf->__Vfunc_is_store__58__i 
                                                                = vlSelf->__Vfunc_writes_gpr__55__i;
                                                            vlSelf->__Vfunc_is_store__58__Vfuncout 
                                                                = 
                                                                (((((0x28U 
                                                                     == 
                                                                     (vlSelf->__Vfunc_is_store__58__i 
                                                                      >> 0x1aU)) 
                                                                    | (0x29U 
                                                                       == 
                                                                       (vlSelf->__Vfunc_is_store__58__i 
                                                                        >> 0x1aU))) 
                                                                   | (0x2bU 
                                                                      == 
                                                                      (vlSelf->__Vfunc_is_store__58__i 
                                                                       >> 0x1aU))) 
                                                                  | (0x2aU 
                                                                     == 
                                                                     (vlSelf->__Vfunc_is_store__58__i 
                                                                      >> 0x1aU))) 
                                                                 | (0x2eU 
                                                                    == 
                                                                    (vlSelf->__Vfunc_is_store__58__i 
                                                                     >> 0x1aU)));
                                                        }(), (IData)(vlSelf->__Vfunc_is_store__58__Vfuncout))))
                                                      : 
                                                     (~ 
                                                      ([&]() {
                                                        vlSelf->__Vfunc_is_store__59__i 
                                                            = vlSelf->__Vfunc_writes_gpr__55__i;
                                                        vlSelf->__Vfunc_is_store__59__Vfuncout 
                                                            = 
                                                            (((((0x28U 
                                                                 == 
                                                                 (vlSelf->__Vfunc_is_store__59__i 
                                                                  >> 0x1aU)) 
                                                                | (0x29U 
                                                                   == 
                                                                   (vlSelf->__Vfunc_is_store__59__i 
                                                                    >> 0x1aU))) 
                                                               | (0x2bU 
                                                                  == 
                                                                  (vlSelf->__Vfunc_is_store__59__i 
                                                                   >> 0x1aU))) 
                                                              | (0x2aU 
                                                                 == 
                                                                 (vlSelf->__Vfunc_is_store__59__i 
                                                                  >> 0x1aU))) 
                                                             | (0x2eU 
                                                                == 
                                                                (vlSelf->__Vfunc_is_store__59__i 
                                                                 >> 0x1aU)));
                                                    }(), (IData)(vlSelf->__Vfunc_is_store__59__Vfuncout))))
                                                     : 
                                                    (~ 
                                                     ([&]() {
                                                    vlSelf->__Vfunc_is_store__60__i 
                                                        = vlSelf->__Vfunc_writes_gpr__55__i;
                                                    vlSelf->__Vfunc_is_store__60__Vfuncout 
                                                        = 
                                                        (((((0x28U 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__60__i 
                                                              >> 0x1aU)) 
                                                            | (0x29U 
                                                               == 
                                                               (vlSelf->__Vfunc_is_store__60__i 
                                                                >> 0x1aU))) 
                                                           | (0x2bU 
                                                              == 
                                                              (vlSelf->__Vfunc_is_store__60__i 
                                                               >> 0x1aU))) 
                                                          | (0x2aU 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__60__i 
                                                              >> 0x1aU))) 
                                                         | (0x2eU 
                                                            == 
                                                            (vlSelf->__Vfunc_is_store__60__i 
                                                             >> 0x1aU)));
                                                }(), (IData)(vlSelf->__Vfunc_is_store__60__Vfuncout)))))
                                      : ((0x40000000U 
                                          & vlSelf->__Vfunc_writes_gpr__55__i)
                                          ? ((0x20000000U 
                                              & vlSelf->__Vfunc_writes_gpr__55__i)
                                              ? (~ 
                                                 ([&]() {
                                                    vlSelf->__Vfunc_is_store__61__i 
                                                        = vlSelf->__Vfunc_writes_gpr__55__i;
                                                    vlSelf->__Vfunc_is_store__61__Vfuncout 
                                                        = 
                                                        (((((0x28U 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__61__i 
                                                              >> 0x1aU)) 
                                                            | (0x29U 
                                                               == 
                                                               (vlSelf->__Vfunc_is_store__61__i 
                                                                >> 0x1aU))) 
                                                           | (0x2bU 
                                                              == 
                                                              (vlSelf->__Vfunc_is_store__61__i 
                                                               >> 0x1aU))) 
                                                          | (0x2aU 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__61__i 
                                                              >> 0x1aU))) 
                                                         | (0x2eU 
                                                            == 
                                                            (vlSelf->__Vfunc_is_store__61__i 
                                                             >> 0x1aU)));
                                                }(), (IData)(vlSelf->__Vfunc_is_store__61__Vfuncout)))
                                              : ((0x10000000U 
                                                  & vlSelf->__Vfunc_writes_gpr__55__i)
                                                  ? 
                                                 (~ 
                                                  ([&]() {
                                                        vlSelf->__Vfunc_is_store__62__i 
                                                            = vlSelf->__Vfunc_writes_gpr__55__i;
                                                        vlSelf->__Vfunc_is_store__62__Vfuncout 
                                                            = 
                                                            (((((0x28U 
                                                                 == 
                                                                 (vlSelf->__Vfunc_is_store__62__i 
                                                                  >> 0x1aU)) 
                                                                | (0x29U 
                                                                   == 
                                                                   (vlSelf->__Vfunc_is_store__62__i 
                                                                    >> 0x1aU))) 
                                                               | (0x2bU 
                                                                  == 
                                                                  (vlSelf->__Vfunc_is_store__62__i 
                                                                   >> 0x1aU))) 
                                                              | (0x2aU 
                                                                 == 
                                                                 (vlSelf->__Vfunc_is_store__62__i 
                                                                  >> 0x1aU))) 
                                                             | (0x2eU 
                                                                == 
                                                                (vlSelf->__Vfunc_is_store__62__i 
                                                                 >> 0x1aU)));
                                                    }(), (IData)(vlSelf->__Vfunc_is_store__62__Vfuncout)))
                                                  : 
                                                 ((0x8000000U 
                                                   & vlSelf->__Vfunc_writes_gpr__55__i)
                                                   ? 
                                                  (~ 
                                                   ([&]() {
                                                            vlSelf->__Vfunc_is_store__63__i 
                                                                = vlSelf->__Vfunc_writes_gpr__55__i;
                                                            vlSelf->__Vfunc_is_store__63__Vfuncout 
                                                                = 
                                                                (((((0x28U 
                                                                     == 
                                                                     (vlSelf->__Vfunc_is_store__63__i 
                                                                      >> 0x1aU)) 
                                                                    | (0x29U 
                                                                       == 
                                                                       (vlSelf->__Vfunc_is_store__63__i 
                                                                        >> 0x1aU))) 
                                                                   | (0x2bU 
                                                                      == 
                                                                      (vlSelf->__Vfunc_is_store__63__i 
                                                                       >> 0x1aU))) 
                                                                  | (0x2aU 
                                                                     == 
                                                                     (vlSelf->__Vfunc_is_store__63__i 
                                                                      >> 0x1aU))) 
                                                                 | (0x2eU 
                                                                    == 
                                                                    (vlSelf->__Vfunc_is_store__63__i 
                                                                     >> 0x1aU)));
                                                        }(), (IData)(vlSelf->__Vfunc_is_store__63__Vfuncout)))
                                                   : 
                                                  ((0x4000000U 
                                                    & vlSelf->__Vfunc_writes_gpr__55__i)
                                                    ? 
                                                   (~ 
                                                    ([&]() {
                                                                vlSelf->__Vfunc_is_store__64__i 
                                                                    = vlSelf->__Vfunc_writes_gpr__55__i;
                                                                vlSelf->__Vfunc_is_store__64__Vfuncout 
                                                                    = 
                                                                    (((((0x28U 
                                                                         == 
                                                                         (vlSelf->__Vfunc_is_store__64__i 
                                                                          >> 0x1aU)) 
                                                                        | (0x29U 
                                                                           == 
                                                                           (vlSelf->__Vfunc_is_store__64__i 
                                                                            >> 0x1aU))) 
                                                                       | (0x2bU 
                                                                          == 
                                                                          (vlSelf->__Vfunc_is_store__64__i 
                                                                           >> 0x1aU))) 
                                                                      | (0x2aU 
                                                                         == 
                                                                         (vlSelf->__Vfunc_is_store__64__i 
                                                                          >> 0x1aU))) 
                                                                     | (0x2eU 
                                                                        == 
                                                                        (vlSelf->__Vfunc_is_store__64__i 
                                                                         >> 0x1aU)));
                                                            }(), (IData)(vlSelf->__Vfunc_is_store__64__Vfuncout)))
                                                    : 
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->__Vfunc_writes_gpr__55__i 
                                                        >> 0x15U)))))))
                                          : ((0x20000000U 
                                              & vlSelf->__Vfunc_writes_gpr__55__i)
                                              ? (~ 
                                                 ([&]() {
                                                    vlSelf->__Vfunc_is_store__65__i 
                                                        = vlSelf->__Vfunc_writes_gpr__55__i;
                                                    vlSelf->__Vfunc_is_store__65__Vfuncout 
                                                        = 
                                                        (((((0x28U 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__65__i 
                                                              >> 0x1aU)) 
                                                            | (0x29U 
                                                               == 
                                                               (vlSelf->__Vfunc_is_store__65__i 
                                                                >> 0x1aU))) 
                                                           | (0x2bU 
                                                              == 
                                                              (vlSelf->__Vfunc_is_store__65__i 
                                                               >> 0x1aU))) 
                                                          | (0x2aU 
                                                             == 
                                                             (vlSelf->__Vfunc_is_store__65__i 
                                                              >> 0x1aU))) 
                                                         | (0x2eU 
                                                            == 
                                                            (vlSelf->__Vfunc_is_store__65__i 
                                                             >> 0x1aU)));
                                                }(), (IData)(vlSelf->__Vfunc_is_store__65__Vfuncout)))
                                              : ((1U 
                                                  & (~ 
                                                     (vlSelf->__Vfunc_writes_gpr__55__i 
                                                      >> 0x1cU))) 
                                                 && (1U 
                                                     & ((0x8000000U 
                                                         & vlSelf->__Vfunc_writes_gpr__55__i)
                                                         ? 
                                                        (vlSelf->__Vfunc_writes_gpr__55__i 
                                                         >> 0x1aU)
                                                         : 
                                                        ((0x4000000U 
                                                          & vlSelf->__Vfunc_writes_gpr__55__i)
                                                          ? 
                                                         ((0x10U 
                                                           == 
                                                           (0x1fU 
                                                            & (vlSelf->__Vfunc_writes_gpr__55__i 
                                                               >> 0x10U))) 
                                                          | (0x11U 
                                                             == 
                                                             (0x1fU 
                                                              & (vlSelf->__Vfunc_writes_gpr__55__i 
                                                                 >> 0x10U))))
                                                          : 
                                                         ((1U 
                                                           & (vlSelf->__Vfunc_writes_gpr__55__i 
                                                              >> 5U)) 
                                                          || (1U 
                                                              & ((0x10U 
                                                                  & vlSelf->__Vfunc_writes_gpr__55__i)
                                                                  ? 
                                                                 ((8U 
                                                                   & vlSelf->__Vfunc_writes_gpr__55__i)
                                                                   ? 
                                                                  (vlSelf->__Vfunc_writes_gpr__55__i 
                                                                   >> 2U)
                                                                   : 
                                                                  ((1U 
                                                                    & (vlSelf->__Vfunc_writes_gpr__55__i 
                                                                       >> 2U)) 
                                                                   || (1U 
                                                                       & (~ vlSelf->__Vfunc_writes_gpr__55__i))))
                                                                  : 
                                                                 ((1U 
                                                                   & (~ 
                                                                      (vlSelf->__Vfunc_writes_gpr__55__i 
                                                                       >> 3U))) 
                                                                  || (1U 
                                                                      & ((4U 
                                                                          & vlSelf->__Vfunc_writes_gpr__55__i)
                                                                          ? 
                                                                         (vlSelf->__Vfunc_writes_gpr__55__i 
                                                                          >> 1U)
                                                                          : 
                                                                         ((1U 
                                                                           & (vlSelf->__Vfunc_writes_gpr__55__i 
                                                                              >> 1U)) 
                                                                          || (1U 
                                                                              & vlSelf->__Vfunc_writes_gpr__55__i))))))))))))))));
                    }(), (IData)(vlSelf->__Vfunc_writes_gpr__55__Vfuncout))) 
                                       & (0U != (IData)(vlSelf->__PVT__me_wa))) 
                                      & (((IData)(__PVT__id_needs_rs) 
                                          & ((0x1fU 
                                              & (vlSelf->__PVT__id_insn 
                                                 >> 0x15U)) 
                                             == (IData)(vlSelf->__PVT__me_wa))) 
                                         | ((IData)(__PVT__id_needs_rt) 
                                            & ((0x1fU 
                                                & (vlSelf->__PVT__id_insn 
                                                   >> 0x10U)) 
                                               == (IData)(vlSelf->__PVT__me_wa)))));
    vlSelf->__VdfgTmp_hc5c1aa8c__0 = ((IData)(__PVT__me_writes) 
                                      & (0U != (IData)(vlSelf->__PVT__me_wa)));
}

VL_INLINE_OPT void Vtb_board_r3900__Cz2___nba_comb__TOP__tb_board__cpu__cpu__1(Vtb_board_r3900__Cz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_board_r3900__Cz2___nba_comb__TOP__tb_board__cpu__cpu__1\n"); );
    // Body
    vlSelf->__PVT__fetch_ok = ((IData)(vlSelf->__PVT__ibus_req) 
                               & ((IData)(vlSymsp->TOP__tb_board__cpu.__PVT__cache__DOT__i_hit) 
                                  | ((IData)(vlSymsp->TOP__tb_board__cpu.cache__DOT____VdfgTmp_h6d079f16__0) 
                                     | (IData)(vlSymsp->TOP__tb_board__cpu.__PVT__cache__DOT__i_fill_fail))));
}
