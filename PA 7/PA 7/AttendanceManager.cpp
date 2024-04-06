#include "AttendanceManager.hpp"

void AttendanceManager::run()
{
	std::ifstream courseList;
	courseList.open("classList.csv");

	std::ofstream masterFStr;
	masterFStr.open("master.csv");

	UserChoice choice;
	do
	{
		this->displayMenu();
		cin >> choice;

		switch (choice)
		{
		case IMPORT_COURSE:
			this->importCourseList(courseList);
			break;
		case LOAD_MASTER:
			break;
		case STORE_MASTER:
			this->storeMasterList(masterFStr);
			break;
		case MARK_ABSENCES:
			break;
		case EDIT_ABSENCES:
			break;
		case GENERATE_REPORT:
			break;
		case EXIT:
			break;
		}
		system("cls");
	} while (choice != EXIT);
}

void AttendanceManager::displayMenu()
{
	cout << "Attendance Manager\n";
	cout << "1. Import course list\n";
	cout << "2. Load master list\n";
	cout << "3. Store master list\n";
	cout << "4. Mark absences\n";
	cout << "5. Edit absences\n";
	cout << "6. Generate report\n";
	cout << "7. Exit\n";
}

std::istream& operator>> (std::istream& lhs, UserChoice& choice)
{
	int input;
	do
	{	// validation
		lhs >> input;
	} while (input < 1 || input > 7);

	switch (input)
	{
	case 1:
		choice = IMPORT_COURSE;
		break;
	case 2:
		choice = LOAD_MASTER;
		break;
	case 3:
		choice = STORE_MASTER;
		break;
	case 4:
		choice = MARK_ABSENCES;
		break;
	case 5:
		choice = EDIT_ABSENCES;
		break;
	case 6:
		choice = GENERATE_REPORT;
		break;
	case 7:
		choice = EXIT;
		break;
	default:
		choice = EXIT;
	}
	return lhs;
}

void AttendanceManager::importCourseList(std::ifstream& fileStream)
{
	this->masterList.~List();	// overwrites list

	string line = "";

	getline(fileStream, line);	// get rid of first line

	while (getline(fileStream, line))
	{
		Data newStudent(this->processLine(line));
		this->masterList.insertAtFront(newStudent);
	}
}

Data AttendanceManager::processLine(string line)
{
	vector<string> procLine = split(line, ",");

	// process name
	string last = procLine[2], first = procLine[3];
	last.erase(0, 1).append(", ");
	first.erase(first.size() - 1, first.size());
	last.append(first);

	Data newStudent(stoi(procLine[0]), stoi(procLine[1]), last, procLine[4], procLine[5], procLine[6], procLine[7]);
	return newStudent;
}

vector<string> AttendanceManager::split(string line, string delim)
{
	vector<string> procLine;
	int index = 0;

	while (!line.empty() && index != -1)
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

void AttendanceManager::storeMasterList(std::ofstream& fileStream)
{
	Node<Data>* pCurr = this->masterList.getHead();
	fileStream << ",ID,Name,Email,Units,Program,Level,Absences,Dates of Absences\n";
	while (pCurr != nullptr)
	{
		Data temp = pCurr->getData();
		fileStream << temp.getRecordNum() << "," << temp.getID() << ",\"" << temp.getName() << "\"," << temp.getCredits() << "," << temp.getMajor() << "," << temp.getLevel() << "," << temp.getNumAbsences() << ",\"";
		for (string date : temp.getDatesAbsent())
		{
			fileStream << date << ",";
		}
		fileStream << "\"\n";
		pCurr = pCurr->getNext();
	}
}