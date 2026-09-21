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
}
