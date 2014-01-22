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


module test;
	A a;
	B b;

	initial 
	begin
		a = new("uA"); // component with null parent will be added to uvm_top automatically
		b = new("uB");
		run_test();
	end
endmodule

