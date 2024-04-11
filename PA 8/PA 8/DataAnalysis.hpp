#include "BST.hpp"

typedef struct _data
{
	string name;
	int units;
	string transactionType;
} Data;

class DataAnalysis
{
public:
	void runAnalysis();
private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	void readFile(const string& path);
	Data processLine(string& line);
	vector<string> splitLine(string line, const string& delim);
	void insert(Data& dataPoint);
	void displayTrends();
};