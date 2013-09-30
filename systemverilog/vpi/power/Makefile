vvp: iverilog power.vpi
	vvp -M. -mpower power

iverilog: power.v
	iverilog -o power power.v

power.o: power.cpp
	g++ -fPIC -c -g -I ${IVERILOG_HOME}/include/iverilog power.cpp

power.vpi: power.o
	iverilog-vpi $^

gdb_vvp: iverilog power.vpi
	gdb --args vvp -M. -mpower power

gdb_coredump: 
	gdb power.o core

gdb_coredump1:
	gdb vvp core

clean:
	rm -fr power power.o power.vpi core.*
