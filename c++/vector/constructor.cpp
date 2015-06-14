#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void constructor()
{
	vector<int> a; // An array with 0 integers 
	vector<int> b(10); // An array with 10 integers, all elements initialized with 0
	vector<int> c(10, 55); // An array with 10 integers, all initialized with 55
	vector<string> d(10); // An array with 10 strings, all elements initialized with ""
	vector<string> e(10, "hello"); // An array with 10 strings, all elements initialized with "hello"
	vector<string> f(e); // An array which initialized with another array e

	assert(a.size() == 0);
	assert(b.size() == 10);
	assert(c.size() == 10);
	assert(d.size() == 10);
	assert(e.size() == 10);

	assert(a.empty() == 1);

	for (vector<int>::size_type i = 0; i < 10; ++i)	{
		assert(b[i] == 0);
		assert(c[i] == 55);
	}
	
	for (vector<string>::size_type i = 0; i < 10; ++i) {
		assert(d[i] == "");
	}

	for (vector<string>::const_iterator i = e.begin(); i != e.end(); ++i) {
		assert(*i == "hello");
	}

	for (vector<string>::const_iterator i = f.begin(); i != f.end(); ++i) {
		assert(*i == "hello");
	}
}

int main()
{
    constructor();
    return 0;
}
