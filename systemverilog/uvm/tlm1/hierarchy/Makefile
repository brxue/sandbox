#ifeq ($(TEST),) # if variable TEST is empty
#$(info Usage: make TEST=blocking.)
#$(error variable TEST must be specified in the command line.)
#endif

vsim: vlog
	vsim -do "run -all; q" test

vlog: vlib test.sv
	vlog test.sv

vlib: 
	test -d work || vlib work

clean: 
	rm -fr work transcript
