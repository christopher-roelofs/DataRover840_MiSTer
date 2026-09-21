// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_board.h for the primary calling header

#include "Vtb_board__pch.h"
#include "Vtb_board__Syms.h"
#include "Vtb_board_r3900_cached__Cz1.h"

VL_INLINE_OPT void Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__0(Vtb_board_r3900_cached__Cz1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__0\n"); );
    // Init
    CData/*0:0*/ cache__DOT____VdfgTmp_he0beb801__0;
    cache__DOT____VdfgTmp_he0beb801__0 = 0;
    // Body
    vlSelf->__PVT__drd = ((IData)(vlSelf->__PVT__cache__DOT__d_read_hit)
                           ? vlSelf->__PVT__cache__DOT__dram_eff
                           : vlSymsp->TOP__tb_board.__PVT__drd);
    vlSelf->cache__DOT____VdfgTmp_h619d70f7__0 = ((IData)(vlSelf->__PVT__cache__DOT__d_thru) 
                                                  & (IData)(vlSymsp->TOP__tb_board.__PVT__dack));
    cache__DOT____VdfgTmp_he0beb801__0 = ((1U == (IData)(vlSelf->__PVT__cache__DOT__dstate)) 
                                          & (IData)(vlSymsp->TOP__tb_board.__PVT__dack));
    vlSelf->__PVT__cache__DOT__d_fill_beat = ((~ (IData)(vlSymsp->TOP__tb_board.__PVT__derr)) 
                                              & (IData)(cache__DOT____VdfgTmp_he0beb801__0));
    vlSelf->__PVT__cache__DOT__d_fill_fail = ((IData)(cache__DOT____VdfgTmp_he0beb801__0) 
                                              & (IData)(vlSymsp->TOP__tb_board.__PVT__derr));
    vlSelf->__PVT__derr = (((IData)(vlSelf->cache__DOT____VdfgTmp_h619d70f7__0) 
                            & (IData)(vlSymsp->TOP__tb_board.__PVT__derr)) 
                           | (IData)(vlSelf->__PVT__cache__DOT__d_fill_fail));
    vlSelf->__PVT__dack = ((IData)(vlSelf->__PVT__cache__DOT__d_read_hit) 
                           | ((IData)(vlSelf->cache__DOT____VdfgTmp_h619d70f7__0) 
                              | (IData)(vlSelf->__PVT__cache__DOT__d_fill_fail)));
}

VL_INLINE_OPT void Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__1(Vtb_board_r3900_cached__Cz1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__1\n"); );
    // Body
    vlSelf->__PVT__cache__DOT__itag_wd = (0x100000U 
                                          | (vlSelf->__PVT__cache__DOT__iline 
                                             >> 0xcU));
    vlSelf->__PVT__cache__DOT__dtag_wd = (0x400000U 
                                          | (vlSelf->__PVT__cache__DOT__dline 
                                             >> 0xaU));
    vlSelf->__PVT__cache__DOT__itag_wa = (0xffU & (vlSelf->__PVT__cache__DOT__iline 
                                                   >> 4U));
    vlSelf->__PVT__cache__DOT__dtag_we = 0U;
    vlSelf->__PVT__cache__DOT__dtag_wa = (0x3fU & (vlSelf->__PVT__cache__DOT__dline 
                                                   >> 4U));
    if ((0x100U & (IData)(vlSelf->__PVT__cache__DOT__init_cnt))) {
        if (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__cache_op) {
            vlSelf->__PVT__cache__DOT__itag_wd = 0U;
            vlSelf->__PVT__cache__DOT__dtag_wd = 0U;
            vlSelf->__PVT__cache__DOT__itag_wa = (0xffU 
                                                  & (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__cache_op_addr 
                                                     >> 4U));
            vlSelf->__PVT__cache__DOT__dtag_we = 1U;
            vlSelf->__PVT__cache__DOT__dtag_wa = (0x3fU 
                                                  & (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__cache_op_addr 
                                                     >> 4U));
        } else if (((IData)(vlSelf->__PVT__cache__DOT__d_fill_beat) 
                    & (3U == (IData)(vlSelf->__PVT__cache__DOT__dcnt)))) {
            vlSelf->__PVT__cache__DOT__dtag_we = 1U;
        }
    } else {
        vlSelf->__PVT__cache__DOT__itag_wd = 0U;
        vlSelf->__PVT__cache__DOT__dtag_wd = 0U;
        vlSelf->__PVT__cache__DOT__itag_wa = (0xffU 
                                              & (IData)(vlSelf->__PVT__cache__DOT__init_cnt));
        vlSelf->__PVT__cache__DOT__dtag_we = 1U;
        vlSelf->__PVT__cache__DOT__dtag_wa = (0x3fU 
                                              & (IData)(vlSelf->__PVT__cache__DOT__init_cnt));
    }
    vlSelf->cache__DOT____VdfgTmp_h6b597d1c__0 = ((IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__ibus_req) 
                                                  & ((IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__ibus_cached) 
                                                     & (IData)(vlSelf->__PVT__cache__DOT__i_idle)));
    vlSelf->__PVT__cache__DOT__i_thru = ((IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__ibus_req) 
                                         & ((~ (IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__ibus_cached)) 
                                            & (IData)(vlSelf->__PVT__cache__DOT__i_idle)));
    vlSelf->__PVT__cache__DOT__i_hit = ((IData)(vlSelf->cache__DOT____VdfgTmp_h6b597d1c__0) 
                                        & ((vlSelf->__PVT__cache__DOT__itagv_q 
                                            >> 0x14U) 
                                           & ((0xfffffU 
                                               & vlSelf->__PVT__cache__DOT__itagv_q) 
                                              == (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__ibus_addr 
                                                  >> 0xcU))));
    vlSelf->__PVT__imem_req = ((1U == (IData)(vlSelf->__PVT__cache__DOT__istate)) 
                               | (IData)(vlSelf->__PVT__cache__DOT__i_thru));
}

