// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdr840_pclink.h for the primary calling header

#ifndef VERILATED_VDR840_PCLINK___024ROOT_H_
#define VERILATED_VDR840_PCLINK___024ROOT_H_  // guard

#include "verilated.h"


class Vdr840_pclink__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdr840_pclink___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(cen,0,0);
        VL_IN8(go_tog,0,0);
        VL_IN8(wr_req,0,0);
        VL_OUT8(wr_ack,0,0);
        VL_OUT8(pmem_req,0,0);
        VL_OUT8(pmem_we,0,0);
        VL_IN8(pmem_ack,0,0);
        VL_IN8(gtx_tog,0,0);
        VL_IN8(gtx_data,7,0);
        VL_OUT8(grx_tog,0,0);
        VL_OUT8(grx_data,7,0);
        VL_IN8(grx_full,0,0);
        VL_IN8(uart_on,0,0);
        VL_OUT8(state,2,0);
        CData/*0:0*/ dr840_pclink__DOT__gtx_q;
        CData/*0:0*/ dr840_pclink__DOT__rx_v;
        CData/*0:0*/ dr840_pclink__DOT__greeted;
        CData/*2:0*/ dr840_pclink__DOT__rx_st;
        CData/*0:0*/ dr840_pclink__DOT__escaped;
        CData/*2:0*/ dr840_pclink__DOT__cmd_idx;
        CData/*0:0*/ dr840_pclink__DOT__cmd_skip;
        CData/*0:0*/ dr840_pclink__DOT__offered;
        CData/*3:0*/ dr840_pclink__DOT__pong_pend;
        CData/*0:0*/ dr840_pclink__DOT__feed_v;
        CData/*0:0*/ dr840_pclink__DOT__dispatch;
        CData/*3:0*/ dr840_pclink__DOT__tx_st;
        CData/*2:0*/ dr840_pclink__DOT__mk;
        CData/*2:0*/ dr840_pclink__DOT__seq;
        CData/*0:0*/ dr840_pclink__DOT__q_pend;
        CData/*7:0*/ dr840_pclink__DOT__blk_q;
        CData/*0:0*/ dr840_pclink__DOT__fill_we;
        CData/*7:0*/ dr840_pclink__DOT__fill_b;
        CData/*7:0*/ dr840_pclink__DOT__fill_at;
        CData/*0:0*/ dr840_pclink__DOT__word_ok;
        CData/*0:0*/ dr840_pclink__DOT__reading;
        CData/*7:0*/ dr840_pclink__DOT__sb;
        CData/*0:0*/ dr840_pclink__DOT__have_word;
        CData/*0:0*/ dr840_pclink__DOT__can_send;
        CData/*0:0*/ dr840_pclink__DOT__next_seq;
        CData/*2:0*/ dr840_pclink__DOT__seq_kind;
        CData/*0:0*/ dr840_pclink__DOT__go_q;
        CData/*7:0*/ __Vdlyvdim0__dr840_pclink__DOT__blk__v0;
        CData/*7:0*/ __Vdlyvval__dr840_pclink__DOT__blk__v0;
        CData/*0:0*/ __Vdlyvset__dr840_pclink__DOT__blk__v0;
        CData/*0:0*/ __Vdly__dr840_pclink__DOT__reading;
        CData/*0:0*/ __Vdly__wr_ack;
        CData/*2:0*/ __Vdly__dr840_pclink__DOT__rx_st;
        CData/*2:0*/ __Vdly__dr840_pclink__DOT__cmd_idx;
        CData/*0:0*/ __Vdly__dr840_pclink__DOT__offered;
        CData/*2:0*/ __Vdly__state;
        CData/*2:0*/ __Vdly__dr840_pclink__DOT__seq;
        CData/*3:0*/ __Vdly__dr840_pclink__DOT__pong_pend;
        CData/*3:0*/ __Vdly__dr840_pclink__DOT__tx_st;
        CData/*0:0*/ __Vdly__grx_tog;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ dr840_pclink__DOT__rx_rem;
        SData/*8:0*/ dr840_pclink__DOT__at;
        SData/*8:0*/ dr840_pclink__DOT__ridx;
    };
    struct {
        SData/*15:0*/ dr840_pclink__DOT__idle_cnt;
        SData/*15:0*/ __Vdly__dr840_pclink__DOT__rx_rem;
        SData/*8:0*/ __Vdly__dr840_pclink__DOT__at;
        SData/*8:0*/ __Vdly__dr840_pclink__DOT__ridx;
        SData/*15:0*/ __Vdly__dr840_pclink__DOT__idle_cnt;
        VL_IN(pkg_len,24,0);
        VL_IN(wr_addr,24,0);
        VL_IN(wr_data,31,0);
        VL_OUT(pmem_addr,24,0);
        VL_OUT(pmem_wdata,31,0);
        VL_IN(pmem_rdata,31,0);
        VL_IN(bit_clocks,19,0);
        VL_OUT(sent,24,0);
        IData/*31:0*/ dr840_pclink__DOT__crc8__Vstatic__x;
        IData/*22:0*/ dr840_pclink__DOT__frame_cen;
        IData/*22:0*/ dr840_pclink__DOT__pace;
        IData/*31:0*/ dr840_pclink__DOT__gshift;
        IData/*31:0*/ dr840_pclink__DOT__cmd_tag;
        IData/*31:0*/ dr840_pclink__DOT__cmd_rem;
        IData/*31:0*/ dr840_pclink__DOT__cmd_len_now;
        IData/*24:0*/ dr840_pclink__DOT__msg_len;
        IData/*24:0*/ dr840_pclink__DOT__mi;
        IData/*31:0*/ dr840_pclink__DOT__crc;
        IData/*31:0*/ dr840_pclink__DOT__word;
        IData/*22:0*/ dr840_pclink__DOT__word_addr;
        IData/*24:0*/ dr840_pclink__DOT__kind_len;
        IData/*22:0*/ __Vdly__dr840_pclink__DOT__pace;
        IData/*31:0*/ __Vdly__dr840_pclink__DOT__gshift;
        IData/*31:0*/ __Vdly__dr840_pclink__DOT__cmd_rem;
        IData/*31:0*/ __Vdly__dr840_pclink__DOT__cmd_tag;
        IData/*31:0*/ __Vdly__dr840_pclink__DOT__crc;
        IData/*24:0*/ __Vdly__dr840_pclink__DOT__mi;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*7:0*/, 256> dr840_pclink__DOT__blk;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdr840_pclink__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdr840_pclink___024root(Vdr840_pclink__Syms* symsp, const char* v__name);
    ~Vdr840_pclink___024root();
    VL_UNCOPYABLE(Vdr840_pclink___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
