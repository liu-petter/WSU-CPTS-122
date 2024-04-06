#include <vector>
#include <string>

using std::vector;
using std::string;

class Stack
{
public:
	Stack();

	string peek();
	string pop();
	void push(string newDate);
	bool isEmpty();

private:
	vector<string> mDatesAbsent;
};