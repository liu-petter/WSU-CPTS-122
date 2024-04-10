#include "FitnessApp.hpp"

ExercisePlan::ExercisePlan(int newGoal, string newName, string newDate)
{
	_stepsGoal = newGoal;
	_planName = newName;
	_planDate = newDate;
}

ExercisePlan::ExercisePlan(const ExercisePlan& copy)
{
	_stepsGoal = copy._stepsGoal;
	_planName = copy._planName;
	_planDate = copy._planDate;
}

ExercisePlan::~ExercisePlan()
{

}

void ExercisePlan::setGoal(int newGoal)
{
	_stepsGoal = newGoal;
}

void ExercisePlan::setName(string newName)
{
	_planName = newName;
}

void ExercisePlan::setDate(string newDate)
{
	_planDate = newDate;
}

int ExercisePlan::getGoal(void) const
{
	return _stepsGoal;
}

string ExercisePlan::getName(void) const
{
	return _planName;
}

string ExercisePlan::getDate(void) const
{
	return _planDate;
}

void ExercisePlan::editGoal(void)
{
	int newGoal = 0;
	do
	{
		cout << "Enter new steps goal: ";
		cin >> newGoal;
	} while (newGoal <= 0);
	_stepsGoal = newGoal;
}

void ExercisePlan::editName(void)
{
	cout << "Enter new plan name: ";
	getc(stdin);	// deletes newline
	getline(cin, this->_planName);
}

void ExercisePlan::editPlan(void)
{
	this->editName();
	this->editGoal();
	this->editDate();
}

void ExercisePlan::editDate(void)
{
	cout << "Enter new plan date (MM/DD/YYYY): ";
	getc(stdin);	// deletes the newline
	getline(cin, this->_planDate);
}

std::ostream& operator<< (std::ostream& lhs, ExercisePlan& rhs)
{
	lhs << rhs.getName() << endl;
	lhs << rhs.getGoal() << endl;
	lhs << rhs.getDate() << endl << endl;
	return lhs;
}

std::istream& operator>> (std::istream& lhs, ExercisePlan& rhs)
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

ifstream& operator>> (ifstream& lhs, ExercisePlan& rhs)
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

ofstream& operator<< (ofstream& lhs, ExercisePlan& rhs)
{
	lhs << rhs.getName() << endl;
	lhs << rhs.getGoal() << endl;
	lhs << rhs.getDate() << endl << endl;
	return lhs;
}