// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_board.h for the primary calling header

#include "Vtb_board__pch.h"
#include "Vtb_board__Syms.h"
#include "Vtb_board_tb_board.h"

VL_INLINE_OPT void Vtb_board_tb_board___ico_sequent__TOP__tb_board__0(Vtb_board_tb_board* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_board_tb_board___ico_sequent__TOP__tb_board__0\n"); );
    // Init
    CData/*0:0*/ board__DOT____VdfgTmp_hab3cb56a__0;
    board__DOT____VdfgTmp_hab3cb56a__0 = 0;
    // Body
    if (vlSelf->__PVT__board__DOT__d_wants_io) {
        vlSelf->__PVT__drd = vlSymsp->TOP.io_rdata;
        board__DOT____VdfgTmp_hab3cb56a__0 = vlSymsp->TOP.io_ack;
    } else {
        vlSelf->__PVT__drd = vlSymsp->TOP.ram_rdata;
        board__DOT____VdfgTmp_hab3cb56a__0 = 0U;
    }
    vlSelf->__PVT__derr = ((IData)(vlSelf->board__DOT____VdfgTmp_h223955ac__0) 
                           | ((IData)(board__DOT____VdfgTmp_hab3cb56a__0) 
                              & (IData)(vlSymsp->TOP.io_err)));
    vlSelf->__PVT__dack = (((IData)(vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0) 
                            & (IData)(vlSymsp->TOP.ram_ack)) 
                           | ((IData)(board__DOT____VdfgTmp_hab3cb56a__0) 
                              | (IData)(vlSelf->board__DOT____VdfgTmp_h223955ac__0)));
}

VL_INLINE_OPT void Vtb_board_tb_board___ico_sequent__TOP__tb_board__1(Vtb_board_tb_board* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_board_tb_board___ico_sequent__TOP__tb_board__1\n"); );
    // Init
    CData/*0:0*/ board__DOT____VdfgTmp_h22b91ed1__0;
    board__DOT____VdfgTmp_h22b91ed1__0 = 0;
    CData/*0:0*/ board__DOT____VdfgTmp_h56676f03__0;
    board__DOT____VdfgTmp_h56676f03__0 = 0;
    CData/*0:0*/ board__DOT____VdfgTmp_h288a1ef5__0;
    board__DOT____VdfgTmp_h288a1ef5__0 = 0;
    CData/*0:0*/ board__DOT____VdfgTmp_h8306d34d__0;
    board__DOT____VdfgTmp_h8306d34d__0 = 0;
    // Body
    vlSelf->__PVT__board__DOT__i_wants_ram = ((IData)(vlSymsp->TOP__tb_board__cpu.__PVT__imem_req) 
                                              & (0U 
                                                 == 
                                                 (0x6000000U 
                                                  & vlSelf->__PVT__board__DOT__i_dec)));
    board__DOT____VdfgTmp_h288a1ef5__0 = ((IData)(vlSymsp->TOP__tb_board__cpu.__PVT__imem_req) 
                                          & (0x4000000U 
                                             == (0x6000000U 
                                                 & vlSelf->__PVT__board__DOT__i_dec)));
    vlSelf->__PVT__board__DOT__i_wants_io = ((IData)(vlSymsp->TOP__tb_board__cpu.__PVT__imem_req) 
                                             & (0x2000000U 
                                                == 
                                                (0x6000000U 
                                                 & vlSelf->__PVT__board__DOT__i_dec)));
    board__DOT____VdfgTmp_h22b91ed1__0 = (((2U == (IData)(vlSelf->__PVT__board__DOT__owner)) 
                                           | ((0U == (IData)(vlSelf->__PVT__board__DOT__owner)) 
                                              & ((~ (IData)(vlSelf->__PVT__board__DOT__d_wants_ram)) 
                                                 & (IData)(vlSelf->__PVT__board__DOT__i_wants_ram)))) 
                                          & (IData)(vlSelf->__PVT__board__DOT__i_wants_ram));
    board__DOT____VdfgTmp_h8306d34d__0 = ((~ (IData)(vlSelf->__PVT__board__DOT__d_wants_io)) 
                                          & (IData)(vlSelf->__PVT__board__DOT__i_wants_io));
    vlSelf->ram_req = ((IData)(vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0) 
                       | (IData)(board__DOT____VdfgTmp_h22b91ed1__0));
    if (board__DOT____VdfgTmp_h8306d34d__0) {
        vlSelf->__PVT__ird = vlSymsp->TOP.io_rdata;
        board__DOT____VdfgTmp_h56676f03__0 = vlSymsp->TOP.io_ack;
    } else {
        vlSelf->__PVT__ird = vlSymsp->TOP.ram_rdata;
        board__DOT____VdfgTmp_h56676f03__0 = 0U;
    }
    vlSelf->__PVT__ierr = ((IData)(board__DOT____VdfgTmp_h288a1ef5__0) 
                           | ((IData)(board__DOT____VdfgTmp_h56676f03__0) 
                              & (IData)(vlSymsp->TOP.io_err)));
    vlSelf->__PVT__iack = (((IData)(board__DOT____VdfgTmp_h22b91ed1__0) 
                            & (IData)(vlSymsp->TOP.ram_ack)) 
                           | ((IData)(board__DOT____VdfgTmp_h56676f03__0) 
                              | (IData)(board__DOT____VdfgTmp_h288a1ef5__0)));
}

