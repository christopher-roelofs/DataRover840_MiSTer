// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram.h"
#include "Vtb_sdram___024root.h"
#include "Vtb_sdram_tb_sdram.h"
#include "Vtb_sdram_sdram_mt48lc16m16a2.h"
#include "Vtb_sdram_r3900_cached__Cz1.h"
#include "Vtb_sdram_r3900__Cz2.h"

// FUNCTIONS
Vtb_sdram__Syms::~Vtb_sdram__Syms()
{
}

Vtb_sdram__Syms::Vtb_sdram__Syms(VerilatedContext* contextp, const char* namep, Vtb_sdram* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__tb_sdram{this, Verilated::catName(namep, "tb_sdram")}
    , TOP__tb_sdram__chip{this, Verilated::catName(namep, "tb_sdram.chip")}
    , TOP__tb_sdram__cpu{this, Verilated::catName(namep, "tb_sdram.cpu")}
    , TOP__tb_sdram__cpu__cpu{this, Verilated::catName(namep, "tb_sdram.cpu.cpu")}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.tb_sdram = &TOP__tb_sdram;
    TOP__tb_sdram.chip = &TOP__tb_sdram__chip;
    TOP__tb_sdram.cpu = &TOP__tb_sdram__cpu;
    TOP__tb_sdram__cpu.cpu = &TOP__tb_sdram__cpu__cpu;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__tb_sdram.__Vconfigure(true);
    TOP__tb_sdram__chip.__Vconfigure(true);
    TOP__tb_sdram__cpu.__Vconfigure(true);
    TOP__tb_sdram__cpu__cpu.__Vconfigure(true);
    // Setup scopes
    __Vscope_tb_sdram__chip.configure(this, name(), "tb_sdram.chip", "chip", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_sdram__cpu__cpu.configure(this, name(), "tb_sdram.cpu.cpu", "cpu", 0, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_tb_sdram__chip.varInsert(__Vfinal,"mem", &(TOP__tb_sdram__chip.mem), false, VLVT_UINT16,VLVD_NODIR|VLVF_PUB_RW,2 ,15,0 ,0,16777215);
        __Vscope_tb_sdram__cpu__cpu.varInsert(__Vfinal,"cache_ops", &(TOP__tb_sdram__cpu__cpu.cache_ops), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,1 ,63,0);
        __Vscope_tb_sdram__cpu__cpu.varInsert(__Vfinal,"cycle_count", &(TOP__tb_sdram__cpu__cpu.cycle_count), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,1 ,63,0);
        __Vscope_tb_sdram__cpu__cpu.varInsert(__Vfinal,"exc_count", &(TOP__tb_sdram__cpu__cpu.exc_count), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,1 ,63,0);
        __Vscope_tb_sdram__cpu__cpu.varInsert(__Vfinal,"hi", &(TOP__tb_sdram__cpu__cpu.hi), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_tb_sdram__cpu__cpu.varInsert(__Vfinal,"insn_count", &(TOP__tb_sdram__cpu__cpu.insn_count), false, VLVT_UINT64,VLVD_NODIR|VLVF_PUB_RW,1 ,63,0);
        __Vscope_tb_sdram__cpu__cpu.varInsert(__Vfinal,"lo", &(TOP__tb_sdram__cpu__cpu.lo), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_tb_sdram__cpu__cpu.varInsert(__Vfinal,"regs", &(TOP__tb_sdram__cpu__cpu.regs), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,2 ,31,0 ,0,31);
    }
}
