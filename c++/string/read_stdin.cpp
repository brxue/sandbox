#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>
using namespace std;

void read_stdin(void)
{
	string s1, s2;
	cout << "Enter two words:";
	cin >> s1 >> s2;
	cout << "Your input is: "; 
	cout << s1 << ' ' << s2 << endl;
}

int main()
{
    read_stdin();
    return 0;
}
