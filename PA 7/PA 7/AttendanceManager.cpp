#include "AttendanceManager.hpp"

void AttendanceManager::runApp()
{
	std::ifstream courseList;
	courseList.open("classList.csv");

	std::ofstream masterFStr;
	masterFStr.open("master.csv");

	this->reportNum = 1;

	UserChoice choice;
	do
	{
		this->displayMenu();
		cin >> choice;
		system("cls");

		switch (choice)
		{
		case IMPORT_COURSE:
			this->importCourseList(courseList);
			break;
		case LOAD_MASTER:
			break;
		case STORE_MASTER:
			if (masterList.isEmpty())
			{
				cout << "Please import a list\n";
				system("pause");
			}
			else
			{
				this->storeMasterList(masterFStr);
			}
			break;
		case MARK_ABSENCES:
			if (masterList.isEmpty())
			{
				cout << "Please import a list\n";
				system("pause");
			}
			else
			{
				this->markAbsences();
			}
			
			break;
		case EDIT_ABSENCES:
			break;
		case GENERATE_REPORT:
			if (masterList.isEmpty())
			{
				cout << "Please import a list\n";
				system("pause");
			}
			else
			{
				this->generateReport();
			}
			
			break;
		case EXIT:
			if (!masterList.isEmpty())
			{
				this->storeMasterList(masterFStr);
			}
			masterFStr.close();
			courseList.close();
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
	system("cls");
	cout << "Imported course list.\n";
	system("pause");
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
		for (string date : temp.getDatesAbsent().mDatesAbsent)
		{
			fileStream << date << ",";
		}
		fileStream << "\"\n";
		pCurr = pCurr->getNext();
	}
	system("cls");
	cout << "Stored list to master.csv.\n";
	system("pause");
}

void AttendanceManager::markAbsences()
{
	Node<Data>* pCurr = this->masterList.getHead();
	char userChoice;

	// from PA instructions
	time_t t = time(0);
	struct tm* now = localtime(&t);

	string date = "";
	date.append(std::to_string(now->tm_year + 1900));
	date.append("/");
	date.append(std::to_string(now->tm_mon + 1));
	date.append("/");
	date.append(std::to_string(now->tm_mday));

	while (pCurr != nullptr)
	{
		Data temp = pCurr->getData();

		do
		{
			system("cls");
			// from PA instructions
			cout << date << endl;
			cout << "Mark " << temp.getName() << " as absent (y/n): ";

			cin >> userChoice;
		} while (userChoice != 'y' && userChoice != 'n');
		
		if (userChoice == 'y')
		{	// is absent
			int numAbsent = temp.getNumAbsences();
			temp.setNumAbsences(++numAbsent);
			Stack datesAbsent = temp.getDatesAbsent();
			datesAbsent.push(date);
			temp.setDatesAbsent(datesAbsent);
		} 

		pCurr->setData(temp);

		pCurr = pCurr->getNext();
	}
}

void AttendanceManager::generateReport()
{
	int userChoice = 0;

	string reportName = "report";
	reportName.append(std::to_string(this->reportNum));
	reportName.append(".txt");

	std::ofstream reportFile;
	reportFile.open(reportName);

	this->reportNum++;

	do
	{
		cout << "1. Generate report for all students\n";
		cout << "2. Generate report for students with absences that match or exceed target\n";
		cin >> userChoice;
	} while (userChoice < 1 || userChoice > 2);
	
	Node<Data>* pCurr = this->masterList.getHead();

	if (userChoice == 1)
	{
		system("cls");
		cout << "Most Recent Absence\n";
		reportFile << "Most Recent Absence\n";
		while (pCurr != nullptr)
		{
			Data temp = pCurr->getData();
			Stack datesAbsent = temp.getDatesAbsent();
			if (datesAbsent.isEmpty())
			{
				cout << temp.getName() << "\n    No Absences\n";
				reportFile << temp.getName() << "\n    No Absences\n";
			}
			else
			{
				cout << temp.getName() << "\n    " << datesAbsent.peek() << "\n";
				reportFile << temp.getName() << "\n    " << datesAbsent.peek() << "\n";
			}
			
			pCurr = pCurr->getNext();
		}
	}
	else
	{
		int target = 0;
		cout << "Enter target absences: ";
		cin >> target;

		system("cls");

		cout << "Students with more than or equal to " << target << " absenses\n";
		reportFile << "Students with more than or equal to " << target << " absenses\n";

		while (pCurr != nullptr)
		{
			Data temp = pCurr->getData();
			if (temp.getNumAbsences() >= target)
			{
				cout << temp.getName() << "\n    " << "Number of Absenses: " << temp.getNumAbsences() << "\n";
				reportFile << temp.getName() << "\n    " << "Number of Absenses: " << temp.getNumAbsences() << "\n";
			}
			pCurr = pCurr->getNext();
		}
	}
	reportFile.close();
	system("pause");
}