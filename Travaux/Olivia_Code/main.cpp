#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    srand(time(NULL));
    char tableau[48843][26] = {'\0'};

    ifstream dico("/home/bastitibot/intro-progra-cours/Travaux/CABAY_Bastien/dico.txt");

    if(!dico.is_open()) //Pr�cise si le fichier n'est PAS ouvert
    {
        cout<<"ERREUR : Impossible d'ouvrir le fichier"<<endl;
        return EXIT_FAILURE;
    } //Le programme affiche un message d'erreur et s'arr�te, si le fichier ne s'est pas ouvert.

    while(dico.good()) // Recopie les donn�es du fichier dans un tableau du programme
    {
        for(int i=0; i<48843; i++)
        {
            dico>>tableau[i];// >> Permet d'associer chaque ligne du fichier � 1 �l�ment de mon tableau
        }
    }
    dico.close();//Fermer le fichier

    int nombredelettres; // Je d�clare les variables que l'utilisateur entrera � la prochaine commande
    int difficulte;


    cout<<"Bienvenue dans le jeu Motus."<<endl; // dialogue avec l'utilisateur pour qu'il comprenne ce qu'il doit faire
    cout<<"Ce jeu consiste a deviner un mot choisi au hasard."<<endl;
    cout<<"Veuillez introduire le nombre de lettres que votre mot comportera :"<<endl;

    cin>>nombredelettres; // permet � l'utilisateur d'entrer la donn�e demand�e au clavier

    cout<<"Veuillez choisir le nombre d'essais mis a votre disposition :"<<endl;

    cin>>difficulte;

    int hasard = rand()%48844; //D�finition d'une variable qui s�lectionnera au hasard un nombre entier entre 0 et 48843, et qui nous permettra de choisir un mot du dictionnaire au hasard
    int n=0; //Variable qui va me permettre de compter le nombre de lettres dans un mot du dictionnaire
    int nouveauhasard;//Variable qui va me permettre d'enregistrer la valeur du num�ro du mot final (celui qui sortira de la boucle)

    while (hasard!=50000)
    {
        n=0; //Je r�initialise la valeur de mon incr�ment pour recommencer le comptage � chaque fois que la boucle se relance
        while (tableau[hasard][n]) //Je cr�e une boucle qui me permet de compter le nombre de lettres dans le mot du tableau choisi
        {
            n++;
        }
        if(n==nombredelettres)//J'ach�ve la boucle si le mot s�lectionn� a le bon nombre de lettres
        {
            nouveauhasard=hasard;
            hasard=50000;
        }
        else//Je passe au mot de la ligne suivante dans la liste si ce dernier ne comporte pas le bon nombre de lettres et je recommence
        {
            hasard++;
        }
    }

    cout<<"Voici le mot selectionne : "<<tableau[nouveauhasard]<<endl;

    cout<<"Veuillez entrer un mot de "<<nombredelettres<<" lettres : "<<endl;
    int i=1;// Permettra de compter le nombre d'essais

    while(i<difficulte+1)
    {
        int b = 0;
        char reponse[nombredelettres];
        char intermediaire1[nombredelettres] = {'\0'};
        char intermediaire2[nombredelettres] = {'\0'};
        char toRemove[nombredelettres] = {'\0'};
        int place = 0;
        cin>>reponse;//L'utilisateur entre un mot dans la console
        for(int j = 0; j < nombredelettres; j++)
        {
            toRemove[j] = tableau[nouveauhasard][j];
        }
        while(reponse[b])//Je compte le nombre de lettres que contient ce mot
        {
            b++;
        }

        if (b!=nombredelettres)//Si l'utilisateur a introduit un mot avec le mauvais nombre de lettres, je lui demande de recommencer en comptant un essais
        {
            cout<<"Ce mot contient "<<b<<" lettres au lieu de "<<nombredelettres<<". Veuillez reessayer de nouveau :"<<endl;
        }
        else
        {
            for(int m = 0; m < nombredelettres; m++)
            {
                if(reponse[m]==toRemove[m])
                {
                    intermediaire1[m]=tableau[nouveauhasard][m];
                    toRemove[m] = '\0';
                    reponse[m] = '\0';
                    place++;
                }
                else
                {
                    intermediaire1[m]='_';
                }
                if(reponse[m]!=toRemove[m])
                {
                    for(int v = 0; v < nombredelettres; v++)
                    {
                        if(reponse[v]==toRemove[m] && v!=m&& reponse[v] != '\0' && toRemove[m]!='\0') // Si intermediaire1 contient une lettre en m et en v, on fait rien. A TESTER...
                        {
                            intermediaire2[v]=reponse[v];
                            toRemove[m] = '\0';
                             reponse[v] = '\0';
                        }
                    }
                }
            }
        }

        if(place==nombredelettres)
        {
            cout<<"Felicitations ! Vous avez trouve le mot en "<<i<<" essais, et aves gagne !"<<endl;
            return 0;
        }
        else
        {
            cout<<intermediaire1<<" ( ";

            for (int k = 0; k < nombredelettres; k++)
            {
                if (intermediaire2[k] != '\0') // Si la lettre n'est pas vide
                {
                    cout << intermediaire2[k];
                    cout << " ";
                }
            }
            cout << ")" << endl;

            cout<<"Veuillez reessayer. Il vous reste "<<difficulte-i<<" essais :"<<endl;
            i++;
        }

    }






    if(i==difficulte+1)
        cout<<"Malheureusement, vous avez utilise vos "<<difficulte<<" essais sans succes, et avez perdu. Le mot recherche etait : "<<tableau[nouveauhasard]<<endl;
    return 0;
}
