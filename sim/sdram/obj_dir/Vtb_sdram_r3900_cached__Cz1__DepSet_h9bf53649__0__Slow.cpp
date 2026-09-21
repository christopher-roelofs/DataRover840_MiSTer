// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram__Syms.h"
#include "Vtb_sdram_r3900_cached__Cz1.h"

VL_ATTR_COLD void Vtb_sdram_r3900_cached__Cz1___stl_sequent__TOP__tb_sdram__cpu__1(Vtb_sdram_r3900_cached__Cz1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_sdram_r3900_cached__Cz1___stl_sequent__TOP__tb_sdram__cpu__1\n"); );
    // Init
    CData/*0:0*/ __PVT__cache__DOT__d_tag_match;
    __PVT__cache__DOT__d_tag_match = 0;
    // Body
    vlSelf->__PVT__cache__DOT__d_merged = ((((8U & (IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_be))
                                              ? (vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word 
                                                 >> 0x18U)
                                              : (vlSelf->__PVT__cache__DOT__dram_eff 
                                                 >> 0x18U)) 
                                            << 0x18U) 
                                           | ((0xff0000U 
                                               & (((4U 
                                                    & (IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_be))
                                                    ? 
                                                   (vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word 
                                                    >> 0x10U)
                                                    : 
                                                   (vlSelf->__PVT__cache__DOT__dram_eff 
                                                    >> 0x10U)) 
                                                  << 0x10U)) 
                                              | ((0xff00U 
                                                  & (((2U 
                                                       & (IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_be))
                                                       ? 
                                                      (vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word 
                                                       >> 8U)
                                                       : 
                                                      (vlSelf->__PVT__cache__DOT__dram_eff 
                                                       >> 8U)) 
                                                     << 8U)) 
                                                 | (0xffU 
                                                    & ((1U 
                                                        & (IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_be))
                                                        ? vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word
                                                        : vlSelf->__PVT__cache__DOT__dram_eff)))));
    if ((1U == (IData)(vlSelf->__PVT__cache__DOT__dstate))) {
        vlSelf->__PVT__dmem_be = 0xfU;
        vlSelf->__PVT__dmem_addr = ((0xfffffff0U & vlSelf->__PVT__cache__DOT__dline) 
                                    | ((IData)(vlSelf->__PVT__cache__DOT__dcnt) 
                                       << 2U));
    } else {
        vlSelf->__PVT__dmem_be = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_be;
        vlSelf->__PVT__dmem_addr = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__dbus_addr;
    }
    vlSelf->__PVT__imem_addr = ((1U == (IData)(vlSelf->__PVT__cache__DOT__istate))
                                 ? ((0xfffffff0U & vlSelf->__PVT__cache__DOT__iline) 
                                    | ((IData)(vlSelf->__PVT__cache__DOT__icnt) 
                                       << 2U)) : vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__ibus_addr);
    __PVT__cache__DOT__d_tag_match = ((IData)(vlSelf->__PVT__cache__DOT__d_idle) 
                                      & ((vlSelf->__PVT__cache__DOT__dtagv_q 
                                          >> 0x16U) 
                                         & ((0x3fffffU 
                                             & vlSelf->__PVT__cache__DOT__dtagv_q) 
                                            == (vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__dbus_addr 
                                                >> 0xaU))));
    vlSelf->__PVT__dmem_we = ((1U != (IData)(vlSelf->__PVT__cache__DOT__dstate)) 
                              & (IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__dbus_we));
    vlSelf->cache__DOT____VdfgTmp_ha01f3fd2__0 = ((IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_needs_mem) 
                                                  & ((~ (IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__dbus_we)) 
                                                     & (IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__dbus_cached)));
    vlSelf->__PVT__cache__DOT__d_thru = ((IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_needs_mem) 
                                         & ((IData)(vlSelf->__PVT__cache__DOT__d_idle) 
                                            & ((~ (IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__dbus_cached)) 
                                               | (IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__dbus_we))));
    vlSelf->__PVT__cache__DOT__d_store_hit = ((IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_needs_mem) 
                                              & ((IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__dbus_we) 
                                                 & ((IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__dbus_cached) 
                                                    & (IData)(__PVT__cache__DOT__d_tag_match))));
    vlSelf->__PVT__cache__DOT__d_read_hit = ((IData)(vlSelf->cache__DOT____VdfgTmp_ha01f3fd2__0) 
                                             & (IData)(__PVT__cache__DOT__d_tag_match));
    vlSelf->__PVT__dmem_req = ((1U == (IData)(vlSelf->__PVT__cache__DOT__dstate)) 
                               | (IData)(vlSelf->__PVT__cache__DOT__d_thru));
}
