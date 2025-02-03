#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

string username, password, today;
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

#include "Register.hpp"

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
	cout << endl;
}

#include "Calendar.hpp"
#include "Food.hpp"
#include "Workouts.hpp"
#include "CaloriesFun.hpp"

int main()
{
    //Introduction
    cout << "Welcome to MyFitnessPal!" << endl;
    cout << "With this app, you can track your daily calorie intake and expenditure" <<
        '\n' << "by creating a physical profile and setting your goals." << endl;
    cout << "Let's get started!" << endl;
    cout << endl;
    
	//Create file to store users' usernames and passwords
	ofstream outfile("accounts.txt", ios::app);
	outfile.close();

    //LogInOrSignUp
    startForm();

    //Display users'data
    displayAccountData();

	//Log out option
	logOut();

	//This function gives the user the chance to change
	//their physical data, activity, and goals 
	changes();

	//Set current date
	today = getCurrentDate();

	//Display recommended calories
	recommendedCaloriesIntake();

	//Display daily balance and add food or workout
	dailyBalance();
}
