# The LCD controller's scanout, against the framebuffer it scans.
VERILATOR ?= verilator
RTL := ../../rtl/soc/dr840_lcd.sv
OBJ := obj_dir

all: $(OBJ)/Vtb_lcd

$(OBJ)/Vtb_lcd: $(RTL) tb_lcd.sv tb_lcd.cpp
	$(VERILATOR) --cc --exe --build -j 0 -Wall -Wno-fatal \
	  --top-module tb_lcd -Mdir $(OBJ) -CFLAGS "-O2" \
	  tb_lcd.sv $(RTL) tb_lcd.cpp

run: $(OBJ)/Vtb_lcd
	./$(OBJ)/Vtb_lcd

clean:
	rm -rf $(OBJ)

.PHONY: all run clean