VL_INLINE_OPT void Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__2(Vtb_board_r3900_cached__Cz1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__2\n"); );
    // Init
    CData/*0:0*/ cache__DOT____VdfgTmp_h7d063475__0;
    cache__DOT____VdfgTmp_h7d063475__0 = 0;
    // Body
    vlSelf->cache__DOT____VdfgTmp_h6d079f16__0 = ((IData)(vlSelf->__PVT__cache__DOT__i_thru) 
                                                  & (IData)(vlSymsp->TOP__tb_board.__PVT__iack));
    cache__DOT____VdfgTmp_h7d063475__0 = ((1U == (IData)(vlSelf->__PVT__cache__DOT__istate)) 
                                          & (IData)(vlSymsp->TOP__tb_board.__PVT__iack));
    vlSelf->__PVT__cache__DOT__i_fill_beat = ((~ (IData)(vlSymsp->TOP__tb_board.__PVT__ierr)) 
                                              & (IData)(cache__DOT____VdfgTmp_h7d063475__0));
    vlSelf->__PVT__cache__DOT__i_fill_fail = ((IData)(cache__DOT____VdfgTmp_h7d063475__0) 
                                              & (IData)(vlSymsp->TOP__tb_board.__PVT__ierr));
    vlSelf->__PVT__cache__DOT__itag_we = 0U;
    if ((0x100U & (IData)(vlSelf->__PVT__cache__DOT__init_cnt))) {
        if (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__cache_op) {
            vlSelf->__PVT__cache__DOT__itag_we = 1U;
        } else if (((IData)(vlSelf->__PVT__cache__DOT__i_fill_beat) 
                    & (3U == (IData)(vlSelf->__PVT__cache__DOT__icnt)))) {
            vlSelf->__PVT__cache__DOT__itag_we = 1U;
        }
    } else {
        vlSelf->__PVT__cache__DOT__itag_we = 1U;
    }
}

