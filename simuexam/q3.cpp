#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream fichier("./mots_caches.txt"); // ouverture du fichier
    string ligne; // variable pour stocker les lignes du fichier
    vector<string> mots; // vecteur pour stocker les lettres du fichier
    while (getline(fichier, ligne)) // tant qu'il y a des lignes dans le fichier
    {
        string mot = ""; // variable pour stocker les lettres de la ligne
        for (int i = 0; i < ligne.size(); i++) //POur chaque lettre de la ligne
        {
            if (ligne[i] != ' ') // si la lettre n'est pas un espace
            {
                mot += ligne[i]; // on ajoute la lettre au mot
            }
        }
        mots.push_back(mot); // on ajoute le string mot au vecteur
    }

    vector<string> transposee; // vector transposée par rapport au vector mot
    for (int i = 0; i < mots.size(); i++)
    {
        string colones; // variable pour stocker les lettres de la ligne
        for (int j = 0; j < mots[i].size(); j++)
        {
            colones += mots[i][j]; // On inverse les lignes et les colonnes du vecteur transposée par rapport au vecteur mots
        }
        transposee.push_back(colones); // On ajoute la ligne à la transposée
    }




    string mot; // variable pour stocker le mot à trouver
    cout << "Entrez un mot : "; // demande de mot à trouver
    cin >> mot; // on stocke le mot dans la variable mot
    ofstream ecrire("./recherche.txt"); // ouverture du fichier de sortie
    while (mot != "stop") // Tant que le mot stop n'est pas introduit, le programme demanderas toujours un nouveau mot
    {
        bool trouve = false; // variable pour savoir si le mot est trouvé

        for (int i = 0; i < mots.size(); i++) // Pour chaque mot du vecteur mots

        {
            trouve = mots[i].find(mot) != string::npos; // On cherche le mot dans le mot du vecteur mots
            if (trouve) // Si le mot est trouvé
            {
                cout << "Le mot " << mot << " est dans le fichier, trouvé horizontalement à la position: "; // on affiche le mot et sa position
                cout << "(" << i+1 << "," <<(mots[i].find(mot)+1) << ")" << endl;
                ecrire << "Le mot " << mot << " est dans le fichier, trouvé horizontalement à la position: "; // on écrit le mot et sa position dans le fichier de sortie
                ecrire << "(" << i+1 << "," <<(mots[i].find(mot)+1) << ")" << endl;
                break; // on sort de la boucle for
            }
        }
        for (int i = 0; i < transposee.size(); i++) // Si le mot n'a pas été trouvé horizontallement, chercchons le verticalement.
        {
            if (!trouve) // On s'assure que le mot n'as pas été trouvé afin d'éviter un bug idiot.
            {
                trouve = transposee[i].find(mot) != string::npos; // On cherche le mot dans le mot du vecteur transposée
                if (trouve) {
                    cout << "Le mot " << mot << " est dans le fichier, trouvé vecticalement à la position: "; // on affiche le mot et sa position
                    cout << "(" << (transposee[i].find(mot) + 1) << "," << i + 1 << ")" << endl;
                    ecrire << "Le mot " << mot << " est dans le fichier, trouvé vecticalement à la position: "; // on écrit le mot et sa position dans le fichier de sortie
                    ecrire << "(" << (transposee[i].find(mot) + 1) << "," << i + 1 << ")" << endl;
                    break; // on sort de la boucle for
                }
            }
        }

        if (!trouve) // Si le mot n'as pas été trouvé verticalement ou horizontalement
        {
            cout << "Le mot " << mot << " est inexistant." << endl; // on affiche que le mot n'est pas dans le fichier
            ecrire << "Le mot " << mot << " est inexistant." << endl; // on écrit dans le fichier de sortie que le mot n'est pas dans le fichier
        }

        cout << "Entrez un mot : "; // demande de mot à trouver
        cin >> mot; // on stocke le mot dans la variable mot
    }

    return 0;
}
