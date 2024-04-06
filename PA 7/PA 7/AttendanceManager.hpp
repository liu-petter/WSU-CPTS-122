#include "utils.hpp"
#include "Data.hpp"
#include "List.hpp"

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
	void runApp();

private:
	List<Data> masterList;

	void displayMenu();
	void importCourseList(std::ifstream& fileStream);
	void storeMasterList(std::ofstream& fileStream);
	void markAbsences();

	// desc: process a string into a Data class
	Data processLine(string line);

	// desc: splits a string based on the delim
	vector<string> split(string line, string delim);
};