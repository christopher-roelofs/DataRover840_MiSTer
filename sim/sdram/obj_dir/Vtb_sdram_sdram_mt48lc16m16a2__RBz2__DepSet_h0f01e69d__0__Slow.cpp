// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram_sdram_mt48lc16m16a2__RBz2.h"

VL_ATTR_COLD void Vtb_sdram_sdram_mt48lc16m16a2__RBz2___eval_initial__TOP__tb_sdram__chip(Vtb_sdram_sdram_mt48lc16m16a2__RBz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_sdram_sdram_mt48lc16m16a2__RBz2___eval_initial__TOP__tb_sdram__chip\n"); );
    // Body
    vlSelf->__PVT__dbg_reads = 0U;
    vlSelf->__PVT__dbg_writes = 0U;
    vlSelf->__PVT__dbg_refreshes = 0U;
    vlSelf->__PVT__dbg_max_refresh_gap = 0U;
    vlSelf->__PVT__dbg_violations = 0U;
    vlSelf->__PVT__cycle = 0U;
    vlSelf->__PVT__since_refresh = 0U;
    vlSelf->__PVT__reports = 0U;
    vlSelf->__PVT__seen_refresh = 0U;
    vlSelf->__PVT__mode_loaded = 0U;
    vlSelf->__PVT__mode_cas = 2U;
    vlSelf->__PVT__mode_burst = 0U;
    vlSelf->__PVT__dq_oe = 0U;
    vlSelf->__PVT__dq_out = 0U;
    vlSelf->__PVT__bank_active[0U] = 0U;
    vlSelf->__PVT__bank_row[0U] = 0U;
    vlSelf->__PVT__bank_act_cyc[0U] = 0U;
    vlSelf->__PVT__bank_active[1U] = 0U;
    vlSelf->__PVT__bank_row[1U] = 0U;
    vlSelf->__PVT__bank_act_cyc[1U] = 0U;
    vlSelf->__PVT__bank_active[2U] = 0U;
    vlSelf->__PVT__bank_row[2U] = 0U;
    vlSelf->__PVT__bank_act_cyc[2U] = 0U;
    vlSelf->__PVT__bank_active[3U] = 0U;
    vlSelf->__PVT__bank_row[3U] = 0U;
    vlSelf->__PVT__bank_act_cyc[3U] = 0U;
    vlSelf->__PVT__rd_data[0U] = 0U;
    vlSelf->__PVT__rd_valid[0U] = 0U;
    vlSelf->__PVT__rd_data[1U] = 0U;
    vlSelf->__PVT__rd_valid[1U] = 0U;
    vlSelf->__PVT__rd_data[2U] = 0U;
    vlSelf->__PVT__rd_valid[2U] = 0U;
    vlSelf->__PVT__rd_data[3U] = 0U;
    vlSelf->__PVT__rd_valid[3U] = 0U;
    vlSelf->__PVT__rd_data[4U] = 0U;
    vlSelf->__PVT__rd_valid[4U] = 0U;
    vlSelf->__PVT__rd_data[5U] = 0U;
    vlSelf->__PVT__rd_valid[5U] = 0U;
    vlSelf->__PVT__rd_data[6U] = 0U;
    vlSelf->__PVT__rd_valid[6U] = 0U;
    vlSelf->__PVT__rd_data[7U] = 0U;
    vlSelf->__PVT__rd_valid[7U] = 0U;
}

VL_ATTR_COLD void Vtb_sdram_sdram_mt48lc16m16a2__RBz2___ctor_var_reset(Vtb_sdram_sdram_mt48lc16m16a2__RBz2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_sdram_sdram_mt48lc16m16a2__RBz2___ctor_var_reset\n"); );
    // Body
    vlSelf->__PVT__clk = VL_RAND_RESET_I(1);
    vlSelf->__PVT__rst = VL_RAND_RESET_I(1);
    vlSelf->__PVT__SDRAM_nCS = VL_RAND_RESET_I(1);
    vlSelf->__PVT__SDRAM_nRAS = VL_RAND_RESET_I(1);
    vlSelf->__PVT__SDRAM_nCAS = VL_RAND_RESET_I(1);
    vlSelf->__PVT__SDRAM_nWE = VL_RAND_RESET_I(1);
    vlSelf->__PVT__SDRAM_A = VL_RAND_RESET_I(13);
    vlSelf->__PVT__SDRAM_BA = VL_RAND_RESET_I(2);
    vlSelf->__PVT__SDRAM_DQML = VL_RAND_RESET_I(1);
    vlSelf->__PVT__SDRAM_DQMH = VL_RAND_RESET_I(1);
    vlSelf->__PVT__SDRAM_DQ_I = VL_RAND_RESET_I(16);
    vlSelf->__PVT__SDRAM_DQ_O = VL_RAND_RESET_I(16);
    vlSelf->__PVT__SDRAM_DQ_OE = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dbg_reads = VL_RAND_RESET_I(32);
    vlSelf->__PVT__dbg_writes = VL_RAND_RESET_I(32);
    vlSelf->__PVT__dbg_refreshes = VL_RAND_RESET_I(32);
    vlSelf->__PVT__dbg_max_refresh_gap = VL_RAND_RESET_I(16);
    vlSelf->__PVT__dbg_violations = VL_RAND_RESET_I(16);
    vlSelf->__PVT__dbg_last_index = VL_RAND_RESET_I(32);
    vlSelf->__PVT__dbg_last_col = VL_RAND_RESET_I(16);
    vlSelf->__PVT__dbg_last_row = VL_RAND_RESET_I(16);
    vlSelf->__PVT__dbg_last_a = VL_RAND_RESET_I(16);
    for (int __Vi0 = 0; __Vi0 < 16777216; ++__Vi0) {
        vlSelf->mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->__PVT__cmd = VL_RAND_RESET_I(4);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__PVT__bank_active[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__PVT__bank_row[__Vi0] = VL_RAND_RESET_I(13);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__PVT__bank_act_cyc[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__mode_loaded = VL_RAND_RESET_I(1);
    vlSelf->__PVT__mode_cas = VL_RAND_RESET_I(3);
    vlSelf->__PVT__mode_burst = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__rd_data[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__PVT__rd_valid[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->__PVT__dq_oe = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dq_out = VL_RAND_RESET_I(16);
    vlSelf->__PVT__cycle = VL_RAND_RESET_I(32);
    vlSelf->__PVT__since_refresh = VL_RAND_RESET_I(16);
    vlSelf->__PVT__reports = VL_RAND_RESET_I(16);
    vlSelf->__PVT__seen_refresh = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cmd_index = VL_RAND_RESET_I(24);
    vlSelf->__PVT__cl_slot = VL_RAND_RESET_I(3);
    vlSelf->__PVT__burst_len = VL_RAND_RESET_I(5);
    vlSelf->__PVT__burst_index__Vstatic__c = VL_RAND_RESET_I(9);
}
