#include <iostream>
#include <vector>
#include<string>
#include <fstream>
#include <ctime>

using namespace std;

string username, password;
unsigned age, height, weight, recCal, calories, food, workout;
char gender, plan, activity, goal;
double bmr, velocity; 

void invalidData()
{
    cout << "Invalid input! Try again!" << endl;
}

void fileProblem()
{
    cout << "This file can't be opened!" << endl;
}

#include "Register.h"

void logOut()
{
	cout << "Do you want to exit the app: (y/n)" << endl;
	char answer = ' ';
	cin >> answer;
	if (answer == 'y')
	{
		cout << "Goodbye :)" << endl;
		cout << endl;
		startForm();
	}
	else if (answer == 'n')
	{
		cout << "Alright, let's continue!" << endl;
	}
	else
	{
		invalidData();
	}
}

#include "Food.h"
#include "CaloriesFun.h"

int main()
{
    //Introduction
    cout << "Welcome to MyFitnessPal!" << endl;
    cout << "With this app, you can track your daily calorie intake and expenditure" <<
        '\n' << "by creating a physical profile and setting your goals." << endl;
    cout << "Let's get started!" << endl;
    cout << endl;
    
	//Create the file 
	ofstream outfile("accounts.txt", ios::app);
	outfile.close();

    //LogInOrSignIn
    startForm();

    //Program
    displayAccountData();

	//LogOutOpp
	logOut();
	cout << endl;

	//RecommendedCalories
	recommendedCaloriesIntake();

	//DailyBalance
	dailyBalance();
}
