module cpu(
	input clk, 
	output logic [31:0] addr,wrdata, 
	output logic wr, 
	input logic [31:0] rddata
);

	import "DPI-C" context task C_main();
	export "DPI-C" task read_mem;
	export "DPI-C" task write_mem;

	task read_mem(input int unsigned a, output int d);
		@(posedge clk);
		addr <= a;
		wr <= 0;
		@(posedge clk);
		// data phase
		@(posedge clk);
		d = rddata; // should investigate why it will return incorrect value if non-blocking assignment is used here
	endtask

	task write_mem(input int unsigned a, input int d);
		@(posedge clk);
		addr <= a;
		wrdata <= d;
		wr <=1;
	endtask

	initial begin
		addr = 0;
		wrdata = 0;
		wr = 0;

		C_main();
	end
endmodule

module memory(
	input clk, 
	input logic [31:0] addr,wrdata, 
	input logic wr, 
	output logic [31:0] rddata
);
	
	logic [31:0] mem[0:15];

	always @(posedge clk) begin
		if (wr) begin
			mem[addr] <= wrdata;
		end
		else begin
			rddata <= mem[addr];
		end
	end
endmodule

module top;
	bit clk;
	initial begin
		clk = 0;
		forever #5 clk = ~clk;
	end

	logic [31:0] addr,wrdata; 
	logic wr;
	logic [31:0] rddata;

	cpu u_cpu(.*);
	memory u_memory(.*);

	initial begin
		#200;
		$finish;
	end

endmodule
