# mister_datarover840

A MiSTer FPGA core for the Oki DataRover 840, the MIPS Magic Cap device.
The goal is the same one magicrecomp has in software: run `MagicCap-USA.image`,
the device's own 4.3 MB ROM, as the hardware would.

## Status

**The CPU matches the reference core over ten million instructions from
reset**, including every one of the 2,146,801 data-bus accesses in that
window. Nothing else exists yet: no SoC, no video, no MiSTer wiring.

```
matched 10000000 of 10000000 instructions, 2146801 bus accesses,
22147759 cycles (2.21 cycles/insn)
PASS
```

On the DE10-Nano part, the core alone:

| | |
|---|---|
| ALMs | 3,345 / 41,910 (8%) |
| Registers | 2,815 |
| DSP | 6 / 112 |
| Block RAM | none yet |
| Fmax | 66.7 MHz (slow 85C) |

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

## Sequencing, and why it is going to change

This is the correctness-first version: one instruction at a time through an
explicit state machine, 2.21 cycles per instruction. At 66.7 MHz that is
about 30 MIPS, against the roughly 36.9 the part manages at 36.864 MHz and
one instruction per cycle. Close, but short.

Pipelining is the next step. The retire port exists so that it can happen
without changing how the core is validated: the harness compares
architectural state at retire and does not care how many stages produced it.

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
