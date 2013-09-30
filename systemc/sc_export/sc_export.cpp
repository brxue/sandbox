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

class slave_1: public sc_module
{
	public: 
		SC_CTOR(slave_1): s("slave")
		{
			xp.bind(s);
		}

		sc_export<memory_if> xp;
		slave s;
};

class slave_2: public sc_module
{
	public:
		SC_CTOR(slave_2): s1("slave_1")
		{
			xp.bind(s1.xp);
		}

		sc_export<memory_if> xp;
		slave_1 s1;
};

class master: public sc_module
{
	public:
		sc_port<memory_if> p1;
		sc_port<memory_if> p2;

		SC_CTOR(master)
		{
			SC_THREAD(main_p1);
			SC_THREAD(main_p2);
		}

		void main_p1()
		{
			cout << "Start accessing through port1 ..." << endl;

			for(int i=0; i!=10; ++i)
				p1->write(i, i+1);

			for(int i=0; i!=10; ++i)
				assert(p1->read(i) == (i+1));

			cout << "End of accessing through port1 ..." << endl;
		}

		void main_p2()
		{
			cout << "Start accessing through port2 ..." << endl;

			for(int i=0; i!=10; ++i)
				p2->write(i, i+2);

			for(int i=0; i!=10; ++i)
				assert(p2->read(i) == (i+2));

			cout << "End of accessing through port2 ..." << endl;
		}
};

int sc_main(int argc, char* argv[])
{
	master m("master");
	slave_1  s1("slave_1");
	slave_2  s2("slave_2");

	m.p1.bind(s1.xp);
	m.p2.bind(s2.xp);

	sc_start();
}

