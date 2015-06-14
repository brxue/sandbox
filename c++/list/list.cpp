#include <list>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

void constructor()
{
	list<int> a;
	list<int> b(10);
	list<int> c(10, -1);
	list<int> d(c);
	list<int> e(d.begin(), d.end());

	assert(a.size() == 0);
	assert(b.size() == 10);
	assert(c.size() == 10);
	assert(d.size() == 10);
	assert(e.size() == 10);

	vector<int> v(10, 2);
	list<int> f(v.begin()+1, v.end()-1);
	assert(f.size() == 8);

	int size = 10;
	list<int> g(size);
	assert(g.size() == size);

	int array[5] = {0,1,2,3,4};
	list<int> h(array, array+5);
	assert(h.size() == 5);
}

void add_element()
{
	list<int> a;
	assert(a.size() == 0);
	
	a.push_back(0);
	a.push_back(1);
	a.push_front(-1);

	assert(a.front() == -1);
	assert(*(a.begin()) == -1);
	assert(*(++a.begin()) ==  0);
	assert(a.back() ==  1);
	assert(*(--a.end()) ==  1);

	a.push_front(-2);
	int j = -2;
	for(list<int>::const_iterator i = a.begin(); i != a.end(); ++i, ++j)
		assert(*i == j);
}

void insert()
{
	list<string> a(10, "hello");
	assert(*(a.begin()) == "hello");

	a.insert(a.begin(), "hi");
	assert(*(a.begin()) == "hi");

	string s[4] = {"A", "B", "C", "D"};
	a.insert(a.end(), s+1, s+4);
	assert(*(--a.end()) == "D");
}

void compare()
{
	list<int> a(10,-1);
	list<int> b(10,-1);
	
	assert(a == b);
}

void assignment()
{
	list<int> a(10, -1);
	list<int> b(5, 2);

	b = a;
	assert(b.size() == 10);
	assert(*(b.begin()) == -1);
}

void remove_element()
{
	list<int> a;
	for (int i = 0; i < 10; ++i) a.push_back(i);
	assert(a.size() == 10);

	assert(*a.begin() == 0);
	assert(*--a.end() == 9);

	a.pop_front();
	a.pop_back();
	// 12345678

	assert(a.front() == 1);
	assert(a.back() == 8);
	assert(a.size() == 8);

	assert(*(a.erase(++(++a.begin()))) == 4);
	assert(a.size() == 7);
	// 1245678
	
	assert(*(a.erase(++(++a.begin()), ++(++(++(++a.begin()))))) == 6);
	assert(a.size() == 5);
	// 12678

	a.clear();
	assert(a.size() == 0);
}

int main()
{
	constructor();
	add_element();
	insert();
	compare();
	assignment();
	remove_element();
	return 0;
}
