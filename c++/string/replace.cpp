#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>
using namespace std;

void replace()
{
	string s("HelloWorld");
	assert(s.replace(6, 3, "hjk") == "HelloWhjkd");
}

int main()
{
    replace();
    return 0;
}
