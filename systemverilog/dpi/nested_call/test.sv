// Simple example that contains nested DPI task and function calls.
module top;

	int square;
	
	bit clk;
	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end
	
	// Import decls define name in the current scope, like native tf declarations.
	// Prototype parameters are required in ordre to define C function's interface.
	import "DPI-C" context task CTask(input int i);
	import "DPI-C" context function int CFunction(input int i);
	
	// Export decls must match a name in the current scope.
	// All exported tf's are context by nature.
	export "DPI-C" task SVTask;
	export "DPI-C" function SVFunction;
	
	// Exported SV task.  Can be called by either C or SV.
	task SVTask(input int loop);
	begin
	    $display("\tIn SVTask");
		for (int i=0; i<loop; i=i+1) begin
			@(posedge clk)
				square <= CFunction(i);
		end
	end
	endtask
	
	// Exported SV function.  Can be called by either C or SV.
	function int SVFunction(input int i);
	begin
	    $display("\t\t\tIn SVFunction");
	    SVFunction = i * i;
	end
	endfunction
	
	// Call imported C task
	initial begin
		CTask(10); // The imported CTask calls the exported SVTask   
		           // The SVTask calls the imported CFunction
		           // The imported CFunction calls the exported SVFunction
		$finish;
	end

	/* The output will be as following
	
	In CTask
	 	In SVTask
	 		In CFunction
	 			In SVFunction
	 		In CFunction
	 			In SVFunction
	 		In CFunction
	 			In SVFunction
	 		In CFunction
	 			In SVFunction
	 		In CFunction
	 			In SVFunction
	 		In CFunction
	 			In SVFunction
	 		In CFunction
	 			In SVFunction
	 		In CFunction
	 			In SVFunction
	 		In CFunction
	 			In SVFunction
	 		In CFunction
	 			In SVFunction
	*/
endmodule
