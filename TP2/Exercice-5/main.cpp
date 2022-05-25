#include <iostream>
using namespace std;

int seconds;

int time()
{
    cout << "Input time (in secs): " << endl;
    cin >> seconds;
    if (seconds <= 0)
    {
        cout << "Time must be strictly postive." << endl;
        return time();
    }
    cout << "There is: ";
    if (seconds / 3600 > 0) //Check if there's hours
    {
        cout << seconds / 3600 << " hour(s), ";
    }
    seconds += -(seconds / 3600) * 3600;
    if (seconds / 60 > 0) //Check if there's minutes
    {
        cout << seconds / 60 << " minute(s) and ";
    }
    seconds += -(seconds / 60) * 60;
    if (seconds > 0) //Check if there's and seconds
    {
        cout << seconds << " second(s)." << endl;
    }
}

int main()
{
    time();
    return 0;
}
