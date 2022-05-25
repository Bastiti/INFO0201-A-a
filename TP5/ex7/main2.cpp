#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

void tri(vector<double> &data, vector<double> &valeur_central, double l_classe, vector<int> &counter) // 
{
    counter.resize(valeur_central.size(), 0); // s'assure que data_f a la bonne taille

    for (int i = 0; i < data.size(); i++) // pour chaque donn�e
    {
        for (int j = 0; j < valeur_central.size(); j++) // teste chaque classe
        {
            if (abs(data[i] - valeur_central[j]) <= l_classe / 2) // comptabilise
            {
                counter[j]++;
                break;
            }
        }
    }
}

void affi(vector<double> &valeur_central, vector<int> &counter)
{
    double q; // quantit� de d'�l�ment pas caract�re
    int q_max = 0;
    for (int k = 0; k < counter.size(); k++)
    {
        if (q_max < counter[k])
            q_max = counter[k];
    }

    q = q_max / 100; // q par =

    for (int i = 0; i < counter.size(); i++) // Select which line we should work on.
    {
        cout << valeur_central[i] << "\t|";

        int n; // Number for =
        n = counter[i] / q;

        if ((n == 0) && (counter[i] != 0)) // Add = in case the class is empty.
            n = 1;

        for (int j = 0; j < n; j++) // Filling lines
        {
            cout << "=";
        }
        cout << endl;
    }
}

int main()
{
    vector<double> data(0); // data
    vector<double> cntr_values(15);
    vector<int> repartition(0);
    double largeur = 0.6;

    ifstream file("./data.dat");
    while (file.good())
    {
        double a;
        file >> a;
        data.push_back(a);
    }
    for (int h = 0; h < 15; h++)
    {
        cntr_values[h] = (-45 + 3 + 6 * h) / 10.;
    }

    tri(data, cntr_values, largeur, repartition);
    affi(cntr_values, repartition);
}
