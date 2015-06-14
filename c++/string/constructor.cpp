#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>
using namespace std;

void constructor()
{
	string s1;
	string s2("Hello World");
	string s3(s2);
	string s4(4, 'C');
	string s5(s2.begin(), s2.begin()+5);
	string s6("Hello", 2);
	string s7(s2, 3);
	string s8(s2, 3, 2);
	
	assert(s1=="");
	assert(s2=="Hello World");
   	assert(s3==s2);
	assert(s4=="CCCC");
	assert(s5=="Hello");
	assert(s6=="He");
	assert(s7=="lo World");
	assert(s8=="lo");
}

int main(void)
{
	constructor();
	return 0;
}
