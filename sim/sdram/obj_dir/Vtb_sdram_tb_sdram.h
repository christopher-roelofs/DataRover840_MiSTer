// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_sdram.h for the primary calling header

#ifndef VERILATED_VTB_SDRAM_TB_SDRAM_H_
#define VERILATED_VTB_SDRAM_TB_SDRAM_H_  // guard

#include "verilated.h"
class Vtb_sdram_r3900_cached__Cz1;
class Vtb_sdram_sdram_mt48lc16m16a2;


class Vtb_sdram__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_sdram_tb_sdram final : public VerilatedModule {
  public:
    // CELLS
    Vtb_sdram_r3900_cached__Cz1* cpu;
    Vtb_sdram_sdram_mt48lc16m16a2* chip;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(clk_div,7,0);
        VL_OUT8(io_req,0,0);
        VL_OUT8(io_we,0,0);
        VL_OUT8(io_be,3,0);
        VL_IN8(io_ack,0,0);
        VL_IN8(io_err,0,0);
        VL_IN8(irq_in,5,0);
        VL_OUT8(retire_valid,0,0);
        VL_OUT8(dbg_ram_ack,0,0);
        VL_OUT8(dbg_ram_req,0,0);
        VL_OUT8(dbg_ram_burst,0,0);
        VL_OUT8(dbg_ch2_req,0,0);
        VL_OUT8(dbg_dack,0,0);
        VL_OUT8(dbg_iack,0,0);
        VL_OUT8(dbg_dreq,0,0);
        VL_OUT8(dbg_ireq,0,0);
        VL_OUT8(dbg_start,0,0);
        VL_OUT8(dbg_start_kind,1,0);
        VL_OUT8(dbg_state,3,0);
        VL_OUT8(dbg_cen,0,0);
        VL_IN8(tx39_en,0,0);
        VL_OUT8(dbg_tx_stb,0,0);
        VL_OUT8(dbg_tx_data,7,0);
        CData/*7:0*/ __PVT__cdiv;
        CData/*0:0*/ __PVT__ierr;
        CData/*0:0*/ __PVT__derr;
        CData/*0:0*/ __PVT__ram_we;
        CData/*0:0*/ __PVT__ram_ack;
        CData/*3:0*/ __PVT__ram_be;
        CData/*0:0*/ __Vcellinp__tx39__io_req;
        CData/*0:0*/ __PVT__io_err_mux;
        CData/*0:0*/ __PVT__ch1_req;
        CData/*0:0*/ __PVT__ch1_ready;
        CData/*0:0*/ __PVT__ch2_req;
        CData/*0:0*/ __PVT__ch2_rnw;
        CData/*0:0*/ __PVT__ch2_ready;
        CData/*1:0*/ __PVT__SDRAM_BA;
        CData/*0:0*/ __PVT__ctl_dq_oe;
        CData/*1:0*/ __PVT__board__DOT__owner;
        CData/*0:0*/ __PVT__board__DOT__d_wants_ram;
        CData/*0:0*/ __PVT__board__DOT__i_wants_ram;
        CData/*0:0*/ __PVT__board__DOT__d_wants_io;
        CData/*0:0*/ board__DOT____VdfgTmp_h22b91ed1__0;
        CData/*0:0*/ board__DOT____VdfgTmp_h288a1ef5__0;
        CData/*0:0*/ board__DOT____VdfgTmp_h8306d34d__0;
        CData/*0:0*/ board__DOT____VdfgTmp_hdb4dbddb__0;
        CData/*0:0*/ board__DOT____VdfgTmp_h223955ac__0;
        CData/*0:0*/ __PVT__tx39__DOT__is_tx39;
        CData/*0:0*/ __PVT__tx39__DOT__served;
        CData/*0:0*/ __PVT__tx39__DOT__io_start;
        CData/*7:0*/ __PVT__tx39__DOT__ua_rx;
        CData/*0:0*/ __PVT__tx39__DOT__ua_rx_full;
        CData/*3:0*/ __PVT__tx39__DOT__tx_bit;
        CData/*0:0*/ __PVT__tx39__DOT__tx_busy;
        CData/*0:0*/ __PVT__tx39__DOT__tx_hold_full;
        CData/*7:0*/ __PVT__tx39__DOT__rx_shift;
        CData/*3:0*/ __PVT__tx39__DOT__rx_bit;
        CData/*0:0*/ __PVT__tx39__DOT__rx_busy;
        CData/*2:0*/ __PVT__tx39__DOT__rxd_sync;
        CData/*3:0*/ __PVT__adapter__DOT__state;
        CData/*0:0*/ __PVT__adapter__DOT__ack_taken;
        CData/*0:0*/ __PVT__adapter__DOT__ch1_done;
    };
    struct {
        CData/*0:0*/ __PVT__adapter__DOT__ch2_done;
        CData/*3:0*/ __PVT__ctl__DOT__state;
        CData/*2:0*/ __PVT__ctl__DOT__command;
        CData/*0:0*/ __PVT__ctl__DOT__chip;
        CData/*6:0*/ __PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay1;
        CData/*6:0*/ __PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay2;
        CData/*6:0*/ __PVT__ctl__DOT__unnamedblk1__DOT__data_ready_delay3;
        CData/*0:0*/ __PVT__ctl__DOT__unnamedblk1__DOT__saved_wr;
        CData/*0:0*/ __PVT__ctl__DOT__unnamedblk1__DOT__ch1_rq;
        CData/*0:0*/ __PVT__ctl__DOT__unnamedblk1__DOT__ch2_rq;
        CData/*0:0*/ __PVT__ctl__DOT__unnamedblk1__DOT__ch3_rq;
        CData/*1:0*/ __PVT__ctl__DOT__unnamedblk1__DOT__ch;
        CData/*0:0*/ __Vdly__ram_ack;
        CData/*3:0*/ __Vdly__adapter__DOT__state;
        CData/*0:0*/ __Vdly__ch1_ready;
        CData/*0:0*/ __Vdly__ch2_ready;
        CData/*3:0*/ __Vdly__ctl__DOT__state;
        CData/*0:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__saved_wr;
        CData/*1:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__ch;
        VL_OUT16(dbg_max_refresh_gap,15,0);
        VL_OUT16(dbg_violations,15,0);
        VL_OUT16(dbg_last_col,15,0);
        VL_OUT16(dbg_last_row,15,0);
        VL_OUT16(dbg_last_a,15,0);
        SData/*12:0*/ __PVT__SDRAM_A;
        SData/*15:0*/ __PVT__ctl_dq_o;
        SData/*15:0*/ __PVT__dq_bus;
        SData/*13:0*/ __PVT__ctl__DOT__refresh_count;
        SData/*12:0*/ __PVT__ctl__DOT__unnamedblk1__DOT__cas_addr;
        SData/*15:0*/ __PVT__ctl__DOT__unnamedblk1__DOT__dq_reg;
        SData/*12:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__cas_addr;
        VL_OUT(io_addr,31,0);
        VL_OUT(io_wdata,31,0);
        VL_IN(io_rdata,31,0);
        VL_OUT(retire_pc,31,0);
        VL_OUT(retire_insn,31,0);
        VL_OUT(retire_next_pc,31,0);
        VL_OUT(ihit_count,31,0);
        VL_OUT(imiss_count,31,0);
        VL_OUT(dhit_count,31,0);
        VL_OUT(dmiss_count,31,0);
        VL_OUT(dbg_reads,31,0);
        VL_OUT(dbg_writes,31,0);
        VL_OUT(dbg_refreshes,31,0);
        VL_OUT(dbg_ram_addr,24,0);
        VL_OUT(dbg_ram_rdata,31,0);
        VL_OUT(dbg_last_index,31,0);
        VL_OUT(dbg_ch2_addr,26,1);
        VL_OUT(dbg_start_addr,24,0);
        VL_OUT(dbg_tx_bytes,31,0);
        IData/*31:0*/ __PVT__ird;
        IData/*31:0*/ __PVT__drd;
        IData/*31:0*/ __PVT__ram_rdata;
        IData/*31:0*/ __PVT__t_rdata;
        IData/*31:0*/ __PVT__io_rdata_mux;
        IData/*25:0*/ __PVT__ch1_addr;
        IData/*25:0*/ __PVT__ch2_addr;
        IData/*31:0*/ __PVT__ch2_dout;
        IData/*31:0*/ __PVT__ch2_din;
        IData/*26:0*/ __PVT__board__DOT__i_dec;
        IData/*31:0*/ __PVT__tx39__DOT__ua_ctrl1;
        IData/*31:0*/ __PVT__tx39__DOT__ua_ctrl2;
        IData/*19:0*/ __PVT__tx39__DOT__tx_cnt;
        IData/*19:0*/ __PVT__tx39__DOT__rx_cnt;
    };
    struct {
        IData/*31:0*/ tx39__DOT____Vlvbound_h2237671c__0;
        IData/*31:0*/ tx39__DOT____Vlvbound_hadcbb189__0;
        IData/*31:0*/ __PVT__adapter__DOT__hold;
        IData/*24:0*/ __PVT__adapter__DOT__line;
        IData/*31:0*/ __PVT__adapter__DOT__merged;
        IData/*31:0*/ __PVT__ctl__DOT__unnamedblk1__DOT__saved_data;
        IData/*31:0*/ __Vdly__ch2_dout;
        IData/*31:0*/ __Vdly__ctl__DOT__unnamedblk1__DOT__saved_data;
        QData/*63:0*/ __PVT__ch1_dout;
        QData/*63:0*/ __Vdly__ch1_dout;
        VlUnpacked<IData/*31:0*/, 256> __PVT__tx39__DOT__rf;
        VlUnpacked<IData/*31:0*/, 6> __PVT__tx39__DOT__icu_status;
        VlUnpacked<IData/*31:0*/, 6> __PVT__tx39__DOT__icu_enable;
    };

    // INTERNAL VARIABLES
    Vtb_sdram__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_sdram_tb_sdram(Vtb_sdram__Syms* symsp, const char* v__name);
    ~Vtb_sdram_tb_sdram();
    VL_UNCOPYABLE(Vtb_sdram_tb_sdram);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
