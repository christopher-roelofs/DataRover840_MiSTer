# The part runs at 36.864 MHz. Ask for 50 so there is headroom for the bus
# and cache logic that will sit between this core and SDRAM.
create_clock -name clk -period 20.000 [get_ports clk]
derive_clock_uncertainty
set_false_path -from [get_ports rst_n]
