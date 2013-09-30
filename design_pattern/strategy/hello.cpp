#include <iostream>

using namespace std;

class Strategy
{
	public: 
		virtual void execute() = 0;
};

class StrategyA : public Strategy
{
	public: 
		void execute()
		{
			cout << "Executing algorithm A" << endl;
		}
};

class StrategyB : public Strategy
{
	public: 
		void execute()
		{
			cout << "Executing algorithm B" << endl;
		}
};

class StrategyC : public Strategy
{
	public: 
		void execute()
		{
			cout << "Executing algorithm C" << endl;
		}
};

class Context
{
	private:
		Strategy *s;
	
	public:
		Context(Strategy *s) {this->s = s;}
		Context() {this->s = NULL;}
		void setContext(Strategy *s) {this->s = s;}
		void execute() {s->execute();}
};

int main()
{
	Context ctx;
	StrategyA sA;
	StrategyB sB;
	StrategyC sC;

	ctx.setContext(&sA);
	ctx.execute();

	ctx.setContext(&sB);
	ctx.execute();

	ctx.setContext(&sC);
	ctx.execute();

	return 0;
}

