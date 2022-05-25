#include <iostream>
#include <fstream>

using namespace std;
ifstream numbers("./nombre.txt");
double tab[50];
int switchvar;
int main()
{
    if (numbers.is_open()) // Add value from matrix
    {
        for (int i =0; i<50; i++)
        {
            numbers>>tab[i];
        }
    }

    for(int j=0;j<50;j++)
    {
        int mini=20000000; // Une valeur max pour le tri.
        int indice; // Element du tableau à venir.
        for(int i=j; i<50; i++)
        {
            if (mini>tab[i])
            {
                mini=tab[i];
                indice=i;
            }
        }

        int c; // Sauvegarde variable
        c=tab[j]; // Sauvegarde cette valeur
        tab[j]=tab[indice]; // Remplace la valeur
        tab[indice]=c;

        cout<<j+1<<"\t"<<tab[j]<<endl;
    }
    return 0;
}

