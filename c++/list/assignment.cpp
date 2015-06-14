#include <list>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

void assignment()
{
	list<int> a(10, -1);
	list<int> b(5, 2);

	b = a; // Assign a to b
	assert(b.size() == 10); // all value of b is now -1
	assert(*(b.begin()) == -1);
}
int main()
{
	assignment();
	return 0;
}
