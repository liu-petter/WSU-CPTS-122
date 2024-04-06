#include "Stack.hpp"

Stack::Stack()
{

}

string Stack::peek()
{
	return this->mDatesAbsent.back();
}

string Stack::pop()
{
	string date = "";
	if (!isEmpty())
	{
		date = this->mDatesAbsent.back();
		this->mDatesAbsent.pop_back();
	}
	return date;
}

void Stack::push(string newDate)
{
	this->mDatesAbsent.push_back(newDate);
}

bool Stack::isEmpty()
{
	return this->mDatesAbsent.empty();
}