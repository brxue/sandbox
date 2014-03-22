vlib:
	vlib work

vlog: vlib
	vlog test.sv

vsim: vlog
	vsim -do "run -all" test

clean:
	rm -fr transcript work
