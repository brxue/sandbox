#include <list>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

void add_element()
{
	list<int> a; // An empty list
	assert(a.size() == 0);
	
	a.push_back(0); // Push value 0 to the end
	a.push_back(1);  // Push value 1 to the end
	a.push_front(-1); // Push value -1 to the front

    assert(a.size() == 3);
    // a is now [-1, 0, 1]

	assert(a.front() == -1);
	assert(*(a.begin()) == -1);
	assert(*(++a.begin()) ==  0);
	assert(a.back() ==  1);
	assert(*(--a.end()) ==  1);

	a.push_front(-2); // Push value -2 to the front
    // a is now [-2, -1, 0, 1]

	int j = -2;
	for(list<int>::const_iterator i = a.begin(); i != a.end(); ++i, ++j)
		assert(*i == j);
}

int main()
{
	add_element();
	return 0;
}
