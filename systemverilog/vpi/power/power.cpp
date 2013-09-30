#include "vpi_user.h"
#include <cmath>

PLI_INT32 pow_calltf (PLI_BYTE8 *user_data)
{
	// Get handle of $pow() from verilog side
	vpiHandle systf_handle = vpi_handle(vpiSysTfCall, NULL);
	if(systf_handle == NULL)
	{
		vpi_printf("ERROR: failed to get handle of $pow() from verilog side.\n");
		return 0;
	}

	// Get argument iterator from systf handle of $pow()
	vpiHandle arg_itr_handle = vpi_iterate(vpiArgument, systf_handle);
	if(arg_itr_handle == NULL)
	{
		vpi_printf("ERROR: failed to get argument handle of $pow().\n");
		return 0;
	}
	
	s_vpi_value v;
	v.format = vpiIntVal;

	vpiHandle arg_handle;
	
	// Scan base as the 1st argument
	arg_handle = vpi_scan(arg_itr_handle);
	vpi_get_value(arg_handle, &v);
	PLI_INT32 base = v.value.integer;

	// Scan exp as the 2nd argument
	arg_handle = vpi_scan(arg_itr_handle);
	vpi_get_value(arg_handle, &v);
	PLI_INT32 exp = v.value.integer;
	
	if (vpi_scan(arg_itr_handle) != NULL) // If there are redudant paramters
		vpi_free_object(arg_itr_handle);//Free the argument iterator

	// Calcualte power by calling <cmath> library function
	vpi_printf("Calculating pow...\n");
	double result = pow(double(base), double(exp));

	// Put the result as the return value of $pow()
	v.value.integer = PLI_INT32(result);
	vpi_put_value(systf_handle, &v, NULL, vpiNoDelay);

	return 0;
}

// compiletf to validate the arguments
PLI_INT32 pow_compiletf(PLI_BYTE8 *user_data)
{
	vpiHandle systf_handle = vpi_handle(vpiSysTfCall, NULL);
	if (systf_handle == NULL)
	{
		vpi_printf("ERROR: failed to get handle of $pow() from verilog side.\n");
		return 0;
	}


	vpiHandle arg_itr_handle = vpi_iterate(vpiArgument, systf_handle);
	if (arg_itr_handle == NULL)
	{
		vpi_printf("ERROR: $pow requires 2 arguments, but here has none.\n");
		return 0;
	}

	int err_flag = 0;

	vpiHandle arg_handle;
	PLI_INT32 arg_type;

	do 
	{
		arg_handle = vpi_scan(arg_itr_handle);
		arg_type = vpi_get(vpiType, arg_handle);
		if (arg_type != vpiIntegerVar && arg_type != vpiReg && arg_type != vpiConstant)
		{
			vpi_printf("ERROR: $pow arg1 must be integer, reg or constant\n");
			err_flag = 1;
			break;
		}

		arg_handle = vpi_scan(arg_itr_handle);
		if (arg_handle == NULL)
		{
			vpi_printf("ERROR: $pow require 2nd argument.\n");
			err_flag = 1;
			break;
		}
		arg_type = vpi_get(vpiType, arg_handle);
		if (arg_type != vpiIntegerVar && arg_type != vpiReg && arg_type != vpiConstant)
		{
			vpi_printf("ERROR: $pow arg1 must be integer, reg or constant\n");
			err_flag = 1;
			break;
		}

		if (vpi_scan(arg_itr_handle) != NULL)
		{
			vpi_printf("ERROR: $pow requires 2 argument, has too many.\n");
			vpi_free_object(arg_itr_handle);
			err_flag = 1;
			break;
		}
	} while (0==1);
	
	if (err_flag) return 0; 
}

// sizetf to tell verilog sde the return size of $pow
PLI_INT32 pow_sizetf (PLI_BYTE8 *user_data)
{
	return 32;
}

PLI_INT32 pow_cbtf_start_of_simulation(s_cb_data *cbData)
{
	vpi_printf("$pow PLI appplication callback @ start of simulation.\n");
	return 0;
}

PLI_INT32 pow_cbtf_end_of_simulation(s_cb_data *cbData)
{
	vpi_printf("$pow PLI appplication callback @ end of simulation.\n");
	return 0;
}

// Register pow to verilog side
void register_pow (void)
{
	s_vpi_systf_data tf_data;

	tf_data.type = vpiSysFunc;
	tf_data.sysfunctype = vpiSysFuncSized;
	tf_data.tfname = "$power"; // NOTE: icarus verilog seems offer an already-existed $pow function, so another name is used here or else some unexpected errors will occur
	tf_data.calltf = pow_calltf;
	tf_data.compiletf = pow_compiletf;
	tf_data.sizetf = pow_sizetf;
	tf_data.user_data = NULL;

	vpi_register_systf(&tf_data);

	s_cb_data cb_data1;
	cb_data1.reason = cbStartOfSimulation;
	cb_data1.cb_rtn = pow_cbtf_start_of_simulation;
	cb_data1.obj = NULL;
	cb_data1.time = NULL;
	cb_data1.value = NULL;
	cb_data1.user_data = NULL;

	s_cb_data cb_data2;
	cb_data2.reason = cbEndOfSimulation;
	cb_data2.cb_rtn = pow_cbtf_end_of_simulation;
	cb_data2.obj = NULL;
	cb_data2.time = NULL;
	cb_data2.value = NULL;

	cb_data2.user_data = NULL;
	vpiHandle cbHandle;

	cbHandle = vpi_register_cb(&cb_data1);
	vpi_free_object(cbHandle);

	cbHandle = vpi_register_cb(&cb_data2);
	vpi_free_object(cbHandle);
}

extern "C" 
{
	// Let verilog side know that we are register a VPI application through register_pow
	void (*vlog_startup_routines[])() = {register_pow, NULL};
}
