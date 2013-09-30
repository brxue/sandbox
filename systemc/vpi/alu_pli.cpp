#include "alu.h"
#include "vpi_user.h"
#include <cassert>

static unsigned long long current_sc_time = 0;
sc_signal<bool> clk, rst;
sc_signal<int> a, b, type, out;

typedef struct {
	vpiHandle tf_handle;
	bool flag;
	alu *sc_alu;
} CbUserData;

PLI_INT32 alu_callback (p_cb_data cb_data)
{
	CbUserData *p_userdata = (CbUserData *)cb_data->user_data;
	vpiHandle tf_handle = (vpiHandle)p_userdata->tf_handle;
	alu *sc_alu = (alu *)p_userdata->sc_alu;

	vpiHandle arg_itr_handle = vpi_iterate(vpiArgument, tf_handle);
	vpiHandle clk_handle = vpi_scan(arg_itr_handle);
	vpiHandle rst_handle = vpi_scan(arg_itr_handle);
	vpiHandle a_handle = vpi_scan(arg_itr_handle);
	vpiHandle b_handle = vpi_scan(arg_itr_handle);
	vpiHandle type_handle = vpi_scan(arg_itr_handle);
	vpiHandle out_handle = vpi_scan(arg_itr_handle);

	s_vpi_value current_value;
	current_value.format = vpiIntVal;

	s_vpi_time current_time;
	current_time.type = vpiSimTime;
	vpi_get_time(tf_handle, &current_time);
	
	int delta = int(current_time.low - current_sc_time);
	assert(delta > 0);
	sc_start(delta, SC_NS);
	current_sc_time = current_time.low;

	vpi_get_value(clk_handle, &current_value);
	clk.write(bool(current_value.value.integer));
	while(sc_pending_activity_at_current_time())
		sc_start(0, SC_NS);

	if (current_value.value.integer != 1) return 0;

	vpi_get_value(rst_handle, &current_value);
	rst.write(bool(current_value.value.integer));

	vpi_get_value(a_handle, &current_value);
	a.write(int(current_value.value.integer));

	vpi_get_value(b_handle, &current_value);
	b.write(int(current_value.value.integer));

	vpi_get_value(type_handle, &current_value);
	type.write(int(current_value.value.integer));

	//while(sc_pending_activity_at_current_time())
	//	sc_start(0, SC_NS);

	current_value.value.integer = int(out.read());
	vpi_put_value(out_handle, &current_value, NULL, vpiNoDelay);
}

PLI_INT32 alu_sync_callback (p_cb_data cb_data)
{
	CbUserData *p_userdata = (CbUserData *)cb_data->user_data;

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
// the purpose of calltf is to register callback function which sensitive to value change of clk
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
	ptr_userdata->sc_alu = new alu("alu");
	ptr_userdata->sc_alu->clk.bind(clk);
	ptr_userdata->sc_alu->rst.bind(rst);
	ptr_userdata->sc_alu->a.bind(a);
	ptr_userdata->sc_alu->b.bind(b);
	ptr_userdata->sc_alu->type.bind(type);
	ptr_userdata->sc_alu->out.bind(out);

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
