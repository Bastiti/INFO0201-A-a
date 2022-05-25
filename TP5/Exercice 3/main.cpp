#include <iostream>
#include <vector>

using namespace std;

int higher(int i)
{
    switch(i)
    {
        case 3:
            i=0;
            break;
        case 4:
            i=1;
            break;
        case 5:
            i=2;
            break;
    }
    return i;
}

double produit_scalaire(double x1, double y1, double z1,double x2, double y2, double z2)
{
    return x1*x2+y1*y2+z1*z2;
}

void produit_vectoriel(vector<double> &vect1, vector<double> &vect2, vector<double> &vect)
{
    cout << "{ ";
    for(int i = 0; i<3; i++)
    {
        vect[i] = vect1[higher(i+1)] * vect2[higher(i+2)] - vect1[higher(i+2)] * vect2[higher(i+1)];
        cout << vect[i] << " ";
    }
    cout << " }\n";
}
int main()
{
    vector<double> vect1(3); //Crée un tableau de 0 nombre à virgule
    vector<double> vect2(3);
    vector<double> vect(3);
    cout << "Entrer les composantes du premier vecteur:" << "\n";
    cin >> vect1[0] >> vect1[1] >> vect1[2];
    cout << "Entrer les composantes du second vecteur:" << "\n";
    cin >> vect2[0] >> vect2[1] >> vect2[2];
    cout << "Le produit scalaire: u.v = " << produit_scalaire(vect1[0],vect1[1],vect1[2],vect2[0],vect2[1],vect2[2]) << "\n";
    produit_vectoriel(vect1, vect2, vect);
    return 0;
}
