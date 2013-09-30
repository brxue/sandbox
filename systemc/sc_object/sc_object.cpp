#include "systemc.h"
#include <vector>
#include <cstring>

using namespace std;

SC_MODULE(M1)
{
	SC_CTOR(M1){}
};

SC_MODULE(M2)
{
	SC_CTOR(M2){}
};

SC_MODULE(TOP)
{
	SC_CTOR(TOP):m1("m1"), m2("m2"){}

	M1 m1;
	M2 m2;
};

int sc_main(int argc, char* argv[])
{
	TOP t("top");
	
	const vector<sc_object*> children = t.get_child_objects();
	for (vector<sc_object*>::const_iterator i=children.begin(); i!=children.end(); ++i)
	{
		cout << (*i)->name() << endl;
		cout << (*i)->basename() << endl;
		cout << (*i)->kind() << endl;
	}

	cout << endl;

	sc_object *p_m1 = children[0];
	sc_object *p_m2 = children[1];

	assert(strcmp((p_m1->get_parent_object())->basename(), "top") == 0);
	assert(strcmp((p_m2->get_parent_object())->basename(), "top") == 0);

	const vector<sc_object*> top_objs = sc_get_top_level_objects();
	for (vector<sc_object*>::const_iterator i=top_objs.begin(); i!=top_objs.end(); ++i)
	{
		cout << (*i)->name() << endl;
		cout << (*i)->basename() << endl;
		cout << (*i)->kind() << endl;
	}

	sc_object *find_m1 = sc_find_object("top.m1");
	assert(strcmp(find_m1->basename(), "m1")==0);
}

