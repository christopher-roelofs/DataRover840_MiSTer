// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sdram.h for the primary calling header

#include "Vtb_sdram__pch.h"
#include "Vtb_sdram__Syms.h"
#include "Vtb_sdram_tb_sdram.h"

VL_INLINE_OPT void Vtb_sdram_tb_sdram___ico_sequent__TOP__tb_sdram__0(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___ico_sequent__TOP__tb_sdram__0\n"); );
    // Init
    CData/*0:0*/ board__DOT____VdfgTmp_hab3cb56a__0;
    board__DOT____VdfgTmp_hab3cb56a__0 = 0;
    // Body
    vlSelf->dbg_cen = ((1U >= (IData)(vlSymsp->TOP.clk_div)) 
                       | (0U == (IData)(vlSelf->__PVT__cdiv)));
    if (vlSelf->__PVT__board__DOT__d_wants_io) {
        vlSelf->__PVT__drd = vlSymsp->TOP.io_rdata;
        board__DOT____VdfgTmp_hab3cb56a__0 = vlSymsp->TOP.io_ack;
    } else {
        vlSelf->__PVT__drd = vlSelf->__PVT__ram_rdata;
        board__DOT____VdfgTmp_hab3cb56a__0 = 0U;
    }
    vlSelf->__PVT__adapter__DOT__ack_taken = ((IData)(vlSelf->dbg_cen) 
                                              & (IData)(vlSelf->__PVT__ram_ack));
    vlSelf->__PVT__derr = ((IData)(vlSelf->board__DOT____VdfgTmp_h223955ac__0) 
                           | ((IData)(board__DOT____VdfgTmp_hab3cb56a__0) 
                              & (IData)(vlSymsp->TOP.io_err)));
    vlSelf->dbg_dack = (((IData)(vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0) 
                         & (IData)(vlSelf->__PVT__ram_ack)) 
                        | ((IData)(board__DOT____VdfgTmp_hab3cb56a__0) 
                           | (IData)(vlSelf->board__DOT____VdfgTmp_h223955ac__0)));
}

VL_INLINE_OPT void Vtb_sdram_tb_sdram___ico_sequent__TOP__tb_sdram__1(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___ico_sequent__TOP__tb_sdram__1\n"); );
    // Init
    CData/*0:0*/ board__DOT____VdfgTmp_h22b91ed1__0;
    board__DOT____VdfgTmp_h22b91ed1__0 = 0;
    CData/*0:0*/ board__DOT____VdfgTmp_h56676f03__0;
    board__DOT____VdfgTmp_h56676f03__0 = 0;
    CData/*0:0*/ board__DOT____VdfgTmp_h288a1ef5__0;
    board__DOT____VdfgTmp_h288a1ef5__0 = 0;
    CData/*0:0*/ board__DOT____VdfgTmp_h8306d34d__0;
    board__DOT____VdfgTmp_h8306d34d__0 = 0;
    // Body
    vlSelf->__PVT__board__DOT__i_wants_ram = ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__imem_req) 
                                              & (0U 
                                                 == 
                                                 (0x6000000U 
                                                  & vlSelf->__PVT__board__DOT__i_dec)));
    board__DOT____VdfgTmp_h288a1ef5__0 = ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__imem_req) 
                                          & (0x4000000U 
                                             == (0x6000000U 
                                                 & vlSelf->__PVT__board__DOT__i_dec)));
    vlSelf->__PVT__board__DOT__i_wants_io = ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__imem_req) 
                                             & (0x2000000U 
                                                == 
                                                (0x6000000U 
                                                 & vlSelf->__PVT__board__DOT__i_dec)));
    board__DOT____VdfgTmp_h22b91ed1__0 = (((2U == (IData)(vlSelf->__PVT__board__DOT__owner)) 
                                           | ((0U == (IData)(vlSelf->__PVT__board__DOT__owner)) 
                                              & ((~ (IData)(vlSelf->__PVT__board__DOT__d_wants_ram)) 
                                                 & (IData)(vlSelf->__PVT__board__DOT__i_wants_ram)))) 
                                          & (IData)(vlSelf->__PVT__board__DOT__i_wants_ram));
    board__DOT____VdfgTmp_h8306d34d__0 = ((~ (IData)(vlSelf->__PVT__board__DOT__d_wants_io)) 
                                          & (IData)(vlSelf->__PVT__board__DOT__i_wants_io));
    vlSelf->dbg_ram_req = ((IData)(vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0) 
                           | (IData)(board__DOT____VdfgTmp_h22b91ed1__0));
    if (board__DOT____VdfgTmp_h8306d34d__0) {
        vlSelf->__PVT__ird = vlSymsp->TOP.io_rdata;
        board__DOT____VdfgTmp_h56676f03__0 = vlSymsp->TOP.io_ack;
    } else {
        vlSelf->__PVT__ird = vlSelf->__PVT__ram_rdata;
        board__DOT____VdfgTmp_h56676f03__0 = 0U;
    }
    vlSelf->__PVT__ierr = ((IData)(board__DOT____VdfgTmp_h288a1ef5__0) 
                           | ((IData)(board__DOT____VdfgTmp_h56676f03__0) 
                              & (IData)(vlSymsp->TOP.io_err)));
    vlSelf->dbg_iack = (((IData)(board__DOT____VdfgTmp_h22b91ed1__0) 
                         & (IData)(vlSelf->__PVT__ram_ack)) 
                        | ((IData)(board__DOT____VdfgTmp_h56676f03__0) 
                           | (IData)(board__DOT____VdfgTmp_h288a1ef5__0)));
}

extern const VlUnpacked<CData/*0:0*/, 64> Vtb_sdram__ConstPool__TABLE_ha033e788_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vtb_sdram__ConstPool__TABLE_h8b08f1f0_0;

