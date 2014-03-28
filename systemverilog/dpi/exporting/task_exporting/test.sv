module top;
	import "DPI-C" context task C_main();
	export "DPI-C" function SV_get_simulation_time;
	export "DPI-C" task SV_at_posedge_clk;

	function int unsigned SV_get_simulation_time();
		return $time;
	endfunction
	
	bit clk;
	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end

	task SV_at_posedge_clk();
		@(posedge clk);
	endtask

	initial begin
		C_main();
		$finish;
	end

endmodule
