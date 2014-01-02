module test;
	import uvm_pkg::*;
    `include "uvm_macros.svh"

	class packet;
		int i;
		function new(int v); i=v; endfunction
	endclass

	class producer extends uvm_component;
		uvm_put_port #(packet) data_out;
		
		function new(string name, uvm_component parent);
			super.new(name,parent);
			data_out = new("data_out", this);
		endfunction
		
		task run_phase(uvm_phase phase);
			packet p;
			int i = 0;
			while(i < 10) begin 
				p = new(i);
				data_out.put(p);
				$display("%0t: put data %0d", $time, p.i);
				i++;
				#10; // producer is faster than consumer
			end
		endtask
	endclass

	class consumer extends uvm_component;
		uvm_get_port #(packet) data_in;
		function new(string name, uvm_component parent);
			super.new(name,parent);
			data_in = new("data_in", this);
		endfunction
    
		task run_phase(uvm_phase phase);
			packet p;
			int i = 0;

			while(i < 10) begin
				data_in.get(p);
				$display("%0t: recieved data %0d", $time, p.i);
				assert(p.i == i); // assert that data is received as the sequence they are put to the fifo
				i++;
				#20; // consumer is slower than producer
			end
		endtask
	endclass

	
	// A dummy test
	class test extends uvm_test;

		`uvm_component_utils(test)

		function new(string name = "", uvm_component parent = null);
			super.new(name, parent);
		endfunction

		task run_phase(uvm_phase phase);
			phase.raise_objection(null);
			#5us; // run for 5us
			phase.drop_objection(null);
		endtask
	endclass

	producer prod = new("prod", null);
	consumer cons = new("cons", null);
	uvm_tlm_fifo #(packet) fifo = new("fifo", null, 5); // fifo depth is 5, it's sure that fifo will be full

	initial begin
		prod.data_out.connect(fifo.put_export);
		cons.data_in.connect(fifo.get_export);

		run_test("test");
	end

endmodule
