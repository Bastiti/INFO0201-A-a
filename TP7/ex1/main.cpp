#include <iostream>

using namespace std;

int main()
{
    // Déclarer une variable entière a
    int a = 2;
    int* b = &a;
    int* c = &a;
    int* d = &a;
    a *= (*b);
    a *= (*c);
    a *= (*d);
    cout << a << endl;
}