module top;
	import "DPI-C" function void c_bit(input bit i, output bit o);
	import "DPI-C" function void c_bit_vector(input bit[39:0] i, output bit[39:0] o);
	
	bit o_bit;
	bit [39:0] o_bit_vector;

	initial begin
		c_bit(1'b0, o_bit);
		c_bit_vector(40'h912345678, o_bit_vector);
	end
endmodule
