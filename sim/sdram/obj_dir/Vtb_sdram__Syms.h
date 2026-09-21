// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_SDRAM__SYMS_H_
#define VERILATED_VTB_SDRAM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_sdram.h"

// INCLUDE MODULE CLASSES
#include "Vtb_sdram___024root.h"
#include "Vtb_sdram_tb_sdram.h"
#include "Vtb_sdram_sdram_mt48lc16m16a2.h"
#include "Vtb_sdram_r3900_cached__Cz1.h"
#include "Vtb_sdram_r3900__Cz2.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb_sdram__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_sdram* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_sdram___024root            TOP;
    Vtb_sdram_tb_sdram             TOP__tb_sdram;
    Vtb_sdram_sdram_mt48lc16m16a2  TOP__tb_sdram__chip;
    Vtb_sdram_r3900_cached__Cz1    TOP__tb_sdram__cpu;
    Vtb_sdram_r3900__Cz2           TOP__tb_sdram__cpu__cpu;

    // SCOPE NAMES
    VerilatedScope __Vscope_tb_sdram__chip;
    VerilatedScope __Vscope_tb_sdram__cpu__cpu;

    // CONSTRUCTORS
    Vtb_sdram__Syms(VerilatedContext* contextp, const char* namep, Vtb_sdram* modelp);
    ~Vtb_sdram__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
