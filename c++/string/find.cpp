#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>
using namespace std;

void find()
{
	string s("Hello World");
	assert(s.find("hi") == string::npos);
	assert(s.find("World") == 6);

	assert(string("AB7C").find_first_of("0123456789") == 2);
	assert(string("AB7C").find_first_of("0123") == string::npos);

	assert(string("782AD").find_first_not_of("0123456789") == 3);
}

int main(void)
{
	find();
	return 0;
}
