# The codec's answers to the pen driver's questions, against the reference's.
all: obj_dir/Vdr840_sib
obj_dir/Vdr840_sib: ../../rtl/soc/dr840_sib.sv tb_sib.cpp
	verilator --cc --exe --build -j 0 -Wno-fatal --top-module dr840_sib -Mdir obj_dir ../../rtl/soc/dr840_sib.sv tb_sib.cpp
run: obj_dir/Vdr840_sib
	./obj_dir/Vdr840_sib
clean:
	rm -rf obj_dir
.PHONY: all run clean
