vlib: 
	test -d work || vlib work

vlog: vlib
	vlog use_uvm_component.sv

vsim: vlog
	vsim -do "run -all; q" test

clean: 
	rm -fr work transcript
