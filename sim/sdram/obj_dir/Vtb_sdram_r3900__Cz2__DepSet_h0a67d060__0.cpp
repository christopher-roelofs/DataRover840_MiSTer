// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram_r3900__Cz2.h"

VL_INLINE_OPT void Vtb_sdram_r3900__Cz2___act_sequent__TOP__tb_sdram__cpu__cpu__0(Vtb_sdram_r3900__Cz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_sdram_r3900__Cz2___act_sequent__TOP__tb_sdram__cpu__cpu__0\n"); );
    // Body
    vlSelf->__PVT__me_exc_out_v = ((IData)(vlSelf->__PVT__me_exc_v) 
                                   | (IData)(vlSelf->__PVT__me_dbe));
}

VL_INLINE_OPT void Vtb_sdram_r3900__Cz2___act_sequent__TOP__tb_sdram__cpu__cpu__1(Vtb_sdram_r3900__Cz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_sdram_r3900__Cz2___act_sequent__TOP__tb_sdram__cpu__cpu__1\n"); );
    // Body
    vlSelf->__PVT__adv_ex = ((IData)(vlSelf->__PVT__adv_mem) 
                             & (~ ((~ ((IData)(vlSelf->__PVT__md_run) 
                                       & ((IData)(vlSelf->__PVT__md_skip) 
                                          | (0U == (IData)(vlSelf->__PVT__md_count))))) 
                                   & (IData)(vlSelf->__PVT__ex_is_div))));
    vlSelf->__PVT__adv_id = ((~ ((IData)(vlSelf->__PVT__load_use) 
                                 | ((IData)(vlSelf->__PVT__branch_load_use) 
                                    | ((IData)(vlSelf->__PVT__special_hazard) 
                                       | ((IData)(vlSelf->__PVT__cp0_write_inflight) 
                                          & (IData)(vlSelf->__PVT__id_v)))))) 
                             & (IData)(vlSelf->__PVT__adv_ex));
}

VL_INLINE_OPT void Vtb_sdram_r3900__Cz2___act_comb__TOP__tb_sdram__cpu__cpu__0(Vtb_sdram_r3900__Cz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_sdram_r3900__Cz2___act_comb__TOP__tb_sdram__cpu__cpu__0\n"); );
    // Body
    vlSelf->__PVT__exc_flush = ((IData)(vlSelf->__PVT__me_v) 
                                & ((IData)(vlSelf->__PVT__adv_mem) 
                                   & (IData)(vlSelf->__PVT__me_exc_out_v)));
    vlSelf->__PVT__ibus_req = ((~ (IData)(vlSelf->__PVT__exc_flush)) 
                               & (IData)(vlSelf->__PVT__adv_id));
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

VL_INLINE_OPT void Vtb_sdram_r3900__Cz2___nba_sequent__TOP__tb_sdram__cpu__cpu__1(Vtb_sdram_r3900__Cz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_sdram_r3900__Cz2___nba_sequent__TOP__tb_sdram__cpu__cpu__1\n"); );
    // Init
    IData/*31:0*/ __Vfunc_phys__0__Vfuncout;
    __Vfunc_phys__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_phys__0__va;
    __Vfunc_phys__0__va = 0;
    // Body
    __Vfunc_phys__0__va = vlSelf->__PVT__fpc;
    __Vfunc_phys__0__Vfuncout = (((0x80000000U <= __Vfunc_phys__0__va) 
                                  & (0xc0000000U > __Vfunc_phys__0__va))
                                  ? (0x1fffffffU & __Vfunc_phys__0__va)
                                  : __Vfunc_phys__0__va);
    vlSelf->__PVT__ibus_addr = __Vfunc_phys__0__Vfuncout;
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
    vlSelf->__PVT__store_word = ((vlSelf->__PVT__me_insn 
                                  >> 0x1fU) ? ((0x40000000U 
                                                & vlSelf->__PVT__me_insn)
                                                ? vlSelf->__PVT__me_rt
                                                : (
                                                   (0x20000000U 
                                                    & vlSelf->__PVT__me_insn)
                                                    ? 
                                                   ((0x10000000U 
                                                     & vlSelf->__PVT__me_insn)
                                                     ? 
                                                    ((0x8000000U 
                                                      & vlSelf->__PVT__me_insn)
                                                      ? 
                                                     ((0x4000000U 
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
                                                      : vlSelf->__PVT__me_rt)
                                                     : 
                                                    ((0x8000000U 
                                                      & vlSelf->__PVT__me_insn)
                                                      ? 
                                                     ((0x4000000U 
                                                       & vlSelf->__PVT__me_insn)
                                                       ? vlSelf->__PVT__me_rt
                                                       : 
                                                      ((2U 
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
                                                         : vlSelf->__PVT__me_rt)))
                                                      : 
                                                     ((0x4000000U 
                                                       & vlSelf->__PVT__me_insn)
                                                       ? 
                                                      ((vlSelf->__PVT__me_rt 
                                                        << 0x10U) 
                                                       | (0xffffU 
                                                          & vlSelf->__PVT__me_rt))
                                                       : 
                                                      ((vlSelf->__PVT__me_rt 
                                                        << 0x18U) 
                                                       | ((0xff0000U 
                                                           & (vlSelf->__PVT__me_rt 
                                                              << 0x10U)) 
                                                          | ((0xff00U 
                                                              & (vlSelf->__PVT__me_rt 
                                                                 << 8U)) 
                                                             | (0xffU 
                                                                & vlSelf->__PVT__me_rt)))))))
                                                    : vlSelf->__PVT__me_rt))
                                  : vlSelf->__PVT__me_rt);
}

VL_INLINE_OPT void Vtb_sdram_r3900__Cz2___nba_comb__TOP__tb_sdram__cpu__cpu__3(Vtb_sdram_r3900__Cz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_sdram_r3900__Cz2___nba_comb__TOP__tb_sdram__cpu__cpu__3\n"); );
    // Body
    vlSelf->__PVT__exc_flush = ((IData)(vlSelf->__PVT__me_v) 
                                & ((IData)(vlSelf->__PVT__adv_mem) 
                                   & (IData)(vlSelf->__PVT__me_exc_out_v)));
    vlSelf->__PVT__ibus_req = ((~ (IData)(vlSelf->__PVT__exc_flush)) 
                               & (IData)(vlSelf->__PVT__adv_id));
}

VL_INLINE_OPT void Vtb_sdram_r3900__Cz2___nba_comb__TOP__tb_sdram__cpu__cpu__4(Vtb_sdram_r3900__Cz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_sdram_r3900__Cz2___nba_comb__TOP__tb_sdram__cpu__cpu__4\n"); );
    // Body
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
