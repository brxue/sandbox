/*
 * DPI C functions for simple_dpi test.
 * These are just transparent wrappers around SV TF calls.
 */

#include "vpi_user.h"
#include "test.h"

// Will be imported as a DPI function
DPI_DLLESPEC
int CFunction(int i)
{
	io_printf("\t\tIn CFunction\n");
    return SVFunction(i);
}


// Will be imported as a DPI task
DPI_DLLESPEC
int CTask(int i)
{
	io_printf("In CTask\n");
    return SVTask(i);
}


