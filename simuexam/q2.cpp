// Déterminer les nombres palindromes carrés entre 1 et 1000.

#include <iostream>
#include <cmath>

using namespace std;

//Voir si le nombre est un carré parfait

bool carréparfait(long double x)
{
    long double racine = sqrt(x);
    return (racine - floor(racine) == 0);
}

int main()
{

    for (int i = 1; i <= 100000; i++)
    {
        int num = i;
        int n = num;
        int rev = 0;
        while (num > 0)
        {
            rev = rev * 10 + num % 10;
            num = num / 10;
        }
        if (n == rev)
        {
           if (carréparfait(n))
           {
               cout << n << endl;
           }
        }
    }
}