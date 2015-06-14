#include <cassert>
#include <utility>
#include <string>
using namespace std;

void constructor()
{
	pair<string, int> a; // A pair with type string and int correspondingly
	pair<string, int> b("Hello", 11); // Initialized as "hello" and 11
	pair<string, int> c(b); // Initialized from another pair

	assert(a.first == "");
	assert(a.second == 0);

	assert(b.first == "Hello");
	assert(b.second == 11);

	assert(c.first == b.first);
	assert(c.second == b.second);
}

int main()
{
	constructor();
	return 0;
}
