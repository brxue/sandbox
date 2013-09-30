#include <iostream>
#include <cassert>

using namespace std;

// Operations are open to extension, but can be closed for modification
class Operation
{
	public:
		virtual int op(int a, int b) = 0;
};

class OperationAdd : public Operation
{
	public:
		int op(int a, int b) { return a + b; }
};

class OperationSub : public Operation
{
	public:
		int op(int a, int b) { return a - b; }
};

class OperationMul : public Operation
{
	public:
		int op(int a, int b) { return a * b; }
};

class OperationDiv : public Operation
{
	public:
		int op(int a, int b) { return a / b; }
};

// Factory must be modified whenever new operations needs to be added, like to calculate log(x)
class Factory
{
	public: 
		Operation* createOperation(string type)
		{
			// The decision of which operation to take is made at runtime depending on request from client code
			if (type == "+")
				return new OperationAdd();
			else if (type == "-")
				return new OperationSub();
			else if (type == "*")
				return new OperationMul();
			else if (type == "/")
				return new OperationDiv();
			else 
				return NULL;
		}
};

// --------------------------------------------------------------
// Client code
//

class Calculator
{
	public:
		int main(string type, int a, int b)
		{
			// Whenever the client needs an operatoin, it requests one from the factory
			Operation *o = NULL;
			o = f.createOperation(type);
			return o->op(a, b);
		}
	private:
		Factory f;
};

int main()
{
	Calculator cal;
	assert(cal.main("+", 2, 3) == 5);
	assert(cal.main("-", 2, 3) == -1);
	assert(cal.main("*", 2, 3) == 6);
	assert(cal.main("/", 4, 2) == 2);
}
