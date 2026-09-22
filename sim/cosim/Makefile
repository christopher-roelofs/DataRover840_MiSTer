# Lockstep comparison of rtl/cpu/r3900.sv against magicrecomp's reference core.
#
#   make            build the simulator
#   make run        run it against sim/golden/reset-1m.{trc,bus}
#   make run N=...  stop after N instructions

VERILATOR ?= verilator
RTL       := ../../rtl/cpu/r3900.sv
TOP       := r3900
OBJ       := obj_dir

VFLAGS := --cc --exe --build -j 0 \
          -Wall -Wno-fatal +define+SIMULATION \
          --top-module $(TOP) \
          -GCOUNT_PER_INSN=1 \
          -CFLAGS "-O2 -I$(CURDIR)" \
          -Mdir $(OBJ)

N ?= 0

all: $(OBJ)/V$(TOP)

$(OBJ)/V$(TOP): $(RTL) tb_r3900.cpp goldtrace.h
	$(VERILATOR) $(VFLAGS) $(RTL) tb_r3900.cpp

run: $(OBJ)/V$(TOP)
	./$(OBJ)/V$(TOP) --state ../golden/reset-1m.trc --bus ../golden/reset-1m.bus -n $(N)

# The same core behind its caches. Same harness, same comparison: a cache
# that needed the test to change would not be invisible.
CACHED_RTL := ../../rtl/cpu/r3900.sv ../../rtl/cpu/r3900_cache.sv
CACHED_OBJ := obj_cached

cached: $(CACHED_OBJ)/Vtb_top

$(CACHED_OBJ)/Vtb_top: $(CACHED_RTL) tb_top.sv tb_r3900.cpp goldtrace.h
	$(VERILATOR) --cc --exe --build -j 0 -Wall -Wno-fatal \
	  +define+SIMULATION --top-module tb_top -GCOUNT_PER_INSN=1 \
	  -CFLAGS "-O2 -DCACHED -I$(CURDIR)" -Mdir $(CACHED_OBJ) \
	  tb_top.sv $(CACHED_RTL) tb_r3900.cpp

# The core, its caches and the board's address decode together.
BOARD_RTL := ../../rtl/cpu/r3900.sv ../../rtl/cpu/r3900_cache.sv ../../rtl/board/dr840_mem.sv
BOARD_OBJ := obj_board

board: $(BOARD_OBJ)/Vtb_board

$(BOARD_OBJ)/Vtb_board: $(BOARD_RTL) tb_board.sv tb_board.cpp goldtrace.h
	$(VERILATOR) --cc --exe --build -j 0 -Wall -Wno-fatal \
	  +define+SIMULATION --top-module tb_board \
	  -CFLAGS "-O2 -I$(CURDIR)" -Mdir $(BOARD_OBJ) \
	  tb_board.sv $(BOARD_RTL) tb_board.cpp

# The first million ROM instructions through every harness. This exists
# because the board harness sat broken for several commits -- an input left
# unconnected when a port was added -- and nothing ran it. Anything that
# builds a harness should also run it.
ROM ?= ../../../magicrecomp/roms/Data Rover 840/DataRover-840-USA.image
check: all cached board
	@echo "== bare core ==";    ./$(OBJ)/V$(TOP) --state ../golden/reset-1m.trc --bus ../golden/reset-1m.bus --rom "$(ROM)" | tail -1
	@echo "== with caches =="; ./$(CACHED_OBJ)/Vtb_top --state ../golden/reset-1m.trc --bus ../golden/reset-1m.bus --rom "$(ROM)" | tail -1
	@echo "== with board ==";  ./$(BOARD_OBJ)/Vtb_board --state ../golden/reset-1m.trc --bus ../golden/reset-1m.bus --rom "$(ROM)" | tail -1

clean:
	rm -rf $(OBJ) $(CACHED_OBJ) $(BOARD_OBJ)

.PHONY: all run clean cached board check
