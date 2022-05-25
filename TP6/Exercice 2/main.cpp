// Ouvrir le fichier “users.txt” en lecture et charger les 10 noms et prénoms qui y figurent dans un vector de string ;

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


// // Ecrire une fonction string formattage(string nom, string prenom) qui renvoie une chaine de caractères contenant la 1re lettre du prénom, un point “.” suivi d’un espace et le nom (“P. Nom”) ;

string formattage(string nom, string prenom)
{
    string format;
    format = prenom.substr(0,1) + ". " + nom;
    return format;
}

int main()
{
    vector<string> users;
    string name;
    ifstream file("users.txt");
    if(file)
    {
        while(file >> name)
        {
            users.push_back(name);
        }
    }
    else
    {
        cout << "Impossible d'ouvrir le fichier" << endl;
    }
    // En utilisant cette fonction, Afficher la liste des noms et prénoms à l’écran sous la forme “P. Nom”, où “P” est la 1re lettre du prénom.
    for(int i = 0; i < users.size(); i++)
    {
        cout << formattage(users[i], users[i+1]) << endl;
        i++;
    }
    return 0;
}