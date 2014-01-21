import uvm_pkg::*;

`include "uvm_macros.svh"

class packet extends uvm_object;
    rand int addr;
    rand int data;

	function new(string name="packet");
		super.new(name);
	endfunction

    //Use the macro in a class to implement factory registration along with other
    //utilities (create, get_type_name). For only factory registration, use
    //the macro `uvm_object_registry(packet,"packet").
    `uvm_object_utils(packet)
    
    //Base constraints
    constraint c1 { addr inside { ['h0:'h40], ['h100:'h200], ['h1000: 'h1fff], ['h4000: 'h4fff] }; }
    constraint c2 { (addr <= 'h40) -> (data inside { [10:20] } ); }
    constraint c3 { (addr >= 'h100 && addr <= 'h200) -> (data inside { [100:200] } ); }
    constraint c4 { (addr >= 'h1000 && addr <= 'h1fff) -> (data inside { [300:400] } ); }
    constraint c5 { (addr >= 'h4000 && addr <= 'h4fff) -> (data inside { [600:800] } ); }

    //do printing, comparing, etc. These functions can also be automated inside
    //the `uvm_object_utils_begin/end macros if desired. Below show the manual 
    //approach.
    function void do_print(uvm_printer printer);
		printer.print_field("addr", addr, $bits(addr));
		printer.print_field("data", data, $bits(data));
    endfunction
    function bit do_compare(uvm_object rhs, uvm_comparer comparer);
		packet rhs_;
		if(rhs==null || !$cast(rhs_, rhs)) return 0;
		do_compare = 1;  
		do_compare &= comparer.compare_field("addr", addr, rhs_.addr, $bits(addr));
		do_compare &= comparer.compare_field("data", data, rhs_.data, $bits(data));
    endfunction
    function void do_copy(uvm_object rhs);
		packet rhs_;
		if(rhs==null || !$cast(rhs_, rhs)) return;
		addr = rhs_.addr;
		data = rhs_.data;
    endfunction
endclass

class gen extends uvm_component;

    //Use the macro in a class to implement factory registration along with other
    //utilities (create, get_type_name). To do only factory registration, use
    //the macro `uvm_component_utils(gen,"gen").
    `uvm_component_utils(gen)
    
    function new (string name, uvm_component parent);
		super.new(name, parent);
    endfunction

    virtual function packet get_packet();
		packet p;

		//use the factory to generate a package
		p = packet::type_id::create("p", this);
     
		//randomize it
		void'(p.randomize());      
     
		return p; 
    endfunction
endclass

class env extends uvm_env;
    gen gen1;

    //Use the macro in a class to implement factory registration along with other
    //utilities (create, get_type_name). For only factory registration, use the
    // macro `uvm_component_registry(env,"env").
    `uvm_component_utils(env)
    
    function new (string name, uvm_component parent);
		uvm_component cmp;
		super.new(name, parent);
     
		//use the factory to create the generator
		gen1 = gen::type_id::create("gen1", this);
    endfunction

    task run_phase(uvm_phase phase);
		packet p;
		phase.raise_objection(this);
		uvm_default_tree_printer.knobs.separator = "";
		repeat(5) begin
			#15 p = gen1.get_packet();
			`uvm_info("PKTGEN", $sformatf("Got packet: %s", p.sprint(uvm_default_tree_printer)), UVM_NONE)
		end
		#15;
		phase.drop_objection(this);
    endtask
endclass

module test;
	import uvm_pkg::*;
	
	`include "uvm_macros.svh"
	env e;  //you need to use something from the package to have the
	        //factory registration occur.
	
	class mygen extends gen;
		function new(string name, uvm_component parent);
			super.new(name, parent);
	  	endfunction
	
	  	function packet get_packet();
			`uvm_info("PKTGEN", $sformatf("Getting a packet from %s (%s)", get_full_name(), get_type_name()), UVM_MEDIUM)
			return super.get_packet();
	  	endfunction
	
	  	//Use the macro in a class to implement factory registration along with other
	  	//utilities (create, get_type_name). To just do factory registration, use the
	  	//macro `uvm_object_registry(mygen,"mygen")
	  	`uvm_component_utils(mygen)
	
	endclass
	
	class mypacket extends packet;
		constraint ct10 {addr >= 0 && addr <= 10;}
	
		//Use the macro in a class to implement factory registration along with other
		//utilities (create, get_type_name).
		`uvm_object_utils(mypacket)
	
		function new(string name="mypacket");
			super.new(name);
		endfunction
	endclass
	
	initial begin
		//uvm_factory::set_inst_override_by_type("uvm_test_top.gen1", gen::get_type(), mygen::get_type());
		//uvm_factory::set_type_override_by_type(packet::get_type(), mypacket::get_type());
	    gen::type_id::set_inst_override(mygen::get_type(), "uvm_test_top.gen1");
	    packet::type_id::set_type_override(mypacket::get_type());
	
	    factory.print(1);
	
	    //If a string is used to run_test, run_test will used the string based factory
	    //create method to create an object of the desired type.
	    run_test("env");
	end
endmodule 