VL_INLINE_OPT void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__0(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__0\n"); );
    // Init
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->__Vdly__adapter__DOT__state = vlSelf->__PVT__adapter__DOT__state;
    vlSelf->__Vdly__ram_ack = vlSelf->__PVT__ram_ack;
    vlSelf->__PVT__cdiv = ((IData)(vlSymsp->TOP.rst_n)
                            ? (((0xffU & ((IData)(1U) 
                                          + (IData)(vlSelf->__PVT__cdiv))) 
                                >= (IData)(vlSymsp->TOP.clk_div))
                                ? 0U : (0xffU & ((IData)(1U) 
                                                 + (IData)(vlSelf->__PVT__cdiv))))
                            : 0U);
    __Vtableidx1 = (((0U != (IData)(vlSelf->__PVT__adapter__DOT__state)) 
                     << 5U) | (((IData)(vlSelf->__PVT__board__DOT__i_wants_ram) 
                                << 4U) | (((IData)(vlSelf->__PVT__board__DOT__d_wants_ram) 
                                           << 3U) | 
                                          (((IData)(vlSelf->__PVT__board__DOT__owner) 
                                            << 1U) 
                                           | (IData)(vlSymsp->TOP.rst_n)))));
    if (Vtb_sdram__ConstPool__TABLE_ha033e788_0[__Vtableidx1]) {
        vlSelf->__PVT__board__DOT__owner = Vtb_sdram__ConstPool__TABLE_h8b08f1f0_0
            [__Vtableidx1];
    }
}

