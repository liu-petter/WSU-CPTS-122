#include "utils.hpp"

class Stack
{
public:
	Stack();

	string peek();
	string pop();
	void push(string newDate);
	bool isEmpty();
	vector<string> mDatesAbsent;
};