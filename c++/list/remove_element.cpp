#include <list>
#include <vector>
#include <cassert>
#include <string>
#include <iostream>

using namespace std;

void remove_element()
{
	list<int> a;
	for (int i = 0; i < 10; ++i) a.push_back(i);
	assert(a.size() == 10);
    // a is now [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

	assert(*a.begin() == 0);
	assert(*--a.end() == 9);

	a.pop_front();
	a.pop_back();
    // a is now [1, 2, 3, 4, 5, 6, 7, 8]

	assert(a.front() == 1);
	assert(a.back() == 8);
	assert(a.size() == 8);

    // Remove a[2], return iterator of next element
	assert(*(a.erase(++(++a.begin()))) == 4);
	assert(a.size() == 7);
    // a is now [1, 2, 4, 5, 6, 7, 8]
	
    // Remove the elements from a[2] to a[4](not included), return iterator of next element
	assert(*(a.erase(++(++a.begin()), ++(++(++(++a.begin()))))) == 6);
	assert(a.size() == 5);
    // a is now [1, 2, 6, 7, 8]

    int j = 0;
    for (list<int>::const_iterator i=a.begin(); i!=a.end(); ++i, ++j)
    {
        switch(j)
        {
            case(0): assert(*i == 1); break;
            case(1): assert(*i == 2); break;
            case(2): assert(*i == 6); break;
            case(3): assert(*i == 7); break;
            case(4): assert(*i == 8); break;
        }
    }

	a.clear(); // Clear the list
	assert(a.size() == 0);
}

int main()
{
	remove_element();
	return 0;
}
