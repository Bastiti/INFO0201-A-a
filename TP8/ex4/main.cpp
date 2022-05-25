#include <iostream>
#include <cmath>

using namespace std;

double alpha_n(double x,int n)
{
    return pow(-1, n-1)*pow(x, n)/n;
}

int main()
{
    // Demander une précision epsilon à l'utilisateur.
    double epsilon;
    cout << "Entrez une précision epsilon : ";
    cin >> epsilon;
    // Epsilon inférieure à 1 et supérieure à 0.
    while (epsilon > 1 || epsilon < 0)
    {
        cout << "Entrez une précision epsilon : ";
        cin >> epsilon;

    }

    // Demander à l'utilisateur de saisir un nombre x.
    double x;
    cout << "Entrez un nombre x : ";
    cin >> x;
    // x strictement supérieur à -1 et inférieur à 1.
    while (x <= -1 || x > 1)
    {
        cout << "Entrez un nombre x : ";
        cin >> x;
    }

    // Faire une somme qui calcule alpha_n jusqu'à que le résultat soit inférieur à epsilon.
    int n = 1;
    double somme = 0;
    while(alpha_n(x, n) > epsilon)
    {
        somme += alpha_n(x, n);
        n++;
    }
    cout << "La somme est : " << somme << endl;
    // Afficher le résultat et comparer avec la valeur calculée directement par log(1+x) de <cmath>
    cout << "La valeur calculée directement par log(1+x) est : " << log(1+x) << endl;

    return 0;
}