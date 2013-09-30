vvp: iverilog read_stimulus.vpi
	vvp -M. -mread_stimulus read_stimulus

iverilog: read_stimulus.v
	iverilog -o read_stimulus read_stimulus.v

read_stimulus.o: read_stimulus.cpp
	g++ -fPIC -c -g -I ${IVERILOG_HOME}/include/iverilog read_stimulus.cpp

read_stimulus.vpi: read_stimulus.o
	iverilog-vpi $^

gdb: iverilog read_stimulus.vpi
	gdb --args vvp -M. -mread_stimulus read_stimulus

gtkwave: vvp
	gtkwave read_stimulus.vcd

clean:
	rm -fr read_stimulus.vcd read_stimulus read_stimulus.o read_stimulus.vpi core.*
