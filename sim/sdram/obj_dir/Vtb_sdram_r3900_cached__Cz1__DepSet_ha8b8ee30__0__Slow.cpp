// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram_r3900_cached__Cz1.h"

VL_ATTR_COLD void Vtb_sdram_r3900_cached__Cz1___stl_sequent__TOP__tb_sdram__cpu__0(Vtb_sdram_r3900_cached__Cz1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_sdram_r3900_cached__Cz1___stl_sequent__TOP__tb_sdram__cpu__0\n"); );
    // Body
    vlSelf->cache__DOT____VdfgTmp_h53db0a74__0 = (1U 
                                                  & ((IData)(vlSelf->__PVT__cache__DOT__init_cnt) 
                                                     >> 8U));
    vlSelf->__PVT__cache__DOT__i_idle = (((IData)(vlSelf->__PVT__cache__DOT__init_cnt) 
                                          >> 8U) & 
                                         (0U == (IData)(vlSelf->__PVT__cache__DOT__istate)));
    vlSelf->__PVT__cache__DOT__dram_eff = (((IData)(vlSelf->__PVT__cache__DOT__stf_v) 
                                            & ((IData)(vlSelf->__PVT__cache__DOT__dram_ra_q) 
                                               == (IData)(vlSelf->__PVT__cache__DOT__stf_a)))
                                            ? vlSelf->__PVT__cache__DOT__stf_d
                                            : vlSelf->__PVT__cache__DOT__dram_q);
    vlSelf->__PVT__cache__DOT__d_idle = (((IData)(vlSelf->__PVT__cache__DOT__init_cnt) 
                                          >> 8U) & 
                                         (0U == (IData)(vlSelf->__PVT__cache__DOT__dstate)));
}

VL_ATTR_COLD void Vtb_sdram_r3900_cached__Cz1___ctor_var_reset(Vtb_sdram_r3900_cached__Cz1* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_sdram_r3900_cached__Cz1___ctor_var_reset\n"); );
    // Body
    vlSelf->__PVT__clk = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cen = VL_RAND_RESET_I(1);
    vlSelf->__PVT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->__PVT__imem_addr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__imem_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__imem_burst = VL_RAND_RESET_I(1);
    vlSelf->__PVT__imem_ack = VL_RAND_RESET_I(1);
    vlSelf->__PVT__imem_rdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__imem_err = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dmem_addr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__dmem_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dmem_burst = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dmem_we = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dmem_be = VL_RAND_RESET_I(4);
    vlSelf->__PVT__dmem_wdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__dmem_ack = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dmem_rdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__dmem_err = VL_RAND_RESET_I(1);
    vlSelf->__PVT__irq_in = VL_RAND_RESET_I(6);
    vlSelf->__PVT__retire_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__retire_pc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__retire_insn = VL_RAND_RESET_I(32);
    vlSelf->__PVT__retire_next_pc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__ihit_count = VL_RAND_RESET_I(32);
    vlSelf->__PVT__imiss_count = VL_RAND_RESET_I(32);
    vlSelf->__PVT__dhit_count = VL_RAND_RESET_I(32);
    vlSelf->__PVT__dmiss_count = VL_RAND_RESET_I(32);
    vlSelf->__PVT__drd = VL_RAND_RESET_I(32);
    vlSelf->__PVT__dack = VL_RAND_RESET_I(1);
    vlSelf->__PVT__derr = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->__PVT__cache__DOT__idata[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cache__DOT__itagv[__Vi0] = VL_RAND_RESET_I(21);
    }
    vlSelf->__PVT__cache__DOT__istate = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cache__DOT__icnt = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cache__DOT__iline = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cache__DOT__itag_we = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cache__DOT__itag_wa = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cache__DOT__itag_wd = VL_RAND_RESET_I(21);
    vlSelf->__PVT__cache__DOT__iram_q = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cache__DOT__itagv_q = VL_RAND_RESET_I(21);
    vlSelf->__PVT__cache__DOT__init_cnt = VL_RAND_RESET_I(9);
    vlSelf->__PVT__cache__DOT__i_idle = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cache__DOT__i_hit = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cache__DOT__i_thru = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cache__DOT__i_fill_fail = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__cache__DOT__ddata[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->__PVT__cache__DOT__dtagv[__Vi0] = VL_RAND_RESET_I(23);
    }
    vlSelf->__PVT__cache__DOT__dstate = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cache__DOT__dcnt = VL_RAND_RESET_I(2);
    vlSelf->__PVT__cache__DOT__dline = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cache__DOT__dtag_we = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cache__DOT__dtag_wa = VL_RAND_RESET_I(6);
    vlSelf->__PVT__cache__DOT__dtag_wd = VL_RAND_RESET_I(23);
    vlSelf->__PVT__cache__DOT__dram_q = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cache__DOT__dtagv_q = VL_RAND_RESET_I(23);
    vlSelf->__PVT__cache__DOT__dram_ra_q = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cache__DOT__stf_v = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cache__DOT__stf_a = VL_RAND_RESET_I(8);
    vlSelf->__PVT__cache__DOT__stf_d = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cache__DOT__dram_eff = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cache__DOT__d_idle = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cache__DOT__d_read_hit = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cache__DOT__d_thru = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cache__DOT__d_merged = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cache__DOT__d_store_hit = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cache__DOT__d_fill_fail = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cache__DOT__i_fill_beat = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cache__DOT__d_fill_beat = VL_RAND_RESET_I(1);
    vlSelf->cache__DOT____VdfgTmp_h6d079f16__0 = 0;
    vlSelf->cache__DOT____VdfgTmp_h619d70f7__0 = 0;
    vlSelf->cache__DOT____VdfgTmp_h53db0a74__0 = 0;
    vlSelf->cache__DOT____VdfgTmp_h6b597d1c__0 = 0;
    vlSelf->cache__DOT____VdfgTmp_ha01f3fd2__0 = 0;
    vlSelf->__Vdly__cache__DOT__dstate = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__cache__DOT__dcnt = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__cache__DOT__istate = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__cache__DOT__icnt = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__cache__DOT__init_cnt = VL_RAND_RESET_I(9);
}
