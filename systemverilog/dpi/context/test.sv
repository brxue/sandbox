// Import c_display in two different scopes, the corresponding C code executes in the context of where the import statement occurred. 
// This is similar to defining a SystemVerilog task in each of two separate moduels with same name, each task accesses variables in its own module, with no ambiguity.

module top;
	import "DPI-C" context function void c_display();
	export "DPI-C" function sv_display;

	function void sv_display();
		$display("sv_display: %m");
	endfunction

	initial
		c_display(); // will call the sv_display in the current scope

	sub u_sub1();
	sub u_sub2();
endmodule

module sub;
	import "DPI-C" context function void c_display();
	export "DPI-C" function sv_display;

	function void sv_display();
		$display("sv_display: %m");
	endfunction

	initial
		c_display(); // will call the sv_display in the current scope
endmodule
