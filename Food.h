#pragma once

string foodName, workoutName;

void addFood()
{
	ofstream foodFile("foods.txt", ios::app);

    if (!foodFile.is_open())
    {
        fileProblem();
    }

    cout << "Enter the name of the food: " << endl;
    cin >> foodName;
    cout << "Enter calories per 100g: " << endl;
    cin >> food;
    if (food < 0)
    {
        invalidData();
        addFood();
    }
    foodFile << foodName << " " << food << endl;
    foodFile.close();

    cout << endl;
    cout << "The food has been successfully added!" << endl;  
    cout << endl;
}

void addWorkout()
{
    ofstream workoutFile("workouts.txt", ios::app);

    if (!workoutFile.is_open())
    {
        fileProblem();
    }

    cout << "Enter the name of the workout: " << endl;
    cin >> workoutName;
    cout << "Enter calories burned: " << endl;
    cin >> workout;
    if (workout < 0)
    {
        invalidData();
    }

    workoutFile << workoutName << " " << workout << endl;
    workoutFile.close();

    cout << endl;
    cout << "The workout  has been successfully added!" << endl;
    cout << endl;
}

void displayFoods()
{
    ifstream infile("foods.txt");

    if (!infile.is_open())
    {
        fileProblem(); 
    }

    cout << "List of foods and their calories per 100g:" << endl;

    while (infile >> foodName >> food) 
    {
        cout << "- " << foodName << ": " << food << " cal per 100g" << endl;
    }

    infile.close();
    cout << endl;
}

void displayWorkouts()
{
    ifstream infile("workouts.txt");

    if (!infile.is_open())
    {
        fileProblem(); 
    }

    cout << "List of workouts and calories burned per session:" << endl;

    while (infile >> workoutName >> workout) 
    {
        cout << "- " << workoutName << ": " << workout << " cal burned" << endl;
    }

    infile.close();
    cout << endl;
}
