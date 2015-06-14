#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void remove_element()
{
	vector<int> a;
	for(int i = 0; i < 10; ++i) a.push_back(i);

	assert(a.back() == 9);
	assert(a.size() == 10);

    // Remove the last element
	a.pop_back();
	assert(a.size()==9);
	assert(a.back() == 8);
	// vector a is now [0, 1, 2, 3, 4, 5, 6, 7, 8]
	
    // Remove element a[2], method erase() return the iterator of next element
	assert(*(a.erase(a.begin() + 2)) == 3);
	assert(a.size() == 8);
	// vector a is now [0, 1, 3, 4, 5, 6, 7, 8]
	
    // Remove elements a[2]/a[3], method erase() return the iterator of next element
	assert(*(a.erase(a.begin()+2, a.begin()+4)) == 5);
	assert(a.size() == 6);
	// vector a is now [0, 1, 5, 6, 7, 8]

    // Remove all elements
	a.clear();
	assert(a.empty());
}

int main()
{
	remove_element();
	return 0;
}
