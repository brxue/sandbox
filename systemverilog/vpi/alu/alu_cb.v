module test;

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
		$display("Simulation finished.");
		$finish;
	end
	
	integer a1, b1, c1, type1;
	always @(posedge clk)
		$alu(a1,b1,type1,c1); // $alu is scheduled to end of current time step, where a1 and b1 had been updated to the latest value.
	
	integer a2, b2, c2, type2;
	always @(posedge clk)
		$alu(a2,b2,type2,c2);

	integer c1_golden;
	integer c2_golden;
	always @(posedge clk)
	begin
		if (rst)
		begin
			a1 <= 0;
			b1 <= 0;
			type1 <= 0;
			c1_golden <= 0;

			a2 <= 0;
			b2 <= 0;
			type2 <= 0;
			c2_golden <= 0;
		end else 
		begin
			a1 <= a1 + 1;
			b1 <= b1 + 2;
			type1 <= 0;
			c1_golden <= a1 + b1;
			
			a2 <= a2 + 3;
			b2 <= b2 + 4;
			type2 <= 0;
			c2_golden <= a2 + b2;
		end
	end
	
	integer c1_q;
	integer c2_q;
	always @(posedge clk)
	begin
		c1_q <= c1;
		c2_q <= c2;
	end
	
	always @(posedge clk)
	begin
		if (~rst)
		begin
			if (c1_golden != c1_q)
				$display("ERROR@%0t: expected c1_golden = %d, actual c1_q = %d", $time, c1_golden, c1_q);
			if (c2_golden != c2_q)
				$display("ERROR@%0t: expected c2_golden = %d, actual c2_q = %d", $time, c2_golden, c2_q);
		end
	end

endmodule
