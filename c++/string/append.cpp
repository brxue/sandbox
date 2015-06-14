#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>
using namespace std;

void append()
{
	string s("Hello");
	assert(s.append("World") == "HelloWorld");
}

int main()
{
    append();
    return 0;
}
