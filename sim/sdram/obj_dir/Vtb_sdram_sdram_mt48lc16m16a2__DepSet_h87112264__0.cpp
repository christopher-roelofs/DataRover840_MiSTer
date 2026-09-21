// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram_sdram_mt48lc16m16a2.h"

uint32_t Vtb_sdram_sdram_mt48lc16m16a2::peek_word(uint32_t index) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtb_sdram_sdram_mt48lc16m16a2::peek_word\n"); );
    VL_OUT16(peek_word__Vfuncrtn,15,0);
    // Body
    peek_word__Vfuncrtn = this->mem[index];
    // Final
    return (peek_word__Vfuncrtn);
}
