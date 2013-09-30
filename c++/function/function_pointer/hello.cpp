#include <string>
#include <iostream>

using namespace std;

bool f(const string &s1, const string &s2)
{
    return s1.size() == s2.size();
}

int main()
{
    // Declare a pointer to a function returning bool that takes two const string references
    bool (*pf)(const string &, const string &);

    // Function name is the address of the function
    pf = f;
    
    // Calling the function through pointer
    cout << pf("hi", "hello") << endl;
    cout << (*pf)("hi", "oh") << endl;// Another equalivant pattern

    return 0;
}
