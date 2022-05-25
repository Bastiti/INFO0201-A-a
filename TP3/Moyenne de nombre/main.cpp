#include <iostream>
#include <cstdlib>
using namespace std;

int n,moyenne;
int main()
{
    srand(time(NULL));
    cout << "Hello world!" << endl;
    cout << "Entrer le nombre de nombre a générer: \n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        moyenne += rand()%1001;
    }
    cout << "La somme tends vers: " << moyenne/n << endl;
    return 0;
}
