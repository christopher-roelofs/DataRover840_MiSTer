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
