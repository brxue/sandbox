module top;
	import "DPI-C" context function void c_display();
	
	// YES, these 3 instances will all export a function named as sv_display
	// At C side, which sv_display will be called?
	sub u_sub1();
	sub u_sub2();
	another_sub u_sub3();

	initial begin
		// By default, simulator assume that sv_display should be defined in the same scope where c_display is called, since we do not define a sv_display in the scope of our top module, the simulator will report run-time error.
		// But we can tell simulator explicitly where to find sv_display by using SV DPI utilities
		c_display();
	end
endmodule

module sub;
	export "DPI-C" function sv_display;
	function void sv_display();
		$display("Calling sv_display in %m.");
	endfunction
endmodule

module another_sub;
	export "DPI-C" function sv_display;
	function void sv_display();
		$display("Calling sv_display in %m.");
	endfunction
endmodule
