// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDR840_NE2000__SYMS_H_
#define VERILATED_VDR840_NE2000__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vdr840_ne2000.h"

// INCLUDE MODULE CLASSES
#include "Vdr840_ne2000___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vdr840_ne2000__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vdr840_ne2000* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vdr840_ne2000___024root        TOP;

    // CONSTRUCTORS
    Vdr840_ne2000__Syms(VerilatedContext* contextp, const char* namep, Vdr840_ne2000* modelp);
    ~Vdr840_ne2000__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
