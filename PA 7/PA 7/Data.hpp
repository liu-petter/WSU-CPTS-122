#include "utils.hpp"
#include "Stack.hpp"

class Data
{
public:
	Data(int newRecordNum = -1, int newID = -1, string newName = "", string newEmail = "", string newCredits = "", string newMajor = "", string newLevel = "", int newNumAbsences = 0, Stack newDatesAbsent = {});
	
	void setRecordNum(const int& newRecordNum);
	int getRecordNum() const;
	void setID(const int& newID);
	int getID() const;
	void setName(const string& newName);
	string getName() const;
	void setEmail(const string& newEmail);
	string getEmail() const;
	void setCredits(const string& newCredits);
	string getCredits() const;
	void setMajor(const string& newMajor);
	string getMajor() const;
	void setLevel(const string& newLevel);
	string getLevel() const;
	void setNumAbsences(const int& newNumAbsences);
	int getNumAbsences() const;
	void setDatesAbsent(Stack newDates);
	Stack getDatesAbsent() const;

private:
	int mRecordNum;
	int mID;
	string mName;
	string mEmail;
	string mCredits;
	string mMajor;
	string mLevel;
	int mNumAbsences;
	Stack mDatesAbsent;
};