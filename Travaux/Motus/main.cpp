#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;



string getWord(int letters) // Prends un mot au random dans le dico et le renvoie sous forme d'un tableau de charactere.
{
    vector<string> words;
    vector<char> c(letters);
    string word;
    ifstream dico("./dico.txt");
    if(dico.is_open())
    {
        while (getline(dico, word)) words.push_back(word); // Prends chaques lignes indépendament du fichier et la stocke dans le vector grâce au push_back.
        int i;
        do
        {
            i = rand() % words.size(); // Génere un nombre entre 0 et la taille du tableau
        }
        while(words[i].size() != letters); // Check si la taille du mot à l'emplacement i du tabmeau est bien égal au nombre de lettre.
        return words[i];
    }
    else
    {
        cout << "Le fichier ne peut pas etre tout vert" << "\n";
        exit(0);
    }
}



bool gameLogic(string tofind, string userinput, int letters) // Logique du jeu en entier:
{
    string game;
    vector<bool> tofindBool(letters, false);
    vector<bool> inputBool(letters, false);

    int bienPlace = 0;

    for (int i =0; i<letters; i++) // Permet de trouver les lettres bien placées.
    {
        if (tofind[i] == userinput[i]) // Check si il y a des lettres correspondantes entre le mot de l'utilisateur et celui qui a été pioché par le programme.
        {
            tofindBool[i] = true; //Montre que cette lettre a déjà été validée et ne doit plus être validée.
            inputBool[i] = true; //Montre que cette lettre a déjà été validée et ne doit plus être validée.

            bienPlace++;
            game.push_back(userinput[i]);
            game.push_back(' ');
        }
        else
        {
            game.push_back('_');
            game.push_back(' ');
        }
    }

    string malPlace;
    for (int i = 0; i < letters; i++) // Permet de trouver les lettres qui existent dans le mot à trouver mais qui sont mal placée.
    {
        for (int j = 0; j < letters; j++)
        {
            if (i!= j && tofind[i] == userinput[j]) // Filtre les lettres communes qui ne sont pas déjà bien placée.
            {
                if(tofindBool[i] == false && inputBool[j] == false) // Ajoute une sécurité pour vérifier que les lettres à comparer ne sont pas déjà validée. #AntiDoublon.
                {
                    tofindBool[i] = true; // Montre que cette lettre a été traitée et validée.
                    inputBool[j] = true; //Montre que cette lettre est mal placée et ne doit plus être validée.
                    cout << "hello" << endl;
                    malPlace.push_back(tofind[j]);
                    malPlace.push_back(',');
                }
            }
        }
    }
    malPlace.pop_back();
    if(malPlace.empty())
        game += " (" + malPlace + " )";
    cout << game << endl;
    return bool(bienPlace == letters);
}

void gameEnd(string tofind, int tries)
{
    if(tries == 0 )
    {
        cout << "Vous avez perdu ! Le mot a trouver était: " + tofind << endl;
    }
    else
    {
        cout << "Bien joué, vous avez gagné la partie ! Le mot était: " +tofind + ". Et il vous restait: " << tries << " essais restants.";
    }
}

int main()
{
    int letters;
    int max_tries;
    string joueur;
    srand(time(NULL));
    // Commence le jeu:
    cout << ">Console: Entrer votre nom d'utilisateur:" << "\n";
    cout << ">" +joueur;
    cin >> joueur;
    cout << ">Console: Indiquer le nombre des lettres du mot:" << "\n";
    cout << ">" +joueur+": ";
    cin >> letters;
    cout << ">Console: Indiquer le nombre d’essais maximal:" << "\n";
    cout << ">" +joueur+": ";
    cin >> max_tries;
    cout << "\n";
    string tofind = getWord(letters); // Appelle la fonction qui va chercher un mot au hazard.
    cout << tofind << "\n";
    string userinput;
    cout << ">" +joueur+": ";
    cin >> userinput;
    while (gameLogic(tofind,userinput, letters) == false && max_tries > 0)
    {
        max_tries--;
        cout << "Perdu" << endl;
        cout << ">" +joueur+": ";
        cin >> userinput;
    }
    gameEnd(tofind,max_tries);

}