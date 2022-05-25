#include <iostream>
#include <cmath>
using namespace std;
double a,b,c,d;
float e = pow(10,30);
float f=-e;
float g = 1;
int h=1;
float j = 0;
int main()
{
    a = 10.0/3.0 ;
    b = a-3.0;
    c = b*3.0;
    d= c-1.0;
    cout << d << endl; // Something e-16, near 0 as expected because computer use imprecise value.
    a = ((10.0/3.0-3)*3.0)-1;
    cout << a << endl;
    for (int i = 1; i <= 100; i++){
        cout << i << endl;
    }
    for (float i = 0; i <= 1; i+=0.1){
        cout << i << endl;
    }
    while (h < 100){
        h += 1;
        cout << h << endl;
    }
    while (j < 1){
        j += 0.1;
        cout << j << endl; // There's do while loop missing. Pretty annoying for nothing.
    }
    cout << e+(f+g) << endl; // Result is 0 because f+g simplified by f
    cout << (e+f)+g << endl; // Result is 1 OK
}
