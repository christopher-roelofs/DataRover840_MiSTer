// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_net.h for the primary calling header

#include "Vtb_net__pch.h"
#include "Vtb_net__Syms.h"
#include "Vtb_net___024root.h"

void Vtb_net___024root___ctor_var_reset(Vtb_net___024root* vlSelf);

Vtb_net___024root::Vtb_net___024root(Vtb_net__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_net___024root___ctor_var_reset(this);
}

void Vtb_net___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtb_net___024root::~Vtb_net___024root() {
}
