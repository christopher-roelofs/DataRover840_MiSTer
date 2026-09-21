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
          -Wall -Wno-fatal \
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

clean:
	rm -rf $(OBJ)

.PHONY: all run clean