extern const VlUnpacked<CData/*0:0*/, 64> Vtb_board__ConstPool__TABLE_ha033e788_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vtb_board__ConstPool__TABLE_h8b08f1f0_0;

VL_INLINE_OPT void Vtb_board_tb_board___nba_sequent__TOP__tb_board__0(Vtb_board_tb_board* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_board_tb_board___nba_sequent__TOP__tb_board__0\n"); );
    // Init
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = ((((~ (IData)(vlSymsp->TOP.ram_ack)) 
                      & (IData)(vlSelf->ram_req)) << 5U) 
                    | (((IData)(vlSelf->__PVT__board__DOT__i_wants_ram) 
                        << 4U) | (((IData)(vlSelf->__PVT__board__DOT__d_wants_ram) 
                                   << 3U) | (((IData)(vlSelf->__PVT__board__DOT__owner) 
                                              << 1U) 
                                             | (IData)(vlSymsp->TOP.rst_n)))));
    if (Vtb_board__ConstPool__TABLE_ha033e788_0[__Vtableidx1]) {
        vlSelf->__PVT__board__DOT__owner = Vtb_board__ConstPool__TABLE_h8b08f1f0_0
            [__Vtableidx1];
    }
}

VL_INLINE_OPT void Vtb_board_tb_board___nba_sequent__TOP__tb_board__1(Vtb_board_tb_board* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_board_tb_board___nba_sequent__TOP__tb_board__1\n"); );
    // Init
    CData/*1:0*/ __PVT__board__DOT__decode__Vstatic__t;
    __PVT__board__DOT__decode__Vstatic__t = 0;
    IData/*24:0*/ __PVT__board__DOT__decode__Vstatic__off;
    __PVT__board__DOT__decode__Vstatic__off = 0;
    IData/*31:0*/ __PVT__board__DOT__decode__Vstatic__rel;
    __PVT__board__DOT__decode__Vstatic__rel = 0;
    CData/*0:0*/ board__DOT____VdfgTmp_hab3cb56a__0;
    board__DOT____VdfgTmp_hab3cb56a__0 = 0;
    IData/*26:0*/ __Vfunc_board__DOT__decode__0__Vfuncout;
    __Vfunc_board__DOT__decode__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_board__DOT__decode__0__pa;
    __Vfunc_board__DOT__decode__0__pa = 0;
    IData/*26:0*/ __Vfunc_board__DOT__decode__1__Vfuncout;
    __Vfunc_board__DOT__decode__1__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_board__DOT__decode__1__pa;
    __Vfunc_board__DOT__decode__1__pa = 0;
    // Body
    __Vfunc_board__DOT__decode__0__pa = vlSymsp->TOP__tb_board__cpu.__PVT__imem_addr;
    __PVT__board__DOT__decode__Vstatic__t = 2U;
    __PVT__board__DOT__decode__Vstatic__off = 0U;
    __PVT__board__DOT__decode__Vstatic__rel = 0U;
    if ((0x3c00000U > __Vfunc_board__DOT__decode__0__pa)) {
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x800000U 
                                                   | (0x3fffffU 
                                                      & __Vfunc_board__DOT__decode__0__pa));
    } else if ((0x4400000U > __Vfunc_board__DOT__decode__0__pa)) {
        __PVT__board__DOT__decode__Vstatic__rel = (__Vfunc_board__DOT__decode__0__pa 
                                                   - (IData)(0x3c00000U));
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x7fffffU 
                                                   & __PVT__board__DOT__decode__Vstatic__rel);
    } else if (((0x13c00000U <= __Vfunc_board__DOT__decode__0__pa) 
                & (0x14400000U > __Vfunc_board__DOT__decode__0__pa))) {
        __PVT__board__DOT__decode__Vstatic__rel = (__Vfunc_board__DOT__decode__0__pa 
                                                   - (IData)(0x13c00000U));
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x7fffffU 
                                                   & __PVT__board__DOT__decode__Vstatic__rel);
    } else if (((0x1fc00000U <= __Vfunc_board__DOT__decode__0__pa) 
                & (0x20000000U > __Vfunc_board__DOT__decode__0__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x3fffffU 
                                                   & __Vfunc_board__DOT__decode__0__pa);
    } else if (((0x10400000U <= __Vfunc_board__DOT__decode__0__pa) 
                & (0x10c00400U > __Vfunc_board__DOT__decode__0__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    } else if (((0x8000000U <= __Vfunc_board__DOT__decode__0__pa) 
                & (0x10000000U > __Vfunc_board__DOT__decode__0__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    } else if (((0x24000000U <= __Vfunc_board__DOT__decode__0__pa) 
                & (0x2c000000U > __Vfunc_board__DOT__decode__0__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    } else if (((0xff000000U <= __Vfunc_board__DOT__decode__0__pa) 
                & (0xff001000U > __Vfunc_board__DOT__decode__0__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    }
    __Vfunc_board__DOT__decode__0__Vfuncout = (((IData)(__PVT__board__DOT__decode__Vstatic__t) 
                                                << 0x19U) 
                                               | __PVT__board__DOT__decode__Vstatic__off);
    vlSelf->__PVT__board__DOT__i_dec = __Vfunc_board__DOT__decode__0__Vfuncout;
    __Vfunc_board__DOT__decode__1__pa = vlSymsp->TOP__tb_board__cpu.__PVT__dmem_addr;
    __PVT__board__DOT__decode__Vstatic__t = 2U;
    __PVT__board__DOT__decode__Vstatic__off = 0U;
    __PVT__board__DOT__decode__Vstatic__rel = 0U;
    if ((0x3c00000U > __Vfunc_board__DOT__decode__1__pa)) {
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x800000U 
                                                   | (0x3fffffU 
                                                      & __Vfunc_board__DOT__decode__1__pa));
    } else if ((0x4400000U > __Vfunc_board__DOT__decode__1__pa)) {
        __PVT__board__DOT__decode__Vstatic__rel = (__Vfunc_board__DOT__decode__1__pa 
                                                   - (IData)(0x3c00000U));
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x7fffffU 
                                                   & __PVT__board__DOT__decode__Vstatic__rel);
    } else if (((0x13c00000U <= __Vfunc_board__DOT__decode__1__pa) 
                & (0x14400000U > __Vfunc_board__DOT__decode__1__pa))) {
        __PVT__board__DOT__decode__Vstatic__rel = (__Vfunc_board__DOT__decode__1__pa 
                                                   - (IData)(0x13c00000U));
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x7fffffU 
                                                   & __PVT__board__DOT__decode__Vstatic__rel);
    } else if (((0x1fc00000U <= __Vfunc_board__DOT__decode__1__pa) 
                & (0x20000000U > __Vfunc_board__DOT__decode__1__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x3fffffU 
                                                   & __Vfunc_board__DOT__decode__1__pa);
    } else if (((0x10400000U <= __Vfunc_board__DOT__decode__1__pa) 
                & (0x10c00400U > __Vfunc_board__DOT__decode__1__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    } else if (((0x8000000U <= __Vfunc_board__DOT__decode__1__pa) 
                & (0x10000000U > __Vfunc_board__DOT__decode__1__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    } else if (((0x24000000U <= __Vfunc_board__DOT__decode__1__pa) 
                & (0x2c000000U > __Vfunc_board__DOT__decode__1__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    } else if (((0xff000000U <= __Vfunc_board__DOT__decode__1__pa) 
                & (0xff001000U > __Vfunc_board__DOT__decode__1__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    }
    __Vfunc_board__DOT__decode__1__Vfuncout = (((IData)(__PVT__board__DOT__decode__Vstatic__t) 
                                                << 0x19U) 
                                               | __PVT__board__DOT__decode__Vstatic__off);
    vlSelf->__PVT__board__DOT__d_dec = __Vfunc_board__DOT__decode__1__Vfuncout;
    vlSelf->board__DOT____VdfgTmp_h223955ac__0 = ((IData)(vlSymsp->TOP__tb_board__cpu.__PVT__dmem_req) 
                                                  & (0x4000000U 
                                                     == 
                                                     (0x6000000U 
                                                      & vlSelf->__PVT__board__DOT__d_dec)));
    vlSelf->__PVT__board__DOT__d_wants_ram = ((IData)(vlSymsp->TOP__tb_board__cpu.__PVT__dmem_req) 
                                              & (0U 
                                                 == 
                                                 (0x6000000U 
                                                  & vlSelf->__PVT__board__DOT__d_dec)));
    vlSelf->__PVT__board__DOT__d_wants_io = ((IData)(vlSymsp->TOP__tb_board__cpu.__PVT__dmem_req) 
                                             & (0x2000000U 
                                                == 
                                                (0x6000000U 
                                                 & vlSelf->__PVT__board__DOT__d_dec)));
    vlSelf->__PVT__board__DOT__grant_d = ((1U == (IData)(vlSelf->__PVT__board__DOT__owner)) 
                                          | ((0U == (IData)(vlSelf->__PVT__board__DOT__owner)) 
                                             & (IData)(vlSelf->__PVT__board__DOT__d_wants_ram)));
    if (vlSelf->__PVT__board__DOT__d_wants_io) {
        vlSelf->__PVT__drd = vlSymsp->TOP.io_rdata;
        board__DOT____VdfgTmp_hab3cb56a__0 = vlSymsp->TOP.io_ack;
    } else {
        vlSelf->__PVT__drd = vlSymsp->TOP.ram_rdata;
        board__DOT____VdfgTmp_hab3cb56a__0 = 0U;
    }
    vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0 = ((IData)(vlSelf->__PVT__board__DOT__grant_d) 
                                                  & (IData)(vlSelf->__PVT__board__DOT__d_wants_ram));
    vlSelf->__PVT__derr = ((IData)(vlSelf->board__DOT____VdfgTmp_h223955ac__0) 
                           | ((IData)(board__DOT____VdfgTmp_hab3cb56a__0) 
                              & (IData)(vlSymsp->TOP.io_err)));
    vlSelf->__PVT__dack = (((IData)(vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0) 
                            & (IData)(vlSymsp->TOP.ram_ack)) 
                           | ((IData)(board__DOT____VdfgTmp_hab3cb56a__0) 
                              | (IData)(vlSelf->board__DOT____VdfgTmp_h223955ac__0)));
}
