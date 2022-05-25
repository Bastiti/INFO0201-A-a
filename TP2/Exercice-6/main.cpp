#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

double x, y, z, norme, teta, phi;

int radToDeg(double angle)
{
    return angle * 180 / M_PI;
}

int main()
{
    cout << "This program will calculate the polar angles of a vector defined in 3 dimensions. "
         << "\n\n";
    cout << "Input X component: " << endl;
    cin >> x;
    cout << "Input Y component: " << endl;
    cin >> y;
    cout << "Input Z component: " << endl;
    cin >> z;
    norme = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); // Get the norm of the direction vector by sqrt(a²+b²+c²)

    teta = M_PI * 0.5 - atan(z/norme); // Get phi angle
    phi = atan(y / x); // Get Teta angle
    cout << norme << endl;
    cout << radToDeg(teta) << endl;
    cout << radToDeg(phi) << endl;
    return 0;
}
