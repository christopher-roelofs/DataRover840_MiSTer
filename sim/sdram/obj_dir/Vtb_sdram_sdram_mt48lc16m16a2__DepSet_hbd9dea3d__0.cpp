// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram__Syms.h"
#include "Vtb_sdram_sdram_mt48lc16m16a2.h"

extern const VlWide<32>/*1023:0*/ Vtb_sdram__ConstPool__CONST_h66c1db22_0;
extern const VlWide<32>/*1023:0*/ Vtb_sdram__ConstPool__CONST_hfcf63cb2_0;
extern const VlWide<32>/*1023:0*/ Vtb_sdram__ConstPool__CONST_h77823079_0;
extern const VlWide<32>/*1023:0*/ Vtb_sdram__ConstPool__CONST_h5f53f96b_0;
extern const VlWide<32>/*1023:0*/ Vtb_sdram__ConstPool__CONST_h1f010471_0;
extern const VlWide<32>/*1023:0*/ Vtb_sdram__ConstPool__CONST_hef84a85a_0;
extern const VlWide<32>/*1023:0*/ Vtb_sdram__ConstPool__CONST_h9c0bbd60_0;
extern const VlWide<32>/*1023:0*/ Vtb_sdram__ConstPool__CONST_hfb707ecf_0;
extern const VlWide<32>/*1023:0*/ Vtb_sdram__ConstPool__CONST_h8b612c80_0;
extern const VlWide<32>/*1023:0*/ Vtb_sdram__ConstPool__CONST_h9cf6a441_0;
extern const VlWide<32>/*1023:0*/ Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0;
extern const VlWide<32>/*1023:0*/ Vtb_sdram__ConstPool__CONST_hf11d036f_0;
extern const VlWide<32>/*1023:0*/ Vtb_sdram__ConstPool__CONST_h1ed05db8_0;
extern const VlWide<32>/*1023:0*/ Vtb_sdram__ConstPool__CONST_h66ec84ff_0;

