all:
	@echo "Usage: "
	@echo "	make show1"
	@echo "	make show2"
	@echo "	make show3"

show1: show1.out show.vpi
	vvp -M. -mshow show1.out
show2: show2.out show.vpi
	vvp -M. -mshow show2.out
show3: show3.out show.vpi
	vvp -M. -mshow show3.out

show1.out: show1.v
	iverilog -o show1.out show1.v
show2.out: show2.v
	iverilog -o show2.out show2.v
show3.out: show3.v
	iverilog -o show3.out show3.v

show.o: show.cc
	g++ -fPIC -c -g -I ${IVERILOG_HOME}/include/iverilog show.cc

show.vpi: show.o
	iverilog-vpi $^

gdb1: show1.out show.vpi
	gdb --args vvp -M. -mshow show1.out
gdb2: show2.out show.vpi
	gdb --args vvp -M. -mshow show2.out
gdb: show3.out show.vpi
	gdb --args vvp -M. -mshow show3.out

clean:
	rm -fr show show.o show.vpi show1.out show2.out show3.out core.*
