// Determiner et afficher la décomposition en facteurs premiers d'un nombre entier naturel

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cout << "Entrez un nombre entier naturel : "; // Demande d'un nombre entier naturel
    cin >> n; // n est un nombre entier naturel
    int i = 2; // i est le nombre de facteur premier
    while (n > 1) // Tant que n est un nombre entier naturel
    {
        if (n % i == 0) // Si n est divisible par i
        {
            cout << i << " x "; // On affiche i
            n = n / i; // On divise n par i
        }
        else
        {
            i++; // Sinon on incrémente i
        }
    }
    cout << endl;
    return 0;
}