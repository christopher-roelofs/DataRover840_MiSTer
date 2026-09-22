// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram_tb_sdram.h"

VL_ATTR_COLD void Vtb_sdram_tb_sdram___eval_static__TOP__tb_sdram(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___eval_static__TOP__tb_sdram\n"); );
    // Body
    vlSelf->__PVT__ctl__DOT__state = 0U;
    vlSelf->__PVT__ctl__DOT__refresh_count = 0x1483U;
}

VL_ATTR_COLD void Vtb_sdram_tb_sdram___eval_initial__TOP__tb_sdram(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___eval_initial__TOP__tb_sdram\n"); );
    // Init
    IData/*31:0*/ __PVT__tx39__DOT__rf_init__DOT__i;
    __PVT__tx39__DOT__rf_init__DOT__i = 0;
    // Body
    __PVT__tx39__DOT__rf_init__DOT__i = 0U;
    while (VL_GTS_III(32, 0x100U, __PVT__tx39__DOT__rf_init__DOT__i)) {
        vlSelf->__PVT__tx39__DOT__rf[(0xffU & __PVT__tx39__DOT__rf_init__DOT__i)] = 0U;
        __PVT__tx39__DOT__rf_init__DOT__i = ((IData)(1U) 
                                             + __PVT__tx39__DOT__rf_init__DOT__i);
    }
    vlSelf->__PVT__tx39__DOT__rf[0x71U] = 0x20000000U;
    vlSelf->__PVT__tx39__DOT__rf[0x32U] = 0x40000000U;
}

