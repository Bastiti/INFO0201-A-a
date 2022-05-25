#include <iostream>
using namespace std;


void afficher(int i) {
 cout << " La valeur est de type int :" << i << endl;
}
void afficher(double  f) {
 cout << " La valeur est de type float :" << f << endl;
}
void afficher(char c[]) {
 cout << " La valeur est de type tableau de char :" << c << endl;
}

int main() {
 afficher(5);
 afficher(5.2);
 afficher("cinq");
 return 0;
}
