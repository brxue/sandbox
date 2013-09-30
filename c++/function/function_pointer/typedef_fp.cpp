#include <string>
#include <iostream>

using namespace std;

// Declare a type which is a pointer to a function returning bool that takes two const string references
typedef bool (*pf)(const string &, const string &);

bool f(const string &s1, const string &s2)
{
    return s1.size() == s2.size();
}

int main()
{
    // Declare a function pointer, and initialized to NULL
    pf p = NULL;
    
    // Another way to get function address
    p = &f;

    cout << p("hi", "hello") << endl;
    cout << (*p)("hi", "oh") << endl;

    return 0;
}
