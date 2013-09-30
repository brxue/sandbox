#include <iostream>

using namespace std;

class Pizza
{
	public:
		virtual void prepare() = 0;
		virtual void bake() = 0;
		virtual void cut() = 0;
		virtual void box() = 0;
};

class CheesePizza : public Pizza
{
	public:
		void prepare() { cout << "Preparing cheese pizza..." << endl; }
		void bake() { cout << "Baking cheese pizza..." << endl; }
		void cut() { cout << "Cutting cheese pizza..." << endl; }
		void box() { cout << "Boxing cheese pizza..." << endl; }
}; 

class GreekPizza : public Pizza
{
	public:
		void prepare() { cout << "Preparing greek pizza..." << endl; }
		void bake() { cout << "Baking greek pizza..." << endl; }
		void cut() { cout << "Cutting greek pizza..." << endl; }
		void box() { cout << "Boxing greek pizza..." << endl; }
}; 

class Factory
{
	public:
		Pizza* createPizza(string type)
		{
			if (type == "cheese")
				return new CheesePizza();
			else if (type == "greek")
				return new GreekPizza();
			else 
				return NULL;
		}
};

// ------------------------------------------------
// Client code
//

class PizzaStore
{
	public:
		Pizza* orderPizza(string type)
		{
			p = f.createPizza(type);
			p->prepare();
			p->bake();
			p->cut();
			p->box();
		}
	private:
		Factory f;
		Pizza *p;
};

int main()
{
	PizzaStore store;
	store.orderPizza("cheese");
	store.orderPizza("greek");

	return 0;
}

