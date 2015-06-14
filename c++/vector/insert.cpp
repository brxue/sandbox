#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void insert()
{
	vector<int> a(10, -1); // 10 elements, each initialized with -1
	int array[4] = {0,1,2,3};

	a.insert(a.begin()+1, array+1, array+4); // Insert before a[1], 3 elements added array[1]/array[2]/array[3]
    // a is now [-1, 1, 2, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1], 13 elements

	a.insert(a.begin()+4, 4); // Insert before a[4], 1 element added with value 4
    // a is now [-1, 1, 2, 3, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1], 14 elements

	assert(a.size() == 14);

	for (vector<int>::size_type i = 0; i < a.size(); ++i)
	{
		if(i >= 1 && i <= 4)
			assert(a[i] == i);
		else
			assert(a[i] == -1);
	}
}

int main()
{
	insert();
	return 0;
}
