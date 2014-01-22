import uvm_pkg::*;

class A extends uvm_component;
	function new(string name);
		super.new(name, null);
	endfunction

	task run_phase(uvm_phase phase);
		$display("A::run_phase HELLO A.");
	endtask
endclass

class B extends uvm_component;
	function new(string name);
		super.new(name, null);
	endfunction

	task run_phase(uvm_phase phase);
		$display("B::run_phase HELLO B.");
	endtask
endclass

class C extends uvm_component;
	
	`include "uvm_macros.svh"

	// register C into the factory
	`uvm_component_utils(C);

	function new(string name, uvm_component parent = null);
		super.new(name, null);
	endfunction

	task run_phase(uvm_phase phase);
		$display("C::run_phase HELLO C.");
	endtask
endclass

module test;
	A a;
	B b;

	initial begin
		a = new("uA");
		b = new("uB");
		
		// C must be registered with the factory to be created within run_test
		run_test("C");
	end
endmodule

