// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_board__pch.h"
#include "Vtb_board.h"
#include "Vtb_board___024root.h"
#include "Vtb_board_tb_board.h"
#include "Vtb_board_r3900_cached__Cz1.h"
#include "Vtb_board_r3900__Cz2.h"

// FUNCTIONS
Vtb_board__Syms::~Vtb_board__Syms()
{
}

Vtb_board__Syms::Vtb_board__Syms(VerilatedContext* contextp, const char* namep, Vtb_board* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__tb_board{this, Verilated::catName(namep, "tb_board")}
    , TOP__tb_board__cpu{this, Verilated::catName(namep, "tb_board.cpu")}
    , TOP__tb_board__cpu__cpu{this, Verilated::catName(namep, "tb_board.cpu.cpu")}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.tb_board = &TOP__tb_board;
    TOP__tb_board.cpu = &TOP__tb_board__cpu;
    TOP__tb_board__cpu.cpu = &TOP__tb_board__cpu__cpu;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__tb_board.__Vconfigure(true);
    TOP__tb_board__cpu.__Vconfigure(true);
    TOP__tb_board__cpu__cpu.__Vconfigure(true);
    // Setup scopes
    __Vscope_tb_board__cpu__cpu.configure(this, name(), "tb_board.cpu.cpu", "cpu", 0, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_tb_board__cpu__cpu.varInsert(__Vfinal,"cache_ops", &(TOP__tb_board__cpu__cpu.cache_ops), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,1 ,63,0);
        __Vscope_tb_board__cpu__cpu.varInsert(__Vfinal,"cycle_count", &(TOP__tb_board__cpu__cpu.cycle_count), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,1 ,63,0);
        __Vscope_tb_board__cpu__cpu.varInsert(__Vfinal,"exc_count", &(TOP__tb_board__cpu__cpu.exc_count), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,1 ,63,0);
        __Vscope_tb_board__cpu__cpu.varInsert(__Vfinal,"hi", &(TOP__tb_board__cpu__cpu.hi), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_tb_board__cpu__cpu.varInsert(__Vfinal,"insn_count", &(TOP__tb_board__cpu__cpu.insn_count), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,1 ,63,0);
        __Vscope_tb_board__cpu__cpu.varInsert(__Vfinal,"lo", &(TOP__tb_board__cpu__cpu.lo), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_tb_board__cpu__cpu.varInsert(__Vfinal,"regs", &(TOP__tb_board__cpu__cpu.regs), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,2 ,31,0 ,0,31);
    }
}
