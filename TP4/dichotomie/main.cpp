#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
double a = 0;
double b = 3;
double c,e;


int main()
{
    cout.precision(10);
    while(b-a > pow(10,-9))
    {
        c = (a+b)/2;
        if (cos(a)*cos(c)<0)
            b=c;
        else
            a=c;
    }
    cout << "Pi as the value: " << a+b;
    ofstream pifile("./pi.txt");
    pifile<<"pi="<<(a+b);
    return 0;
}
