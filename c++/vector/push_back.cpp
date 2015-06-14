#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void add_element()
{
	vector<int> a;
	a.push_back(0xaa); // Add new element 1 to the end
	a.push_back(0x55); // Add new element 2 to the end

	vector<int> b(2);
	b[0] = 0xaa;
	b[1] = 0x55;

	assert(a == b);
}

int main()
{
	add_element();
	return 0;
}
