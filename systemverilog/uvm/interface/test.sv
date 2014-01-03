interface apb_if(input bit pclk);
	wire [31:0] paddr;
	wire        psel;
	wire        penable;
	wire        pwrite;
	wire [31:0] prdata;
	wire [31:0] pwdata;
	
	
	clocking mck @(posedge pclk);
	    output paddr, psel, penable, pwrite, pwdata;
	    input  prdata;
	endclocking: mck
	
	clocking sck @(posedge pclk);
	    input  paddr, psel, penable, pwrite, pwdata;
	    output prdata;
	endclocking: sck
	
	clocking pck @(posedge pclk);
	    input paddr, psel, penable, pwrite, prdata, pwdata;
	endclocking: pck
	
	modport master(input pclk, clocking mck);
	modport slave(input pclk, clocking sck);
	modport passive(input pclk, clocking pck);
endinterface

import uvm_pkg::*;
`include "uvm_macros.svh"
	
class driver extends uvm_component;
	virtual apb_if vif;
	
	function new(string name, uvm_component parent = null);
		super.new(name, parent);
	endfunction
	
	function void connect_phase(uvm_phase phase);
		assert(uvm_resource_db#(virtual apb_if)::read_by_name(get_full_name(), "vif", vif));// assert resource exists
	endfunction
	
	task run_phase(uvm_phase phase);
		logic [31:0] d;
		int i = 0;
		while(i<10) begin
			`uvm_info("driver", $sformatf("writing: addr = %0d, pwdata = %0h", i, 32'h4000+i), UVM_NONE);
			write(i, 32'h4000+i);
			i++;
		end

		i = 0;
		while(i<10) begin
			read(i, d);
			`uvm_info("driver", $sformatf("reading: addr = %0d, prdata = %0h", i, d), UVM_NONE);
			assert(d == (32'h4000+i));
			i++;
		end
	endtask

	task read(input bit [31:0] addr, output logic [31:0] data);
	    @ (this.vif.mck);
	    this.vif.mck.paddr   <= addr;
	    this.vif.mck.pwrite  <= '0;
	    this.vif.mck.psel    <= '1;
	    @ (this.vif.mck);
	    this.vif.mck.penable <= '1;
	    @ (this.vif.mck);
	    data = this.vif.mck.prdata;
	    this.vif.mck.psel    <= '0;
	    this.vif.mck.penable <= '0;
	endtask: read
	
	task write(input bit [31:0] addr, input bit [31:0] data);
	    @ (this.vif.mck);
	    this.vif.mck.paddr   <= addr;
	    this.vif.mck.pwdata  <= data;
	    this.vif.mck.pwrite  <= '1;
	    this.vif.mck.psel    <= '1;
	    @ (this.vif.mck);
	    this.vif.mck.penable <= '1;
	    @ (this.vif.mck);
	    this.vif.mck.psel    <= '0;
	    this.vif.mck.penable <= '0;
	endtask: write
endclass

class env extends uvm_env;
	local virtual apb_if pif;
	driver d;
	
	function new(string name, uvm_component parent = null);
		super.new(name, parent);
		d = new("u_driver", this);
	endfunction

	task run_phase(uvm_phase phase);
		phase.raise_objection(this);
		#1000;
		phase.drop_objection(this);
	endtask
endclass

module dut(apb_if.slave pif);
	
	logic [31:0] mem[0:31];

	always @(posedge pif.pclk) begin
		if(pif.sck.psel == 1'b1) begin
			if (pif.sck.pwrite == 1'b1) begin
				@(posedge pif.pclk);
				mem[pif.sck.paddr] <= pif.sck.pwdata;
			end else begin
				pif.sck.prdata <= mem[pif.sck.paddr];
			end
		end
	end

endmodule

module test;

	bit clk;
	initial begin
		forever begin
			#5 clk = 1;
			#5 clk = 0;
		end
	end

	apb_if pif(clk);

	env e;
	dut d(pif.slave);

	initial begin
		e = new("u_env");

		// connect virtual interface in u_driver to real instance
		uvm_resource_db#(virtual apb_if)::set("u_env.u_driver", "vif", pif); 	
		
		// dump resouce database
		uvm_resource_db#(virtual apb_if)::dump();

		run_test();
	end
  
endmodule
