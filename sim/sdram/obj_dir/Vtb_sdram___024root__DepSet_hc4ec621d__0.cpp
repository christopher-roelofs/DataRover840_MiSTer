// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram__Syms.h"
#include "Vtb_sdram___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sdram___024root___dump_triggers__ico(Vtb_sdram___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_sdram___024root___eval_triggers__ico(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
    vlSelf->__VicoTriggered.set(1U, ((IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_dbe) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__me_dbe__1)));
    vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__me_dbe__1 
        = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_dbe;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VicoDidInit))))) {
        vlSelf->__VicoDidInit = 1U;
        vlSelf->__VicoTriggered.set(1U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_sdram___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtb_sdram___024root___ico_sequent__TOP__0(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->dbg_cen = vlSymsp->TOP__tb_sdram.dbg_cen;
    vlSelf->dbg_iack = vlSymsp->TOP__tb_sdram.dbg_iack;
    vlSelf->dbg_dack = vlSymsp->TOP__tb_sdram.dbg_dack;
}

void Vtb_sdram_tb_sdram___ico_sequent__TOP__tb_sdram__0(Vtb_sdram_tb_sdram* vlSelf);
void Vtb_sdram_r3900__Cz2___ico_sequent__TOP__tb_sdram__cpu__cpu__0(Vtb_sdram_r3900__Cz2* vlSelf);
void Vtb_sdram_r3900_cached__Cz1___ico_sequent__TOP__tb_sdram__cpu__0(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram_r3900__Cz2___ico_sequent__TOP__tb_sdram__cpu__cpu__1(Vtb_sdram_r3900__Cz2* vlSelf);
void Vtb_sdram_r3900__Cz2___ico_comb__TOP__tb_sdram__cpu__cpu__0(Vtb_sdram_r3900__Cz2* vlSelf);
void Vtb_sdram_r3900_cached__Cz1___ico_comb__TOP__tb_sdram__cpu__0(Vtb_sdram_r3900_cached__Cz1* vlSelf);

void Vtb_sdram___024root___eval_ico(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vtb_sdram_tb_sdram___ico_sequent__TOP__tb_sdram__0((&vlSymsp->TOP__tb_sdram));
        Vtb_sdram_r3900__Cz2___ico_sequent__TOP__tb_sdram__cpu__cpu__0((&vlSymsp->TOP__tb_sdram__cpu__cpu));
        Vtb_sdram___024root___ico_sequent__TOP__0(vlSelf);
        Vtb_sdram_r3900_cached__Cz1___ico_sequent__TOP__tb_sdram__cpu__0((&vlSymsp->TOP__tb_sdram__cpu));
        Vtb_sdram_r3900__Cz2___ico_sequent__TOP__tb_sdram__cpu__cpu__1((&vlSymsp->TOP__tb_sdram__cpu__cpu));
    }
    if ((3ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vtb_sdram_r3900__Cz2___ico_comb__TOP__tb_sdram__cpu__cpu__0((&vlSymsp->TOP__tb_sdram__cpu__cpu));
        Vtb_sdram_r3900_cached__Cz1___ico_comb__TOP__tb_sdram__cpu__0((&vlSymsp->TOP__tb_sdram__cpu));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sdram___024root___dump_triggers__act(Vtb_sdram___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_sdram___024root___eval_triggers__act(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__adv_mem) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__adv_mem__1)));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_dbe) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__me_dbe__2)));
    vlSelf->__VactTriggered.set(2U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((~ (IData)(vlSelf->rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__rst_n__0))));
    vlSelf->__VactTriggered.set(3U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__adv_mem__1 
        = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__adv_mem;
    vlSelf->__Vtrigprevexpr___TOP__tb_sdram__cpu__cpu____PVT__me_dbe__2 
        = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__me_dbe;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(0U, 1U);
        vlSelf->__VactTriggered.set(1U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_sdram___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtb_sdram___024root___act_comb__TOP__0(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___act_comb__TOP__0\n"); );
    // Body
    vlSelf->dbg_ireq = vlSymsp->TOP__tb_sdram__cpu.__PVT__imem_req;
}

VL_INLINE_OPT void Vtb_sdram___024root___act_comb__TOP__1(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___act_comb__TOP__1\n"); );
    // Body
    vlSelf->io_req = vlSymsp->TOP__tb_sdram.io_req;
    vlSelf->dbg_ram_req = vlSymsp->TOP__tb_sdram.dbg_ram_req;
    vlSelf->dbg_iack = vlSymsp->TOP__tb_sdram.dbg_iack;
    vlSelf->dbg_dack = vlSymsp->TOP__tb_sdram.dbg_dack;
}

void Vtb_sdram_r3900__Cz2___act_sequent__TOP__tb_sdram__cpu__cpu__0(Vtb_sdram_r3900__Cz2* vlSelf);
void Vtb_sdram_r3900__Cz2___act_sequent__TOP__tb_sdram__cpu__cpu__1(Vtb_sdram_r3900__Cz2* vlSelf);
void Vtb_sdram_r3900__Cz2___act_comb__TOP__tb_sdram__cpu__cpu__0(Vtb_sdram_r3900__Cz2* vlSelf);
void Vtb_sdram_r3900_cached__Cz1___act_comb__TOP__tb_sdram__cpu__0(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram_tb_sdram___act_comb__TOP__tb_sdram__0(Vtb_sdram_tb_sdram* vlSelf);
void Vtb_sdram_r3900_cached__Cz1___act_comb__TOP__tb_sdram__cpu__1(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram_r3900__Cz2___act_comb__TOP__tb_sdram__cpu__cpu__1(Vtb_sdram_r3900__Cz2* vlSelf);

void Vtb_sdram___024root___eval_act(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___eval_act\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_sdram_r3900__Cz2___act_sequent__TOP__tb_sdram__cpu__cpu__0((&vlSymsp->TOP__tb_sdram__cpu__cpu));
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_sdram_r3900__Cz2___act_sequent__TOP__tb_sdram__cpu__cpu__1((&vlSymsp->TOP__tb_sdram__cpu__cpu));
    }
    if ((3ULL & vlSelf->__VactTriggered.word(0U))) {
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

VL_INLINE_OPT void Vtb_sdram___024root___nba_sequent__TOP__0(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->dbg_violations = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_violations;
    vlSelf->dbg_reads = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_reads;
    vlSelf->dbg_last_index = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_last_index;
    vlSelf->dbg_last_col = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_last_col;
    vlSelf->dbg_last_row = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_last_row;
    vlSelf->dbg_last_a = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_last_a;
    vlSelf->dbg_writes = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_writes;
    vlSelf->dbg_refreshes = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_refreshes;
    vlSelf->dbg_max_refresh_gap = vlSymsp->TOP__tb_sdram__chip.__PVT__dbg_max_refresh_gap;
}

VL_INLINE_OPT void Vtb_sdram___024root___nba_sequent__TOP__1(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->dbg_tx_bytes = vlSymsp->TOP__tb_sdram.dbg_tx_bytes;
    vlSelf->dbg_tx_stb = vlSymsp->TOP__tb_sdram.dbg_tx_stb;
    vlSelf->dbg_tx_data = vlSymsp->TOP__tb_sdram.dbg_tx_data;
    vlSelf->dbg_ch2_req = vlSymsp->TOP__tb_sdram.__PVT__ch2_req;
    vlSelf->dbg_start = vlSymsp->TOP__tb_sdram.dbg_start;
    vlSelf->dbg_start_addr = vlSymsp->TOP__tb_sdram.dbg_start_addr;
    vlSelf->dbg_start_kind = vlSymsp->TOP__tb_sdram.dbg_start_kind;
    vlSelf->dbg_ch2_addr = vlSymsp->TOP__tb_sdram.__PVT__ch2_addr;
    vlSelf->dbg_ram_ack = vlSymsp->TOP__tb_sdram.__PVT__ram_ack;
    vlSelf->dbg_ram_rdata = vlSymsp->TOP__tb_sdram.__PVT__ram_rdata;
    vlSelf->dbg_state = vlSymsp->TOP__tb_sdram.__PVT__adapter__DOT__state;
    vlSelf->ihit_count = vlSymsp->TOP__tb_sdram__cpu.__PVT__ihit_count;
    vlSelf->imiss_count = vlSymsp->TOP__tb_sdram__cpu.__PVT__imiss_count;
    vlSelf->dhit_count = vlSymsp->TOP__tb_sdram__cpu.__PVT__dhit_count;
    vlSelf->dmiss_count = vlSymsp->TOP__tb_sdram__cpu.__PVT__dmiss_count;
    vlSelf->retire_valid = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__rt_v;
    vlSelf->retire_pc = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__rt_pc;
    vlSelf->retire_insn = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__rt_insn;
    vlSelf->retire_next_pc = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__rt_next_pc;
    vlSelf->io_wdata = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word;
}

VL_INLINE_OPT void Vtb_sdram___024root___nba_sequent__TOP__2(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->dbg_dreq = vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_req;
    vlSelf->io_be = ((IData)(vlSymsp->TOP__tb_sdram.__PVT__board__DOT__d_wants_io)
                      ? (IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_be)
                      : 0xfU);
    vlSelf->io_we = vlSymsp->TOP__tb_sdram.io_we;
    vlSelf->io_addr = vlSymsp->TOP__tb_sdram.io_addr;
    vlSelf->dbg_ram_addr = vlSymsp->TOP__tb_sdram.dbg_ram_addr;
    vlSelf->dbg_ram_burst = vlSymsp->TOP__tb_sdram.dbg_ram_burst;
}

VL_INLINE_OPT void Vtb_sdram___024root___nba_sequent__TOP__3(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->dbg_cen = vlSymsp->TOP__tb_sdram.dbg_cen;
}

void Vtb_sdram_r3900_cached__Cz1___nba_sequent__TOP__tb_sdram__cpu__0(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__0(Vtb_sdram_tb_sdram* vlSelf);
void Vtb_sdram_sdram_mt48lc16m16a2___nba_sequent__TOP__tb_sdram__chip__0(Vtb_sdram_sdram_mt48lc16m16a2* vlSelf);
void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__1(Vtb_sdram_tb_sdram* vlSelf);
void Vtb_sdram_sdram_mt48lc16m16a2___nba_sequent__TOP__tb_sdram__chip__1(Vtb_sdram_sdram_mt48lc16m16a2* vlSelf);
void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__2(Vtb_sdram_tb_sdram* vlSelf);
void Vtb_sdram_r3900_cached__Cz1___nba_sequent__TOP__tb_sdram__cpu__1(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram_r3900__Cz2___nba_sequent__TOP__tb_sdram__cpu__cpu__0(Vtb_sdram_r3900__Cz2* vlSelf);
void Vtb_sdram_r3900_cached__Cz1___nba_sequent__TOP__tb_sdram__cpu__2(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__3(Vtb_sdram_tb_sdram* vlSelf);
void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__4(Vtb_sdram_tb_sdram* vlSelf);
void Vtb_sdram_r3900_cached__Cz1___nba_sequent__TOP__tb_sdram__cpu__3(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram_r3900_cached__Cz1___nba_comb__TOP__tb_sdram__cpu__0(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram_tb_sdram___nba_comb__TOP__tb_sdram__0(Vtb_sdram_tb_sdram* vlSelf);
void Vtb_sdram_r3900_cached__Cz1___nba_comb__TOP__tb_sdram__cpu__1(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram_r3900__Cz2___nba_comb__TOP__tb_sdram__cpu__cpu__0(Vtb_sdram_r3900__Cz2* vlSelf);
void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__5(Vtb_sdram_tb_sdram* vlSelf);
void Vtb_sdram_r3900__Cz2___nba_comb__TOP__tb_sdram__cpu__cpu__3(Vtb_sdram_r3900__Cz2* vlSelf);
void Vtb_sdram_r3900_cached__Cz1___nba_comb__TOP__tb_sdram__cpu__2(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram_tb_sdram___nba_comb__TOP__tb_sdram__1(Vtb_sdram_tb_sdram* vlSelf);
void Vtb_sdram_r3900_cached__Cz1___nba_comb__TOP__tb_sdram__cpu__3(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram_r3900__Cz2___nba_comb__TOP__tb_sdram__cpu__cpu__4(Vtb_sdram_r3900__Cz2* vlSelf);
void Vtb_sdram_r3900_cached__Cz1___nba_comb__TOP__tb_sdram__cpu__4(Vtb_sdram_r3900_cached__Cz1* vlSelf);
void Vtb_sdram_tb_sdram___nba_comb__TOP__tb_sdram__2(Vtb_sdram_tb_sdram* vlSelf);
void Vtb_sdram_r3900__Cz2___nba_comb__TOP__tb_sdram__cpu__cpu__5(Vtb_sdram_r3900__Cz2* vlSelf);

void Vtb_sdram___024root___eval_nba(Vtb_sdram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sdram___024root___eval_nba\n"); );
    // Body
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_sdram_r3900_cached__Cz1___nba_sequent__TOP__tb_sdram__cpu__0((&vlSymsp->TOP__tb_sdram__cpu));
        Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__0((&vlSymsp->TOP__tb_sdram));
        Vtb_sdram_sdram_mt48lc16m16a2___nba_sequent__TOP__tb_sdram__chip__0((&vlSymsp->TOP__tb_sdram__chip));
        Vtb_sdram___024root___nba_sequent__TOP__0(vlSelf);
        Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__1((&vlSymsp->TOP__tb_sdram));
        Vtb_sdram_sdram_mt48lc16m16a2___nba_sequent__TOP__tb_sdram__chip__1((&vlSymsp->TOP__tb_sdram__chip));
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__2((&vlSymsp->TOP__tb_sdram));
        Vtb_sdram_r3900_cached__Cz1___nba_sequent__TOP__tb_sdram__cpu__1((&vlSymsp->TOP__tb_sdram__cpu));
        Vtb_sdram_r3900__Cz2___nba_sequent__TOP__tb_sdram__cpu__cpu__0((&vlSymsp->TOP__tb_sdram__cpu__cpu));
        Vtb_sdram___024root___nba_sequent__TOP__1(vlSelf);
        Vtb_sdram_r3900_cached__Cz1___nba_sequent__TOP__tb_sdram__cpu__2((&vlSymsp->TOP__tb_sdram__cpu));
        Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__3((&vlSymsp->TOP__tb_sdram));
        Vtb_sdram___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__4((&vlSymsp->TOP__tb_sdram));
        Vtb_sdram_r3900_cached__Cz1___nba_sequent__TOP__tb_sdram__cpu__3((&vlSymsp->TOP__tb_sdram__cpu));
    }
    if ((0xcULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_sdram_r3900_cached__Cz1___nba_comb__TOP__tb_sdram__cpu__0((&vlSymsp->TOP__tb_sdram__cpu));
        Vtb_sdram_tb_sdram___nba_comb__TOP__tb_sdram__0((&vlSymsp->TOP__tb_sdram));
        Vtb_sdram_r3900_cached__Cz1___nba_comb__TOP__tb_sdram__cpu__1((&vlSymsp->TOP__tb_sdram__cpu));
        Vtb_sdram_r3900__Cz2___nba_comb__TOP__tb_sdram__cpu__cpu__0((&vlSymsp->TOP__tb_sdram__cpu__cpu));
    }
    if ((6ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_sdram_r3900__Cz2___act_sequent__TOP__tb_sdram__cpu__cpu__0((&vlSymsp->TOP__tb_sdram__cpu__cpu));
    }
    if ((5ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_sdram_r3900__Cz2___act_sequent__TOP__tb_sdram__cpu__cpu__1((&vlSymsp->TOP__tb_sdram__cpu__cpu));
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__5((&vlSymsp->TOP__tb_sdram));
        Vtb_sdram___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((7ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_sdram_r3900__Cz2___nba_comb__TOP__tb_sdram__cpu__cpu__3((&vlSymsp->TOP__tb_sdram__cpu__cpu));
        Vtb_sdram_r3900_cached__Cz1___nba_comb__TOP__tb_sdram__cpu__2((&vlSymsp->TOP__tb_sdram__cpu));
        Vtb_sdram___024root___act_comb__TOP__0(vlSelf);
        Vtb_sdram_tb_sdram___nba_comb__TOP__tb_sdram__1((&vlSymsp->TOP__tb_sdram));
        Vtb_sdram___024root___act_comb__TOP__1(vlSelf);
        Vtb_sdram_r3900_cached__Cz1___nba_comb__TOP__tb_sdram__cpu__3((&vlSymsp->TOP__tb_sdram__cpu));
    }
    if ((0xfULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_sdram_r3900__Cz2___nba_comb__TOP__tb_sdram__cpu__cpu__4((&vlSymsp->TOP__tb_sdram__cpu__cpu));
        Vtb_sdram_r3900_cached__Cz1___nba_comb__TOP__tb_sdram__cpu__4((&vlSymsp->TOP__tb_sdram__cpu));
        Vtb_sdram_tb_sdram___nba_comb__TOP__tb_sdram__2((&vlSymsp->TOP__tb_sdram));
        Vtb_sdram_r3900__Cz2___nba_comb__TOP__tb_sdram__cpu__cpu__5((&vlSymsp->TOP__tb_sdram__cpu__cpu));
        Vtb_sdram_r3900_cached__Cz1___ico_comb__TOP__tb_sdram__cpu__0((&vlSymsp->TOP__tb_sdram__cpu));
    }
}
