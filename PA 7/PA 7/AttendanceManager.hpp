#include <iostream>
#include <fstream>
#include <vector>
#include "List.hpp"
#include "Data.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

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
	List<Data> masterList;

	void displayMenu();
	void importCourseList(std::ifstream& fileStream);

	// desc: process a string into a Data class
	Data processLine(string line);

	// desc: splits a string based on the delim
	vector<string> split(string line, string delim);
};