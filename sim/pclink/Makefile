# The package link against a port of the reference's PC side.
VERILATOR ?= verilator
OBJ := obj_dir
PKG ?= ../../../magicrecomp/packages/DvorakKeyboard.pkg

all: $(OBJ)/Vdr840_pclink

$(OBJ)/Vdr840_pclink: ../../rtl/soc/dr840_pclink.sv tb_pclink.cpp
	$(VERILATOR) --cc --exe --build -j 0 -Wall -Wno-fatal \
	  --top-module dr840_pclink -Mdir $(OBJ) -CFLAGS "-O2" \
	  ../../rtl/soc/dr840_pclink.sv tb_pclink.cpp

run: $(OBJ)/Vdr840_pclink
	./$(OBJ)/Vdr840_pclink "$(PKG)"

clean:
	rm -rf $(OBJ)

.PHONY: all run clean
