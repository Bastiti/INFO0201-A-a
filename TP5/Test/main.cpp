#include <iostream>

using namespace std;

void afficher(int unNombre){
    std::cout << "je fais ce que je veux d'abord "<< unNombre;
}
void afficher(int unAutreNombre){
    std::cout << "je fais toujours ce que je veux "<< unAutreNombre;
}
int main()
{
    afficher(5);
}
