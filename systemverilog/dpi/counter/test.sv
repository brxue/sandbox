module top;
	import "DPI-C" context function chandle counter_new();
	import "DPI-C" context function void counter_reset(chandle inst);
	import "DPI-C" context function void counter_load(chandle inst, byte unsigned);
	import "DPI-C" context function byte unsigned counter_get(chandle inst);
	import "DPI-C" context function void counter_cycle(chandle inst);

	chandle inst = counter_new();

	initial begin
		counter_reset(inst);
		counter_load(inst, 10);
	end

	bit clk;
	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end

	byte unsigned cnt;
	always @(posedge clk) begin
		counter_cycle(inst);
		cnt = counter_get(inst);
	end
endmodule

