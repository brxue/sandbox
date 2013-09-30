#include <cassert>
#include <string>

using std::string;

class A
{
	public:
		virtual void whatever() {}
		string f()
		{
			return "A::f";
		}
};

class B: public A
{
	public:
		string f()
		{
			return "B::f";
		}
};

int main()
{
	A a;
	B b;
	B *pb = NULL;

	A *pa1 = &a;
	assert(pa1->f()=="A::f");
	if (!(pb = dynamic_cast<B*>(pa1)))
		assert(1);
	else 
		assert(0);

	A *pa2 = &b;
	assert(pa2->f()=="A::f");
	if (pb = dynamic_cast<B*>(pa2))
		assert(pb->f()=="B::f");
	else 
		assert(0);
}

