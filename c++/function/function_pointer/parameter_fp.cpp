#include <string>
#include <iostream>

using namespace std;

// Declare a type which is a pointer to a function returning bool that takes two const string references
typedef bool (*pf)(const string &, const string &);

bool f(const string &s1, const string &s2)
{
    return s1.size() == s2.size();
}

bool call1(pf);
bool call2(bool (const string &, const string &));
bool call3(bool (*)(const string &, const string &));

int main()
{
    // Declare a function pointer, and initialized to NULL
    pf p = NULL;
    
    // Another way to get function address
    p = &f;

    cout << call1(f) << endl;
    cout << call2(f) << endl;
    cout << call3(f) << endl;

    return 0;
}

bool call1 (pf p)
{
    cout << "Inside call1: ";
    return p("hello", "hello");
}

bool call2 (bool func(const string &, const string &))
{
    cout << "Inside call2: ";
    return func("hello", "hello");
}

bool call3 (bool (*p)(const string &, const string &))
{
    cout << "Inside call3: ";
    return p("hello", "hello");
}


