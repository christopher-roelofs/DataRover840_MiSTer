# The whole memory path, against a model of the SDRAM chip that checks the
# controller as it goes.
VERILATOR ?= verilator
RTL := ../../rtl/cpu/r3900.sv ../../rtl/cpu/r3900_cache.sv \
       ../../rtl/board/dr840_mem.sv ../../rtl/board/dr840_sdram.sv \
       ../../rtl/board/sdram.sv ../../rtl/soc/dr840_tx39.sv ../../rtl/soc/dr840_sib.sv ../../rtl/soc/dr840_pen.sv ../../rtl/soc/dr840_lcd.sv models/sdram_mt48lc16m16a2.v models/altddio_out.v
OBJ := obj_dir
N ?= 0
ROM ?= ../../../magicrecomp/roms/Data Rover 840/DataRover-840-USA.image

all: $(OBJ)/Vtb_sdram

$(OBJ)/Vtb_sdram: $(RTL) tb_sdram.sv tb_sdram.cpp ../cosim/goldtrace.h
	$(VERILATOR) --cc --exe --build -j 0 -Wall -Wno-fatal \
	  --top-module tb_sdram -Mdir $(OBJ) \
	  -CFLAGS "-O2 -I$(CURDIR) -I$(CURDIR)/../cosim" \
	  tb_sdram.sv $(RTL) tb_sdram.cpp

run: $(OBJ)/Vtb_sdram
	./$(OBJ)/Vtb_sdram --state ../golden/reset-1m.trc \
	                   --bus ../golden/reset-1m.bus --rom "$(ROM)" -n $(N)

clean:
	rm -rf $(OBJ)

.PHONY: all run clean
