#include "Data.hpp"

Data::Data(int newRecordNum, int newID, string newName, string newEmail, string newMajor, string newLevel, int newNumAbsences, vector<string> newDatesAbsent)
{
	mRecordNum = newRecordNum;
	mID = newID;
	mName = newName;
	mEmail = newEmail;
	mMajor = newMajor;
	mLevel = newLevel;
	mNumAbsences = newNumAbsences;
	mDatesAbsent = newDatesAbsent;
}

int Data::getNumAbsences() const
{
	return mNumAbsences;
}

void Data::setNumAbsences(const int& newNumAbsences)
{
	mNumAbsences = newNumAbsences;
}