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

void size()
{
	string s1("Hello"), s2;
	if (s1.size() == 5 && s2.empty())
		cout << "[size]: test OK." << endl;
}

void equal()
{
	string s1("Hello"), s2("Hello");
	if (s1==s2 && s1=="Hello")
		cout << "[equal]: test OK." << endl;
}

void assign()
{
	string s1("Hello"), s2, s3, s4;
	s2 = s1;
	s3 = "Hello";
	const char *c4 = "Hello";
	s4 = c4;
	if (s2==s1 && s3==s1 && s4==s1)
		cout << "[assign]: test OK." << endl;
}

void add()
{
	string s1("hello"), s2(" "), s3("world");
	if ((s1+s2+s3+"!") == ("hello world!"))
		cout << "[add]: test OK." << endl;
}

void indexing()
{
	string s("hello");
	ostringstream o;
	for (string::size_type i=0; i!=s.size(); ++i)
	{
		o << s[i];
		s[i] = 'g';
	}
	if ((o.str() == "hello") && (s == "ggggg"))
		cout << "[indexing]: test OK." << endl;
}

void char_type(void)
{
	string s("8eLLO");
	for (string::size_type i=0; i!=s.size(); ++i)
	{
		if (isalnum(s[i]))
			s[i] = isupper(s[i]) ? tolower(s[i]) : s[i];
		else if (isdigit(s[i]))
			s[i] = 'D';
	}
	if (s=="Dello")
		cout << "[char_type]: test OK." << endl;
}

void substring()
{
	string s("Hello World!");
	assert(s.substr(2,5) == "llo W");
	assert(s.substr(2) == "llo World!");
}

void append()
{
	string s("Hello");
	assert(s.append("World") == "HelloWorld");
}

void replace()
{
	string s("HelloWorld");
	assert(s.replace(6, 3, "hjk") == "HelloWhjkd");
}

void find()
{
	string s("Hello World");
	assert(s.find("hi") == string::npos);
	assert(s.find("World") == 6);

	assert(string("AB7C").find_first_of("0123456789") == 2);
	assert(string("AB7C").find_first_of("0123") == string::npos);

	assert(string("782AD").find_first_not_of("0123456789") == 3);
}

void compare()
{
	;
}
void read_write(void)
{
	string s1, s2;
	cout << "Enter two words:";
	cin >> s1 >> s2;
	cout << "Your input is: "; 
	cout << s1 << s2 << endl;
}

void get_chars(void)
{
	char c;
	cout << "get_chars: " << endl;
	while (cin.get(c))
	{
		cout << c << " ";;
	}
	cout << "EOF encounted." << endl;
	cin.clear();// clear EOF flag of cin
}

void get_words(void)
{
	string s;
	cout << "get_words: " << endl;
	while (cin >> s) // CTRL-D to end
	{
		cout << s << " ";
	}
	cout << "EOF encounted." << endl;
	cin.clear();// clear EOF flag of cin
}

void get_lines(void)
{
	string line;
	cout << "get_lines: " << endl;
	while (getline(cin, line))
	{
		cout << line << endl;
	}
	cout << "EOF encounted." << endl;
	cin.clear();// clear EOF flag of cin
}

int main(void)
{
	constructor();
	size();
	equal();
	add();
	indexing();
	char_type();
	assign();
	substring();
	append();
	replace();
	find();
	compare();
	//read_write();
	//get_chars();
	//get_words();
	//get_lines();
	return 0;
}
