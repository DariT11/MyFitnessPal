#pragma once

string foodName;

/*void createFoodFile()
{
    ofstream foodFile("foods.txt");

    if (!foodFile.is_open())
    {
        fileProblem();
    }
}*/

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

    calories -= food;

    cout << endl;
    cout << "The food has been successfully added!" << endl;  
    cout << endl;
}

void foodDataInVector()
{
    foods.push_back(food);
}

void displayFoods()
{
    ifstream infile("foods.txt");

    if (!infile.is_open())
    {
        return;
    }

    cout << "List of foods and their calories per 100g:" << endl;

    while (infile >> foodName >> food) 
    {
        cout << "- " << foodName << ": " << food << " cal per 100g" << endl;
    }

    infile.close();
    cout << endl;
}
