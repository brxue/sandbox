#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void swap()
{
	vector<int> a(5, 0xaa);
	vector<int> b(4, 0xbb);
	
    // Switch a and b
	a.swap(b);

	assert(a.size() == 4);
	assert(b.size() == 5);

    for (vector<int>::const_iterator i=a.begin(); i!=a.end(); ++i)
        assert(*i == 0xbb);

    for (vector<int>::const_iterator i=b.begin(); i!=b.end(); ++i)
        assert(*i == 0xaa);
}

int main()
{
	swap();
	return 0;
}
