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
    CData/*0:0*/ __PVT__io_ack_mux;
    __PVT__io_ack_mux = 0;
    CData/*0:0*/ board__DOT____VdfgTmp_h56676f03__0;
    board__DOT____VdfgTmp_h56676f03__0 = 0;
    CData/*0:0*/ board__DOT____VdfgTmp_hab3cb56a__0;
    board__DOT____VdfgTmp_hab3cb56a__0 = 0;
    // Body
    vlSelf->dbg_cen = ((1U >= (IData)(vlSymsp->TOP.clk_div)) 
                       | (0U == (IData)(vlSelf->__PVT__cdiv)));
    vlSelf->__PVT__io_err_mux = ((1U & (~ (IData)(vlSymsp->TOP.tx39_en))) 
                                 && (IData)(vlSymsp->TOP.io_err));
    if (vlSymsp->TOP.tx39_en) {
        vlSelf->__Vcellinp__tx39__io_req = vlSelf->io_req;
        vlSelf->__PVT__io_rdata_mux = vlSelf->__PVT__t_rdata;
        __PVT__io_ack_mux = ((IData)(vlSelf->__Vcellinp__tx39__io_req) 
                             & (IData)(vlSelf->__PVT__tx39__DOT__served));
    } else {
        vlSelf->__Vcellinp__tx39__io_req = 0U;
        vlSelf->__PVT__io_rdata_mux = vlSymsp->TOP.io_rdata;
        __PVT__io_ack_mux = vlSymsp->TOP.io_ack;
    }
    vlSelf->__PVT__adapter__DOT__ack_taken = ((IData)(vlSelf->dbg_cen) 
                                              & (IData)(vlSelf->__PVT__ram_ack));
    vlSelf->__PVT__tx39__DOT__io_start = ((IData)(vlSelf->__Vcellinp__tx39__io_req) 
                                          & ((~ (IData)(vlSelf->__PVT__tx39__DOT__served)) 
                                             & (IData)(vlSelf->dbg_cen)));
    vlSelf->__PVT__ird = ((IData)(vlSelf->board__DOT____VdfgTmp_h8306d34d__0)
                           ? vlSelf->__PVT__io_rdata_mux
                           : vlSelf->__PVT__ram_rdata);
    vlSelf->__PVT__drd = ((IData)(vlSelf->__PVT__board__DOT__d_wants_io)
                           ? vlSelf->__PVT__io_rdata_mux
                           : vlSelf->__PVT__ram_rdata);
    board__DOT____VdfgTmp_h56676f03__0 = ((IData)(vlSelf->board__DOT____VdfgTmp_h8306d34d__0) 
                                          & (IData)(__PVT__io_ack_mux));
    board__DOT____VdfgTmp_hab3cb56a__0 = ((IData)(vlSelf->__PVT__board__DOT__d_wants_io) 
                                          & (IData)(__PVT__io_ack_mux));
    vlSelf->__PVT__ierr = ((IData)(vlSelf->board__DOT____VdfgTmp_h288a1ef5__0) 
                           | ((IData)(board__DOT____VdfgTmp_h56676f03__0) 
                              & (IData)(vlSelf->__PVT__io_err_mux)));
    vlSelf->dbg_iack = (((IData)(vlSelf->board__DOT____VdfgTmp_h22b91ed1__0) 
                         & (IData)(vlSelf->__PVT__ram_ack)) 
                        | ((IData)(board__DOT____VdfgTmp_h56676f03__0) 
                           | (IData)(vlSelf->board__DOT____VdfgTmp_h288a1ef5__0)));
    vlSelf->__PVT__derr = ((IData)(vlSelf->board__DOT____VdfgTmp_h223955ac__0) 
                           | ((IData)(board__DOT____VdfgTmp_hab3cb56a__0) 
                              & (IData)(vlSelf->__PVT__io_err_mux)));
    vlSelf->dbg_dack = (((IData)(vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0) 
                         & (IData)(vlSelf->__PVT__ram_ack)) 
                        | ((IData)(board__DOT____VdfgTmp_hab3cb56a__0) 
                           | (IData)(vlSelf->board__DOT____VdfgTmp_h223955ac__0)));
}

VL_INLINE_OPT void Vtb_sdram_tb_sdram___act_comb__TOP__tb_sdram__0(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___act_comb__TOP__tb_sdram__0\n"); );
    // Init
    CData/*0:0*/ __PVT__io_ack_mux;
    __PVT__io_ack_mux = 0;
    CData/*0:0*/ __PVT__board__DOT__i_wants_io;
    __PVT__board__DOT__i_wants_io = 0;
    CData/*0:0*/ board__DOT____VdfgTmp_h56676f03__0;
    board__DOT____VdfgTmp_h56676f03__0 = 0;
    CData/*0:0*/ board__DOT____VdfgTmp_hab3cb56a__0;
    board__DOT____VdfgTmp_hab3cb56a__0 = 0;
    // Body
    vlSelf->__PVT__board__DOT__i_wants_ram = ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__imem_req) 
                                              & (0U 
                                                 == 
                                                 (0x6000000U 
                                                  & vlSelf->__PVT__board__DOT__i_dec)));
    vlSelf->board__DOT____VdfgTmp_h288a1ef5__0 = ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__imem_req) 
                                                  & (0x4000000U 
                                                     == 
                                                     (0x6000000U 
                                                      & vlSelf->__PVT__board__DOT__i_dec)));
    __PVT__board__DOT__i_wants_io = ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__imem_req) 
                                     & (0x2000000U 
                                        == (0x6000000U 
                                            & vlSelf->__PVT__board__DOT__i_dec)));
    vlSelf->board__DOT____VdfgTmp_h22b91ed1__0 = ((
                                                   (2U 
                                                    == (IData)(vlSelf->__PVT__board__DOT__owner)) 
                                                   | ((0U 
                                                       == (IData)(vlSelf->__PVT__board__DOT__owner)) 
                                                      & ((~ (IData)(vlSelf->__PVT__board__DOT__d_wants_ram)) 
                                                         & (IData)(vlSelf->__PVT__board__DOT__i_wants_ram)))) 
                                                  & (IData)(vlSelf->__PVT__board__DOT__i_wants_ram));
    vlSelf->board__DOT____VdfgTmp_h8306d34d__0 = ((~ (IData)(vlSelf->__PVT__board__DOT__d_wants_io)) 
                                                  & (IData)(__PVT__board__DOT__i_wants_io));
    vlSelf->io_req = ((IData)(vlSelf->__PVT__board__DOT__d_wants_io) 
                      | (IData)(__PVT__board__DOT__i_wants_io));
    vlSelf->dbg_ram_req = ((IData)(vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0) 
                           | (IData)(vlSelf->board__DOT____VdfgTmp_h22b91ed1__0));
    vlSelf->__PVT__ird = ((IData)(vlSelf->board__DOT____VdfgTmp_h8306d34d__0)
                           ? vlSelf->__PVT__io_rdata_mux
                           : vlSelf->__PVT__ram_rdata);
    vlSelf->__Vcellinp__tx39__io_req = ((IData)(vlSelf->io_req) 
                                        & (IData)(vlSymsp->TOP.tx39_en));
    vlSelf->__PVT__tx39__DOT__io_start = ((IData)(vlSelf->__Vcellinp__tx39__io_req) 
                                          & ((~ (IData)(vlSelf->__PVT__tx39__DOT__served)) 
                                             & (IData)(vlSelf->dbg_cen)));
    __PVT__io_ack_mux = ((IData)(vlSymsp->TOP.tx39_en)
                          ? ((IData)(vlSelf->__Vcellinp__tx39__io_req) 
                             & (IData)(vlSelf->__PVT__tx39__DOT__served))
                          : (IData)(vlSymsp->TOP.io_ack));
    board__DOT____VdfgTmp_h56676f03__0 = ((IData)(vlSelf->board__DOT____VdfgTmp_h8306d34d__0) 
                                          & (IData)(__PVT__io_ack_mux));
    board__DOT____VdfgTmp_hab3cb56a__0 = ((IData)(vlSelf->__PVT__board__DOT__d_wants_io) 
                                          & (IData)(__PVT__io_ack_mux));
    vlSelf->__PVT__ierr = ((IData)(vlSelf->board__DOT____VdfgTmp_h288a1ef5__0) 
                           | ((IData)(board__DOT____VdfgTmp_h56676f03__0) 
                              & (IData)(vlSelf->__PVT__io_err_mux)));
    vlSelf->dbg_iack = (((IData)(vlSelf->board__DOT____VdfgTmp_h22b91ed1__0) 
                         & (IData)(vlSelf->__PVT__ram_ack)) 
                        | ((IData)(board__DOT____VdfgTmp_h56676f03__0) 
                           | (IData)(vlSelf->board__DOT____VdfgTmp_h288a1ef5__0)));
    vlSelf->__PVT__derr = ((IData)(vlSelf->board__DOT____VdfgTmp_h223955ac__0) 
                           | ((IData)(board__DOT____VdfgTmp_hab3cb56a__0) 
                              & (IData)(vlSelf->__PVT__io_err_mux)));
    vlSelf->dbg_dack = (((IData)(vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0) 
                         & (IData)(vlSelf->__PVT__ram_ack)) 
                        | ((IData)(board__DOT____VdfgTmp_hab3cb56a__0) 
                           | (IData)(vlSelf->board__DOT____VdfgTmp_h223955ac__0)));
}

