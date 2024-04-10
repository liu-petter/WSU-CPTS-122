#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>	//so i can read in enum as int

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

#include "DietPlan.hpp"
#include "ExercisePlan.hpp"

typedef enum _menuSelection
{
	LOAD_DIET = 1,
	LOAD_EXERCISE,
	STORE_DIET,
	STORE_EXERCISE,
	DISPLAY_DIET,
	DISPLAY_EXERCISE,
	EDIT_DIET,
	EDIT_EXERCISE,
	EXIT
} MenuSelection;

class FitnessAppWrapper
{
public:
	void runApp();
	MenuSelection displayMenu();
private:
	vector<DietPlan> weeklyDietPlan;
	vector<ExercisePlan> weeklyExercisePlan;

	void loadDailyPlan(ifstream& fileStream, DietPlan& plan);
	void loadWeeklyPlan(ifstream& fileStream, vector<DietPlan>& weeklyPlan);
	void loadDailyPlan(ifstream& fileStream, ExercisePlan& plan);
	void loadWeeklyPlan(ifstream& fileStream, vector<ExercisePlan>& weeklyPlan);
	void displayDailyPlan(DietPlan& plan);
	void displayWeeklyPlan(vector<DietPlan>& weeklyPlan);
	void displayDailyPlan(ExercisePlan& plan);
	void displayWeeklyPlan(vector<ExercisePlan>& weeklyPlan);
	void storeDailyPlan(ofstream& fileStream, DietPlan& plan);
	void storeWeeklyPlan(ofstream& fileStream, vector<DietPlan>& weeklyPlan);
	void storeDailyPlan(ofstream& fileStream, ExercisePlan& plan);
	void storeWeeklyPlan(ofstream& fileStream, vector<ExercisePlan>& weeklyPlan);
	void editDailyPlan(vector<DietPlan>& weeklyPlan, int targetDay);
	void editDailyPlan(vector<ExercisePlan>& weeklyPlan, int targetDay);
	void choosePlan(vector<DietPlan>& weeklyPlan);
	void choosePlan(vector<ExercisePlan>& weeklyPlan);
};
