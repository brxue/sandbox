`timescale 1ns/1ns

module test;

initial begin
	$dumpfile("alu_sim.vcd");
	$dumpvars(0, test);
end

reg clk;
initial begin
	clk = 0;
	forever #5 clk = ~clk;
end

reg rst;
initial begin
	rst <= 1;
	repeat(5)@(posedge clk);
	rst <= 0;

	repeat(100)@(posedge clk);
	$finish;
end

integer a, b, type, out;
always @(posedge clk)
begin
	if (rst)
	begin
		a <= 0;
		b <= 0;
		type <= 0;
	end else
	begin
		a <= a + 1;
		b <= b + 2;
	end
end

initial
	$alu(clk, rst, a, b, type, out);

integer out_q;
always @(posedge clk)
	out_q <= out;

endmodule

