# mister_datarover840

A MiSTer FPGA core for the Oki DataRover 840, the MIPS Magic Cap device.
The goal is the same one magicrecomp has in software: run `MagicCap-USA.image`,
the device's own 4.3 MB ROM, as the hardware would.

## Status

**Magic Cap boots.** Load the core on a MiSTer with the DataRover ROM and
the panel shows the rabbit coming out of the hat, then the splash: "Magic
Cap -- Touch the screen to begin". Hold the option (OSD: Boot) and it takes
the ROM's other path instead, the IDT monitor, whose banner comes out of
the serial port byte-identical to the reference emulator's, through the
`<IDT>` prompt (`scripts/serial`). Underneath that: **the CPU matches the
reference core over ten million instructions from reset**, including every
one of the 2,146,801 data-bus accesses in that window, and the peripheral
traffic of the whole Magic Cap boot -- every register, every value, in
order -- matches the reference's through the splash.

**And stays up.** For a while it booted, showed the splash, and a few
seconds later restarted into "Cleaning up" -- five boots in twelve. That
was an exception taken in a branch delay slot whose fetch had missed the
cache: the core lost track that it was a delay slot, returned to the slot
instead of the branch, and a taken branch fell through. Once in a few
million instructions an interrupt landed on exactly such a slot. Fixed,
twelve boots in twelve come up and stay, each with the same exception
count to the instruction. Finding it took running the two machines in
step *through* the interrupts, in both directions; see **How it is
validated**.

A mouse is the pen: it moves a crosshair over the panel, its left button
is a touch and its right a touch with the option key held; a joystick is
the pen as well, its stick moving the crosshair, A a touch and B a touch
with option, and its third button the ON button. Calibration
goes through, the MiSTer's keyboard is a Magic Bus keyboard, and the boot
sound plays. After the machine has sat idle Magic Cap turns it off; by
default the core then presses the ON button for it (there is no battery to
save), and F4 or the joystick's ON button is that button. The AC
adaptor is plugged in by default (OSD: Power), which is what a MiSTer is,
and Magic Cap's battery gauge shows its lightning bolt; it is the TX39's
PWRINT pin, found by driving each input the ROM watches in the reference
emulator until the gauge changed. On the adaptor Magic Cap never turns
itself off when idle, as the real machine on its charger does not; on
Battery it does, and "After idle power-off" says whether it wakes again.

**And remembers.** The four megabytes of RAM -- everything the user has --
are a MiSTer save file, `saves/DataRover840/<rom>.sav`, written when Magic
Cap turns the machine off, on "Save RAM now", or (off by default) when the
OSD opens, and read back when the core starts: the ROM finds its own
world, says "Cleaning up", and carries on where it was. A save or load
holds the machine for about two seconds, and the panel shows a bar
filling meanwhile. "Autosave every" (off by default) adds a save every 5,
15 or 30 minutes, taken only if the RAM has changed since the last one. "Start fresh" resets into cleared RAM instead, leaving
the file to be replaced by the next save. The USA, Japanese
and Rosemary SDK ROMs are three menu entries, each with its own save. The
panel can be shown in black and white, as a grey STN or in the green of a
PIC-2000's lit panel, and `shadow_masks/` holds the LCD grid for the
framework's video settings at the panel's 3x and 4x integer scales.

**And takes a card.** A memory card in slot 2 is a raw image of its common
memory -- the reference emulator's own format, so a card is carried
between the two as a file -- mounted from the OSD, written back with the
RAM and whenever the OSD opens with it written to. The controller sees it
arrive, the ROM reads its CIS and probes its size exactly as the reference
does (the ROM's whole probing of a formatted card matches the reference's
access for access), and Magic Cap formats a blank one itself when it goes
in with the option key held, which the OSD's re-insert entry does.
`scripts/mkcard` makes a blank one.