VL_INLINE_OPT void Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__0(Vtb_board_r3900_cached__Cz1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__0\n"); );
    // Init
    CData/*7:0*/ __Vdlyvdim0__cache__DOT__itagv__v0;
    __Vdlyvdim0__cache__DOT__itagv__v0 = 0;
    IData/*20:0*/ __Vdlyvval__cache__DOT__itagv__v0;
    __Vdlyvval__cache__DOT__itagv__v0 = 0;
    CData/*0:0*/ __Vdlyvset__cache__DOT__itagv__v0;
    __Vdlyvset__cache__DOT__itagv__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__cache__DOT__ddata__v0;
    __Vdlyvdim0__cache__DOT__ddata__v0 = 0;
    IData/*31:0*/ __Vdlyvval__cache__DOT__ddata__v0;
    __Vdlyvval__cache__DOT__ddata__v0 = 0;
    CData/*0:0*/ __Vdlyvset__cache__DOT__ddata__v0;
    __Vdlyvset__cache__DOT__ddata__v0 = 0;
    CData/*5:0*/ __Vdlyvdim0__cache__DOT__dtagv__v0;
    __Vdlyvdim0__cache__DOT__dtagv__v0 = 0;
    IData/*22:0*/ __Vdlyvval__cache__DOT__dtagv__v0;
    __Vdlyvval__cache__DOT__dtagv__v0 = 0;
    CData/*0:0*/ __Vdlyvset__cache__DOT__dtagv__v0;
    __Vdlyvset__cache__DOT__dtagv__v0 = 0;
    // Body
    __Vdlyvset__cache__DOT__dtagv__v0 = 0U;
    __Vdlyvset__cache__DOT__itagv__v0 = 0U;
    vlSelf->__Vdlyvset__cache__DOT__idata__v0 = 0U;
    __Vdlyvset__cache__DOT__ddata__v0 = 0U;
    if (vlSelf->__PVT__cache__DOT__dtag_we) {
        __Vdlyvval__cache__DOT__dtagv__v0 = vlSelf->__PVT__cache__DOT__dtag_wd;
        __Vdlyvset__cache__DOT__dtagv__v0 = 1U;
        __Vdlyvdim0__cache__DOT__dtagv__v0 = vlSelf->__PVT__cache__DOT__dtag_wa;
    }
    if (vlSelf->__PVT__cache__DOT__itag_we) {
        __Vdlyvval__cache__DOT__itagv__v0 = vlSelf->__PVT__cache__DOT__itag_wd;
        __Vdlyvset__cache__DOT__itagv__v0 = 1U;
        __Vdlyvdim0__cache__DOT__itagv__v0 = vlSelf->__PVT__cache__DOT__itag_wa;
    }
    if (vlSelf->__PVT__cache__DOT__i_fill_beat) {
        vlSelf->__Vdlyvval__cache__DOT__idata__v0 = vlSymsp->TOP__tb_board.__PVT__ird;
        vlSelf->__Vdlyvset__cache__DOT__idata__v0 = 1U;
        vlSelf->__Vdlyvdim0__cache__DOT__idata__v0 
            = ((0x3fcU & (vlSelf->__PVT__cache__DOT__iline 
                          >> 2U)) | (IData)(vlSelf->__PVT__cache__DOT__icnt));
    }
    if (((IData)(vlSelf->__PVT__cache__DOT__d_fill_beat) 
         | (IData)(vlSelf->__PVT__cache__DOT__d_store_hit))) {
        if (vlSelf->__PVT__cache__DOT__d_fill_beat) {
            __Vdlyvval__cache__DOT__ddata__v0 = vlSymsp->TOP__tb_board.__PVT__drd;
            __Vdlyvdim0__cache__DOT__ddata__v0 = (0xffU 
                                                  & ((0xfcU 
                                                      & (vlSelf->__PVT__cache__DOT__dline 
                                                         >> 2U)) 
                                                     | (IData)(vlSelf->__PVT__cache__DOT__dcnt)));
        } else {
            __Vdlyvval__cache__DOT__ddata__v0 = vlSelf->__PVT__cache__DOT__d_merged;
            __Vdlyvdim0__cache__DOT__ddata__v0 = (0xffU 
                                                  & (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_addr 
                                                     >> 2U));
        }
        __Vdlyvset__cache__DOT__ddata__v0 = 1U;
    }
    vlSelf->__PVT__cache__DOT__itagv_q = vlSelf->__PVT__cache__DOT__itagv
        [(0xffU & (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__ibus_addr_la 
                   >> 4U))];
    vlSelf->__PVT__cache__DOT__dram_ra_q = (0xffU & 
                                            (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_addr_la 
                                             >> 2U));
    vlSelf->__PVT__cache__DOT__dram_q = vlSelf->__PVT__cache__DOT__ddata
        [(0xffU & (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_addr_la 
                   >> 2U))];
    vlSelf->__PVT__cache__DOT__dtagv_q = vlSelf->__PVT__cache__DOT__dtagv
        [(0x3fU & (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_addr_la 
                   >> 4U))];
    if (__Vdlyvset__cache__DOT__itagv__v0) {
        vlSelf->__PVT__cache__DOT__itagv[__Vdlyvdim0__cache__DOT__itagv__v0] 
            = __Vdlyvval__cache__DOT__itagv__v0;
    }
    if (__Vdlyvset__cache__DOT__ddata__v0) {
        vlSelf->__PVT__cache__DOT__ddata[__Vdlyvdim0__cache__DOT__ddata__v0] 
            = __Vdlyvval__cache__DOT__ddata__v0;
    }
    if (__Vdlyvset__cache__DOT__dtagv__v0) {
        vlSelf->__PVT__cache__DOT__dtagv[__Vdlyvdim0__cache__DOT__dtagv__v0] 
            = __Vdlyvval__cache__DOT__dtagv__v0;
    }
}

