#ifndef __ALU_H__
#define __ALU_H__

#include "systemc.h"

SC_MODULE(alu)
{
	sc_in<bool> clk;
	sc_in<bool> rst;
	sc_in<int> a;
	sc_in<int> b;
	sc_in<int> type;
	sc_out<int> out;

	SC_CTOR(alu);
	~alu();

	sc_trace_file *trace_file;

	void main();
};

#endif

