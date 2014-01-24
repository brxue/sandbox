`include "uvm_macros.svh"

package bus_vip;

	import uvm_pkg::*;
	
	typedef class bus_driver;
	typedef class bus_driver_cb;
	
	class bus_transaction extends uvm_transaction;
		rand int addr;
	  	rand int data;
	  	virtual function string convert2string();
			convert2string = $sformatf("addr=%0h data=%0h",addr,data);
	  	endfunction
	endclass
	
	virtual class bus_driver_cb extends uvm_callback; 
		virtual function bit trans_received(bus_driver driver, bus_transaction tr);
			return 0;
	  	endfunction
	
	  	virtual task trans_executed(bus_driver driver, bus_transaction tr);
	  	endtask
	
	  	function new(string name="bus_driver_cb_inst");
			super.new(name);
	  	endfunction
	
	  	static string type_name = "bus_driver_cb";
	
	  	virtual function string get_type_name();
			return type_name;
	  	endfunction
	endclass
	
	class bus_driver extends uvm_component;
		uvm_blocking_put_imp #(bus_transaction,bus_driver) in;
	
		// regsiter callbacks
	  	`uvm_register_cb(bus_driver, bus_driver_cb)
	
	  	function new (string name, uvm_component parent=null);
			super.new(name,parent);
			in = new("in",this);
	  	endfunction
	
	  	static string type_name = "bus_driver";
	
	  	virtual function string get_type_name();
			return type_name;
	  	endfunction
	
	  	virtual function bit trans_received(bus_transaction tr);
			// the callback functions will not be called if any of the callback function return 1
			`uvm_do_callbacks_exit_on(bus_driver, bus_driver_cb, trans_received(this, tr), 1)
	  	endfunction
	
	  	virtual task trans_executed(bus_transaction tr);
			// always call this call back 
			`uvm_do_callbacks(bus_driver, bus_driver_cb, trans_executed(this, tr))
	  	endtask
	
	  	virtual task put(bus_transaction t);
			uvm_report_info("bus_transaction received", t.convert2string());
			if (!trans_received(t)) begin
				uvm_report_info("bus_transaction dropped", "user callback indicated DROPPED\n");
				return;
			end
			#100;
			trans_executed(t);
			uvm_report_info("bus_transaction executed",{t.convert2string(),"\n"});
	  	endtask
	endclass
endpackage


import bus_vip::*;

// User derived callback
class my_bus_driver_cb1 extends bus_driver_cb;

	function new(string name="bus_driver_cb_inst");
		super.new(name);
  	endfunction

  	virtual function bit trans_received(bus_driver driver, bus_transaction tr);
		static bit drop = 0;
		driver.uvm_report_info("trans_received_cb", {"  bus_driver=",driver.get_full_name()," tr=",tr.convert2string()});
		drop = 1 - drop;
		return drop;
  	endfunction

  	virtual task trans_executed(bus_driver driver, bus_transaction tr);
		driver.uvm_report_info("trans_executed_cb", {"  bus_driver=",driver.get_full_name()," tr=",tr.convert2string()});
  	endtask

  	virtual function string get_type_name();
		return "my_bus_driver_cb1";
  	endfunction
endclass

// Another user derived callback, only one of the two available methods are defined.
class my_bus_driver_cb2 extends bus_driver_cb;
	function new(string name="bus_driver_cb_inst");
		super.new(name);
	endfunction

	virtual task trans_executed(bus_driver driver, bus_transaction tr);
		driver.uvm_report_info("trans_executed_cb2", {"  bus_driver=",driver.get_full_name()," tr=",tr.convert2string()});
	endtask

	virtual function string get_type_name();
		return "my_bus_driver_cb2";
	endfunction
endclass


// Test bench
module test;
	import uvm_pkg::*;

	bus_transaction   tr     = new;
	bus_driver        driver = new("driver");
	my_bus_driver_cb1 cb1    = new("cb1");
	my_bus_driver_cb2 cb2    = new("cb2");

	initial begin
		// register callback handles to specific driver instance
		uvm_callbacks#(bus_driver, bus_driver_cb)::add(driver, cb1);
		uvm_callbacks#(bus_driver, bus_driver_cb)::add(driver, cb2);
		
		// show the callback information associated with type "bus_driver"
		uvm_callbacks#(bus_driver, bus_driver_cb)::display();
		
		// drive transactions
		// callback functions will be called as the driver receives each transaction
		for (int i=1; i<=5; i++) begin
			tr.addr = i;
			tr.data = 6-i;
			driver.in.put(tr);
		end
		
		begin
			uvm_report_server svr;
			svr = uvm_report_server::get_server();
			svr.summarize();
		end
	end
endmodule
