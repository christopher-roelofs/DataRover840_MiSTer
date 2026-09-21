# The core and its caches run from a clock enable, at half the clock the
# SDRAM uses. Every register in this module is enabled by `cen`, so every
# path inside it has two clock periods to settle, not one.
#
# Saying so is not optional. A clock enable does not relax timing by itself:
# without these the fitter has to close the whole core at the memory's rate,
# which it cannot do and should not have to.
create_clock -name clk -period 10.526 [get_ports clk]
derive_clock_uncertainty

set_multicycle_path -setup -end 2 -from [get_registers *] -to [get_registers *]
set_multicycle_path -hold  -end 1 -from [get_registers *] -to [get_registers *]

set_false_path -from [get_ports rst_n]
