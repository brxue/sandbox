#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>
using namespace std;

void size()
{
	string s1("Hello"), s2;
	assert(s1.size() == 5 && s2.empty());
}

int main(void)
{
	size();
	return 0;
}
