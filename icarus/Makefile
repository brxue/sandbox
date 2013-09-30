iverilog: hello.v
	iverilog -o hello hello.v

vvp: iverilog
	vvp hello

gtkwave: hello.vcd
	gtkwave hello.vcd

help_iverilog: 
	man iverilog

help_vvp: 
	man vvp

clean: 
	rm -fr hello hello.vcd
