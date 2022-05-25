#include <iostream>
#include <fstream>
using namespace std;

ifstream numbers("./nombre.txt");
double tab[50];int track;
int main()
{
    if (numbers.is_open())
    {
        for (int i =0; i<50; i++)
        {
            numbers>>tab[i];
            cout<<i<<"\t"<<tab[i] << endl;
        }
    }
    int mini = tab[0];
    for (int j = 0; j < 50; j++)
    {
        if (mini>tab[j])
        {
            mini=tab[j];
            track=j;
        }
    }
    cout << "Minimum is: " << mini << "\nNumber in the tab is: " << track;
    return 0;
}
