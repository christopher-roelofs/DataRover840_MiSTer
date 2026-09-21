// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTB_SDRAM_H_
#define VERILATED_VTB_SDRAM_H_  // guard

#include "verilated.h"
#include "svdpi.h"

class Vtb_sdram__Syms;
class Vtb_sdram___024root;
class Vtb_sdram_tb_sdram;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vtb_sdram VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vtb_sdram__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk,0,0);
    VL_IN8(&rst_n,0,0);
    VL_OUT8(&io_req,0,0);
    VL_OUT8(&io_we,0,0);
    VL_OUT8(&io_be,3,0);
    VL_IN8(&io_ack,0,0);
    VL_IN8(&io_err,0,0);
    VL_IN8(&irq_in,5,0);
    VL_OUT8(&retire_valid,0,0);
    VL_OUT8(&dbg_ram_ack,0,0);
    VL_OUT8(&dbg_ram_req,0,0);
    VL_OUT8(&dbg_ram_burst,0,0);
    VL_OUT8(&dbg_ch2_req,0,0);
    VL_OUT8(&dbg_dack,0,0);
    VL_OUT8(&dbg_iack,0,0);
    VL_OUT8(&dbg_dreq,0,0);
    VL_OUT8(&dbg_ireq,0,0);
    VL_OUT16(&dbg_max_refresh_gap,15,0);
    VL_OUT16(&dbg_violations,15,0);
    VL_OUT16(&dbg_last_col,15,0);
    VL_OUT16(&dbg_last_row,15,0);
    VL_OUT16(&dbg_last_a,15,0);
    VL_OUT(&io_addr,31,0);
    VL_OUT(&io_wdata,31,0);
    VL_IN(&io_rdata,31,0);
    VL_OUT(&retire_pc,31,0);
    VL_OUT(&retire_insn,31,0);
    VL_OUT(&retire_next_pc,31,0);
    VL_OUT(&ihit_count,31,0);
    VL_OUT(&imiss_count,31,0);
    VL_OUT(&dhit_count,31,0);
    VL_OUT(&dmiss_count,31,0);
    VL_OUT(&dbg_reads,31,0);
    VL_OUT(&dbg_writes,31,0);
    VL_OUT(&dbg_refreshes,31,0);
    VL_OUT(&dbg_ram_addr,24,0);
    VL_OUT(&dbg_ram_rdata,31,0);
    VL_OUT(&dbg_last_index,31,0);
    VL_OUT(&dbg_ch2_addr,26,1);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vtb_sdram_tb_sdram* const tb_sdram;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtb_sdram___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vtb_sdram(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vtb_sdram(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vtb_sdram();
  private:
    VL_UNCOPYABLE(Vtb_sdram);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
};

#endif  // guard
