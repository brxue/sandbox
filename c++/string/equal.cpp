#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>
using namespace std;

void equal()
{
	string s1("Hello"), s2("Hello");
	assert(s1==s2 && s1=="Hello");
}

int main(void)
{
	equal();
	return 0;
}
