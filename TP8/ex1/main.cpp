#include <iostream>
#include <vector>

using namespace std;

int main() {
    // on demande à l'utilisateur de saisir une matrice carrée M de taille variable et la stocker dans un tableau (vector) 2D
    int M;
    cout << "Entrez la taille de la matrice carrée: ";
    cin >> M;
    vector<vector<int>> matrice(M, vector<int>(M)); // création de la matrice de taille MxM

    // on demande à l'utilisateur de saisir les valeurs de la matrice
    for (int i = 0; i < M; i++) { // on parcourt les lignes
        for (int j = 0; j < M; j++) { // on parcourt les colonnes
            cout << "Entrez la valeur de la case [" << i << "][" << j << "]: "; // on demande à l'utilisateur de saisir la valeur de la case
            cin >> matrice[i][j]; // on stocke la valeur dans la case
        }
    }

    // I Afficher la matrice transposée MT dans la console.
    cout << "La matrice transposée est: " << endl; // on affiche le message
    for (int i = 0; i < M; i++) { // on parcourt les colonnes
        for (int j = 0; j < M; j++) { // on parcourt les lignes
            cout << matrice[j][i] << " "; // on affiche la valeur de la case
        }
        cout << endl;
    }

    return 0; // on quitte le programme
}