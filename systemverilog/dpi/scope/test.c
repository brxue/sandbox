#include "vpi_user.h"
#include "test.h"
#include "svdpi.h"

DPI_DLLESPEC
void c_display()
{
	io_printf("Calling c_display\n");

	svSetScope(svGetScopeFromName("top.u_sub2"));
	sv_display();

	svSetScope(svGetScopeFromName("top.u_sub1"));
	sv_display();

	svSetScope(svGetScopeFromName("top.u_sub3"));
	sv_display();
}


