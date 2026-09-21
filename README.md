# mister_datarover840

A MiSTer FPGA core for the Oki DataRover 840, the MIPS Magic Cap device.
The goal is the same one magicrecomp has in software: run `MagicCap-USA.image`,
the device's own 4.3 MB ROM, as the hardware would.

## Status

**The CPU matches the reference core over ten million instructions from
reset**, including every one of the 2,146,801 data-bus accesses in that
window. Nothing else exists yet: no SoC, no video, no MiSTer wiring.

```
matched 10000000 of 10000000 instructions, 2146802 bus accesses,
11656940 cycles (1.17 cycles/insn, 0.858 IPC)
fetches 10000004 for 10000000 retires (1.000 per instruction)
PASS
```

On the DE10-Nano part, the core alone:

| | |
|---|---|
| ALMs | 2,759 / 41,910 (7%) |
| Registers | 3,249 |
| DSP | 6 / 112 |
| Block RAM | none yet |
| Fmax | 56.07 MHz (slow 85C) |

**56.07 MHz at 0.858 IPC is 48.1 MIPS**, against the 36.864 the part manages
at one instruction per cycle. That is 1.3x the target, which is the margin
the caches and SDRAM controller have to fit inside.

## How it is validated

magicrecomp is the reference. Its C core is the thing every hardware
conclusion in this project was derived from, so the RTL is not compared
against a datasheet or against intuition -- it is compared against that,
instruction by instruction, running the real ROM.

Two traces come out of magicrecomp (`--trace-state`, `--trace-bus`):

- **state**, one fixed-size record per retired instruction, holding pc, the
  instruction word, next_pc, hi, lo and r1..r31
- **bus**, one record per data access, in program order

The RTL core in `sim/cosim` has no memory and no devices, and needs none.
The state trace already says what instruction sits at every address it will
fetch, and the bus trace says what every read returned. So the harness
serves fetches from the trace, replays reads, checks writes, and compares
the whole architectural state at each retire. A CPU can therefore be brought
up against the device's own ROM before a single peripheral is modelled, and
a divergence is reported at the instruction it happens on rather than
somewhere downstream.

```sh
scripts/mktrace                  # regenerate sim/golden/reset-1m.{trc,bus}
cd sim/cosim && make && make run
```

Traces are not in git -- a million instructions is 144 MB.

## What the core is

`rtl/cpu/r3900.sv`. MIPS-I plus `CACHE` and `RFE`, big-endian, no TLB.
Anything else raises Reserved Instruction rather than quietly becoming a
NOP, which is also what the reference does; the two have to disagree about
nothing, including what they refuse.

The R3900 differences that matter, all of them established in
magicrecomp's `docs/HARDWARE.md` from the ROM's own behaviour:

- **No TLB.** kseg0/kseg1 mask the top three bits; kuseg and kseg2/3 map
  straight through.
- **No architectural load delay slot.** The part scoreboards, so a load
  result is available to the next instruction. This is the main reason the
  PSX R3000A core is not a drop-in: it models the slot.
- **CP0 Config is $3**, not $16.
- **Status.PE is a write-one-to-clear latch**, not a stored bit. Storing it
  verbatim makes the ROM's monitor report a parity error after every
  character it transmits.
- **PRId reads 0x2200.** The ROM compares against that literal and branches.
- Only the two software interrupt bits of Cause are writable.

The MADD family the R3900 also has is deliberately absent, because the
reference does not implement it either and this ROM does not use it. Adding
it on one side only would break lockstep for no gain.

### ISA coverage

54 distinct instructions are exercised by the ten-million-instruction
window, which is essentially the whole MIPS-I integer set including
`lwl`/`lwr`/`swl`/`swr` and `mult`/`divu`. Implemented but **not** reached
by that window, and so not yet validated: `add`, `sub`, `multu`, `div`,
`bltzal`, `bgezal`, `syscall`, `break`, and every exception path -- the ROM
takes none in the first ten million instructions.

## Sequencing

Five stages: IF, ID, EX, MEM, WB.

**Branches resolve in ID**, which is what makes the delay slot architectural
rather than something to squash around. When a branch is in ID the delay
slot is already the address IF is fetching, so the redirect lands on the
fetch after it and the core never runs down a wrong path at all. The harness
checks this directly and reports 1.000 fetches per retired instruction.

Costing the 0.142 IPC that is not there, in rough order:

- **Load-use.** The part has no architectural load delay slot -- it
  scoreboards -- so the pipeline interlocks for one cycle and then forwards
  from MEM/WB. A branch needs its operands a stage earlier than everyone
  else, so a load two ahead of a branch costs a second cycle.
- **CP0 and HI/LO are interlocked, not forwarded.** Both commit in WB, and a
  reader behind a writer stalls until it drains. They are 1.3% of this ROM's
  instructions, and an interlock cannot be subtly wrong the way a forwarding
  path can. If IPC ever needs to go higher this is the first thing to
  convert.
- **Divide** is 33 cycles, restoring, on magnitudes. 29 of them in ten
  million instructions.

Multiply is one cycle in the DSP blocks.

The retire port names the instruction whose writes have already landed,
which is one edge behind WB. That is deliberate: naming it while it is still
in WB would point at state it has not written yet.

## Layout

```
rtl/cpu/r3900.sv     the core
sim/cosim/           Verilator lockstep harness against magicrecomp
sim/golden/          reference traces (regenerated, not committed)
scripts/mktrace      regenerates them
syn/cpu/             Quartus project for the core alone: area and Fmax
sys/                 MiSTer framework
```

## Next

1. Pipeline the core to one instruction per cycle.
2. I-cache and D-cache (4 KB / 1 KB, what the monitor reports), SDRAM
   controller, ROM load over the HPS.
3. TX39 peripheral block, enough of it to reach the IDT monitor banner:
   BIU, interrupt controller, UART A, clock/power control.
4. LCD controller to MiSTer video. 480x320 at 2 bpp, four pixels per byte,
   most significant bits first -- the same panel format every Magic Cap
   machine uses.
5. SIB and the UCB1100: touchscreen ADC, the AD2/AD3 battery rails, the
   periodic sound-in interrupt the boot path waits on.
6. Empty PC Card slots with card-detect high, MBUS idle.
