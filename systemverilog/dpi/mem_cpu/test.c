#include "vpi_user.h"
#include "svdpi.h"
#include "assert.h"

extern int read_mem(unsigned int addr, int* data);
extern int write_mem(unsigned int addr, int data);

int C_main()
{
	int data2, data5;

	write_mem(0x2, 0x55aa55aa);
	io_printf("Write 0x55aa55aa to address 0x2\n");

	write_mem(0x5, 0x55aa55ab);
	io_printf("Write 0x55aa55ab to address 0x5\n");

	read_mem(0x2, &data2);
	io_printf("Read address 0x2 got %x\n", data2);

	read_mem(0x5, &data5);
	io_printf("Read address 0x5 got %x\n", data5);

	//assert(data2 == (data5-1));

	return 0;
}
