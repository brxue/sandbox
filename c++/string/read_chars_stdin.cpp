#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>

using namespace std;

void read_chars_from_stdin(void)
{
	char c;
    string s;
	cout << "get_chars (input '.' to end): " << endl;
	while (cin.get(c))
	{
        if (c == '.')
            break;
        s.push_back(c);
	}
    
    cout << "Your input is:" << endl;
    cout << s << endl;
}

int main()
{
    read_chars_from_stdin();
    return 0;
}
