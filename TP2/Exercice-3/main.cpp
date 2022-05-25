#include <iostream>
#include <cmath>

double a;
int lastrealnr;

using namespace std;


void verifyLastNumbers(double number)
{
    lastrealnr = fmod(number,97); // Uses of fmod to avoid being on negative number.
    cout << "Les deux dernier numeros de compte devrait etre: " << lastrealnr << endl;
}

int main()
{
    cout << "Enter double value for \"a\": " << endl;
    cin >> a;
    cout << "Integer part: " << (int)a << "; Decimal part: " << a-(int)a << endl;
    verifyLastNumbers(2105468768);
    verifyLastNumbers(3631264958);
    verifyLastNumbers(19185472);
    return 0;
}
