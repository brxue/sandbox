TEST ?= test.sv

vsim: vlog
	vsim -do "run -all; q" test

vlog: vlib $(TEST)
	vlog $(TEST)

vlib: 
	test -d work || vlib work

clean: 
	rm -fr *.wlf work transcript
