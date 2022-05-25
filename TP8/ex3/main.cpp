#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    // demande à l'utilisateur de saisir deux vecteurs de tailles variables
    // I calcule le produit tensoriel de ces deux vecteurs dans un tableau dynamique (2 dimensions) ;
    // affiche le résultat à la fois à l'écran et dans un fichier nommé "produit_tensoriel.txt" ;

    int nb_lignes;
    cin >> nb_lignes;

    vector<double> vecteur1(nb_lignes);
    
    for (int i = 0; i < nb_lignes; i++)
    {
        cin >> vecteur1[i];
    }

    int nb_colonnes;
    cin >> nb_colonnes;

    vector<double> vecteur2(nb_colonnes);

    for (int i = 0; i < nb_colonnes; i++)
    {
        cin >> vecteur2[i];
    }

    int nb_lignes_colonnes = nb_lignes * nb_colonnes;

    vector<double> produit_tensoriel(nb_lignes_colonnes);

    ofstream fichier("produit_tensoriel.txt");

    for (int i = 0; i < nb_lignes; i++)
    {
        for (int j = 0; j < nb_colonnes; j++)
        {
            produit_tensoriel[i * nb_colonnes + j] = vecteur1[i] * vecteur2[j];
            fichier << produit_tensoriel[i * nb_colonnes + j] << " ";
            cout << produit_tensoriel[i * nb_colonnes + j] << "\t";
        }
        cout << endl;
    }

    return 0;

}