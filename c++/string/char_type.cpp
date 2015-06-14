#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>
using namespace std;

void char_type(void)
{
	string s("8eLLO");
    
	for (string::size_type i=0; i!=s.size(); ++i)
	{
		if (isalnum(s[i])) // Transfer upper case char to lower case char
			s[i] = isupper(s[i]) ? tolower(s[i]) : s[i];

		if (isdigit(s[i])) // Transfer digit to char 'D'
			s[i] = 'D';
	}

	assert(s=="Dello");
}

int main()
{
    char_type();
    return 0;
}
