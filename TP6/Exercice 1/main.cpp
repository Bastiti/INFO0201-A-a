// Déclarer un objet string et demander à l'utilisateur de l'entrer;
// Afficher le contenu de l'objet string;

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cout << "Entrez une chaine de caractere: ";
    getline(cin, str);
    cout << "Vous avez entre: " << str << endl;
    // Montrer la longueur du string
    cout << "La longueur de la chaine est: " << str.length() << endl;
    // Modifier le message pour que la première lettre soit une majuscule si elle ne l’est pas ;
    if (str[0] >= 'a' && str[0] <= 'z')
    {
        str[0] = str[0] - 32;
    }
    // Ajouter un point “.” à la fin du message s’il n’y en a pas ;
    if (str[str.length() - 1] != '.')
    {
        str += '.';
    }
    // Afficher le message ainsi modifié à l’écran ;
    cout << "Le message modifie est: " << str << endl;
    // Demander à l’utilisateur un mot à chercher ;
    string search;
    cout << "Entrez un mot a chercher: ";
    getline(cin, search);
    // Chercher le mot dans le message et afficher combien il y a de fois qu’il est présent et à quelle position ;
    int count = 0;
    int pos = str.find(search);
    while (pos != string::npos)
    {
        count++;
        pos = str.find(search, pos + 1);
    }
    cout << "Le mot " << search << " est present " << count << " fois et a la position " << pos << endl;

    return 0;
}