VL_ATTR_COLD void Vtb_sdram_tb_sdram___ctor_var_reset(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->clk_div = VL_RAND_RESET_I(8);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->io_addr = VL_RAND_RESET_I(32);
    vlSelf->io_req = VL_RAND_RESET_I(1);
    vlSelf->io_we = VL_RAND_RESET_I(1);
    vlSelf->io_be = VL_RAND_RESET_I(4);
    vlSelf->io_wdata = VL_RAND_RESET_I(32);
    vlSelf->io_ack = VL_RAND_RESET_I(1);
    vlSelf->io_rdata = VL_RAND_RESET_I(32);
    vlSelf->io_err = VL_RAND_RESET_I(1);
    vlSelf->irq_in = VL_RAND_RESET_I(6);
    vlSelf->retire_valid = VL_RAND_RESET_I(1);
    vlSelf->retire_pc = VL_RAND_RESET_I(32);
    vlSelf->retire_insn = VL_RAND_RESET_I(32);
    vlSelf->retire_next_pc = VL_RAND_RESET_I(32);
    vlSelf->ihit_count = VL_RAND_RESET_I(32);
    vlSelf->imiss_count = VL_RAND_RESET_I(32);
    vlSelf->dhit_count = VL_RAND_RESET_I(32);
    vlSelf->dmiss_count = VL_RAND_RESET_I(32);
    vlSelf->dbg_reads = VL_RAND_RESET_I(32);
    vlSelf->dbg_writes = VL_RAND_RESET_I(32);
    vlSelf->dbg_refreshes = VL_RAND_RESET_I(32);
    vlSelf->dbg_max_refresh_gap = VL_RAND_RESET_I(16);
    vlSelf->dbg_violations = VL_RAND_RESET_I(16);
    vlSelf->dbg_ram_addr = VL_RAND_RESET_I(25);
    vlSelf->dbg_ram_ack = VL_RAND_RESET_I(1);
    vlSelf->dbg_ram_req = VL_RAND_RESET_I(1);
    vlSelf->dbg_ram_burst = VL_RAND_RESET_I(1);
    vlSelf->dbg_ram_rdata = VL_RAND_RESET_I(32);
    vlSelf->dbg_last_index = VL_RAND_RESET_I(32);
    vlSelf->dbg_last_col = VL_RAND_RESET_I(16);
    vlSelf->dbg_last_row = VL_RAND_RESET_I(16);
    vlSelf->dbg_last_a = VL_RAND_RESET_I(16);
    vlSelf->dbg_ch2_addr = VL_RAND_RESET_I(26);
    vlSelf->dbg_ch2_req = VL_RAND_RESET_I(1);
    vlSelf->dbg_dack = VL_RAND_RESET_I(1);
    vlSelf->dbg_iack = VL_RAND_RESET_I(1);
    vlSelf->dbg_dreq = VL_RAND_RESET_I(1);
    vlSelf->dbg_ireq = VL_RAND_RESET_I(1);
    vlSelf->dbg_start = VL_RAND_RESET_I(1);
    vlSelf->dbg_start_addr = VL_RAND_RESET_I(25);
    vlSelf->dbg_start_kind = VL_RAND_RESET_I(2);
    vlSelf->dbg_state = VL_RAND_RESET_I(4);
    vlSelf->dbg_cen = VL_RAND_RESET_I(1);
    vlSelf->tx39_en = VL_RAND_RESET_I(1);
    vlSelf->dbg_tx_stb = VL_RAND_RESET_I(1);
    vlSelf->dbg_tx_data = VL_RAND_RESET_I(8);
    vlSelf->dbg_tx_bytes = VL_RAND_RESET_I(32);
    vlSelf->__PVT__cdiv = VL_RAND_RESET_I(8);
    vlSelf->__PVT__ird = VL_RAND_RESET_I(32);
    vlSelf->__PVT__drd = VL_RAND_RESET_I(32);
    vlSelf->__PVT__ierr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__derr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ram_we = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ram_ack = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ram_be = VL_RAND_RESET_I(4);
    vlSelf->__PVT__ram_rdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__t_rdata = VL_RAND_RESET_I(32);
    vlSelf->__Vcellinp__tx39__io_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__io_rdata_mux = VL_RAND_RESET_I(32);
    vlSelf->__PVT__io_err_mux = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ch1_addr = VL_RAND_RESET_I(26);
    vlSelf->__PVT__ch2_addr = VL_RAND_RESET_I(26);
    vlSelf->__PVT__ch1_dout = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__ch2_dout = VL_RAND_RESET_I(32);
    vlSelf->__PVT__ch2_din = VL_RAND_RESET_I(32);
    vlSelf->__PVT__ch1_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ch1_ready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ch2_req = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ch2_rnw = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ch2_ready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__SDRAM_A = VL_RAND_RESET_I(13);
    vlSelf->__PVT__SDRAM_BA = VL_RAND_RESET_I(2);
    vlSelf->__PVT__ctl_dq_o = VL_RAND_RESET_I(16);
    vlSelf->__PVT__ctl_dq_oe = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dq_bus = VL_RAND_RESET_I(16);
    vlSelf->__PVT__board__DOT__i_dec = VL_RAND_RESET_I(27);
    vlSelf->__PVT__board__DOT__owner = VL_RAND_RESET_I(2);
    vlSelf->__PVT__board__DOT__d_wants_ram = VL_RAND_RESET_I(1);
    vlSelf->__PVT__board__DOT__i_wants_ram = VL_RAND_RESET_I(1);
    vlSelf->__PVT__board__DOT__d_wants_io = VL_RAND_RESET_I(1);
    vlSelf->board__DOT____VdfgTmp_h22b91ed1__0 = 0;
    vlSelf->board__DOT____VdfgTmp_h288a1ef5__0 = 0;
    vlSelf->board__DOT____VdfgTmp_h8306d34d__0 = 0;
    vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0 = 0;
    vlSelf->board__DOT____VdfgTmp_h223955ac__0 = 0;
    vlSelf->__PVT__tx39__DOT__is_tx39 = VL_RAND_RESET_I(1);
    vlSelf->__PVT__tx39__DOT__served = VL_RAND_RESET_I(1);
    vlSelf->__PVT__tx39__DOT__io_start = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->__PVT__tx39__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__tx39__DOT__rf_q = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__PVT__tx39__DOT__icu_status[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__PVT__tx39__DOT__icu_enable[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__tx39__DOT__rtc = VL_RAND_RESET_Q(40);
    vlSelf->__PVT__tx39__DOT__rtc_acc = VL_RAND_RESET_I(32);
    vlSelf->__PVT__tx39__DOT__rtc_alarm = VL_RAND_RESET_Q(40);
    vlSelf->__PVT__tx39__DOT__t_ctrl = VL_RAND_RESET_I(32);
    vlSelf->__PVT__tx39__DOT__t_per = VL_RAND_RESET_I(32);
    vlSelf->__PVT__tx39__DOT__per_last = VL_RAND_RESET_Q(40);
    vlSelf->__PVT__tx39__DOT__ua_ctrl1 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__tx39__DOT__ua_ctrl2 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__tx39__DOT__ua_rx = VL_RAND_RESET_I(8);
    vlSelf->__PVT__tx39__DOT__ua_rx_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__tx39__DOT__tx_bit = VL_RAND_RESET_I(4);
    vlSelf->__PVT__tx39__DOT__tx_cnt = VL_RAND_RESET_I(20);
    vlSelf->__PVT__tx39__DOT__tx_busy = VL_RAND_RESET_I(1);
    vlSelf->__PVT__tx39__DOT__tx_hold_full = VL_RAND_RESET_I(1);
    vlSelf->__PVT__tx39__DOT__rx_shift = VL_RAND_RESET_I(8);
    vlSelf->__PVT__tx39__DOT__rx_bit = VL_RAND_RESET_I(4);
    vlSelf->__PVT__tx39__DOT__rx_cnt = VL_RAND_RESET_I(20);
    vlSelf->__PVT__tx39__DOT__rx_busy = VL_RAND_RESET_I(1);
    vlSelf->__PVT__tx39__DOT__rxd_sync = VL_RAND_RESET_I(3);
    vlSelf->tx39__DOT____Vlvbound_h2237671c__0 = VL_RAND_RESET_I(32);
    vlSelf->tx39__DOT____Vlvbound_hadcbb189__0 = VL_RAND_RESET_I(32);
    vlSelf->__PVT__adapter__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->__PVT__adapter__DOT__hold = VL_RAND_RESET_I(32);
    vlSelf->__PVT__adapter__DOT__line = VL_RAND_RESET_I(25);
    vlSelf->__PVT__adapter__DOT__merged = VL_RAND_RESET_I(32);
    vlSelf->__PVT__adapter__DOT__ack_taken = VL_RAND_RESET_I(1);
    vlSelf->__PVT__adapter__DOT__ch1_done = VL_RAND_RESET_I(1);
    vlSelf->__PVT__adapter__DOT__ch2_done = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ctl__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->__PVT__ctl__DOT__refresh_count = VL_RAND_RESET_I(14);
    vlSelf->__PVT__ctl__DOT__command = VL_RAND_RESET_I(3);
    vlSelf->__PVT__ctl__DOT__chip = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay1 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay2 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay3 = VL_RAND_RESET_I(7);
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__saved_wr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__cas_addr = VL_RAND_RESET_I(13);
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__saved_data = VL_RAND_RESET_I(32);
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__dq_reg = VL_RAND_RESET_I(16);
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch1_rq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch2_rq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch3_rq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch = VL_RAND_RESET_I(2);
    vlSelf->__Vdlyvdim0__tx39__DOT__rf__v0 = 0;
    vlSelf->__Vdlyvval__tx39__DOT__rf__v0 = VL_RAND_RESET_I(32);
    vlSelf->__Vdlyvset__tx39__DOT__rf__v0 = 0;
    vlSelf->__Vdly__ram_ack = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__adapter__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__ch1_ready = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__ch2_ready = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__ch1_dout = VL_RAND_RESET_Q(64);
    vlSelf->__Vdly__ch2_dout = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__ctl__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr = VL_RAND_RESET_I(13);
    vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__saved_data = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__saved_wr = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__ch = VL_RAND_RESET_I(2);
}
