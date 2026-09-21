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