VL_INLINE_OPT void Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__1(Vtb_board_r3900_cached__Cz1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__1\n"); );
    // Init
    CData/*1:0*/ __Vdly__cache__DOT__dstate;
    __Vdly__cache__DOT__dstate = 0;
    CData/*1:0*/ __Vdly__cache__DOT__dcnt;
    __Vdly__cache__DOT__dcnt = 0;
    CData/*1:0*/ __Vdly__cache__DOT__istate;
    __Vdly__cache__DOT__istate = 0;
    CData/*1:0*/ __Vdly__cache__DOT__icnt;
    __Vdly__cache__DOT__icnt = 0;
    SData/*8:0*/ __Vdly__cache__DOT__init_cnt;
    __Vdly__cache__DOT__init_cnt = 0;
    // Body
    __Vdly__cache__DOT__icnt = vlSelf->__PVT__cache__DOT__icnt;
    __Vdly__cache__DOT__istate = vlSelf->__PVT__cache__DOT__istate;
    __Vdly__cache__DOT__init_cnt = vlSelf->__PVT__cache__DOT__init_cnt;
    __Vdly__cache__DOT__dcnt = vlSelf->__PVT__cache__DOT__dcnt;
    __Vdly__cache__DOT__dstate = vlSelf->__PVT__cache__DOT__dstate;
    if (vlSymsp->TOP.rst_n) {
        if ((1U & (~ (IData)(vlSelf->cache__DOT____VdfgTmp_h53db0a74__0)))) {
            __Vdly__cache__DOT__init_cnt = (0x1ffU 
                                            & ((IData)(1U) 
                                               + (IData)(vlSelf->__PVT__cache__DOT__init_cnt)));
        }
        if ((0x100U & (IData)(vlSelf->__PVT__cache__DOT__init_cnt))) {
            vlSelf->__PVT__cache__DOT__stf_d = vlSelf->__PVT__cache__DOT__d_merged;
            vlSelf->__PVT__cache__DOT__stf_v = vlSelf->__PVT__cache__DOT__d_store_hit;
            vlSelf->__PVT__cache__DOT__stf_a = (0xffU 
                                                & (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_addr 
                                                   >> 2U));
            if ((2U == (IData)(vlSelf->__PVT__cache__DOT__istate))) {
                __Vdly__cache__DOT__istate = 0U;
            } else if ((0U == (IData)(vlSelf->__PVT__cache__DOT__istate))) {
                if (vlSelf->__PVT__cache__DOT__i_hit) {
                    vlSelf->__PVT__ihit_count = ((IData)(1U) 
                                                 + vlSelf->__PVT__ihit_count);
                } else if (((~ (IData)(vlSelf->__PVT__cache__DOT__i_hit)) 
                            & (IData)(vlSelf->cache__DOT____VdfgTmp_h6b597d1c__0))) {
                    vlSelf->__PVT__imiss_count = ((IData)(1U) 
                                                  + vlSelf->__PVT__imiss_count);
                    __Vdly__cache__DOT__istate = 1U;
                    __Vdly__cache__DOT__icnt = 0U;
                    vlSelf->__PVT__cache__DOT__iline 
                        = (0xfffffff0U & vlSymsp->TOP__tb_board__cpu__cpu.__PVT__ibus_addr);
                }
            } else if ((1U == (IData)(vlSelf->__PVT__cache__DOT__istate))) {
                if (vlSymsp->TOP__tb_board.__PVT__iack) {
                    if (vlSymsp->TOP__tb_board.__PVT__ierr) {
                        __Vdly__cache__DOT__istate = 0U;
                    } else {
                        __Vdly__cache__DOT__icnt = 
                            (3U & ((IData)(1U) + (IData)(vlSelf->__PVT__cache__DOT__icnt)));
                        if ((3U == (IData)(vlSelf->__PVT__cache__DOT__icnt))) {
                            __Vdly__cache__DOT__istate = 2U;
                        }
                    }
                }
            } else {
                __Vdly__cache__DOT__istate = 0U;
            }
            if ((2U == (IData)(vlSelf->__PVT__cache__DOT__dstate))) {
                __Vdly__cache__DOT__dstate = 0U;
            } else if ((0U == (IData)(vlSelf->__PVT__cache__DOT__dstate))) {
                if ((1U & (~ ((IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__me_needs_mem) 
                              & (IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_we))))) {
                    if (vlSelf->__PVT__cache__DOT__d_read_hit) {
                        vlSelf->__PVT__dhit_count = 
                            ((IData)(1U) + vlSelf->__PVT__dhit_count);
                    } else if (((IData)(vlSelf->cache__DOT____VdfgTmp_ha01f3fd2__0) 
                                & ((~ (IData)(vlSelf->__PVT__cache__DOT__d_read_hit)) 
                                   & (IData)(vlSelf->__PVT__cache__DOT__d_idle)))) {
                        vlSelf->__PVT__dmiss_count 
                            = ((IData)(1U) + vlSelf->__PVT__dmiss_count);
                        __Vdly__cache__DOT__dstate = 1U;
                        __Vdly__cache__DOT__dcnt = 0U;
                        vlSelf->__PVT__cache__DOT__dline 
                            = (0xfffffff0U & vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_addr);
                    }
                }
            } else if ((1U == (IData)(vlSelf->__PVT__cache__DOT__dstate))) {
                if (vlSymsp->TOP__tb_board.__PVT__dack) {
                    if (vlSymsp->TOP__tb_board.__PVT__derr) {
                        __Vdly__cache__DOT__dstate = 0U;
                    } else {
                        __Vdly__cache__DOT__dcnt = 
                            (3U & ((IData)(1U) + (IData)(vlSelf->__PVT__cache__DOT__dcnt)));
                        if ((3U == (IData)(vlSelf->__PVT__cache__DOT__dcnt))) {
                            __Vdly__cache__DOT__dstate = 2U;
                        }
                    }
                }
            } else {
                __Vdly__cache__DOT__dstate = 0U;
            }
        }
    } else {
        __Vdly__cache__DOT__init_cnt = 0U;
        vlSelf->__PVT__cache__DOT__stf_v = 0U;
        vlSelf->__PVT__imiss_count = 0U;
        __Vdly__cache__DOT__istate = 0U;
        __Vdly__cache__DOT__icnt = 0U;
        vlSelf->__PVT__ihit_count = 0U;
        vlSelf->__PVT__dmiss_count = 0U;
        __Vdly__cache__DOT__dstate = 0U;
        __Vdly__cache__DOT__dcnt = 0U;
        vlSelf->__PVT__dhit_count = 0U;
    }
    vlSelf->__PVT__cache__DOT__icnt = __Vdly__cache__DOT__icnt;
    vlSelf->__PVT__cache__DOT__istate = __Vdly__cache__DOT__istate;
    vlSelf->__PVT__cache__DOT__dcnt = __Vdly__cache__DOT__dcnt;
    vlSelf->__PVT__cache__DOT__init_cnt = __Vdly__cache__DOT__init_cnt;
    vlSelf->__PVT__cache__DOT__dstate = __Vdly__cache__DOT__dstate;
    vlSelf->cache__DOT____VdfgTmp_h53db0a74__0 = (1U 
                                                  & ((IData)(vlSelf->__PVT__cache__DOT__init_cnt) 
                                                     >> 8U));
    vlSelf->__PVT__cache__DOT__i_idle = (((IData)(vlSelf->__PVT__cache__DOT__init_cnt) 
                                          >> 8U) & 
                                         (0U == (IData)(vlSelf->__PVT__cache__DOT__istate)));
    vlSelf->__PVT__cache__DOT__d_idle = (((IData)(vlSelf->__PVT__cache__DOT__init_cnt) 
                                          >> 8U) & 
                                         (0U == (IData)(vlSelf->__PVT__cache__DOT__dstate)));
}

