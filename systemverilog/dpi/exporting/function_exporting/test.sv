module top;
	import "DPI-C" context function void C_main();
	export "DPI-C" function SV_get_simulation_time;

	function int unsigned SV_get_simulation_time();
		return $time;
	endfunction

	initial begin
		for (int i=0; i<10; i++) begin
			C_main();
			#10;
		end
	end

endmodule
