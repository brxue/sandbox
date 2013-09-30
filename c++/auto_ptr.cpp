#include <cassert>
#include <memory>

using namespace std;

void test()
{
	auto_ptr<int> p1(new int);
	*p1 = 10;
	
	auto_ptr<int> p2(new int(20));
	assert(*p2 == 20);

	auto_ptr<int> p3(p2);
	// p2 is now null pointer of auto_ptr
	assert(*p3 == 20);
	
	int *temp = new int(40);
	auto_ptr<pair<int*, int> > p4(new pair<int*, int>(temp, 41));
	assert(*(p4->first)  == 40); 
	assert( (p4->second) == 41); 
	
	class A
	{
		public:
			A(int* p): autop(p) {}
			auto_ptr<int> autop;
	};

	A a(temp);
	assert(*(a.autop) == 40);
}

int main()
{
	test();

	return 0;
}
