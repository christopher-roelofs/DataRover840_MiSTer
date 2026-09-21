// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_sdram.h for the primary calling header

#ifndef VERILATED_VTB_SDRAM___024ROOT_H_
#define VERILATED_VTB_SDRAM___024ROOT_H_  // guard

#include "verilated.h"
class Vtb_sdram_tb_sdram;


class Vtb_sdram__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_sdram___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtb_sdram_tb_sdram* tb_sdram;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(clk_div,7,0);
    VL_OUT8(io_req,0,0);
    VL_OUT8(io_we,0,0);
    VL_OUT8(io_be,3,0);
    VL_IN8(io_ack,0,0);
    VL_IN8(io_err,0,0);
    VL_IN8(irq_in,5,0);
    VL_OUT8(retire_valid,0,0);
    VL_OUT8(dbg_ram_ack,0,0);
    VL_OUT8(dbg_ram_req,0,0);
    VL_OUT8(dbg_ram_burst,0,0);
    VL_OUT8(dbg_ch2_req,0,0);
    VL_OUT8(dbg_dack,0,0);
    VL_OUT8(dbg_iack,0,0);
    VL_OUT8(dbg_dreq,0,0);
    VL_OUT8(dbg_ireq,0,0);
    VL_OUT8(dbg_start,0,0);
    VL_OUT8(dbg_start_kind,1,0);
    VL_OUT8(dbg_state,3,0);
    VL_OUT8(dbg_cen,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(dbg_max_refresh_gap,15,0);
    VL_OUT16(dbg_violations,15,0);
    VL_OUT16(dbg_last_col,15,0);
    VL_OUT16(dbg_last_row,15,0);
    VL_OUT16(dbg_last_a,15,0);
    VL_OUT(io_addr,31,0);
    VL_OUT(io_wdata,31,0);
    VL_IN(io_rdata,31,0);
    VL_OUT(retire_pc,31,0);
    VL_OUT(retire_insn,31,0);
    VL_OUT(retire_next_pc,31,0);
    VL_OUT(ihit_count,31,0);
    VL_OUT(imiss_count,31,0);
    VL_OUT(dhit_count,31,0);
    VL_OUT(dmiss_count,31,0);
    VL_OUT(dbg_reads,31,0);
    VL_OUT(dbg_writes,31,0);
    VL_OUT(dbg_refreshes,31,0);
    VL_OUT(dbg_ram_addr,24,0);
    VL_OUT(dbg_ram_rdata,31,0);
    VL_OUT(dbg_last_index,31,0);
    VL_OUT(dbg_ch2_addr,26,1);
    VL_OUT(dbg_start_addr,24,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_sdram__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_sdram___024root(Vtb_sdram__Syms* symsp, const char* v__name);
    ~Vtb_sdram___024root();
    VL_UNCOPYABLE(Vtb_sdram___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
