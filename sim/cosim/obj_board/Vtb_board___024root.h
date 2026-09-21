// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_board.h for the primary calling header

#ifndef VERILATED_VTB_BOARD___024ROOT_H_
#define VERILATED_VTB_BOARD___024ROOT_H_  // guard

#include "verilated.h"
class Vtb_board_tb_board;


class Vtb_board__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_board___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtb_board_tb_board* tb_board;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_OUT8(ram_req,0,0);
    VL_OUT8(ram_burst,0,0);
    VL_OUT8(ram_we,0,0);
    VL_OUT8(ram_be,3,0);
    VL_IN8(ram_ack,0,0);
    VL_OUT8(io_req,0,0);
    VL_OUT8(io_we,0,0);
    VL_OUT8(io_be,3,0);
    VL_IN8(io_ack,0,0);
    VL_IN8(io_err,0,0);
    VL_IN8(irq_in,5,0);
    VL_OUT8(retire_valid,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT(ram_addr,24,0);
    VL_OUT(ram_wdata,31,0);
    VL_IN(ram_rdata,31,0);
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
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_board__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_board___024root(Vtb_board__Syms* symsp, const char* v__name);
    ~Vtb_board___024root();
    VL_UNCOPYABLE(Vtb_board___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
