#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    // Ecrire un programme qui réalise un grand nombre de tirages aléatoires de deux dés (valeurs de 1 à 6).
    //Calculer la probabilité d'obtenir chacune des valeurs possibles pour la somme des deux dés.

    int nb_tirages = 1000000;
    int nb_de[12] = {0};

    for (int i = 0; i < nb_tirages; i++)
    {
        int de1 = rand() % 6 + 1;
        int de2 = rand() % 6 + 1;
        int somme = de1 + de2;
        nb_de[somme]++;
        
    }

    // Quel est le résultat le plus probable ?

    int max = 0;
    int max_index = 0;

    for (int i = 0; i < 12; i++)
    {
        if (nb_de[i] > max)
        {
            max = nb_de[i];
            max_index = i;
        }
    }

    cout << "Le résultat le plus probable est " << max_index << "." << endl;

}