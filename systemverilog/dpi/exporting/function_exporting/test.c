#include "vpi_user.h"
#include "svdpi.h"

extern unsigned int SV_get_simulation_time();

void C_main()
{
	io_printf("At simulation time %d\n", SV_get_simulation_time());
}
