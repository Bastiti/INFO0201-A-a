#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

float g = 9.81;

double h_rebond(double h_start, double epsilon)
{
    double v0 = sqrt(2*g*h_start); // La vitesse atteinte lors de l'impact au sol est v0 = sqrt(2gh0);
    double v1 = v0*epsilon; // On considère le rebondissent avec un coeff de restitution 'epsilon';
    double height = pow(v1,2)/(2*g); // La nouvelle hauteur atteinte est alors h = (v1)²/(2g).
    return height;
}
double h_final(double h_start, int n, double epsilon)
{
    double height = h_start;
    for(int i = 1; i <= n; i++)
    {
        height = h_rebond(height, 0.85);
    }
    return height;
}

double n_rebonds(double h_start, double h_end, double epsilon)
{
    double height = h_start;
    int i = 0;
    do
    {
        i++;
        height = h_rebond(height, 0.85);
    }
    while(height > h_end);
    return i;
}

int main()
{
    double height;
    cin >> height;
    ofstream rebonds("./rebonds.txt");
    cout << "Hauteur après un rebond: " << h_rebond(height, 0.85) << "m." << endl;
    cout << "Hauteur après 4 rebonds: " << h_final(height, 4, 0.85) << "m." << endl;
    cout << "Nombre de rebonds avant que la hauteur soit inférieur à 1cm: " << n_rebonds(height, 0.01, 0.85)" << endl;
    for(int i = 1; i <= 22; i++)
    {
        rebonds << h_final(height, i, 0.85) << "\n";
    }
    return 0;
}
