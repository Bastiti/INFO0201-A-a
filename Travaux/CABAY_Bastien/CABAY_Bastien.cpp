/*
Nom: CABAY
Prenom: Bastien
Matricule: s210200

Remarque: Code compilé pour un Debian GNU/Linux 64 bits sous CPU Intel Core i5-1135G7
==> La compilation sur des architectures différentes peut poser des problèmes de compatibilité (ex: sur un cpu arm/amd/...) <==

Compilé avec g++ version 10.2.1 (Debian 10.2.1-6)

/!\ Ce code a été testé sous une machine Debian, il est possible qu'il ne fonctionne pas ou differement sur d'autres systèmes.

==> Windows NT 10.0, il faut inclure, la bibliotheque <ctime> dans le projet.<==

$ lsb_release -a
Distributor ID:	Debian
Description:	Debian GNU/Linux 11 (Bullseye)
Release:	    11
Code Name:	    bullseye

Règle n°1 : Tant que le code marche, il n'y a rien à modifier.
Règle n°2 : Si le code ne marche pas, il faut modifier le code pour qu'il marche.
Règle n°3: Si il y a un problème, utiliser la méthode de la règle n°2 pour résoudre le problème.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL)); // Initialisation de la fonction rand() avec la date du système. Cette fonction est utilisée pour générer des nombres aléatoires.
    
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    // Déclaration des variables.
    char wordlist[48844][26];                                                // Tableau de mots contenant les mots de la liste de mots.
    int letters;                                                             // Nombre de lettres dans le mot à trouver.
    int tries;                                                               // Nombre de tentatives.
    cout << "Bienvenue dans le jeu du Motus." << endl;                       // Message de bienvenue.
    cout << "Veuillez entrer le nombre de lettres dans le mot à trouver : "; // Demande du nombre de lettres dans le mot à trouver.
    cin >> letters;                                                          // Le joueur entre le nombre de lettres dans le mot à trouver.
    while (letters < 1 || letters > 25)                                      // Boucle pour vérifier que le nombre de lettres est compris entre 1 et 25.
    {
        cout << "Nombre de lettres invalidated, veuillez entrer un nombre entre 1 et 25 : "; // Message d'erreur.
        cin >> letters;                                                                      // Le joueur entre le nombre de lettres dans le mot à trouver.
    }
    cout << "Veuillez entrer le nombre de tentatives : "; // On demande au joueur le nombre de tentatives.
    cin >> tries;                                         // Le joueur entre le nombre de tentatives.
    while (tries < 1)                                     // Boucle pour vérifier que le nombre de tentatives est supérieur à 0.
    {
        cout << "Nombre de tentatives invalidated, veuillez entrer un nombre supérieur à 0 : "; // Message d'erreur.
        cin >> tries;                                                                           // Le joueur entre le nombre de tentatives.
    }

    /*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    // Lecture du fichier contenant les mots.
    ifstream file("wordlist.txt"); // On ouvre le fichier wordlist.txt.
    if (!file)                     // Si le fichier n'existe pas, on affiche un message d'erreur.
    {
        cout << "Erreur : le fichier wordlist.txt n'existe pas." << endl;
        return 1;
    }
    else if (file.is_open()) // Si le fichier existe, on continue.
    {
        for (int i = 0; i < 48844; i++) // On parcourt le tableau de mots.
        {
            file >> wordlist[i]; // On lit le mot.
        }
    }
    file.close(); // On ferme le fichier.

    /*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    // Recherche d'un mot de worldlist qui a le même nombre de lettres que le mot à trouver.
    int random = rand() % 48844; // On génère un nombre aléatoire entre 0 et 48843.
    int length = 0;
    while (letters != length) // On vérifie que le mot généré a le même nombre de lettres que le mot à trouver.
    {
        length = 0;
        random = rand() % 48844; // On génère un nombre aléatoire entre 0 et 48843.
        for (int g = 0; g < 26; g++)
        {
            if (wordlist[random][g] != '\0') // On vérifie que le mot généré n'est pas vide.
            {
                length++; // On incrémente la longueur du mot
            }
        }
    }
    cout << wordlist[random] << endl; // On affiche le mot généré.

    /*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    // Partie qui gère le jeu.
    for (int i = 0; i < tries; i++) // On fait tourner le programme autant de fois que le joueur ait choisi.
    {
        char userword[26];                   // On déclare un tableau de caractères pour le mot du joueur.
        cout << "Veuillez entrer le mot : "; // On demande au joueur de rentrer le mot.
        cin >> userword;                     // On lit le mot.
        int userlength = 0;                  // On déclare une variable pour la longueur du mot.
        for (int g = 0; g < 26; g++)         // On parcourt le tableau de caractères.
        {
            if (userword[g] != '\0') // On vérifie que le mot n'est pas vide.
            {
                userlength++; // On incrémente la longueur du mot.
            }
        }

        /*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        // Vérification de la longueur du mot.
        cout << userlength << endl;
        while (userlength != letters) // On vérifie que le mot a le même nombre de lettres que le mot à trouver.
        {
            cout << "Mot invalidated, veuillez entrer un mot avec " << letters << " lettres : "; // Message d'erreur.
            cin >> userword;                                                                     // On lit le mot.
            userlength = 0;                                                                      // On réinitialise la longueur du mot.
            for (int g = 0; g < 26; g++)                                                         // On parcourt le tableau de caractères.
            {
                if (userword[g] != '\0') // On vérifie que le mot n'est pas vide.
                {
                    userlength++; // On incrémente la longueur du mot.
                }
            }
        }
        char processWord[26];        // On déclare un tableau de caractères pour le mot à trouver.
        for (int g = 0; g < 26; g++) // On parcourt le tableau de caractères.
        {
            processWord[g] = wordlist[random][g]; // On copie le mot à trouver dans le tableau de caractères.
        }
        int wellPlaced = 0;             // On déclare une variable pour le nombre de lettres bien placées.
        int badPlaced = 0;              // On déclare une variable pour le nombre de lettres mal placées.
        char nonvalidated[26] = {'\0'}; // On déclare un tableau de caractères pour le mot non validated

        /*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        // Partie pour vérifier les lettres bien placées et mal placées.
        for (int g = 0; g < 26; g++) // On parcourt le tableau de caractères.
        {
            if (userword[g] != '\0') // On vérifie que le mot n'est pas vide.
            {
                if (userword[g] == processWord[g]) // On vérifie que les lettres sont identiques.
                {
                    wellPlaced++;               // On incrémente le nombre de lettres bien placées.
                    cout << userword[g] << " "; // On affiche la lettre.
                    userword[g] = '\0';         // On met la lettre à 0.
                    processWord[g] = '\0';      // On met la lettre à 0.
                }
                else // Si les lettres ne sont pas identiques.
                {
                    cout << "_ "; // On affiche un "_".
                }
                if (userword[g] != processWord[g]) // Si les lettres ne sont pas identiques.
                {
                    for (int h = 0; h < 26; h++) // On parcourt le tableau de caractères.
                    {
                        if (userword[h] == processWord[g] && userword[h] != '\0' && processWord[g] != '\0' && g != h) // On vérifie que les lettres sont identiques.
                        {
                            nonvalidated[h] = userword[h]; // On copie la lettre dans le tableau de caractères.
                            processWord[g] = '\0';         // On met la lettre à 0.
                            badPlaced++;                   // On incrémente le nombre de lettres mal placées.
                        }
                    }
                }
            }
        }

        /*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        // Partie qui affiche les lettres mal placées.
        if (badPlaced != 0) // Si le nombre de lettres mal placées est égal à 0.
        {
            cout << "( ";                // On affiche un crochet ouvrant.
            for (int g = 0; g < 26; g++) // On parcourt le tableau de caractères.
            {
                if (nonvalidated[g] != '\0') // On vérifie que le mot n'est pas vide.
                {
                    cout << nonvalidated[g] << " "; // On affiche la lettre.
                }
            }
            cout << ")"; // On affiche un crochet fermant.
        }
        cout << endl;

        /*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        // Partie de vérification de la victoire.
        if (wellPlaced == letters) // Si le nombre de lettres bien placées est égal au nombre de lettres dans le mot à trouver.
        {
            cout << "Vous avez gagné !" << endl; // On affiche un message de victoire.
            return 0;                            // On quitte le programme.
        }
        else if (i == tries - 1) // Si le joueur a perdu.
        {
            cout << "Vous avez perdu !" << endl; // On affiche un message de défaite.
            return 0;                            // On quitte le programme.
        }
        else // Si le joueur n'a pas gagné.
        {
            cout << "Vous avez " << tries - i - 1 << " tentatives restantes." << endl; // On affiche le nombre de tentatives restantes.
        }
    }
}
