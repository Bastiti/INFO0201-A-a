#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int n;
double sum[3];

int main()
{
    ofstream pifile("./pi.txt");
    cout.precision(15);
    for (int i=1; i<4; i++)
    {
        while(2*n+1<pow(10,3*i))
        {
            sum[i] += (double)pow(-1,n)/(2*n+1);
            n++;
        }
        pifile << "Found the value of pi: " << 4*sum[i] << "\nWith a precision of: " << n << "\n\n";
        cout << "Found the value of pi: " << 4*sum[i] << "\nWith a precision of: " << n << "\n\n";
        n = 0;
    }
    pifile.close();
    return 0;
}
