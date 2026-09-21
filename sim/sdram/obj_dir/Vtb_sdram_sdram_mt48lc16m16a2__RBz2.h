// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_sdram.h for the primary calling header

#ifndef VERILATED_VTB_SDRAM_SDRAM_MT48LC16M16A2__RBZ2_H_
#define VERILATED_VTB_SDRAM_SDRAM_MT48LC16M16A2__RBZ2_H_  // guard

#include "verilated.h"


class Vtb_sdram__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_sdram_sdram_mt48lc16m16a2__RBz2 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__rst,0,0);
    VL_IN8(__PVT__SDRAM_nCS,0,0);
    VL_IN8(__PVT__SDRAM_nRAS,0,0);
    VL_IN8(__PVT__SDRAM_nCAS,0,0);
    VL_IN8(__PVT__SDRAM_nWE,0,0);
    VL_IN8(__PVT__SDRAM_BA,1,0);
    VL_IN8(__PVT__SDRAM_DQML,0,0);
    VL_IN8(__PVT__SDRAM_DQMH,0,0);
    VL_OUT8(__PVT__SDRAM_DQ_OE,0,0);
    CData/*3:0*/ __PVT__cmd;
    CData/*0:0*/ __PVT__mode_loaded;
    CData/*2:0*/ __PVT__mode_cas;
    CData/*2:0*/ __PVT__mode_burst;
    CData/*0:0*/ __PVT__dq_oe;
    CData/*0:0*/ __PVT__seen_refresh;
    CData/*2:0*/ __PVT__cl_slot;
    CData/*4:0*/ __PVT__burst_len;
    VL_IN16(__PVT__SDRAM_A,12,0);
    VL_IN16(__PVT__SDRAM_DQ_I,15,0);
    VL_OUT16(__PVT__SDRAM_DQ_O,15,0);
    VL_OUT16(__PVT__dbg_max_refresh_gap,15,0);
    VL_OUT16(__PVT__dbg_violations,15,0);
    VL_OUT16(__PVT__dbg_last_col,15,0);
    VL_OUT16(__PVT__dbg_last_row,15,0);
    VL_OUT16(__PVT__dbg_last_a,15,0);
    SData/*15:0*/ __PVT__dq_out;
    SData/*15:0*/ __PVT__since_refresh;
    SData/*15:0*/ __PVT__reports;
    SData/*8:0*/ __PVT__burst_index__Vstatic__c;
    VL_OUT(__PVT__dbg_reads,31,0);
    VL_OUT(__PVT__dbg_writes,31,0);
    VL_OUT(__PVT__dbg_refreshes,31,0);
    VL_OUT(__PVT__dbg_last_index,31,0);
    IData/*31:0*/ __PVT__cycle;
    IData/*23:0*/ __PVT__cmd_index;
    VlUnpacked<SData/*15:0*/, 16777216> mem;
    VlUnpacked<CData/*0:0*/, 4> __PVT__bank_active;
    VlUnpacked<SData/*12:0*/, 4> __PVT__bank_row;
    VlUnpacked<IData/*31:0*/, 4> __PVT__bank_act_cyc;
    VlUnpacked<SData/*15:0*/, 8> __PVT__rd_data;
    VlUnpacked<CData/*0:0*/, 8> __PVT__rd_valid;

    // INTERNAL VARIABLES
    Vtb_sdram__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_sdram_sdram_mt48lc16m16a2__RBz2(Vtb_sdram__Syms* symsp, const char* v__name);
    ~Vtb_sdram_sdram_mt48lc16m16a2__RBz2();
    VL_UNCOPYABLE(Vtb_sdram_sdram_mt48lc16m16a2__RBz2);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    uint32_t peek_word(uint32_t index);
};


#endif  // guard
