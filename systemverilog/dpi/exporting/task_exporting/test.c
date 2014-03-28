#include "vpi_user.h"
#include "svdpi.h"

extern unsigned int SV_get_simulation_time();
extern void SV_at_posedge_clk();

int C_main()
{
	int i;
	for (i=0; i<10; i++)
	{
		SV_at_posedge_clk();
		io_printf("At simulation time %d\n", SV_get_simulation_time());
	}
	
	// An imported C Task must return a zero value? 
	// or else seems the simulator will report a run time error.
	return 0;
}
