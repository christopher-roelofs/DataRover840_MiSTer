// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram__Syms.h"
#include "Vtb_sdram___024root.h"

VL_ATTR_COLD void Vtb_sdram_tb_sdram___eval_static__TOP__tb_sdram(Vtb_sdram_tb_sdram* vlSelf);

VL_ATTR_COLD void Vtb_sdram___024root___eval_static(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___eval_static\n"); );
    // Body
    Vtb_sdram_tb_sdram___eval_static__TOP__tb_sdram((&vlSymsp->TOP__tb_sdram));
}

VL_ATTR_COLD void Vtb_sdram_tb_sdram___eval_initial__TOP__tb_sdram(Vtb_sdram_tb_sdram* vlSelf);
VL_ATTR_COLD void Vtb_sdram_sdram_mt48lc16m16a2___eval_initial__TOP__tb_sdram__chip(Vtb_sdram_sdram_mt48lc16m16a2* vlSelf);

VL_ATTR_COLD void Vtb_sdram___024root___eval_initial(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___eval_initial\n"); );
    // Body
    Vtb_sdram_tb_sdram___eval_initial__TOP__tb_sdram((&vlSymsp->TOP__tb_sdram));
    Vtb_sdram_sdram_mt48lc16m16a2___eval_initial__TOP__tb_sdram__chip((&vlSymsp->TOP__tb_sdram__chip));
    vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__adv_mem__0 
        = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__adv_mem;
    vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__me_dbe__0 
        = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_dbe;
    vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__me_dbe__1 
        = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_dbe;
    vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__adv_mem__1 
        = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__adv_mem;
    vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__me_dbe__2 
        = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_dbe;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sdram___024root___dump_triggers__stl(Vtb_sdram___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_sdram___024root___eval_triggers__stl(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
    vlSelf->__VstlTriggered.set(1U, ((IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__adv_mem) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__adv_mem__0)));
    vlSelf->__VstlTriggered.set(2U, ((IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_dbe) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__me_dbe__0)));
    vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__adv_mem__0 
        = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__adv_mem;
    vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__me_dbe__0 
        = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_dbe;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VstlDidInit))))) {
        vlSelf->__VstlDidInit = 1U;
        vlSelf->__VstlTriggered.set(1U, 1U);
        vlSelf->__VstlTriggered.set(2U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_sdram___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtb_sdram___024root___stl_sequent__TOP__0(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->dbg_tx_bytes = vlSymsp->TOP__tb_sdram.dbg_tx_bytes;
    vlSelf->dbg_tx_data = vlSymsp->TOP__tb_sdram.dbg_tx_data;
    vlSelf->dbg_tx_stb = vlSymsp->TOP__tb_sdram.dbg_tx_stb;
    vlSelf->dbg_state = vlSymsp->TOP__tb_sdram.__PVT__adapter__DOT__state;
    vlSelf->dbg_start_kind = vlSymsp->TOP__tb_sdram.dbg_start_kind;
    vlSelf->dbg_start_addr = vlSymsp->TOP__tb_sdram.dbg_start_addr;
    vlSelf->dbg_start = vlSymsp->TOP__tb_sdram.dbg_start;
    vlSelf->dbg_ch2_req = vlSymsp->TOP__tb_sdram.__PVT__ch2_req;
    vlSelf->dbg_ch2_addr = vlSymsp->TOP__tb_sdram.__PVT__ch2_addr;
    vlSelf->dbg_last_a = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_last_a;
    vlSelf->dbg_last_row = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_last_row;
    vlSelf->dbg_last_col = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_last_col;
    vlSelf->dbg_last_index = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_last_index;
    vlSelf->dbg_ram_rdata = vlSymsp->TOP__tb_sdram.__PVT__ram_rdata;
    vlSelf->dbg_ram_ack = vlSymsp->TOP__tb_sdram.__PVT__ram_ack;
    vlSelf->dbg_violations = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_violations;
    vlSelf->dbg_max_refresh_gap = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_max_refresh_gap;
    vlSelf->dbg_refreshes = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_refreshes;
    vlSelf->dbg_writes = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_writes;
    vlSelf->dbg_reads = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_reads;
    vlSelf->dmiss_count = vlSymsp->TOP__tb_sdram__cpu.__PVT__dmiss_count;
    vlSelf->dhit_count = vlSymsp->TOP__tb_sdram__cpu.__PVT__dhit_count;
    vlSelf->imiss_count = vlSymsp->TOP__tb_sdram__cpu.__PVT__imiss_count;
    vlSelf->ihit_count = vlSymsp->TOP__tb_sdram__cpu.__PVT__ihit_count;
    vlSelf->retire_next_pc = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__rt_next_pc;
    vlSelf->retire_insn = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__rt_insn;
    vlSelf->retire_pc = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__rt_pc;
    vlSelf->retire_valid = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__rt_v;
}

VL_ATTR_COLD void Vtb_sdram___024root___stl_sequent__TOP__1(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___stl_sequent__TOP__1\n"); );
    // Body
    vlSelf->io_wdata = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word;
    vlSelf->dbg_cen = vlSymsp->TOP__tb_sdram.dbg_cen;
}

VL_ATTR_COLD void Vtb_sdram_sdram_mt48lc16m16a2___stl_sequent__TOP__tb_sdram__chip__0(Vtb_sdram_sdram_mt48lc16m16a2* vlSelf);
VL_ATTR_COLD void Vtb_sdram_r3900_cached__Cz1___stl_sequent__TOP__tb_sdram__cpu__0(Vtb_sdram_r3900_cached__Cz1* vlSelf);
VL_ATTR_COLD void Vtb_sdram_r3900__Cz2___stl_sequent__TOP__tb_sdram__cpu__cpu__0(Vtb_sdram_r3900__Cz2* vlSelf);
VL_ATTR_COLD void Vtb_sdram_tb_sdram___stl_sequent__TOP__tb_sdram__0(Vtb_sdram_tb_sdram* vlSelf);
VL_ATTR_COLD void Vtb_sdram_r3900_cached__Cz1___stl_sequent__TOP__tb_sdram__cpu__1(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__4(Vtb_sdram_tb_sdram* vlSelf);
void Vtb_sdram___024root___nba_sequent__TOP__3(Vtb_sdram___024root* vlSelf);
VL_ATTR_COLD void Vtb_sdram_r3900_cached__Cz1___stl_sequent__TOP__tb_sdram__cpu__2(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram_r3900__Cz2___nba_comb__TOP__tb_sdram__cpu__cpu__2(Vtb_sdram_r3900__Cz2* vlSelf);
void Vtb_sdram_r3900__Cz2___act_sequent__TOP__tb_sdram__cpu__cpu__0(Vtb_sdram_r3900__Cz2* vlSelf);
void Vtb_sdram_r3900__Cz2___act_sequent__TOP__tb_sdram__cpu__cpu__1(Vtb_sdram_r3900__Cz2* vlSelf);
void Vtb_sdram_r3900__Cz2___act_comb__TOP__tb_sdram__cpu__cpu__0(Vtb_sdram_r3900__Cz2* vlSelf);
void Vtb_sdram_r3900_cached__Cz1___act_comb__TOP__tb_sdram__cpu__0(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram___024root___act_comb__TOP__0(Vtb_sdram___024root* vlSelf);
void Vtb_sdram_tb_sdram___act_comb__TOP__tb_sdram__0(Vtb_sdram_tb_sdram* vlSelf);
void Vtb_sdram___024root___act_comb__TOP__1(Vtb_sdram___024root* vlSelf);
void Vtb_sdram_r3900_cached__Cz1___act_comb__TOP__tb_sdram__cpu__1(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram_r3900__Cz2___act_comb__TOP__tb_sdram__cpu__cpu__1(Vtb_sdram_r3900__Cz2* vlSelf);
void Vtb_sdram_r3900_cached__Cz1___ico_comb__TOP__tb_sdram__cpu__0(Vtb_sdram_r3900_cached__Cz1* vlSelf);

VL_ATTR_COLD void Vtb_sdram___024root___eval_stl(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_sdram___024root___stl_sequent__TOP__0(vlSelf);
        Vtb_sdram_sdram_mt48lc16m16a2___stl_sequent__TOP__tb_sdram__chip__0((&vlSymsp->TOP__tb_sdram__chip));
        Vtb_sdram_r3900_cached__Cz1___stl_sequent__TOP__tb_sdram__cpu__0((&vlSymsp->TOP__tb_sdram__cpu));
        Vtb_sdram_r3900__Cz2___stl_sequent__TOP__tb_sdram__cpu__cpu__0((&vlSymsp->TOP__tb_sdram__cpu__cpu));
        Vtb_sdram_tb_sdram___stl_sequent__TOP__tb_sdram__0((&vlSymsp->TOP__tb_sdram));
        Vtb_sdram___024root___stl_sequent__TOP__1(vlSelf);
        Vtb_sdram_r3900_cached__Cz1___stl_sequent__TOP__tb_sdram__cpu__1((&vlSymsp->TOP__tb_sdram__cpu));
        Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__4((&vlSymsp->TOP__tb_sdram));
        Vtb_sdram___024root___nba_sequent__TOP__3(vlSelf);
        Vtb_sdram_r3900_cached__Cz1___stl_sequent__TOP__tb_sdram__cpu__2((&vlSymsp->TOP__tb_sdram__cpu));
        Vtb_sdram_r3900__Cz2___nba_comb__TOP__tb_sdram__cpu__cpu__2((&vlSymsp->TOP__tb_sdram__cpu__cpu));
    }
    if ((5ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_sdram_r3900__Cz2___act_sequent__TOP__tb_sdram__cpu__cpu__0((&vlSymsp->TOP__tb_sdram__cpu__cpu));
    }
    if ((3ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_sdram_r3900__Cz2___act_sequent__TOP__tb_sdram__cpu__cpu__1((&vlSymsp->TOP__tb_sdram__cpu__cpu));
    }
    if ((7ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_sdram_r3900__Cz2___act_comb__TOP__tb_sdram__cpu__cpu__0((&vlSymsp->TOP__tb_sdram__cpu__cpu));
        Vtb_sdram_r3900_cached__Cz1___act_comb__TOP__tb_sdram__cpu__0((&vlSymsp->TOP__tb_sdram__cpu));
        Vtb_sdram___024root___act_comb__TOP__0(vlSelf);
        Vtb_sdram_tb_sdram___act_comb__TOP__tb_sdram__0((&vlSymsp->TOP__tb_sdram));
        Vtb_sdram___024root___act_comb__TOP__1(vlSelf);
        Vtb_sdram_r3900_cached__Cz1___act_comb__TOP__tb_sdram__cpu__1((&vlSymsp->TOP__tb_sdram__cpu));
        Vtb_sdram_r3900__Cz2___act_comb__TOP__tb_sdram__cpu__cpu__1((&vlSymsp->TOP__tb_sdram__cpu__cpu));
        Vtb_sdram_r3900_cached__Cz1___ico_comb__TOP__tb_sdram__cpu__0((&vlSymsp->TOP__tb_sdram__cpu));
    }
}