VL_INLINE_OPT void Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__2(Vtb_board_r3900_cached__Cz1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__2\n"); );
    // Body
    vlSelf->__PVT__imem_addr = ((1U == (IData)(vlSelf->__PVT__cache__DOT__istate))
                                 ? ((0xfffffff0U & vlSelf->__PVT__cache__DOT__iline) 
                                    | ((IData)(vlSelf->__PVT__cache__DOT__icnt) 
                                       << 2U)) : vlSymsp->TOP__tb_board__cpu__cpu.__PVT__ibus_addr);
    if ((1U == (IData)(vlSelf->__PVT__cache__DOT__dstate))) {
        vlSelf->__PVT__dmem_addr = ((0xfffffff0U & vlSelf->__PVT__cache__DOT__dline) 
                                    | ((IData)(vlSelf->__PVT__cache__DOT__dcnt) 
                                       << 2U));
        vlSelf->__PVT__dmem_be = 0xfU;
    } else {
        vlSelf->__PVT__dmem_addr = vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_addr;
        vlSelf->__PVT__dmem_be = vlSymsp->TOP__tb_board__cpu__cpu.__PVT__me_be;
    }
    vlSelf->__PVT__dmem_we = ((1U != (IData)(vlSelf->__PVT__cache__DOT__dstate)) 
                              & (IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_we));
    vlSelf->cache__DOT____VdfgTmp_ha01f3fd2__0 = ((IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__me_needs_mem) 
                                                  & ((~ (IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_we)) 
                                                     & (IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_cached)));
    vlSelf->__PVT__cache__DOT__d_thru = ((IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__me_needs_mem) 
                                         & ((IData)(vlSelf->__PVT__cache__DOT__d_idle) 
                                            & ((~ (IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_cached)) 
                                               | (IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_we))));
    vlSelf->__PVT__dmem_req = ((1U == (IData)(vlSelf->__PVT__cache__DOT__dstate)) 
                               | (IData)(vlSelf->__PVT__cache__DOT__d_thru));
}

