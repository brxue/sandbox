vlib: 
	test -d work || vlib work

vlog: vlib
	vlog test.sv

vsim: vlog
	vsim -do "run -all; q" test

clean: 
	rm -fr work transcript
