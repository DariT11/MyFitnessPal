/**
*
* Solution to course project # 9
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2024/2025
*
* @author Darina Todorova
* @idnumber 4MI0600501
* @compiler VC
*
* File with food functions

*/

#pragma once

string foodName;

void addFood()
{
    ofstream foodFile(username + "foods.txt", ios::app);

    if (!foodFile.is_open())
    {
        fileProblem();
    }

    cout << "Enter the name of the food: " << endl;
    cin >> foodName;
    cout << "Enter calories: " << endl;
    cin >> food;
    if (food < 0)
    {
        invalidData();
        addFood();
    }

    foodFile << foodName << " " << food << endl;
    foodFile.close();

    calories -= food;

    cout << endl;
    cout << "The food has been successfully added!" << endl;  
    cout << endl;
}

void displayFoods()
{
    ifstream infile(username + "foods.txt");

    if (!infile.is_open())
    {
        return;
    }

    cout << "List of foods and their calories:" << endl;

    while (infile >> foodName >> food) 
    {
        cout << " - " << foodName << ": " << food << " cals" << endl;
    }

    infile.close();
    cout << endl;
}