VL_INLINE_OPT void Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__3(Vtb_board_r3900_cached__Cz1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__3\n"); );
    // Init
    CData/*0:0*/ cache__DOT____VdfgTmp_he0beb801__0;
    cache__DOT____VdfgTmp_he0beb801__0 = 0;
    // Body
    vlSelf->cache__DOT____VdfgTmp_h619d70f7__0 = ((IData)(vlSelf->__PVT__cache__DOT__d_thru) 
                                                  & (IData)(vlSymsp->TOP__tb_board.__PVT__dack));
    cache__DOT____VdfgTmp_he0beb801__0 = ((1U == (IData)(vlSelf->__PVT__cache__DOT__dstate)) 
                                          & (IData)(vlSymsp->TOP__tb_board.__PVT__dack));
    vlSelf->__PVT__cache__DOT__d_fill_beat = ((~ (IData)(vlSymsp->TOP__tb_board.__PVT__derr)) 
                                              & (IData)(cache__DOT____VdfgTmp_he0beb801__0));
    vlSelf->__PVT__cache__DOT__d_fill_fail = ((IData)(cache__DOT____VdfgTmp_he0beb801__0) 
                                              & (IData)(vlSymsp->TOP__tb_board.__PVT__derr));
    vlSelf->__PVT__derr = (((IData)(vlSelf->cache__DOT____VdfgTmp_h619d70f7__0) 
                            & (IData)(vlSymsp->TOP__tb_board.__PVT__derr)) 
                           | (IData)(vlSelf->__PVT__cache__DOT__d_fill_fail));
}

