#include "Data.hpp"

Data::Data(char newChar, string newMorse)
{
	this->mChar = newChar;
	this->mMorse = newMorse;
}

Data::~Data()
{

}

char Data::getChar(void) const
{
	return this->mChar;
}

void Data::setChar(char newChar)
{
	this->mChar = newChar;
}

string Data::getMorse(void) const
{
	return this->mMorse;
}

void Data::setMorse(string newMorse)
{
	this->mMorse;
}

bool operator< (Data lhs, Data rhs)
{
	if (lhs.getChar() < rhs.getChar())
	{
		return true;
	}
	return false;
}

bool operator> (Data lhs, Data rhs)
{
	if (lhs.getChar() > rhs.getChar())
	{
		return true;
	}
	return false;
}