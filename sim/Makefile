OUT=out
TOP=tb_top

ROOT=$(abspath $(CURDIR)/..)

SRC=$(ROOT)/rtl/top/top.sv \
    $(ROOT)/rtl/top/imem.sv \
    $(ROOT)/rtl/top/dmem.sv \
    $(ROOT)/rtl/core/core.sv \
    $(ROOT)/tb/tb_top.sv \
    $(ROOT)/tb/assertions/arch_sva.sv \
    $(ROOT)/tb/scoreboard/scoreboard.sv

all: test

test:
	mkdir -p $(OUT)
	verilator --timing -Wno-fatal --cc --exe --build \
	  --top-module $(TOP) \
	  -Mdir $(OUT) \
	  $(SRC) main.cpp
	./$(OUT)/V$(TOP)


clean:
	rm -rf $(OUT)
