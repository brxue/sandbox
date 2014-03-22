module hello;

	reg clk;
	reg [3:0] d, q;
	always @(posedge clk) q <= d;

	initial begin
		d = 0;
		repeat(16)@(posedge clk) begin
			d <= d + 1;
			$display("cycle %d", d);
		end
		$finish;
	end

	initial clk = 0;
	always #5 clk = ~clk;

endmodule

