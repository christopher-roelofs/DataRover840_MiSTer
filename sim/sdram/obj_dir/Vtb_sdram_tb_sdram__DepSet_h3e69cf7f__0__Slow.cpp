// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram__Syms.h"
#include "Vtb_sdram_tb_sdram.h"

VL_ATTR_COLD void Vtb_sdram_tb_sdram___stl_sequent__TOP__tb_sdram__0(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___stl_sequent__TOP__tb_sdram__0\n"); );
    // Body
    vlSelf->__PVT__dq_bus = ((IData)(vlSelf->__PVT__ctl_dq_oe)
                              ? (IData)(vlSelf->__PVT__ctl_dq_o)
                              : ((IData)(vlSymsp->TOP__tb_sdram__chip.__PVT__dq_oe)
                                  ? (IData)(vlSymsp->TOP__tb_sdram__chip.__PVT__dq_out)
                                  : 0xffffU));
    vlSelf->dbg_cen = ((1U >= (IData)(vlSymsp->TOP.clk_div)) 
                       | (0U == (IData)(vlSelf->__PVT__cdiv)));
    vlSelf->__PVT__io_err_mux = ((1U & (~ (IData)(vlSymsp->TOP.tx39_en))) 
                                 && (IData)(vlSymsp->TOP.io_err));
    vlSelf->__PVT__adapter__DOT__ack_taken = ((IData)(vlSelf->dbg_cen) 
                                              & (IData)(vlSelf->__PVT__ram_ack));
}

