#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class gt_integer 
{
	public:
		gt_integer(int val): _val(val){}
		bool operator() (int val) { return _val > val ? true : false; }
	private:
		int _val;
};
void greater_than_integer(void)
{
	gt_integer gt(5);

	assert(gt(6) == false);
	assert(gt(4) == true);
}

class gt_string
{
	public:
		gt_string(int val): _val(val){}
		bool operator() (string s) { return _val > s.size() ? true : false; }
	private:
		int _val;
};
void greater_than_size_of_string(void)
{
	gt_string gt(5);

	assert(gt("Hello World") == false);
	assert(gt("Hi") == true);

	vector<string> words;
	words.push_back("hello");
	words.push_back("hi");
	words.push_back("nihao");
	words.push_back("how are you?");

	assert(count_if(words.begin(), words.end(), gt_string(3)) == 1);
}

int main()
{
	greater_than_integer();
	greater_than_size_of_string();

	return 0;
}

