#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>
using namespace std;

void add()
{
	string s1("hello"), s2(" "), s3("world");
	assert((s1+s2+s3+"!") == ("hello world!"));
}

int main()
{
    add();
    return 0;
}
