vvp: iverilog hello.vpi
	vvp -M. -mhello hello

iverilog: hello.v
	iverilog -o hello hello.v

hello.o: hello.cpp
	g++ -fPIC -c -g -I ${IVERILOG_HOME}/include/iverilog hello.cpp

hello.vpi: hello.o
	iverilog-vpi $^

gdb: iverilog hello.vpi
	gdb --eval-command 'b compile_design' --eval-command 'run' --eval-command 'info share' --args vvp -M ./ -mhello hello

clean:
	rm -fr hello hello.o hello.vpi
