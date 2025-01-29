#pragma once

double bmrCal(char g, unsigned w, unsigned h, unsigned a)
{
    if (g == 'm')
    {
        return 88.362 + (13.397 * w) + (4.799 * h) - (5.677 * a);
    }
    else if (g == 'f')
    {
        return 447.593 + (9.247 * w) + (3.098 * h) - (4.330 * a);
    }
}

double activityCoeff(char act)
{
    switch (act)
    {
    case 'l': return 1.375;
        break;
    case 'm': return 1.55;
        break;
    case 'a': return 1.725;
        break;
    case 'v': return 1.9;
        break;
    default: return 1.2;
        break;
    }
}

unsigned proteinCal(char go, unsigned cal)
{
    if (go == 'l')
    {
        return 0.35 * cal;
    }
    else if (go == 'm')
    {
        return 0.25 * cal;
    }
    else
    {
        return 0.4 * cal;
    }
}

unsigned proteinGrams(char go, unsigned cals)
{
    return proteinCal(go, cals) / 4;
}

unsigned fatCal(char go, unsigned cal)
{
    if (go == 'l')
    {
        return 0.3 * cal;
    }
    else if (go == 'm')
    {
        return 0.3 * cal;
    }
    else
    {
        return 0.25 * cal;
    }
}

unsigned fatGrams(char go, unsigned cals)
{
    return fatCal(go, cals) / 9;
}

unsigned carbsCal(char go, unsigned cal)
{
    if (go == 'l')
    {
        return 0.35 * cal;
    }
    else if (go == 'm')
    {
        return 0.45 * cal;
    }
    else
    {
        return 0.35 * cal;
    }
}

unsigned carbsGrams(char go, unsigned cals)
{
    return carbsCal(go, cals) / 4;
}

void displayMacros(unsigned pC, unsigned fC, unsigned cC, unsigned pG, unsigned fG, unsigned cG)
{
    cout << "Protein: " << pC << " cal and " << pG << " g" << endl;
    cout << "Fat: " << fC << " cal and " << fG << " g" << endl;
    cout << "Carbs: " << cC << " cal and " << cG << " g" << endl;
}

unsigned defOrEx(double v)
{
    if (v == 0.25)
    {
        return 275;
    }
    else if (v == 0.5)
    {
        return 550;
    }
    else if (v == 0.75)
    {
        return 825;
    }
    else
    {
        return 1100;
    }
}

void caloriesDataInVectors()
{
    recCals.push_back(recCal);
    dailyCalories.push_back(calories);
    bmrValues.push_back(bmr);
}

void saveCalInFile(unsigned cal)
{
    ofstream personalFile(username + "calories.txt");
    if (!personalFile.is_open())
    {
        fileProblem();
    }
    personalFile << cal;
    personalFile.close();
}

void recommendedCaloriesIntake()
{
    ifstream infile(username + ".txt");
    if (!infile.is_open())
    {
        fileProblem();
    }

    string u, p;
    unsigned a, h, w;
    char g, act, go, pl;
    double v;

    bmr = 0;

    unsigned deficit = 0;
    unsigned excess = 0;
    double activityCoef = 0;

    unsigned protein = 0;
    unsigned fat = 0;
    unsigned carbs = 0;
    unsigned proteinG = 0;
    unsigned fatG = 0;
    unsigned carbsG = 0;
   
    cout << "Recommended caloric intake: " << endl;
    while (infile >> u >> p >> a >> g >> h >> w >> act >> go >> pl >> v)
    {
        if (username == u)
        {
            bmr = bmrCal(g, w, h, a);
            activityCoef = activityCoeff(act);

            if (go == 'l' || go == 'g')
            {
                if (go == 'l')
                {
                    deficit = defOrEx(v);
                    recCal = bmr * activityCoef - deficit;
                }
                else
                {
                    excess = defOrEx(v);
                    recCal = bmr * activityCoef + excess;
                }
            }
            else
            {
                recCal = bmr * activityCoef;
            }

            cout << "Calories: " << (int)recCal << " cal per day" << endl;
            cout << endl;

            if (pl == 'p')
            {
                protein = proteinCal(go, recCal);
                fat = fatCal(go, recCal);
                carbs = carbsCal(go, recCal);
                proteinG = proteinGrams(go, recCal);
                fatG = fatGrams(go, recCal);
                carbsG = carbsGrams(go, recCal);
                displayMacros(protein, fat, carbs, proteinG, fatG, carbsG);
            }
        }
    }
    infile.close();

    calories = recCal;
    caloriesDataInVectors();
    saveCalInFile(recCal);
    
    cout << endl;
    cout << "*1 kg body weight = 7700 cal!" << endl;
    cout << endl;

    if (recCal < 1200)
    {
        cout << "Warning:"
            << "This recommended calorie intake is tailored to your goals"
            << " but it may not be safe for your health." << endl;
        cout << endl;
        changes();
        recommendedCaloriesIntake();
    }
}

unsigned readCalFromFile()
{
    ifstream personalFile(username + "calories.txt");
    if (!personalFile.is_open())
    {
        fileProblem();
    }
    unsigned cal = 0;
    personalFile >> cal;
    personalFile.close();

    return cal;
}

void changeCal()
{
    unsigned currCal = readCalFromFile();
    unsigned newCal = calories;
    saveCalInFile(newCal);
}

void dailyBalance()
{
    cout << "Recommended calories: " << recCal << endl;
    cout << "Daily Balance: " << calories << " " << endl;
    cout << endl;
    cout << "Do you want to add food or workout: (f/w)" << endl;
    char answer = ' ';
    cin >> answer;

    if (answer == 'f')
    {
        addFood();
        changeCal();
        displayFoods();
        displayWorkouts();
        logOut();
        dailyBalance();
    }
    else if(answer == 'w')
    {
        addWorkout();
        changeCal();
        displayFoods();
        displayWorkouts();
        logOut();
        dailyBalance();
    }
    else
    {
        invalidData();
        dailyBalance();
        cout << endl;
    } 
    cout << endl;
}