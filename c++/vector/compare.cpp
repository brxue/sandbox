#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void compare()
{
	vector<int> a(10, -1); // vector a with 10 element, each is -1
	vector<int> b(9,  -1); // vector a with 9  element, each is -1
	vector<int> c(10, 2);  // vector a with 10 element, each is  2
	vector<int> d(10, -1); // vector a with 10 element, each is -1

	assert(a != b); // a has different size with b
	assert(a != c); // a has different values with b
	assert(a == d); // a has the same size and values with b
}

int main()
{
	compare();
	return 0;
}
