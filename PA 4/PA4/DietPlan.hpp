#include "FitnessApp.hpp"
class DietPlan
{
public:
	DietPlan(int newGoal = 0, string newName = "", string newDate = "");
	DietPlan(const DietPlan& copy);
	~DietPlan();

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
	int _calorieGoal;
	string _planName;
	string _planDate;
};

std::ostream& operator<< (std::ostream& lhs, DietPlan& rhs);
std::istream& operator>> (std::istream& lhs, DietPlan& rhs);
ifstream& operator>> (ifstream& lhs, DietPlan& rhs);
ofstream& operator<< (ofstream& lhs, DietPlan& rhs);