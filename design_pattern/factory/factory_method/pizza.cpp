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

class NyCheesePizza : public Pizza
{
	public:
		void prepare() { cout << "[New York] Preparing cheese pizza..." << endl; }
		void bake() { cout << "[New York] Baking cheese pizza..." << endl; }
		void cut() { cout << "[New York] Cutting cheese pizza..." << endl; }
		void box() { cout << "[New York] Boxing cheese pizza..." << endl; }
}; 

class NyGreekPizza : public Pizza
{
	public:
		void prepare() { cout << "[New York] Preparing greek pizza..." << endl; }
		void bake() { cout << "[New York] Baking greek pizza..." << endl; }
		void cut() { cout << "[New York] Cutting greek pizza..." << endl; }
		void box() { cout << "[New York] Boxing greek pizza..." << endl; }
}; 

class ChicagoCheesePizza : public Pizza
{
	public:
		void prepare() { cout << "[Chicago] Preparing cheese pizza..." << endl; }
		void bake() { cout << "[Chicago] Baking cheese pizza..." << endl; }
		void cut() { cout << "[Chicago] Cutting cheese pizza..." << endl; }
		void box() { cout << "[Chicago] Boxing cheese pizza..." << endl; }
}; 

class ChicagoGreekPizza : public Pizza
{
	public:
		void prepare() { cout << "[Chicago] Preparing greek pizza..." << endl; }
		void bake() { cout << "[Chicago] Baking greek pizza..." << endl; }
		void cut() { cout << "[Chicago] Cutting greek pizza..." << endl; }
		void box() { cout << "[Chicago] Boxing greek pizza..." << endl; }
};

class Factory
{
	public:
		// Factory Method: implemented in subclass
		virtual Pizza* createPizza(string type) = 0;
};

// What kind of objects to be created is decided in subclass
class NyPizzaFactory : public Factory
{
	public:
		// The subclass handles object instantiation
		Pizza* createPizza(string type)
		{
			if (type == "cheese")
				return new NyCheesePizza();
			else if (type == "greek")
				return new NyGreekPizza();
			else 
				return NULL;
		}
};

// What kind of objects to be created is decided in subclass
class ChicagoPizzaFactory : public Factory
{
	public:
		// The subclass handles object instantiation
		Pizza* createPizza(string type)
		{
			if (type == "cheese")
				return new ChicagoCheesePizza();
			else if (type == "greek")
				return new ChicagoGreekPizza();
			else 
				return NULL;
		}
};

// ------------------------------------------------
// Client code
//

// Depends on abstraction ---- Pizza, but not concret classes ---- kinds of specific pizzas
class PizzaStore
{
	public:
		PizzaStore(Factory *f) {this->f = f;}
		Pizza* orderPizza(string type)
		{
			// A factory method isolate the Client from knowing what kind of concret product(Pizza) is actually created
			p = f->createPizza(type);
			p->prepare();
			p->bake();
			p->cut();
			p->box();
		}
	private:
		// PizzaStore depends only on abstract classes
		Factory *f;
		Pizza *p;
};

/*
class NyPizzaStore : public PizzaStore
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
		NyPizzaFactory f;
		Pizza *p;
};

class ChicagoPizzaStore : public PizzaStore
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
		ChicagoPizzaFactory f;
		Pizza *p;
};
*/
int main()
{
	// The client just needs to know what kind of Pizza it needs, and then pass corresponding concret Factory to PizzaStore
	PizzaStore *nyStore = new PizzaStore(new NyPizzaFactory());
	nyStore->orderPizza("cheese");
	nyStore->orderPizza("greek");

	PizzaStore *chicagoStore = new PizzaStore(new ChicagoPizzaFactory());
	chicagoStore->orderPizza("cheese");
	chicagoStore->orderPizza("greek");
	return 0;
}

