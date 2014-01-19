`include "uvm_macros.svh"

import uvm_pkg::*;

typedef enum { BUS_READ, BUS_WRITE } bus_op_t;
typedef enum { STATUS_OK, STATUS_NOT_OK } status_t;

class bus_trans extends uvm_sequence_item;
	bit [11:0] addr;
	bit [7:0] data;
	bus_op_t op;

	`uvm_object_utils_begin(bus_trans)
	`uvm_field_int(addr,UVM_DEFAULT)
	`uvm_field_int(data,UVM_DEFAULT)
	`uvm_field_enum(bus_op_t,op,UVM_DEFAULT)
	`uvm_field_utils_end

	function new(string name="");
		super.new(name);
	endfunction
endclass

class bus_req extends bus_trans;
	`uvm_object_utils(bus_req)

	function new(string name="");
		super.new(name);
	endfunction     
endclass

class bus_rsp extends bus_trans;
	status_t status;

	function new(string name="");
		super.new(name);
	endfunction

	`uvm_object_utils_begin(bus_rsp)
	`uvm_field_enum(status_t,status,UVM_DEFAULT)
	`uvm_object_utils_end
endclass

class my_driver #(type REQ = uvm_sequence_item, type RSP = uvm_sequence_item) extends uvm_driver #(REQ, RSP);
	`uvm_component_param_utils(my_driver#(REQ,RSP))

	local int data_array[511:0];

	function new(string name, uvm_component parent);
		super.new(name, parent);
	endfunction

	virtual task run_phase(uvm_phase phase);
		REQ req;
		RSP rsp;

		forever begin
			// get request
			seq_item_port.get(req);

			rsp = new();
			rsp.set_id_info(req);

			if (req.op == BUS_READ) begin // READ
				rsp.addr = req.addr[8:0];
				rsp.data = data_array[rsp.addr];
				//`uvm_info("sending", rsp.sprint(), UVM_MEDIUM)
				`uvm_info("sending", $sformatf("read addr = %2h data = %2h", rsp.addr, rsp.data), UVM_MEDIUM)
			end else begin // WRITE
				data_array[req.addr[8:0]] = req.data;
				//`uvm_info("sending", req.sprint(), UVM_MEDIUM)
				`uvm_info("sending", $sformatf("write addr = %2h data = %2h", req.addr, req.data), UVM_MEDIUM)
			end
			
			// send back response
			seq_item_port.put(rsp);
		end
	endtask
endclass

class my_sequence #(type REQ = uvm_sequence_item, type RSP = uvm_sequence_item) extends uvm_sequence #(REQ, RSP);
	`uvm_object_param_utils(my_sequence#(REQ,RSP))

	local static integer g_my_id = 0;
	local integer my_id;

	function new(string name="");
		super.new(name);
		my_id = g_my_id++;
	endfunction

	virtual task body();
		REQ  req;
		RSP  rsp;

		`uvm_info("my_sequence", "Starting sequence", UVM_MEDIUM)
		
		// 8*2=16 transactions
		for(int unsigned i = 0; i < 8; i++) begin
			`uvm_create(req)
			req.set_name($sformatf("req%0d_write", i));
			req.addr = (my_id * 8) + i;
			req.data = my_id + i + 55;
			req.op   = BUS_WRITE;
			`uvm_send(req)
			get_response(rsp);

			`uvm_create(req)
			req.set_name($sformatf("req%0d_read", i));
			req.addr = (my_id * 8) + i;
			req.data = 0;
			req.op   = BUS_READ;
			`uvm_send(req)
			get_response(rsp);

			if (rsp.data != (my_id + i + 55)) begin
				`uvm_error("my_sequence", $sformatf("Error, addr: %0d, expected data: %0d, actual data: %0d",	req.addr, req.data, rsp.data))
			end
		end
		`uvm_info("my_sequence", "Finishing sequence", UVM_MEDIUM)
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

		drv.seq_item_port.connect(sqr.seq_item_export); // connect driver with sequencer
	endfunction

	virtual task run_phase(uvm_phase phase);
		phase.raise_objection(this);

		// 10 sequences simultaneously, all using the same sequencer
		for (int i = 0; i < 10; i++) begin
			int tmp = i;
			fork begin
				my_sequence #(bus_req, bus_rsp) the_sequence=  new($sformatf("sequence%0d", tmp));
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

