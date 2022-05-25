#include <iostream>
#include <cstdlib>

using namespace std;

int n1,n2,n3,n4;
int wellplaced,wrongplaced;
int tries = 1;
int main()
{
    srand(time(NULL));
    // Génération de nombre aléatoire
    int a = rand()%10;
    int b = rand()%10;
    int c = rand()%10;
    int d = rand()%10;

    cout<<a<<b<<c<<d<<endl; // Afficher la réponse pour le debug.

    do
    {
        wellplaced = 0;
        wrongplaced = 0;
        cout << "Please input 4 numbers:\n";
        cin >> n1;
        cin >> n2;
        cin >> n3;
        cin >> n4;
        // Check for wellplaced
        if (n1==a)
            wellplaced++;
        if (n2==b)
            wellplaced++;
        if (n3==c)
            wellplaced++;
        if (n4==d)
            wellplaced++;
        // check for wrong placed
        if (((a==n2)||(a==n3)||(a==n4))&&(a!=n1))
            wrongplaced++;
        if (((b==n3)||(b==n4)||(b==n1))&&(b!=n2))
            wrongplaced++;
        if (((c==n4)||(c==n1)||(c==n2))&&(c!=n3))
            wrongplaced++;
        if (((d==n1)||(d==n2)||(d==n3))&&(d!=n4))
            wrongplaced++;

        cout<<"Game\t"<<tries<<"\tWellplaced numbers\t"<<wellplaced<<"\tWrongplaced numbers\t"<<wrongplaced<<endl;
        tries++;

    }
    while((tries < 10)&&(wellplaced!=4)); // While il va si tries >= 10 ou wellplaced = 4

    if (wellplaced!=4)
        cout<<"You lost !"<<endl;
    else
        cout<<"You won !"<<endl;
    cout<<"Solution:\t"<<a<<b<<c<<d<<endl;
}