VL_INLINE_OPT void Vtb_board_r3900_cached__Cz1___nba_comb__TOP__tb_board__cpu__0(Vtb_board_r3900_cached__Cz1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_board_r3900_cached__Cz1___nba_comb__TOP__tb_board__cpu__0\n"); );
    // Init
    CData/*0:0*/ __PVT__cache__DOT__d_tag_match;
    __PVT__cache__DOT__d_tag_match = 0;
    // Body
    vlSelf->__PVT__cache__DOT__dram_eff = (((IData)(vlSelf->__PVT__cache__DOT__stf_v) 
                                            & ((IData)(vlSelf->__PVT__cache__DOT__dram_ra_q) 
                                               == (IData)(vlSelf->__PVT__cache__DOT__stf_a)))
                                            ? vlSelf->__PVT__cache__DOT__stf_d
                                            : vlSelf->__PVT__cache__DOT__dram_q);
    __PVT__cache__DOT__d_tag_match = ((IData)(vlSelf->__PVT__cache__DOT__d_idle) 
                                      & ((vlSelf->__PVT__cache__DOT__dtagv_q 
                                          >> 0x16U) 
                                         & ((0x3fffffU 
                                             & vlSelf->__PVT__cache__DOT__dtagv_q) 
                                            == (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_addr 
                                                >> 0xaU))));
    vlSelf->__PVT__cache__DOT__d_merged = ((((8U & (IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__me_be))
                                              ? (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__store_word 
                                                 >> 0x18U)
                                              : (vlSelf->__PVT__cache__DOT__dram_eff 
                                                 >> 0x18U)) 
                                            << 0x18U) 
                                           | ((0xff0000U 
                                               & (((4U 
                                                    & (IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__me_be))
                                                    ? 
                                                   (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__store_word 
                                                    >> 0x10U)
                                                    : 
                                                   (vlSelf->__PVT__cache__DOT__dram_eff 
                                                    >> 0x10U)) 
                                                  << 0x10U)) 
                                              | ((0xff00U 
                                                  & (((2U 
                                                       & (IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__me_be))
                                                       ? 
                                                      (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__store_word 
                                                       >> 8U)
                                                       : 
                                                      (vlSelf->__PVT__cache__DOT__dram_eff 
                                                       >> 8U)) 
                                                     << 8U)) 
                                                 | (0xffU 
                                                    & ((1U 
                                                        & (IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__me_be))
                                                        ? vlSymsp->TOP__tb_board__cpu__cpu.__PVT__store_word
                                                        : vlSelf->__PVT__cache__DOT__dram_eff)))));
    vlSelf->__PVT__cache__DOT__d_store_hit = ((IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__me_needs_mem) 
                                              & ((IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_we) 
                                                 & ((IData)(vlSymsp->TOP__tb_board__cpu__cpu.__PVT__dbus_cached) 
                                                    & (IData)(__PVT__cache__DOT__d_tag_match))));
    vlSelf->__PVT__cache__DOT__d_read_hit = ((IData)(vlSelf->cache__DOT____VdfgTmp_ha01f3fd2__0) 
                                             & (IData)(__PVT__cache__DOT__d_tag_match));
    vlSelf->__PVT__drd = ((IData)(vlSelf->__PVT__cache__DOT__d_read_hit)
                           ? vlSelf->__PVT__cache__DOT__dram_eff
                           : vlSymsp->TOP__tb_board.__PVT__drd);
    vlSelf->__PVT__dack = ((IData)(vlSelf->__PVT__cache__DOT__d_read_hit) 
                           | ((IData)(vlSelf->cache__DOT____VdfgTmp_h619d70f7__0) 
                              | (IData)(vlSelf->__PVT__cache__DOT__d_fill_fail)));
}

VL_INLINE_OPT void Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__4(Vtb_board_r3900_cached__Cz1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__4\n"); );
    // Body
    vlSelf->__PVT__cache__DOT__iram_q = vlSelf->__PVT__cache__DOT__idata
        [(0x3ffU & (vlSymsp->TOP__tb_board__cpu__cpu.__PVT__ibus_addr_la 
                    >> 2U))];
    if (vlSelf->__Vdlyvset__cache__DOT__idata__v0) {
        vlSelf->__PVT__cache__DOT__idata[vlSelf->__Vdlyvdim0__cache__DOT__idata__v0] 
            = vlSelf->__Vdlyvval__cache__DOT__idata__v0;
    }
}
