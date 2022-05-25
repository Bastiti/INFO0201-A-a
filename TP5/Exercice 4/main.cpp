#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

double P_val(vector<double> $func,double x)
{
    double y = 0;
    for(int i = 0; i<$func.size(); i++)
    {
        y += $func[i]*pow(x,i);
    }
    return y;
}
int main()
{
    int deg;
    cout << "Degré du polynôme:" << endl;
    cin >> deg;
    cout << "Entrez les valeurs du polynomes:" << endl;
    vector<double> func(deg);
    for(int i = 0; i <= deg; i++)
    {
        int j;
        cin >> j;
        func[i] = j;
    }
    ofstream results("./result.txt");
    for (double i = -3; i <= 3; i+=0.001)
    {
        results << "( " << i << "," << P_val(func,i) << ")\n";
    }
    return 0;
}
