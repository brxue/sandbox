#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void constructor()
{
	vector<int> a;
	vector<int> b(10);
	vector<int> c(10, 55);
	vector<string> d(10);
	vector<string> e(10, "hello");
	vector<string> f(e);

	assert(a.size() == 0);
	assert(b.size() == 10);
	assert(c.size() == 10);
	assert(d.size() == 10);
	assert(e.size() == 10);

	assert(a.empty() == 1);

	for (vector<int>::size_type i = 0; i < 10; i++)
	{
		assert(b[i] == 0);
		assert(c[i] == 55);
	}
	
	for (vector<string>::size_type i = 0; i < 10; i++)
	{
		assert(d[i] == "");
	}

	for (vector<string>::const_iterator i = e.begin(); i != e.end(); ++i)
	{
		assert(*i == "hello");
	}

	for (vector<string>::const_iterator i = f.begin(); i != f.end(); ++i)
	{
		assert(*i == "hello");
	}
}

void assignment()
{
	vector<int> a(10, -1);
	vector<int> b(5, 33);
	assert(a.size() == 10);
	assert(b.size() == 5);

	b = a;
	assert(b.size() == 10);
	for(vector<int>::const_iterator i = b.begin(); i != b.end(); ++i) assert(*i == -1);

	b.assign(5, 33);
	assert(b.size() == 5);
	for(vector<int>::const_iterator i = b.begin(); i != b.end(); ++i) assert(*i == 33);

	b.assign(a.begin(), a.begin()+1);
	assert(b.size() == 1);
	for(vector<int>::const_iterator i = b.begin(); i != b.end(); ++i) assert(*i == -1);
}

void compare()
{
	vector<int> a(10, -1);
	vector<int> b(9,  -1);
	vector<int> c(10, 2);
	vector<int> d(10, -1);

	assert(a != b);
	assert(a != c);
	assert(a == d);
}

void add_element()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);

	vector<int> b(2);
	b[0] = 1;
	b[1] = 2;

	assert(a == b);
}

void insert()
{
	vector<int> a(10, -1);

	int array[4] = {0,1,2,3};
	a.insert(a.begin()+1, array+1, array+4);
	a.insert(a.begin()+4, 4);
	assert(a.size() == 14);

	for (vector<int>::size_type i = 0; i < a.size(); ++i)
	{
		if(i >= 1 && i <= 4)
			assert(a[i] == i);
		else
			assert(a[i] == -1);
	}
}

void test_iterator()
{
	vector<int> a(10);
	int j = 0;
	for (vector<int>::iterator i = a.begin(); i != a.end(); ++i,++j)
		*i = j;
	for (vector<int>::size_type i = 0; i != 10; ++i)
		assert(a[i] == i);
	j = 0;
	for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i,++j)
		assert(*i == j);

	for (vector<int>::iterator i = a.begin(); i != a.begin() + (a.size()/2); ++i)
		*i = 88;

}

void vector_2d()
{
	vector< vector<int> > a(5, vector<int>(10, -1));
	assert(a.size() == 5);

	for(vector< vector<int> >::const_iterator i = a.begin(); i != a.end(); ++i)
	{
		for (vector<int>::const_iterator j = i->begin(); j != i->end(); ++j)
		{
			assert(*j == -1);
		}
	}
}

void resize()
{
	vector <int> a(10,-1);
	assert(a.size() == 10);

	a.resize(4);
	assert(a.size() == 4);

	a.resize(11, 0xaa);
	assert(a.size() == 11);
	assert(vector<int>(7, 0xaa) == vector<int>(a.begin()+4, a.end()));
}

void remove_element()
{
	vector<int> a;
	for(int i = 0; i < 10; ++i) a.push_back(i);

	assert(a.back() == 9);
	assert(a.size() == 10);

	a.pop_back();
	assert(a.size()==9);
	assert(a.back() == 8);
	// 012345678
	
	assert(*(a.erase(a.begin() + 2)) == 3);
	assert(a.size() == 8);
	// 01345678
	
	assert(*(a.erase(a.begin()+2, a.begin()+4)) == 5);
	assert(a.size() == 6);
	// 015678

	a.clear();
	assert(a.empty());
}

void swap()
{
	vector<int> a(5, 0xaa);
	vector<int> b(4, 0xbb);
	
	a.swap(b);
	assert(a.size() == 4);
	assert(b.size() == 5);
}

int main()
{
	constructor();
	assignment();
	compare();
	add_element();
	test_iterator();
	vector_2d();
	insert();
	resize();
	remove_element();
	swap();
	return 0;
}


