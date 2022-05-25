#include <iostream>
#include <vector>

using namespace std;

int main() {
    /*
     * Ecrire un programme qui décompose un nombre entier décimal en nombre
    binaire et place la valeur de chacun des bits dans un tableau. Le stockage
    sous forme little endian (bits de poid faible à gauche) sera utilisé.
     */
    // Entrer un nombre entier au clavier ;
    int nombre;
    cout << "Entrer un nombre entier : ";
    cin >> nombre;
    // Décomposer le nombre en binaire ;
    vector<int> binaire;
    while (nombre > 0) {
        binaire.push_back(nombre % 2);
        nombre /= 2;
    }
    // Afficher le nombre binaire ;
    cout << "Nombre binaire : ";
    for (int i = binaire.size() - 1; i >= 0; i--)
        cout << binaire[i];
    cout << endl;
    return 0;
}