VL_ATTR_COLD void Vtb_sdram_tb_sdram___stl_sequent__TOP__tb_sdram__1(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___stl_sequent__TOP__tb_sdram__1\n"); );
    // Init
    CData/*1:0*/ __PVT__board__DOT__decode__Vstatic__t;
    __PVT__board__DOT__decode__Vstatic__t = 0;
    IData/*24:0*/ __PVT__board__DOT__decode__Vstatic__off;
    __PVT__board__DOT__decode__Vstatic__off = 0;
    IData/*31:0*/ __PVT__board__DOT__decode__Vstatic__rel;
    __PVT__board__DOT__decode__Vstatic__rel = 0;
    IData/*26:0*/ __PVT__board__DOT__d_dec;
    __PVT__board__DOT__d_dec = 0;
    CData/*0:0*/ __PVT__board__DOT__grant_d;
    __PVT__board__DOT__grant_d = 0;
    IData/*26:0*/ __Vfunc_board__DOT__decode__0__Vfuncout;
    __Vfunc_board__DOT__decode__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_board__DOT__decode__0__pa;
    __Vfunc_board__DOT__decode__0__pa = 0;
    IData/*26:0*/ __Vfunc_board__DOT__decode__1__Vfuncout;
    __Vfunc_board__DOT__decode__1__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_board__DOT__decode__1__pa;
    __Vfunc_board__DOT__decode__1__pa = 0;
    // Body
    __Vfunc_board__DOT__decode__0__pa = vlSymsp->TOP__tb_sdram__cpu.__PVT__imem_addr;
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
    __Vfunc_board__DOT__decode__1__pa = vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_addr;
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
    __PVT__board__DOT__d_dec = __Vfunc_board__DOT__decode__1__Vfuncout;
    vlSelf->board__DOT____VdfgTmp_h223955ac__0 = ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_req) 
                                                  & (0x4000000U 
                                                     == 
                                                     (0x6000000U 
                                                      & __PVT__board__DOT__d_dec)));
    vlSelf->__PVT__board__DOT__d_wants_ram = ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_req) 
                                              & (0U 
                                                 == 
                                                 (0x6000000U 
                                                  & __PVT__board__DOT__d_dec)));
    vlSelf->__PVT__board__DOT__d_wants_io = ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_req) 
                                             & (0x2000000U 
                                                == 
                                                (0x6000000U 
                                                 & __PVT__board__DOT__d_dec)));
    __PVT__board__DOT__grant_d = ((1U == (IData)(vlSelf->__PVT__board__DOT__owner)) 
                                  | ((0U == (IData)(vlSelf->__PVT__board__DOT__owner)) 
                                     & (IData)(vlSelf->__PVT__board__DOT__d_wants_ram)));
    vlSelf->io_we = ((IData)(vlSelf->__PVT__board__DOT__d_wants_io) 
                     & (IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_we));
    if (__PVT__board__DOT__grant_d) {
        vlSelf->__PVT__ram_we = vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_we;
        vlSelf->__PVT__ram_be = vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_be;
        vlSelf->dbg_ram_addr = (0x1ffffffU & __PVT__board__DOT__d_dec);
        vlSelf->dbg_ram_burst = (1U == (IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__cache__DOT__dstate));
    } else {
        vlSelf->__PVT__ram_we = 0U;
        vlSelf->__PVT__ram_be = 0xfU;
        vlSelf->dbg_ram_addr = (0x1ffffffU & vlSelf->__PVT__board__DOT__i_dec);
        vlSelf->dbg_ram_burst = (1U == (IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__cache__DOT__istate));
    }
    vlSelf->__PVT__adapter__DOT__merged = ((((1U & 
                                              ((~ (IData)(__PVT__board__DOT__grant_d)) 
                                               | ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_be) 
                                                  >> 3U)))
                                              ? (vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word 
                                                 >> 0x18U)
                                              : (vlSelf->__PVT__adapter__DOT__hold 
                                                 >> 0x18U)) 
                                            << 0x18U) 
                                           | ((0xff0000U 
                                               & (((1U 
                                                    & ((~ (IData)(__PVT__board__DOT__grant_d)) 
                                                       | ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_be) 
                                                          >> 2U)))
                                                    ? 
                                                   (vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word 
                                                    >> 0x10U)
                                                    : 
                                                   (vlSelf->__PVT__adapter__DOT__hold 
                                                    >> 0x10U)) 
                                                  << 0x10U)) 
                                              | ((0xff00U 
                                                  & (((1U 
                                                       & ((~ (IData)(__PVT__board__DOT__grant_d)) 
                                                          | ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_be) 
                                                             >> 1U)))
                                                       ? 
                                                      (vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word 
                                                       >> 8U)
                                                       : 
                                                      (vlSelf->__PVT__adapter__DOT__hold 
                                                       >> 8U)) 
                                                     << 8U)) 
                                                 | (0xffU 
                                                    & ((1U 
                                                        & ((~ (IData)(__PVT__board__DOT__grant_d)) 
                                                           | (IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_be)))
                                                        ? vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word
                                                        : vlSelf->__PVT__adapter__DOT__hold)))));
    vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0 = ((IData)(__PVT__board__DOT__grant_d) 
                                                  & (IData)(vlSelf->__PVT__board__DOT__d_wants_ram));
    vlSelf->io_addr = ((IData)(vlSelf->__PVT__board__DOT__d_wants_io)
                        ? vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_addr
                        : vlSymsp->TOP__tb_sdram__cpu.__PVT__imem_addr);
    vlSelf->__PVT__tx39__DOT__is_tx39 = ((0x10c00000U 
                                          <= vlSelf->io_addr) 
                                         & (0x10c00400U 
                                            > vlSelf->io_addr));
    vlSelf->__PVT__t_rdata = ((IData)(vlSelf->__PVT__tx39__DOT__is_tx39)
                               ? ((0x104U == (0xfffU 
                                              & vlSelf->io_addr))
                                   ? (0xa00U | vlSelf->__PVT__tx39__DOT__icu_status
                                      [1U]) : (((0x100U 
                                                 <= 
                                                 (0xfffU 
                                                  & vlSelf->io_addr)) 
                                                & (0x118U 
                                                   > 
                                                   (0xfffU 
                                                    & vlSelf->io_addr)))
                                                ? (
                                                   (5U 
                                                    >= 
                                                    (7U 
                                                     & (vlSelf->io_addr 
                                                        >> 2U)))
                                                    ? 
                                                   vlSelf->__PVT__tx39__DOT__icu_status
                                                   [
                                                   (7U 
                                                    & (vlSelf->io_addr 
                                                       >> 2U))]
                                                    : 0U)
                                                : (
                                                   (0x140U 
                                                    == 
                                                    (0xfffU 
                                                     & vlSelf->io_addr))
                                                    ? 
                                                   (0xffU 
                                                    & (IData)(
                                                              (vlSelf->__PVT__tx39__DOT__rtc 
                                                               >> 0x20U)))
                                                    : 
                                                   ((0x144U 
                                                     == 
                                                     (0xfffU 
                                                      & vlSelf->io_addr))
                                                     ? (IData)(vlSelf->__PVT__tx39__DOT__rtc)
                                                     : 
                                                    ((0x148U 
                                                      == 
                                                      (0xfffU 
                                                       & vlSelf->io_addr))
                                                      ? 
                                                     (0xffU 
                                                      & (IData)(
                                                                (vlSelf->__PVT__tx39__DOT__rtc_alarm 
                                                                 >> 0x20U)))
                                                      : 
                                                     ((0x14cU 
                                                       == 
                                                       (0xfffU 
                                                        & vlSelf->io_addr))
                                                       ? (IData)(vlSelf->__PVT__tx39__DOT__rtc_alarm)
                                                       : 
                                                      ((0x150U 
                                                        == 
                                                        (0xfffU 
                                                         & vlSelf->io_addr))
                                                        ? vlSelf->__PVT__tx39__DOT__t_ctrl
                                                        : 
                                                       ((0x154U 
                                                         == 
                                                         (0xfffU 
                                                          & vlSelf->io_addr))
                                                         ? vlSelf->__PVT__tx39__DOT__t_per
                                                         : 
                                                        ((0xe0U 
                                                          == 
                                                          (0xfffU 
                                                           & vlSelf->io_addr))
                                                          ? 
                                                         (0x20000000U 
                                                          | (0x7fffffffU 
                                                             & vlSelf->__PVT__tx39__DOT__rf_q))
                                                          : 
                                                         (((0x118U 
                                                            <= 
                                                            (0xfffU 
                                                             & vlSelf->io_addr)) 
                                                           & (0x130U 
                                                              > 
                                                              (0xfffU 
                                                               & vlSelf->io_addr)))
                                                           ? 
                                                          ((5U 
                                                            >= 
                                                            (7U 
                                                             & ((vlSelf->io_addr 
                                                                 >> 2U) 
                                                                - (IData)(6U))))
                                                            ? 
                                                           vlSelf->__PVT__tx39__DOT__icu_enable
                                                           [
                                                           (7U 
                                                            & ((vlSelf->io_addr 
                                                                >> 2U) 
                                                               - (IData)(6U)))]
                                                            : 0U)
                                                           : 
                                                          ((0xb0U 
                                                            == 
                                                            (0xfffU 
                                                             & vlSelf->io_addr))
                                                            ? 
                                                           (((vlSelf->__PVT__tx39__DOT__ua_ctrl1 
                                                              | ((1U 
                                                                  & vlSelf->__PVT__tx39__DOT__ua_ctrl1)
                                                                  ? 0x80000000U
                                                                  : 0U)) 
                                                             | ((IData)(vlSelf->__PVT__tx39__DOT__tx_busy)
                                                                 ? 0U
                                                                 : 0x40000000U)) 
                                                            | ((IData)(vlSelf->__PVT__tx39__DOT__ua_rx_full)
                                                                ? 0x10000000U
                                                                : 0U))
                                                            : 
                                                           ((0xb4U 
                                                             == 
                                                             (0xfffU 
                                                              & vlSelf->io_addr))
                                                             ? vlSelf->__PVT__tx39__DOT__ua_ctrl2
                                                             : 
                                                            ((0xc4U 
                                                              == 
                                                              (0xfffU 
                                                               & vlSelf->io_addr))
                                                              ? (IData)(vlSelf->__PVT__tx39__DOT__ua_rx)
                                                              : vlSelf->__PVT__tx39__DOT__rf_q)))))))))))))
                               : 0xffffffffU);
    vlSelf->__PVT__io_rdata_mux = ((IData)(vlSymsp->TOP.tx39_en)
                                    ? vlSelf->__PVT__t_rdata
                                    : vlSymsp->TOP.io_rdata);
    vlSelf->__PVT__drd = ((IData)(vlSelf->__PVT__board__DOT__d_wants_io)
                           ? vlSelf->__PVT__io_rdata_mux
                           : vlSelf->__PVT__ram_rdata);
}
