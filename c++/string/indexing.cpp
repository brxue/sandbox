#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>
using namespace std;

void indexing()
{
	string s("hello");

	ostringstream o;
	for (string::size_type i=0; i!=s.size(); ++i)
	{
		o << s[i];
		s[i] = 'g';
	}

	assert((o.str() == "hello") && (s == "ggggg"));
}

int main()
{
    indexing();
    return 0;
}
