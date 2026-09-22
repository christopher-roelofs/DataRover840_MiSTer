// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram__Syms.h"
#include "Vtb_sdram_r3900__Cz2.h"

VL_ATTR_COLD void Vtb_sdram_r3900__Cz2___stl_sequent__TOP__tb_sdram__cpu__cpu__0(Vtb_sdram_r3900__Cz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_sdram_r3900__Cz2___stl_sequent__TOP__tb_sdram__cpu__cpu__0\n"); );
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
    // Body
    vlSelf->__PVT__exc_vector = ((0x400000U & vlSelf->__PVT__cp0
                                  [0xcU]) ? 0xbfc00180U
                                  : 0x80000080U);
    vlSelf->__PVT__i_id = vlSelf->__PVT__id_insn;
    vlSelf->__PVT__i_ex = vlSelf->__PVT__ex_insn;
    vlSelf->__PVT__i_me = vlSelf->__PVT__me_insn;
    vlSelf->__PVT__md_shifted = VL_SHIFTL_QQI(64,64,32, vlSelf->__PVT__md_rq, 1U);
    vlSelf->__PVT__me_exc_out_ret = (1U & ((~ (IData)(vlSelf->__PVT__me_exc_v)) 
                                           | (IData)(vlSelf->__PVT__me_exc_ret)));
    vlSelf->__PVT__ex_exc_out_ret = (1U & ((~ (IData)(vlSelf->__PVT__ex_exc_v)) 
                                           | (IData)(vlSelf->__PVT__ex_exc_ret)));
    if (vlSelf->__PVT__me_exc_v) {
        vlSelf->__PVT__me_exc_out_code = vlSelf->__PVT__me_exc_code;
        vlSelf->__PVT__me_exc_out_bad = vlSelf->__PVT__me_exc_bad;
    } else {
        vlSelf->__PVT__me_exc_out_code = 7U;
        vlSelf->__PVT__me_exc_out_bad = vlSelf->__PVT__me_va;
    }
    vlSelf->__PVT__me_exc_out_badv = (1U & ((~ (IData)(vlSelf->__PVT__me_exc_v)) 
                                            | (IData)(vlSelf->__PVT__me_exc_bad_v)));
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
    __Vfunc_phys__80__va = vlSelf->__PVT__me_va;
    __Vfunc_phys__80__Vfuncout = (((0x80000000U <= __Vfunc_phys__80__va) 
                                   & (0xc0000000U > __Vfunc_phys__80__va))
                                   ? (0x1fffffffU & __Vfunc_phys__80__va)
                                   : __Vfunc_phys__80__va);
    vlSelf->__PVT__cache_op_addr = __Vfunc_phys__80__Vfuncout;
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
    vlSelf->__VdfgExtracted_h84f92045__0 = ((8U == 
                                             (0x3fU 
                                              & vlSelf->__PVT__id_insn)) 
                                            | (9U == 
                                               (0x3fU 
                                                & vlSelf->__PVT__id_insn)));
    vlSelf->__PVT__cause_live = ((0xffff03ffU & vlSelf->__PVT__cp0
                                  [0xdU]) | VL_SHIFTL_III(32,32,32, 
                                                          ((IData)(vlSymsp->TOP.tx39_en)
                                                            ? (IData)(vlSymsp->TOP__tb_sdram.__PVT__tx39__DOT__irq_r)
                                                            : (IData)(vlSymsp->TOP.irq_in)), 0xaU));
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
    __Vfunc_cacheable__1__va = vlSelf->__PVT__fpc;
    __Vfunc_cacheable__1__Vfuncout = (0xa0000000U > __Vfunc_cacheable__1__va);
    vlSelf->__PVT__ibus_cached = __Vfunc_cacheable__1__Vfuncout;
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
    __Vfunc_phys__0__va = vlSelf->__PVT__fpc;
    __Vfunc_phys__0__Vfuncout = (((0x80000000U <= __Vfunc_phys__0__va) 
                                  & (0xc0000000U > __Vfunc_phys__0__va))
                                  ? (0x1fffffffU & __Vfunc_phys__0__va)
                                  : __Vfunc_phys__0__va);
    vlSelf->__PVT__ibus_addr = __Vfunc_phys__0__Vfuncout;
    __Vfunc_cacheable__79__va = vlSelf->__PVT__me_va;
    __Vfunc_cacheable__79__Vfuncout = (0xa0000000U 
                                       > __Vfunc_cacheable__79__va);
    vlSelf->__PVT__dbus_cached = __Vfunc_cacheable__79__Vfuncout;
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
    vlSelf->__PVT__dbus_addr = (0xfffffffcU & ([&]() {
                vlSelf->__Vfunc_phys__78__va = vlSelf->__PVT__me_va;
                vlSelf->__Vfunc_phys__78__Vfuncout 
                    = (((0x80000000U <= vlSelf->__Vfunc_phys__78__va) 
                        & (0xc0000000U > vlSelf->__Vfunc_phys__78__va))
                        ? (0x1fffffffU & vlSelf->__Vfunc_phys__78__va)
                        : vlSelf->__Vfunc_phys__78__va);
            }(), vlSelf->__Vfunc_phys__78__Vfuncout));
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
