
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

float v,h,a,g = 9.81;
double d;
int value;
int result;
void divide(int value, int number){
    if (value % number == 0){
        cout <<  value << " can be divided by: " << number << endl;
    } else {
        cout <<  value << " cannot be divided by: " << number << endl;
    }
}

int main()
{
    cout << "Input shoot angle (deg): " << endl; cin >> a;
    cout << "Input hoop height (m): " << endl; cin >> h;
    cout << "Input inital speed (m/s): " << endl; cin >> v;
    if (pow(v * sin(a * M_PI/180),2) > 2*g*h && a >= 0 && a <=90) // Check if the sqrt is postitive
    {
        d = ((v*cos(a * M_PI/180))/g) * (v*sin(a * M_PI/180) + sqrt(pow(v * sin(a * M_PI/180),2) - 2*g*h)); // Apply formula
        cout << "Shoot distance: " << d << " meters" << endl;
    }
    else
    {
        cout << "U SUCKS, Distance needs to be strictly positive and real." << endl;
    }
    cout << "Choose an interger value: " << endl; cin >> value;
    divide(value,2);
    divide(value,3);
    divide(value,5);
    return 0;
}
