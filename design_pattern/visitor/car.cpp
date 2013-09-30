#include <string>
#include <iostream>
#include <vector>
 
using namespace std;
 
class Wheel;
class Engine;
class Body;
class Car;
 
// Interface to all car 'elements'
struct CarElementVisitor 
{
	// Function overloading, visit each element of a car
	virtual void visit(Wheel& wheel) const = 0;
  	virtual void visit(Engine& engine) const = 0;
  	virtual void visit(Body& body) const = 0;
	
	// visit entire car
	virtual void visitCar(Car& car) const = 0;
	virtual ~CarElementVisitor() {}
};
 
// Interface to one element 
struct CarElement 
{
	virtual void accept(const CarElementVisitor& visitor) = 0;
	virtual ~CarElement() {}
};
 
// Wheel element, there are four wheels with unique names
class Wheel : public CarElement
{
	public:
		explicit Wheel(const string& name) : name_(name)
  		{
  		}
  		const string& getName() const 
  		{
			return name_;
  		}
  		void accept(const CarElementVisitor& visitor)  
  		{
			visitor.visit(*this);
  		}
	private:
		string name_;
};
 
// Engine
class Engine : public CarElement
{
	public:
		void accept(const CarElementVisitor& visitor) 
		{
			visitor.visit(*this);
		}
};
 
// Body
class Body : public CarElement
{
	public:
		void accept(const CarElementVisitor& visitor) 
  		{
			visitor.visit(*this);
  		}
};
 
// Car, all car elements(parts) together
class Car 
{
	public:
		vector<CarElement*>& getElements()
  		{
			return elements_;
  		}
  		Car() 
  		{
			// Assume that neither push_back nor Wheel(const string&) may throw
  		  	elements_.push_back( new Wheel("front left") );
  		  	elements_.push_back( new Wheel("front right") );
  		  	elements_.push_back( new Wheel("back left") );
  		  	elements_.push_back( new Wheel("back right") );
  		  	elements_.push_back( new Body() );
  		  	elements_.push_back( new Engine() );
  		}
  		~Car()
  		{
			for(vector<CarElement*>::iterator it = elements_.begin(); it != elements_.end(); ++it)
  		  	{
		  	  	delete *it;
  		  	}
  		}
	private:
		vector<CarElement*> elements_;
};
 
// PrintVisitor and DoVisitor show by using a different implementation the Car class is unchanged
// even though the algorithm is different in PrintVisitor and DoVisitor.
//
// Suppose Car is stable, we can add more visitors to visit Car but without changing Car's implementation
class CarElementPrintVisitor : public CarElementVisitor 
{
	public:
		void visit(Wheel& wheel) const
  		{ 
			cout << "Visiting " << wheel.getName() << " wheel" << endl;
  		}
  		void visit(Engine& engine) const
  		{
			cout << "Visiting engine" << endl;
  		}
  		void visit(Body& body) const
  		{
			cout << "Visiting body" << endl;
  		}
  		void visitCar(Car& car) const
  		{
			cout << endl << "Visiting car" << endl;

  		  	vector<CarElement*>& elems = car.getElements();
  		  	for(vector<CarElement*>::iterator it = elems.begin(); it != elems.end(); ++it)
  		  	{
				// Each element accept visito's visiting
				(*it)->accept(*this);     // This issues the callback i.e. to this from the element  
  		  	}

  		  	cout << "Visited car" << endl;
  		}
};
 
class CarElementDoVisitor : public CarElementVisitor 
{
	public:
		// these are specific implementations added to the original object without modifying the original struct
  		void visit(Wheel& wheel) const
  		{
			cout << "Kicking my " << wheel.getName() << " wheel" << endl;
  		}
  		void visit(Engine& engine) const
  		{
			cout << "Starting my engine" << endl;
  		}
  		void visit(Body& body) const
  		{
			cout << "Moving my body" << endl;
  		}
  		void visitCar(Car& car) const
  		{
			cout << endl << "Starting my car" << endl;

  		  	vector<CarElement*>& elems = car.getElements();
  		  	for(vector<CarElement*>::iterator it = elems.begin(); it != elems.end(); ++it)
  		  	{
				// Each element accepts visitor's visiting
				(*it)->accept(*this);     // this issues the callback i.e. to this from the element  
  		  	}

  		  	cout << "Stopped car" << endl;
  		}
};
 
int main()
{
	Car car;
	CarElementPrintVisitor printVisitor;
	CarElementDoVisitor doVisitor;
	
	printVisitor.visitCar(car);
	doVisitor.visitCar(car);
	
	return 0;
}
