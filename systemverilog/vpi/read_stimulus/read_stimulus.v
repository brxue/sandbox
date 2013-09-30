module test;
	
	initial begin
		$dumpfile("read_stimulus.vcd");
		$dumpvars(0, test);
	end
	
	reg clk;
	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end
	
	initial begin
		repeat (20)@(posedge clk);
		$finish;
	end
	
	reg [31:0] bus1;
	always @(posedge clk)
		$read_stimulus("data1.txt", bus1);
	
	reg [31:0] bus2;
	always @(posedge clk)
		$read_stimulus("data2.txt", bus2);

	reg [31:0] bus1_tmp, bus2_tmp;
	always @*
	begin
		bus1_tmp = bus1;
		bus2_tmp = bus2;
	end

	reg [31:0] bus1_q, bus2_q;
	always @(posedge clk)
	begin
		bus1_q <= bus1_tmp;
		bus2_q <= bus2_tmp;
	end

endmodule
