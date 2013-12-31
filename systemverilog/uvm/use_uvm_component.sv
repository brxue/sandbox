package pkg;
	import uvm_pkg::*;
	`include "uvm_macros.svh"
	
	class component_A extends uvm_component;
		function new(string name, uvm_component parent);
	  	  super.new(name, parent);
	  	endfunction
	
	  	task run_phase(uvm_phase phase);
	  	  phase.raise_objection(this);
		  for (int i=0; i<10; i++)
			`uvm_info("component_A says", "hello!", UVM_MEDIUM)
	  	  phase.drop_objection(this);
	  	endtask
	endclass

	class component_B extends uvm_component;
		function new(string name, uvm_component parent);
	  	  super.new(name, parent);
	  	endfunction
	
	  	task run_phase(uvm_phase phase);
	  	  phase.raise_objection(this);
		  for (int i=0; i<5; i++)
			`uvm_info("component_B says", "hi!", UVM_MEDIUM)
	  	  phase.drop_objection(this);
	  	endtask
	endclass

	class component_TOP extends uvm_component;
		component_A a;
		component_B b;

		function new(string name, uvm_component parent);
	  	  super.new(name, parent);
		  a = new("compa", this);
		  b = new("compb", this);
	  	endfunction
	
	  	task run_phase(uvm_phase phase);
	  	  phase.raise_objection(this);
		  for (int i=0; i<2; i++)
			`uvm_info("component_TOP says", "hello out there!", UVM_MEDIUM)
			#0; // remove the objection race at time zero
	  	  phase.drop_objection(this);
	  	endtask
	endclass
endpackage

module test;
	import uvm_pkg::*;
   	import pkg::*;
   	component_TOP t;
   	
   	initial begin
		uvm_top.enable_print_topology = 1;
		t = new("Top", null);
   	   	run_test();
   	end
endmodule // test

