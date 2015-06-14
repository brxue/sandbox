#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>

using namespace std;

void read_lines_from_stdin(void)
{
	string line;
    string o;
	cout << "get_lines: " << endl;
	while (getline(cin, line))
	{
        if (line == "end")
            break;
        o += line;
	}
	cout << "Your input is: " << endl;
    cout << o << endl;
}

int main()
{
    read_lines_from_stdin();
    return 0;
}
