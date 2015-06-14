#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>
using namespace std;

void assign()
{
	string s1("Hello"), s2, s3, s4;
	s2 = s1;
	s3 = "Hello";
	const char *c4 = "Hello";
	s4 = c4;
	assert(s2==s1 && s3==s1 && s4==s1);
}

int main()
{
    assign();
    return 0;
}
