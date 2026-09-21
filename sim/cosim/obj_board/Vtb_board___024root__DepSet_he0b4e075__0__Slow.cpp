// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_board.h for the primary calling header

#include "Vtb_board__pch.h"
#include "Vtb_board__Syms.h"
#include "Vtb_board___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_board___024root___dump_triggers__stl(Vtb_board___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_board___024root___eval_triggers__stl(Vtb_board___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_board___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_board___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtb_board___024root___stl_sequent__TOP__0(Vtb_board___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_board___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->dmiss_count = vlSymsp->TOP__tb_board__cpu.__PVT__dmiss_count;
    vlSelf->dhit_count = vlSymsp->TOP__tb_board__cpu.__PVT__dhit_count;
    vlSelf->imiss_count = vlSymsp->TOP__tb_board__cpu.__PVT__imiss_count;
    vlSelf->ihit_count = vlSymsp->TOP__tb_board__cpu.__PVT__ihit_count;
    vlSelf->retire_next_pc = vlSymsp->TOP__tb_board__cpu__cpu.__PVT__rt_next_pc;
    vlSelf->retire_insn = vlSymsp->TOP__tb_board__cpu__cpu.__PVT__rt_insn;
    vlSelf->retire_pc = vlSymsp->TOP__tb_board__cpu__cpu.__PVT__rt_pc;
    vlSelf->retire_valid = vlSymsp->TOP__tb_board__cpu__cpu.__PVT__rt_v;
}

VL_ATTR_COLD void Vtb_board___024root___stl_sequent__TOP__1(Vtb_board___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_board___024root___stl_sequent__TOP__1\n"); );
    // Body
    vlSelf->io_wdata = vlSymsp->TOP__tb_board__cpu__cpu.__PVT__store_word;
    vlSelf->ram_wdata = vlSymsp->TOP__tb_board__cpu__cpu.__PVT__store_word;
}

VL_ATTR_COLD void Vtb_board_r3900_cached__Cz1___stl_sequent__TOP__tb_board__cpu__0(Vtb_board_r3900_cached__Cz1* vlSelf);
VL_ATTR_COLD void Vtb_board_r3900__Cz2___stl_sequent__TOP__tb_board__cpu__cpu__0(Vtb_board_r3900__Cz2* vlSelf);
VL_ATTR_COLD void Vtb_board_r3900_cached__Cz1___stl_sequent__TOP__tb_board__cpu__1(Vtb_board_r3900_cached__Cz1* vlSelf);
void Vtb_board_tb_board___nba_sequent__TOP__tb_board__1(Vtb_board_tb_board* vlSelf);
void Vtb_board___024root___nba_sequent__TOP__1(Vtb_board___024root* vlSelf);
void Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__0(Vtb_board_r3900_cached__Cz1* vlSelf);
void Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__1(Vtb_board_r3900__Cz2* vlSelf);
void Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__1(Vtb_board_r3900_cached__Cz1* vlSelf);
void Vtb_board_tb_board___ico_sequent__TOP__tb_board__1(Vtb_board_tb_board* vlSelf);
void Vtb_board___024root___ico_sequent__TOP__0(Vtb_board___024root* vlSelf);
void Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__2(Vtb_board_r3900_cached__Cz1* vlSelf);
void Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__2(Vtb_board_r3900__Cz2* vlSelf);

VL_ATTR_COLD void Vtb_board___024root___eval_stl(Vtb_board___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_board___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_board___024root___stl_sequent__TOP__0(vlSelf);
        Vtb_board_r3900_cached__Cz1___stl_sequent__TOP__tb_board__cpu__0((&vlSymsp->TOP__tb_board__cpu));
        Vtb_board_r3900__Cz2___stl_sequent__TOP__tb_board__cpu__cpu__0((&vlSymsp->TOP__tb_board__cpu__cpu));
        Vtb_board___024root___stl_sequent__TOP__1(vlSelf);
        Vtb_board_r3900_cached__Cz1___stl_sequent__TOP__tb_board__cpu__1((&vlSymsp->TOP__tb_board__cpu));
        Vtb_board_tb_board___nba_sequent__TOP__tb_board__1((&vlSymsp->TOP__tb_board));
        Vtb_board___024root___nba_sequent__TOP__1(vlSelf);
        Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__0((&vlSymsp->TOP__tb_board__cpu));
        Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__1((&vlSymsp->TOP__tb_board__cpu__cpu));
        Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__1((&vlSymsp->TOP__tb_board__cpu));
        Vtb_board_tb_board___ico_sequent__TOP__tb_board__1((&vlSymsp->TOP__tb_board));
        Vtb_board___024root___ico_sequent__TOP__0(vlSelf);
        Vtb_board_r3900_cached__Cz1___ico_sequent__TOP__tb_board__cpu__2((&vlSymsp->TOP__tb_board__cpu));
        Vtb_board_r3900__Cz2___ico_sequent__TOP__tb_board__cpu__cpu__2((&vlSymsp->TOP__tb_board__cpu__cpu));
    }
}
