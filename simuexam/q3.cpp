
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Charger le contenu de ./mots_caches.txt de manière dynamique
    // Elever les espaces entre les lettres

    ifstream fichier("./mots_caches.txt");
    string ligne;
    vector<string> mots;
    while (getline(fichier, ligne))
    {
        string mot = "";
        for (int i = 0; i < ligne.size(); i++)
        {
            if (ligne[i] != ' ')
            {
                mot += ligne[i];
            }
        }
        mots.push_back(mot);
    }

    // Afficher les mots
    for (int i = 0; i < mots.size(); i++)
    {
        cout << mots[i] << endl;
    }

    // Demander un mot à l'utilisateur et vérifier si il est dans le fichier
    string mot;
    cout << "Entrez un mot : ";
    cin >> mot;
    bool trouve = false;
    int position = -1;
    for (int i = 0; i < mots.size(); i++)
    {
        trouve = mots[i].find(mot) != string::npos;
        if (trouve)
        {
            cout << "Le mot " << mot << " est dans le fichier, trouvé à la position: ";
            cout << "(" << i+1 << "," <<(mots[i].find(mot)+1) << ")" << endl;
            break;
        }
    }
    return 0;
}
