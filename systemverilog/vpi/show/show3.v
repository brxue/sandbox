module dflop (clk, rst, d, q);
	input clk, rst;
	input [3:0] d;
	output [3:0] q;
	
	reg [3:0] q;
	integer i;
	time t;
	real r;

	always @(posedge clk)
	begin
		if (rst) 
		begin
			q <= 0;
			i <= 0;
			t <= 0;
			r <= 0.1;
		end else 
		begin
			q <= d;
			i <= i + 1;
			t <= $time;
			r <= r + 1;
		end
	end
endmodule

module test;
	reg clk, rst;
	reg [3:0] d;
	wire [3:0] q;

	initial clk = 0;
	always #5 clk = ~clk;
	
	always @(posedge clk)
	begin: d_generator
		integer test;
		test <= 20;
		$show;
		if (rst)
			d <= 0;
		else
			d <= d + 1;
	end
	
	dflop u_dflop (clk, rst, d, q);

	initial begin
		rst <= 1;
		repeat(5)@(posedge clk);
		rst <= 0;
		#100;
		$finish;
	end
endmodule

