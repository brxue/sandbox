#include <cassert>
#include <utility>
#include <string>
using namespace std;

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
	make__pair();
	return 0;
}
