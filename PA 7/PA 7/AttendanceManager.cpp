#include "AttendanceManager.hpp"

void AttendanceManager::run()
{
	UserChoice choice;
	do
	{
		this->displayMenu();
		cin >> choice;

		switch (choice)
		{
		case IMPORT_COURSE:
			break;
		case LOAD_MASTER:
			break;
		case STORE_MASTER:
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