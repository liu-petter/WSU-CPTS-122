#include "FitnessApp.hpp"

DietPlan::DietPlan(int newGoal, string newName, string newDate)
{
	_calorieGoal = newGoal;
	_planName =  newName;
	_planDate = newDate;
}

DietPlan::DietPlan(const DietPlan& copy)
{
	_calorieGoal = copy._calorieGoal;
	_planName = copy._planName;
	_planDate = copy._planDate;
}

DietPlan::~DietPlan()
{

}

void DietPlan::setGoal(int newGoal)
{
	_calorieGoal = newGoal;
}

void DietPlan::setName(string newName)
{
	_planName = newName;
}

void DietPlan::setDate(string newDate)
{
	_planDate = newDate;
}

int DietPlan::getGoal(void) const
{
	return _calorieGoal;
}

string DietPlan::getName(void) const
{
	return _planName;
}

string DietPlan::getDate(void) const
{
	return _planDate;
}

void DietPlan::editGoal(void)
{
	int newGoal = 0;
	do
	{
		cout << "Enter new calorie goal: ";
		cin >> newGoal;
	} while (newGoal <= 0);
	_calorieGoal = newGoal;
}

void DietPlan::editName(void)
{
	cout << "Enter new plan name: ";
	getc(stdin);	// deletes newline
	getline(cin, this->_planName);
}

void DietPlan::editPlan(void)
{
	this->editName();
	this->editGoal();
	this->editDate();
}

void DietPlan::editDate(void)
{
	cout << "Enter new plan date (MM/DD/YYYY): ";
	getc(stdin);	// deletes the newline
	getline(cin, this->_planDate);
	/*
	int month = 0, day = 0, year = 0;
	string temp = "", newDate = "";
	cout << "Enter new plan data (M/D/Y): ";

	do
	{	// take in month
		cin >> month;
	} while (month > 12 || month < 1);
	
	// remove slash
	cin >> temp;

	do
	{	// take in day
		cin >> day;
	} while (day > 31 || day < 1);

	// remove slash
	cin >> temp;

	do
	{	// take in year
		cin >> year;
	} while (year < 1);

	//assemble date
	newDate = std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
	this->_planDate = newDate;
	*/
}

std::ostream& operator<< (std::ostream& lhs, DietPlan& rhs)
{
	lhs << rhs.getName() << endl;
	lhs << rhs.getGoal() << endl;
	lhs << rhs.getDate() << endl << endl;
	return lhs;
}

std::istream& operator>> (std::istream& lhs, DietPlan& rhs)
{
	string name = "", date = "", temp1;
	char temp2 = '\0';
	int goal = 0;

	// get plan name
	getline(lhs, name);
	rhs.setName(name);

	// get goal
	lhs >> goal;
	rhs.setGoal(goal);

	// remove newline
	lhs >> temp2;

	// get date
	getline(lhs, date);
	rhs.setDate(date);
	return lhs;
}

ifstream& operator>> (ifstream& lhs, DietPlan& rhs)
{
	string name = "", date = "", temp1;
	char temp2 = '\0';
	int goal = 0;

	// get plan name
	getline(lhs, name);
	rhs.setName(name);

	// get goal
	lhs >> goal;
	rhs.setGoal(goal);

	// remove newline
	lhs >> temp2;

	// get date
	getline(lhs, date);
	rhs.setDate(date);

	// remove empty line
	getline(lhs, temp1);
	return lhs;
}

ofstream& operator<< (ofstream& lhs, DietPlan& rhs)
{
	lhs << rhs.getName() << endl << rhs.getGoal() << endl << rhs.getDate() << endl << endl;
	return lhs;
}