// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_board.h for the primary calling header

#include "Vtb_board__pch.h"
#include "Vtb_board_r3900__Cz2.h"

VL_INLINE_OPT void Vtb_board_r3900__Cz2___nba_comb__TOP__tb_board__cpu__cpu__2(Vtb_board_r3900__Cz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_board_r3900__Cz2___nba_comb__TOP__tb_board__cpu__cpu__2\n"); );
    // Body
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