**And installs packages.** Magic Cap gets its software over the serial
port from a PC running WinPcLink; the OSD's "Install package" entry is
that PC. The file goes into the SDRAM beyond the cards while the machine
runs, and is offered on UART A by the PC's half of the link
(`rtl/soc/dr840_pclink.sv`, from the reference emulator's `pclink.c`):
in Magic Cap, walk to the Storeroom and tap the computer, and "Receiving
Package" fills its bar. The engine's every byte -- the blocks, the
quoting, the CRCs, the offer record -- is checked against a port of the
reference's PC side (`sim/pclink/`), and the whole thing has run in
simulation from a warm RAM image through the nine taps to the computer:
the link came up at 535M instructions, the package was taken at 794M,
and the Storeroom's shelf then holds "DvorakKeyboard 21K" -- the same
screen the reference emulator ends on. "Offer package again" holds the
same package out for another RAM image. The device runs the link at 19200
baud and a real PC could not change that; this link is not a wire, and by
default hands bytes over four times as fast, with 2x and the device's own
rate as OSD choices. Four times is as fast as Magic Cap keeps up: in
simulation, sixteen times loses data ("Part of the data was lost on the
way") and unpaced never links. The guest's own work dominates a transfer,
so 4x is about 1.6 times quicker overall, not four.

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
| ALMs | 2,781 (7%) | 3,208 (8%) |
| Registers | 3,229 | 3,447 |
| Block RAM | none | 7 M10K |
| DSP | 6 / 112 | 6 / 112 |
| Fmax | 57.17 MHz | 47.31 MHz |

With the clock enable and its multicycle constraints, the cached core closes
at a **95 MHz clock** -- the SDRAM's rate, advancing every second edge -- with
0.439 ns of slack. The whole machine, with the peripheral block, closes at
92 MHz. See **Clocking**.

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
cd sim/cosim && make check       # the first million through every harness
```

`make check` is the thing to run after touching anything. It exists because
the board harness sat frozen for several commits after a port was added to
the core and not wired into it, and the directed tests went on passing from
binaries built before the change. A harness nobody runs is not a harness.

Traces are not in git -- a million instructions is 144 MB.

### In step through the interrupts

The state trace stops being usable once the two machines' interrupts
arrive at different instructions, which they do as soon as their clocks
differ; and their peripherals are different implementations, so from then
on every diff is timing. Two things cut through that.

`sim/sdram/tb_sdram --replay --bus dev.bus --irq irq.bin` plays the
reference's device answers and the *level* of its interrupt line (from its
`--trace-bus-dev` and `--trace-irq`, run `--headless` -- it paces itself to
the wall clock otherwise, and two runs differ) into this machine. Its
devices are bypassed; its core, caches and memory run the reference's
program, and the first device access that is not the reference's next one
is where they part. With the fix above they do not: 180 million
instructions and 1,641,474 device accesses, to the end of the trace.

`--record prefix` does the reverse: this machine's own device answers,
interrupt level and the instruction each interrupt was taken in front of,
which the reference plays back (`--replay-dev`, `--replay-irq`,
`--replay-take`). Then the reference runs *this* machine's boot, with the
divergence reported as drift in the instruction count -- which is how a
one-instruction difference at one interrupt in a few million became
visible at all. `--trace-from N,count` on both lines the two up by
instruction. With the fix, the reference runs 174 million instructions of
this machine's recording to the end, in step.

`--check` is the cheap version: this machine's own devices answer, and every
access is compared against the reference's trace anyway. Where the value a
register returns differs, it prints; where only the count of a poll
differs, the collapsed streams (`ACC=1 --iolog`) diff clean.

### What the hardware says

On the board the status line does what the traces do in simulation. While
the guest leaves UART A idle, `rtl/dr840_status.sv` borrows the pin and
sends a line of hex every second at 38400: resets, exceptions, the ROM's
checksum as sent and as read back, the last PC and retired count, the
memory test's mismatches (or, while those stay at zero, the pen: down,
and the raw X and Y counts the codec is given), and the first fault at a
place other than the boot's one known BREAK -- code, EPC, BadVAddr. `scripts/soak N secs`
reloads the core N times and collects the last line of each boot, so a
fault on the hardware is something collected rather than described.

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

## Building and running it

```sh
quartus_sh --flow compile DataRover840     # output_files/DataRover840.rbf
scripts/deploy                             # copies core and ROM to the MiSTer
```

It builds and meets timing: 10,475 ALMs of 41,910, 65 of 553 M10K, with
1.089 ns of setup slack and 0.240 ns of hold on the 92 MHz clock. Most of
that area is the MiSTer framework; the core itself is 3,208 ALMs and 7 M10K.

`scripts/deploy` puts the core in `_Console`, the ROM in
`games/DataRover840`, and a `.mgl` beside the core that names them both,
then asks MiSTer to load the `.mgl`. That boots with the ROM attached and
nothing to pick from the OSD. The ROM arrives over `ioctl` and is written
into the SDRAM before the core leaves reset.

`scripts/serial` reboots it that way and prints what comes out of the
serial port. The core's `UART_TXD` reaches the HPS's own UART, which Linux
on the MiSTer sees as `/dev/ttyS1`; the monitor runs it at 38400 8N1.

The HPS sends bytes and the controller has no byte enables, so bytes are
assembled into whole words first -- four times fewer transactions, and no
read-modify-write per byte of a four megabyte image. `ioctl_wait` carries
the back-pressure: the stream is faster than the SDRAM, and without it the
writes that do not fit are simply dropped, leaving a ROM with holes in it
that looks exactly like a CPU bug.

### What you see

The panel: 480x320 at 2 bits per pixel, as a raster of its own size at
59.96 Hz and a 3:2 aspect for the framework's scaler, whose video settings
choose the size on the screen -- integer 3x or 4x with the LCD grid from
`shadow_masks/`, or filled (`rtl/soc/dr840_lcd.sv`). The OSD's Screen
option has the older 640x480 raster with the panel in a bezel instead,
which is also what the debug display draws in. The LCD controller is a
scanout of the framebuffer VIDEOCTRL3 names, a line at a time into a line
buffer, fetched through the board's arbiter as its third and last
requester. A set bit is ink; INVVID flips it. Until the ROM enables the
controller the panel is a flat grey, which is what an unpowered LCD looks
like too.

The OSD's Display option swaps in a debug display instead: ten 32-bit
values in hex (`rtl/dr840_hud.sv`).

| row | |
|---|---|
| 0 | the last retired PC |
| 1 | the instruction at it |
| 2 | instructions retired |
| 3 | times the core has been let out of reset |
| 4 | exceptions taken since |
| 5, 6 | data cache hits, misses |
| 7 | device reads |
| 8 | ROM words loaded |
| 9 | bytes sent on UART A |

Row 2 climbing means the core is fetching from SDRAM and executing. Row 9
stopping at 0x179 (377) means the banner is out and the monitor is waiting
at its prompt. Row 8 at zero means no ROM has been loaded yet, and the core
is held in reset until one is.

## Clocking

One clock, one domain, nothing to cross. The SDRAM runs at 92 MHz and the
core is the same clock gated down by a clock enable, so it advances every
second edge -- an effective 46 MHz. Every register in the core and its
caches is enabled; the adapter and the controller are not. The peripheral
block moves on the core's edges too.

The point is latency measured in the core's own cycles. A memory access
takes about twelve memory clocks whatever else happens, and at a divider of
two that is six of the core's rather than twelve:

| memory clocks per core clock | 1 | 2 | 3 | 4 |
|---|---|---|---|---|
| IPC at the core's rate | 0.075 | 0.149 | 0.223 | 0.293 |

(first 200k instructions, which are almost entirely uncached monitor code
and so the worst case the machine ever has.) Over the first million it is
0.097 against 0.188 -- the divider is worth a little under 2x, and 3 or 4
would be worth more still if the SDRAM could be clocked that high, which at
95 MHz it already nearly cannot.

**Crossing between the two rates is where this got interesting.** The core's
registers move on enabled edges and the adapter's move on every edge, so a
path between them has one memory clock unless something makes it otherwise.
The decode in front of the adapter and the route from its data into the
cache RAMs both need more than one; the first build missed by 5 ns.

The fix is in the adapter, not the constraints: it **raises a reply, and
starts a transaction, only on an enabled edge**. Then the far side captures
on the next one and everything crossing has a whole core period. The
controller's ready pulses are one cycle wide and do not wait, so they are
caught and held until that edge comes round. It costs a little -- IPC at a
divider of two went 0.149 to 0.145 over the first million -- and it lets the
`.sdc` say something true instead of something convenient.

**A clock enable does not relax timing by itself.** Without saying so, the
fitter has to close the whole core at the memory's rate. The constraint that
makes it true is in `syn/cached/r3900_cached_syn.sdc`:

```
set_multicycle_path -setup -end 2 -from [get_registers *] -to [get_registers *]
set_multicycle_path -hold  -end 1 -from [get_registers *] -to [get_registers *]
```

With those, the core and caches close at 95 MHz with 0.439 ns to spare.
Without them the same design fails by a factor of two, and the failure looks
like the core being too slow rather than the constraints being wrong.

**Where the clock went, and how it came back.** With the peripheral block
in place the build stopped closing at 92 and ran at 78 for a day. The path
was not the one it looked like. Read from the report node by node, it was:
the data cache's fill state, through the board's decode, into the
peripheral block's *live* read mux -- fifteen address compares and a
select -- back through the cache as load data, forwarded straight into a
branch compare in ID, and from there through `fpc_nxt` to the instruction
cache's RAM address. 24.8 ns. A load-to-branch forward with a combinational
peripheral at the front of it.

Two registers fix it. The peripheral block decides its reply on the edge
that carries the transaction out and holds it until the acknowledgement is
taken; the board chooses whether to hand back the peripheral's reply or
the memory's from a register that moves on the core's edges. Both replies
are registered and neither can arrive on the first enabled edge after a
request, so the choice is always made in time. The same chain now starts
nine nanoseconds later. That left one path -- the UART's bit period, a
multiplier feeding the bit counters' compare directly, 10.5 ns single-cycle
-- and the product is a register now too, since the divisor changes once.

Along the way, a lesson about where a register goes. The first attempt
registered the board's decode, and made timing *worse* by 10 ns: the new
register sat in the board, outside the group the `.sdc` gives two periods
to, so the same path was launched from there and judged against one. A
register does not shorten a path; it decides where the path starts, and
the constraints have to know about it. The board's reply-select register
is named in the `.sdc` for exactly that reason.

Everything derived from the clock is a parameter -- the SDRAM's refresh
interval, the UART's bit period, the RTC's 32.768 kHz tick -- so a retarget
is one number in `rtl/dr840_machine.sv` and the PLL.

The controller's refresh constants are derived from its clock now rather
than written out for 100 MHz. At 95 MHz, where this first ran, the
100 MHz numbers refresh every 8.2 us where the part wants 7.8 -- about 7,800
refreshes in the 64 ms that needs 8,192. Close enough to look fine and not
close enough to be right; the chip model's worst gap fell from 1,559 clocks
to 799 when they were corrected.

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

**One million instructions match through the whole path**, with the chip
reporting no protocol violation.

`sim/sdram/` runs it against a model of the chip that **checks the
controller as it goes**: bank state, tRCD, reads from an unopened row,
refresh interval. The model came from TI83Plus_MiSTer and was extended here
for burst reads, since answering only the first word of a four-word burst
would make a controller look correct while three quarters of every cache
line came back as whatever was on the bus.

### What the chip model caught

Two things, and both were real.

**An acknowledgement reached the wrong requester.** A fetch was issued to
memory, the data cache then missed, the stall reached back and the fetch
stage stopped asking for anything -- and the arbiter, which derived its
grant from who was asking *now*, moved on. The reply to that fetch arrived
afterwards and was handed to the data side, which took it as the first word
of its own cache line. Every word after it landed one slot late and the line
was quietly wrong: `0,0,0,1` where the ROM has `0,0,1,0`.

A grant has to outlive the request that earned it. It is now held until the
memory says it is finished, and a reply that nobody is waiting for is
dropped rather than given to whoever happens to be asking.

This is the kind of fault that only appears once a real controller is in the
loop: with memory that answers immediately, or on a fixed delay, the
requester never has time to withdraw.

**A refresh alarm calibrated for a different controller.** The model warned
above a 1200-clock gap, which suits a controller refreshing every 390. This
one refreshes every 780 and forces one at 1560, so ordinary catch-up -- a
worst gap of 1522 -- tripped it. Retuned to 1700, which is above what this
controller allows itself and far below losing data: a row has 64 ms, or 6.4
million clocks at 100 MHz.

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
rtl/soc/dr840_tx39.sv   the TX39 peripheral block: interrupts, UART A, RTC,
                        timers, power, MBUS, and the two Glacier card controllers
rtl/soc/dr840_sib.sv    the serial interface bus and the UCB1100 codec on it
rtl/soc/dr840_lcd.sv    the LCD controller, onto a 640x480 raster
rtl/soc/dr840_pclink.sv the PC side of the package link, on UART A
rtl/dr840_machine.sv    the machine: clock enable, loader mux, core, board, SoC
rtl/emu.sv              the MiSTer top: ROM loader, UART pins, debug display
scripts/deploy          builds a boot on the MiSTer; scripts/serial reads it
sim/lcd/             the panel's scanout against the framebuffer it scans
sim/pclink/          the package link against a port of the reference's PC side
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

## The peripherals, and how they were found

Everything in `rtl/soc/` was written from the reference emulator's models
and then argued with until the two machines' peripheral traffic agreed.
The tool for that is the SDRAM harness's `--iolog`, which prints every
device access in the reference's own `--log-mmio` format with polls
collapsed to one line and a count, so the two boots diff directly; with
`--watch-write`, `--trace-after` (added to the reference too) and
`--dump-fb`, each divergence took about an hour to name. Some of them:

- **IOCTRL's option pin.** Bits 6..0 are inputs and read from the pins
  whatever was written. Pin 3 is the option button, and the ROM's
  boot-select reads it 742,000 instructions in to choose Magic Cap or the
  monitor. Reading back the written zero chose the monitor every time.
- **POWERCTRL reads PWROK set** whatever was written. Reading it clear after
  the ROM's own write, the ROM concluded the supply was failing and ran its
  shutdown routine -- the countdown loops at 13C3B1E4 were its settling
  delays.
- **The interrupt lines.** ICU banks 1..5 drive IP4 and bank 6 drives IP6.
  NetBSD's tx39icu.c switches on MIPS_INT_MASK_2 and MIPS_INT_MASK_4, and
  those count hardware lines from zero; read as IP2 and IP4, the ROM never
  enabled either, no interrupt was ever taken, and Magic Cap sat forever
  in its idle loop waiting on a flag that only an interrupt handler sets.
- **The SIB is a clocked frame bus.** SIBSF0INT is periodic, not raised by
  the write that starts a transfer -- the ROM clears it after starting one
  and waits, so raising it in the write loses it. The frame rate here is
  the sound sample rate, 36.864 MHz / (128 * (SNDFSDIV + 1)); the reference
  completes a frame every machine tick, about three times faster, so
  anything the ROM paces by frames takes about three times as long here
  as there. This is the one place the two are known to differ in time,
  and the hardware rate is the honest one.
- **INTRSTATUS6 is a summary** carrying IRQLOW whenever any bank has an
  enabled source pending; the OS idle routine polls it. It is read-only.
- **The Glacier card-detect pins are active low.** An empty slot reads them
  high, and returning zero leaves the ROM's debounce polling forever.

Two more came from the hardware rather than from a diff, and neither could
have come from anywhere else:

- **A burst address is aligned down to sixteen bytes** by the adapter, which
  had only ever been handed cache lines, and cache lines are aligned. A
  panel line is 120 bytes, so every other line begins eight bytes off a
  boundary and came back shifted by eight: half the screen right and half
  of it wrong. The controller now fetches the aligned window the line falls
  in and reads out at an offset. `sim/lcd` scans a framebuffer whose every
  line is distinguishable and reports which source line each screen line
  actually came from, which is how this was found and is what keeps it
  found.
- **Nothing cleared the DRAM.** Magic Cap keeps its world in RAM and expects
  it to survive a power cycle -- the real machine's RAM is battery-backed --
  so it found the previous run's memory, recognised it as its own and
  damaged, and spent the boot on "Cleaning up". A model's memory begins as
  zeroes, so no simulation could have shown this. The loader walks the four
  megabytes before the core is let go, and a reset asks for the same walk.

## Next

1. Recover the IPC lost to the handshakes on the core's edges: 0.72 at
   the core's rate over the banner path, against 0.75 before them.
2. An external interrupt test: the ICU is exercised by the ROM's own timer
   path but nothing yet drives an IP line from outside the block.
3. A network: the ROM speaks PPP to a modem, so a modem PC Card with a
   16550 is the path, prototyped in the reference emulator first.
