#include <iostream>
#include "vpi_user.h"

void print_signal_value (vpiHandle signal_iterator)
{
	if (signal_iterator != NULL)
	{
		s_vpi_value current_value;
		vpiHandle signal_handle;
		while ((signal_handle = vpi_scan(signal_iterator)) != NULL)
		{
			PLI_INT32 signal_type = vpi_get(vpiType, signal_handle);
			switch (signal_type)
			{
				case vpiNet:
					current_value.format = vpiBinStrVal;
					vpi_get_value(signal_handle, &current_value);
					vpi_printf("net: %s = %s\n", vpi_get_str(vpiName, signal_handle), current_value.value.str);
					break;
				case vpiReg:
					current_value.format = vpiBinStrVal;
					vpi_get_value(signal_handle, &current_value);
					vpi_printf("reg: %s = %s\n", vpi_get_str(vpiName, signal_handle), current_value.value.str);
					break;

				// All these three types belog to vpiVariables
				case vpiIntegerVar:
					current_value.format = vpiIntVal;
					vpi_get_value(signal_handle, &current_value);
					vpi_printf("integer: %s = %d\n", vpi_get_str(vpiName, signal_handle), current_value.value.integer);
					break;
				case vpiRealVar:
					current_value.format = vpiRealVal;
					vpi_get_value(signal_handle, &current_value);
					vpi_printf("real: %s = %2.2f\n", vpi_get_str(vpiName, signal_handle), current_value.value.real);
					break;
				case vpiTimeVar:
					current_value.format = vpiTimeVal;
					vpi_get_value(signal_handle, &current_value);
					vpi_printf("time: %s = (%x, %x)\n", vpi_get_str(vpiName, signal_handle), current_value.value.time->high, current_value.value.time->low);
					break;

				default: 
					break;
			}
		}
	}
}

PLI_INT32 show_calltf (PLI_BYTE8 *user_data)
{
	vpiHandle tf_handle = vpi_handle(vpiSysTfCall, NULL);
	if (tf_handle == NULL) {vpi_printf("ERROR: can't get handle of $show from verilog side.\n"); return 0;}

	vpiHandle arg_itr_handle = vpi_iterate(vpiArgument, tf_handle);
	vpiHandle scope_handle;
	if (arg_itr_handle == NULL) 
	{
		// No arguments, OK, then use the scope that called $show
		scope_handle = vpi_handle(vpiScope, tf_handle);
	}
	else 
	{
		scope_handle = vpi_scan(arg_itr_handle);
		if (vpi_get(vpiType, scope_handle) != vpiModule)
			// arg is not module/instance, assume it is a scope
			scope_handle = vpi_handle(vpiScope, tf_handle);

		if (vpi_scan(arg_itr_handle) != NULL)
			vpi_free_object(arg_itr_handle);
	}
	
	s_vpi_time current_time;
	current_time.type = vpiScaledRealTime;
	vpi_get_time(tf_handle, &current_time);

	// Copy name, because the pointer returned by vpi_get_str() is a union which is shared
	std::string module_name   = vpi_get_str(vpiDefName, scope_handle);
	std::string instance_name = vpi_get_str(vpiName, scope_handle);
	std::string full_name	  = vpi_get_str(vpiFullName, scope_handle);
	vpi_printf("At time %2.2f: moduleName = %s, instanceName = %s, fullName = %s\n", current_time.real, module_name.c_str(), instance_name.c_str(), full_name.c_str());

	if (vpi_get(vpiType, scope_handle) == vpiModule) // Nets can only exist in module
		print_signal_value(vpi_iterate(vpiNet, scope_handle));
	print_signal_value(vpi_iterate(vpiReg, scope_handle));
	print_signal_value(vpi_iterate(vpiVariables, scope_handle));

	return 0;
}

PLI_INT32 show_compiletf (PLI_BYTE8 *user_data)
{
	// Obtain a handle to the system task instance
	vpiHandle tf_handle = vpi_handle(vpiSysTfCall, NULL);

	vpiHandle arg_iterator = vpi_iterate(vpiArgument, tf_handle);
	if (arg_iterator == NULL)
		return 0; // NO arguments, OK; skip remaining checks

	vpiHandle arg_handle = vpi_scan(arg_iterator);
	PLI_INT32 arg_type = vpi_get(vpiType, arg_handle);
	switch(arg_type)
	{
		case vpiModule: 
		case vpiTask:
		case vpiFunction:
		case vpiNamedBegin:
		case vpiNamedFork:
			break;
		default:
			vpi_printf("ERROR: argument of $show must be a scope instance or null.\n");
			vpi_control(vpiFinish, 1); // Abort simulation
			break;
	}

	if (vpi_scan(arg_iterator) != NULL)
	{
		vpi_printf("ERROR: $show can only have one argument.\n");
		vpi_free_object(arg_iterator);
		vpi_control(vpiFinish, 1); // Abort simulation
	}

	return 0;
}

void register_show (void)
{
	s_vpi_systf_data tf_data;
	tf_data.type = vpiSysTask;
	tf_data.sysfunctype = 0;
	tf_data.tfname = "$show";
	tf_data.calltf = show_calltf;
	tf_data.compiletf  = show_compiletf;
	tf_data.sizetf = NULL;
	tf_data.user_data = NULL;
	
	// Don't forget this, else $show can't be found
	vpi_register_systf(&tf_data);
}

extern "C" {
	void (*vlog_startup_routines[])() = {register_show, NULL};
}
