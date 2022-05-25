#include <iostream>
#include <cmath>

using namespace std;

double terme_Leibniz(int n)
{
    double i=pow(-1,n)/(2*n+1);
    return i;
}

int main()
{
    cout.precision(15);

    double epsilon;
    cin>>epsilon;

    double pi=0;
    int n=0;
    do
    {
        pi+=4*terme_Leibniz(n);
        n++;
    }
    while (abs(terme_Leibniz(n)-terme_Leibniz(n-1))>epsilon);

    cout<<pi<<endl;
}
