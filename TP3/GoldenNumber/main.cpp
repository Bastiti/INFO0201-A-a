#include <iostream>
#include <unistd.h>
#include <cmath>

using namespace std;

double a = 1;
double b = 1;
double d = 1;
double c,e;
int main()
{
    cout << "Input precision of Gold Number:" << endl;
    cin >> e;
    while (d > e)
    {
        c = a + b; //While a = 0 and b = 1, c will be 1. First terms of
        d = abs(c/b-b/a);
        if (d > e)
            cout << d << endl;
        a = b;
        b = c;
        sleep(1);
    }

}
