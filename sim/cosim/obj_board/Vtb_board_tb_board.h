// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_board.h for the primary calling header

#ifndef VERILATED_VTB_BOARD_TB_BOARD_H_
#define VERILATED_VTB_BOARD_TB_BOARD_H_  // guard

#include "verilated.h"
class Vtb_board_r3900_cached__Cz1;


class Vtb_board__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_board_tb_board final : public VerilatedModule {
  public:
    // CELLS
    Vtb_board_r3900_cached__Cz1* cpu;

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
    CData/*0:0*/ __PVT__iack;
    CData/*0:0*/ __PVT__ierr;
    CData/*0:0*/ __PVT__dack;
    CData/*0:0*/ __PVT__derr;
    CData/*1:0*/ __PVT__board__DOT__owner;
    CData/*0:0*/ __PVT__board__DOT__d_wants_ram;
    CData/*0:0*/ __PVT__board__DOT__i_wants_ram;
    CData/*0:0*/ __PVT__board__DOT__grant_d;
    CData/*0:0*/ __PVT__board__DOT__d_wants_io;
    CData/*0:0*/ __PVT__board__DOT__i_wants_io;
    CData/*0:0*/ board__DOT____VdfgTmp_h22b91ed1__0;
    CData/*0:0*/ board__DOT____VdfgTmp_hdb4dbddb__0;
    CData/*0:0*/ board__DOT____VdfgTmp_h223955ac__0;
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
    IData/*31:0*/ __PVT__ird;
    IData/*31:0*/ __PVT__drd;
    IData/*26:0*/ __PVT__board__DOT__i_dec;
    IData/*26:0*/ __PVT__board__DOT__d_dec;

    // INTERNAL VARIABLES
    Vtb_board__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_board_tb_board(Vtb_board__Syms* symsp, const char* v__name);
    ~Vtb_board_tb_board();
    VL_UNCOPYABLE(Vtb_board_tb_board);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
