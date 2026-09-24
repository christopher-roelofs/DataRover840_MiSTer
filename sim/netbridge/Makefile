VERILATOR ?= verilator
OBJ := obj_dir
RTL := ../../rtl/soc/dr840_ne2000.sv ../../rtl/dr840_netbridge.sv
all: $(OBJ)/Vtb_net
$(OBJ)/Vtb_net: $(RTL) tb_net.sv tb_net.cpp
	$(VERILATOR) --cc --exe --build -j 0 -Wno-fatal --top-module tb_net -Mdir $(OBJ) -CFLAGS "-O2" tb_net.sv $(RTL) tb_net.cpp
run: $(OBJ)/Vtb_net
	./$(OBJ)/Vtb_net 1
clean:
	rm -rf $(OBJ)
.PHONY: all run clean
