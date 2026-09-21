// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram_tb_sdram.h"

VL_INLINE_OPT void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__0(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__ch1_rq;
    __Vdly__ctl__DOT__unnamedblk1__DOT__ch1_rq = 0;
    CData/*0:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__ch2_rq;
    __Vdly__ctl__DOT__unnamedblk1__DOT__ch2_rq = 0;
    CData/*0:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__ch3_rq;
    __Vdly__ctl__DOT__unnamedblk1__DOT__ch3_rq = 0;
    SData/*13:0*/ __Vdly__ctl__DOT__refresh_count;
    __Vdly__ctl__DOT__refresh_count = 0;
    CData/*6:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay1;
    __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay1 = 0;
    CData/*6:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay2;
    __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay2 = 0;
    CData/*6:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay3;
    __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay3 = 0;
    // Body
    vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__ch 
        = vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch;
    vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__saved_wr 
        = vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__saved_wr;
    vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__saved_data 
        = vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__saved_data;
    vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr 
        = vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__cas_addr;
    vlSelf->__Vdly__ctl__DOT__state = vlSelf->__PVT__ctl__DOT__state;
    vlSelf->__Vdly__ch2_dout = vlSelf->__PVT__ch2_dout;
    vlSelf->__Vdly__ch1_dout = vlSelf->__PVT__ch1_dout;
    __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay3 
        = vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay3;
    __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay2 
        = vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay2;
    __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay1 
        = vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay1;
    __Vdly__ctl__DOT__refresh_count = vlSelf->__PVT__ctl__DOT__refresh_count;
    vlSelf->__Vdly__ch2_ready = vlSelf->__PVT__ch2_ready;
    vlSelf->__Vdly__ch1_ready = vlSelf->__PVT__ch1_ready;
    __Vdly__ctl__DOT__unnamedblk1__DOT__ch3_rq = vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch3_rq;
    __Vdly__ctl__DOT__unnamedblk1__DOT__ch2_rq = vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch2_rq;
    __Vdly__ctl__DOT__unnamedblk1__DOT__ch1_rq = vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch1_rq;
}

VL_INLINE_OPT void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__4(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__4\n"); );
    // Body
    vlSelf->__PVT__ch1_dout = vlSelf->__Vdly__ch1_dout;
    vlSelf->__PVT__ch1_ready = vlSelf->__Vdly__ch1_ready;
    vlSelf->__PVT__ch2_ready = vlSelf->__Vdly__ch2_ready;
    vlSelf->__PVT__ch2_dout = vlSelf->__Vdly__ch2_dout;
}
