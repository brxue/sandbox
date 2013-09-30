// The macro must be defined to use sc_spawn
#define SC_INCLUDE_DYNAMIC_PROCESSES

#include "systemc.h"

void f1()
{
	sc_time t = sc_time_stamp();
	cout << "Hello f1 @ " << t << endl;
}

int f2(int a, int &b, const int &c, const sc_clock &clk)
{
	assert(a==0x2a);
	assert(b==0x2b);
	assert(c==0x2c);
	
	for(int i=0; i!=2; ++i) wait(clk.posedge_event());	

	sc_time t = sc_time_stamp();
	cout << "Hello f2 @ " << t << endl;

	b = 0xbb;
	return 0xf2;
}

class f3
{
	public:
		void operator()()
		{
			sc_time t = sc_time_stamp();
			cout << "Hello f3 @ " << t << endl;
		}
};

class f4
{
	public:
		// result_type must be defined to spawn function objects
		typedef int result_type;
		int operator()(int a, int &b, const int &c, const sc_clock &clk)
		{
			assert(a==0x4a);
			assert(b==0x4b);
			assert(c==0x4c);
			
			for(int i=0; i!=4; ++i) wait(clk.posedge_event());	

			sc_time t = sc_time_stamp();
			cout << "Hello f4 @ " << t << endl;

			b = 0xbb;
			return 0xf4;
		}
};

void f5()
{
	while(1)
	{
		sc_time t = sc_time_stamp();
		cout << "Hello f5 @ " << t << endl;

		for(int i=0; i!=10; ++i) wait();
	}
}

void f6()
{
	cout << "Hello f6 @ " << sc_time_stamp() << endl;
}

void f7()
{
	for(int i=0; i!=6; ++i) wait();

	sc_time t = sc_time_stamp();
	cout << "Hello f7 @ " << t << endl;

	// spawn another thread
	sc_spawn(f6);
}

class M : public sc_module
{
	public:
		SC_CTOR(M): clk("Clock", 10, SC_NS)
		{
			// f1
			sc_spawn(f1);
			
			// f2
			a2=0x2a; b2=0x2b; c2=0x2c;
			sc_spawn(&ret2, sc_bind(f2, a2, sc_ref(b2), sc_cref(c2), sc_cref(clk)));
			
			// f3
			sc_spawn(f3());
			
			// f4
			a4=0x4a; b4=0x4b; c4=0x4c;
			sc_spawn(&ret4, sc_bind(f4(), a4, sc_ref(b4), sc_cref(c4), sc_cref(clk)));
			
			// f5
			sc_spawn_options opt5;
			opt5.set_sensitivity(&clk.posedge_event());
			opt5.dont_initialize();
			sc_spawn(f5, "f5", &opt5);

			// f7
			sc_spawn_options opt7;
			opt7.set_sensitivity(&clk.posedge_event());
			opt7.dont_initialize();
			sc_spawn(f7, "f7", &opt7);

			// f8
			sc_spawn(sc_bind(&M::f8, this));

			// f9
			a9=0x9a; b9=0x9b; c9=0x9c;
			sc_spawn(&ret9, sc_bind(&M::f9, this, a9, sc_ref(b9), sc_cref(c9)));

			SC_THREAD(compare);
		}
	private:
		void f8()
		{
			sc_time t = sc_time_stamp();
			cout << "Hello f8 @ " << t << endl;
		}

		int f9(int a, int &b, const int &c)
		{
			assert(a==0x9a);
			assert(b==0x9b);
			assert(c==0x9c);
			
			for(int i=0; i!=9; ++i) wait(clk.posedge_event());	
			
			sc_time t = sc_time_stamp();
			cout << "Hello f9 @ " << t << endl;

			b = 0xbb;
			return 0xf9;
		}

		void compare()
		{
			cout << "Comparing..." << endl;

			for(int i=0; i!=10; ++i)wait(clk.posedge_event());

			assert(b2==0xbb);
			assert(ret2==0xf2);

			assert(b4==0xbb);
			assert(ret4==0xf4);

			assert(b9==0xbb);
			assert(ret9==0xf9);
		}

	private:
		sc_clock clk;

		int a1, b1, c1, ret1;
		int a2, b2, c2, ret2;
		int a3, b3, c3, ret3;
		int a4, b4, c4, ret4;
		int a5, b5, c5, ret5;
		int a6, b6, c6, ret6;
		int a7, b7, c7, ret7;
		int a8, b8, c8, ret8;
		int a9, b9, c9, ret9;
};

int sc_main(int argc, char* argv[])
{
	M m("module");

	sc_start(1000, SC_NS);
}
