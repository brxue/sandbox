#include <cassert>
#include <utility>
#include <string>

using namespace std;

void constructor()
{
	pair<string, int> a;
	pair<string, int> b("Hello", 11);
	pair<string, int> c(b);

	assert(a.first == "");
	assert(a.second == 0);
	assert(b.first == "Hello");
	assert(b.second == 11);
	assert(c.first == b.first);
	assert(c.second == b.second);
}

void make__pair()
{
	pair<string, int> a;

	a = make_pair("Hello", 11);
	assert(a.first == "Hello");
	assert(a.second == 11);

	a = pair<string, int>("Hi", 22);
	assert(a.first == "Hi");
	assert(a.second == 22);

	a.first = "Nihao";
	a.second = 33;
	assert(a.first == "Nihao");
	assert(a.second == 33);
}

int main()
{
	constructor();
	make__pair();
	return 0;
}
