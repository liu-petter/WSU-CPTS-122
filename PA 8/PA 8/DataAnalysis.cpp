#include "DataAnalysis.hpp"

void DataAnalysis::runAnalysis()
{
	readFile("data.csv");
	displayTrends();
}

void DataAnalysis::readFile(const string& path)
{
	this->mCsvStream.open(path);
	string line = "";

	// get rid of header line
	getline(mCsvStream, line);

	while (getline(mCsvStream, line))
	{
		Data dataPoint = processLine(line);
		insert(dataPoint);
	}
}

Data DataAnalysis::processLine(string& line)
{
	vector<string> procLine = splitLine(line, ",");
	Data dataPoint;
	
	dataPoint.name = procLine[1];
	dataPoint.units = stoi(procLine[0]);
	dataPoint.transactionType = procLine[2];

	return dataPoint;
}

vector<string> DataAnalysis::splitLine(string line, const string& delim)
{
	vector<string> procLine;

	while (!line.empty())
	{
		string s = "";
		if (line.find(delim) != string::npos)
		{	// delim found
			s = line.substr(0, line.find(delim));
			procLine.push_back(s);
			line.erase(0, line.find(delim) + delim.size());
		}
		else
		{
			procLine.push_back(line);
			line.erase(0, line.size());
		}
	}
	return procLine;
}

void DataAnalysis::insert(Data& dataPoint)
{
	if (dataPoint.transactionType == "Purchased")
	{
		this->mTreePurchased.insert(dataPoint.name, dataPoint.units);
	}
	else
	{
		this->mTreeSold.insert(dataPoint.name, dataPoint.units);
	}
}

void DataAnalysis::displayTrends()
{
	cout << "Least Sold: ";
	this->mTreeSold.findSmallest().printData();
	cout << "Most Sold: ";
	this->mTreeSold.findLargest().printData();
	cout << "Least Purchased: ";
	this->mTreePurchased.findSmallest().printData();
	cout << "Most Purchased: ";
	this->mTreePurchased.findLargest().printData();
}