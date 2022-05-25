#include <iostream>
int a;
float b;
double c;

int main()
{
    std::cout << "Enter an interger value for \"a\"" << std::endl;
    std::cin >> a;
    std::cout << "Enter a double value for \"b\"" << std::endl;
    std::cin >> b;
    std::cout << "Enter a float value for \"c\"" << std::endl;
    std::cin >> c;
    std::cout << "Value for a: " << a << "\n"
              << "Value for b: " << b << "\n"
             ,+6 << "Value for c: " << c << std::endl;
    return 0;
}
