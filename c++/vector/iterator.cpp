#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void test_iterator()
{
	vector<int> a(10);
    int j;

    // Initialize each elements of vector a sequentially
    j = 0;
	for (vector<int>::iterator i = a.begin(); i != a.end(); ++i,++j)
		*i = j; 

    // Access vector a with integer index
	for (vector<int>::size_type i = 0; i != 10; ++i)
		assert(a[i] == i);

    // Access vector a with const iterator, can't change element value with const iterator
    j = 0;
	for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i,++j)
		assert(*i == j);

    // Access vector a with iterator
	for (vector<int>::iterator i = a.begin(); i != a.begin() + (a.size()/2); ++i)
		*i = 88;
}

int main()
{
	test_iterator();
	return 0;
}
