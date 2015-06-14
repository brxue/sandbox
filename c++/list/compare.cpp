#include <list>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

void compare()
{
	list<int> a(10,-1);
	list<int> b(10,-1);
	
	assert(a == b); // Whether the two list has the same size and the same values
}

int main()
{
	compare();
	return 0;
}
