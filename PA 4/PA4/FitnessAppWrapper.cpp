#include "FitnessApp.hpp"

void FitnessAppWrapper::runApp()
{
	MenuSelection userSelection;

	ifstream dietInfile, exerciseInfile;
	ofstream dietOutfile, exerciseOutfile;

	do
	{
		userSelection = this->displayMenu();
		system("cls");
		switch (userSelection)
		{
		case LOAD_DIET:
			dietInfile.open("dietPlan.txt");
			this->loadWeeklyPlan(dietInfile, this->weeklyDietPlan);
			dietInfile.close();
			break;
		case LOAD_EXERCISE:
			exerciseInfile.open("exercisePlan.txt");
			this->loadWeeklyPlan(exerciseInfile, this->weeklyExercisePlan);
			exerciseInfile.close();
			break;
		case STORE_DIET:
			if (!weeklyDietPlan.empty())
			{
				dietOutfile.open("dietPlan.txt");
				this->storeWeeklyPlan(dietOutfile, this->weeklyDietPlan);
				dietOutfile.close();
			}
			else
			{
				cout << "Weekly diet plan is empty" << endl;
			}
			break;
		case STORE_EXERCISE:
			if (!weeklyExercisePlan.empty())
			{
				exerciseOutfile.open("exercisePlan.txt");
				this->storeWeeklyPlan(exerciseOutfile, this->weeklyExercisePlan);
				exerciseOutfile.close();
			}
			else
			{
				cout << "Weekly exercise plan is empty" << endl;
			}
			break;
		case DISPLAY_DIET:
			this->displayWeeklyPlan(this->weeklyDietPlan);
			break;
		case DISPLAY_EXERCISE:
			this->displayWeeklyPlan(this->weeklyExercisePlan);
			break;
		case EDIT_DIET:
			if (!weeklyDietPlan.empty())
			{
				this->choosePlan(weeklyDietPlan);
			}
			else
			{
				cout << "Weekly diet plan is empty" << endl;
			}
			break;
		case EDIT_EXERCISE:
			if (!weeklyExercisePlan.empty())
			{
				this->choosePlan(weeklyExercisePlan);
			}
			else
			{
				cout << "Weekly exercise plan is empty" << endl;
			}
			break;
		case EXIT:
			break;
		}
		system("pause");
		system("cls");
	} while (userSelection != 9);
	return;
}

MenuSelection FitnessAppWrapper::displayMenu()
{
	MenuSelection selec;
	cout << "Fitness App" << endl;
	cout << "1. Load weekly diet plan from file." << endl;
	cout << "2. Load weekly exercise plan from file." << endl;
	cout << "3. Store weekly diet plan to file." << endl;
	cout << "4. Store weekly exercise plan to file." << endl;
	cout << "5. Display weekly diet plan to screen." << endl;
	cout << "6. Display weekly exercise plan to screen." << endl;
	cout << "7. Edit daily diet plan." << endl;
	cout << "8. Edit daily exercise plan." << endl;
	cout << "9. Exit." << endl;

	scanf("%d", &selec);
	return selec;
}

void FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, DietPlan& plan) 
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, vector<DietPlan>& weeklyPlan)
{
	for (int i = 0; i<7; i++)
	{
		DietPlan newPlan;
		loadDailyPlan(fileStream, newPlan);
		weeklyPlan.push_back(newPlan);
	}
	cout << "Files Loaded" << endl;
}

void FitnessAppWrapper::loadDailyPlan(ifstream& fileStream, ExercisePlan& plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(ifstream& fileStream, vector<ExercisePlan>& weeklyPlan)
{
	for (int i = 0; i < 7; i++)
	{
		ExercisePlan newPlan;
		loadDailyPlan(fileStream, newPlan);
		weeklyPlan.push_back(newPlan);
	}
	cout << "Files Loaded" << endl;
}

void FitnessAppWrapper::displayDailyPlan(DietPlan& plan)
{
	cout << plan;
}

void FitnessAppWrapper::displayWeeklyPlan(vector<DietPlan>& weeklyPlan)
{
	for (DietPlan plan : weeklyPlan)
	{
		this->displayDailyPlan(plan);
	}
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan)
{
	cout << plan;
}

void FitnessAppWrapper::displayWeeklyPlan(vector<ExercisePlan>& weeklyPlan)
{
	for (ExercisePlan plan : weeklyPlan)
	{
		this->displayDailyPlan(plan);
	}
}

void FitnessAppWrapper::storeDailyPlan(ofstream& fileStream, DietPlan& plan)
{
	fileStream << plan;
}

void FitnessAppWrapper::storeWeeklyPlan(ofstream& fileStream, vector<DietPlan>& weeklyPlan)
{
	for (DietPlan plan : weeklyPlan)
	{
		storeDailyPlan(fileStream, plan);
	}
	cout << "Files Stored" << endl;
}

void FitnessAppWrapper::storeDailyPlan(ofstream& fileStream, ExercisePlan& plan)
{
	fileStream << plan;
}

void FitnessAppWrapper::storeWeeklyPlan(ofstream& fileStream, vector<ExercisePlan>& weeklyPlan)
{
	for (ExercisePlan plan : weeklyPlan)
	{
		storeDailyPlan(fileStream, plan);
	}
	cout << "Files Stored" << endl;
}

void FitnessAppWrapper::editDailyPlan(vector<DietPlan>& weeklyPlan, int targetDay)
{
	weeklyPlan[targetDay].editPlan();
}

void FitnessAppWrapper::editDailyPlan(vector<ExercisePlan>& weeklyPlan, int targetDay)
{
	weeklyPlan[targetDay].editPlan();
}

void FitnessAppWrapper::choosePlan(vector<DietPlan>& weeklyPlan)
{
	int choice = 0;
	do
	{
		system("cls");
		this->displayWeeklyPlan(weeklyPlan);
		cout << "Choose plan 1-7: ";
		cin >> choice;
	} while (choice < 1 || choice > 7);
	this->editDailyPlan(weeklyPlan, choice - 1);
}

void FitnessAppWrapper::choosePlan(vector<ExercisePlan>& weeklyPlan)
{
	int choice = 0;
	do
	{
		system("cls");
		this->displayWeeklyPlan(weeklyPlan);
		cout << "Choose plan 1-7: ";
		cin >> choice;
	} while (choice < 1 || choice > 7);
	this->editDailyPlan(weeklyPlan, choice - 1);
}