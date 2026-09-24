// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VDR840_PCLINK_H_
#define VERILATED_VDR840_PCLINK_H_  // guard

#include "verilated.h"

class Vdr840_pclink__Syms;
class Vdr840_pclink___024root;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vdr840_pclink VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vdr840_pclink__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk,0,0);
    VL_IN8(&rst_n,0,0);
    VL_IN8(&cen,0,0);
    VL_IN8(&go_tog,0,0);
    VL_IN8(&wr_req,0,0);
    VL_OUT8(&wr_ack,0,0);
    VL_OUT8(&pmem_req,0,0);
    VL_OUT8(&pmem_we,0,0);
    VL_IN8(&pmem_ack,0,0);
    VL_IN8(&gtx_tog,0,0);
    VL_IN8(&gtx_data,7,0);
    VL_OUT8(&grx_tog,0,0);
    VL_OUT8(&grx_data,7,0);
    VL_IN8(&grx_full,0,0);
    VL_IN8(&uart_on,0,0);
    VL_OUT8(&state,2,0);
    VL_IN(&pkg_len,24,0);
    VL_IN(&wr_addr,24,0);
    VL_IN(&wr_data,31,0);
    VL_OUT(&pmem_addr,24,0);
    VL_OUT(&pmem_wdata,31,0);
    VL_IN(&pmem_rdata,31,0);
    VL_IN(&bit_clocks,19,0);
    VL_OUT(&sent,24,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vdr840_pclink___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vdr840_pclink(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vdr840_pclink(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vdr840_pclink();
  private:
    VL_UNCOPYABLE(Vdr840_pclink);  ///< Copying not allowed

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
