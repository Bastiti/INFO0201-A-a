#include <iostream>

int i1, i2;
double d1, d2;
int a, b;

using namespace std;

int main()
{
    cout << "Enter integer value for \"i1\": " << endl;
    cin >> i1;
    cout << "Enter integer value for \"i2\": " << endl;
    cin >> i2;
    cout << "Enter double value for \"d1\": " << endl;
    cin >> d1;
    cout << "Enter double value for \"d2\": " << endl;
    cin >> d2;
    cout << "Enter double value for \"a\": " << endl;
    cin >> a;
    cout << "Enter double value for \"b\": " << endl;
    cin >> b;
    cout << "Add: " << i1 + i2 << " Multipy: " << i1 * i2 << " Substract: " << i1 - i2 << " Divide (modulo): " << i1 % i2 << " Divide (real): " << (double)i1 / i2 << endl;
    cout << "Add: " << d1 + d2 << " Multipy: " << d1 * d2 << " Substract: " << d1 - d2 << " Divide: " << (double)d1 / d2 << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}
