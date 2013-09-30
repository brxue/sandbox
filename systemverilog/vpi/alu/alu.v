module test;

	integer a, b, c, type;
	
    initial begin
        $dumpfile("alu.vcd");
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
	
	integer c_q;
	always @(posedge clk)
	begin
		$alu(a,b,type,c); // 'c' is writter with 'vpiNoDelay in alu_calltf, when exit $alu(), the updated 'c' is already available.
		$display("@%3t, a=%2d, b=%2d, type=%2d, c=%2d",$time, a,b,type, c);
		c_q <= c; // use the updated 'c'
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
	
	// Note: the value of wrong_c_q is not correct, the RHS 'c' is evaluated
	// at active region, LHS is assigned at NBA region.
	// $alu() is also evaluated at active region, but whether '$alu() ' is
	// evaluated before 'c' is non-determined.
	integer wrong_c_q;
	always @(posedge clk)
		wrong_c_q <= c;
	
	// Note: this is an workaround for geting a correct register-ed c
	// c is updated by $alu
	integer correct_c_q;
	integer temp_c;
	always @* temp_c = c; // whenever c gets upated, temp_c is re-calculated. The always process here and $alu are all executed in active region
	always @(posedge clk)
		correct_c_q <= temp_c; // register temp_c will give the right result

	always @(posedge clk)
	begin
		if (c_golden != c_q)
			$display("ERROR@%0t: expected = %d, actual = %d", $time, c_golden, c);
	end

endmodule
