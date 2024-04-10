#include "FitnessApp.hpp"
class ExercisePlan
{
public:
	ExercisePlan(int newGoal = 0, string newName = "", string newDate = "");
	ExercisePlan(const ExercisePlan& copy);
	~ExercisePlan();

	void setGoal(int newGoal);
	void setName(string newName);
	void setDate(string newDate);
	int getGoal(void) const;
	string getName(void) const;
	string getDate(void) const;

	void editGoal(void);
	void editName(void);
	void editDate(void);

	void editPlan(void);
private:
	int _stepsGoal;
	string _planName;
	string _planDate;
};

std::ostream& operator<< (std::ostream& lhs, ExercisePlan& rhs);
std::istream& operator>> (std::istream& lhs, ExercisePlan& rhs);
ifstream& operator>> (ifstream& lhs, ExercisePlan& rhs);
ofstream& operator<< (ofstream& lhs, ExercisePlan& rhs);