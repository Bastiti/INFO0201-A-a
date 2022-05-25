#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
int choice[4];
int number;
int tries=10;

int generateNumber(int values[]) // That's a function, it gives you the possibility to beautify your code.
{
    for (int i = 0; i<4; i++)
    {
        number = rand()%9+1; // Generate a random number

        values[i] = number; // Insert it into the array
    }
    return values[4];
}

int getNumber(int choice[4])
{
    cout << "Please input your choice:" << endl << endl;
    string s;
    cin >> s;
    cout << endl;
    for (int i = 0; i<4; i++)
    {
        choice[i] = s[i]-'0'; //Substract "input i number" and 0. Ascii number. + Transfer it into an int. Gives us an int number.
    }
    return choice[4];
}

void result(int generated[4], int userChoice[4], int &  wellplaced, int & wrongplaced)
{
    bool genValidated[4];
    bool userValidated[4];
    //Check for well placed number
    for (int i =0; i<4; i++)
    {
        if  ( generated[i] == userChoice[i])
        {
            genValidated[i] = true; // Goal is to filter numbers
            userValidated[i] = true;
            wellplaced++;
        }
        else
        {
            genValidated[i]= false;
            userValidated[i] = false;
        }
    }
    //Check for wrong placed number
    for (int i =0; i<4; i++)
    {
        for (int j = 0; j<4; j++)
        {
            if (i != j && generated[i] == userChoice[j] && userValidated[j] == false && genValidated[i] == false) // Check if numbers aren't well placed and exist in the result.
            {
                userValidated[j] = true; // Avoid to get a number counted twice or more.
                genValidated[i] = true;
                wrongplaced++;
            }
        }

    }

}

int main()
{
    int values[4];
    srand(time(NULL));
    generateNumber(values);
    cout << "Welcome to the MasterMind: " << endl;
    while (tries > 0 )
    {
        tries -=1;
        int wrongplaced = 0;
        int wellplaced = 0;
        getNumber(choice);
        result(values,choice,wellplaced,wrongplaced);
        if (wellplaced == 4)
        {
            cout << "Congrats, you won the game !";
            return 0;
        }
        cout << "You have placed " << wellplaced << " numbers correctly and only " << wrongplaced << " are wrong placed." << endl;
        cout << "You have " << tries << " tries left." << endl << endl;
    }
    cout << "Sorry, but you lost. Number was: ";
    for (int i =0; i<4; i++)
    {
        cout << values[i]; // Show the value
    }
    cout << "\n";
    return 0;
}
