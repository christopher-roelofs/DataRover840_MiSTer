// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_board.h for the primary calling header

#include "Vtb_board__pch.h"
#include "Vtb_board__Syms.h"
#include "Vtb_board___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_board___024root___dump_triggers__ico(Vtb_board___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_board___024root___eval_triggers__ico(Vtb_board___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_board___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_board___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtb_board___024root___ico_sequent__TOP__0(Vtb_board___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_board___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->io_req = ((IData)(vlSymsp->TOP__tb_board.__PVT__board__DOT__d_wants_io) 
                      | (IData)(vlSymsp->TOP__tb_board.__PVT__board__DOT__i_wants_io));
    vlSelf->ram_req = vlSymsp->TOP__tb_board.ram_req;
}

void Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__0(Vtb_board_r3900__Cz2* vlSelf);
void Vtb_board_tb_board___ico_sequent__TOP__tb_board__0(Vtb_board_tb_board* vlSelf);
void Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__0(Vtb_board_r3900_cached__Cz1* vlSelf);
void Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__1(Vtb_board_r3900__Cz2* vlSelf);
void Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__1(Vtb_board_r3900_cached__Cz1* vlSelf);
void Vtb_board_tb_board___ico_sequent__TOP__tb_board__1(Vtb_board_tb_board* vlSelf);
void Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__2(Vtb_board_r3900_cached__Cz1* vlSelf);
void Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__2(Vtb_board_r3900__Cz2* vlSelf);

