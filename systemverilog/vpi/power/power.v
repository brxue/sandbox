module top;

integer a, b, c;

initial
	begin
		$display("$power(%0d, %0d) = %0d", 2, 3, $power(2,3));
		$display("$power(%0d, %0d) = %0d", 3, 4, $power(3,4));

		a = 2;
		b = 10;
		$display("$power(%0d, %0d) = %0d", a, b, $power(a,b));

	end

endmodule

