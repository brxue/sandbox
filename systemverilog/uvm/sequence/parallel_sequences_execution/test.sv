`include "uvm_macros.svh"

import uvm_pkg::*;

typedef enum { BUS_READ, BUS_WRITE } bus_op_t;
typedef enum { STATUS_OK, STATUS_NOT_OK } status_t;

// Basic transation which inherited from uvm_sequence_item
class bus_trans extends uvm_sequence_item;
	bit [11:0] addr;
	bit [7:0] data;
	bus_op_t op;

	`uvm_object_utils_begin(bus_trans)
	`uvm_field_int(addr,UVM_DEFAULT)
	`uvm_field_int(data,UVM_DEFAULT)
	`uvm_field_enum(bus_op_t,op,UVM_DEFAULT)
	`uvm_object_utils_end

	function new(string name="");
		super.new(name);
	endfunction
endclass

// Request transaction
class bus_req extends bus_trans;
	`uvm_object_utils(bus_req)

	function new(string name="");
		super.new(name);
	endfunction     
endclass

// Response transaction
class bus_rsp extends bus_trans;
	status_t status;

	function new(string name="");
		super.new(name);
	endfunction

	`uvm_object_utils_begin(bus_rsp)
	`uvm_field_enum(status_t,status,UVM_DEFAULT)
	`uvm_object_utils_end
endclass

// Diver class templated with REQ and RSP, it will communicate with sequence through an sequencer
class my_driver #(type REQ = uvm_sequence_item, type RSP = uvm_sequence_item) extends uvm_driver #(REQ, RSP);
	`uvm_component_param_utils(my_driver#(REQ,RSP))
	
	// Ideally, driver will translate transactions into pin-level signal swiggles, 
	// but for now it will just saved it.
	local int data_array[511:0];

	function new(string name, uvm_component parent);
		super.new(name, parent);
	endfunction

	virtual task run_phase(uvm_phase phase);
		REQ req;
		RSP rsp;

		forever begin
			// Get sequence item from sequencer
			// seq_item_port is a pre-defined tlm1 port in uvm_driver
			// the 'req' object was allocated in the sequnce
			seq_item_port.get(req);
			
			// Allocate response object
			rsp = new();

			// Transaction ID will be allocated automatically by sequencer
			rsp.set_id_info(req);
			
			if (req.op == BUS_READ) begin // READ
				rsp.addr = req.addr[8:0];
				rsp.data = data_array[rsp.addr];
				`uvm_info(get_name(), $sformatf("read addr = %2h data = %2h", rsp.addr, rsp.data), UVM_MEDIUM)
			end else begin // WRITE
				data_array[req.addr[8:0]] = req.data;
				`uvm_info(get_name(), $sformatf("write addr = %2h data = %2h", req.addr, req.data), UVM_MEDIUM)
			end
			
			// send back response
			seq_item_port.put(rsp);
		end
	endtask
endclass

class my_sequence #(type REQ = uvm_sequence_item, type RSP = uvm_sequence_item) extends uvm_sequence #(REQ, RSP);
	`uvm_object_param_utils(my_sequence#(REQ,RSP))

	integer base_addr = 0;

	function new(string name="");
		super.new(name);
	endfunction

	virtual task body();
		REQ  req;
		RSP  rsp;

		`uvm_info(get_name(), "Starting sequence", UVM_MEDIUM)
		
		// Write transactions
		for(int unsigned i = 0; i < 8; i++) begin
			`uvm_create(req)
			req.set_name($sformatf("req%0d_write", i));
			req.addr = base_addr + i;
			req.data = i*i;
			req.op   = BUS_WRITE;
			`uvm_send(req)
			get_response(rsp);
		end

		// Read transactions
		for(int unsigned i = 0; i < 8; i++) begin
			`uvm_create(req)
			req.set_name($sformatf("req%0d_read", i));
			req.addr = base_addr + i;
			req.data = 0;
			req.op   = BUS_READ;
			`uvm_send(req)
			get_response(rsp);
			
			// Checking result
			if (rsp.data != i*i) begin
				`uvm_error(get_name(), $sformatf("Error, addr: %0d, expected data: %0d, actual data: %0d",	req.addr, req.data, rsp.data))
			end
		end

		`uvm_info(get_name(), "Finishing sequence", UVM_MEDIUM)
	endtask
endclass

class env extends uvm_env;
	`uvm_component_utils(env)
	local uvm_sequencer #(bus_req, bus_rsp) sqr;
	local my_driver #(bus_req, bus_rsp) drv ;

	function new(string name, uvm_component parent);
		super.new(name, parent);
	endfunction

	virtual function void build_phase(uvm_phase phase);
		super.build_phase(phase);
		sqr = new("sequencer", this);
		drv = new("my_driver", this);
	endfunction

	virtual function void connect_phase(uvm_phase phase);
		super.connect_phase(phase);
		drv.seq_item_port.connect(sqr.seq_item_export); // connect driver with sequencer
	endfunction

	virtual task run_phase(uvm_phase phase);
		phase.raise_objection(this);

		// 10 sequences simultaneously, all using the same sequencer
		for (int i = 0; i < 10; i++) begin
			int tmp = i;
			fork begin
				my_sequence #(bus_req, bus_rsp) the_sequence = new($sformatf("sequence%0d", tmp));
				the_sequence.base_addr = tmp * 10;
				the_sequence.start(sqr, null); // start the sequence
			end
			join_none
		end

		wait fork;

		phase.drop_objection(this);
	endtask
endclass

module test;
	import uvm_pkg::*;

	env e;
	initial begin
		`uvm_info("top","In top initial block", UVM_MEDIUM)
		e = new("env", null);
		run_test();
	end
endmodule

