// Ouvrir le chier presence.txt en lecture et charger les 200 noms et prénoms qui y gurent dans un vector de string ;

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> liste;
    string nom;
    ifstream fichier("presence.txt");
    if (fichier)
    {
        while (getline(fichier, nom))
        {
            liste.push_back(nom);
        }
    }
    else
    {
        cout << "Impossible d'ouvrir le fichier presence.txt" << endl;
    }
    fichier.close();
    // Trier le tableau dans l'ordre alphabétiquement croissant des noms ;
    // Parcourir le tableau, comparer les noms successifs deux à deux et les échanger s'ils ne sont pas dans le bon ordre ;
    // Répéter le parcours du tableau entier tant que des éléments ont dû être échangés quelque part lors de l'itération précédente ;
    // Enregistrer le tableau trié dans un fichier presence_trie.txt ;

    for (int i = 0; i < liste.size(); i++) // On parcourt le tableau une première fois afin de trier le tableau
    {
        for (int j = 0; j < liste.size(); j++) // On parcourt le tableau une seconde fois afin de comparer les noms
        {
            if (liste[i] < liste[j]) // si le nom est plus petit que le nom suivant
            {
                string temp = liste[i]; // On crée un tampon pour échanger les éléments. Tampon = emplacement dans la mémoire temporaire pour effectuer un échange des éléments.
                liste[i] = liste[j]; // On échange les éléments
                liste[j] = temp; // On assigne le tampon à l'élément suivant.
            }
        }
    }

    /*bool echange = true;
    while (echange)
    {
        echange = false;
        for (int i = 0; i < liste.size() - 1; i++)
        {
            if (liste[i] > liste[i + 1])
            {
                string temp = liste[i];
                liste[i] = liste[i + 1];
                liste[i + 1] = temp;
                echange = true;
            }
        }
    }*/

    ofstream fichier2("presence_trie.txt");
    if (fichier2)
    {
        for (int i = 0; i < liste.size(); i++)
        {
            fichier2 << liste[i] << endl;
        }
    }
    else
    {
        cout << "Impossible d'ouvrir le fichier presence_trie.txt" << endl;
    }
    fichier2.close();
    // Demander à l'utilisateur de saisir un nom à rechercher au clavier ;
    // Chercher le nom dans le tableau trié ;

    cout << "Entrez un nom : ";
    string nom_a_chercher;
    getline(cin, nom_a_chercher);
    // Demander un nouveau nom à vérifier à l'utilisateur tant que le mot "quitter" n'est pas saisi au clavier.

    while (nom_a_chercher != "quitter")
    {

        int position = 0;
        // Chercher dans le tableau si le nom y est présent et acher le résultat à l'écran ;
        for (int i = 0; i < liste.size(); i++)
        {
            if (liste[i] == nom_a_chercher)
            {
                position = i;
            }
        }
        // Dans un chier verication_presence.txt
        // ajouter le nom et prénom recherchés ainsi que le résultat sous la forme
        // "Nom prénom est présent/absent" selon le cas;
        ofstream fichier3("verification_presence.txt");
        if (fichier3)
        {
            if (position == 0)
            {
                fichier3 << nom_a_chercher << " est absent" << endl;
                cout << nom_a_chercher << " est absent" << endl;
            }
            else
            {
                fichier3 << nom_a_chercher << " est présent" << endl;
                cout << nom_a_chercher << " est présent" << endl;
            }
        }
        else
        {
            cout << "Impossible d'ouvrir le fichier verification_presence.txt" << endl;
        }
        fichier3.close();
        cout << "Entrez un nom : ";
        getline(cin, nom_a_chercher);
    }
    return 0;
}