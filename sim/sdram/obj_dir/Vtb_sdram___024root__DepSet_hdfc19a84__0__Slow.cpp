// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram___024root.h"

VL_ATTR_COLD void Vtb_sdram___024root___eval_final(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sdram___024root___dump_triggers__stl(Vtb_sdram___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_sdram___024root___eval_phase__stl(Vtb_sdram___024root* vlSelf);

VL_ATTR_COLD void Vtb_sdram___024root___eval_settle(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_sdram___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb_sdram.sv", 11, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_sdram___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sdram___024root___dump_triggers__stl(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
    if ((2ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 1 is active: @([hybrid] tb_sdram.cpu.cpu.adv_mem)\n");
    }
    if ((4ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 2 is active: @([hybrid] tb_sdram.cpu.cpu.me_dbe)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_sdram___024root___eval_triggers__stl(Vtb_sdram___024root* vlSelf);
VL_ATTR_COLD void Vtb_sdram___024root___eval_stl(Vtb_sdram___024root* vlSelf);

VL_ATTR_COLD bool Vtb_sdram___024root___eval_phase__stl(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_sdram___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_sdram___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sdram___024root___dump_triggers__ico(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
    if ((2ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 1 is active: @([hybrid] tb_sdram.cpu.cpu.me_dbe)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sdram___024root___dump_triggers__act(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([hybrid] tb_sdram.cpu.cpu.adv_mem)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([hybrid] tb_sdram.cpu.cpu.me_dbe)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge clk or negedge rst_n)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sdram___024root___dump_triggers__nba(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([hybrid] tb_sdram.cpu.cpu.adv_mem)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([hybrid] tb_sdram.cpu.cpu.me_dbe)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge clk or negedge rst_n)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_sdram___024root___ctor_var_reset(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___ctor_var_reset\n"); );
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
    vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__adv_mem__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__me_dbe__0 = VL_RAND_RESET_I(1);
    vlSelf->__VstlDidInit = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__me_dbe__1 = VL_RAND_RESET_I(1);
    vlSelf->__VicoDidInit = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__adv_mem__1 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__me_dbe__2 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
}
