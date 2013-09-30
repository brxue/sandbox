#include <iostream>
#include <string>
using namespace std;

// 1. Add an accept(Visitor) method to the "element" hierarchy
// 2. Create a "visitor" base class w/ a visit() method for every "element" type
// 3. Create a "visitor" derived class for each "operation" to do on "elements"
// 4. Client creates "visitor" objects and passes each to accept() calls

class This;
class That;
class TheOther;

class Visitor
{
	public:
		// Note: function overloading, visit each 'element' which is passed into the 'visit' function
    	virtual void visit(This *e) = 0;
    	virtual void visit(That *e) = 0;
    	virtual void visit(TheOther *e) = 0;
};

class Element
{
	public:
		// each element accept visitor's access
    	virtual void accept(Visitor &v) = 0;
};

class This: public Element
{
	public:
		void accept(Visitor &v)
		{
			v.visit(this);
		}
    	string thiss()
    	{
    	    return "This";
    	}
};

class That: public Element
{
	public:
		void accept(Visitor &v)
		{
			v.visit(this);
		}
    	string that()
    	{
    	    return "That";
    	}
};

class TheOther: public Element
{
	public:
		void accept(Visitor &v)
		{
			v.visit(this);
		}
    	string theOther()
    	{
    	    return "TheOther";
    	}
};

class UpVisitor: public Visitor
{
    void visit(This *e)
    {
        cout << "do Up on " + e->thiss() << '\n';
    }
    void visit(That *e)
    {
        cout << "do Up on " + e->that() << '\n';
    }
    void visit(TheOther *e)
    {
        cout << "do Up on " + e->theOther() << '\n';
    }
};

class DownVisitor: public Visitor
{
    void visit(This *e)
    {
        cout << "do Down on " + e->thiss() << '\n';
    }
    void visit(That *e)
    {
        cout << "do Down on " + e->that() << '\n';
    }
    void visit(TheOther *e)
    {
        cout << "do Down on " + e->theOther() << '\n';
    }
};

// Client
//
int main()
{
	Element *list[] = {new This(), new That(), new TheOther()};

  	UpVisitor up; 
  	DownVisitor down;  
	
	// Each element accept visitor's visiting
	// That is to say, each visitor is visiting each element
	
  	for (int i = 0; i < 3; i++)
  	  list[i]->accept(up);

  	for (int i = 0; i < 3; i++)
  	  list[i]->accept(down);

	// Suppose 'element' is stable, then we can add more visitors (for example, LeftVisitor and RightVisitor) to them without changing elements,
	// That is to say, element is closed to modification
}
