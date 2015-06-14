#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>
using namespace std;

void substring()
{
	string s("Hello World!");
	assert(s.substr(2,5) == "llo W");
	assert(s.substr(2) == "llo World!");
}

int main()
{
    substring();
    return 0;
}
