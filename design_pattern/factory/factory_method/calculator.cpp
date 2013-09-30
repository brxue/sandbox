#include <iostream>
#include <cassert>

using namespace std;

// -------------------------------------------------------------------
//
// Operations are closed to modification, but open to extension
//
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

// -------------------------------------------------------------------
//
// Factories are closed to modification, but open to extension
//
class Factory
{
	public: 
		// Factory Method
		virtual Operation* createOperation() = 0;
};

// Subclass decides which operation to create
class AddFactory : public Factory
{
	public:
		Operation* createOperation() { return new OperationAdd(); }
};

// Subclass decides which operation to create
class SubFactory : public Factory
{
	public:
		Operation* createOperation() { return new OperationSub(); }
};

// Subclass decides which operation to create
class MulFactory : public Factory
{
	public:
		Operation* createOperation() { return new OperationMul(); }
};

// Subclass decides which operation to create
class DivFactory : public Factory
{
	public:
		Operation* createOperation() { return new OperationDiv(); }
};


// ----------------------------------------------------------------------------
// Client code
//
class Calculator
{
	public:
		// The condition switch is now moved to client itself
		// Client decides by itself what kind of factories it needs
		int main(string type, int a, int b)
		{
			if (type == "+")
				f = new AddFactory();
			else if (type == "-")
				f = new SubFactory();
			else if (type == "*")
				f = new MulFactory();
			else if (type == "/")
				f = new DivFactory();

			// Whenever the client needs an operatoin, it requests one from the factory
			Operation *o = NULL;
			o = f->createOperation();

			return o->op(a, b);
		}
	private:
		Factory *f;
};

int main()
{
	Calculator cal;
	assert(cal.main("+", 2, 3) == 5);
	assert(cal.main("-", 2, 3) == -1);
	assert(cal.main("*", 2, 3) == 6);
	assert(cal.main("/", 4, 2) == 2);
}
