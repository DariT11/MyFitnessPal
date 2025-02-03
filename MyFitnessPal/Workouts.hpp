#pragma once

string workoutName;

void addWorkout()
{
    ofstream workoutFile(username + "workouts.txt", ios::app);

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
        addWorkout();
    }

    workoutFile << workoutName << " " << workout << endl;
    workoutFile.close();

    calories += workout;

    cout << endl;
    cout << "The workout has been successfully added!" << endl;
    cout << endl;
}

void displayWorkouts()
{
    ifstream infile(username + "workouts.txt");

    if (!infile.is_open())
    {
        return;
    }

    cout << "List of workouts and calories burned per sessions:" << endl;

    while (infile >> workoutName >> workout)
    {
        cout << " - " << workoutName << ": " << workout << " cals burned" << endl;
    }

    infile.close();
    cout << endl;
}