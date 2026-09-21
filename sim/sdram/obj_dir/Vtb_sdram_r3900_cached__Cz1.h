// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_sdram.h for the primary calling header

#ifndef VERILATED_VTB_SDRAM_R3900_CACHED__CZ1_H_
#define VERILATED_VTB_SDRAM_R3900_CACHED__CZ1_H_  // guard

#include "verilated.h"
class Vtb_sdram_r3900__Cz2;


class Vtb_sdram__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_sdram_r3900_cached__Cz1 final : public VerilatedModule {
  public:
    // CELLS
    Vtb_sdram_r3900__Cz2* cpu;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(__PVT__clk,0,0);
        VL_IN8(__PVT__rst_n,0,0);
        VL_IN8(__PVT__cen,0,0);
        VL_OUT8(__PVT__imem_req,0,0);
        VL_OUT8(__PVT__imem_burst,0,0);
        VL_IN8(__PVT__imem_ack,0,0);
        VL_IN8(__PVT__imem_err,0,0);
        VL_OUT8(__PVT__dmem_req,0,0);
        VL_OUT8(__PVT__dmem_burst,0,0);
        VL_OUT8(__PVT__dmem_we,0,0);
        VL_OUT8(__PVT__dmem_be,3,0);
        VL_IN8(__PVT__dmem_ack,0,0);
        VL_IN8(__PVT__dmem_err,0,0);
        VL_IN8(__PVT__irq_in,5,0);
        VL_OUT8(__PVT__retire_valid,0,0);
        CData/*0:0*/ __PVT__dack;
        CData/*0:0*/ __PVT__derr;
        CData/*1:0*/ __PVT__cache__DOT__istate;
        CData/*1:0*/ __PVT__cache__DOT__icnt;
        CData/*0:0*/ __PVT__cache__DOT__itag_we;
        CData/*7:0*/ __PVT__cache__DOT__itag_wa;
        CData/*0:0*/ __PVT__cache__DOT__i_idle;
        CData/*0:0*/ __PVT__cache__DOT__i_hit;
        CData/*0:0*/ __PVT__cache__DOT__i_thru;
        CData/*0:0*/ __PVT__cache__DOT__i_fill_fail;
        CData/*1:0*/ __PVT__cache__DOT__dstate;
        CData/*1:0*/ __PVT__cache__DOT__dcnt;
        CData/*0:0*/ __PVT__cache__DOT__dtag_we;
        CData/*5:0*/ __PVT__cache__DOT__dtag_wa;
        CData/*7:0*/ __PVT__cache__DOT__dram_ra_q;
        CData/*0:0*/ __PVT__cache__DOT__stf_v;
        CData/*7:0*/ __PVT__cache__DOT__stf_a;
        CData/*0:0*/ __PVT__cache__DOT__d_idle;
        CData/*0:0*/ __PVT__cache__DOT__d_read_hit;
        CData/*0:0*/ __PVT__cache__DOT__d_thru;
        CData/*0:0*/ __PVT__cache__DOT__d_store_hit;
        CData/*0:0*/ __PVT__cache__DOT__d_fill_fail;
        CData/*0:0*/ __PVT__cache__DOT__i_fill_beat;
        CData/*0:0*/ __PVT__cache__DOT__d_fill_beat;
        CData/*0:0*/ cache__DOT____VdfgTmp_h6d079f16__0;
        CData/*0:0*/ cache__DOT____VdfgTmp_h619d70f7__0;
        CData/*0:0*/ cache__DOT____VdfgTmp_h53db0a74__0;
        CData/*0:0*/ cache__DOT____VdfgTmp_h6b597d1c__0;
        CData/*0:0*/ cache__DOT____VdfgTmp_ha01f3fd2__0;
        CData/*1:0*/ __Vdly__cache__DOT__dstate;
        CData/*1:0*/ __Vdly__cache__DOT__dcnt;
        CData/*1:0*/ __Vdly__cache__DOT__istate;
        CData/*1:0*/ __Vdly__cache__DOT__icnt;
        SData/*8:0*/ __PVT__cache__DOT__init_cnt;
        SData/*8:0*/ __Vdly__cache__DOT__init_cnt;
        VL_OUT(__PVT__imem_addr,31,0);
        VL_IN(__PVT__imem_rdata,31,0);
        VL_OUT(__PVT__dmem_addr,31,0);
        VL_OUT(__PVT__dmem_wdata,31,0);
        VL_IN(__PVT__dmem_rdata,31,0);
        VL_OUT(__PVT__retire_pc,31,0);
        VL_OUT(__PVT__retire_insn,31,0);
        VL_OUT(__PVT__retire_next_pc,31,0);
        VL_OUT(__PVT__ihit_count,31,0);
        VL_OUT(__PVT__imiss_count,31,0);
        VL_OUT(__PVT__dhit_count,31,0);
        VL_OUT(__PVT__dmiss_count,31,0);
        IData/*31:0*/ __PVT__drd;
        IData/*31:0*/ __PVT__cache__DOT__iline;
    };
    struct {
        IData/*20:0*/ __PVT__cache__DOT__itag_wd;
        IData/*31:0*/ __PVT__cache__DOT__iram_q;
        IData/*20:0*/ __PVT__cache__DOT__itagv_q;
        IData/*31:0*/ __PVT__cache__DOT__dline;
        IData/*22:0*/ __PVT__cache__DOT__dtag_wd;
        IData/*31:0*/ __PVT__cache__DOT__dram_q;
        IData/*22:0*/ __PVT__cache__DOT__dtagv_q;
        IData/*31:0*/ __PVT__cache__DOT__stf_d;
        IData/*31:0*/ __PVT__cache__DOT__dram_eff;
        IData/*31:0*/ __PVT__cache__DOT__d_merged;
        VlUnpacked<IData/*31:0*/, 1024> __PVT__cache__DOT__idata;
        VlUnpacked<IData/*20:0*/, 256> __PVT__cache__DOT__itagv;
        VlUnpacked<IData/*31:0*/, 256> __PVT__cache__DOT__ddata;
        VlUnpacked<IData/*22:0*/, 64> __PVT__cache__DOT__dtagv;
    };

    // INTERNAL VARIABLES
    Vtb_sdram__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_sdram_r3900_cached__Cz1(Vtb_sdram__Syms* symsp, const char* v__name);
    ~Vtb_sdram_r3900_cached__Cz1();
    VL_UNCOPYABLE(Vtb_sdram_r3900_cached__Cz1);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
