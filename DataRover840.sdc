# 92 MHz for the SDRAM; the core advances on every second edge of it.
#
# It was 78 for a while. The longest path in the machine ran from the data
# cache's fill state, through the board's decode, into the peripheral
# block's live read mux, back through the cache as load data, forwarded
# into a branch compare in ID, and from there to the instruction cache's
# RAM address: 24.8 ns. The peripheral block now decides its reply on the
# transaction edge and holds it in a register, and the board chooses which
# reply to hand back from a register too, so the chain starts nine
# nanoseconds later. Two periods of 92 MHz is 21.7.
#
# The core and its caches advance on every second edge of the SDRAM clock,
# so every path inside them has two periods to settle. Saying so is not
# optional: a clock enable does not relax timing by itself, and without this
# the fitter has to close the core at 95 MHz, which it cannot do.
#
# Scoped to the core deliberately. The adapter, the controller and the
# framework all run at the full rate, and a path leaving the core for any of
# them stays single-cycle.
set_multicycle_path -setup -end 2 \
    -from [get_registers {*r3900_cached:cpu|*}] \
    -to   [get_registers {*r3900_cached:cpu|*}]
set_multicycle_path -hold -end 1 \
    -from [get_registers {*r3900_cached:cpu|*}] \
    -to   [get_registers {*r3900_cached:cpu|*}]

# The adapter runs at the full rate but only ever hands a reply over on an
# enabled edge (see dr840_sdram.sv), so data crossing from it into the core
# has a whole core period to settle, not one memory clock. Without this the
# paths from ram_rdata into the cache RAMs miss by about 5 ns and the build
# does not close.
set_multicycle_path -setup -end 2 \
    -from [get_registers {*dr840_sdram:adapter|*}] \
    -to   [get_registers {*r3900_cached:cpu|*}]
set_multicycle_path -hold -end 1 \
    -from [get_registers {*dr840_sdram:adapter|*}] \
    -to   [get_registers {*r3900_cached:cpu|*}]

# And the same the other way. The adapter only starts a transaction on an
# enabled edge, so the address it samples -- which comes out of the core
# through the board's decode -- has had a whole core period to settle.
set_multicycle_path -setup -end 2 \
    -from [get_registers {*r3900_cached:cpu|*}] \
    -to   [get_registers {*dr840_sdram:adapter|*}]
set_multicycle_path -hold -end 1 \
    -from [get_registers {*r3900_cached:cpu|*}] \
    -to   [get_registers {*dr840_sdram:adapter|*}]

# Every register in the board moves on the core's edges: the choice of
# which reply to hand back, and the arbiter's grant. So paths into them
# from the core and from the adapter -- whose state also only moves on
# those edges -- have a whole core period, and paths out of them likewise.
set_multicycle_path -setup -end 2 \
    -from [get_registers {*dr840_mem:board|*}] \
    -to   [get_registers {*r3900_cached:cpu|*}]
set_multicycle_path -hold -end 1 \
    -from [get_registers {*dr840_mem:board|*}] \
    -to   [get_registers {*r3900_cached:cpu|*}]
set_multicycle_path -setup -end 2 \
    -from [get_registers {*r3900_cached:cpu|* *dr840_sdram:adapter|* *dr840_lcd:lcd|*}] \
    -to   [get_registers {*dr840_mem:board|*}]
set_multicycle_path -hold -end 1 \
    -from [get_registers {*r3900_cached:cpu|* *dr840_sdram:adapter|* *dr840_lcd:lcd|*}] \
    -to   [get_registers {*dr840_mem:board|*}]
set_multicycle_path -setup -end 2 \
    -from [get_registers {*dr840_mem:board|*}] \
    -to   [get_registers {*dr840_sdram:adapter|* *dr840_lcd:lcd|*}]
set_multicycle_path -hold -end 1 \
    -from [get_registers {*dr840_mem:board|*}] \
    -to   [get_registers {*dr840_sdram:adapter|* *dr840_lcd:lcd|*}]

# The LCD controller's fetch engine moves on the core's edges too, so its
# requests into the adapter, and the adapter's replies back, have a whole
# core period each.
set_multicycle_path -setup -end 2 \
    -from [get_registers {*dr840_lcd:lcd|*}] \
    -to   [get_registers {*dr840_sdram:adapter|*}]
set_multicycle_path -hold -end 1 \
    -from [get_registers {*dr840_lcd:lcd|*}] \
    -to   [get_registers {*dr840_sdram:adapter|*}]
