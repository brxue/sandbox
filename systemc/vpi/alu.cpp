#include "alu.h"

alu::alu(sc_module_name name): sc_module(name)
{
	SC_METHOD(main);
	sensitive << clk.pos();

	trace_file = sc_create_vcd_trace_file(basename());
	sc_trace(trace_file, clk, "clk");
	sc_trace(trace_file, rst, "rst");
	sc_trace(trace_file, a, "a");
	sc_trace(trace_file, b, "b");
	sc_trace(trace_file, type, "type");
	sc_trace(trace_file, out, "out");
}

alu::~alu()
{
	sc_close_vcd_trace_file(trace_file);
}

void alu::main()
{
	if (rst == 1)
		out.write(0);
	else if (type == 0)
		out.write(a.read() + b.read());
	else 
		out.write(a.read() - b.read());
}
