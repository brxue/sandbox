#include "alu.h"
#include "systemc.h"

SC_MODULE(driver)
{
	sc_in<bool> clk;
	sc_out<bool> rst;
	sc_out<int> a, b, type;
	sc_in<int> out;

	SC_CTOR(driver)
	{
		SC_THREAD(main);
		sensitive << clk.pos();
	}

	void main()
	{
		a.write(0);
		b.write(0);
		type.write(0);
		rst.write(1);
		for (int i = 0; i < 5; i++) 
			wait();
		rst.write(0);
		while(1)
		{
			wait();
			a.write(a.read() + 1);
			b.write(b.read() + 2);
		}
	}
};

int sc_main(int argc, char* argv[])
{
	sc_clock clk("Clock", 5, SC_NS);
	
	sc_signal<bool> rst;
	sc_signal<int> a, b, type, out;

	alu u_alu("alu");
	u_alu.clk.bind(clk);
	u_alu.rst.bind(rst);
	u_alu.a.bind(a);
	u_alu.b.bind(b);
	u_alu.type.bind(type);
	u_alu.out.bind(out);

	driver u_driver("driver");
	u_driver.clk.bind(clk);
	u_driver.rst.bind(rst);
	u_driver.a.bind(a);
	u_driver.b.bind(b);
	u_driver.type.bind(type);
	u_driver.out.bind(out);

	sc_start(100, SC_NS);

	return 0;
}

