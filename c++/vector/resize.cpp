#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void resize()
{
	vector <int> a(10,-1);
	assert(a.size() == 10);

	a.resize(4); // Resize to 4, out-of-bound elements removed
	assert(a.size() == 4);

	a.resize(11, 0xaa); // Resize to 11, new elements are 0xaa
	assert(a.size() == 11);

	assert(vector<int>(4, -1) == vector<int>(a.begin(), a.begin()+4));
	assert(vector<int>(7, 0xaa) == vector<int>(a.begin()+4, a.end()));
}

int main()
{
	resize();
	return 0;
}
