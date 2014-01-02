/*
 -----------------------------------------------------------------------------------------------------------------------
|                                                                                                                       |
|   ----------------------------------------------------------               ----------------------------------------   |
|  |                     producer                             |             |       consumer                         |  |
|  |                                                          |             |                                        |  |
|  |  --------          ------------          --------        |             |        ------------          --------  |  |
|  | |        |        |            |        |        |       |             |       |            |        |        | |  |
|  | |        |_      _|            |_      _|        |_      |_           _|      _|            |_      _|        | |  |
|  | |        | |    | |            | |    | |        | |     | |         | |     | |            | |    | |        | |  |
|  | | gen    |P|___\|E| tlm_fifo   |E|___\|P| conv   |P|____\|P|________\|E|____\|E| tlm_fifo   |E|___\|P| bfm    | |  |
|  | |        |_|   /|_|            |_|   /|_|        |_|    /|_|        /|_|    /|_|            |_|   /|_|        | |  |
|  | |        |        |            |        |        |       |             |       |            |        |        | |  |
|  |  --------          ------------          --------        |             |        ------------          --------  |  |
|  |                                            | AP|         |             |                                        |  |
|  |                                             ---          |             |                                        |  |
|  |                                              |           |             |                                        |  |
|  |                                             \|/          |             |                                        |  |
|   ----------------------------------------------------------               ----------------------------------------   |
|                                               | AP|                                                                   | 
|                                                ---                                                                    | 
|                                                 |                                                                     |
|                                                \|/                                                                    |
|                                                ---                                                                    | 
|                                               | AE|                                   top                             | 
|                                            -----------                                                                | 
|                                           |           |                                                               | 
|                                           | listener  |                                                               | 
|                                           |           |                                                               | 
|                                            -----------                                                                | 
 -----------------------------------------------------------------------------------------------------------------------
*/

`include "uvm_macros.svh"

module test;

	import uvm_pkg::*;
  
	class transaction extends uvm_transaction;
		int data;
		function new (int i); data = i; endfunction  
	endclass
  
	class gen extends uvm_component;
		uvm_blocking_put_port #(transaction) put_port;
    
		function new(string name, uvm_component parent);
			super.new(name, parent);
			put_port = new("put_port", this);
		endfunction
    
		task run_phase(uvm_phase phase);
			transaction t;
			string msg;
      
			for(int i=0; i < 20; i++) begin
				t = new(i);
				`uvm_info("gen", $sformatf("sending  : %d", t.data), UVM_MEDIUM)
				put_port.put(t);
				#10;
			end
		endtask
	endclass
  
  
	class conv extends uvm_component;
		uvm_blocking_put_port #(transaction) put_port;
		uvm_blocking_get_port #(transaction) get_port;
		uvm_analysis_port #(transaction) ap;
    
		function new(string name, uvm_component parent);
			super.new(name, parent);
			put_port = new("put_port", this);
			get_port = new("get_port", this);
			ap = new("analysis_port", this);
		endfunction
    
		task run_phase(uvm_phase phase);
			transaction t;
			forever begin
				get_port.get(t);
				t.data = t.data * t.data;
				#20;
				ap.write(t);
				put_port.put(t);
			end
		endtask
	endclass
  
	class bfm extends uvm_component;
		uvm_blocking_get_port #(transaction) get_port;
    
		function new(string name, uvm_component parent);
			super.new(name, parent);
			get_port = new("get_port", this);
		endfunction
    
		task run_phase(uvm_phase phase);
			transaction t;
      
			for(int i=0; i < 20; i++) begin
				get_port.get(t);
				assert(t.data == i*i)
				else
					`uvm_error("bfm", $sformatf("expected: %d, but receiving: %d", i*i, t.data))

				`uvm_info("bfm", $sformatf("receiving: %d", t.data), UVM_MEDIUM)
				#5;
			end
		endtask
	endclass
  
	class listener extends uvm_subscriber #(transaction);
		function new(string name, uvm_component parent);
			super.new(name,parent);
		endfunction 

		function void write(input transaction t);
			`uvm_info(m_name, $sformatf("Received: %d", t.data), UVM_MEDIUM)
		endfunction
	endclass
  
	class producer extends uvm_component;
		uvm_blocking_put_port #(transaction) put_port;
		uvm_analysis_port #(transaction) ap;
    
		gen g;
		uvm_tlm_fifo #(transaction) f;
		conv c;
    
		function new(string name, uvm_component parent);
			super.new(name, parent);
			put_port = new("put_port", this);
			ap = new("analysis_port", this);
			g = new("gen", this);
			c = new("conv", this);
			f = new("fifo", this);
		endfunction
    
		function void connect_phase(uvm_phase phase);
			g.put_port.connect(f.blocking_put_export);  // A
			c.get_port.connect(f.blocking_get_export);  // B
			c.put_port.connect(put_port); // C
			c.ap.connect(ap);
		endfunction
	endclass
  
	class consumer extends uvm_component;

		uvm_blocking_put_export #(transaction) put_export;
    
		bfm b;
		uvm_tlm_fifo #(transaction) f;
    
		function new(string name, uvm_component parent);
			super.new(name, parent);
			put_export = new("put_export", this);
			f = new("fifo", this);
			b = new("bfm", this);
		endfunction
    
		function void connect_phase(uvm_phase phase);
			put_export.connect(f.blocking_put_export);
			b.get_port.connect(f.blocking_get_export);
		endfunction
	endclass
  
	class top extends uvm_env;
		producer p;
		consumer c;
		listener l;
    
		function new(string name, uvm_component parent);
			super.new(name, parent);
			p = new("producer", this);
			c = new("consumer", this);
			l = new("listener", this);

			// Connections may also be done in the constructor, if you wish
			p.put_port.connect(c.put_export);
			p.ap.connect(l.analysis_export);
		endfunction

		task run_phase(uvm_phase phase);
		endtask
	endclass
  
	class env extends uvm_env;
		top t;
    
		function new(string name = "env");
			super.new(name);
			t = new("top", this);
		endfunction
    
		task run_phase(uvm_phase phase);
			phase.raise_objection(this);
			#1000; 
			phase.drop_objection(this);
		endtask
    
	endclass
  
	env e;

	initial begin
		e = new("e");
		run_test();
	end

endmodule
