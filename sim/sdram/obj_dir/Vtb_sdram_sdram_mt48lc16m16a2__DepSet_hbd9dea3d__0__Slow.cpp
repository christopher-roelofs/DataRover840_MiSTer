// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram__Syms.h"
#include "Vtb_sdram_sdram_mt48lc16m16a2.h"

VL_ATTR_COLD void Vtb_sdram_sdram_mt48lc16m16a2___stl_sequent__TOP__tb_sdram__chip__0(Vtb_sdram_sdram_mt48lc16m16a2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_sdram_sdram_mt48lc16m16a2___stl_sequent__TOP__tb_sdram__chip__0\n"); );
    // Body
    vlSelf->__PVT__cl_slot = ((2U <= (IData)(vlSelf->__PVT__mode_cas))
                               ? (7U & ((IData)(vlSelf->__PVT__mode_cas) 
                                        - (IData)(2U)))
                               : 0U);
    vlSelf->__PVT__burst_len = ((0U == (IData)(vlSelf->__PVT__mode_burst))
                                 ? 1U : ((1U == (IData)(vlSelf->__PVT__mode_burst))
                                          ? 2U : ((2U 
                                                   == (IData)(vlSelf->__PVT__mode_burst))
                                                   ? 4U
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelf->__PVT__mode_burst))
                                                    ? 8U
                                                    : 1U))));
    vlSelf->__PVT__cmd = (((IData)(vlSymsp->TOP__tb_sdram.__PVT__ctl__DOT__chip) 
                           << 3U) | (IData)(vlSymsp->TOP__tb_sdram.__PVT__ctl__DOT__command));
    vlSelf->__PVT__cmd_index = (((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA) 
                                 << 0x16U) | ((vlSelf->__PVT__bank_row
                                               [vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA] 
                                               << 9U) 
                                              | (0x1ffU 
                                                 & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A))));
}
