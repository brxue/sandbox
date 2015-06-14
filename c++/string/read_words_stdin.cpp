#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cassert>

using namespace std;

void read_words_from_stdin(void)
{
	string s;
    string o;
	cout << "get_words: " << endl;
	while (cin >> s)
	{
        if (s == "end")
            break;
        o += s;
	}
	cout << "Your input is:" << endl;
    cout << o << endl;
}

int main()
{
    read_words_from_stdin();
    return 0;
}
