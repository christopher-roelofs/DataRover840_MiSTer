// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_net.h for the primary calling header

#ifndef VERILATED_VTB_NET___024ROOT_H_
#define VERILATED_VTB_NET___024ROOT_H_  // guard

#include "verilated.h"


class Vtb_net__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_net___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(enable,0,0);
        VL_IN8(acc,0,0);
        VL_IN8(we,0,0);
        VL_IN8(wide,0,0);
        VL_IN8(port,4,0);
        VL_OUT8(irq,0,0);
        VL_IN8(ddr_busy,0,0);
        VL_OUT8(ddr_rd,0,0);
        VL_OUT8(ddr_we,0,0);
        VL_IN8(ddr_dout_ready,0,0);
        VL_OUT8(link,0,0);
        VL_OUT8(cen_o,0,0);
        CData/*0:0*/ tb_net__DOT__cen;
        CData/*0:0*/ tb_net__DOT__tx_req;
        CData/*0:0*/ tb_net__DOT__tx_done;
        CData/*0:0*/ tb_net__DOT__tx_ok;
        CData/*0:0*/ tb_net__DOT__rx_offer;
        CData/*0:0*/ tb_net__DOT__rx_answer;
        CData/*0:0*/ tb_net__DOT__rx_take;
        CData/*0:0*/ tb_net__DOT__rx_byte;
        CData/*0:0*/ tb_net__DOT__rx_busy;
        CData/*7:0*/ tb_net__DOT__rx_data;
        CData/*0:0*/ tb_net__DOT____Vcellinp__nic__acc;
        CData/*7:0*/ tb_net__DOT__nic__DOT__cr;
        CData/*7:0*/ tb_net__DOT__nic__DOT__isr;
        CData/*7:0*/ tb_net__DOT__nic__DOT__imr;
        CData/*7:0*/ tb_net__DOT__nic__DOT__dcr;
        CData/*7:0*/ tb_net__DOT__nic__DOT__rcr;
        CData/*7:0*/ tb_net__DOT__nic__DOT__tcr;
        CData/*7:0*/ tb_net__DOT__nic__DOT__tsr;
        CData/*7:0*/ tb_net__DOT__nic__DOT__rsr;
        CData/*7:0*/ tb_net__DOT__nic__DOT__pstart;
        CData/*7:0*/ tb_net__DOT__nic__DOT__pstop;
        CData/*7:0*/ tb_net__DOT__nic__DOT__bnry;
        CData/*7:0*/ tb_net__DOT__nic__DOT__curr;
        CData/*7:0*/ tb_net__DOT__nic__DOT__tpsr;
        CData/*0:0*/ tb_net__DOT__nic__DOT__tx_pending;
        CData/*7:0*/ tb_net__DOT__nic__DOT__qa_e;
        CData/*7:0*/ tb_net__DOT__nic__DOT__qa_o;
        CData/*0:0*/ tb_net__DOT__nic__DOT__wa_e;
        CData/*0:0*/ tb_net__DOT__nic__DOT__wa_o;
        CData/*7:0*/ tb_net__DOT__nic__DOT__wa_e_d;
        CData/*7:0*/ tb_net__DOT__nic__DOT__wa_o_d;
        CData/*0:0*/ tb_net__DOT__nic__DOT__wb;
        CData/*7:0*/ tb_net__DOT__nic__DOT__wb_d;
        CData/*7:0*/ tb_net__DOT__nic__DOT__qb_e;
        CData/*7:0*/ tb_net__DOT__nic__DOT__qb_o;
        CData/*0:0*/ tb_net__DOT__nic__DOT__b_lsb;
        CData/*7:0*/ tb_net__DOT__nic__DOT__b0;
        CData/*7:0*/ tb_net__DOT__nic__DOT__b1;
        CData/*0:0*/ tb_net__DOT__nic__DOT__dma_rd_ok;
        CData/*0:0*/ tb_net__DOT__nic__DOT__dma_wr_ok;
        CData/*0:0*/ tb_net__DOT__nic__DOT__off_q;
        CData/*0:0*/ tb_net__DOT__nic__DOT__o_acc;
        CData/*0:0*/ tb_net__DOT__nic__DOT__o_ring_ok;
        CData/*0:0*/ tb_net__DOT__nic__DOT__o_bnry_in;
        CData/*7:0*/ tb_net__DOT__nic__DOT__o_next;
        CData/*2:0*/ tb_net__DOT__nic__DOT__r_st;
        CData/*7:0*/ tb_net__DOT__nic__DOT__r_next;
        CData/*7:0*/ tb_net__DOT__nic__DOT__r_page;
        CData/*0:0*/ tb_net__DOT__nic__DOT__r_group;
        CData/*1:0*/ tb_net__DOT__nic__DOT__r_k;
    };
    struct {
        CData/*0:0*/ tb_net__DOT__nic__DOT__tx_copied;
        CData/*0:0*/ tb_net__DOT__nic__DOT__tx_copied_ok;
        CData/*7:0*/ tb_net__DOT__nic__DOT__v;
        CData/*0:0*/ tb_net__DOT__nic__DOT__started;
        CData/*7:0*/ tb_net__DOT__nic__DOT__iset;
        CData/*7:0*/ tb_net__DOT__nic__DOT__iclr;
        CData/*0:0*/ tb_net__DOT__nic__DOT__nreset;
        CData/*7:0*/ tb_net__DOT__nic__DOT____Vlvbound_h66bf5d70__0;
        CData/*7:0*/ tb_net__DOT__nic__DOT____Vlvbound_h9fb8493e__0;
        CData/*4:0*/ tb_net__DOT__br__DOT__st;
        CData/*4:0*/ tb_net__DOT__br__DOT__ret;
        CData/*1:0*/ tb_net__DOT__br__DOT__bw;
        CData/*2:0*/ tb_net__DOT__br__DOT__lanes;
        CData/*0:0*/ tb_net__DOT__br__DOT__pulse_wait;
        CData/*7:0*/ __Vfunc_tb_net__DOT__nic__DOT__prom__1__Vfuncout;
        CData/*4:0*/ __Vfunc_tb_net__DOT__nic__DOT__prom__1__a;
        CData/*7:0*/ __Vfunc_tb_net__DOT__nic__DOT__prom__3__Vfuncout;
        CData/*4:0*/ __Vfunc_tb_net__DOT__nic__DOT__prom__3__a;
        CData/*0:0*/ __Vdly__tb_net__DOT__cen;
        CData/*0:0*/ __Vdlyvset__tb_net__DOT__nic__DOT__tally__v0;
        CData/*7:0*/ __Vdly__tb_net__DOT__nic__DOT__cr;
        CData/*0:0*/ __Vdly__tb_net__DOT__nic__DOT__tx_pending;
        CData/*0:0*/ __Vdly__tb_net__DOT__tx_req;
        CData/*0:0*/ __Vdly__tb_net__DOT__nic__DOT__tx_copied;
        CData/*7:0*/ __Vdly__tb_net__DOT__nic__DOT__rcr;
        CData/*0:0*/ __Vdlyvset__tb_net__DOT__nic__DOT__par__v0;
        CData/*7:0*/ __Vdly__tb_net__DOT__nic__DOT__curr;
        CData/*0:0*/ __Vdlyvset__tb_net__DOT__nic__DOT__mar__v0;
        CData/*0:0*/ __Vdly__tb_net__DOT__nic__DOT__tx_copied_ok;
        CData/*0:0*/ __Vdly__tb_net__DOT__nic__DOT__off_q;
        CData/*0:0*/ __Vdlyvset__tb_net__DOT__nic__DOT__tally__v1;
        CData/*0:0*/ __Vdlyvset__tb_net__DOT__nic__DOT__tally__v2;
        CData/*2:0*/ __Vdly__tb_net__DOT__nic__DOT__r_st;
        CData/*7:0*/ __Vdly__tb_net__DOT__nic__DOT__r_next;
        CData/*7:0*/ __Vdly__tb_net__DOT__nic__DOT__r_page;
        CData/*0:0*/ __Vdly__tb_net__DOT__nic__DOT__r_group;
        CData/*1:0*/ __Vdly__tb_net__DOT__nic__DOT__r_k;
        CData/*0:0*/ __Vdlyvset__tb_net__DOT__nic__DOT__tally__v3;
        CData/*0:0*/ __Vdlyvset__tb_net__DOT__nic__DOT__tally__v6;
        CData/*0:0*/ __Vdlyvset__tb_net__DOT__nic__DOT__par__v1;
        CData/*0:0*/ __Vdlyvset__tb_net__DOT__nic__DOT__par__v2;
        CData/*0:0*/ __Vdly__tb_net__DOT__tx_done;
        CData/*0:0*/ __Vdly__tb_net__DOT__rx_offer;
        CData/*0:0*/ __Vdly__tb_net__DOT__rx_byte;
        CData/*7:0*/ __Vdly__tb_net__DOT__rx_data;
        CData/*0:0*/ __Vdly__tb_net__DOT__tx_ok;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __VactContinue;
        VL_IN16(wdata,15,0);
        VL_OUT16(rdata,15,0);
        SData/*13:0*/ tb_net__DOT__tx_base;
        SData/*13:0*/ tb_net__DOT__b_addr;
        SData/*10:0*/ tb_net__DOT__tx_len;
        SData/*10:0*/ tb_net__DOT__rx_len;
        SData/*15:0*/ tb_net__DOT__nic__DOT__rsar;
        SData/*15:0*/ tb_net__DOT__nic__DOT__rbcr;
        SData/*15:0*/ tb_net__DOT__nic__DOT__tbcr;
        SData/*15:0*/ tb_net__DOT__nic__DOT__rsar_n;
        SData/*12:0*/ tb_net__DOT__nic__DOT__wa_e_i;
        SData/*12:0*/ tb_net__DOT__nic__DOT__wa_o_i;
        SData/*13:0*/ tb_net__DOT__nic__DOT__wb_a;
    };
    struct {
        SData/*13:0*/ tb_net__DOT__nic__DOT__pb_a;
        SData/*12:0*/ tb_net__DOT__nic__DOT__pa_e;
        SData/*12:0*/ tb_net__DOT__nic__DOT__pa_o;
        SData/*10:0*/ tb_net__DOT__nic__DOT__off_len;
        SData/*10:0*/ tb_net__DOT__nic__DOT__o_pad;
        SData/*8:0*/ tb_net__DOT__nic__DOT__o_avail;
        SData/*15:0*/ tb_net__DOT__nic__DOT__r_ptr;
        SData/*10:0*/ tb_net__DOT__nic__DOT__r_n;
        SData/*10:0*/ tb_net__DOT__nic__DOT__r_len;
        SData/*10:0*/ tb_net__DOT__nic__DOT__r_pad;
        SData/*11:0*/ tb_net__DOT__nic__DOT__r_cnt;
        SData/*15:0*/ tb_net__DOT__nic__DOT__r_ptr_n;
        SData/*15:0*/ tb_net__DOT__nic__DOT__tx_wait;
        SData/*10:0*/ tb_net__DOT__br__DOT__n;
        SData/*15:0*/ __Vdly__tb_net__DOT__nic__DOT__rbcr;
        SData/*15:0*/ __Vdly__tb_net__DOT__nic__DOT__tx_wait;
        SData/*10:0*/ __Vdly__tb_net__DOT__nic__DOT__r_len;
        SData/*10:0*/ __Vdly__tb_net__DOT__nic__DOT__r_n;
        SData/*10:0*/ __Vdly__tb_net__DOT__nic__DOT__r_pad;
        SData/*11:0*/ __Vdly__tb_net__DOT__nic__DOT__r_cnt;
        SData/*15:0*/ __Vdly__tb_net__DOT__nic__DOT__r_ptr;
        SData/*10:0*/ __Vdly__tb_net__DOT__rx_len;
        VL_OUT(ddr_addr,28,0);
        VL_OUT(frames_tx,31,0);
        VL_OUT(frames_rx,31,0);
        IData/*31:0*/ tb_net__DOT__nic__DOT__dbg_tx;
        IData/*31:0*/ tb_net__DOT__nic__DOT__dbg_rx;
        IData/*31:0*/ tb_net__DOT__nic__DOT__crc8__Vstatic__x;
        IData/*31:0*/ tb_net__DOT__nic__DOT__r_crc;
        IData/*31:0*/ tb_net__DOT__br__DOT__tx_head;
        IData/*31:0*/ tb_net__DOT__br__DOT__tx_tail;
        IData/*31:0*/ tb_net__DOT__br__DOT__rx_head;
        IData/*31:0*/ tb_net__DOT__br__DOT__rx_tail;
        IData/*19:0*/ tb_net__DOT__br__DOT__poll_cnt;
        IData/*31:0*/ __Vdly__tb_net__DOT__nic__DOT__r_crc;
        IData/*31:0*/ __VactIterCount;
        VL_OUT64(ddr_din,63,0);
        VL_IN64(ddr_dout,63,0);
        QData/*47:0*/ tb_net__DOT__rx_dst;
        QData/*47:0*/ tb_net__DOT__nic__DOT__off_dst;
        QData/*63:0*/ tb_net__DOT__br__DOT__acc;
        QData/*47:0*/ __Vdly__tb_net__DOT__rx_dst;
        VlUnpacked<CData/*7:0*/, 6> tb_net__DOT__nic__DOT__par;
        VlUnpacked<CData/*7:0*/, 8> tb_net__DOT__nic__DOT__mar;
        VlUnpacked<CData/*7:0*/, 3> tb_net__DOT__nic__DOT__tally;
        VlUnpacked<CData/*7:0*/, 8192> tb_net__DOT__nic__DOT__ram_e;
        VlUnpacked<CData/*7:0*/, 8192> tb_net__DOT__nic__DOT__ram_o;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_net__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_net___024root(Vtb_net__Syms* symsp, const char* v__name);
    ~Vtb_net___024root();
    VL_UNCOPYABLE(Vtb_net___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
