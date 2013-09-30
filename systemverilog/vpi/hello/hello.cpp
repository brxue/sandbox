#include <vpi_user.h>

PLI_INT32 hello_calltf (PLI_BYTE8 *user_data)
{
	vpi_printf("Hello World!\n");
	return 0;
}

void register_hello (void)
{
	s_vpi_systf_data tf;
	
	tf.type = vpiSysTask;
	tf.sysfunctype = 0;
	tf.tfname = "$hello";
	tf.calltf = hello_calltf;
	tf.compiletf = NULL;
	tf.sizetf = NULL;
	tf.user_data = NULL;

	vpi_register_systf(&tf);
}

extern "C" {
	void (*vlog_startup_routines[])() = {register_hello, 0};
}

