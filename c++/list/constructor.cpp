#include <list>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

void constructor()
{
	list<int> a; // An empty list
	list<int> b(10); // A list with 10 elements, each initialized with 0
	list<int> c(10, -1); // A list with 10 elements, each initialized with -1
	list<int> d(c); // A list initialized with another list
	list<int> e(d.begin(), d.end()); // Initialized with elements between iterators

	assert(a.size() == 0);
	assert(b.size() == 10);
	assert(c.size() == 10);
	assert(d.size() == 10);
	assert(e.size() == 10);

	vector<int> v(10, 2); // A vector with 10 elements, each initialized with 2
	list<int> f(v.begin()+1, v.end()-1); // Initialized with elemtns from a vector
	assert(f.size() == 8);

	int size = 10;
	list<int> g(size);
	assert(g.size() == size);

	int array[5] = {0,1,2,3,4};
	list<int> h(array, array+5); // Initialized with elements from array
	assert(h.size() == 5);
}

int main()
{
	constructor();
    return 0;
}
