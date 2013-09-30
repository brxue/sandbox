#include "systemc.h"
#include <iostream>

using namespace std;

SC_MODULE(dff)
{
	sc_in_clk clk;
	sc_in<bool> rst;
	sc_in<int> d;
	sc_out<int> q;

	SC_CTOR(dff)
	{
		SC_METHOD(main);
		sensitive << clk.pos();
	}

	void main()
	{
		if (rst.read() == 1)
			q.write(0);
		else
			q.write(d);
	}
};

SC_MODULE(driver)
{
	sc_in_clk clk;
	sc_out<int>	d;
	sc_out<bool> rst;

	SC_CTOR(driver)
	{
		SC_THREAD(drive_d);
		sensitive << clk.pos();

		SC_THREAD(drive_rst);
		sensitive << clk.pos();
	}

	void drive_d()
	{
		d.write(0);
		while (1)
		{
			wait();
			d.write(d.read() + 1);
		}
	}

	void drive_rst()
	{
		rst.write(1);
		for (int i=0; i< 5; i++)
			wait();
		rst.write(0);
	}
};

int sc_main(int argc, char* argv[])
{
	sc_clock clk("Clock", 10, SC_NS);
	
	sc_signal<bool> rst;
	sc_signal<int> d;
	sc_signal<int> q;
	
	dff u_dff("DFF");
	driver u_driver("DRIVER");

	u_dff.clk.bind(clk);
	u_dff.rst.bind(rst);
	u_dff.d.bind(d);
	u_dff.q.bind(q);

	u_driver.clk.bind(clk);
	u_driver.rst.bind(rst);
	u_driver.d.bind(d);

	sc_trace_file *tf = sc_create_vcd_trace_file("dff");

	sc_trace(tf, clk, "CLK");
	sc_trace(tf, rst, "RST");
	sc_trace(tf, d, "D");
	sc_trace(tf, q, "Q");

	sc_start(100, SC_NS);

	sc_close_vcd_trace_file(tf);
	return 0;
}

