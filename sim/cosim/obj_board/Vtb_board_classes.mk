# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vtb_board.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 0
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 0
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vtb_board \
	Vtb_board___024root__DepSet_he0b4e075__0 \
	Vtb_board___024root__DepSet_h11c18119__0 \
	Vtb_board_tb_board__DepSet_h12112e9c__0 \
	Vtb_board_r3900_cached__Cz1__DepSet_h0851a39b__0 \
	Vtb_board_r3900__Cz2__DepSet_h179e57d0__0 \
	Vtb_board_r3900__Cz2__DepSet_hde9acdbe__0 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vtb_board__ConstPool_0 \
	Vtb_board___024root__Slow \
	Vtb_board___024root__DepSet_he0b4e075__0__Slow \
	Vtb_board___024root__DepSet_h11c18119__0__Slow \
	Vtb_board_tb_board__Slow \
	Vtb_board_tb_board__DepSet_he41dc672__0__Slow \
	Vtb_board_r3900_cached__Cz1__Slow \
	Vtb_board_r3900_cached__Cz1__DepSet_h0851a39b__0__Slow \
	Vtb_board_r3900_cached__Cz1__DepSet_hfa5e4177__0__Slow \
	Vtb_board_r3900__Cz2__Slow \
	Vtb_board_r3900__Cz2__DepSet_h179e57d0__0__Slow \
	Vtb_board_r3900__Cz2__DepSet_hde9acdbe__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Vtb_board__Dpi \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vtb_board__Syms \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_dpi \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
