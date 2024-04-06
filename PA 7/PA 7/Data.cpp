#include "Data.hpp"

Data::Data(int newRecordNum, int newID, string newName, string newEmail, string newCredits, string newMajor, string newLevel, int newNumAbsences, vector<string> newDatesAbsent)
{
	mRecordNum = newRecordNum;
	mID = newID;
	mName = newName;
	mEmail = newEmail;
	mCredits = newCredits;
	mMajor = newMajor;
	mLevel = newLevel;
	mNumAbsences = newNumAbsences;
	mDatesAbsent = newDatesAbsent;
}

void Data::setRecordNum(const int& newRecordNum)
{
	mRecordNum = newRecordNum;
}

int Data::getRecordNum() const
{
	return mRecordNum;
}

void Data::setID(const int& newID)
{
	mID = newID;
}

int Data::getID() const
{
	return mID;
}

void Data::setName(const string& newName)
{
	mName = newName;
}

string Data::getName() const
{
	return mName;
}

void Data::setEmail(const string& newEmail)
{
	mEmail = newEmail;
}

string Data::getEmail() const
{
	return mEmail;
}

void Data::setCredits(const string& newCredits)
{
	mCredits = newCredits;
}

string Data::getCredits() const
{
	return mCredits;
}

void Data::setMajor(const string& newMajor)
{
	mMajor = newMajor;
}

string Data::getMajor() const
{
	return mMajor;
}

void Data::setLevel(const string& newLevel)
{
	mLevel = newLevel;
}

string Data::getLevel() const
{
	return mLevel;
}

int Data::getNumAbsences() const
{
	return mNumAbsences;
}

void Data::setNumAbsences(const int& newNumAbsences)
{
	mNumAbsences = newNumAbsences;
}