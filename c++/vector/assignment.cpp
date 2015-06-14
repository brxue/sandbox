#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void assignment()
{
	vector<int> a(10, -1); // vector a with 10 elements, each initilized with -1
	vector<int> b(5, 33); // vector a with 10 elements, each initilized with 33

	assert(a.size() == 10);
	assert(b.size() == 5);

	b = a; // A deep copy from vector a to vector b
	assert(b.size() == 10); // b is now has 10 elements, each is -1
	for(vector<int>::const_iterator i = b.begin(); i != b.end(); ++i) 
        assert(*i == -1);

	b.assign(5, 33); // Assign b with 5 elements, each is 33
	assert(b.size() == 5);
	for(vector<int>::const_iterator i = b.begin(); i != b.end(); ++i) 
        assert(*i == 33);

	b.assign(a.begin(), a.begin()+2); // Assign b with 2 elements, b[0] is a[0], b[1] is a[1]
	assert(b.size() == 2);
	for(vector<int>::const_iterator i = b.begin(); i != b.end(); ++i) 
        assert(*i == -1);
}

int main()
{
	assignment();
	return 0;
}
