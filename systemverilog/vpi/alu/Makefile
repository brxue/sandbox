all:
	@echo "Usage:"
	@echo "	make alu"
	@echo "	make alu_cb"
	@echo "	make alu_comb"
	@echo "	make alu_seq"

alu: alu.out alu.vpi
	vvp -M. -malu alu.out

alu.out: alu.v
	iverilog -o $@ $^

alu.o: alu.cpp
	g++ -fPIC -c -g -I ${IVERILOG_HOME}/include/iverilog $^

alu.vpi: alu.o
	iverilog-vpi $^

gdb_alu: alu.out alu.vpi
	gdb --args vvp -M. -malu alu

gtkwave_alu: alu
	gtkwave alu.vcd


###############################################################

alu_cb: alu_cb.out alu_cb.vpi
	vvp -M. -malu_cb alu_cb.out

alu_cb.out: alu_cb.v
	iverilog -o $@ $^

alu_cb.o: alu_cb.cpp
	g++ -fPIC -c -g -I ${IVERILOG_HOME}/include/iverilog $^

alu_cb.vpi: alu_cb.o
	iverilog-vpi $^

gdb_alu_cb: alu_cb.out alu_cb.vpi
	gdb --args vvp -M. -malu_cb alu_cb

gtkwave_alu_cb: alu_cb
	gtkwave alu_cb.vcd

###############################################################

alu_comb: alu_comb.out alu_comb.vpi
	vvp -M. -malu_comb alu_comb.out

alu_comb.out: alu_comb.v
	iverilog -o $@ $^

alu_comb.o: alu_comb.cpp
	g++ -fPIC -c -g -I ${IVERILOG_HOME}/include/iverilog $^

alu_comb.vpi: alu_comb.o
	iverilog-vpi $^

gdb_alu_comb: alu_comb.out alu_comb.vpi
	gdb --args vvp -M. -malu_comb alu_comb

gtkwave_alu_comb: alu_comb
	gtkwave alu_cb.vcd

##############################################################

alu_seq: alu_seq.out alu_seq.vpi
	vvp -M. -malu_seq alu_seq.out

alu_seq.out: alu_seq.v
	iverilog -o $@ $^

alu_seq.o: alu_seq.cpp
	g++ -fPIC -c -g -I ${IVERILOG_HOME}/include/iverilog $^

alu_seq.vpi: alu_seq.o
	iverilog-vpi $^

gdb_alu_seq: alu_seq.out alu_seq.vpi
	gdb --args vvp -M. -malu_seq alu_seq

gtkwave_alu_seq: alu_seq
	gtkwave alu_cb.vcd

clean:
	rm -fr alu*.vcd alu*.out alu*.o alu*.vpi core.*
