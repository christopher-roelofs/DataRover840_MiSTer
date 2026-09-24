# The NE2000 against the reference emulator's model of it.
VERILATOR ?= verilator
REF ?= ../../../magicrecomp
OBJ := obj_dir

all: $(OBJ)/Vdr840_ne2000

$(OBJ)/Vdr840_ne2000: ../../rtl/soc/dr840_ne2000.sv tb_ne2000.cpp
	$(VERILATOR) --cc --exe --build -j 0 -Wall -Wno-fatal \
	  --top-module dr840_ne2000 -Mdir $(OBJ) -CFLAGS "-O2 -I$(abspath $(REF))/src" \
	  ../../rtl/soc/dr840_ne2000.sv tb_ne2000.cpp $(abspath $(REF))/src/devices/ne2000/ne2000.c

run: $(OBJ)/Vdr840_ne2000
	./$(OBJ)/Vdr840_ne2000 1 400

clean:
	rm -rf $(OBJ)

.PHONY: all run clean
