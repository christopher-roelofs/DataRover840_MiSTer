// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_board.h for the primary calling header

#include "Vtb_board__pch.h"
#include "Vtb_board__Syms.h"
#include "Vtb_board_r3900__Cz2.h"

void Vtb_board_r3900__Cz2___ctor_var_reset(Vtb_board_r3900__Cz2* vlSelf);

Vtb_board_r3900__Cz2::Vtb_board_r3900__Cz2(Vtb_board__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_board_r3900__Cz2___ctor_var_reset(this);
}

void Vtb_board_r3900__Cz2::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtb_board_r3900__Cz2::~Vtb_board_r3900__Cz2() {
}
