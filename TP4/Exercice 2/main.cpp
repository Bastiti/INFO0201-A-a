#include <iostream>
#include <cstdlib>
using namespace std;


int cote[10];
int maxi = 0;
int mini = 20;
int checkupper;
double moyenne;
int i;
int percent;
int main()
{
    srand(time(NULL));
    cout << "Check grade which is upper: ";
    cin >> checkupper;
    for (i = 0; i < 10; i++)
    {
        cote[i] = rand()%21;
        cout<<i+1<<"\t"<<cote[i]<<endl;
        if (maxi<cote[i])
            maxi=cote[i];
        if (mini>cote[i])
            mini=cote[i];
        moyenne += cote[i];
    }
    cout<<"\nmax\t"<<maxi<< "\nmin\t" << mini << "\nmoyenne\t" << moyenne/i <<endl;
    for (i=0; i<10;i++)
    {
        if (checkupper<cote[i]){
            cout << "\n" << cote[i];
        percent++;
        }
    }
    cout << "\nPercentage: " << (double)percent/i <<"%\n";
    return 0;
}
