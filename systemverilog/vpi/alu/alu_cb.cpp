#include <iostream>
#include "vpi_user.h"

int alu (int a, int b, int type)
{
	int c;
	enum {ADD, SUB};
	switch(type)
	{
		case ADD: c = a + b; break;
		case SUB: c = a - b; break;
		default: ;
	}

	return c;
}

PLI_INT32 alu_callback (p_cb_data cb_data)
{
	s_vpi_value current_value;
	current_value.format = vpiIntVal;

	vpiHandle tf_handle = (vpiHandle)cb_data->user_data;
	vpiHandle arg_itr_handle = vpi_iterate(vpiArgument, tf_handle);

	vpiHandle arg_handle;
	
	arg_handle = vpi_scan(arg_itr_handle);
	vpi_get_value(arg_handle, &current_value);
	int a = current_value.value.integer;

	arg_handle = vpi_scan(arg_itr_handle);
	vpi_get_value(arg_handle, &current_value);
	int b = current_value.value.integer;

	arg_handle = vpi_scan(arg_itr_handle);
	vpi_get_value(arg_handle, &current_value);
	int type = current_value.value.integer;

	int c = alu(a, b, type);
	
	current_value.value.integer = c;
	arg_handle = vpi_scan(arg_itr_handle);
	vpi_put_value(arg_handle, &current_value, NULL, vpiNoDelay);
}

PLI_INT32 alu_calltf (PLI_BYTE8 *user_data)
{
	vpiHandle tf_handle = vpi_handle(vpiSysTfCall, NULL);
	
	// shedule a callback to the end of current time step
	s_vpi_time time;
	time.type = vpiSimTime;
	time.high = 0;
	time.low = 0;
	s_cb_data cb_data;
	cb_data.reason = cbReadWriteSynch;
	cb_data.cb_rtn = alu_callback;
	cb_data.obj = NULL;
	cb_data.time = &time;
	cb_data.value = NULL;
	cb_data.user_data = (PLI_BYTE8 *)tf_handle;

	vpiHandle cbHandle;
	cbHandle = vpi_register_cb(&cb_data);
	vpi_free_object(cbHandle);

	return 0;
}
void register_alu (void)
{
	s_vpi_systf_data tf_data;
	tf_data.type = vpiSysTask;
	tf_data.sysfunctype = 0;
	tf_data.tfname = "$alu";
	tf_data.calltf = alu_calltf;
	tf_data.compiletf  = NULL;
	tf_data.sizetf = NULL;
	tf_data.user_data = NULL;
	
	vpi_register_systf(&tf_data);
}

extern "C" {
	void (*vlog_startup_routines[])() = {register_alu, NULL};
}
