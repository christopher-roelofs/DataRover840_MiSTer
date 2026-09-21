// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_BOARD__SYMS_H_
#define VERILATED_VTB_BOARD__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_board.h"

// INCLUDE MODULE CLASSES
#include "Vtb_board___024root.h"
#include "Vtb_board_tb_board.h"
#include "Vtb_board_r3900_cached__Cz1.h"
#include "Vtb_board_r3900__Cz2.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb_board__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_board* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_board___024root            TOP;
    Vtb_board_tb_board             TOP__tb_board;
    Vtb_board_r3900_cached__Cz1    TOP__tb_board__cpu;
    Vtb_board_r3900__Cz2           TOP__tb_board__cpu__cpu;

    // SCOPE NAMES
    VerilatedScope __Vscope_tb_board__cpu__cpu;

    // CONSTRUCTORS
    Vtb_board__Syms(VerilatedContext* contextp, const char* namep, Vtb_board* modelp);
    ~Vtb_board__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