VL_INLINE_OPT void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__1(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__1\n"); );
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
            if ((0x2cdU < (IData)(vlSelf->__PVT__ctl__DOT__refresh_count))) {
                __Vdly__ctl__DOT__refresh_count = (0x3fffU 
                                                   & ((IData)(1U) 
                                                      + 
                                                      ((IData)(vlSelf->__PVT__ctl__DOT__refresh_count) 
                                                       - (IData)(0x2cdU))));
                vlSelf->__Vdly__ctl__DOT__state = 0xaU;
                vlSelf->__PVT__ctl__DOT__command = 1U;
                vlSelf->__PVT__ctl__DOT__chip = 0U;
            }
        } else if ((0xaU == (IData)(vlSelf->__PVT__ctl__DOT__state))) {
            vlSelf->__Vdly__ctl__DOT__state = 9U;
            vlSelf->__PVT__ctl__DOT__command = 1U;
            vlSelf->__PVT__ctl__DOT__chip = 1U;
        } else if ((0x59aU < (IData)(vlSelf->__PVT__ctl__DOT__refresh_count))) {
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
        __Vdly__ctl__DOT__refresh_count = 0x1483U;
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

extern const VlUnpacked<CData/*0:0*/, 64> Vtb_sdram__ConstPool__TABLE_ha033e788_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vtb_sdram__ConstPool__TABLE_h8b08f1f0_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vtb_sdram__ConstPool__TABLE_heaad40ca_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vtb_sdram__ConstPool__TABLE_h0c921ac5_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vtb_sdram__ConstPool__TABLE_h801ee4dd_0;

VL_INLINE_OPT void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__2(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__2\n"); );
    // Init
    CData/*7:0*/ __PVT__tx39__DOT__tx_hold;
    __PVT__tx39__DOT__tx_hold = 0;
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
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*5:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*2:0*/ __Vdly__tx39__DOT__rxd_sync;
    __Vdly__tx39__DOT__rxd_sync = 0;
    IData/*31:0*/ __Vdly__tx39__DOT__rtc_acc;
    __Vdly__tx39__DOT__rtc_acc = 0;
    QData/*39:0*/ __Vdly__tx39__DOT__rtc;
    __Vdly__tx39__DOT__rtc = 0;
    IData/*31:0*/ __Vdlyvval__tx39__DOT__icu_status__v0;
    __Vdlyvval__tx39__DOT__icu_status__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tx39__DOT__icu_status__v0;
    __Vdlyvset__tx39__DOT__icu_status__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tx39__DOT__icu_status__v1;
    __Vdlyvval__tx39__DOT__icu_status__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tx39__DOT__icu_status__v1;
    __Vdlyvset__tx39__DOT__icu_status__v1 = 0;
    IData/*19:0*/ __Vdly__tx39__DOT__tx_cnt;
    __Vdly__tx39__DOT__tx_cnt = 0;
    IData/*31:0*/ __Vdlyvval__tx39__DOT__icu_status__v2;
    __Vdlyvval__tx39__DOT__icu_status__v2 = 0;
    CData/*0:0*/ __Vdlyvset__tx39__DOT__icu_status__v2;
    __Vdlyvset__tx39__DOT__icu_status__v2 = 0;
    CData/*3:0*/ __Vdly__tx39__DOT__tx_bit;
    __Vdly__tx39__DOT__tx_bit = 0;
    IData/*31:0*/ __Vdlyvval__tx39__DOT__icu_status__v3;
    __Vdlyvval__tx39__DOT__icu_status__v3 = 0;
    CData/*0:0*/ __Vdlyvset__tx39__DOT__icu_status__v3;
    __Vdlyvset__tx39__DOT__icu_status__v3 = 0;
    CData/*0:0*/ __Vdly__tx39__DOT__tx_busy;
    __Vdly__tx39__DOT__tx_busy = 0;
    IData/*19:0*/ __Vdly__tx39__DOT__rx_cnt;
    __Vdly__tx39__DOT__rx_cnt = 0;
    IData/*31:0*/ __Vdlyvval__tx39__DOT__icu_status__v4;
    __Vdlyvval__tx39__DOT__icu_status__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tx39__DOT__icu_status__v4;
    __Vdlyvset__tx39__DOT__icu_status__v4 = 0;
    CData/*2:0*/ __Vdlyvdim0__tx39__DOT__icu_status__v5;
    __Vdlyvdim0__tx39__DOT__icu_status__v5 = 0;
    IData/*31:0*/ __Vdlyvval__tx39__DOT__icu_status__v5;
    __Vdlyvval__tx39__DOT__icu_status__v5 = 0;
    CData/*0:0*/ __Vdlyvset__tx39__DOT__icu_status__v5;
    __Vdlyvset__tx39__DOT__icu_status__v5 = 0;
    IData/*31:0*/ __Vdlyvval__tx39__DOT__icu_status__v6;
    __Vdlyvval__tx39__DOT__icu_status__v6 = 0;
    CData/*0:0*/ __Vdlyvset__tx39__DOT__icu_status__v6;
    __Vdlyvset__tx39__DOT__icu_status__v6 = 0;
    IData/*31:0*/ __Vdlyvval__tx39__DOT__icu_status__v7;
    __Vdlyvval__tx39__DOT__icu_status__v7 = 0;
    CData/*0:0*/ __Vdlyvset__tx39__DOT__icu_status__v7;
    __Vdlyvset__tx39__DOT__icu_status__v7 = 0;
    IData/*31:0*/ __Vdlyvval__tx39__DOT__icu_status__v8;
    __Vdlyvval__tx39__DOT__icu_status__v8 = 0;
    CData/*0:0*/ __Vdlyvset__tx39__DOT__icu_status__v8;
    __Vdlyvset__tx39__DOT__icu_status__v8 = 0;
    CData/*0:0*/ __Vdlyvset__tx39__DOT__icu_status__v9;
    __Vdlyvset__tx39__DOT__icu_status__v9 = 0;
    CData/*0:0*/ __Vdlyvset__tx39__DOT__icu_status__v10;
    __Vdlyvset__tx39__DOT__icu_status__v10 = 0;
    CData/*7:0*/ __Vdlyvdim0__tx39__DOT__rf__v0;
    __Vdlyvdim0__tx39__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tx39__DOT__rf__v0;
    __Vdlyvval__tx39__DOT__rf__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tx39__DOT__rf__v0;
    __Vdlyvset__tx39__DOT__rf__v0 = 0;
    CData/*0:0*/ __Vdly__tx39__DOT__served;
    __Vdly__tx39__DOT__served = 0;
    CData/*2:0*/ __Vdlyvdim0__tx39__DOT__icu_enable__v0;
    __Vdlyvdim0__tx39__DOT__icu_enable__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tx39__DOT__icu_enable__v0;
    __Vdlyvval__tx39__DOT__icu_enable__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tx39__DOT__icu_enable__v0;
    __Vdlyvset__tx39__DOT__icu_enable__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tx39__DOT__icu_enable__v1;
    __Vdlyvset__tx39__DOT__icu_enable__v1 = 0;
    CData/*0:0*/ __Vdly__ram_ack;
    __Vdly__ram_ack = 0;
    CData/*3:0*/ __Vdly__adapter__DOT__state;
    __Vdly__adapter__DOT__state = 0;
    // Body
    __Vdly__tx39__DOT__served = vlSelf->__PVT__tx39__DOT__served;
    __Vdly__adapter__DOT__state = vlSelf->__PVT__adapter__DOT__state;
    __Vdly__ram_ack = vlSelf->__PVT__ram_ack;
    __Vdlyvset__tx39__DOT__rf__v0 = 0U;
    __Vdlyvset__tx39__DOT__icu_enable__v0 = 0U;
    __Vdlyvset__tx39__DOT__icu_enable__v1 = 0U;
    __Vdly__tx39__DOT__rx_cnt = vlSelf->__PVT__tx39__DOT__rx_cnt;
    __Vdly__tx39__DOT__tx_bit = vlSelf->__PVT__tx39__DOT__tx_bit;
    __Vdly__tx39__DOT__tx_cnt = vlSelf->__PVT__tx39__DOT__tx_cnt;
    __Vdly__tx39__DOT__rtc_acc = vlSelf->__PVT__tx39__DOT__rtc_acc;
    __Vdly__tx39__DOT__rxd_sync = vlSelf->__PVT__tx39__DOT__rxd_sync;
    __Vdly__tx39__DOT__tx_busy = vlSelf->__PVT__tx39__DOT__tx_busy;
    __Vdly__tx39__DOT__rtc = vlSelf->__PVT__tx39__DOT__rtc;
    __Vdlyvset__tx39__DOT__icu_status__v0 = 0U;
    __Vdlyvset__tx39__DOT__icu_status__v1 = 0U;
    __Vdlyvset__tx39__DOT__icu_status__v2 = 0U;
    __Vdlyvset__tx39__DOT__icu_status__v3 = 0U;
    __Vdlyvset__tx39__DOT__icu_status__v4 = 0U;
    __Vdlyvset__tx39__DOT__icu_status__v5 = 0U;
    __Vdlyvset__tx39__DOT__icu_status__v6 = 0U;
    __Vdlyvset__tx39__DOT__icu_status__v7 = 0U;
    __Vdlyvset__tx39__DOT__icu_status__v8 = 0U;
    __Vdlyvset__tx39__DOT__icu_status__v9 = 0U;
    __Vdlyvset__tx39__DOT__icu_status__v10 = 0U;
    if (vlSymsp->TOP.rst_n) {
        vlSelf->__PVT__cdiv = (((0xffU & ((IData)(1U) 
                                          + (IData)(vlSelf->__PVT__cdiv))) 
                                >= (IData)(vlSymsp->TOP.clk_div))
                                ? 0U : (0xffU & ((IData)(1U) 
                                                 + (IData)(vlSelf->__PVT__cdiv))));
        if (vlSelf->__Vcellinp__tx39__io_req) {
            if (((~ (IData)(vlSelf->__PVT__tx39__DOT__served)) 
                 & (IData)(vlSelf->dbg_cen))) {
                __Vdly__tx39__DOT__served = 1U;
            } else if (((IData)(vlSelf->__PVT__tx39__DOT__served) 
                        & (IData)(vlSelf->dbg_cen))) {
                __Vdly__tx39__DOT__served = 0U;
            }
        } else {
            __Vdly__tx39__DOT__served = 0U;
        }
        if (vlSelf->dbg_cen) {
            vlSelf->__PVT__tx39__DOT__irq_r = (((0U 
                                                 != 
                                                 (vlSelf->__PVT__tx39__DOT__icu_status
                                                  [5U] 
                                                  & vlSelf->__PVT__tx39__DOT__icu_enable
                                                  [5U])) 
                                                << 2U) 
                                               | (0U 
                                                  != 
                                                  ((vlSelf->__PVT__tx39__DOT__icu_status
                                                    [0U] 
                                                    & vlSelf->__PVT__tx39__DOT__icu_enable
                                                    [0U]) 
                                                   | ((vlSelf->__PVT__tx39__DOT__icu_status
                                                       [1U] 
                                                       & vlSelf->__PVT__tx39__DOT__icu_enable
                                                       [1U]) 
                                                      | ((vlSelf->__PVT__tx39__DOT__icu_status
                                                          [2U] 
                                                          & vlSelf->__PVT__tx39__DOT__icu_enable
                                                          [2U]) 
                                                         | ((vlSelf->__PVT__tx39__DOT__icu_status
                                                             [3U] 
                                                             & vlSelf->__PVT__tx39__DOT__icu_enable
                                                             [3U]) 
                                                            | (vlSelf->__PVT__tx39__DOT__icu_status
                                                               [4U] 
                                                               & vlSelf->__PVT__tx39__DOT__icu_enable
                                                               [4U])))))));
        }
        vlSelf->dbg_tx_stb = 0U;
        __Vdly__tx39__DOT__rxd_sync = (1U | (6U & ((IData)(vlSelf->__PVT__tx39__DOT__rxd_sync) 
                                                   << 1U)));
        if ((1U & (~ (vlSelf->__PVT__tx39__DOT__t_ctrl 
                      >> 6U)))) {
            if ((0x57bcf00U <= ((IData)(0x8000U) + vlSelf->__PVT__tx39__DOT__rtc_acc))) {
                __Vdly__tx39__DOT__rtc_acc = ((IData)(0xfa84b100U) 
                                              + vlSelf->__PVT__tx39__DOT__rtc_acc);
                __Vdly__tx39__DOT__rtc = (0xffffffffffULL 
                                          & (1ULL + vlSelf->__PVT__tx39__DOT__rtc));
            } else {
                __Vdly__tx39__DOT__rtc_acc = ((IData)(0x8000U) 
                                              + vlSelf->__PVT__tx39__DOT__rtc_acc);
            }
        }
        if ((((0ULL != vlSelf->__PVT__tx39__DOT__rtc_alarm) 
              & (vlSelf->__PVT__tx39__DOT__rtc >= vlSelf->__PVT__tx39__DOT__rtc_alarm)) 
             & (~ (vlSelf->__PVT__tx39__DOT__icu_status
                   [4U] >> 0x1eU)))) {
            __Vdlyvval__tx39__DOT__icu_status__v0 = 
                (0x40000000U | vlSelf->__PVT__tx39__DOT__icu_status
                 [4U]);
            __Vdlyvset__tx39__DOT__icu_status__v0 = 1U;
        }
        if (((vlSelf->__PVT__tx39__DOT__t_ctrl >> 4U) 
             & (0U != (0xffffU & vlSelf->__PVT__tx39__DOT__t_per)))) {
            if (((0xffffffffffULL & (vlSelf->__PVT__tx39__DOT__rtc 
                                     - vlSelf->__PVT__tx39__DOT__per_last)) 
                 >= (QData)((IData)((0xffffU & vlSelf->__PVT__tx39__DOT__t_per))))) {
                __Vdlyvval__tx39__DOT__icu_status__v1 
                    = (0x20000000U | vlSelf->__PVT__tx39__DOT__icu_status
                       [4U]);
                __Vdlyvset__tx39__DOT__icu_status__v1 = 1U;
                vlSelf->__PVT__tx39__DOT__per_last 
                    = vlSelf->__PVT__tx39__DOT__rtc;
            }
        } else {
            vlSelf->__PVT__tx39__DOT__per_last = vlSelf->__PVT__tx39__DOT__rtc;
        }
        if (vlSelf->__PVT__tx39__DOT__tx_busy) {
            if ((vlSelf->__PVT__tx39__DOT__tx_cnt >= 
                 (0xfffffU & ((IData)(0x18fU) * (0xfffffU 
                                                 & ((IData)(1U) 
                                                    + 
                                                    (0x3ffU 
                                                     & vlSelf->__PVT__tx39__DOT__ua_ctrl2))))))) {
                __Vdly__tx39__DOT__tx_cnt = 0U;
                if ((9U == (IData)(vlSelf->__PVT__tx39__DOT__tx_bit))) {
                    if (vlSelf->__PVT__tx39__DOT__tx_hold_full) {
                        __Vdlyvval__tx39__DOT__icu_status__v2 
                            = (0x4000000U | vlSelf->__PVT__tx39__DOT__icu_status
                               [1U]);
                        __Vdlyvset__tx39__DOT__icu_status__v2 = 1U;
                        vlSelf->__PVT__tx39__DOT__tx_hold_full = 0U;
                        __Vdly__tx39__DOT__tx_bit = 0U;
                    } else {
                        __Vdlyvval__tx39__DOT__icu_status__v3 
                            = (0x1000000U | vlSelf->__PVT__tx39__DOT__icu_status
                               [1U]);
                        __Vdlyvset__tx39__DOT__icu_status__v3 = 1U;
                        __Vdly__tx39__DOT__tx_busy = 0U;
                    }
                } else {
                    __Vdly__tx39__DOT__tx_bit = (0xfU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->__PVT__tx39__DOT__tx_bit)));
                }
            } else {
                __Vdly__tx39__DOT__tx_cnt = (0xfffffU 
                                             & ((IData)(1U) 
                                                + vlSelf->__PVT__tx39__DOT__tx_cnt));
            }
        }
        if (vlSelf->__PVT__tx39__DOT__rx_busy) {
            if ((vlSelf->__PVT__tx39__DOT__rx_cnt >= 
                 (0xfffffU & ((IData)(0x18fU) * (0xfffffU 
                                                 & ((IData)(1U) 
                                                    + 
                                                    (0x3ffU 
                                                     & vlSelf->__PVT__tx39__DOT__ua_ctrl2))))))) {
                __Vdly__tx39__DOT__rx_cnt = 0U;
                if ((8U == (IData)(vlSelf->__PVT__tx39__DOT__rx_bit))) {
                    __Vdlyvval__tx39__DOT__icu_status__v4 
                        = (0x80000000U | vlSelf->__PVT__tx39__DOT__icu_status
                           [1U]);
                    __Vdlyvset__tx39__DOT__icu_status__v4 = 1U;
                    vlSelf->__PVT__tx39__DOT__rx_busy = 0U;
                    vlSelf->__PVT__tx39__DOT__ua_rx 
                        = vlSelf->__PVT__tx39__DOT__rx_shift;
                    vlSelf->__PVT__tx39__DOT__ua_rx_full = 1U;
                } else {
                    vlSelf->__PVT__tx39__DOT__rx_shift 
                        = ((0x80U & ((IData)(vlSelf->__PVT__tx39__DOT__rxd_sync) 
                                     << 5U)) | (0x7fU 
                                                & ((IData)(vlSelf->__PVT__tx39__DOT__rx_shift) 
                                                   >> 1U)));
                    vlSelf->__PVT__tx39__DOT__rx_bit 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->__PVT__tx39__DOT__rx_bit)));
                }
            } else {
                __Vdly__tx39__DOT__rx_cnt = (0xfffffU 
                                             & ((IData)(1U) 
                                                + vlSelf->__PVT__tx39__DOT__rx_cnt));
            }
        } else if ((2U == (3U & ((IData)(vlSelf->__PVT__tx39__DOT__rxd_sync) 
                                 >> 1U)))) {
            vlSelf->__PVT__tx39__DOT__rx_bit = 0U;
            vlSelf->__PVT__tx39__DOT__rx_busy = 1U;
            __Vdly__tx39__DOT__rx_cnt = (0x7ffffU & 
                                         (((IData)(0x18fU) 
                                           * (0xfffffU 
                                              & ((IData)(1U) 
                                                 + 
                                                 (0x3ffU 
                                                  & vlSelf->__PVT__tx39__DOT__ua_ctrl2)))) 
                                          >> 1U));
        }
        if ((((IData)(vlSelf->__PVT__tx39__DOT__io_start) 
              & (IData)(vlSelf->__PVT__tx39__DOT__is_tx39)) 
             & (IData)(vlSelf->io_we))) {
            __Vdlyvval__tx39__DOT__rf__v0 = ((0xe0U 
                                              == (0xfffU 
                                                  & vlSelf->io_addr))
                                              ? (0xdfffffffU 
                                                 & vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word)
                                              : vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word);
            __Vdlyvset__tx39__DOT__rf__v0 = 1U;
            __Vdlyvdim0__tx39__DOT__rf__v0 = (0xffU 
                                              & (vlSelf->io_addr 
                                                 >> 2U));
            if (((0x100U <= (0xfffU & vlSelf->io_addr)) 
                 & (0x118U > (0xfffU & vlSelf->io_addr)))) {
                vlSelf->tx39__DOT____Vlvbound_h2237671c__0 
                    = (((5U >= (7U & (vlSelf->io_addr 
                                      >> 2U))) ? vlSelf->__PVT__tx39__DOT__icu_status
                        [(7U & (vlSelf->io_addr >> 2U))]
                         : 0U) & (~ vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word));
                if ((5U >= (7U & (vlSelf->io_addr >> 2U)))) {
                    __Vdlyvval__tx39__DOT__icu_status__v5 
                        = vlSelf->tx39__DOT____Vlvbound_h2237671c__0;
                    __Vdlyvset__tx39__DOT__icu_status__v5 = 1U;
                    __Vdlyvdim0__tx39__DOT__icu_status__v5 
                        = (7U & (vlSelf->io_addr >> 2U));
                }
            } else if ((1U & (~ ((0x118U <= (0xfffU 
                                             & vlSelf->io_addr)) 
                                 & (0x130U > (0xfffU 
                                              & vlSelf->io_addr)))))) {
                if ((0xb0U == (0xfffU & vlSelf->io_addr))) {
                    if ((1U & ((~ vlSelf->__PVT__tx39__DOT__ua_ctrl1) 
                               & vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word))) {
                        __Vdlyvval__tx39__DOT__icu_status__v6 
                            = (0x5000000U | vlSelf->__PVT__tx39__DOT__icu_status
                               [1U]);
                        __Vdlyvset__tx39__DOT__icu_status__v6 = 1U;
                    }
                } else if ((0x148U != (0xfffU & vlSelf->io_addr))) {
                    if ((0x14cU != (0xfffU & vlSelf->io_addr))) {
                        if ((0x150U == (0xfffU & vlSelf->io_addr))) {
                            if ((8U & vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word)) {
                                __Vdly__tx39__DOT__rtc = 0ULL;
                                __Vdly__tx39__DOT__rtc_acc = 0U;
                                vlSelf->__PVT__tx39__DOT__per_last = 0ULL;
                            }
                        } else if ((0x154U != (0xfffU 
                                               & vlSelf->io_addr))) {
                            if ((0xb4U != (0xfffU & vlSelf->io_addr))) {
                                if ((0xc4U == (0xfffU 
                                               & vlSelf->io_addr))) {
                                    if (vlSelf->__PVT__tx39__DOT__tx_busy) {
                                        __PVT__tx39__DOT__tx_hold 
                                            = (0xffU 
                                               & vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word);
                                        vlSelf->__PVT__tx39__DOT__tx_hold_full = 1U;
                                    } else {
                                        __Vdlyvval__tx39__DOT__icu_status__v7 
                                            = (0x4000000U 
                                               | vlSelf->__PVT__tx39__DOT__icu_status
                                               [1U]);
                                        __Vdlyvset__tx39__DOT__icu_status__v7 = 1U;
                                        __Vdly__tx39__DOT__tx_busy = 1U;
                                        __Vdly__tx39__DOT__tx_bit = 0U;
                                        __Vdly__tx39__DOT__tx_cnt = 0U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if ((1U & (~ ((0x100U <= (0xfffU & vlSelf->io_addr)) 
                          & (0x118U > (0xfffU & vlSelf->io_addr)))))) {
                if ((1U & (~ ((0x118U <= (0xfffU & vlSelf->io_addr)) 
                              & (0x130U > (0xfffU & vlSelf->io_addr)))))) {
                    if ((0xb0U != (0xfffU & vlSelf->io_addr))) {
                        if ((0x148U != (0xfffU & vlSelf->io_addr))) {
                            if ((0x14cU != (0xfffU 
                                            & vlSelf->io_addr))) {
                                if ((0x150U != (0xfffU 
                                                & vlSelf->io_addr))) {
                                    if ((0x154U != 
                                         (0xfffU & vlSelf->io_addr))) {
                                        if ((0xb4U 
                                             != (0xfffU 
                                                 & vlSelf->io_addr))) {
                                            if ((0xc4U 
                                                 == 
                                                 (0xfffU 
                                                  & vlSelf->io_addr))) {
                                                vlSelf->dbg_tx_bytes 
                                                    = 
                                                    ((IData)(1U) 
                                                     + vlSelf->dbg_tx_bytes);
                                                vlSelf->dbg_tx_stb = 1U;
                                                vlSelf->dbg_tx_data 
                                                    = 
                                                    (0xffU 
                                                     & vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word);
                                            }
                                        }
                                        if ((0xb4U 
                                             == (0xfffU 
                                                 & vlSelf->io_addr))) {
                                            vlSelf->__PVT__tx39__DOT__ua_ctrl2 
                                                = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word;
                                        }
                                    }
                                    if ((0x154U == 
                                         (0xfffU & vlSelf->io_addr))) {
                                        vlSelf->__PVT__tx39__DOT__t_per 
                                            = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word;
                                    }
                                }
                                if ((0x150U == (0xfffU 
                                                & vlSelf->io_addr))) {
                                    vlSelf->__PVT__tx39__DOT__t_ctrl 
                                        = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word;
                                }
                            }
                        }
                        if ((0x148U == (0xfffU & vlSelf->io_addr))) {
                            vlSelf->__PVT__tx39__DOT__rtc_alarm 
                                = ((0xffffffffULL & vlSelf->__PVT__tx39__DOT__rtc_alarm) 
                                   | ((QData)((IData)(
                                                      (0xffU 
                                                       & vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word))) 
                                      << 0x20U));
                        } else if ((0x14cU == (0xfffU 
                                               & vlSelf->io_addr))) {
                            vlSelf->__PVT__tx39__DOT__rtc_alarm 
                                = ((0xff00000000ULL 
                                    & vlSelf->__PVT__tx39__DOT__rtc_alarm) 
                                   | (IData)((IData)(vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word)));
                        }
                    }
                    if ((0xb0U == (0xfffU & vlSelf->io_addr))) {
                        vlSelf->__PVT__tx39__DOT__ua_ctrl1 
                            = (0xfffffffU & vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word);
                    }
                }
                if (((0x118U <= (0xfffU & vlSelf->io_addr)) 
                     & (0x130U > (0xfffU & vlSelf->io_addr)))) {
                    vlSelf->tx39__DOT____Vlvbound_hadcbb189__0 
                        = vlSymsp->TOP__tb_sdram__cpu__cpu.__PVT__store_word;
                    if ((5U >= (7U & ((vlSelf->io_addr 
                                       >> 2U) - (IData)(6U))))) {
                        __Vdlyvval__tx39__DOT__icu_enable__v0 
                            = vlSelf->tx39__DOT____Vlvbound_hadcbb189__0;
                        __Vdlyvset__tx39__DOT__icu_enable__v0 = 1U;
                        __Vdlyvdim0__tx39__DOT__icu_enable__v0 
                            = (7U & ((vlSelf->io_addr 
                                      >> 2U) - (IData)(6U)));
                    }
                }
            }
        }
        if (((IData)(vlSelf->__PVT__tx39__DOT__io_start) 
             & (~ (IData)(vlSelf->io_we)))) {
            if (((IData)(vlSelf->__PVT__tx39__DOT__is_tx39) 
                 & (0xc4U == (0xfffU & vlSelf->io_addr)))) {
                __Vdlyvval__tx39__DOT__icu_status__v8 
                    = (0x7fffffffU & vlSelf->__PVT__tx39__DOT__icu_status
                       [1U]);
                __Vdlyvset__tx39__DOT__icu_status__v8 = 1U;
                vlSelf->__PVT__tx39__DOT__ua_rx_full = 0U;
            }
        }
        vlSelf->__PVT__ch1_req = 0U;
        vlSelf->__PVT__ch2_req = 0U;
        if (vlSelf->__PVT__adapter__DOT__ack_taken) {
            __Vdly__ram_ack = 0U;
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
                __Vdly__adapter__DOT__state = 0U;
            } else if ((2U & (IData)(vlSelf->__PVT__adapter__DOT__state))) {
                if ((1U & (IData)(vlSelf->__PVT__adapter__DOT__state))) {
                    if (vlSelf->__PVT__adapter__DOT__ack_taken) {
                        __Vdly__adapter__DOT__state = 0U;
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
                    __Vdly__ram_ack = 1U;
                    __Vdly__adapter__DOT__state = 0xbU;
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
                    __Vdly__ram_ack = 1U;
                    __Vdly__adapter__DOT__state = 0xaU;
                }
            } else if (vlSelf->__PVT__adapter__DOT__ack_taken) {
                vlSelf->__PVT__ch1_addr = (4U | (0xfffff8U 
                                                 & (vlSelf->__PVT__adapter__DOT__line 
                                                    >> 1U)));
                vlSelf->__PVT__ch1_req = 1U;
                __Vdly__adapter__DOT__state = 9U;
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
                        __Vdly__ram_ack = 1U;
                        __Vdly__adapter__DOT__state = 8U;
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
                    __Vdly__ram_ack = 1U;
                    __Vdly__adapter__DOT__state = 7U;
                }
            } else if ((1U & (IData)(vlSelf->__PVT__adapter__DOT__state))) {
                if (vlSelf->__PVT__adapter__DOT__ack_taken) {
                    __Vdly__adapter__DOT__state = 0U;
                }
            } else {
                __Vfunc_adapter__DOT__swap__6__x = vlSelf->__PVT__adapter__DOT__merged;
                __Vfunc_adapter__DOT__swap__6__Vfuncout 
                    = ((__Vfunc_adapter__DOT__swap__6__x 
                        << 0x10U) | (__Vfunc_adapter__DOT__swap__6__x 
                                     >> 0x10U));
                vlSelf->__PVT__ch2_din = __Vfunc_adapter__DOT__swap__6__Vfuncout;
                vlSelf->__PVT__ch2_req = 1U;
                __Vdly__adapter__DOT__state = 2U;
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
                    __Vdly__adapter__DOT__state = 4U;
                }
            } else if (((IData)(vlSelf->__PVT__adapter__DOT__ch2_done) 
                        & (IData)(vlSelf->dbg_cen))) {
                __Vdly__ram_ack = 1U;
                __Vdly__adapter__DOT__state = 5U;
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
                __Vdly__ram_ack = 1U;
                __Vdly__adapter__DOT__state = 5U;
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
                __Vdly__adapter__DOT__state = 6U;
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
                __Vdly__adapter__DOT__state = 2U;
            } else if (vlSelf->__PVT__ram_we) {
                vlSelf->__PVT__ch2_addr = (0xffffffU 
                                           & (vlSelf->dbg_ram_addr 
                                              >> 1U));
                vlSelf->__PVT__ch2_rnw = 1U;
                vlSelf->__PVT__ch2_req = 1U;
                __Vdly__adapter__DOT__state = 3U;
            } else {
                vlSelf->__PVT__ch2_addr = (0xffffffU 
                                           & (vlSelf->dbg_ram_addr 
                                              >> 1U));
                vlSelf->__PVT__ch2_rnw = 1U;
                vlSelf->__PVT__ch2_req = 1U;
                __Vdly__adapter__DOT__state = 1U;
            }
        }
    } else {
        vlSelf->__PVT__cdiv = 0U;
        __Vdly__tx39__DOT__served = 0U;
        vlSelf->dbg_tx_bytes = 0U;
        __Vdlyvset__tx39__DOT__icu_enable__v1 = 1U;
        vlSelf->__PVT__tx39__DOT__irq_r = 0U;
        vlSelf->dbg_tx_stb = 0U;
        vlSelf->dbg_tx_data = 0U;
        vlSelf->__PVT__tx39__DOT__rx_bit = 0U;
        __Vdly__tx39__DOT__rtc = 0ULL;
        __Vdly__tx39__DOT__rtc_acc = 0U;
        __Vdlyvset__tx39__DOT__icu_status__v9 = 1U;
        vlSelf->__PVT__tx39__DOT__ua_rx = 0U;
        vlSelf->__PVT__tx39__DOT__ua_rx_full = 0U;
        __Vdly__tx39__DOT__tx_busy = 0U;
        vlSelf->__PVT__tx39__DOT__tx_hold_full = 0U;
        __Vdly__tx39__DOT__tx_bit = 0U;
        __Vdly__tx39__DOT__tx_cnt = 0U;
        vlSelf->__PVT__tx39__DOT__rx_busy = 0U;
        __Vdly__tx39__DOT__rx_cnt = 0U;
        __Vdly__tx39__DOT__rxd_sync = 7U;
        vlSelf->__PVT__tx39__DOT__per_last = 0ULL;
        __Vdlyvset__tx39__DOT__icu_status__v10 = 1U;
        __Vdly__adapter__DOT__state = 0U;
        vlSelf->dbg_start = 0U;
        vlSelf->__PVT__ch1_req = 0U;
        vlSelf->__PVT__ch2_req = 0U;
        __Vdly__ram_ack = 0U;
        vlSelf->__PVT__tx39__DOT__t_ctrl = 0U;
        vlSelf->__PVT__tx39__DOT__rtc_alarm = 0ULL;
        vlSelf->__PVT__tx39__DOT__t_per = 0U;
        vlSelf->__PVT__tx39__DOT__ua_ctrl2 = 0U;
        vlSelf->__PVT__tx39__DOT__ua_ctrl1 = 0U;
    }
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
    vlSelf->__PVT__tx39__DOT__served = __Vdly__tx39__DOT__served;
    if (__Vdlyvset__tx39__DOT__rf__v0) {
        vlSelf->__PVT__tx39__DOT__rf[__Vdlyvdim0__tx39__DOT__rf__v0] 
            = __Vdlyvval__tx39__DOT__rf__v0;
    }
    if (__Vdlyvset__tx39__DOT__icu_enable__v0) {
        vlSelf->__PVT__tx39__DOT__icu_enable[__Vdlyvdim0__tx39__DOT__icu_enable__v0] 
            = __Vdlyvval__tx39__DOT__icu_enable__v0;
    }
    if (__Vdlyvset__tx39__DOT__icu_enable__v1) {
        vlSelf->__PVT__tx39__DOT__icu_enable[0U] = 0U;
        vlSelf->__PVT__tx39__DOT__icu_enable[1U] = 0U;
        vlSelf->__PVT__tx39__DOT__icu_enable[2U] = 0U;
        vlSelf->__PVT__tx39__DOT__icu_enable[3U] = 0U;
        vlSelf->__PVT__tx39__DOT__icu_enable[4U] = 0U;
        vlSelf->__PVT__tx39__DOT__icu_enable[5U] = 0U;
    }
    vlSelf->__PVT__tx39__DOT__rxd_sync = __Vdly__tx39__DOT__rxd_sync;
    vlSelf->__PVT__tx39__DOT__rtc_acc = __Vdly__tx39__DOT__rtc_acc;
    vlSelf->__PVT__tx39__DOT__tx_cnt = __Vdly__tx39__DOT__tx_cnt;
    vlSelf->__PVT__tx39__DOT__tx_bit = __Vdly__tx39__DOT__tx_bit;
    vlSelf->__PVT__tx39__DOT__rx_cnt = __Vdly__tx39__DOT__rx_cnt;
    vlSelf->__PVT__tx39__DOT__rtc = __Vdly__tx39__DOT__rtc;
    vlSelf->__PVT__tx39__DOT__tx_busy = __Vdly__tx39__DOT__tx_busy;
    if (__Vdlyvset__tx39__DOT__icu_status__v0) {
        vlSelf->__PVT__tx39__DOT__icu_status[4U] = __Vdlyvval__tx39__DOT__icu_status__v0;
    }
    if (__Vdlyvset__tx39__DOT__icu_status__v1) {
        vlSelf->__PVT__tx39__DOT__icu_status[4U] = __Vdlyvval__tx39__DOT__icu_status__v1;
    }
    if (__Vdlyvset__tx39__DOT__icu_status__v2) {
        vlSelf->__PVT__tx39__DOT__icu_status[1U] = __Vdlyvval__tx39__DOT__icu_status__v2;
    }
    if (__Vdlyvset__tx39__DOT__icu_status__v3) {
        vlSelf->__PVT__tx39__DOT__icu_status[1U] = __Vdlyvval__tx39__DOT__icu_status__v3;
    }
    if (__Vdlyvset__tx39__DOT__icu_status__v4) {
        vlSelf->__PVT__tx39__DOT__icu_status[1U] = __Vdlyvval__tx39__DOT__icu_status__v4;
    }
    if (__Vdlyvset__tx39__DOT__icu_status__v5) {
        vlSelf->__PVT__tx39__DOT__icu_status[__Vdlyvdim0__tx39__DOT__icu_status__v5] 
            = __Vdlyvval__tx39__DOT__icu_status__v5;
    }
    if (__Vdlyvset__tx39__DOT__icu_status__v6) {
        vlSelf->__PVT__tx39__DOT__icu_status[1U] = __Vdlyvval__tx39__DOT__icu_status__v6;
    }
    if (__Vdlyvset__tx39__DOT__icu_status__v7) {
        vlSelf->__PVT__tx39__DOT__icu_status[1U] = __Vdlyvval__tx39__DOT__icu_status__v7;
    }
    if (__Vdlyvset__tx39__DOT__icu_status__v8) {
        vlSelf->__PVT__tx39__DOT__icu_status[1U] = __Vdlyvval__tx39__DOT__icu_status__v8;
    }
    if (__Vdlyvset__tx39__DOT__icu_status__v9) {
        vlSelf->__PVT__tx39__DOT__icu_status[0U] = 0U;
    }
    if (__Vdlyvset__tx39__DOT__icu_status__v10) {
        vlSelf->__PVT__tx39__DOT__icu_status[1U] = 0U;
        vlSelf->__PVT__tx39__DOT__icu_status[2U] = 0U;
        vlSelf->__PVT__tx39__DOT__icu_status[3U] = 0U;
        vlSelf->__PVT__tx39__DOT__icu_status[4U] = 0U;
        vlSelf->__PVT__tx39__DOT__icu_status[5U] = 0U;
    }
    vlSelf->__PVT__ram_ack = __Vdly__ram_ack;
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
    vlSelf->__PVT__adapter__DOT__state = __Vdly__adapter__DOT__state;
}

VL_INLINE_OPT void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__3(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__3\n"); );
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
        vlSelf->io_we = vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_we;
        vlSelf->io_addr = vlSymsp->TOP__tb_sdram__cpu.__PVT__dmem_addr;
    } else {
        vlSelf->io_we = 0U;
        vlSelf->io_addr = vlSymsp->TOP__tb_sdram__cpu.__PVT__imem_addr;
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
    vlSelf->__PVT__tx39__DOT__is_tx39 = ((0x10c00000U 
                                          <= vlSelf->io_addr) 
                                         & (0x10c00400U 
                                            > vlSelf->io_addr));
}

VL_INLINE_OPT void Vtb_sdram_tb_sdram___nba_comb__TOP__tb_sdram__0(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___nba_comb__TOP__tb_sdram__0\n"); );
    // Body
    vlSelf->__PVT__t_rdata = ((IData)(vlSelf->__PVT__tx39__DOT__is_tx39)
                               ? ((0x104U == (0xfffU 
                                              & vlSelf->io_addr))
                                   ? (0xa00U | vlSelf->__PVT__tx39__DOT__icu_status
                                      [1U]) : (((0x100U 
                                                 <= 
                                                 (0xfffU 
                                                  & vlSelf->io_addr)) 
                                                & (0x118U 
                                                   > 
                                                   (0xfffU 
                                                    & vlSelf->io_addr)))
                                                ? (
                                                   (5U 
                                                    >= 
                                                    (7U 
                                                     & (vlSelf->io_addr 
                                                        >> 2U)))
                                                    ? 
                                                   vlSelf->__PVT__tx39__DOT__icu_status
                                                   [
                                                   (7U 
                                                    & (vlSelf->io_addr 
                                                       >> 2U))]
                                                    : 0U)
                                                : (
                                                   (0x140U 
                                                    == 
                                                    (0xfffU 
                                                     & vlSelf->io_addr))
                                                    ? 
                                                   (0xffU 
                                                    & (IData)(
                                                              (vlSelf->__PVT__tx39__DOT__rtc 
                                                               >> 0x20U)))
                                                    : 
                                                   ((0x144U 
                                                     == 
                                                     (0xfffU 
                                                      & vlSelf->io_addr))
                                                     ? (IData)(vlSelf->__PVT__tx39__DOT__rtc)
                                                     : 
                                                    ((0x148U 
                                                      == 
                                                      (0xfffU 
                                                       & vlSelf->io_addr))
                                                      ? 
                                                     (0xffU 
                                                      & (IData)(
                                                                (vlSelf->__PVT__tx39__DOT__rtc_alarm 
                                                                 >> 0x20U)))
                                                      : 
                                                     ((0x14cU 
                                                       == 
                                                       (0xfffU 
                                                        & vlSelf->io_addr))
                                                       ? (IData)(vlSelf->__PVT__tx39__DOT__rtc_alarm)
                                                       : 
                                                      ((0x150U 
                                                        == 
                                                        (0xfffU 
                                                         & vlSelf->io_addr))
                                                        ? vlSelf->__PVT__tx39__DOT__t_ctrl
                                                        : 
                                                       ((0x154U 
                                                         == 
                                                         (0xfffU 
                                                          & vlSelf->io_addr))
                                                         ? vlSelf->__PVT__tx39__DOT__t_per
                                                         : 
                                                        ((0xe0U 
                                                          == 
                                                          (0xfffU 
                                                           & vlSelf->io_addr))
                                                          ? 
                                                         (0x20000000U 
                                                          | (0x7fffffffU 
                                                             & vlSelf->__PVT__tx39__DOT__rf_q))
                                                          : 
                                                         (((0x118U 
                                                            <= 
                                                            (0xfffU 
                                                             & vlSelf->io_addr)) 
                                                           & (0x130U 
                                                              > 
                                                              (0xfffU 
                                                               & vlSelf->io_addr)))
                                                           ? 
                                                          ((5U 
                                                            >= 
                                                            (7U 
                                                             & ((vlSelf->io_addr 
                                                                 >> 2U) 
                                                                - (IData)(6U))))
                                                            ? 
                                                           vlSelf->__PVT__tx39__DOT__icu_enable
                                                           [
                                                           (7U 
                                                            & ((vlSelf->io_addr 
                                                                >> 2U) 
                                                               - (IData)(6U)))]
                                                            : 0U)
                                                           : 
                                                          ((0xb0U 
                                                            == 
                                                            (0xfffU 
                                                             & vlSelf->io_addr))
                                                            ? 
                                                           (((vlSelf->__PVT__tx39__DOT__ua_ctrl1 
                                                              | ((1U 
                                                                  & vlSelf->__PVT__tx39__DOT__ua_ctrl1)
                                                                  ? 0x80000000U
                                                                  : 0U)) 
                                                             | ((IData)(vlSelf->__PVT__tx39__DOT__tx_busy)
                                                                 ? 0U
                                                                 : 0x40000000U)) 
                                                            | ((IData)(vlSelf->__PVT__tx39__DOT__ua_rx_full)
                                                                ? 0x10000000U
                                                                : 0U))
                                                            : 
                                                           ((0xb4U 
                                                             == 
                                                             (0xfffU 
                                                              & vlSelf->io_addr))
                                                             ? vlSelf->__PVT__tx39__DOT__ua_ctrl2
                                                             : 
                                                            ((0xc4U 
                                                              == 
                                                              (0xfffU 
                                                               & vlSelf->io_addr))
                                                              ? (IData)(vlSelf->__PVT__tx39__DOT__ua_rx)
                                                              : vlSelf->__PVT__tx39__DOT__rf_q)))))))))))))
                               : 0xffffffffU);
    vlSelf->__PVT__io_rdata_mux = ((IData)(vlSymsp->TOP.tx39_en)
                                    ? vlSelf->__PVT__t_rdata
                                    : vlSymsp->TOP.io_rdata);
    vlSelf->__PVT__drd = ((IData)(vlSelf->__PVT__board__DOT__d_wants_io)
                           ? vlSelf->__PVT__io_rdata_mux
                           : vlSelf->__PVT__ram_rdata);
}

VL_INLINE_OPT void Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__5(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___nba_sequent__TOP__tb_sdram__5\n"); );
    // Body
    vlSelf->dbg_cen = ((1U >= (IData)(vlSymsp->TOP.clk_div)) 
                       | (0U == (IData)(vlSelf->__PVT__cdiv)));
    vlSelf->__PVT__adapter__DOT__ack_taken = ((IData)(vlSelf->dbg_cen) 
                                              & (IData)(vlSelf->__PVT__ram_ack));
}

VL_INLINE_OPT void Vtb_sdram_tb_sdram___nba_comb__TOP__tb_sdram__1(Vtb_sdram_tb_sdram* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sdram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtb_sdram_tb_sdram___nba_comb__TOP__tb_sdram__1\n"); );
    // Init
    CData/*0:0*/ __PVT__io_ack_mux;
    __PVT__io_ack_mux = 0;
    CData/*0:0*/ __PVT__board__DOT__i_wants_io;
    __PVT__board__DOT__i_wants_io = 0;
    CData/*0:0*/ board__DOT____VdfgTmp_h56676f03__0;
    board__DOT____VdfgTmp_h56676f03__0 = 0;
    CData/*0:0*/ board__DOT____VdfgTmp_hab3cb56a__0;
    board__DOT____VdfgTmp_hab3cb56a__0 = 0;
    // Body
    vlSelf->__PVT__board__DOT__i_wants_ram = ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__imem_req) 
                                              & (0U 
                                                 == 
                                                 (0x6000000U 
                                                  & vlSelf->__PVT__board__DOT__i_dec)));
    vlSelf->board__DOT____VdfgTmp_h288a1ef5__0 = ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__imem_req) 
                                                  & (0x4000000U 
                                                     == 
                                                     (0x6000000U 
                                                      & vlSelf->__PVT__board__DOT__i_dec)));
    __PVT__board__DOT__i_wants_io = ((IData)(vlSymsp->TOP__tb_sdram__cpu.__PVT__imem_req) 
                                     & (0x2000000U 
                                        == (0x6000000U 
                                            & vlSelf->__PVT__board__DOT__i_dec)));
    vlSelf->board__DOT____VdfgTmp_h22b91ed1__0 = ((
                                                   (2U 
                                                    == (IData)(vlSelf->__PVT__board__DOT__owner)) 
                                                   | ((0U 
                                                       == (IData)(vlSelf->__PVT__board__DOT__owner)) 
                                                      & ((~ (IData)(vlSelf->__PVT__board__DOT__d_wants_ram)) 
                                                         & (IData)(vlSelf->__PVT__board__DOT__i_wants_ram)))) 
                                                  & (IData)(vlSelf->__PVT__board__DOT__i_wants_ram));
    vlSelf->board__DOT____VdfgTmp_h8306d34d__0 = ((~ (IData)(vlSelf->__PVT__board__DOT__d_wants_io)) 
                                                  & (IData)(__PVT__board__DOT__i_wants_io));
    vlSelf->io_req = ((IData)(vlSelf->__PVT__board__DOT__d_wants_io) 
                      | (IData)(__PVT__board__DOT__i_wants_io));
    vlSelf->dbg_ram_req = ((IData)(vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0) 
                           | (IData)(vlSelf->board__DOT____VdfgTmp_h22b91ed1__0));
    vlSelf->__Vcellinp__tx39__io_req = ((IData)(vlSelf->io_req) 
                                        & (IData)(vlSymsp->TOP.tx39_en));
    vlSelf->__PVT__tx39__DOT__io_start = ((IData)(vlSelf->__Vcellinp__tx39__io_req) 
                                          & ((~ (IData)(vlSelf->__PVT__tx39__DOT__served)) 
                                             & (IData)(vlSelf->dbg_cen)));
    __PVT__io_ack_mux = ((IData)(vlSymsp->TOP.tx39_en)
                          ? ((IData)(vlSelf->__Vcellinp__tx39__io_req) 
                             & (IData)(vlSelf->__PVT__tx39__DOT__served))
                          : (IData)(vlSymsp->TOP.io_ack));
    board__DOT____VdfgTmp_h56676f03__0 = ((IData)(vlSelf->board__DOT____VdfgTmp_h8306d34d__0) 
                                          & (IData)(__PVT__io_ack_mux));
    board__DOT____VdfgTmp_hab3cb56a__0 = ((IData)(vlSelf->__PVT__board__DOT__d_wants_io) 
                                          & (IData)(__PVT__io_ack_mux));
    vlSelf->__PVT__ierr = ((IData)(vlSelf->board__DOT____VdfgTmp_h288a1ef5__0) 
                           | ((IData)(board__DOT____VdfgTmp_h56676f03__0) 
                              & (IData)(vlSelf->__PVT__io_err_mux)));
    vlSelf->dbg_iack = (((IData)(vlSelf->board__DOT____VdfgTmp_h22b91ed1__0) 
                         & (IData)(vlSelf->__PVT__ram_ack)) 
                        | ((IData)(board__DOT____VdfgTmp_h56676f03__0) 
                           | (IData)(vlSelf->board__DOT____VdfgTmp_h288a1ef5__0)));
    vlSelf->__PVT__derr = ((IData)(vlSelf->board__DOT____VdfgTmp_h223955ac__0) 
                           | ((IData)(board__DOT____VdfgTmp_hab3cb56a__0) 
                              & (IData)(vlSelf->__PVT__io_err_mux)));
    vlSelf->dbg_dack = (((IData)(vlSelf->board__DOT____VdfgTmp_hdb4dbddb__0) 
                         & (IData)(vlSelf->__PVT__ram_ack)) 
                        | ((IData)(board__DOT____VdfgTmp_hab3cb56a__0) 
                           | (IData)(vlSelf->board__DOT____VdfgTmp_h223955ac__0)));
}
