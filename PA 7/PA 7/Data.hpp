#include <string>
#include <vector>

using std::vector;
using std::string;

class Data
{
public:
	Data(int newRecordNum = -1, int newID = -1, string newName = "", string newEmail = "", string newMajor = "", string newLevel = "", int newNumAbsences = 0, vector<string> newDatesAbsent);
	
	void setNumAbsences(const int& newNumAbsences);
	int getNumAbsences() const;

private:
	int mRecordNum;
	int mID;
	string mName;
	string mEmail;
	string mMajor;
	string mLevel;
	int mNumAbsences;
	vector<string> mDatesAbsent;
};