// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vdr840_ne2000__pch.h"
#include "Vdr840_ne2000.h"
#include "Vdr840_ne2000___024root.h"

// FUNCTIONS
Vdr840_ne2000__Syms::~Vdr840_ne2000__Syms()
{
}

Vdr840_ne2000__Syms::Vdr840_ne2000__Syms(VerilatedContext* contextp, const char* namep, Vdr840_ne2000* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
