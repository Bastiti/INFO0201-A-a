#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

double int_cos2(double a,double b,double epsilon) // Get the integral of cos(2x);
{
    double y=0;
    for(; a<b; a+=epsilon)
    {
        y+=epsilon*cos(2*a+epsilon);
    }
    return y;
}

double Px(vector<double>&coef,double x)// Get the integral of a polynom:
{
    double valeur=0;
    for(int i=0; i<coef.size(); i++)
    {
        valeur+=coef[i]*pow(x,i);
    }
    return valeur;
}

double int_Px(vector<double>&coef,double a,double b,double epsilon)// Get the integral of a polynom:
{
    double integrale=0;
    for(;a<b; a+=epsilon)
    {
        integrale+=epsilon*Px(coef,a+epsilon/2);
    }
    return integrale;
}


int main()
{
    double a=0,b=10,epsi=0.001;
    vector<double> coef(6);
    coef[0]=7;
    coef[1]=5;
    coef[2]=2;
    coef[3]=0;
    coef[4]=3;
    coef[5]=7;
    for(int i = 1; i <= 5; i++)
    {
        cout << "La valeur de PI en fonction de la série de riemann avec une précision de :" << 1/pow(10,i) << " vaut: " <<int_cos2(0, M_PI/4, 1/pow(10,i)) << "\n";
    }
    ofstream valeur("./polvalue.txt");
    valeur.precision(14);
    valeur<<"Integrate from 0 to t"<<endl;
    for(int h=1;h<=1000;h++)
    {
      valeur<<(double)h/100<<"\t"<<int_Px(coef,a,b,epsi)<<endl;
    }
}
