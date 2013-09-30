#include "systemc.h"

class memory_if: public sc_interface
{
	public:
		virtual unsigned int read(unsigned int addr) = 0;
		virtual void write(unsigned int addr, unsigned int data) = 0;
};

class slave: public memory_if, sc_module
{
	public:
		SC_CTOR(slave)
		{
			;
		}

		unsigned int read(unsigned int addr)
		{
			return mem[addr];
		}

		void write(unsigned int addr, unsigned int data)
		{
			mem[addr] = data;
		}

	private:
		unsigned int mem[1024];
};

class master: public sc_module
{
	public:
		sc_port<memory_if> p;

		SC_CTOR(master)
		{
			SC_THREAD(main);
		}

		void main()
		{
			cout << "Start accessing slave..." << endl;

			for(int i=0; i!=10; ++i)
				p->write(i, i+1);

			for(int i=0; i!=10; ++i)
				assert(p->read(i) == (i+1));

			cout << "End of accessing slave..." << endl;
		}
};

int sc_main(int argc, char* argv[])
{
	master m("master");
	slave  s("slave");

	m.p.bind(s);

	sc_start();
}

