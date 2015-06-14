#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void vector_2d()
{
    // vector a, each element initialized with another vector which has 10 elements each is -1
	vector< vector<int> > a(5, vector<int>(10, -1));

	assert(a.size() == 5);

	for(vector< vector<int> >::const_iterator i = a.begin(); i != a.end(); ++i)
		for (vector<int>::const_iterator j = i->begin(); j != i->end(); ++j)
			assert(*j == -1);
}

int main()
{
	vector_2d();
	return 0;
}
