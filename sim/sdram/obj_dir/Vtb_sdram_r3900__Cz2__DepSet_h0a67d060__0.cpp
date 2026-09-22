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
