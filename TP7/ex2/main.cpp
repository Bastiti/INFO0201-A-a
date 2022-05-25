#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>

using namespace std;

string tocaps(string s)
{
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            res += s[i] - 32;
        }
        else
        {
            res += s[i];
        }
    }
    return res;
}

int main()
{
    // Charger les données du fichier “alphabet_morse.txt”
    // Charger les lettres de l'alphabet latin dans un vector et le'alphabet morse dans un autre vector

    vector<string> alphabet_latin;
    vector<string> alphabet_morse;

    ifstream fichier("alphabet_morse.txt");
    string ligne;
    unsigned int microsecond = 500000;

    while (getline(fichier, ligne))
    {
        string lettre = ligne.substr(0, 1);
        string code = ligne.substr(2);
        alphabet_latin.push_back(lettre);
        alphabet_morse.push_back(code);
    }

    // Sasir des mots à traduire et les placer dans un troisième vector.
    // Jusqu’à ce que le mot “STOP” soit saisi

    vector<string> mots;
    string mot;
    cout << "Saisir un mot à traduire : ";
    cin >> mot;

    while (mot != "STOP")
    {
        mot = tocaps(mot);
        mots.push_back(mot);
        cout << "Saisir un mot à traduire : ";
        cin >> mot;
    }

    // A l’aide des correspondances entre les deux vector précédemment créés,
    // traduire les mots précédemment saisis
    // et afficher le résultat sur la sortie standard.
    vector<string> traductions;

    for (int i = 0; i < mots.size(); i++)
    {
        string aTrad = mots[i];
        for (int j = 0; j < aTrad.size(); j++)
        {
            char lettre = aTrad[j];
            for (int k = 0; k < alphabet_latin.size(); k++)
            {
                if (lettre == alphabet_latin[k][0])
                {
                    traductions.push_back(alphabet_morse[k]);
                    traductions.push_back(" ");
                }
            }
        }
    }
    for (int i = 0; i < traductions.size(); i++)
    {
        for (int j = 0; j < traductions[i].size(); j++)
        {
            if (traductions[i][j] == '.')
            {
                usleep(microsecond * 0.1);
                system("play -q morse2.wav");
            }
            else if (traductions[i][j] == '-')
            {
                usleep(microsecond * 0.3);
                system("play -q morse.wav");
            }
        }
    }
    // write mots into mots.txt
    ofstream fichier2("mots.txt");
    fichier2 << "THIS TEXT MEANS: ";
    for (int i = 0; i < mots.size(); i++)
    {
        fichier2 << mots[i] << endl;
    }
    fichier2.close();
    return 0;
}