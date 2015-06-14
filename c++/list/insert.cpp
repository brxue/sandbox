#include <list>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

void insert()
{
	list<string> a(5, "hello"); // 5 elements each initialized with "hello"
	assert(*(a.begin()) == "hello");

	a.insert(a.begin(), "hi"); // insert before a.begin()
	assert(*(a.begin()) == "hi");
    assert(a.size() == 6);

	string s[4] = {"A", "B", "C", "D"};
	a.insert(a.end(), s+1, s+4); // insert before a.end()
	assert(*(--a.end()) == "D");
    assert(a.size() == 9);
}
int main()
{
	insert();
	return 0;
}
