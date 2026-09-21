// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_board.h for the primary calling header

#include "Vtb_board__pch.h"
#include "Vtb_board_tb_board.h"

VL_ATTR_COLD void Vtb_board_tb_board___ctor_var_reset(Vtb_board_tb_board* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_board__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_board_tb_board___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->ram_addr = VL_RAND_RESET_I(25);
    vlSelf->ram_req = VL_RAND_RESET_I(1);
    vlSelf->ram_burst = VL_RAND_RESET_I(1);
    vlSelf->ram_we = VL_RAND_RESET_I(1);
    vlSelf->ram_be = VL_RAND_RESET_I(4);
    vlSelf->ram_wdata = VL_RAND_RESET_I(32);
    vlSelf->ram_ack = VL_RAND_RESET_I(1);
    vlSelf->ram_rdata = VL_RAND_RESET_I(32);
    vlSelf->io_addr = VL_RAND_RESET_I(32);
    vlSelf->io_req = VL_RAND_RESET_I(1);
    vlSelf->io_we = VL_RAND_RESET_I(1);
    vlSelf->io_be = VL_RAND_RESET_I(4);
    vlSelf->io_wdata = VL_RAND_RESET_I(32);
    vlSelf->io_ack = VL_RAND_RESET_I(1);
    vlSelf->io_rdata = VL_RAND_RESET_I(32);
    vlSelf->io_err = VL_RAND_RESET_I(1);
    vlSelf->irq_in = VL_RAND_RESET_I(6);
    vlSelf->retire_valid = VL_RAND_RESET_I(1);
    vlSelf->retire_pc = VL_RAND_RESET_I(32);
    vlSelf->retire_insn = VL_RAND_RESET_I(32);
    vlSelf->retire_next_pc = VL_RAND_RESET_I(32);
    vlSelf->ihit_count = VL_RAND_RESET_I(32);
    vlSelf->imiss_count = VL_RAND_RESET_I(32);
    vlSelf->dhit_count = VL_RAND_RESET_I(32);
    vlSelf->dmiss_count = VL_RAND_RESET_I(32);
    vlSelf->__PVT__ird = VL_RAND_RESET_I(32);
    vlSelf->__PVT__drd = VL_RAND_RESET_I(32);
    vlSelf->__PVT__iack = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ierr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dack = VL_RAND_RESET_I(1);
    vlSelf->__PVT__derr = VL_RAND_RESET_I(1);
    vlSelf->__PVT__board__DOT__i_dec = VL_RAND_RESET_I(27);
    vlSelf->__PVT__board__DOT__d_dec = VL_RAND_RESET_I(27);
    vlSelf->__PVT__board__DOT__owner = VL_RAND_RESET_I(2);
    vlSelf->__PVT__board__DOT__d_wants_ram = VL_RAND_RESET_I(1);
    vlSelf->__PVT__board__DOT__i_wants_ram = VL_RAND_RESET_I(1);
    vlSelf->__PVT__board__DOT__grant_d = VL_RAND_RESET_I(1);
    vlSelf->__PVT__board__DOT__d_wants_io = VL_RAND_RESET_I(1);
    vlSelf->__PVT__board__DOT__i_wants_io = VL_RAND_RESET_I(1);
    vlSelf->board__DOT____VdfgTmp_h22b91ed1__0 = 0;
    vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0 = 0;
    vlSelf->board__DOT____VdfgTmp_h223955ac__0 = 0;
}
