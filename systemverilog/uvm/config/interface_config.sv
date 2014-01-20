import uvm_pkg::*;

interface intf;
	logic sig;
endinterface

class env extends uvm_env;

	virtual intf vif;

	function new (string name, uvm_component parent = null);
		super.new(name, parent);
	endfunction

	function void build_phase(uvm_phase phase);
		super.build_phase(phase);

		// static function bit get(uvm_component cntxt, string inst_name, string field_name, ref T value)
		// here the template type T is (virtual intf)
		assert(uvm_config_db#(virtual intf)::get(this, "", "vif", vif) == 1);
	endfunction

endclass


class free_env;
	virtual intf vif;

	function virtual intf get_vif();
		return vif;
	endfunction

	function void set_vif(virtual intf vif);
		this.vif = vif;
	endfunction
endclass

module test;
	
	import uvm_pkg::*;

	// instance of interface "intf"
	intf vif_inst();

	free_env fe;
	env e;

	initial begin
		fe = new;
		fe.set_vif(vif_inst);

		e = new("test_env");

		// static function void set(uvm_component cntxt, string inst_name, string field_name, T value)
		// here the template type T is (virtual intf)
		uvm_config_db#(virtual intf)::set(e, "", "vif", vif_inst);

		// utilize uvm phasing to execute e.build_phase()
		run_test();
	end
endmodule
