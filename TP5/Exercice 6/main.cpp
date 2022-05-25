#include <iostream>
#include <stdio.h>

using namespace std;

int fibo(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return (fibo(n-1) + fibo(n-2));
}

int main()
{
    int n;
    cout << "Nombre de terme de la suite à calculer" << endl;
    cin >> n;
    cout << "Voici les %nbr premiers termes de la série de fibo: " << "\n";
    for(int i = 0; i<= n; i++)
    {
        cout << fibo(i) << "\n";
    }
    return 0;
}
