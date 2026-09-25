// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdr840_ne2000.h for the primary calling header

#ifndef VERILATED_VDR840_NE2000___024ROOT_H_
#define VERILATED_VDR840_NE2000___024ROOT_H_  // guard

#include "verilated.h"


class Vdr840_ne2000__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdr840_ne2000___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(cen,0,0);
        VL_IN8(acc,0,0);
        VL_IN8(we,0,0);
        VL_IN8(port,4,0);
        VL_IN8(wide,0,0);
        VL_IN8(board_reset,0,0);
        VL_OUT8(irq,0,0);
        VL_OUT8(tx_req,0,0);
        VL_IN8(tx_done,0,0);
        VL_IN8(tx_ok,0,0);
        VL_IN8(rx_offer,0,0);
        VL_OUT8(rx_answer,0,0);
        VL_OUT8(rx_take,0,0);
        VL_IN8(rx_byte,0,0);
        VL_IN8(rx_data,7,0);
        VL_OUT8(rx_busy,0,0);
        VL_OUT8(b_q,7,0);
        CData/*7:0*/ dr840_ne2000__DOT__cr;
        CData/*7:0*/ dr840_ne2000__DOT__isr;
        CData/*7:0*/ dr840_ne2000__DOT__imr;
        CData/*7:0*/ dr840_ne2000__DOT__dcr;
        CData/*7:0*/ dr840_ne2000__DOT__rcr;
        CData/*7:0*/ dr840_ne2000__DOT__tcr;
        CData/*7:0*/ dr840_ne2000__DOT__tsr;
        CData/*7:0*/ dr840_ne2000__DOT__rsr;
        CData/*7:0*/ dr840_ne2000__DOT__pstart;
        CData/*7:0*/ dr840_ne2000__DOT__pstop;
        CData/*7:0*/ dr840_ne2000__DOT__bnry;
        CData/*7:0*/ dr840_ne2000__DOT__curr;
        CData/*7:0*/ dr840_ne2000__DOT__tpsr;
        CData/*0:0*/ dr840_ne2000__DOT__tx_pending;
        CData/*7:0*/ dr840_ne2000__DOT__qa_e;
        CData/*7:0*/ dr840_ne2000__DOT__qa_o;
        CData/*0:0*/ dr840_ne2000__DOT__wa_e;
        CData/*0:0*/ dr840_ne2000__DOT__wa_o;
        CData/*7:0*/ dr840_ne2000__DOT__wa_e_d;
        CData/*7:0*/ dr840_ne2000__DOT__wa_o_d;
        CData/*0:0*/ dr840_ne2000__DOT__wb;
        CData/*7:0*/ dr840_ne2000__DOT__wb_d;
        CData/*7:0*/ dr840_ne2000__DOT__qb_e;
        CData/*7:0*/ dr840_ne2000__DOT__qb_o;
        CData/*0:0*/ dr840_ne2000__DOT__b_lsb;
        CData/*7:0*/ dr840_ne2000__DOT__b0;
        CData/*7:0*/ dr840_ne2000__DOT__b1;
        CData/*0:0*/ dr840_ne2000__DOT__dma_rd_ok;
        CData/*0:0*/ dr840_ne2000__DOT__dma_wr_ok;
        CData/*0:0*/ dr840_ne2000__DOT__off_q;
        CData/*0:0*/ dr840_ne2000__DOT__o_acc;
        CData/*0:0*/ dr840_ne2000__DOT__o_ring_ok;
        CData/*0:0*/ dr840_ne2000__DOT__o_bnry_in;
        CData/*7:0*/ dr840_ne2000__DOT__o_next;
        CData/*2:0*/ dr840_ne2000__DOT__r_st;
        CData/*7:0*/ dr840_ne2000__DOT__r_next;
        CData/*7:0*/ dr840_ne2000__DOT__r_page;
        CData/*0:0*/ dr840_ne2000__DOT__r_group;
        CData/*1:0*/ dr840_ne2000__DOT__r_k;
        CData/*0:0*/ dr840_ne2000__DOT__tx_copied;
        CData/*0:0*/ dr840_ne2000__DOT__tx_copied_ok;
        CData/*7:0*/ dr840_ne2000__DOT__v;
        CData/*0:0*/ dr840_ne2000__DOT__started;
        CData/*7:0*/ dr840_ne2000__DOT__iset;
        CData/*7:0*/ dr840_ne2000__DOT__iclr;
    };
    struct {
        CData/*0:0*/ dr840_ne2000__DOT__nreset;
        CData/*7:0*/ dr840_ne2000__DOT____Vlvbound_h66bf5d70__0;
        CData/*7:0*/ dr840_ne2000__DOT____Vlvbound_h9fb8493e__0;
        CData/*7:0*/ __Vfunc_dr840_ne2000__DOT__prom__1__Vfuncout;
        CData/*4:0*/ __Vfunc_dr840_ne2000__DOT__prom__1__a;
        CData/*7:0*/ __Vfunc_dr840_ne2000__DOT__prom__3__Vfuncout;
        CData/*4:0*/ __Vfunc_dr840_ne2000__DOT__prom__3__a;
        CData/*0:0*/ __Vdlyvset__dr840_ne2000__DOT__tally__v0;
        CData/*7:0*/ __Vdly__dr840_ne2000__DOT__cr;
        CData/*0:0*/ __Vdly__dr840_ne2000__DOT__tx_pending;
        CData/*0:0*/ __Vdly__tx_req;
        CData/*0:0*/ __Vdly__dr840_ne2000__DOT__tx_copied;
        CData/*7:0*/ __Vdly__dr840_ne2000__DOT__rcr;
        CData/*0:0*/ __Vdlyvset__dr840_ne2000__DOT__par__v0;
        CData/*7:0*/ __Vdly__dr840_ne2000__DOT__curr;
        CData/*0:0*/ __Vdlyvset__dr840_ne2000__DOT__mar__v0;
        CData/*0:0*/ __Vdly__dr840_ne2000__DOT__tx_copied_ok;
        CData/*0:0*/ __Vdly__dr840_ne2000__DOT__off_q;
        CData/*0:0*/ __Vdlyvset__dr840_ne2000__DOT__tally__v1;
        CData/*0:0*/ __Vdlyvset__dr840_ne2000__DOT__tally__v2;
        CData/*2:0*/ __Vdly__dr840_ne2000__DOT__r_st;
        CData/*7:0*/ __Vdly__dr840_ne2000__DOT__r_next;
        CData/*7:0*/ __Vdly__dr840_ne2000__DOT__r_page;
        CData/*0:0*/ __Vdly__dr840_ne2000__DOT__r_group;
        CData/*1:0*/ __Vdly__dr840_ne2000__DOT__r_k;
        CData/*0:0*/ __Vdlyvset__dr840_ne2000__DOT__tally__v3;
        CData/*0:0*/ __Vdlyvset__dr840_ne2000__DOT__tally__v6;
        CData/*0:0*/ __Vdlyvset__dr840_ne2000__DOT__par__v1;
        CData/*0:0*/ __Vdlyvset__dr840_ne2000__DOT__par__v2;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __VactContinue;
        VL_IN16(wdata,15,0);
        VL_OUT16(rdata,15,0);
        VL_OUT16(tx_base,13,0);
        VL_OUT16(tx_len,10,0);
        VL_IN16(rx_len,10,0);
        VL_IN16(b_addr,13,0);
        SData/*15:0*/ dr840_ne2000__DOT__rsar;
        SData/*15:0*/ dr840_ne2000__DOT__rbcr;
        SData/*15:0*/ dr840_ne2000__DOT__tbcr;
        SData/*15:0*/ dr840_ne2000__DOT__rsar_n;
        SData/*12:0*/ dr840_ne2000__DOT__wa_e_i;
        SData/*12:0*/ dr840_ne2000__DOT__wa_o_i;
        SData/*13:0*/ dr840_ne2000__DOT__wb_a;
        SData/*13:0*/ dr840_ne2000__DOT__pb_a;
        SData/*12:0*/ dr840_ne2000__DOT__pa_e;
        SData/*12:0*/ dr840_ne2000__DOT__pa_o;
        SData/*10:0*/ dr840_ne2000__DOT__off_len;
        SData/*10:0*/ dr840_ne2000__DOT__o_pad;
        SData/*8:0*/ dr840_ne2000__DOT__o_avail;
        SData/*15:0*/ dr840_ne2000__DOT__r_ptr;
        SData/*10:0*/ dr840_ne2000__DOT__r_n;
        SData/*10:0*/ dr840_ne2000__DOT__r_len;
        SData/*10:0*/ dr840_ne2000__DOT__r_pad;
        SData/*11:0*/ dr840_ne2000__DOT__r_cnt;
        SData/*15:0*/ dr840_ne2000__DOT__r_ptr_n;
        SData/*15:0*/ dr840_ne2000__DOT__tx_wait;
        SData/*15:0*/ __Vdly__dr840_ne2000__DOT__rbcr;
        SData/*15:0*/ __Vdly__dr840_ne2000__DOT__tx_wait;
        SData/*10:0*/ __Vdly__dr840_ne2000__DOT__r_len;
        SData/*10:0*/ __Vdly__dr840_ne2000__DOT__r_n;
    };
    struct {
        SData/*10:0*/ __Vdly__dr840_ne2000__DOT__r_pad;
        SData/*11:0*/ __Vdly__dr840_ne2000__DOT__r_cnt;
        SData/*15:0*/ __Vdly__dr840_ne2000__DOT__r_ptr;
        VL_OUT(dbg_tx,31,0);
        VL_OUT(dbg_rx,31,0);
        IData/*31:0*/ dr840_ne2000__DOT__crc8__Vstatic__x;
        IData/*31:0*/ dr840_ne2000__DOT__r_crc;
        IData/*31:0*/ __Vdly__dr840_ne2000__DOT__r_crc;
        IData/*31:0*/ __VactIterCount;
        VL_IN64(rx_dst,47,0);
        QData/*47:0*/ dr840_ne2000__DOT__off_dst;
        VlUnpacked<CData/*7:0*/, 6> dr840_ne2000__DOT__par;
        VlUnpacked<CData/*7:0*/, 8> dr840_ne2000__DOT__mar;
        VlUnpacked<CData/*7:0*/, 3> dr840_ne2000__DOT__tally;
        VlUnpacked<CData/*7:0*/, 8192> dr840_ne2000__DOT__ram_e;
        VlUnpacked<CData/*7:0*/, 8192> dr840_ne2000__DOT__ram_o;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdr840_ne2000__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdr840_ne2000___024root(Vdr840_ne2000__Syms* symsp, const char* v__name);
    ~Vdr840_ne2000___024root();
    VL_UNCOPYABLE(Vdr840_ne2000___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
