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
11791270 cycles (1.18 cycles/insn, 0.848 IPC)
fetches 10000004 for 10000000 retires (1.000 per instruction)
PASS
```

Eleven directed tests cover what the ROM does not reach, including every
exception the core can raise. `tests/run`.

The same ten million also pass **with the caches in place** and **under
memory latency**, fixed or random. A cache is supposed to be invisible, so
the test for one is that nothing above had to change.

On the DE10-Nano part, the core alone:

| | |
|---|---|
| | core | with caches |
|---|---|---|
| ALMs | 2,781 (7%) | 3,203 (8%) |
| Registers | 3,229 | 3,516 |
| Block RAM | none | 7 M10K, 47,808 bits |
| DSP | 6 / 112 | 6 / 112 |
| Fmax | 57.17 MHz | 47.49 MHz |

### What that is worth

Memory that answers immediately is the one thing this core will never meet,
so IPC at zero latency is not a number to plan with. Against the same
modelled latency, over the ten-million-instruction window:

| memory latency | no cache | cached |
|---|---|---|
| 0 | 0.858 | 0.923 |
| 2 cycles | 0.245 | **0.497** |
| 5 cycles | 0.120 | **0.367** |
| random 0-11 | 0.117 | **0.351** |

At two cycles that is 14.0 MIPS against 23.6: the caches are worth about
1.7x after paying for the lower Fmax they cost.

**On the target this gets measured against.** Earlier notes here called
36.864 MIPS the goal, taking the reference's one-instruction-per-cycle
model at face value. That model is a placeholder -- magicrecomp's own source
says so -- and the real TMPR3902U has these same two caches with real DRAM
behind them, so it stalls too. What the part actually retires per second is
not known and nothing here has measured it. The honest claim is that the
cached core is about 1.7x the uncached one at a plausible latency, not that
it meets a verified number.

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

### Directed tests

The ROM is an excellent test of the paths it uses and no test at all of the
ones it does not. It exercises 54 distinct instructions in ten million from
reset -- essentially the whole MIPS-I integer set, `lwl`/`lwr`/`swl`/`swr`
and `mult`/`divu` included -- and takes **zero exceptions** in all of it.
Everything the core does about faults was therefore untested by it.

`tests/*.s` aims at the rest deliberately, with the reference still the
arbiter: each one is assembled, run on magicrecomp, and replayed against the
RTL through the same lockstep harness. So the tests say what the hardware
does rather than what I believed when writing them.

| | |
|---|---|
| `exc_adel`, `exc_ades` | misaligned load and store |
| `exc_ovf` | overflow from `ADD`, `ADDI` and `SUB`, resuming between each |
| `exc_ri` | encodings both cores must refuse, not quietly NOP |
| `exc_sys_bp` | `SYSCALL` and `BREAK` |
| `exc_dbe` | load and store to nothing -- the only fault raised in MEM |
| `exc_ibe` | a jump to nothing -- the only fault raised in IF |
| `exc_delay` | a fault in a delay slot: EPC names the branch, Cause.BD set |
| `exc_int` | a software interrupt, and `RFE` returning from it |
| `exc_bev0` | the other vector, with the handler copied into RAM first |
| `arith` | `ADD`, `SUB`, `MULTU`, signed `DIV` and both its special cases, the variable shifts, `BLTZAL`/`BGEZAL`, `MTHI`/`MTLO` |

A test also declares how many exceptions it expects, and the runner checks
the reference actually took that many. A test that stops faulting -- because
an encoding stopped being illegal, say -- would otherwise keep passing while
testing nothing.

`tools/mipsasm.py` assembles them, so no cross-toolchain is needed;
`tools/gentrace.c` runs them on the reference in a machine that is two RAMs
and nothing else, resetting exactly as the real part does so the RTL side
needs no special setup.

Still not covered: an interrupt arriving on an external `IP` line rather
than through Cause's software bits, and the TLB instructions, which this
part does not have.

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

## The board

`rtl/board/dr840_mem.sv`. The address decode and the arbiter that puts the
two cache ports onto one memory. The map is the reference's, which prints it
at startup: 4 MB of DRAM across a 60 MB decode, flash at three separate chip
selects (its own base, the one the OS runs from, and the reset alias), two
PC Card controllers, the TX39 peripheral block, four card windows and the
unidentified chip in kseg3. Anything else is a bus error, which is how the
ROM's own probes find out what is not there.

RAM and flash both live in the one SDRAM -- ROM at its base, DRAM above it
-- so a single chip serves both and the HPS can load the ROM into it before
the core leaves reset.

Data wins arbitration. Anything in MEM was fetched before whatever IF is
asking for, so making the younger access wait is free where making the older
one wait is not. A burst holds the grant, which needs no counter: the cache
keeps its request asserted for all four beats.

The board is tested at memory latencies from zero upward, fixed and random,
because one SDRAM serving two ports is where a stall bug hides.

| SDRAM latency | 0 | 1 | 2 | 4 | random 0-7 |
|---|---|---|---|---|---|
| first 1M instructions | 0.901 | 0.524 | 0.366 | 0.230 | 0.254 |
| first 10M instructions | 0.650 | **0.566** | **0.501** | | |

The two windows disagree in opposite directions for the same reason. The
first million is nearly all uncached monitor code in kseg1: single-word
fetches, which are free when memory answers instantly and expensive when it
does not. The ten million is mostly the OS running cached out of kuseg,
where the caches carry it and the latency barely shows. The second is the
one to plan with, and at a plausible latency it is about **0.50 IPC**, or
23.8 MIPS at the 47.49 MHz the cached core closes at.

`sim/cosim/tb_board.cpp` runs the same lockstep one level further out, and
the split it uses is the board's rather than a guess. Whatever the decode
calls memory is served from a model of the SDRAM with the ROM loaded at its
base, exactly as the HPS will load it; whatever it calls a peripheral is
replayed from the reference's bus trace in order. An access sent to the
wrong side shows up at once, as a device access that does not match or as a
wrong instruction retired.

One deliberate difference from the reference: a chip select mirrors through
the space it decodes, and the reference does that with a real modulo of the
installed size -- 4,528,151 bytes, not a power of two. Here the window is
masked to 8 MB instead. In ten million instructions nothing reads past the
image at all (the furthest access is its very last byte), and the ROM does
not use mirroring to find its size -- it does not find it at all, it is a
constant. A real modulo would put a 32-bit divide on the path to memory.

## SDRAM

`rtl/board/sdram.sv` is Sorgelig's MiSTer controller, taken from GBA_MiSTer
rather than written here: it is the one already proven against the 128 MB
module this core targets, two chips selected by nCS from the top address
bit, burst length 4, CAS 2. A controller is a bad place to be original.

One change, and it is not behavioural: the bidirectional data bus comes out
as separate `_O`, `_OE` and `_I` instead of a registered `inout`, and the
pin is driven in one place at the top. A registered inout cannot be
simulated -- Verilator refuses it outright -- and a memory controller is
precisely the thing that most needs simulating.

`rtl/board/dr840_sdram.sv` adapts it to the port the caches present, and
each part of it exists for one mismatch:

- **A refill is 16 bytes, a burst read returns 8**, so a line is two
  transactions and the four words go back one per acknowledge.
- **Halfword order.** The controller returns the lowest-addressed halfword
  in the low bits and this machine is big-endian, so a word is the two
  halves the other way round. The ROM the HPS loads goes through the same
  swap, which is what keeps it readable.
- **No byte enables.** The controller drives both byte masks from the same
  bits, so a store narrower than a word reads, merges and writes back --
  two transactions, for the 43,126 SB and SH in the first ten million
  instructions. Adding masking to an otherwise proven controller is the
  worse trade.

`sim/sdram/` runs the whole path against a model of the chip that **checks
the controller as it goes**: bank state, tRCD, reads from an unopened row,
refresh interval. The model came from TI83Plus_MiSTer and was extended here
for burst reads, since answering only the first word of a four-word burst
would make a controller look correct while three quarters of every cache
line came back as whatever was on the bus.

### Known broken: the first line refill through real SDRAM

Twenty thousand instructions match, with no protocol violation reported by
the chip. The first *cache line refill* does not, and the run stops at
instruction 81,302.

What is known: all four beats are flagged as a burst and carry the right
addresses, and the words the chip returns are right. The adapter issues
**three** SDRAM transactions for the line where it should issue two --
acknowledging once, then twice, then once -- so the first burst loses an
acknowledge and every word after it lands one slot late. The line ends up
holding `0,0,0,1` where the ROM has `0,0,1,0`.

Everything above this level still passes: the same ten million instructions
match through `sim/cosim` with the caches and the board, against modelled
memory at every latency tried. This is the adapter's burst sequencing and
nothing further up.

## Caches

`rtl/cpu/r3900_cache.sv`. 4 KB of instruction cache and 1 KB of data cache,
direct-mapped, 16-byte lines. Not guesses: the IDT monitor prints both
sizes, and the ROM's invalidation loops at `0x83C008AC` and `0x83C008D4`
walk exactly those sizes in 16-byte lines.

- **Write-through, no write allocate**, which is what the TX39 family
  documents. It also keeps the thing testable: every store still reaches
  memory in program order, so stores go on being checked against the
  reference one for one, and only reads are filtered.
- **A hit costs no cycles.** The core publishes a lookahead address so the
  tag and data RAMs have already been read by the time an access is asked
  for. Addressing them with the current address would make every hit take
  two cycles and halve the IPC the pipeline exists for.
- **Refills are bursts.** Four separate reads pay the access latency four
  times, which throws away most of the benefit.
- **kuseg and kseg0 are cached; kseg1 and kseg2/3 are not.** kseg1 is where
  this board's registers are reached. This is the one thing lockstep cannot
  check: a cache is architecturally invisible in a machine with one master,
  so the reference agrees with any policy. The tests show the caches break
  nothing, not that the policy is the part's own.
- **No snooping.** MIPS hardware does not snoop; software that writes
  instructions invalidates them itself, and this ROM does. The CACHE
  instruction is passed out of the core and drops the addressed line.

## Layout

```
rtl/cpu/r3900.sv     the core
rtl/cpu/r3900_cache.sv  the caches, and the core wrapped in them
rtl/board/dr840_mem.sv  address decode and the memory arbiter
rtl/board/dr840_sdram.sv  the memory port onto the controller's channels
rtl/board/sdram.sv      Sorgelig's MiSTer SDRAM controller
sim/sdram/           the whole memory path against a model of the chip
sim/cosim/           Verilator lockstep harness against magicrecomp
sim/golden/          reference traces (regenerated, not committed)
scripts/mktrace      regenerates them
tests/               directed tests, and tests/run
tools/mipsasm.py     a small big-endian MIPS-I assembler
tools/gentrace.c     runs a test on the reference, emits the same traces
syn/cpu/             Quartus project for the core alone: area and Fmax
sys/                 MiSTer framework
```

## Next

1. Clocking, and ROM load over the HPS. The controller wants to run faster
   than the CPU; one PLL with the core on a clock enable avoids any domain
   crossing, and is what decides the real throughput.
2. TX39 peripheral block, enough of it to reach the IDT monitor banner:
   BIU, interrupt controller, UART A, clock/power control.
3. LCD controller to MiSTer video. 480x320 at 2 bpp, four pixels per byte,
   most significant bits first -- the same panel format every Magic Cap
   machine uses.
4. SIB and the UCB1100: touchscreen ADC, the AD2/AD3 battery rails, the
   periodic sound-in interrupt the boot path waits on.
5. Empty PC Card slots with card-detect high, MBUS idle.
