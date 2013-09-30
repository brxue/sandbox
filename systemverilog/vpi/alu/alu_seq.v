module test;

	integer a, b, c, type;
	
    initial begin
        $dumpfile("alu_cb.vcd");
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
		repeat (5)@(posedge clk);
		rst <= 0;
	end
	
	initial begin
		repeat(30) @(posedge clk);
		$finish;
	end
	
	initial begin
		// whenever a/b/type gets changed, a PLI callback function will be executed
		$alu(clk, a,b,type,c);
	end
	
	integer c_golden;
	always @(posedge clk)
	begin
		if (rst)
		begin
			a <= 0;
			b <= 0;
			type <= 0;
			c_golden <= 0;
		end else 
		begin
			a <= a + 1;
			b <= b + 2;
			type <= 0;
			c_golden <= a + b;
		end
	end
	
	integer c_q;
	always @(posedge clk)
		c_q <= c;
	
	always @(posedge clk)
	begin
		if (c_golden != c_q)
			$display("ERROR@%0t: expected = %d, actual = %d", $time, c_golden, c);
	end

endmodule
