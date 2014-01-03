import uvm_pkg::*;
`include "uvm_macros.svh"

class A extends uvm_component;
	int i;
	function new(string name, uvm_component p);
		super.new(name, p);
		i = 10;
	endfunction

	function void build_phase(uvm_phase phase);
		super.build_phase(phase);

		// get the config value from resource database
		assert(get_config_int("i", i)==1);
	endfunction

	`uvm_field_utils_begin(A)
		`uvm_field_int(i, UVM_DEC)
	`uvm_field_utils_end
endclass

class B extends uvm_component;
	A a;
	string s;
	function new(string name, uvm_component p);
		super.new(name, p);
		s = "Hello World!";
	endfunction
	
	function void build_phase(uvm_phase phase);
		super.build_phase(phase);
		a = new("ua", this);

		// get the config value from resource database
		assert(get_config_string("s", s) == 1);
	endfunction

	`uvm_field_utils_begin(B)
		`uvm_field_string(s, UVM_DEC)
	`uvm_field_utils_end
endclass

class C extends uvm_component;
	B b;
	logic [5:0] l;
	function new(string name, uvm_component p);
		super.new(name, p);
		l = 6'h6;
	endfunction
	
	function void build_phase(uvm_phase phase);
		super.build_phase(phase);
		b = new("ub", this);
	endfunction

	`uvm_field_utils_begin(C)
		`uvm_field_int(l, UVM_HEX)
	`uvm_field_utils_end
endclass

class env extends uvm_env;
	C c1;
	C c2;
	function new(string name, uvm_component p);
		super.new(name, p);
	endfunction

	function void build_phase(uvm_phase phase);
		super.build_phase(phase);
		c1 = new("uc1", this);
		c2 = new("uc2", this);
	endfunction

	task run_phase(uvm_phase phase);
		phase.raise_objection(this);
		#10;
		phase.drop_objection(this);
	endtask
endclass

module test;
	env e;

	import uvm_pkg::*;

	initial begin
		// uvm_top.print_topology() will be called automatically at the end of run_test
		uvm_top.enable_print_topology = 1;

		set_config_int("uenv.uc1.*", "i", 11);
		set_config_string("uenv.uc2.ub", "s", "Hello ASIC!");

		e = new("uenv", null);
		run_test();
	end
endmodule
