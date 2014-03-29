#include "vpi_user.h"
#include "svdpi.h"
#include "assert.h"

void c_bit(svBit i, svBit *o)
{
	*o = (i==0) ? 1 : 0;
	io_printf("c_bit: i = %d o = %d\n", i, *o);
}

void c_bit_vector(svBitVecVal *i, svBitVecVal *o)
{
	svBitVecVal in[SV_PACKED_DATA_NELEMS(39)];
	
	int k=0;
	for (k=0; k<SV_PACKED_DATA_NELEMS(39); k++)
	{
		in[k] = i[k];
		o[k] = i[k];

		io_printf("c_bit_vector: i[%d]= 0x%x o[%d] = 0x%x\n", k, in[k], k, o[k]);
	}
}
