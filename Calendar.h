#pragma once
#include<string>
#include <ctime>

string getCurrentDate()
{
    time_t t = time(0);
    struct tm now;
    localtime_s(&now, &t);  

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &now);  
    return string(buffer);
}

void getDataInFile(string date)
{
    ofstream file(username + date + ".txt");
    if (!file.is_open())
    {
        fileProblem();
    }

    file << "Recommended calories: " << recCal << "cals per day" << endl;

    string line;
    ifstream caloriesFile(username + ".txt");
    if (!caloriesFile.is_open())
    {
        fileProblem();
    }
    getline(caloriesFile, line);
    file << "Daily balance: " << line << " cals" << endl;
    caloriesFile.close();

    ifstream foodFile("food.txt");
    if (!foodFile.is_open())
    {
        fileProblem();
    }
    file << "Food information: ";
    while (getline(foodFile, line))
    {
        file << line << endl;
    }
    foodFile.close();

    ifstream workoutFile("workout.txt");
    if (!workoutFile.is_open())
    {
        fileProblem();
    }
    file << "Workouts information: ";
    while (getline(workoutFile, line))
    {
        file << line << endl;
    }
    workoutFile.close();

    file.close();
}

void readFile(string date)
{
    ifstream file(username + date + ".txt");
    if (!file.is_open())
    {
        cout << "There is no data for this date!" << endl;
        cout << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}

void deleteFile(string date)
{
    cout << "Do you want to delete your daily balance for this date? (y/n)" << endl;
    char answer = ' ';
    if (answer == 'y' || answer == 'Y')
    {
        remove((username + date + ".txt").c_str());
        cout << "Your daily balance for this date is successfully deleted!" << endl;
        cout << endl;
        logOut();
    }
    else if (answer == 'n' || answer == 'N')
    {
        cout << endl;
        cout << "Alrigth! Let's continue!" << endl;
        cout << endl;
        return;
    }
    else
    {
        cout << endl;
        invalidData();
        cout << endl;
        deleteFile(date);
    }
}

void searchByDate()
{
    cout << "Do you want to see your daily balance from another day? (y/n)" << endl;
    char answer = ' ';
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        cout << endl;
        cout << "Enter date: (YYYY-MM-DD)" << endl;
        string date = " ";
        cin >> date;
        readFile(date);
        cout << endl;
        deleteFile(date);
    }
    else if (answer == 'n' || answer == 'N')
    {
        cout << endl;
        cout << "Alrigth! Let's continue!" << endl;
        cout << endl;
        return;
    }
    else
    {
        invalidData();
        searchByDate();
    }
}

bool isItNewDay()
{
	return false;
}

void saveDataForEachDay()
{
    today = getCurrentDate();
    if (isItNewDay())
    {
        getDataInFile(today);
    }
    else
    {

    }
}