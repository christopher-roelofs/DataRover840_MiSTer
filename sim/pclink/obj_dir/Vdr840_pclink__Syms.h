// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDR840_PCLINK__SYMS_H_
#define VERILATED_VDR840_PCLINK__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vdr840_pclink.h"

// INCLUDE MODULE CLASSES
#include "Vdr840_pclink___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vdr840_pclink__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vdr840_pclink* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vdr840_pclink___024root        TOP;

    // CONSTRUCTORS
    Vdr840_pclink__Syms(VerilatedContext* contextp, const char* namep, Vdr840_pclink* modelp);
    ~Vdr840_pclink__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
