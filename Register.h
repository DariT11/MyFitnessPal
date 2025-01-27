#pragma once

bool accountExists()
{
    ifstream infile("accounts.txt");
    string u, p;

    if (!infile.is_open())
    {
        fileProblem();
    }
    else
    {
        while (infile >> u >> p)
        {
            if (u == username)
            {
                return true;
            }
        }
        infile.close();
    }
    return false;
}

void enterAge()
{
    cout << "Enter your age: (Between 18 and 99)" << endl;
    age = 0;
    cin >> age;
    if (age < 18 || age > 99)
    {
        cout << "Enter valid age!" << endl;
        cout << endl;
        enterAge();
    }
}

void enterGender()
{
    cout << "Enter your gender: (m-male/f-female)" << endl;
    gender = ' ';
    cin >> gender;
    if (gender != 'm' && gender != 'f')
    {
        cout << "Enter valid gender!" << endl;
        cout << endl;
        enterGender();
    }
}

void enterHeight()
{
    cout << "Enter your height: (Between 63 and 252 cm)" << endl;
    height = 0;
    cin >> height;
    if (height < 63 || height > 252)
    {
        cout << "Enter valid height!" << endl;
        cout << endl;
        enterHeight();
    }
}

void enterWeight()
{
    cout << "Enter your weight: (Between 5 and 636 kg)" << endl;
    weight = 0;
    cin >> weight;
    if (weight < 5 || weight > 636)
    {
        cout << "Enter valid weight!" << endl;
        cout << endl;
        enterWeight();
    }
}

void enterActivity()
{
    cout << "Enter your daily activity: " << endl;
    cout << "l - lightly active - workouts 1-3 days weekly" << endl;
    cout << "m - moderately active - workouts 3-5 days weekly" << endl;
    cout << "a - active - workouts 6-7 days weekly" << endl;
    cout << "v - very active - physical work and intense training" << endl;
    activity = ' ';
    cin >> activity;
    if (activity != 'a' && activity != 'l' && activity != 'm' && activity != 'v')
    {
        cout << "Enter valid activity!" << endl;
        cout << endl;
        enterActivity();
    }
}

void enterGoals()
{
    cout << "Enter your goal: " << endl;
    cout << "l - weight loss" << endl;
    cout << "m - maintain weight" << endl;
    cout << "g - gain weight" << endl;
    goal = ' ';
    velocity = 0;
    cin >> goal;
    if (goal != 'l' && goal != 'm' && goal != 'g')
    {
        cout << "Enter valid weight!" << endl;
        cout << endl;
        enterGoals();
    }
    if (goal == 'l')
    {
        cout << "Enter how much weight do you want to loss weekly: " << endl;
        cout << "(0.25/0.5/0.75/1 kg per week)" << endl;
        cin >> velocity;
    }
    else if (goal == 'g')
    {
        cout << "Enter how much weight do you want to gain weekly: " << endl;
        cout << "(0.25/0.5/0.75/1 kg per week)" << endl;
        cin >> velocity;
    }
    else
    {
        velocity = 0;
    }
}

void choosePlan()
{
    cout << "Choose plan: (s - Standart/p - Premium): " << endl;
    plan = ' ';
    cin >> plan;

    if (plan != 's' && plan != 'p')
    {
        cout << "Enter valid plan!" << endl;
        cout << endl;
        choosePlan();
    }
}

void signIn()
{
    cout << "Enter username: (At least 4 characters and no more than 20 characters)" << endl;
    cin >> username;
    if (username.length() < 3 || username.length() > 20)
    {
        invalidData();
        signIn();
    }
    if (accountExists())
    {
        cout << "This username already exist! Try again!" << endl;
        signIn();
    }

    cout << "Enter password: (Between 8 and 15 characters)" << endl;
    cin >> password;
    if (password.length() < 8 || password.length() > 15)
    {
        invalidData();
        signIn();
    }

    cout << endl;
    cout << "Now let's make your physical profile! " << endl;
    cout << endl;
    enterAge();
    enterGender();
    enterHeight();
    enterWeight();
    enterActivity();

    cout << endl;
    cout << "Set your goal and you are ready to have your dream body!" << endl;
    enterGoals();

    cout << endl;
    choosePlan();
    cout << endl;

    ofstream outfile("accounts.txt", ios:: app);
    if (!outfile.is_open())
    {
        fileProblem();
    }
    outfile << username << " " << password << " " << age << " " << gender << " " << height << " "
        << weight << " " << activity << " " << goal << " " << plan << " " << velocity << endl;

    cout << "Your account is registered!" << endl;
    cout << endl;
    outfile.close();
}

bool corectLogIn()
{
    ifstream infile("accounts.txt");
    string u, p;

    if (!infile.is_open())
    {
        fileProblem();
    }

    while (infile >> u >> p)
    {
        if (username == u && password == p)
        {
            infile.close();
            return true;
        }
    }
    infile.close();
    return false;
}

void logIn()
{
    cout << "Username: " << endl;
    cin >> username;
    cout << "Password: " << endl;
    cin >> password;
    cout << endl;
    if (corectLogIn())
    {
        cout << "Welcome back!" << endl;
        cout << endl;
    }
    else
    {
        cout << "Wrong username or password! Please try again!" << endl;
        cout << endl;
        logIn();
    }
}

void startForm()
{
    cout << "Log in(l), Sign in(s) or Exit(e): " << endl;
    char answer = ' ';
    cin >> answer;
    if (answer == 'l')
    {
        logIn();
    }
    else if (answer == 's')
    {
        signIn();
    }
    else if (answer == 'e')
    {
        cout << "Goodbye :)" << endl;
        return;
    }
    else
    {
        invalidData();
        cout << endl;
        startForm();
    }
}

void displayAccountData()
{
    ifstream infile("accounts.txt");
    string u, p;
    unsigned a, h, w;
    char g, act, go, pl;
    double v;

    if (!infile.is_open())
    {
        fileProblem();
    }

    cout << "Your data: " << endl;
    while (infile >> u >> p >> a >> g >> h >> w >> act >> go >> pl >> v)
    {
        if (username == u)
        {
            cout << "Username: " << u << endl;
            cout << "Age: " << a << endl;
            cout << "Gender: " << g << endl;
            cout << "Height: " << h << endl;
            cout << "Weight: " << w << endl;
            cout << "Activity: " << act << endl;
            cout << "Goal: " << go << endl;
            cout << "Plan: " << pl << endl;
            if (go == 'm')
            {
                cout << "Nothing to lose!" << endl;
            }
            else
            {
                cout << "Goal per week: " << v << endl;
            }
        }
    }
    cout << endl;
    infile.close();
}