VL_INLINE_OPT void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__2(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__2\n"); );
    // Init
    SData/*15:0*/ __PVT__ctl__DOT__ch3_dout;
    __PVT__ctl__DOT__ch3_dout = 0;
    CData/*0:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__ch1_rq;
    __Vdly__ctl__DOT__unnamedblk1__DOT__ch1_rq = 0;
    CData/*0:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__ch2_rq;
    __Vdly__ctl__DOT__unnamedblk1__DOT__ch2_rq = 0;
    CData/*0:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__ch3_rq;
    __Vdly__ctl__DOT__unnamedblk1__DOT__ch3_rq = 0;
    SData/*13:0*/ __Vdly__ctl__DOT__refresh_count;
    __Vdly__ctl__DOT__refresh_count = 0;
    CData/*6:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay1;
    __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay1 = 0;
    CData/*6:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay2;
    __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay2 = 0;
    CData/*6:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay3;
    __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay3 = 0;
    // Body
    __Vdly__ctl__DOT__unnamedblk1__DOT__ch1_rq = ((IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch1_rq) 
                                                  | (IData)(vlSelf->__PVT__ch1_req));
    __Vdly__ctl__DOT__unnamedblk1__DOT__ch2_rq = ((IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch2_rq) 
                                                  | (IData)(vlSelf->__PVT__ch2_req));
    __Vdly__ctl__DOT__unnamedblk1__DOT__ch3_rq = vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch3_rq;
    vlSelf->__Vdly__ch1_ready = 0U;
    vlSelf->__Vdly__ch2_ready = 0U;
    __Vdly__ctl__DOT__refresh_count = (0x3fffU & ((IData)(1U) 
                                                  + (IData)(vlSelf->__PVT__ctl__DOT__refresh_count)));
    __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay1 
        = (0x7fU & VL_SHIFTR_III(7,7,32, (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay1), 1U));
    __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay2 
        = (0x7fU & VL_SHIFTR_III(7,7,32, (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay2), 1U));
    __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay3 
        = (0x7fU & VL_SHIFTR_III(7,7,32, (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay3), 1U));
    if ((8U & (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay1))) {
        vlSelf->__Vdly__ch1_dout = ((0xffffffffffff0000ULL 
                                     & vlSelf->__Vdly__ch1_dout) 
                                    | (IData)((IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__dq_reg)));
    }
    if ((4U & (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay1))) {
        vlSelf->__Vdly__ch1_dout = ((0xffffffff0000ffffULL 
                                     & vlSelf->__Vdly__ch1_dout) 
                                    | ((QData)((IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__dq_reg)) 
                                       << 0x10U));
    }
    if ((2U & (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay1))) {
        vlSelf->__Vdly__ch1_dout = ((0xffff0000ffffffffULL 
                                     & vlSelf->__Vdly__ch1_dout) 
                                    | ((QData)((IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__dq_reg)) 
                                       << 0x20U));
        vlSelf->__Vdly__ch1_ready = 1U;
    }
    if ((1U & (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay1))) {
        vlSelf->__Vdly__ch1_dout = ((0xffffffffffffULL 
                                     & vlSelf->__Vdly__ch1_dout) 
                                    | ((QData)((IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__dq_reg)) 
                                       << 0x30U));
    }
    if ((8U & (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay2))) {
        vlSelf->__Vdly__ch2_dout = ((0xffff0000U & vlSelf->__Vdly__ch2_dout) 
                                    | (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__dq_reg));
    }
    if ((4U & (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay2))) {
        vlSelf->__Vdly__ch2_dout = ((0xffffU & vlSelf->__Vdly__ch2_dout) 
                                    | ((IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__dq_reg) 
                                       << 0x10U));
        vlSelf->__Vdly__ch2_ready = 1U;
    }
    if ((8U & (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay3))) {
        __PVT__ctl__DOT__ch3_dout = ((0xff00U & (IData)(__PVT__ctl__DOT__ch3_dout)) 
                                     | (0xffU & (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__dq_reg)));
    }
    if ((2U & (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay3))) {
        __PVT__ctl__DOT__ch3_dout = ((0xffU & (IData)(__PVT__ctl__DOT__ch3_dout)) 
                                     | (0xff00U & ((IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__dq_reg) 
                                                   << 8U)));
    }
    vlSelf->__PVT__ctl_dq_oe = 0U;
    vlSelf->__PVT__ctl__DOT__command = 7U;
    if (((((((((0U == (IData)(vlSelf->__PVT__ctl__DOT__state)) 
               | (9U == (IData)(vlSelf->__PVT__ctl__DOT__state))) 
              | (8U == (IData)(vlSelf->__PVT__ctl__DOT__state))) 
             | (7U == (IData)(vlSelf->__PVT__ctl__DOT__state))) 
            | (6U == (IData)(vlSelf->__PVT__ctl__DOT__state))) 
           | (5U == (IData)(vlSelf->__PVT__ctl__DOT__state))) 
          | (0xaU == (IData)(vlSelf->__PVT__ctl__DOT__state))) 
         | (4U == (IData)(vlSelf->__PVT__ctl__DOT__state)))) {
        if ((0U == (IData)(vlSelf->__PVT__ctl__DOT__state))) {
            vlSelf->__PVT__SDRAM_A = 0U;
            vlSelf->__PVT__SDRAM_BA = 0U;
            if ((0x3fbfU == (IData)(vlSelf->__PVT__ctl__DOT__refresh_count))) {
                vlSelf->__PVT__ctl__DOT__chip = 0U;
            }
            if ((0x3fdfU == (IData)(vlSelf->__PVT__ctl__DOT__refresh_count))) {
                vlSelf->__PVT__ctl__DOT__chip = 1U;
            }
            if (((0x3fc0U == (IData)(vlSelf->__PVT__ctl__DOT__refresh_count)) 
                 | (0x3fe0U == (IData)(vlSelf->__PVT__ctl__DOT__refresh_count)))) {
                vlSelf->__PVT__ctl__DOT__command = 2U;
                vlSelf->__PVT__SDRAM_A = (0x400U | (IData)(vlSelf->__PVT__SDRAM_A));
                vlSelf->__PVT__SDRAM_BA = 0U;
            }
            if (((0x3fc8U == (IData)(vlSelf->__PVT__ctl__DOT__refresh_count)) 
                 | (0x3fe8U == (IData)(vlSelf->__PVT__ctl__DOT__refresh_count)))) {
                vlSelf->__PVT__ctl__DOT__command = 1U;
            }
            if (((0x3fd0U == (IData)(vlSelf->__PVT__ctl__DOT__refresh_count)) 
                 | (0x3ff0U == (IData)(vlSelf->__PVT__ctl__DOT__refresh_count)))) {
                vlSelf->__PVT__ctl__DOT__command = 1U;
            }
            if (((0x3fd8U == (IData)(vlSelf->__PVT__ctl__DOT__refresh_count)) 
                 | (0x3ff8U == (IData)(vlSelf->__PVT__ctl__DOT__refresh_count)))) {
                vlSelf->__PVT__ctl__DOT__command = 0U;
                vlSelf->__PVT__SDRAM_A = 0x222U;
            }
            if ((1U & (~ (IData)((0U != (IData)(vlSelf->__PVT__ctl__DOT__refresh_count)))))) {
                vlSelf->__Vdly__ctl__DOT__state = 4U;
                __Vdly__ctl__DOT__refresh_count = 0U;
            }
        } else if ((9U == (IData)(vlSelf->__PVT__ctl__DOT__state))) {
            vlSelf->__Vdly__ctl__DOT__state = 8U;
        } else if ((8U == (IData)(vlSelf->__PVT__ctl__DOT__state))) {
            vlSelf->__Vdly__ctl__DOT__state = 7U;
        } else if ((7U == (IData)(vlSelf->__PVT__ctl__DOT__state))) {
            vlSelf->__Vdly__ctl__DOT__state = 6U;
        } else if ((6U == (IData)(vlSelf->__PVT__ctl__DOT__state))) {
            vlSelf->__Vdly__ctl__DOT__state = 5U;
        } else if ((5U == (IData)(vlSelf->__PVT__ctl__DOT__state))) {
            vlSelf->__Vdly__ctl__DOT__state = 4U;
            if ((0x2e5U < (IData)(vlSelf->__PVT__ctl__DOT__refresh_count))) {
                __Vdly__ctl__DOT__refresh_count = (0x3fffU 
                                                   & ((IData)(1U) 
                                                      + 
                                                      ((IData)(vlSelf->__PVT__ctl__DOT__refresh_count) 
                                                       - (IData)(0x2e5U))));
                vlSelf->__Vdly__ctl__DOT__state = 0xaU;
                vlSelf->__PVT__ctl__DOT__command = 1U;
                vlSelf->__PVT__ctl__DOT__chip = 0U;
            }
        } else if ((0xaU == (IData)(vlSelf->__PVT__ctl__DOT__state))) {
            vlSelf->__Vdly__ctl__DOT__state = 9U;
            vlSelf->__PVT__ctl__DOT__command = 1U;
            vlSelf->__PVT__ctl__DOT__chip = 1U;
        } else if ((0x5caU < (IData)(vlSelf->__PVT__ctl__DOT__refresh_count))) {
            vlSelf->__Vdly__ctl__DOT__state = 5U;
        } else if (vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch1_rq) {
            vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr 
                = ((0x1ffU & (IData)(vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr)) 
                   | (0x400U | (0x200U & (vlSelf->__PVT__ch1_addr 
                                          >> 0xfU))));
            vlSelf->__PVT__SDRAM_BA = (3U & (vlSelf->__PVT__ch1_addr 
                                             >> 0x16U));
            vlSelf->__PVT__SDRAM_A = (0x1fffU & (vlSelf->__PVT__ch1_addr 
                                                 >> 9U));
            vlSelf->__PVT__ctl__DOT__chip = (1U & (vlSelf->__PVT__ch1_addr 
                                                   >> 0x19U));
            vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__saved_data = 0U;
            vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__saved_wr = 0U;
            vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__ch = 0U;
            __Vdly__ctl__DOT__unnamedblk1__DOT__ch1_rq = 0U;
            vlSelf->__PVT__ctl__DOT__command = 3U;
            vlSelf->__Vdly__ctl__DOT__state = 1U;
            vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr 
                = ((0x1e00U & (IData)(vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr)) 
                   | (0x1ffU & vlSelf->__PVT__ch1_addr));
        } else if (vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch2_rq) {
            vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr 
                = ((0x1ffU & (IData)(vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr)) 
                   | (((IData)(vlSelf->__PVT__ch2_rnw) 
                       << 0xaU) | (0x200U & (vlSelf->__PVT__ch2_addr 
                                             >> 0xfU))));
            vlSelf->__PVT__SDRAM_BA = (3U & (vlSelf->__PVT__ch2_addr 
                                             >> 0x16U));
            vlSelf->__PVT__SDRAM_A = (0x1fffU & (vlSelf->__PVT__ch2_addr 
                                                 >> 9U));
            vlSelf->__PVT__ctl__DOT__chip = (1U & (vlSelf->__PVT__ch2_addr 
                                                   >> 0x19U));
            vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__saved_data 
                = vlSelf->__PVT__ch2_din;
            vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__saved_wr 
                = (1U & (~ (IData)(vlSelf->__PVT__ch2_rnw)));
            vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__ch = 1U;
            __Vdly__ctl__DOT__unnamedblk1__DOT__ch2_rq = 0U;
            vlSelf->__PVT__ctl__DOT__command = 3U;
            vlSelf->__Vdly__ctl__DOT__state = 1U;
            vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr 
                = ((0x1e00U & (IData)(vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr)) 
                   | (0x1ffU & vlSelf->__PVT__ch2_addr));
        } else if (vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch3_rq) {
            vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr 
                = (0x400U | (0x1ffU & (IData)(vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr)));
            vlSelf->__PVT__SDRAM_BA = 0U;
            vlSelf->__PVT__SDRAM_A = 0U;
            vlSelf->__PVT__ctl__DOT__chip = 0U;
            vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__saved_data = 0xff00ff00U;
            vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__saved_wr = 0U;
            vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__ch = 2U;
            __Vdly__ctl__DOT__unnamedblk1__DOT__ch3_rq = 0U;
            vlSelf->__PVT__ctl__DOT__command = 3U;
            vlSelf->__Vdly__ctl__DOT__state = 1U;
            vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr 
                = (0x1e00U & (IData)(vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr));
        }
    } else if ((1U == (IData)(vlSelf->__PVT__ctl__DOT__state))) {
        vlSelf->__Vdly__ctl__DOT__state = 2U;
    } else if ((2U == (IData)(vlSelf->__PVT__ctl__DOT__state))) {
        vlSelf->__PVT__SDRAM_A = vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__cas_addr;
        if (vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__saved_wr) {
            vlSelf->__PVT__ctl__DOT__command = 4U;
            vlSelf->__PVT__ctl_dq_o = (0xffffU & vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__saved_data);
            vlSelf->__PVT__ctl_dq_oe = 1U;
            if ((0U != (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch))) {
                vlSelf->__Vdly__ctl__DOT__state = 3U;
            } else {
                vlSelf->__Vdly__ch1_ready = 1U;
                vlSelf->__Vdly__ctl__DOT__state = 6U;
            }
        } else {
            vlSelf->__PVT__ctl__DOT__command = 5U;
            vlSelf->__Vdly__ctl__DOT__state = 9U;
            if ((0U == (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch))) {
                __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay1 
                    = (0x40U | (IData)(__Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay1));
            } else if ((1U == (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch))) {
                __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay2 
                    = (0x40U | (IData)(__Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay2));
            } else {
                __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay3 
                    = (0x40U | (IData)(__Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay3));
            }
        }
    } else if ((3U == (IData)(vlSelf->__PVT__ctl__DOT__state))) {
        if ((1U == (IData)(vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch))) {
            vlSelf->__Vdly__ctl__DOT__state = 6U;
            vlSelf->__PVT__SDRAM_A = (0x400U | (IData)(vlSelf->__PVT__SDRAM_A));
            vlSelf->__PVT__ctl__DOT__command = 4U;
            vlSelf->__PVT__ctl_dq_o = (vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__saved_data 
                                       >> 0x10U);
            vlSelf->__PVT__ctl_dq_oe = 1U;
            vlSelf->__Vdly__ch2_ready = 1U;
            vlSelf->__PVT__SDRAM_A = (1U | (IData)(vlSelf->__PVT__SDRAM_A));
        } else {
            vlSelf->__Vdly__ctl__DOT__state = 6U;
            vlSelf->__PVT__SDRAM_A = (0x400U | (IData)(vlSelf->__PVT__SDRAM_A));
            vlSelf->__PVT__ctl__DOT__command = 4U;
            vlSelf->__PVT__ctl_dq_o = (vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__saved_data 
                                       >> 0x10U);
            vlSelf->__PVT__ctl_dq_oe = 1U;
            vlSelf->__PVT__SDRAM_A = (2U | (IData)(vlSelf->__PVT__SDRAM_A));
        }
    }
    if ((1U & (~ (IData)(vlSymsp->TOP.rst_n)))) {
        vlSelf->__Vdly__ctl__DOT__state = 0U;
        __Vdly__ctl__DOT__refresh_count = 0x1318U;
    }
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch1_rq 
        = __Vdly__ctl__DOT__unnamedblk1__DOT__ch1_rq;
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch2_rq 
        = __Vdly__ctl__DOT__unnamedblk1__DOT__ch2_rq;
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch3_rq 
        = __Vdly__ctl__DOT__unnamedblk1__DOT__ch3_rq;
    vlSelf->__PVT__ctl__DOT__refresh_count = __Vdly__ctl__DOT__refresh_count;
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay1 
        = __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay1;
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay2 
        = __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay2;
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay3 
        = __Vdly__ctl__DOT__unnamedblk1__DOT__data_ready_delay3;
    vlSelf->__PVT__ctl__DOT__state = vlSelf->__Vdly__ctl__DOT__state;
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__cas_addr 
        = vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr;
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__saved_data 
        = vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__saved_data;
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__saved_wr 
        = vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__saved_wr;
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__ch = vlSelf->__Vdly__ctl__DOT__unnamedblk1__DOT__ch;
    vlSelf->__PVT__ctl__DOT__unnamedblk1__DOT__dq_reg 
        = vlSelf->__PVT__dq_bus;
    vlSelf->__PVT__dq_bus = ((IData)(vlSelf->__PVT__ctl_dq_oe)
                              ? (IData)(vlSelf->__PVT__ctl_dq_o)
                              : ((IData)(vlSymsp->TOP__tb_sdram__chip.__PVT__dq_oe)
                                  ? (IData)(vlSymsp->TOP__tb_sdram__chip.__PVT__dq_out)
                                  : 0xffffU));
}

extern const VlUnpacked<CData/*1:0*/, 64> Vtb_sdram__ConstPool__TABLE_heaad40ca_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vtb_sdram__ConstPool__TABLE_h0c921ac5_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vtb_sdram__ConstPool__TABLE_h801ee4dd_0;

VL_INLINE_OPT void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__3(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__3\n"); );
    // Init
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__2__Vfuncout;
    __Vfunc_adapter__DOT__swap__2__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__2__x;
    __Vfunc_adapter__DOT__swap__2__x = 0;
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__3__Vfuncout;
    __Vfunc_adapter__DOT__swap__3__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__3__x;
    __Vfunc_adapter__DOT__swap__3__x = 0;
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__4__Vfuncout;
    __Vfunc_adapter__DOT__swap__4__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__4__x;
    __Vfunc_adapter__DOT__swap__4__x = 0;
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__5__Vfuncout;
    __Vfunc_adapter__DOT__swap__5__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__5__x;
    __Vfunc_adapter__DOT__swap__5__x = 0;
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__6__Vfuncout;
    __Vfunc_adapter__DOT__swap__6__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__6__x;
    __Vfunc_adapter__DOT__swap__6__x = 0;
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__7__Vfuncout;
    __Vfunc_adapter__DOT__swap__7__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__7__x;
    __Vfunc_adapter__DOT__swap__7__x = 0;
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__8__Vfuncout;
    __Vfunc_adapter__DOT__swap__8__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__8__x;
    __Vfunc_adapter__DOT__swap__8__x = 0;
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__9__Vfuncout;
    __Vfunc_adapter__DOT__swap__9__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_adapter__DOT__swap__9__x;
    __Vfunc_adapter__DOT__swap__9__x = 0;
    CData/*5:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    if (vlSymsp->TOP.rst_n) {
        vlSelf->__PVT__ch1_req = 0U;
        vlSelf->__PVT__ch2_req = 0U;
        if (vlSelf->__PVT__adapter__DOT__ack_taken) {
            vlSelf->__Vdly__ram_ack = 0U;
        }
        vlSelf->dbg_start = 0U;
        if ((((0U == (IData)(vlSelf->__PVT__adapter__DOT__state)) 
              & (IData)(vlSelf->dbg_ram_req)) & (~ (IData)(vlSelf->__PVT__ram_ack)))) {
            vlSelf->dbg_start = 1U;
            vlSelf->dbg_start_addr = vlSelf->dbg_ram_addr;
            vlSelf->dbg_start_kind = ((IData)(vlSelf->dbg_ram_burst)
                                       ? 3U : (((IData)(vlSelf->__PVT__ram_we) 
                                                & (0xfU 
                                                   == (IData)(vlSelf->__PVT__ram_be)))
                                                ? 1U
                                                : ((IData)(vlSelf->__PVT__ram_we)
                                                    ? 2U
                                                    : 0U)));
        }
        if ((8U & (IData)(vlSelf->__PVT__adapter__DOT__state))) {
            if ((4U & (IData)(vlSelf->__PVT__adapter__DOT__state))) {
                vlSelf->__Vdly__adapter__DOT__state = 0U;
            } else if ((2U & (IData)(vlSelf->__PVT__adapter__DOT__state))) {
                if ((1U & (IData)(vlSelf->__PVT__adapter__DOT__state))) {
                    if (vlSelf->__PVT__adapter__DOT__ack_taken) {
                        vlSelf->__Vdly__adapter__DOT__state = 0U;
                    }
                } else if (vlSelf->__PVT__adapter__DOT__ack_taken) {
                    __Vfunc_adapter__DOT__swap__2__x 
                        = (IData)((vlSelf->__PVT__ch1_dout 
                                   >> 0x20U));
                    __Vfunc_adapter__DOT__swap__2__Vfuncout 
                        = ((__Vfunc_adapter__DOT__swap__2__x 
                            << 0x10U) | (__Vfunc_adapter__DOT__swap__2__x 
                                         >> 0x10U));
                    vlSelf->__PVT__ram_rdata = __Vfunc_adapter__DOT__swap__2__Vfuncout;
                    vlSelf->__Vdly__ram_ack = 1U;
                    vlSelf->__Vdly__adapter__DOT__state = 0xbU;
                }
            } else if ((1U & (IData)(vlSelf->__PVT__adapter__DOT__state))) {
                if (((IData)(vlSelf->__PVT__adapter__DOT__ch1_done) 
                     & (IData)(vlSelf->dbg_cen))) {
                    __Vfunc_adapter__DOT__swap__3__x 
                        = (IData)(vlSelf->__PVT__ch1_dout);
                    __Vfunc_adapter__DOT__swap__3__Vfuncout 
                        = ((__Vfunc_adapter__DOT__swap__3__x 
                            << 0x10U) | (__Vfunc_adapter__DOT__swap__3__x 
                                         >> 0x10U));
                    vlSelf->__PVT__ram_rdata = __Vfunc_adapter__DOT__swap__3__Vfuncout;
                    vlSelf->__Vdly__ram_ack = 1U;
                    vlSelf->__Vdly__adapter__DOT__state = 0xaU;
                }
            } else if (vlSelf->__PVT__adapter__DOT__ack_taken) {
                vlSelf->__PVT__ch1_addr = (4U | (0xfffff8U 
                                                 & (vlSelf->__PVT__adapter__DOT__line 
                                                    >> 1U)));
                vlSelf->__PVT__ch1_req = 1U;
                vlSelf->__Vdly__adapter__DOT__state = 9U;
            }
        } else if ((4U & (IData)(vlSelf->__PVT__adapter__DOT__state))) {
            if ((2U & (IData)(vlSelf->__PVT__adapter__DOT__state))) {
                if ((1U & (IData)(vlSelf->__PVT__adapter__DOT__state))) {
                    if (vlSelf->__PVT__adapter__DOT__ack_taken) {
                        __Vfunc_adapter__DOT__swap__4__x 
                            = (IData)((vlSelf->__PVT__ch1_dout 
                                       >> 0x20U));
                        __Vfunc_adapter__DOT__swap__4__Vfuncout 
                            = ((__Vfunc_adapter__DOT__swap__4__x 
                                << 0x10U) | (__Vfunc_adapter__DOT__swap__4__x 
                                             >> 0x10U));
                        vlSelf->__PVT__ram_rdata = __Vfunc_adapter__DOT__swap__4__Vfuncout;
                        vlSelf->__Vdly__ram_ack = 1U;
                        vlSelf->__Vdly__adapter__DOT__state = 8U;
                    }
                } else if (((IData)(vlSelf->__PVT__adapter__DOT__ch1_done) 
                            & (IData)(vlSelf->dbg_cen))) {
                    __Vfunc_adapter__DOT__swap__5__x 
                        = (IData)(vlSelf->__PVT__ch1_dout);
                    __Vfunc_adapter__DOT__swap__5__Vfuncout 
                        = ((__Vfunc_adapter__DOT__swap__5__x 
                            << 0x10U) | (__Vfunc_adapter__DOT__swap__5__x 
                                         >> 0x10U));
                    vlSelf->__PVT__ram_rdata = __Vfunc_adapter__DOT__swap__5__Vfuncout;
                    vlSelf->__Vdly__ram_ack = 1U;
                    vlSelf->__Vdly__adapter__DOT__state = 7U;
                }
            } else if ((1U & (IData)(vlSelf->__PVT__adapter__DOT__state))) {
                if (vlSelf->__PVT__adapter__DOT__ack_taken) {
                    vlSelf->__Vdly__adapter__DOT__state = 0U;
                }
            } else {
                __Vfunc_adapter__DOT__swap__6__x = vlSelf->__PVT__adapter__DOT__merged;
                __Vfunc_adapter__DOT__swap__6__Vfuncout 
                    = ((__Vfunc_adapter__DOT__swap__6__x 
                        << 0x10U) | (__Vfunc_adapter__DOT__swap__6__x 
                                     >> 0x10U));
                vlSelf->__PVT__ch2_din = __Vfunc_adapter__DOT__swap__6__Vfuncout;
                vlSelf->__PVT__ch2_req = 1U;
                vlSelf->__Vdly__adapter__DOT__state = 2U;
            }
        } else if ((2U & (IData)(vlSelf->__PVT__adapter__DOT__state))) {
            if ((1U & (IData)(vlSelf->__PVT__adapter__DOT__state))) {
                if (((IData)(vlSelf->__PVT__adapter__DOT__ch2_done) 
                     & (IData)(vlSelf->dbg_cen))) {
                    __Vfunc_adapter__DOT__swap__7__x 
                        = vlSelf->__PVT__ch2_dout;
                    __Vfunc_adapter__DOT__swap__7__Vfuncout 
                        = ((__Vfunc_adapter__DOT__swap__7__x 
                            << 0x10U) | (__Vfunc_adapter__DOT__swap__7__x 
                                         >> 0x10U));
                    vlSelf->__PVT__adapter__DOT__hold 
                        = __Vfunc_adapter__DOT__swap__7__Vfuncout;
                    vlSelf->__PVT__ch2_rnw = 0U;
                    vlSelf->__Vdly__adapter__DOT__state = 4U;
                }
            } else if (((IData)(vlSelf->__PVT__adapter__DOT__ch2_done) 
                        & (IData)(vlSelf->dbg_cen))) {
                vlSelf->__Vdly__ram_ack = 1U;
                vlSelf->__Vdly__adapter__DOT__state = 5U;
            }
        } else if ((1U & (IData)(vlSelf->__PVT__adapter__DOT__state))) {
            if (((IData)(vlSelf->__PVT__adapter__DOT__ch2_done) 
                 & (IData)(vlSelf->dbg_cen))) {
                __Vfunc_adapter__DOT__swap__8__x = vlSelf->__PVT__ch2_dout;
                __Vfunc_adapter__DOT__swap__8__Vfuncout 
                    = ((__Vfunc_adapter__DOT__swap__8__x 
                        << 0x10U) | (__Vfunc_adapter__DOT__swap__8__x 
                                     >> 0x10U));
                vlSelf->__PVT__ram_rdata = __Vfunc_adapter__DOT__swap__8__Vfuncout;
                vlSelf->__Vdly__ram_ack = 1U;
                vlSelf->__Vdly__adapter__DOT__state = 5U;
            }
        } else if ((((IData)(vlSelf->dbg_ram_req) & 
                     (~ (IData)(vlSelf->__PVT__ram_ack))) 
                    & (IData)(vlSelf->dbg_cen))) {
            if (vlSelf->dbg_ram_burst) {
                vlSelf->__PVT__adapter__DOT__line = 
                    (0x1fffff0U & vlSelf->dbg_ram_addr);
                vlSelf->__PVT__ch1_addr = (0xfffff8U 
                                           & (vlSelf->dbg_ram_addr 
                                              >> 1U));
                vlSelf->__PVT__ch1_req = 1U;
                vlSelf->__Vdly__adapter__DOT__state = 6U;
            } else if (((IData)(vlSelf->__PVT__ram_we) 
                        & (0xfU == (IData)(vlSelf->__PVT__ram_be)))) {
                __Vfunc_adapter__DOT__swap__9__x = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word;
                __Vfunc_adapter__DOT__swap__9__Vfuncout 
                    = ((__Vfunc_adapter__DOT__swap__9__x 
                        << 0x10U) | (__Vfunc_adapter__DOT__swap__9__x 
                                     >> 0x10U));
                vlSelf->__PVT__ch2_addr = (0xffffffU 
                                           & (vlSelf->dbg_ram_addr 
                                              >> 1U));
                vlSelf->__PVT__ch2_din = __Vfunc_adapter__DOT__swap__9__Vfuncout;
                vlSelf->__PVT__ch2_rnw = 0U;
                vlSelf->__PVT__ch2_req = 1U;
                vlSelf->__Vdly__adapter__DOT__state = 2U;
            } else if (vlSelf->__PVT__ram_we) {
                vlSelf->__PVT__ch2_addr = (0xffffffU 
                                           & (vlSelf->dbg_ram_addr 
                                              >> 1U));
                vlSelf->__PVT__ch2_rnw = 1U;
                vlSelf->__PVT__ch2_req = 1U;
                vlSelf->__Vdly__adapter__DOT__state = 3U;
            } else {
                vlSelf->__PVT__ch2_addr = (0xffffffU 
                                           & (vlSelf->dbg_ram_addr 
                                              >> 1U));
                vlSelf->__PVT__ch2_rnw = 1U;
                vlSelf->__PVT__ch2_req = 1U;
                vlSelf->__Vdly__adapter__DOT__state = 1U;
            }
        }
    } else {
        vlSelf->__Vdly__adapter__DOT__state = 0U;
        vlSelf->dbg_start = 0U;
        vlSelf->__PVT__ch1_req = 0U;
        vlSelf->__PVT__ch2_req = 0U;
        vlSelf->__Vdly__ram_ack = 0U;
    }
    vlSelf->__PVT__ram_ack = vlSelf->__Vdly__ram_ack;
    __Vtableidx2 = ((((1U == (IData)(vlSelf->__PVT__adapter__DOT__state)) 
                      | ((2U == (IData)(vlSelf->__PVT__adapter__DOT__state)) 
                         | (3U == (IData)(vlSelf->__PVT__adapter__DOT__state)))) 
                     << 5U) | (((IData)(vlSelf->__PVT__ch2_ready) 
                                << 4U) | (((IData)(vlSelf->dbg_cen) 
                                           << 3U) | 
                                          ((((6U == (IData)(vlSelf->__PVT__adapter__DOT__state)) 
                                             | (9U 
                                                == (IData)(vlSelf->__PVT__adapter__DOT__state))) 
                                            << 2U) 
                                           | (((IData)(vlSelf->__PVT__ch1_ready) 
                                               << 1U) 
                                              | (IData)(vlSymsp->TOP.rst_n))))));
    if ((1U & Vtb_sdram__ConstPool__TABLE_heaad40ca_0
         [__Vtableidx2])) {
        vlSelf->__PVT__adapter__DOT__ch1_done = Vtb_sdram__ConstPool__TABLE_h0c921ac5_0
            [__Vtableidx2];
    }
    if ((2U & Vtb_sdram__ConstPool__TABLE_heaad40ca_0
         [__Vtableidx2])) {
        vlSelf->__PVT__adapter__DOT__ch2_done = Vtb_sdram__ConstPool__TABLE_h801ee4dd_0
            [__Vtableidx2];
    }
    vlSelf->__PVT__adapter__DOT__state = vlSelf->__Vdly__adapter__DOT__state;
    vlSelf->dbg_cen = ((1U >= (IData)(vlSymsp->TOP.clk_div)) 
                       | (0U == (IData)(vlSelf->__PVT__cdiv)));
    vlSelf->__PVT__adapter__DOT__ack_taken = ((IData)(vlSelf->dbg_cen) 
                                              & (IData)(vlSelf->__PVT__ram_ack));
}

VL_INLINE_OPT void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__4(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__4\n"); );
    // Init
    CData/*1:0*/ __PVT__board__DOT__decode__Vstatic__t;
    __PVT__board__DOT__decode__Vstatic__t = 0;
    IData/*24:0*/ __PVT__board__DOT__decode__Vstatic__off;
    __PVT__board__DOT__decode__Vstatic__off = 0;
    IData/*31:0*/ __PVT__board__DOT__decode__Vstatic__rel;
    __PVT__board__DOT__decode__Vstatic__rel = 0;
    IData/*26:0*/ __PVT__board__DOT__d_dec;
    __PVT__board__DOT__d_dec = 0;
    CData/*0:0*/ __PVT__board__DOT__grant_d;
    __PVT__board__DOT__grant_d = 0;
    CData/*0:0*/ board__DOT____VdfgTmp_hab3cb56a__0;
    board__DOT____VdfgTmp_hab3cb56a__0 = 0;
    IData/*26:0*/ __Vfunc_board__DOT__decode__0__Vfuncout;
    __Vfunc_board__DOT__decode__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_board__DOT__decode__0__pa;
    __Vfunc_board__DOT__decode__0__pa = 0;
    IData/*26:0*/ __Vfunc_board__DOT__decode__1__Vfuncout;
    __Vfunc_board__DOT__decode__1__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_board__DOT__decode__1__pa;
    __Vfunc_board__DOT__decode__1__pa = 0;
    // Body
    __Vfunc_board__DOT__decode__0__pa = vlSymsp->TOP__tb_sdram__cpu.__PVT__imem_addr;
    __PVT__board__DOT__decode__Vstatic__t = 2U;
    __PVT__board__DOT__decode__Vstatic__off = 0U;
    __PVT__board__DOT__decode__Vstatic__rel = 0U;
    if ((0x3c00000U > __Vfunc_board__DOT__decode__0__pa)) {
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x800000U 
                                                   | (0x3fffffU 
                                                      & __Vfunc_board__DOT__decode__0__pa));
    } else if ((0x4400000U > __Vfunc_board__DOT__decode__0__pa)) {
        __PVT__board__DOT__decode__Vstatic__rel = (__Vfunc_board__DOT__decode__0__pa 
                                                   - (IData)(0x3c00000U));
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x7fffffU 
                                                   & __PVT__board__DOT__decode__Vstatic__rel);
    } else if (((0x13c00000U <= __Vfunc_board__DOT__decode__0__pa) 
                & (0x14400000U > __Vfunc_board__DOT__decode__0__pa))) {
        __PVT__board__DOT__decode__Vstatic__rel = (__Vfunc_board__DOT__decode__0__pa 
                                                   - (IData)(0x13c00000U));
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x7fffffU 
                                                   & __PVT__board__DOT__decode__Vstatic__rel);
    } else if (((0x1fc00000U <= __Vfunc_board__DOT__decode__0__pa) 
                & (0x20000000U > __Vfunc_board__DOT__decode__0__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x3fffffU 
                                                   & __Vfunc_board__DOT__decode__0__pa);
    } else if (((0x10400000U <= __Vfunc_board__DOT__decode__0__pa) 
                & (0x10c00400U > __Vfunc_board__DOT__decode__0__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    } else if (((0x8000000U <= __Vfunc_board__DOT__decode__0__pa) 
                & (0x10000000U > __Vfunc_board__DOT__decode__0__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    } else if (((0x24000000U <= __Vfunc_board__DOT__decode__0__pa) 
                & (0x2c000000U > __Vfunc_board__DOT__decode__0__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    } else if (((0xff000000U <= __Vfunc_board__DOT__decode__0__pa) 
                & (0xff001000U > __Vfunc_board__DOT__decode__0__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    }
    __Vfunc_board__DOT__decode__0__Vfuncout = (((IData)(__PVT__board__DOT__decode__Vstatic__t) 
                                                << 0x19U) 
                                               | __PVT__board__DOT__decode__Vstatic__off);
    vlSelf->__PVT__board__DOT__i_dec = __Vfunc_board__DOT__decode__0__Vfuncout;
    __Vfunc_board__DOT__decode__1__pa = vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_addr;
    __PVT__board__DOT__decode__Vstatic__t = 2U;
    __PVT__board__DOT__decode__Vstatic__off = 0U;
    __PVT__board__DOT__decode__Vstatic__rel = 0U;
    if ((0x3c00000U > __Vfunc_board__DOT__decode__1__pa)) {
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x800000U 
                                                   | (0x3fffffU 
                                                      & __Vfunc_board__DOT__decode__1__pa));
    } else if ((0x4400000U > __Vfunc_board__DOT__decode__1__pa)) {
        __PVT__board__DOT__decode__Vstatic__rel = (__Vfunc_board__DOT__decode__1__pa 
                                                   - (IData)(0x3c00000U));
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x7fffffU 
                                                   & __PVT__board__DOT__decode__Vstatic__rel);
    } else if (((0x13c00000U <= __Vfunc_board__DOT__decode__1__pa) 
                & (0x14400000U > __Vfunc_board__DOT__decode__1__pa))) {
        __PVT__board__DOT__decode__Vstatic__rel = (__Vfunc_board__DOT__decode__1__pa 
                                                   - (IData)(0x13c00000U));
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x7fffffU 
                                                   & __PVT__board__DOT__decode__Vstatic__rel);
    } else if (((0x1fc00000U <= __Vfunc_board__DOT__decode__1__pa) 
                & (0x20000000U > __Vfunc_board__DOT__decode__1__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 0U;
        __PVT__board__DOT__decode__Vstatic__off = (0x3fffffU 
                                                   & __Vfunc_board__DOT__decode__1__pa);
    } else if (((0x10400000U <= __Vfunc_board__DOT__decode__1__pa) 
                & (0x10c00400U > __Vfunc_board__DOT__decode__1__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    } else if (((0x8000000U <= __Vfunc_board__DOT__decode__1__pa) 
                & (0x10000000U > __Vfunc_board__DOT__decode__1__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    } else if (((0x24000000U <= __Vfunc_board__DOT__decode__1__pa) 
                & (0x2c000000U > __Vfunc_board__DOT__decode__1__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    } else if (((0xff000000U <= __Vfunc_board__DOT__decode__1__pa) 
                & (0xff001000U > __Vfunc_board__DOT__decode__1__pa))) {
        __PVT__board__DOT__decode__Vstatic__t = 1U;
    }
    __Vfunc_board__DOT__decode__1__Vfuncout = (((IData)(__PVT__board__DOT__decode__Vstatic__t) 
                                                << 0x19U) 
                                               | __PVT__board__DOT__decode__Vstatic__off);
    __PVT__board__DOT__d_dec = __Vfunc_board__DOT__decode__1__Vfuncout;
    vlSelf->board__DOT____VdfgTmp_h223955ac__0 = ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_req) 
                                                  & (0x4000000U 
                                                     == 
                                                     (0x6000000U 
                                                      & __PVT__board__DOT__d_dec)));
    vlSelf->__PVT__board__DOT__d_wants_ram = ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_req) 
                                              & (0U 
                                                 == 
                                                 (0x6000000U 
                                                  & __PVT__board__DOT__d_dec)));
    vlSelf->__PVT__board__DOT__d_wants_io = ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_req) 
                                             & (0x2000000U 
                                                == 
                                                (0x6000000U 
                                                 & __PVT__board__DOT__d_dec)));
    __PVT__board__DOT__grant_d = ((1U == (IData)(vlSelf->__PVT__board__DOT__owner)) 
                                  | ((0U == (IData)(vlSelf->__PVT__board__DOT__owner)) 
                                     & (IData)(vlSelf->__PVT__board__DOT__d_wants_ram)));
    if (vlSelf->__PVT__board__DOT__d_wants_io) {
        vlSelf->__PVT__drd = vlSymsp->TOP.io_rdata;
        board__DOT____VdfgTmp_hab3cb56a__0 = vlSymsp->TOP.io_ack;
    } else {
        vlSelf->__PVT__drd = vlSelf->__PVT__ram_rdata;
        board__DOT____VdfgTmp_hab3cb56a__0 = 0U;
    }
    if (__PVT__board__DOT__grant_d) {
        vlSelf->__PVT__ram_we = vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_we;
        vlSelf->__PVT__ram_be = vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_be;
        vlSelf->dbg_ram_addr = (0x1ffffffU & __PVT__board__DOT__d_dec);
        vlSelf->dbg_ram_burst = (1U == (IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__cache__DOT__dstate));
    } else {
        vlSelf->__PVT__ram_we = 0U;
        vlSelf->__PVT__ram_be = 0xfU;
        vlSelf->dbg_ram_addr = (0x1ffffffU & vlSelf->__PVT__board__DOT__i_dec);
        vlSelf->dbg_ram_burst = (1U == (IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__cache__DOT__istate));
    }
    vlSelf->__PVT__adapter__DOT__merged = ((((1U & 
                                              ((~ (IData)(__PVT__board__DOT__grant_d)) 
                                               | ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_be) 
                                                  >> 3U)))
                                              ? (vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word 
                                                 >> 0x18U)
                                              : (vlSelf->__PVT__adapter__DOT__hold 
                                                 >> 0x18U)) 
                                            << 0x18U) 
                                           | ((0xff0000U 
                                               & (((1U 
                                                    & ((~ (IData)(__PVT__board__DOT__grant_d)) 
                                                       | ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_be) 
                                                          >> 2U)))
                                                    ? 
                                                   (vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word 
                                                    >> 0x10U)
                                                    : 
                                                   (vlSelf->__PVT__adapter__DOT__hold 
                                                    >> 0x10U)) 
                                                  << 0x10U)) 
                                              | ((0xff00U 
                                                  & (((1U 
                                                       & ((~ (IData)(__PVT__board__DOT__grant_d)) 
                                                          | ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_be) 
                                                             >> 1U)))
                                                       ? 
                                                      (vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word 
                                                       >> 8U)
                                                       : 
                                                      (vlSelf->__PVT__adapter__DOT__hold 
                                                       >> 8U)) 
                                                     << 8U)) 
                                                 | (0xffU 
                                                    & ((1U 
                                                        & ((~ (IData)(__PVT__board__DOT__grant_d)) 
                                                           | (IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_be)))
                                                        ? vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word
                                                        : vlSelf->__PVT__adapter__DOT__hold)))));
    vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0 = ((IData)(__PVT__board__DOT__grant_d) 
                                                  & (IData)(vlSelf->__PVT__board__DOT__d_wants_ram));
    vlSelf->__PVT__derr = ((IData)(vlSelf->board__DOT____VdfgTmp_h223955ac__0) 
                           | ((IData)(board__DOT____VdfgTmp_hab3cb56a__0) 
                              & (IData)(vlSymsp->TOP.io_err)));
    vlSelf->dbg_dack = (((IData)(vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0) 
                         & (IData)(vlSelf->__PVT__ram_ack)) 
                        | ((IData)(board__DOT____VdfgTmp_hab3cb56a__0) 
                           | (IData)(vlSelf->board__DOT____VdfgTmp_h223955ac__0)));
}
