#include "utils.hpp"

class Data
{
public:
	Data(char newChar, string newMorse);
	~Data();

	char getChar(void) const;
	void setChar(char newChar);

	string getMorse(void) const;
	void setMorse(string newMorse);

private:
	char mChar;
	string mMorse;
};

bool operator< (Data lhs, Data rhs);
bool operator> (Data lhs, Data rhs);

std::ostream& operator<< (std::ostream& rhs, Data& lhs);