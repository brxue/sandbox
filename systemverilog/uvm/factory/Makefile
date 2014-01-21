vsim: vlog
	vsim -do "run -all; q" test

vlog: vlib test.sv
	vlog test.sv

vlib: 
	test -d work || vlib work

clean: 
	rm -fr *.wlf work transcript
