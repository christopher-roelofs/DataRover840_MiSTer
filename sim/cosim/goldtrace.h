//
// goldtrace.h - layout of the reference traces this core is validated against.
//
// Both files are written by magicrecomp's --trace-state and --trace-bus.
// They are fixed-size little-endian records behind a 16-byte header, because
// a useful run is millions of instructions long and text would not fit.
//
#pragma once
#include <stdint.h>

#define TRACE_STATE_MAGIC 0x54435254u  // "TRCT"
#define BUS_TRACE_MAGIC   0x53554254u  // "TBUS"

struct trace_hdr {
    uint32_t magic;
    uint32_t version;
    uint32_t record_size;
    uint32_t reserved;
};

// One per retired instruction, holding the state it produced.
struct state_rec {
    uint32_t pc;        // the instruction's own address
    uint32_t insn;      // its encoding
    uint32_t next_pc;   // the address two instructions ahead, branches applied
    uint32_t hi, lo;
    uint32_t r[31];     // r1..r31; r0 is not recorded because it is always 0
};

// One per data-bus access, in program order.
struct bus_rec {
    uint32_t insn_count;  // low 32 bits, for locating a divergence
    uint32_t addr;        // physical, at the access's own width
    uint32_t value;
    uint32_t flags;       // low byte: size in bytes; bit 8: write
};

#define BUS_F_WRITE  0x100u
#define BUS_F_ERROR  0x200u   // the access failed; nothing decoded it
#define BUS_F_IFETCH 0x400u   // an instruction fetch, not a data access

#define BUS_SIZE(f)     ((f) & 0xFFu)
#define BUS_IS_WRITE(f) (((f) & BUS_F_WRITE) != 0)
#define BUS_IS_ERROR(f) (((f) & BUS_F_ERROR) != 0)
