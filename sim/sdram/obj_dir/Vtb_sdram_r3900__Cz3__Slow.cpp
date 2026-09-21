// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram__Syms.h"
#include "Vtb_sdram_r3900__Cz3.h"

void Vtb_sdram_r3900__Cz3___ctor_var_reset(Vtb_sdram_r3900__Cz3* vlSelf);

Vtb_sdram_r3900__Cz3::Vtb_sdram_r3900__Cz3(Vtb_sdram__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_sdram_r3900__Cz3___ctor_var_reset(this);
}

void Vtb_sdram_r3900__Cz3::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtb_sdram_r3900__Cz3::~Vtb_sdram_r3900__Cz3() {
}
