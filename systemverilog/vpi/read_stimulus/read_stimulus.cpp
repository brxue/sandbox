#include <iostream>
#include <fstream>
#include "vpi_user.h"

typedef struct {
	std::string file_name;
	std::ifstream file;
	vpiHandle bus;
} TfUserData;

PLI_INT32 read_stimulus_callback_start_of_simulation (p_cb_data cb_data)
{
	// TF handle was saved in callback user data when callback was registered
	vpiHandle tf_handle = (vpiHandle)cb_data->user_data;
	
	// get argument handle from TF handle
	vpiHandle arg_itr_handle = vpi_iterate(vpiArgument,tf_handle);
	vpiHandle arg1_handle = vpi_scan(arg_itr_handle);
	vpiHandle arg2_handle = vpi_scan(arg_itr_handle);
	if(vpi_scan(arg_itr_handle) != NULL)
		vpi_free_object(arg_itr_handle);

	// get file name which is a string
	s_vpi_value arg_value;
	arg_value.format = vpiStringVal;
	vpi_get_value(arg1_handle, &arg_value);
	
	// save file stream and the handle to the 2nd argument
	TfUserData *tf_data = new TfUserData; // must use a pointer here, variables in stack will be invalid after function exit
	tf_data->file_name = arg_value.value.str;
	tf_data->file.open(arg_value.value.str);
	if ((tf_data->file).good() == 0)
		vpi_printf("ERROR: can't open file.\n");

	tf_data->bus = arg2_handle;
	
	// put user data to the instance area of the TF
	vpi_put_userdata(tf_handle, (void *)tf_data);

	return 0;
}

PLI_INT32 read_stimulus_callback_end_of_simulation (p_cb_data cb_data)
{
	vpiHandle tf_handle = (vpiHandle)cb_data->user_data;

	TfUserData *tf_data;
	tf_data = (TfUserData *)vpi_get_userdata(tf_handle);

	vpi_printf("%s closed.\n", (tf_data->file_name).c_str());
	tf_data->file.close();
}

PLI_INT32 read_stimulus_compiletf (PLI_BYTE8 *user_data)
{
	vpiHandle tf_handle = vpi_handle(vpiSysTfCall, NULL);

	s_cb_data cb_data1;
	cb_data1.reason = cbStartOfSimulation;
	cb_data1.cb_rtn = read_stimulus_callback_start_of_simulation;
	cb_data1.obj = NULL;
	cb_data1.time = NULL;
	cb_data1.value = NULL;
	cb_data1.user_data = (PLI_BYTE8 *)tf_handle;

	s_cb_data cb_data2;
	cb_data2.reason = cbEndOfSimulation;
	cb_data2.cb_rtn = read_stimulus_callback_end_of_simulation;
	cb_data2.obj = NULL;
	cb_data2.time = NULL;
	cb_data2.value = NULL;
	cb_data2.user_data = (PLI_BYTE8 *)tf_handle;

	vpiHandle cbHandle;

	cbHandle = vpi_register_cb(&cb_data1);
	vpi_free_object(cbHandle);

	cbHandle = vpi_register_cb(&cb_data2);
	vpi_free_object(cbHandle);
}

PLI_INT32 read_stimulus_calltf (PLI_BYTE8 *user_data)
{
	vpiHandle tf_handle = vpi_handle(vpiSysTfCall, NULL);

	TfUserData *tf_data = (TfUserData *)vpi_get_userdata(tf_handle);
	vpiHandle bus = tf_data->bus;
	
	unsigned int data;
	s_vpi_value bus_value;
	bus_value.format = vpiIntVal;
	if (tf_data->file >> std::hex >> data)
	{
		bus_value.value.integer = data;
	}
	else
	{
		vpi_printf("EOF of %s.\n", (tf_data->file_name).c_str());
		bus_value.value.integer = 0xdeaddead;
	}

	vpi_put_value(tf_data->bus, &bus_value, NULL, vpiNoDelay);
	
	return 0;
}

void register_read_stimulus (void)
{
	s_vpi_systf_data tf_data;

	tf_data.type = vpiSysTask;
	tf_data.sysfunctype = 0;
	tf_data.tfname = "$read_stimulus";
	tf_data.calltf = read_stimulus_calltf;
	tf_data.compiletf = read_stimulus_compiletf;
	tf_data.sizetf = NULL;
	tf_data.user_data = NULL;

	vpi_register_systf(&tf_data);
}

extern "C" 
{
	void (*vlog_startup_routines[])() = {register_read_stimulus, NULL};
}
