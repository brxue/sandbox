#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class A 
{
public:
	virtual string vf(void)
	{
		return string("A::vf");
	}
	string f(void)
	{
		return string("A::f");
	}

};

class B : public A
{
public:
	string vf(void)
	{
		return string("B::vf");
	}
	string f(void)
	{
		return string("B::f");
	}
};

int main ()
{
	A a;
	B b;

	A *pa;
	pa = &b;
	assert(pa->vf() == "B::vf");
	assert(pa->f()  == "A::f");
	assert(pa->A::vf() == "A::vf");

	A &ra = b;
	assert(ra.vf() == "B::vf");
	assert(ra.f()  == "A::f");

	return 0;
}

