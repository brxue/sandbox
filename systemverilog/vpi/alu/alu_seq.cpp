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

typedef struct {
	vpiHandle tf_handle;
	bool flag;
} CbUserData;

PLI_INT32 alu_callback (p_cb_data cb_data)
{
	// when this cbReadWriteSynch call back gets execute, a/b/type value change in the current time step should have been all occurred
	s_vpi_value current_value;
	current_value.format = vpiIntVal;

	CbUserData *p_userdata = (CbUserData *)cb_data->user_data;

	vpiHandle tf_handle = (vpiHandle)p_userdata->tf_handle;
	vpiHandle arg_itr_handle = vpi_iterate(vpiArgument, tf_handle);

	vpiHandle clk_handle = vpi_scan(arg_itr_handle);

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

PLI_INT32 alu_sync_callback (p_cb_data cb_data)
{
	CbUserData *p_userdata = (CbUserData *)cb_data->user_data;

	vpiHandle tf_handle = (vpiHandle)p_userdata->tf_handle;
	vpiHandle arg_itr_handle = vpi_iterate(vpiArgument, tf_handle);
	vpiHandle clk_handle = vpi_scan(arg_itr_handle);
	s_vpi_value clk_value;
	clk_value.format = vpiIntVal;
	vpi_get_value(clk_handle, &clk_value);
	
	// filter out negedge
	if (clk_value.value.integer != 1) return 0;

	s_vpi_time time;
	time.type = vpiSimTime;
	time.high = 0;
	time.low = 0;

	s_vpi_value val;
	val.format = vpiIntVal;

	s_cb_data sync_cb_data;
	sync_cb_data.reason = cbReadWriteSynch;
	sync_cb_data.cb_rtn = alu_callback;
	sync_cb_data.time = &time;
	sync_cb_data.value = NULL;
	sync_cb_data.user_data = (PLI_BYTE8 *)p_userdata;

	vpiHandle cb_handle;
	cb_handle = vpi_register_cb(&sync_cb_data);
	vpi_free_object(cb_handle);
}

// calltf will be executed only once in the initial block
// the purpose of calltf is to register callback function which sensitive to value change of a/b/type
PLI_INT32 alu_calltf (PLI_BYTE8 *user_data)
{
	vpiHandle tf_handle = vpi_handle(vpiSysTfCall, NULL);

	vpiHandle arg_itr_handle = vpi_iterate(vpiArgument, tf_handle);
	vpiHandle clk_handle = vpi_scan(arg_itr_handle);
	//vpiHandle a_handle = vpi_scan(arg_itr_handle);
	//vpiHandle b_handle = vpi_scan(arg_itr_handle);
	//vpiHandle type_handle = vpi_scan(arg_itr_handle);
	//vpiHandle c_handle = vpi_scan(arg_itr_handle);

	CbUserData *ptr_userdata = new CbUserData;
	ptr_userdata->tf_handle = tf_handle;
	ptr_userdata->flag = 0;

	s_vpi_time time;
	time.type = vpiSimTime;
	time.high = 0;
	time.low = 0;
	
	s_vpi_value val;
	val.format = vpiIntVal;

	s_cb_data cb_data;
	cb_data.reason = cbValueChange;
	cb_data.cb_rtn = alu_sync_callback;
	cb_data.time = &time;
	cb_data.value = &val;
	cb_data.user_data = (PLI_BYTE8 *)ptr_userdata;

	vpiHandle cb_handle;

	cb_data.obj = clk_handle;
	cb_handle = vpi_register_cb(&cb_data);
	vpi_free_object(cb_handle);

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
