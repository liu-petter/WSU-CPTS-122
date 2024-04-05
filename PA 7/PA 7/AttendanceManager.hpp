#include <iostream>

using std::cout;
using std::cin;
using std::endl;

typedef enum userChoice
{
	IMPORT_COURSE = 1,
	LOAD_MASTER,
	STORE_MASTER,
	MARK_ABSENCES,
	EDIT_ABSENCES,
	GENERATE_REPORT,
	EXIT
} UserChoice;

std::istream& operator>> (std::istream& lhs, UserChoice& choice);

class AttendanceManager
{
public:
	void run();
private:
	void displayMenu();
};