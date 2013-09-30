all:
	@echo "Usage:"
	@echo "	make alu_emu"
	@echo "	make alu_sim"

alu_emu: alu.emu
	./alu.emu
alu_sim: alu.sim alu_pli.vpi
	vvp -M. -malu_pli alu.sim

# library options must behind 'tb_alu.cpp', or else ld can't find the systemc and alu shared library
alu.emu: libalu.so tb_alu.cpp
	g++ -I$(SYSTEMC_HOME)/include -I. tb_alu.cpp -L. -lalu -Wl,-rpath,. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath,$(SYSTEMC_HOME)/lib-linux64 -lsystemc -o $@

alu.sim: alu.v
	iverilog -o $@ $^
#alu_pli.vpi: alu_pli.o
#	iverilog-vpi $^ $(SYSTEMC_HOME)/lib-linux64/libsystemc.a
alu_pli.vpi: alu_pli.cpp libalu.so
	g++ -fPIC -g -shared -I$(SYSTEMC_HOME)/include -I $(IVERILOG_HOME)/include/iverilog $< -L$(IVERILOG_HOME)/lib/ -lvpi -Wl,-rpath,$(SYSTEMC_HOME)/lib-linux64 -L$(SYSTEMC_HOME)/lib-linux64 -lsystemc -Wl,-rpath,. -L. -lalu -o $@
gdb_sim: alu.sim
	gdb --args vvp -M. -malu_pli alu.sim

libalu.so: alu.cpp
	g++ -fPIC -g -shared -I. -I$(SYSTEMC_HOME)/include  $^ -Wl,-rpath,$(SYSTEMC_HOME)/lib-linux64 -L$(SYSTEMC_HOME)/lib-linux64 -lsystemc -o $@

gtkwave: alu.vcd
	gtkwave $^

gtkwave_sim: alu_sim.vcd
	gtkwave $^

clean:
	rm -fr *.vcd a.out libalu.so *.vpi *.o alu.sim alu.emu