VL_INLINE_OPT void Vtb_sdram_sdram_mt48lc16m16a2___nba_sequent__TOP__tb_sdram__chip__0(Vtb_sdram_sdram_mt48lc16m16a2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_sdram_sdram_mt48lc16m16a2___nba_sequent__TOP__tb_sdram__chip__0\n"); );
    // Init
    VlWide<32>/*1023:0*/ __Vtask_report__0__msg;
    VL_ZERO_W(1024, __Vtask_report__0__msg);
    VlWide<32>/*1023:0*/ __Vtask_report__1__msg;
    VL_ZERO_W(1024, __Vtask_report__1__msg);
    VlWide<32>/*1023:0*/ __Vtask_report__2__msg;
    VL_ZERO_W(1024, __Vtask_report__2__msg);
    VlWide<32>/*1023:0*/ __Vtask_report__3__msg;
    VL_ZERO_W(1024, __Vtask_report__3__msg);
    IData/*23:0*/ __Vfunc_burst_index__4__Vfuncout;
    __Vfunc_burst_index__4__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_burst_index__4__beat;
    __Vfunc_burst_index__4__beat = 0;
    VlWide<32>/*1023:0*/ __Vtask_report__5__msg;
    VL_ZERO_W(1024, __Vtask_report__5__msg);
    VlWide<32>/*1023:0*/ __Vtask_report__6__msg;
    VL_ZERO_W(1024, __Vtask_report__6__msg);
    VlWide<32>/*1023:0*/ __Vtask_report__7__msg;
    VL_ZERO_W(1024, __Vtask_report__7__msg);
    VlWide<32>/*1023:0*/ __Vtask_report__8__msg;
    VL_ZERO_W(1024, __Vtask_report__8__msg);
    VlWide<32>/*1023:0*/ __Vtask_report__9__msg;
    VL_ZERO_W(1024, __Vtask_report__9__msg);
    VlWide<32>/*1023:0*/ __Vtask_report__10__msg;
    VL_ZERO_W(1024, __Vtask_report__10__msg);
    VlWide<32>/*1023:0*/ __Vtask_report__11__msg;
    VL_ZERO_W(1024, __Vtask_report__11__msg);
    VlWide<32>/*1023:0*/ __Vtask_report__12__msg;
    VL_ZERO_W(1024, __Vtask_report__12__msg);
    VlWide<32>/*1023:0*/ __Vtask_report__13__msg;
    VL_ZERO_W(1024, __Vtask_report__13__msg);
    VlWide<32>/*1023:0*/ __Vtask_report__14__msg;
    VL_ZERO_W(1024, __Vtask_report__14__msg);
    IData/*31:0*/ __Vdly__cycle;
    __Vdly__cycle = 0;
    SData/*15:0*/ __Vdly__since_refresh;
    __Vdly__since_refresh = 0;
    SData/*15:0*/ __Vdlyvval__rd_data__v0;
    __Vdlyvval__rd_data__v0 = 0;
    CData/*0:0*/ __Vdlyvset__rd_data__v0;
    __Vdlyvset__rd_data__v0 = 0;
    CData/*0:0*/ __Vdlyvval__rd_valid__v0;
    __Vdlyvval__rd_valid__v0 = 0;
    SData/*15:0*/ __Vdlyvval__rd_data__v1;
    __Vdlyvval__rd_data__v1 = 0;
    CData/*0:0*/ __Vdlyvval__rd_valid__v1;
    __Vdlyvval__rd_valid__v1 = 0;
    SData/*15:0*/ __Vdlyvval__rd_data__v2;
    __Vdlyvval__rd_data__v2 = 0;
    CData/*0:0*/ __Vdlyvval__rd_valid__v2;
    __Vdlyvval__rd_valid__v2 = 0;
    SData/*15:0*/ __Vdlyvval__rd_data__v3;
    __Vdlyvval__rd_data__v3 = 0;
    CData/*0:0*/ __Vdlyvval__rd_valid__v3;
    __Vdlyvval__rd_valid__v3 = 0;
    SData/*15:0*/ __Vdlyvval__rd_data__v4;
    __Vdlyvval__rd_data__v4 = 0;
    CData/*0:0*/ __Vdlyvval__rd_valid__v4;
    __Vdlyvval__rd_valid__v4 = 0;
    SData/*15:0*/ __Vdlyvval__rd_data__v5;
    __Vdlyvval__rd_data__v5 = 0;
    CData/*0:0*/ __Vdlyvval__rd_valid__v5;
    __Vdlyvval__rd_valid__v5 = 0;
    SData/*15:0*/ __Vdlyvval__rd_data__v6;
    __Vdlyvval__rd_data__v6 = 0;
    CData/*0:0*/ __Vdlyvval__rd_valid__v6;
    __Vdlyvval__rd_valid__v6 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_data__v7;
    __Vdlyvdim0__rd_data__v7 = 0;
    SData/*15:0*/ __Vdlyvval__rd_data__v7;
    __Vdlyvval__rd_data__v7 = 0;
    CData/*0:0*/ __Vdlyvset__rd_data__v7;
    __Vdlyvset__rd_data__v7 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_valid__v8;
    __Vdlyvdim0__rd_valid__v8 = 0;
    CData/*1:0*/ __Vdlyvdim0__bank_active__v0;
    __Vdlyvdim0__bank_active__v0 = 0;
    CData/*0:0*/ __Vdlyvset__bank_active__v0;
    __Vdlyvset__bank_active__v0 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_data__v8;
    __Vdlyvdim0__rd_data__v8 = 0;
    SData/*15:0*/ __Vdlyvval__rd_data__v8;
    __Vdlyvval__rd_data__v8 = 0;
    CData/*0:0*/ __Vdlyvset__rd_data__v8;
    __Vdlyvset__rd_data__v8 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_valid__v9;
    __Vdlyvdim0__rd_valid__v9 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_data__v9;
    __Vdlyvdim0__rd_data__v9 = 0;
    SData/*15:0*/ __Vdlyvval__rd_data__v9;
    __Vdlyvval__rd_data__v9 = 0;
    CData/*0:0*/ __Vdlyvset__rd_data__v9;
    __Vdlyvset__rd_data__v9 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_valid__v10;
    __Vdlyvdim0__rd_valid__v10 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_data__v10;
    __Vdlyvdim0__rd_data__v10 = 0;
    SData/*15:0*/ __Vdlyvval__rd_data__v10;
    __Vdlyvval__rd_data__v10 = 0;
    CData/*0:0*/ __Vdlyvset__rd_data__v10;
    __Vdlyvset__rd_data__v10 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_valid__v11;
    __Vdlyvdim0__rd_valid__v11 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_data__v11;
    __Vdlyvdim0__rd_data__v11 = 0;
    SData/*15:0*/ __Vdlyvval__rd_data__v11;
    __Vdlyvval__rd_data__v11 = 0;
    CData/*0:0*/ __Vdlyvset__rd_data__v11;
    __Vdlyvset__rd_data__v11 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_valid__v12;
    __Vdlyvdim0__rd_valid__v12 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_data__v12;
    __Vdlyvdim0__rd_data__v12 = 0;
    SData/*15:0*/ __Vdlyvval__rd_data__v12;
    __Vdlyvval__rd_data__v12 = 0;
    CData/*0:0*/ __Vdlyvset__rd_data__v12;
    __Vdlyvset__rd_data__v12 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_valid__v13;
    __Vdlyvdim0__rd_valid__v13 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_data__v13;
    __Vdlyvdim0__rd_data__v13 = 0;
    SData/*15:0*/ __Vdlyvval__rd_data__v13;
    __Vdlyvval__rd_data__v13 = 0;
    CData/*0:0*/ __Vdlyvset__rd_data__v13;
    __Vdlyvset__rd_data__v13 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_valid__v14;
    __Vdlyvdim0__rd_valid__v14 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_data__v14;
    __Vdlyvdim0__rd_data__v14 = 0;
    SData/*15:0*/ __Vdlyvval__rd_data__v14;
    __Vdlyvval__rd_data__v14 = 0;
    CData/*0:0*/ __Vdlyvset__rd_data__v14;
    __Vdlyvset__rd_data__v14 = 0;
    CData/*2:0*/ __Vdlyvdim0__rd_valid__v15;
    __Vdlyvdim0__rd_valid__v15 = 0;
    IData/*23:0*/ __Vdlyvdim0__mem__v0;
    __Vdlyvdim0__mem__v0 = 0;
    CData/*3:0*/ __Vdlyvlsb__mem__v0;
    __Vdlyvlsb__mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__mem__v0;
    __Vdlyvval__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__mem__v0;
    __Vdlyvset__mem__v0 = 0;
    IData/*23:0*/ __Vdlyvdim0__mem__v1;
    __Vdlyvdim0__mem__v1 = 0;
    CData/*3:0*/ __Vdlyvlsb__mem__v1;
    __Vdlyvlsb__mem__v1 = 0;
    CData/*7:0*/ __Vdlyvval__mem__v1;
    __Vdlyvval__mem__v1 = 0;
    CData/*0:0*/ __Vdlyvset__mem__v1;
    __Vdlyvset__mem__v1 = 0;
    CData/*1:0*/ __Vdlyvdim0__bank_active__v1;
    __Vdlyvdim0__bank_active__v1 = 0;
    CData/*0:0*/ __Vdlyvset__bank_active__v1;
    __Vdlyvset__bank_active__v1 = 0;
    CData/*1:0*/ __Vdlyvdim0__bank_row__v0;
    __Vdlyvdim0__bank_row__v0 = 0;
    SData/*12:0*/ __Vdlyvval__bank_row__v0;
    __Vdlyvval__bank_row__v0 = 0;
    CData/*0:0*/ __Vdlyvset__bank_row__v0;
    __Vdlyvset__bank_row__v0 = 0;
    CData/*1:0*/ __Vdlyvdim0__bank_act_cyc__v0;
    __Vdlyvdim0__bank_act_cyc__v0 = 0;
    IData/*31:0*/ __Vdlyvval__bank_act_cyc__v0;
    __Vdlyvval__bank_act_cyc__v0 = 0;
    CData/*1:0*/ __Vdlyvdim0__bank_active__v2;
    __Vdlyvdim0__bank_active__v2 = 0;
    CData/*0:0*/ __Vdlyvset__bank_active__v3;
    __Vdlyvset__bank_active__v3 = 0;
    CData/*1:0*/ __Vdlyvdim0__bank_active__v7;
    __Vdlyvdim0__bank_active__v7 = 0;
    CData/*0:0*/ __Vdlyvset__bank_active__v7;
    __Vdlyvset__bank_active__v7 = 0;
    CData/*0:0*/ __Vdlyvset__rd_valid__v16;
    __Vdlyvset__rd_valid__v16 = 0;
    // Body
    __Vdly__since_refresh = vlSelf->__PVT__since_refresh;
    __Vdly__cycle = vlSelf->__PVT__cycle;
    __Vdlyvset__mem__v0 = 0U;
    __Vdlyvset__mem__v1 = 0U;
    __Vdlyvset__bank_active__v0 = 0U;
    __Vdlyvset__bank_active__v1 = 0U;
    __Vdlyvset__bank_active__v3 = 0U;
    __Vdlyvset__bank_active__v7 = 0U;
    __Vdlyvset__bank_row__v0 = 0U;
    __Vdlyvset__rd_valid__v16 = 0U;
    __Vdlyvset__rd_data__v0 = 0U;
    __Vdlyvset__rd_data__v7 = 0U;
    __Vdlyvset__rd_data__v8 = 0U;
    __Vdlyvset__rd_data__v9 = 0U;
    __Vdlyvset__rd_data__v10 = 0U;
    __Vdlyvset__rd_data__v11 = 0U;
    __Vdlyvset__rd_data__v12 = 0U;
    __Vdlyvset__rd_data__v13 = 0U;
    __Vdlyvset__rd_data__v14 = 0U;
    if (vlSymsp->TOP.rst_n) {
        __Vdly__cycle = ((IData)(1U) + vlSelf->__PVT__cycle);
        __Vdly__since_refresh = (0xffffU & ((IData)(1U) 
                                            + (IData)(vlSelf->__PVT__since_refresh)));
        if (vlSelf->__PVT__rd_valid[0U]) {
            vlSelf->__PVT__dq_oe = 1U;
            vlSelf->__PVT__dq_out = vlSelf->__PVT__rd_data
                [0U];
        } else {
            vlSelf->__PVT__dq_oe = 0U;
        }
        __Vdlyvval__rd_data__v0 = vlSelf->__PVT__rd_data
            [1U];
        __Vdlyvset__rd_data__v0 = 1U;
        __Vdlyvval__rd_valid__v0 = vlSelf->__PVT__rd_valid
            [1U];
        __Vdlyvval__rd_data__v1 = vlSelf->__PVT__rd_data
            [2U];
        __Vdlyvval__rd_valid__v1 = vlSelf->__PVT__rd_valid
            [2U];
        __Vdlyvval__rd_data__v2 = vlSelf->__PVT__rd_data
            [3U];
        __Vdlyvval__rd_valid__v2 = vlSelf->__PVT__rd_valid
            [3U];
        __Vdlyvval__rd_data__v3 = vlSelf->__PVT__rd_data
            [4U];
        __Vdlyvval__rd_valid__v3 = vlSelf->__PVT__rd_valid
            [4U];
        __Vdlyvval__rd_data__v4 = vlSelf->__PVT__rd_data
            [5U];
        __Vdlyvval__rd_valid__v4 = vlSelf->__PVT__rd_valid
            [5U];
        __Vdlyvval__rd_data__v5 = vlSelf->__PVT__rd_data
            [6U];
        __Vdlyvval__rd_valid__v5 = vlSelf->__PVT__rd_valid
            [6U];
        __Vdlyvval__rd_data__v6 = vlSelf->__PVT__rd_data
            [7U];
        __Vdlyvval__rd_valid__v6 = vlSelf->__PVT__rd_valid
            [7U];
        if ((8U & (IData)(vlSelf->__PVT__cmd))) {
            if ((1U & (~ (IData)(vlSymsp->TOP__tb_sdram.__PVT__ctl__DOT__chip)))) {
                __Vtask_report__0__msg[0U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0U];
                __Vtask_report__0__msg[1U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[1U];
                __Vtask_report__0__msg[2U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[2U];
                __Vtask_report__0__msg[3U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[3U];
                __Vtask_report__0__msg[4U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[4U];
                __Vtask_report__0__msg[5U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[5U];
                __Vtask_report__0__msg[6U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[6U];
                __Vtask_report__0__msg[7U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[7U];
                __Vtask_report__0__msg[8U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[8U];
                __Vtask_report__0__msg[9U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[9U];
                __Vtask_report__0__msg[0xaU] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0xaU];
                __Vtask_report__0__msg[0xbU] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0xbU];
                __Vtask_report__0__msg[0xcU] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0xcU];
                __Vtask_report__0__msg[0xdU] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0xdU];
                __Vtask_report__0__msg[0xeU] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0xeU];
                __Vtask_report__0__msg[0xfU] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0xfU];
                __Vtask_report__0__msg[0x10U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x10U];
                __Vtask_report__0__msg[0x11U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x11U];
                __Vtask_report__0__msg[0x12U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x12U];
                __Vtask_report__0__msg[0x13U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x13U];
                __Vtask_report__0__msg[0x14U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x14U];
                __Vtask_report__0__msg[0x15U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x15U];
                __Vtask_report__0__msg[0x16U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x16U];
                __Vtask_report__0__msg[0x17U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x17U];
                __Vtask_report__0__msg[0x18U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x18U];
                __Vtask_report__0__msg[0x19U] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x19U];
                __Vtask_report__0__msg[0x1aU] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x1aU];
                __Vtask_report__0__msg[0x1bU] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x1bU];
                __Vtask_report__0__msg[0x1cU] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x1cU];
                __Vtask_report__0__msg[0x1dU] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x1dU];
                __Vtask_report__0__msg[0x1eU] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x1eU];
                __Vtask_report__0__msg[0x1fU] = Vtb_sdram__ConstPool__CONST_h66c1db22_0[0x1fU];
                vlSelf->__PVT__dbg_violations = (0xffffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->__PVT__dbg_violations)));
                if (VL_UNLIKELY((0x14U > (IData)(vlSelf->__PVT__reports)))) {
                    vlSelf->__PVT__reports = (0xffffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->__PVT__reports)));
                    VL_WRITEF("[sdram] cycle %0#: %0s\n",
                              32,vlSelf->__PVT__cycle,
                              1024,__Vtask_report__0__msg.data());
                    if (VL_UNLIKELY((0x14U == (IData)(vlSelf->__PVT__reports)))) {
                        VL_WRITEF("[sdram] further violations counted but not printed\n");
                    }
                }
            }
        } else if ((4U & (IData)(vlSelf->__PVT__cmd))) {
            if ((1U & (~ ((IData)(vlSelf->__PVT__cmd) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelf->__PVT__cmd))) {
                    vlSelf->__PVT__dbg_reads = ((IData)(1U) 
                                                + vlSelf->__PVT__dbg_reads);
                    if ((1U & (~ (IData)(vlSelf->__PVT__mode_loaded)))) {
                        __Vtask_report__1__msg[0U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0U];
                        __Vtask_report__1__msg[1U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[1U];
                        __Vtask_report__1__msg[2U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[2U];
                        __Vtask_report__1__msg[3U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[3U];
                        __Vtask_report__1__msg[4U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[4U];
                        __Vtask_report__1__msg[5U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[5U];
                        __Vtask_report__1__msg[6U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[6U];
                        __Vtask_report__1__msg[7U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[7U];
                        __Vtask_report__1__msg[8U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[8U];
                        __Vtask_report__1__msg[9U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[9U];
                        __Vtask_report__1__msg[0xaU] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0xaU];
                        __Vtask_report__1__msg[0xbU] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0xbU];
                        __Vtask_report__1__msg[0xcU] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0xcU];
                        __Vtask_report__1__msg[0xdU] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0xdU];
                        __Vtask_report__1__msg[0xeU] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0xeU];
                        __Vtask_report__1__msg[0xfU] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0xfU];
                        __Vtask_report__1__msg[0x10U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x10U];
                        __Vtask_report__1__msg[0x11U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x11U];
                        __Vtask_report__1__msg[0x12U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x12U];
                        __Vtask_report__1__msg[0x13U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x13U];
                        __Vtask_report__1__msg[0x14U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x14U];
                        __Vtask_report__1__msg[0x15U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x15U];
                        __Vtask_report__1__msg[0x16U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x16U];
                        __Vtask_report__1__msg[0x17U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x17U];
                        __Vtask_report__1__msg[0x18U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x18U];
                        __Vtask_report__1__msg[0x19U] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x19U];
                        __Vtask_report__1__msg[0x1aU] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x1aU];
                        __Vtask_report__1__msg[0x1bU] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x1bU];
                        __Vtask_report__1__msg[0x1cU] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x1cU];
                        __Vtask_report__1__msg[0x1dU] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x1dU];
                        __Vtask_report__1__msg[0x1eU] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x1eU];
                        __Vtask_report__1__msg[0x1fU] 
                            = Vtb_sdram__ConstPool__CONST_hfcf63cb2_0[0x1fU];
                        vlSelf->__PVT__dbg_violations 
                            = (0xffffU & ((IData)(1U) 
                                          + (IData)(vlSelf->__PVT__dbg_violations)));
                        if (VL_UNLIKELY((0x14U > (IData)(vlSelf->__PVT__reports)))) {
                            vlSelf->__PVT__reports 
                                = (0xffffU & ((IData)(1U) 
                                              + (IData)(vlSelf->__PVT__reports)));
                            VL_WRITEF("[sdram] cycle %0#: %0s\n",
                                      32,vlSelf->__PVT__cycle,
                                      1024,__Vtask_report__1__msg.data());
                            if (VL_UNLIKELY((0x14U 
                                             == (IData)(vlSelf->__PVT__reports)))) {
                                VL_WRITEF("[sdram] further violations counted but not printed\n");
                            }
                        }
                    }
                    vlSelf->__PVT__dbg_last_index = vlSelf->__PVT__cmd_index;
                    vlSelf->__PVT__dbg_last_col = (0x1ffU 
                                                   & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A));
                    vlSelf->__PVT__dbg_last_row = vlSelf->__PVT__bank_row
                        [vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA];
                    vlSelf->__PVT__dbg_last_a = vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A;
                    if (vlSelf->__PVT__bank_active[vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA]) {
                        if ((1U > (vlSelf->__PVT__cycle 
                                   - vlSelf->__PVT__bank_act_cyc
                                   [vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA]))) {
                            __Vtask_report__2__msg[0U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0U];
                            __Vtask_report__2__msg[1U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[1U];
                            __Vtask_report__2__msg[2U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[2U];
                            __Vtask_report__2__msg[3U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[3U];
                            __Vtask_report__2__msg[4U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[4U];
                            __Vtask_report__2__msg[5U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[5U];
                            __Vtask_report__2__msg[6U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[6U];
                            __Vtask_report__2__msg[7U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[7U];
                            __Vtask_report__2__msg[8U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[8U];
                            __Vtask_report__2__msg[9U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[9U];
                            __Vtask_report__2__msg[0xaU] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0xaU];
                            __Vtask_report__2__msg[0xbU] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0xbU];
                            __Vtask_report__2__msg[0xcU] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0xcU];
                            __Vtask_report__2__msg[0xdU] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0xdU];
                            __Vtask_report__2__msg[0xeU] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0xeU];
                            __Vtask_report__2__msg[0xfU] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0xfU];
                            __Vtask_report__2__msg[0x10U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x10U];
                            __Vtask_report__2__msg[0x11U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x11U];
                            __Vtask_report__2__msg[0x12U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x12U];
                            __Vtask_report__2__msg[0x13U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x13U];
                            __Vtask_report__2__msg[0x14U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x14U];
                            __Vtask_report__2__msg[0x15U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x15U];
                            __Vtask_report__2__msg[0x16U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x16U];
                            __Vtask_report__2__msg[0x17U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x17U];
                            __Vtask_report__2__msg[0x18U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x18U];
                            __Vtask_report__2__msg[0x19U] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x19U];
                            __Vtask_report__2__msg[0x1aU] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x1aU];
                            __Vtask_report__2__msg[0x1bU] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x1bU];
                            __Vtask_report__2__msg[0x1cU] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x1cU];
                            __Vtask_report__2__msg[0x1dU] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x1dU];
                            __Vtask_report__2__msg[0x1eU] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x1eU];
                            __Vtask_report__2__msg[0x1fU] 
                                = Vtb_sdram__ConstPool__CONST_h77823079_0[0x1fU];
                            vlSelf->__PVT__dbg_violations 
                                = (0xffffU & ((IData)(1U) 
                                              + (IData)(vlSelf->__PVT__dbg_violations)));
                            if (VL_UNLIKELY((0x14U 
                                             > (IData)(vlSelf->__PVT__reports)))) {
                                vlSelf->__PVT__reports 
                                    = (0xffffU & ((IData)(1U) 
                                                  + (IData)(vlSelf->__PVT__reports)));
                                VL_WRITEF("[sdram] cycle %0#: %0s\n",
                                          32,vlSelf->__PVT__cycle,
                                          1024,__Vtask_report__2__msg.data());
                                if (VL_UNLIKELY((0x14U 
                                                 == (IData)(vlSelf->__PVT__reports)))) {
                                    VL_WRITEF("[sdram] further violations counted but not printed\n");
                                }
                            }
                        }
                    } else {
                        __Vtask_report__3__msg[0U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0U];
                        __Vtask_report__3__msg[1U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[1U];
                        __Vtask_report__3__msg[2U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[2U];
                        __Vtask_report__3__msg[3U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[3U];
                        __Vtask_report__3__msg[4U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[4U];
                        __Vtask_report__3__msg[5U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[5U];
                        __Vtask_report__3__msg[6U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[6U];
                        __Vtask_report__3__msg[7U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[7U];
                        __Vtask_report__3__msg[8U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[8U];
                        __Vtask_report__3__msg[9U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[9U];
                        __Vtask_report__3__msg[0xaU] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0xaU];
                        __Vtask_report__3__msg[0xbU] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0xbU];
                        __Vtask_report__3__msg[0xcU] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0xcU];
                        __Vtask_report__3__msg[0xdU] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0xdU];
                        __Vtask_report__3__msg[0xeU] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0xeU];
                        __Vtask_report__3__msg[0xfU] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0xfU];
                        __Vtask_report__3__msg[0x10U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x10U];
                        __Vtask_report__3__msg[0x11U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x11U];
                        __Vtask_report__3__msg[0x12U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x12U];
                        __Vtask_report__3__msg[0x13U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x13U];
                        __Vtask_report__3__msg[0x14U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x14U];
                        __Vtask_report__3__msg[0x15U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x15U];
                        __Vtask_report__3__msg[0x16U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x16U];
                        __Vtask_report__3__msg[0x17U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x17U];
                        __Vtask_report__3__msg[0x18U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x18U];
                        __Vtask_report__3__msg[0x19U] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x19U];
                        __Vtask_report__3__msg[0x1aU] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x1aU];
                        __Vtask_report__3__msg[0x1bU] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x1bU];
                        __Vtask_report__3__msg[0x1cU] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x1cU];
                        __Vtask_report__3__msg[0x1dU] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x1dU];
                        __Vtask_report__3__msg[0x1eU] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x1eU];
                        __Vtask_report__3__msg[0x1fU] 
                            = Vtb_sdram__ConstPool__CONST_h5f53f96b_0[0x1fU];
                        vlSelf->__PVT__dbg_violations 
                            = (0xffffU & ((IData)(1U) 
                                          + (IData)(vlSelf->__PVT__dbg_violations)));
                        if (VL_UNLIKELY((0x14U > (IData)(vlSelf->__PVT__reports)))) {
                            vlSelf->__PVT__reports 
                                = (0xffffU & ((IData)(1U) 
                                              + (IData)(vlSelf->__PVT__reports)));
                            VL_WRITEF("[sdram] cycle %0#: %0s\n",
                                      32,vlSelf->__PVT__cycle,
                                      1024,__Vtask_report__3__msg.data());
                            if (VL_UNLIKELY((0x14U 
                                             == (IData)(vlSelf->__PVT__reports)))) {
                                VL_WRITEF("[sdram] further violations counted but not printed\n");
                            }
                        }
                    }
                    if ((0U < (IData)(vlSelf->__PVT__burst_len))) {
                        __Vdlyvval__rd_data__v7 = vlSelf->mem
                            [([&]() {
                                __Vfunc_burst_index__4__beat = 0U;
                                vlSelf->__PVT__burst_index__Vstatic__c 
                                    = (0x1ffU & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A));
                                if ((1U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1feU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((2U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1fcU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (3U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((3U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1f8U 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (7U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                }
                                __Vfunc_burst_index__4__Vfuncout 
                                    = (((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA) 
                                        << 0x16U) | 
                                       ((vlSelf->__PVT__bank_row
                                         [vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA] 
                                         << 9U) | (IData)(vlSelf->__PVT__burst_index__Vstatic__c)));
                            }(), __Vfunc_burst_index__4__Vfuncout)];
                        __Vdlyvset__rd_data__v7 = 1U;
                        __Vdlyvdim0__rd_data__v7 = vlSelf->__PVT__cl_slot;
                        __Vdlyvdim0__rd_valid__v8 = vlSelf->__PVT__cl_slot;
                    }
                    if ((0x400U & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A))) {
                        __Vdlyvset__bank_active__v0 = 1U;
                        __Vdlyvdim0__bank_active__v0 
                            = vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA;
                    }
                    if ((1U < (IData)(vlSelf->__PVT__burst_len))) {
                        __Vdlyvval__rd_data__v8 = vlSelf->mem
                            [([&]() {
                                __Vfunc_burst_index__4__beat = 1U;
                                vlSelf->__PVT__burst_index__Vstatic__c 
                                    = (0x1ffU & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A));
                                if ((1U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1feU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((2U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1fcU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (3U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((3U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1f8U 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (7U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                }
                                __Vfunc_burst_index__4__Vfuncout 
                                    = (((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA) 
                                        << 0x16U) | 
                                       ((vlSelf->__PVT__bank_row
                                         [vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA] 
                                         << 9U) | (IData)(vlSelf->__PVT__burst_index__Vstatic__c)));
                            }(), __Vfunc_burst_index__4__Vfuncout)];
                        __Vdlyvset__rd_data__v8 = 1U;
                        __Vdlyvdim0__rd_data__v8 = 
                            (7U & ((IData)(1U) + (IData)(vlSelf->__PVT__cl_slot)));
                        __Vdlyvdim0__rd_valid__v9 = 
                            (7U & ((IData)(1U) + (IData)(vlSelf->__PVT__cl_slot)));
                    }
                    if ((2U < (IData)(vlSelf->__PVT__burst_len))) {
                        __Vdlyvval__rd_data__v9 = vlSelf->mem
                            [([&]() {
                                __Vfunc_burst_index__4__beat = 2U;
                                vlSelf->__PVT__burst_index__Vstatic__c 
                                    = (0x1ffU & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A));
                                if ((1U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1feU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((2U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1fcU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (3U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((3U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1f8U 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (7U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                }
                                __Vfunc_burst_index__4__Vfuncout 
                                    = (((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA) 
                                        << 0x16U) | 
                                       ((vlSelf->__PVT__bank_row
                                         [vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA] 
                                         << 9U) | (IData)(vlSelf->__PVT__burst_index__Vstatic__c)));
                            }(), __Vfunc_burst_index__4__Vfuncout)];
                        __Vdlyvset__rd_data__v9 = 1U;
                        __Vdlyvdim0__rd_data__v9 = 
                            (7U & ((IData)(2U) + (IData)(vlSelf->__PVT__cl_slot)));
                        __Vdlyvdim0__rd_valid__v10 
                            = (7U & ((IData)(2U) + (IData)(vlSelf->__PVT__cl_slot)));
                    }
                    if ((3U < (IData)(vlSelf->__PVT__burst_len))) {
                        __Vdlyvval__rd_data__v10 = 
                            vlSelf->mem[([&]() {
                                __Vfunc_burst_index__4__beat = 3U;
                                vlSelf->__PVT__burst_index__Vstatic__c 
                                    = (0x1ffU & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A));
                                if ((1U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1feU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((2U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1fcU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (3U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((3U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1f8U 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (7U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                }
                                __Vfunc_burst_index__4__Vfuncout 
                                    = (((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA) 
                                        << 0x16U) | 
                                       ((vlSelf->__PVT__bank_row
                                         [vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA] 
                                         << 9U) | (IData)(vlSelf->__PVT__burst_index__Vstatic__c)));
                            }(), __Vfunc_burst_index__4__Vfuncout)];
                        __Vdlyvset__rd_data__v10 = 1U;
                        __Vdlyvdim0__rd_data__v10 = 
                            (7U & ((IData)(3U) + (IData)(vlSelf->__PVT__cl_slot)));
                        __Vdlyvdim0__rd_valid__v11 
                            = (7U & ((IData)(3U) + (IData)(vlSelf->__PVT__cl_slot)));
                    }
                    if ((4U < (IData)(vlSelf->__PVT__burst_len))) {
                        __Vdlyvval__rd_data__v11 = 
                            vlSelf->mem[([&]() {
                                __Vfunc_burst_index__4__beat = 4U;
                                vlSelf->__PVT__burst_index__Vstatic__c 
                                    = (0x1ffU & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A));
                                if ((1U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1feU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((2U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1fcU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (3U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((3U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1f8U 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (7U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                }
                                __Vfunc_burst_index__4__Vfuncout 
                                    = (((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA) 
                                        << 0x16U) | 
                                       ((vlSelf->__PVT__bank_row
                                         [vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA] 
                                         << 9U) | (IData)(vlSelf->__PVT__burst_index__Vstatic__c)));
                            }(), __Vfunc_burst_index__4__Vfuncout)];
                        __Vdlyvset__rd_data__v11 = 1U;
                        __Vdlyvdim0__rd_data__v11 = 
                            (7U & ((IData)(4U) + (IData)(vlSelf->__PVT__cl_slot)));
                        __Vdlyvdim0__rd_valid__v12 
                            = (7U & ((IData)(4U) + (IData)(vlSelf->__PVT__cl_slot)));
                    }
                    if ((5U < (IData)(vlSelf->__PVT__burst_len))) {
                        __Vdlyvval__rd_data__v12 = 
                            vlSelf->mem[([&]() {
                                __Vfunc_burst_index__4__beat = 5U;
                                vlSelf->__PVT__burst_index__Vstatic__c 
                                    = (0x1ffU & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A));
                                if ((1U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1feU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((2U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1fcU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (3U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((3U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1f8U 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (7U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                }
                                __Vfunc_burst_index__4__Vfuncout 
                                    = (((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA) 
                                        << 0x16U) | 
                                       ((vlSelf->__PVT__bank_row
                                         [vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA] 
                                         << 9U) | (IData)(vlSelf->__PVT__burst_index__Vstatic__c)));
                            }(), __Vfunc_burst_index__4__Vfuncout)];
                        __Vdlyvset__rd_data__v12 = 1U;
                        __Vdlyvdim0__rd_data__v12 = 
                            (7U & ((IData)(5U) + (IData)(vlSelf->__PVT__cl_slot)));
                        __Vdlyvdim0__rd_valid__v13 
                            = (7U & ((IData)(5U) + (IData)(vlSelf->__PVT__cl_slot)));
                    }
                    if ((6U < (IData)(vlSelf->__PVT__burst_len))) {
                        __Vdlyvval__rd_data__v13 = 
                            vlSelf->mem[([&]() {
                                __Vfunc_burst_index__4__beat = 6U;
                                vlSelf->__PVT__burst_index__Vstatic__c 
                                    = (0x1ffU & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A));
                                if ((1U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1feU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((2U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1fcU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (3U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((3U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1f8U 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (7U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                }
                                __Vfunc_burst_index__4__Vfuncout 
                                    = (((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA) 
                                        << 0x16U) | 
                                       ((vlSelf->__PVT__bank_row
                                         [vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA] 
                                         << 9U) | (IData)(vlSelf->__PVT__burst_index__Vstatic__c)));
                            }(), __Vfunc_burst_index__4__Vfuncout)];
                        __Vdlyvset__rd_data__v13 = 1U;
                        __Vdlyvdim0__rd_data__v13 = 
                            (7U & ((IData)(6U) + (IData)(vlSelf->__PVT__cl_slot)));
                        __Vdlyvdim0__rd_valid__v14 
                            = (7U & ((IData)(6U) + (IData)(vlSelf->__PVT__cl_slot)));
                    }
                    if ((7U < (IData)(vlSelf->__PVT__burst_len))) {
                        __Vdlyvval__rd_data__v14 = 
                            vlSelf->mem[([&]() {
                                __Vfunc_burst_index__4__beat = 7U;
                                vlSelf->__PVT__burst_index__Vstatic__c 
                                    = (0x1ffU & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A));
                                if ((1U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1feU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (1U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((2U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1fcU 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (3U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                } else if ((3U == (IData)(vlSelf->__PVT__mode_burst))) {
                                    vlSelf->__PVT__burst_index__Vstatic__c 
                                        = ((0x1f8U 
                                            & (IData)(vlSelf->__PVT__burst_index__Vstatic__c)) 
                                           | (7U & 
                                              ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                               + (IData)(__Vfunc_burst_index__4__beat))));
                                }
                                __Vfunc_burst_index__4__Vfuncout 
                                    = (((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA) 
                                        << 0x16U) | 
                                       ((vlSelf->__PVT__bank_row
                                         [vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA] 
                                         << 9U) | (IData)(vlSelf->__PVT__burst_index__Vstatic__c)));
                            }(), __Vfunc_burst_index__4__Vfuncout)];
                        __Vdlyvset__rd_data__v14 = 1U;
                        __Vdlyvdim0__rd_data__v14 = 
                            (7U & ((IData)(7U) + (IData)(vlSelf->__PVT__cl_slot)));
                        __Vdlyvdim0__rd_valid__v15 
                            = (7U & ((IData)(7U) + (IData)(vlSelf->__PVT__cl_slot)));
                    }
                } else {
                    vlSelf->__PVT__dbg_writes = ((IData)(1U) 
                                                 + vlSelf->__PVT__dbg_writes);
                    if ((1U & (~ (IData)(vlSelf->__PVT__mode_loaded)))) {
                        __Vtask_report__5__msg[0U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0U];
                        __Vtask_report__5__msg[1U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[1U];
                        __Vtask_report__5__msg[2U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[2U];
                        __Vtask_report__5__msg[3U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[3U];
                        __Vtask_report__5__msg[4U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[4U];
                        __Vtask_report__5__msg[5U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[5U];
                        __Vtask_report__5__msg[6U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[6U];
                        __Vtask_report__5__msg[7U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[7U];
                        __Vtask_report__5__msg[8U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[8U];
                        __Vtask_report__5__msg[9U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[9U];
                        __Vtask_report__5__msg[0xaU] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0xaU];
                        __Vtask_report__5__msg[0xbU] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0xbU];
                        __Vtask_report__5__msg[0xcU] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0xcU];
                        __Vtask_report__5__msg[0xdU] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0xdU];
                        __Vtask_report__5__msg[0xeU] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0xeU];
                        __Vtask_report__5__msg[0xfU] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0xfU];
                        __Vtask_report__5__msg[0x10U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x10U];
                        __Vtask_report__5__msg[0x11U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x11U];
                        __Vtask_report__5__msg[0x12U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x12U];
                        __Vtask_report__5__msg[0x13U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x13U];
                        __Vtask_report__5__msg[0x14U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x14U];
                        __Vtask_report__5__msg[0x15U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x15U];
                        __Vtask_report__5__msg[0x16U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x16U];
                        __Vtask_report__5__msg[0x17U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x17U];
                        __Vtask_report__5__msg[0x18U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x18U];
                        __Vtask_report__5__msg[0x19U] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x19U];
                        __Vtask_report__5__msg[0x1aU] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x1aU];
                        __Vtask_report__5__msg[0x1bU] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x1bU];
                        __Vtask_report__5__msg[0x1cU] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x1cU];
                        __Vtask_report__5__msg[0x1dU] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x1dU];
                        __Vtask_report__5__msg[0x1eU] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x1eU];
                        __Vtask_report__5__msg[0x1fU] 
                            = Vtb_sdram__ConstPool__CONST_h1f010471_0[0x1fU];
                        vlSelf->__PVT__dbg_violations 
                            = (0xffffU & ((IData)(1U) 
                                          + (IData)(vlSelf->__PVT__dbg_violations)));
                        if (VL_UNLIKELY((0x14U > (IData)(vlSelf->__PVT__reports)))) {
                            vlSelf->__PVT__reports 
                                = (0xffffU & ((IData)(1U) 
                                              + (IData)(vlSelf->__PVT__reports)));
                            VL_WRITEF("[sdram] cycle %0#: %0s\n",
                                      32,vlSelf->__PVT__cycle,
                                      1024,__Vtask_report__5__msg.data());
                            if (VL_UNLIKELY((0x14U 
                                             == (IData)(vlSelf->__PVT__reports)))) {
                                VL_WRITEF("[sdram] further violations counted but not printed\n");
                            }
                        }
                    }
                    if (vlSelf->__PVT__bank_active[vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA]) {
                        if ((1U > (vlSelf->__PVT__cycle 
                                   - vlSelf->__PVT__bank_act_cyc
                                   [vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA]))) {
                            __Vtask_report__6__msg[0U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0U];
                            __Vtask_report__6__msg[1U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[1U];
                            __Vtask_report__6__msg[2U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[2U];
                            __Vtask_report__6__msg[3U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[3U];
                            __Vtask_report__6__msg[4U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[4U];
                            __Vtask_report__6__msg[5U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[5U];
                            __Vtask_report__6__msg[6U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[6U];
                            __Vtask_report__6__msg[7U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[7U];
                            __Vtask_report__6__msg[8U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[8U];
                            __Vtask_report__6__msg[9U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[9U];
                            __Vtask_report__6__msg[0xaU] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0xaU];
                            __Vtask_report__6__msg[0xbU] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0xbU];
                            __Vtask_report__6__msg[0xcU] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0xcU];
                            __Vtask_report__6__msg[0xdU] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0xdU];
                            __Vtask_report__6__msg[0xeU] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0xeU];
                            __Vtask_report__6__msg[0xfU] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0xfU];
                            __Vtask_report__6__msg[0x10U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x10U];
                            __Vtask_report__6__msg[0x11U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x11U];
                            __Vtask_report__6__msg[0x12U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x12U];
                            __Vtask_report__6__msg[0x13U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x13U];
                            __Vtask_report__6__msg[0x14U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x14U];
                            __Vtask_report__6__msg[0x15U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x15U];
                            __Vtask_report__6__msg[0x16U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x16U];
                            __Vtask_report__6__msg[0x17U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x17U];
                            __Vtask_report__6__msg[0x18U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x18U];
                            __Vtask_report__6__msg[0x19U] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x19U];
                            __Vtask_report__6__msg[0x1aU] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x1aU];
                            __Vtask_report__6__msg[0x1bU] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x1bU];
                            __Vtask_report__6__msg[0x1cU] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x1cU];
                            __Vtask_report__6__msg[0x1dU] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x1dU];
                            __Vtask_report__6__msg[0x1eU] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x1eU];
                            __Vtask_report__6__msg[0x1fU] 
                                = Vtb_sdram__ConstPool__CONST_hef84a85a_0[0x1fU];
                            vlSelf->__PVT__dbg_violations 
                                = (0xffffU & ((IData)(1U) 
                                              + (IData)(vlSelf->__PVT__dbg_violations)));
                            if (VL_UNLIKELY((0x14U 
                                             > (IData)(vlSelf->__PVT__reports)))) {
                                vlSelf->__PVT__reports 
                                    = (0xffffU & ((IData)(1U) 
                                                  + (IData)(vlSelf->__PVT__reports)));
                                VL_WRITEF("[sdram] cycle %0#: %0s\n",
                                          32,vlSelf->__PVT__cycle,
                                          1024,__Vtask_report__6__msg.data());
                                if (VL_UNLIKELY((0x14U 
                                                 == (IData)(vlSelf->__PVT__reports)))) {
                                    VL_WRITEF("[sdram] further violations counted but not printed\n");
                                }
                            }
                        } else {
                            if ((IData)((0x1800U == 
                                         (0x1800U & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A))))) {
                                __Vtask_report__7__msg[0U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0U];
                                __Vtask_report__7__msg[1U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[1U];
                                __Vtask_report__7__msg[2U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[2U];
                                __Vtask_report__7__msg[3U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[3U];
                                __Vtask_report__7__msg[4U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[4U];
                                __Vtask_report__7__msg[5U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[5U];
                                __Vtask_report__7__msg[6U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[6U];
                                __Vtask_report__7__msg[7U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[7U];
                                __Vtask_report__7__msg[8U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[8U];
                                __Vtask_report__7__msg[9U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[9U];
                                __Vtask_report__7__msg[0xaU] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0xaU];
                                __Vtask_report__7__msg[0xbU] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0xbU];
                                __Vtask_report__7__msg[0xcU] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0xcU];
                                __Vtask_report__7__msg[0xdU] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0xdU];
                                __Vtask_report__7__msg[0xeU] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0xeU];
                                __Vtask_report__7__msg[0xfU] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0xfU];
                                __Vtask_report__7__msg[0x10U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x10U];
                                __Vtask_report__7__msg[0x11U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x11U];
                                __Vtask_report__7__msg[0x12U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x12U];
                                __Vtask_report__7__msg[0x13U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x13U];
                                __Vtask_report__7__msg[0x14U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x14U];
                                __Vtask_report__7__msg[0x15U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x15U];
                                __Vtask_report__7__msg[0x16U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x16U];
                                __Vtask_report__7__msg[0x17U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x17U];
                                __Vtask_report__7__msg[0x18U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x18U];
                                __Vtask_report__7__msg[0x19U] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x19U];
                                __Vtask_report__7__msg[0x1aU] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x1aU];
                                __Vtask_report__7__msg[0x1bU] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x1bU];
                                __Vtask_report__7__msg[0x1cU] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x1cU];
                                __Vtask_report__7__msg[0x1dU] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x1dU];
                                __Vtask_report__7__msg[0x1eU] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x1eU];
                                __Vtask_report__7__msg[0x1fU] 
                                    = Vtb_sdram__ConstPool__CONST_h9c0bbd60_0[0x1fU];
                                vlSelf->__PVT__dbg_violations 
                                    = (0xffffU & ((IData)(1U) 
                                                  + (IData)(vlSelf->__PVT__dbg_violations)));
                                if (VL_UNLIKELY((0x14U 
                                                 > (IData)(vlSelf->__PVT__reports)))) {
                                    vlSelf->__PVT__reports 
                                        = (0xffffU 
                                           & ((IData)(1U) 
                                              + (IData)(vlSelf->__PVT__reports)));
                                    VL_WRITEF("[sdram] cycle %0#: %0s\n",
                                              32,vlSelf->__PVT__cycle,
                                              1024,
                                              __Vtask_report__7__msg.data());
                                    if (VL_UNLIKELY(
                                                    (0x14U 
                                                     == (IData)(vlSelf->__PVT__reports)))) {
                                        VL_WRITEF("[sdram] further violations counted but not printed\n");
                                    }
                                }
                            }
                            if ((1U & (~ ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                          >> 0xbU)))) {
                                __Vdlyvval__mem__v0 
                                    = (0xffU & (IData)(vlSymsp->TOP__tb_sdram.__PVT__dq_bus));
                                __Vdlyvset__mem__v0 = 1U;
                                __Vdlyvlsb__mem__v0 = 0U;
                                __Vdlyvdim0__mem__v0 
                                    = vlSelf->__PVT__cmd_index;
                            }
                            if ((1U & (~ ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                          >> 0xcU)))) {
                                __Vdlyvval__mem__v1 
                                    = (0xffU & ((IData)(vlSymsp->TOP__tb_sdram.__PVT__dq_bus) 
                                                >> 8U));
                                __Vdlyvset__mem__v1 = 1U;
                                __Vdlyvlsb__mem__v1 = 8U;
                                __Vdlyvdim0__mem__v1 
                                    = vlSelf->__PVT__cmd_index;
                            }
                        }
                    } else {
                        __Vtask_report__8__msg[0U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0U];
                        __Vtask_report__8__msg[1U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[1U];
                        __Vtask_report__8__msg[2U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[2U];
                        __Vtask_report__8__msg[3U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[3U];
                        __Vtask_report__8__msg[4U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[4U];
                        __Vtask_report__8__msg[5U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[5U];
                        __Vtask_report__8__msg[6U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[6U];
                        __Vtask_report__8__msg[7U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[7U];
                        __Vtask_report__8__msg[8U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[8U];
                        __Vtask_report__8__msg[9U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[9U];
                        __Vtask_report__8__msg[0xaU] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0xaU];
                        __Vtask_report__8__msg[0xbU] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0xbU];
                        __Vtask_report__8__msg[0xcU] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0xcU];
                        __Vtask_report__8__msg[0xdU] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0xdU];
                        __Vtask_report__8__msg[0xeU] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0xeU];
                        __Vtask_report__8__msg[0xfU] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0xfU];
                        __Vtask_report__8__msg[0x10U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x10U];
                        __Vtask_report__8__msg[0x11U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x11U];
                        __Vtask_report__8__msg[0x12U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x12U];
                        __Vtask_report__8__msg[0x13U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x13U];
                        __Vtask_report__8__msg[0x14U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x14U];
                        __Vtask_report__8__msg[0x15U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x15U];
                        __Vtask_report__8__msg[0x16U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x16U];
                        __Vtask_report__8__msg[0x17U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x17U];
                        __Vtask_report__8__msg[0x18U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x18U];
                        __Vtask_report__8__msg[0x19U] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x19U];
                        __Vtask_report__8__msg[0x1aU] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x1aU];
                        __Vtask_report__8__msg[0x1bU] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x1bU];
                        __Vtask_report__8__msg[0x1cU] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x1cU];
                        __Vtask_report__8__msg[0x1dU] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x1dU];
                        __Vtask_report__8__msg[0x1eU] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x1eU];
                        __Vtask_report__8__msg[0x1fU] 
                            = Vtb_sdram__ConstPool__CONST_hfb707ecf_0[0x1fU];
                        vlSelf->__PVT__dbg_violations 
                            = (0xffffU & ((IData)(1U) 
                                          + (IData)(vlSelf->__PVT__dbg_violations)));
                        if (VL_UNLIKELY((0x14U > (IData)(vlSelf->__PVT__reports)))) {
                            vlSelf->__PVT__reports 
                                = (0xffffU & ((IData)(1U) 
                                              + (IData)(vlSelf->__PVT__reports)));
                            VL_WRITEF("[sdram] cycle %0#: %0s\n",
                                      32,vlSelf->__PVT__cycle,
                                      1024,__Vtask_report__8__msg.data());
                            if (VL_UNLIKELY((0x14U 
                                             == (IData)(vlSelf->__PVT__reports)))) {
                                VL_WRITEF("[sdram] further violations counted but not printed\n");
                            }
                        }
                    }
                    if ((0x400U & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A))) {
                        __Vdlyvset__bank_active__v1 = 1U;
                        __Vdlyvdim0__bank_active__v1 
                            = vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA;
                    }
                }
            }
        } else if ((2U & (IData)(vlSelf->__PVT__cmd))) {
            if ((1U & (IData)(vlSelf->__PVT__cmd))) {
                if (vlSelf->__PVT__bank_active[vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA]) {
                    __Vtask_report__9__msg[0U] = Vtb_sdram__ConstPool__CONST_h8b612c80_0[0U];
                    __Vtask_report__9__msg[1U] = Vtb_sdram__ConstPool__CONST_h8b612c80_0[1U];
                    __Vtask_report__9__msg[2U] = Vtb_sdram__ConstPool__CONST_h8b612c80_0[2U];
                    __Vtask_report__9__msg[3U] = Vtb_sdram__ConstPool__CONST_h8b612c80_0[3U];
                    __Vtask_report__9__msg[4U] = Vtb_sdram__ConstPool__CONST_h8b612c80_0[4U];
                    __Vtask_report__9__msg[5U] = Vtb_sdram__ConstPool__CONST_h8b612c80_0[5U];
                    __Vtask_report__9__msg[6U] = Vtb_sdram__ConstPool__CONST_h8b612c80_0[6U];
                    __Vtask_report__9__msg[7U] = Vtb_sdram__ConstPool__CONST_h8b612c80_0[7U];
                    __Vtask_report__9__msg[8U] = Vtb_sdram__ConstPool__CONST_h8b612c80_0[8U];
                    __Vtask_report__9__msg[9U] = Vtb_sdram__ConstPool__CONST_h8b612c80_0[9U];
                    __Vtask_report__9__msg[0xaU] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0xaU];
                    __Vtask_report__9__msg[0xbU] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0xbU];
                    __Vtask_report__9__msg[0xcU] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0xcU];
                    __Vtask_report__9__msg[0xdU] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0xdU];
                    __Vtask_report__9__msg[0xeU] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0xeU];
                    __Vtask_report__9__msg[0xfU] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0xfU];
                    __Vtask_report__9__msg[0x10U] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x10U];
                    __Vtask_report__9__msg[0x11U] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x11U];
                    __Vtask_report__9__msg[0x12U] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x12U];
                    __Vtask_report__9__msg[0x13U] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x13U];
                    __Vtask_report__9__msg[0x14U] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x14U];
                    __Vtask_report__9__msg[0x15U] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x15U];
                    __Vtask_report__9__msg[0x16U] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x16U];
                    __Vtask_report__9__msg[0x17U] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x17U];
                    __Vtask_report__9__msg[0x18U] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x18U];
                    __Vtask_report__9__msg[0x19U] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x19U];
                    __Vtask_report__9__msg[0x1aU] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x1aU];
                    __Vtask_report__9__msg[0x1bU] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x1bU];
                    __Vtask_report__9__msg[0x1cU] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x1cU];
                    __Vtask_report__9__msg[0x1dU] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x1dU];
                    __Vtask_report__9__msg[0x1eU] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x1eU];
                    __Vtask_report__9__msg[0x1fU] = 
                        Vtb_sdram__ConstPool__CONST_h8b612c80_0[0x1fU];
                    vlSelf->__PVT__dbg_violations = 
                        (0xffffU & ((IData)(1U) + (IData)(vlSelf->__PVT__dbg_violations)));
                    if (VL_UNLIKELY((0x14U > (IData)(vlSelf->__PVT__reports)))) {
                        vlSelf->__PVT__reports = (0xffffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__reports)));
                        VL_WRITEF("[sdram] cycle %0#: %0s\n",
                                  32,vlSelf->__PVT__cycle,
                                  1024,__Vtask_report__9__msg.data());
                        if (VL_UNLIKELY((0x14U == (IData)(vlSelf->__PVT__reports)))) {
                            VL_WRITEF("[sdram] further violations counted but not printed\n");
                        }
                    }
                }
                __Vdlyvval__bank_row__v0 = vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A;
                __Vdlyvset__bank_row__v0 = 1U;
                __Vdlyvdim0__bank_row__v0 = vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA;
                __Vdlyvval__bank_act_cyc__v0 = vlSelf->__PVT__cycle;
                __Vdlyvdim0__bank_act_cyc__v0 = vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA;
                __Vdlyvdim0__bank_active__v2 = vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA;
            } else if ((0x400U & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A))) {
                __Vdlyvset__bank_active__v3 = 1U;
            } else {
                __Vdlyvset__bank_active__v7 = 1U;
                __Vdlyvdim0__bank_active__v7 = vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA;
            }
        } else if ((1U & (IData)(vlSelf->__PVT__cmd))) {
            vlSelf->__PVT__dbg_refreshes = ((IData)(1U) 
                                            + vlSelf->__PVT__dbg_refreshes);
            if (vlSelf->__PVT__seen_refresh) {
                if (((IData)(vlSelf->__PVT__since_refresh) 
                     > (IData)(vlSelf->__PVT__dbg_max_refresh_gap))) {
                    vlSelf->__PVT__dbg_max_refresh_gap 
                        = vlSelf->__PVT__since_refresh;
                }
                if ((0x4b0U < (IData)(vlSelf->__PVT__since_refresh))) {
                    __Vtask_report__10__msg[0U] = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0U];
                    __Vtask_report__10__msg[1U] = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[1U];
                    __Vtask_report__10__msg[2U] = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[2U];
                    __Vtask_report__10__msg[3U] = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[3U];
                    __Vtask_report__10__msg[4U] = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[4U];
                    __Vtask_report__10__msg[5U] = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[5U];
                    __Vtask_report__10__msg[6U] = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[6U];
                    __Vtask_report__10__msg[7U] = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[7U];
                    __Vtask_report__10__msg[8U] = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[8U];
                    __Vtask_report__10__msg[9U] = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[9U];
                    __Vtask_report__10__msg[0xaU] = 
                        Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0xaU];
                    __Vtask_report__10__msg[0xbU] = 
                        Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0xbU];
                    __Vtask_report__10__msg[0xcU] = 
                        Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0xcU];
                    __Vtask_report__10__msg[0xdU] = 
                        Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0xdU];
                    __Vtask_report__10__msg[0xeU] = 
                        Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0xeU];
                    __Vtask_report__10__msg[0xfU] = 
                        Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0xfU];
                    __Vtask_report__10__msg[0x10U] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x10U];
                    __Vtask_report__10__msg[0x11U] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x11U];
                    __Vtask_report__10__msg[0x12U] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x12U];
                    __Vtask_report__10__msg[0x13U] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x13U];
                    __Vtask_report__10__msg[0x14U] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x14U];
                    __Vtask_report__10__msg[0x15U] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x15U];
                    __Vtask_report__10__msg[0x16U] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x16U];
                    __Vtask_report__10__msg[0x17U] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x17U];
                    __Vtask_report__10__msg[0x18U] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x18U];
                    __Vtask_report__10__msg[0x19U] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x19U];
                    __Vtask_report__10__msg[0x1aU] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x1aU];
                    __Vtask_report__10__msg[0x1bU] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x1bU];
                    __Vtask_report__10__msg[0x1cU] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x1cU];
                    __Vtask_report__10__msg[0x1dU] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x1dU];
                    __Vtask_report__10__msg[0x1eU] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x1eU];
                    __Vtask_report__10__msg[0x1fU] 
                        = Vtb_sdram__ConstPool__CONST_h9cf6a441_0[0x1fU];
                    vlSelf->__PVT__dbg_violations = 
                        (0xffffU & ((IData)(1U) + (IData)(vlSelf->__PVT__dbg_violations)));
                    if (VL_UNLIKELY((0x14U > (IData)(vlSelf->__PVT__reports)))) {
                        vlSelf->__PVT__reports = (0xffffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->__PVT__reports)));
                        VL_WRITEF("[sdram] cycle %0#: %0s\n",
                                  32,vlSelf->__PVT__cycle,
                                  1024,__Vtask_report__10__msg.data());
                        if (VL_UNLIKELY((0x14U == (IData)(vlSelf->__PVT__reports)))) {
                            VL_WRITEF("[sdram] further violations counted but not printed\n");
                        }
                    }
                }
            }
            if (vlSelf->__PVT__bank_active[0U]) {
                __Vtask_report__11__msg[0U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0U];
                __Vtask_report__11__msg[1U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[1U];
                __Vtask_report__11__msg[2U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[2U];
                __Vtask_report__11__msg[3U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[3U];
                __Vtask_report__11__msg[4U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[4U];
                __Vtask_report__11__msg[5U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[5U];
                __Vtask_report__11__msg[6U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[6U];
                __Vtask_report__11__msg[7U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[7U];
                __Vtask_report__11__msg[8U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[8U];
                __Vtask_report__11__msg[9U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[9U];
                __Vtask_report__11__msg[0xaU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xaU];
                __Vtask_report__11__msg[0xbU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xbU];
                __Vtask_report__11__msg[0xcU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xcU];
                __Vtask_report__11__msg[0xdU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xdU];
                __Vtask_report__11__msg[0xeU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xeU];
                __Vtask_report__11__msg[0xfU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xfU];
                __Vtask_report__11__msg[0x10U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x10U];
                __Vtask_report__11__msg[0x11U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x11U];
                __Vtask_report__11__msg[0x12U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x12U];
                __Vtask_report__11__msg[0x13U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x13U];
                __Vtask_report__11__msg[0x14U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x14U];
                __Vtask_report__11__msg[0x15U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x15U];
                __Vtask_report__11__msg[0x16U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x16U];
                __Vtask_report__11__msg[0x17U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x17U];
                __Vtask_report__11__msg[0x18U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x18U];
                __Vtask_report__11__msg[0x19U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x19U];
                __Vtask_report__11__msg[0x1aU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1aU];
                __Vtask_report__11__msg[0x1bU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1bU];
                __Vtask_report__11__msg[0x1cU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1cU];
                __Vtask_report__11__msg[0x1dU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1dU];
                __Vtask_report__11__msg[0x1eU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1eU];
                __Vtask_report__11__msg[0x1fU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1fU];
                vlSelf->__PVT__dbg_violations = (0xffffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->__PVT__dbg_violations)));
                if (VL_UNLIKELY((0x14U > (IData)(vlSelf->__PVT__reports)))) {
                    vlSelf->__PVT__reports = (0xffffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->__PVT__reports)));
                    VL_WRITEF("[sdram] cycle %0#: %0s\n",
                              32,vlSelf->__PVT__cycle,
                              1024,__Vtask_report__11__msg.data());
                    if (VL_UNLIKELY((0x14U == (IData)(vlSelf->__PVT__reports)))) {
                        VL_WRITEF("[sdram] further violations counted but not printed\n");
                    }
                }
            }
            vlSelf->__PVT__seen_refresh = 1U;
            __Vdly__since_refresh = 0U;
            if (vlSelf->__PVT__bank_active[1U]) {
                __Vtask_report__11__msg[0U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0U];
                __Vtask_report__11__msg[1U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[1U];
                __Vtask_report__11__msg[2U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[2U];
                __Vtask_report__11__msg[3U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[3U];
                __Vtask_report__11__msg[4U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[4U];
                __Vtask_report__11__msg[5U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[5U];
                __Vtask_report__11__msg[6U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[6U];
                __Vtask_report__11__msg[7U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[7U];
                __Vtask_report__11__msg[8U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[8U];
                __Vtask_report__11__msg[9U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[9U];
                __Vtask_report__11__msg[0xaU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xaU];
                __Vtask_report__11__msg[0xbU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xbU];
                __Vtask_report__11__msg[0xcU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xcU];
                __Vtask_report__11__msg[0xdU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xdU];
                __Vtask_report__11__msg[0xeU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xeU];
                __Vtask_report__11__msg[0xfU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xfU];
                __Vtask_report__11__msg[0x10U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x10U];
                __Vtask_report__11__msg[0x11U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x11U];
                __Vtask_report__11__msg[0x12U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x12U];
                __Vtask_report__11__msg[0x13U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x13U];
                __Vtask_report__11__msg[0x14U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x14U];
                __Vtask_report__11__msg[0x15U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x15U];
                __Vtask_report__11__msg[0x16U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x16U];
                __Vtask_report__11__msg[0x17U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x17U];
                __Vtask_report__11__msg[0x18U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x18U];
                __Vtask_report__11__msg[0x19U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x19U];
                __Vtask_report__11__msg[0x1aU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1aU];
                __Vtask_report__11__msg[0x1bU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1bU];
                __Vtask_report__11__msg[0x1cU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1cU];
                __Vtask_report__11__msg[0x1dU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1dU];
                __Vtask_report__11__msg[0x1eU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1eU];
                __Vtask_report__11__msg[0x1fU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1fU];
                vlSelf->__PVT__dbg_violations = (0xffffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->__PVT__dbg_violations)));
                if (VL_UNLIKELY((0x14U > (IData)(vlSelf->__PVT__reports)))) {
                    vlSelf->__PVT__reports = (0xffffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->__PVT__reports)));
                    VL_WRITEF("[sdram] cycle %0#: %0s\n",
                              32,vlSelf->__PVT__cycle,
                              1024,__Vtask_report__11__msg.data());
                    if (VL_UNLIKELY((0x14U == (IData)(vlSelf->__PVT__reports)))) {
                        VL_WRITEF("[sdram] further violations counted but not printed\n");
                    }
                }
            }
            if (vlSelf->__PVT__bank_active[2U]) {
                __Vtask_report__11__msg[0U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0U];
                __Vtask_report__11__msg[1U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[1U];
                __Vtask_report__11__msg[2U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[2U];
                __Vtask_report__11__msg[3U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[3U];
                __Vtask_report__11__msg[4U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[4U];
                __Vtask_report__11__msg[5U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[5U];
                __Vtask_report__11__msg[6U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[6U];
                __Vtask_report__11__msg[7U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[7U];
                __Vtask_report__11__msg[8U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[8U];
                __Vtask_report__11__msg[9U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[9U];
                __Vtask_report__11__msg[0xaU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xaU];
                __Vtask_report__11__msg[0xbU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xbU];
                __Vtask_report__11__msg[0xcU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xcU];
                __Vtask_report__11__msg[0xdU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xdU];
                __Vtask_report__11__msg[0xeU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xeU];
                __Vtask_report__11__msg[0xfU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xfU];
                __Vtask_report__11__msg[0x10U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x10U];
                __Vtask_report__11__msg[0x11U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x11U];
                __Vtask_report__11__msg[0x12U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x12U];
                __Vtask_report__11__msg[0x13U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x13U];
                __Vtask_report__11__msg[0x14U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x14U];
                __Vtask_report__11__msg[0x15U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x15U];
                __Vtask_report__11__msg[0x16U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x16U];
                __Vtask_report__11__msg[0x17U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x17U];
                __Vtask_report__11__msg[0x18U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x18U];
                __Vtask_report__11__msg[0x19U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x19U];
                __Vtask_report__11__msg[0x1aU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1aU];
                __Vtask_report__11__msg[0x1bU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1bU];
                __Vtask_report__11__msg[0x1cU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1cU];
                __Vtask_report__11__msg[0x1dU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1dU];
                __Vtask_report__11__msg[0x1eU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1eU];
                __Vtask_report__11__msg[0x1fU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1fU];
                vlSelf->__PVT__dbg_violations = (0xffffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->__PVT__dbg_violations)));
                if (VL_UNLIKELY((0x14U > (IData)(vlSelf->__PVT__reports)))) {
                    vlSelf->__PVT__reports = (0xffffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->__PVT__reports)));
                    VL_WRITEF("[sdram] cycle %0#: %0s\n",
                              32,vlSelf->__PVT__cycle,
                              1024,__Vtask_report__11__msg.data());
                    if (VL_UNLIKELY((0x14U == (IData)(vlSelf->__PVT__reports)))) {
                        VL_WRITEF("[sdram] further violations counted but not printed\n");
                    }
                }
            }
            if (vlSelf->__PVT__bank_active[3U]) {
                __Vtask_report__11__msg[0U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0U];
                __Vtask_report__11__msg[1U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[1U];
                __Vtask_report__11__msg[2U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[2U];
                __Vtask_report__11__msg[3U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[3U];
                __Vtask_report__11__msg[4U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[4U];
                __Vtask_report__11__msg[5U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[5U];
                __Vtask_report__11__msg[6U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[6U];
                __Vtask_report__11__msg[7U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[7U];
                __Vtask_report__11__msg[8U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[8U];
                __Vtask_report__11__msg[9U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[9U];
                __Vtask_report__11__msg[0xaU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xaU];
                __Vtask_report__11__msg[0xbU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xbU];
                __Vtask_report__11__msg[0xcU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xcU];
                __Vtask_report__11__msg[0xdU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xdU];
                __Vtask_report__11__msg[0xeU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xeU];
                __Vtask_report__11__msg[0xfU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0xfU];
                __Vtask_report__11__msg[0x10U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x10U];
                __Vtask_report__11__msg[0x11U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x11U];
                __Vtask_report__11__msg[0x12U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x12U];
                __Vtask_report__11__msg[0x13U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x13U];
                __Vtask_report__11__msg[0x14U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x14U];
                __Vtask_report__11__msg[0x15U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x15U];
                __Vtask_report__11__msg[0x16U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x16U];
                __Vtask_report__11__msg[0x17U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x17U];
                __Vtask_report__11__msg[0x18U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x18U];
                __Vtask_report__11__msg[0x19U] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x19U];
                __Vtask_report__11__msg[0x1aU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1aU];
                __Vtask_report__11__msg[0x1bU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1bU];
                __Vtask_report__11__msg[0x1cU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1cU];
                __Vtask_report__11__msg[0x1dU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1dU];
                __Vtask_report__11__msg[0x1eU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1eU];
                __Vtask_report__11__msg[0x1fU] = Vtb_sdram__ConstPool__CONST_hc4bcdcdc_0[0x1fU];
                vlSelf->__PVT__dbg_violations = (0xffffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->__PVT__dbg_violations)));
                if (VL_UNLIKELY((0x14U > (IData)(vlSelf->__PVT__reports)))) {
                    vlSelf->__PVT__reports = (0xffffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->__PVT__reports)));
                    VL_WRITEF("[sdram] cycle %0#: %0s\n",
                              32,vlSelf->__PVT__cycle,
                              1024,__Vtask_report__11__msg.data());
                    if (VL_UNLIKELY((0x14U == (IData)(vlSelf->__PVT__reports)))) {
                        VL_WRITEF("[sdram] further violations counted but not printed\n");
                    }
                }
            }
        } else {
            if ((3U < (7U & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A)))) {
                __Vtask_report__12__msg[0U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0U];
                __Vtask_report__12__msg[1U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[1U];
                __Vtask_report__12__msg[2U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[2U];
                __Vtask_report__12__msg[3U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[3U];
                __Vtask_report__12__msg[4U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[4U];
                __Vtask_report__12__msg[5U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[5U];
                __Vtask_report__12__msg[6U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[6U];
                __Vtask_report__12__msg[7U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[7U];
                __Vtask_report__12__msg[8U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[8U];
                __Vtask_report__12__msg[9U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[9U];
                __Vtask_report__12__msg[0xaU] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0xaU];
                __Vtask_report__12__msg[0xbU] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0xbU];
                __Vtask_report__12__msg[0xcU] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0xcU];
                __Vtask_report__12__msg[0xdU] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0xdU];
                __Vtask_report__12__msg[0xeU] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0xeU];
                __Vtask_report__12__msg[0xfU] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0xfU];
                __Vtask_report__12__msg[0x10U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x10U];
                __Vtask_report__12__msg[0x11U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x11U];
                __Vtask_report__12__msg[0x12U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x12U];
                __Vtask_report__12__msg[0x13U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x13U];
                __Vtask_report__12__msg[0x14U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x14U];
                __Vtask_report__12__msg[0x15U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x15U];
                __Vtask_report__12__msg[0x16U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x16U];
                __Vtask_report__12__msg[0x17U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x17U];
                __Vtask_report__12__msg[0x18U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x18U];
                __Vtask_report__12__msg[0x19U] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x19U];
                __Vtask_report__12__msg[0x1aU] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x1aU];
                __Vtask_report__12__msg[0x1bU] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x1bU];
                __Vtask_report__12__msg[0x1cU] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x1cU];
                __Vtask_report__12__msg[0x1dU] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x1dU];
                __Vtask_report__12__msg[0x1eU] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x1eU];
                __Vtask_report__12__msg[0x1fU] = Vtb_sdram__ConstPool__CONST_hf11d036f_0[0x1fU];
                vlSelf->__PVT__dbg_violations = (0xffffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->__PVT__dbg_violations)));
                if (VL_UNLIKELY((0x14U > (IData)(vlSelf->__PVT__reports)))) {
                    vlSelf->__PVT__reports = (0xffffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->__PVT__reports)));
                    VL_WRITEF("[sdram] cycle %0#: %0s\n",
                              32,vlSelf->__PVT__cycle,
                              1024,__Vtask_report__12__msg.data());
                    if (VL_UNLIKELY((0x14U == (IData)(vlSelf->__PVT__reports)))) {
                        VL_WRITEF("[sdram] further violations counted but not printed\n");
                    }
                }
            }
            vlSelf->__PVT__mode_loaded = 1U;
            vlSelf->__PVT__mode_burst = (7U & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A));
            vlSelf->__PVT__mode_cas = (7U & ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                             >> 4U));
            if ((8U & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A))) {
                __Vtask_report__13__msg[0U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0U];
                __Vtask_report__13__msg[1U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[1U];
                __Vtask_report__13__msg[2U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[2U];
                __Vtask_report__13__msg[3U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[3U];
                __Vtask_report__13__msg[4U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[4U];
                __Vtask_report__13__msg[5U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[5U];
                __Vtask_report__13__msg[6U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[6U];
                __Vtask_report__13__msg[7U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[7U];
                __Vtask_report__13__msg[8U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[8U];
                __Vtask_report__13__msg[9U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[9U];
                __Vtask_report__13__msg[0xaU] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0xaU];
                __Vtask_report__13__msg[0xbU] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0xbU];
                __Vtask_report__13__msg[0xcU] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0xcU];
                __Vtask_report__13__msg[0xdU] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0xdU];
                __Vtask_report__13__msg[0xeU] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0xeU];
                __Vtask_report__13__msg[0xfU] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0xfU];
                __Vtask_report__13__msg[0x10U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x10U];
                __Vtask_report__13__msg[0x11U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x11U];
                __Vtask_report__13__msg[0x12U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x12U];
                __Vtask_report__13__msg[0x13U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x13U];
                __Vtask_report__13__msg[0x14U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x14U];
                __Vtask_report__13__msg[0x15U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x15U];
                __Vtask_report__13__msg[0x16U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x16U];
                __Vtask_report__13__msg[0x17U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x17U];
                __Vtask_report__13__msg[0x18U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x18U];
                __Vtask_report__13__msg[0x19U] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x19U];
                __Vtask_report__13__msg[0x1aU] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x1aU];
                __Vtask_report__13__msg[0x1bU] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x1bU];
                __Vtask_report__13__msg[0x1cU] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x1cU];
                __Vtask_report__13__msg[0x1dU] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x1dU];
                __Vtask_report__13__msg[0x1eU] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x1eU];
                __Vtask_report__13__msg[0x1fU] = Vtb_sdram__ConstPool__CONST_h1ed05db8_0[0x1fU];
                vlSelf->__PVT__dbg_violations = (0xffffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->__PVT__dbg_violations)));
                if (VL_UNLIKELY((0x14U > (IData)(vlSelf->__PVT__reports)))) {
                    vlSelf->__PVT__reports = (0xffffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->__PVT__reports)));
                    VL_WRITEF("[sdram] cycle %0#: %0s\n",
                              32,vlSelf->__PVT__cycle,
                              1024,__Vtask_report__13__msg.data());
                    if (VL_UNLIKELY((0x14U == (IData)(vlSelf->__PVT__reports)))) {
                        VL_WRITEF("[sdram] further violations counted but not printed\n");
                    }
                }
            }
            if (((2U != (7U & ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                               >> 4U))) & (3U != (7U 
                                                  & ((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A) 
                                                     >> 4U))))) {
                __Vtask_report__14__msg[0U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0U];
                __Vtask_report__14__msg[1U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[1U];
                __Vtask_report__14__msg[2U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[2U];
                __Vtask_report__14__msg[3U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[3U];
                __Vtask_report__14__msg[4U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[4U];
                __Vtask_report__14__msg[5U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[5U];
                __Vtask_report__14__msg[6U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[6U];
                __Vtask_report__14__msg[7U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[7U];
                __Vtask_report__14__msg[8U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[8U];
                __Vtask_report__14__msg[9U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[9U];
                __Vtask_report__14__msg[0xaU] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0xaU];
                __Vtask_report__14__msg[0xbU] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0xbU];
                __Vtask_report__14__msg[0xcU] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0xcU];
                __Vtask_report__14__msg[0xdU] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0xdU];
                __Vtask_report__14__msg[0xeU] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0xeU];
                __Vtask_report__14__msg[0xfU] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0xfU];
                __Vtask_report__14__msg[0x10U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x10U];
                __Vtask_report__14__msg[0x11U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x11U];
                __Vtask_report__14__msg[0x12U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x12U];
                __Vtask_report__14__msg[0x13U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x13U];
                __Vtask_report__14__msg[0x14U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x14U];
                __Vtask_report__14__msg[0x15U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x15U];
                __Vtask_report__14__msg[0x16U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x16U];
                __Vtask_report__14__msg[0x17U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x17U];
                __Vtask_report__14__msg[0x18U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x18U];
                __Vtask_report__14__msg[0x19U] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x19U];
                __Vtask_report__14__msg[0x1aU] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x1aU];
                __Vtask_report__14__msg[0x1bU] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x1bU];
                __Vtask_report__14__msg[0x1cU] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x1cU];
                __Vtask_report__14__msg[0x1dU] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x1dU];
                __Vtask_report__14__msg[0x1eU] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x1eU];
                __Vtask_report__14__msg[0x1fU] = Vtb_sdram__ConstPool__CONST_h66ec84ff_0[0x1fU];
                vlSelf->__PVT__dbg_violations = (0xffffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->__PVT__dbg_violations)));
                if (VL_UNLIKELY((0x14U > (IData)(vlSelf->__PVT__reports)))) {
                    vlSelf->__PVT__reports = (0xffffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->__PVT__reports)));
                    VL_WRITEF("[sdram] cycle %0#: %0s\n",
                              32,vlSelf->__PVT__cycle,
                              1024,__Vtask_report__14__msg.data());
                    if (VL_UNLIKELY((0x14U == (IData)(vlSelf->__PVT__reports)))) {
                        VL_WRITEF("[sdram] further violations counted but not printed\n");
                    }
                }
            }
        }
    } else {
        __Vdly__cycle = ((IData)(1U) + vlSelf->__PVT__cycle);
        __Vdly__since_refresh = 0U;
        vlSelf->__PVT__dq_oe = 0U;
        __Vdlyvset__rd_valid__v16 = 1U;
    }
    vlSelf->__PVT__cycle = __Vdly__cycle;
    vlSelf->__PVT__since_refresh = __Vdly__since_refresh;
    if (__Vdlyvset__mem__v0) {
        vlSelf->mem[__Vdlyvdim0__mem__v0] = (((~ ((IData)(0xffU) 
                                                  << (IData)(__Vdlyvlsb__mem__v0))) 
                                              & vlSelf->mem
                                              [__Vdlyvdim0__mem__v0]) 
                                             | (0xffffU 
                                                & ((IData)(__Vdlyvval__mem__v0) 
                                                   << (IData)(__Vdlyvlsb__mem__v0))));
    }
    if (__Vdlyvset__mem__v1) {
        vlSelf->mem[__Vdlyvdim0__mem__v1] = (((~ ((IData)(0xffU) 
                                                  << (IData)(__Vdlyvlsb__mem__v1))) 
                                              & vlSelf->mem
                                              [__Vdlyvdim0__mem__v1]) 
                                             | (0xffffU 
                                                & ((IData)(__Vdlyvval__mem__v1) 
                                                   << (IData)(__Vdlyvlsb__mem__v1))));
    }
    if (__Vdlyvset__bank_active__v0) {
        vlSelf->__PVT__bank_active[__Vdlyvdim0__bank_active__v0] = 0U;
    }
    if (__Vdlyvset__bank_active__v1) {
        vlSelf->__PVT__bank_active[__Vdlyvdim0__bank_active__v1] = 0U;
    }
    if (__Vdlyvset__bank_row__v0) {
        vlSelf->__PVT__bank_act_cyc[__Vdlyvdim0__bank_act_cyc__v0] 
            = __Vdlyvval__bank_act_cyc__v0;
        vlSelf->__PVT__bank_row[__Vdlyvdim0__bank_row__v0] 
            = __Vdlyvval__bank_row__v0;
        vlSelf->__PVT__bank_active[__Vdlyvdim0__bank_active__v2] = 1U;
    }
    if (__Vdlyvset__bank_active__v3) {
        vlSelf->__PVT__bank_active[0U] = 0U;
        vlSelf->__PVT__bank_active[1U] = 0U;
        vlSelf->__PVT__bank_active[2U] = 0U;
        vlSelf->__PVT__bank_active[3U] = 0U;
    }
    if (__Vdlyvset__bank_active__v7) {
        vlSelf->__PVT__bank_active[__Vdlyvdim0__bank_active__v7] = 0U;
    }
    if (__Vdlyvset__rd_data__v0) {
        vlSelf->__PVT__rd_valid[0U] = __Vdlyvval__rd_valid__v0;
        vlSelf->__PVT__rd_valid[1U] = __Vdlyvval__rd_valid__v1;
        vlSelf->__PVT__rd_valid[2U] = __Vdlyvval__rd_valid__v2;
        vlSelf->__PVT__rd_valid[3U] = __Vdlyvval__rd_valid__v3;
        vlSelf->__PVT__rd_valid[4U] = __Vdlyvval__rd_valid__v4;
        vlSelf->__PVT__rd_valid[5U] = __Vdlyvval__rd_valid__v5;
        vlSelf->__PVT__rd_valid[6U] = __Vdlyvval__rd_valid__v6;
        vlSelf->__PVT__rd_valid[7U] = 0U;
        vlSelf->__PVT__rd_data[0U] = __Vdlyvval__rd_data__v0;
        vlSelf->__PVT__rd_data[1U] = __Vdlyvval__rd_data__v1;
        vlSelf->__PVT__rd_data[2U] = __Vdlyvval__rd_data__v2;
        vlSelf->__PVT__rd_data[3U] = __Vdlyvval__rd_data__v3;
        vlSelf->__PVT__rd_data[4U] = __Vdlyvval__rd_data__v4;
        vlSelf->__PVT__rd_data[5U] = __Vdlyvval__rd_data__v5;
        vlSelf->__PVT__rd_data[6U] = __Vdlyvval__rd_data__v6;
    }
    if (__Vdlyvset__rd_data__v7) {
        vlSelf->__PVT__rd_valid[__Vdlyvdim0__rd_valid__v8] = 1U;
        vlSelf->__PVT__rd_data[__Vdlyvdim0__rd_data__v7] 
            = __Vdlyvval__rd_data__v7;
    }
    if (__Vdlyvset__rd_data__v8) {
        vlSelf->__PVT__rd_valid[__Vdlyvdim0__rd_valid__v9] = 1U;
        vlSelf->__PVT__rd_data[__Vdlyvdim0__rd_data__v8] 
            = __Vdlyvval__rd_data__v8;
    }
    if (__Vdlyvset__rd_data__v9) {
        vlSelf->__PVT__rd_valid[__Vdlyvdim0__rd_valid__v10] = 1U;
        vlSelf->__PVT__rd_data[__Vdlyvdim0__rd_data__v9] 
            = __Vdlyvval__rd_data__v9;
    }
    if (__Vdlyvset__rd_data__v10) {
        vlSelf->__PVT__rd_valid[__Vdlyvdim0__rd_valid__v11] = 1U;
        vlSelf->__PVT__rd_data[__Vdlyvdim0__rd_data__v10] 
            = __Vdlyvval__rd_data__v10;
    }
    if (__Vdlyvset__rd_data__v11) {
        vlSelf->__PVT__rd_valid[__Vdlyvdim0__rd_valid__v12] = 1U;
        vlSelf->__PVT__rd_data[__Vdlyvdim0__rd_data__v11] 
            = __Vdlyvval__rd_data__v11;
    }
    if (__Vdlyvset__rd_data__v12) {
        vlSelf->__PVT__rd_valid[__Vdlyvdim0__rd_valid__v13] = 1U;
        vlSelf->__PVT__rd_data[__Vdlyvdim0__rd_data__v12] 
            = __Vdlyvval__rd_data__v12;
    }
    if (__Vdlyvset__rd_data__v13) {
        vlSelf->__PVT__rd_valid[__Vdlyvdim0__rd_valid__v14] = 1U;
        vlSelf->__PVT__rd_data[__Vdlyvdim0__rd_data__v13] 
            = __Vdlyvval__rd_data__v13;
    }
    if (__Vdlyvset__rd_data__v14) {
        vlSelf->__PVT__rd_valid[__Vdlyvdim0__rd_valid__v15] = 1U;
        vlSelf->__PVT__rd_data[__Vdlyvdim0__rd_data__v14] 
            = __Vdlyvval__rd_data__v14;
    }
    if (__Vdlyvset__rd_valid__v16) {
        vlSelf->__PVT__bank_active[0U] = 0U;
        vlSelf->__PVT__bank_active[1U] = 0U;
        vlSelf->__PVT__bank_active[2U] = 0U;
        vlSelf->__PVT__bank_active[3U] = 0U;
        vlSelf->__PVT__rd_valid[0U] = 0U;
        vlSelf->__PVT__rd_valid[1U] = 0U;
        vlSelf->__PVT__rd_valid[2U] = 0U;
        vlSelf->__PVT__rd_valid[3U] = 0U;
        vlSelf->__PVT__rd_valid[4U] = 0U;
        vlSelf->__PVT__rd_valid[5U] = 0U;
        vlSelf->__PVT__rd_valid[6U] = 0U;
        vlSelf->__PVT__rd_valid[7U] = 0U;
    }
    vlSelf->__PVT__burst_len = ((0U == (IData)(vlSelf->__PVT__mode_burst))
                                 ? 1U : ((1U == (IData)(vlSelf->__PVT__mode_burst))
                                          ? 2U : ((2U 
                                                   == (IData)(vlSelf->__PVT__mode_burst))
                                                   ? 4U
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelf->__PVT__mode_burst))
                                                    ? 8U
                                                    : 1U))));
    vlSelf->__PVT__cl_slot = ((2U <= (IData)(vlSelf->__PVT__mode_cas))
                               ? (7U & ((IData)(vlSelf->__PVT__mode_cas) 
                                        - (IData)(2U)))
                               : 0U);
}

VL_INLINE_OPT void Vtb_sdram_sdram_mt48lc16m16a2___nba_sequent__TOP__tb_sdram__chip__1(Vtb_sdram_sdram_mt48lc16m16a2* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_sdram_sdram_mt48lc16m16a2___nba_sequent__TOP__tb_sdram__chip__1\n"); );
    // Body
    vlSelf->__PVT__cmd = (((IData)(vlSymsp->TOP__tb_sdram.__PVT__ctl__DOT__chip) 
                           << 3U) | (IData)(vlSymsp->TOP__tb_sdram.__PVT__ctl__DOT__command));
    vlSelf->__PVT__cmd_index = (((IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA) 
                                 << 0x16U) | ((vlSelf->__PVT__bank_row
                                               [vlSymsp->TOP__tb_sdram.__PVT__SDRAM_BA] 
                                               << 9U) 
                                              | (0x1ffU 
                                                 & (IData)(vlSymsp->TOP__tb_sdram.__PVT__SDRAM_A))));
}