set_multicycle_path -setup -end 2 \
    -from [get_registers {*dr840_sdram:adapter|*}] \
    -to   [get_registers {*dr840_lcd:lcd|*}]
set_multicycle_path -hold -end 1 \
    -from [get_registers {*dr840_sdram:adapter|*}] \
    -to   [get_registers {*dr840_lcd:lcd|*}]

# The peripheral block runs at the full rate but only moves on the core's
# edges -- it carries a transaction out on one and has it taken on the next,
# and its interrupt lines are registered on them too. So everything crossing
# from it into the core has a whole core period.
set_multicycle_path -setup -end 2 \
    -from [get_registers {*dr840_tx39:soc|*}] \
    -to   [get_registers {*r3900_cached:cpu|*}]
set_multicycle_path -hold -end 1 \
    -from [get_registers {*dr840_tx39:soc|*}] \
    -to   [get_registers {*r3900_cached:cpu|*}]
set_multicycle_path -setup -end 2 \
    -from [get_registers {*r3900_cached:cpu|*}] \
    -to   [get_registers {*dr840_tx39:soc|*}]
set_multicycle_path -hold -end 1 \
    -from [get_registers {*r3900_cached:cpu|*}] \
    -to   [get_registers {*dr840_tx39:soc|*}]

# The pen's pixels-to-counts multiply (dr840_pen.sv). A pen moves at a
# human's speed and the result is read thousands of clocks later, so the
# multiply can have two periods; at one it misses by a nanosecond and a
# half.
set_multicycle_path -setup -end 2 \
    -to [get_registers {*dr840_pen:pen|*}]
set_multicycle_path -hold -end 1 \
    -to [get_registers {*dr840_pen:pen|*}]

# The LCD's fetch engine runs on the core's enabled edges too, and its
# address reaches the core's cache fill through the arbiter's logic in the
# board -- register to register from the LCD to the core, which neither of
# the groups above (LCD to board, board to core) names. It was closing on
# placement luck and lost by 0.4 ns once the pen's multiplier moved in.
set_multicycle_path -setup -end 2 \
    -from [get_registers {*dr840_lcd:lcd|*}] \
    -to   [get_registers {*r3900_cached:cpu|*}]
set_multicycle_path -hold -end 1 \
    -from [get_registers {*dr840_lcd:lcd|*}] \
    -to   [get_registers {*r3900_cached:cpu|*}]

# The sound (dr840_snd.sv) runs on the core's enabled edges like the LCD's
# fetch engine, and talks to the board and the peripheral block, which
# change on those edges too; so everything into and out of it has a whole
# core period.
set_multicycle_path -setup -end 2 -from [get_registers {*dr840_snd:snd|*}]
set_multicycle_path -hold  -end 1 -from [get_registers {*dr840_snd:snd|*}]
set_multicycle_path -setup -end 2 -to   [get_registers {*dr840_snd:snd|*}]
set_multicycle_path -hold  -end 1 -to   [get_registers {*dr840_snd:snd|*}]

# The peripheral block's Magic Bus DMA into the board, and the board's
# acknowledgement back: both sides change on the core's enabled edges.
set_multicycle_path -setup -end 2 -from [get_registers {*dr840_tx39:soc|*}] -to [get_registers {*dr840_mem:board|*}]
set_multicycle_path -hold  -end 1 -from [get_registers {*dr840_tx39:soc|*}] -to [get_registers {*dr840_mem:board|*}]
set_multicycle_path -setup -end 2 -from [get_registers {*dr840_mem:board|*}] -to [get_registers {*dr840_tx39:soc|*}]
set_multicycle_path -hold  -end 1 -from [get_registers {*dr840_mem:board|*}] -to [get_registers {*dr840_tx39:soc|*}]

# The DMA clients' addresses decode in the board's arbiter, whose grants
# gate the peripheral block's own request: a path that leaves the block
# (or the sound, or the LCD) and comes back into it through the board's
# logic, register to register, on enabled edges at both ends.
set_multicycle_path -setup -end 2 -from [get_registers {*dr840_mbus:mbus|* *dr840_snd:snd|* *dr840_lcd:lcd|*}] -to [get_registers {*dr840_tx39:soc|*}]
set_multicycle_path -hold  -end 1 -from [get_registers {*dr840_mbus:mbus|* *dr840_snd:snd|* *dr840_lcd:lcd|*}] -to [get_registers {*dr840_tx39:soc|*}]