void Vtb_board___024root___eval_ico(Vtb_board___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_board___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__0((&vlSymsp->TOP__tb_board__cpu__cpu));
        Vtb_board_tb_board___ico_sequent__TOP__tb_board__0((&vlSymsp->TOP__tb_board));
        Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__0((&vlSymsp->TOP__tb_board__cpu));
        Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__1((&vlSymsp->TOP__tb_board__cpu__cpu));
        Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__1((&vlSymsp->TOP__tb_board__cpu));
        Vtb_board_tb_board___ico_sequent__TOP__tb_board__1((&vlSymsp->TOP__tb_board));
        Vtb_board___024root___ico_sequent__TOP__0(vlSelf);
        Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__2((&vlSymsp->TOP__tb_board__cpu));
        Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__2((&vlSymsp->TOP__tb_board__cpu__cpu));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_board___024root___dump_triggers__act(Vtb_board___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_board___024root___eval_triggers__act(Vtb_board___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_board___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((~ (IData)(vlSelf->rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__rst_n__0))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_board___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtb_board___024root___nba_sequent__TOP__0(Vtb_board___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_board___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->ihit_count = vlSymsp->TOP__tb_board__cpu.__PVT__ihit_count;
    vlSelf->imiss_count = vlSymsp->TOP__tb_board__cpu.__PVT__imiss_count;
    vlSelf->dhit_count = vlSymsp->TOP__tb_board__cpu.__PVT__dhit_count;
    vlSelf->dmiss_count = vlSymsp->TOP__tb_board__cpu.__PVT__dmiss_count;
    vlSelf->retire_valid = vlSymsp->TOP__tb_board__cpu__cpu.__PVT__rt_v;
    vlSelf->retire_pc = vlSymsp->TOP__tb_board__cpu__cpu.__PVT__rt_pc;
    vlSelf->retire_insn = vlSymsp->TOP__tb_board__cpu__cpu.__PVT__rt_insn;
    vlSelf->retire_next_pc = vlSymsp->TOP__tb_board__cpu__cpu.__PVT__rt_next_pc;
    vlSelf->io_wdata = vlSymsp->TOP__tb_board__cpu__cpu.__PVT__store_word;
    vlSelf->ram_wdata = vlSymsp->TOP__tb_board__cpu__cpu.__PVT__store_word;
}

VL_INLINE_OPT void Vtb_board___024root___nba_sequent__TOP__1(Vtb_board___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_board___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (vlSymsp->TOP__tb_board.__PVT__board__DOT__d_wants_io) {
        vlSelf->io_be = vlSymsp->TOP__tb_board__cpu.__PVT__dmem_be;
        vlSelf->io_addr = vlSymsp->TOP__tb_board__cpu.__PVT__dmem_addr;
        vlSelf->io_we = vlSymsp->TOP__tb_board__cpu.__PVT__dmem_we;
    } else {
        vlSelf->io_be = 0xfU;
        vlSelf->io_addr = vlSymsp->TOP__tb_board__cpu.__PVT__imem_addr;
        vlSelf->io_we = 0U;
    }
    if (vlSymsp->TOP__tb_board.__PVT__board__DOT__grant_d) {
        vlSelf->ram_be = vlSymsp->TOP__tb_board__cpu.__PVT__dmem_be;
        vlSelf->ram_burst = (1U == (IData)(vlSymsp->TOP__tb_board__cpu.__PVT__cache__DOT__dstate));
        vlSelf->ram_addr = (0x1ffffffU & vlSymsp->TOP__tb_board.__PVT__board__DOT__d_dec);
        vlSelf->ram_we = vlSymsp->TOP__tb_board__cpu.__PVT__dmem_we;
    } else {
        vlSelf->ram_be = 0xfU;
        vlSelf->ram_burst = (1U == (IData)(vlSymsp->TOP__tb_board__cpu.__PVT__cache__DOT__istate));
        vlSelf->ram_addr = (0x1ffffffU & vlSymsp->TOP__tb_board.__PVT__board__DOT__i_dec);
        vlSelf->ram_we = 0U;
    }
}

void Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__0(Vtb_board_r3900_cached__Cz1* vlSelf);
void Vtb_board_r3900__Cz2___nba_sequent__TOP__tb_board__cpu__cpu__0(Vtb_board_r3900__Cz2* vlSelf);
void Vtb_board_tb_board___nba_sequent__TOP__tb_board__0(Vtb_board_tb_board* vlSelf);
void Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__1(Vtb_board_r3900_cached__Cz1* vlSelf);
void Vtb_board_r3900__Cz2___nba_sequent__TOP__tb_board__cpu__cpu__1(Vtb_board_r3900__Cz2* vlSelf);
void Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__2(Vtb_board_r3900_cached__Cz1* vlSelf);
void Vtb_board_tb_board___nba_sequent__TOP__tb_board__1(Vtb_board_tb_board* vlSelf);
void Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__3(Vtb_board_r3900_cached__Cz1* vlSelf);
void Vtb_board_r3900_cached__Cz1___nba_comb__TOP__tb_board__cpu__0(Vtb_board_r3900_cached__Cz1* vlSelf);
void Vtb_board_r3900__Cz2___nba_comb__TOP__tb_board__cpu__cpu__1(Vtb_board_r3900__Cz2* vlSelf);
void Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__4(Vtb_board_r3900_cached__Cz1* vlSelf);
void Vtb_board_r3900__Cz2___nba_comb__TOP__tb_board__cpu__cpu__2(Vtb_board_r3900__Cz2* vlSelf);

void Vtb_board___024root___eval_nba(Vtb_board___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_board___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__0((&vlSymsp->TOP__tb_board__cpu));
        Vtb_board_r3900__Cz2___nba_sequent__TOP__tb_board__cpu__cpu__0((&vlSymsp->TOP__tb_board__cpu__cpu));
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_board_tb_board___nba_sequent__TOP__tb_board__0((&vlSymsp->TOP__tb_board));
        Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__1((&vlSymsp->TOP__tb_board__cpu));
        Vtb_board_r3900__Cz2___nba_sequent__TOP__tb_board__cpu__cpu__1((&vlSymsp->TOP__tb_board__cpu__cpu));
        Vtb_board___024root___nba_sequent__TOP__0(vlSelf);
        Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__2((&vlSymsp->TOP__tb_board__cpu));
        Vtb_board_tb_board___nba_sequent__TOP__tb_board__1((&vlSymsp->TOP__tb_board));
        Vtb_board___024root___nba_sequent__TOP__1(vlSelf);
        Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__3((&vlSymsp->TOP__tb_board__cpu));
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_board_r3900_cached__Cz1___nba_comb__TOP__tb_board__cpu__0((&vlSymsp->TOP__tb_board__cpu));
        Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__1((&vlSymsp->TOP__tb_board__cpu__cpu));
        Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__1((&vlSymsp->TOP__tb_board__cpu));
        Vtb_board_tb_board___ico_sequent__TOP__tb_board__1((&vlSymsp->TOP__tb_board));
        Vtb_board___024root___ico_sequent__TOP__0(vlSelf);
        Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__2((&vlSymsp->TOP__tb_board__cpu));
        Vtb_board_r3900__Cz2___nba_comb__TOP__tb_board__cpu__cpu__1((&vlSymsp->TOP__tb_board__cpu__cpu));
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_board_r3900_cached__Cz1___nba_sequent__TOP__tb_board__cpu__4((&vlSymsp->TOP__tb_board__cpu));
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_board_r3900__Cz2___nba_comb__TOP__tb_board__cpu__cpu__2((&vlSymsp->TOP__tb_board__cpu__cpu));
    }
}
