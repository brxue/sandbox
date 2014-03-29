#include "vpi_user.h"
#include "svdpi.h"
#include "assert.h"

extern int sv_display();

int c_display()
{
	sv_display();
	return 0;
}
