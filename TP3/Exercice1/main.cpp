#include <iostream>
#include <cstdlib>
using namespace std;

char a;
int b;
unsigned int c;
bool isLowercaseVowel, isUppercaseVowel;

int Vowel(char c){
    if (isupper(c) == 256){
        cout << "This is the letter number:"<< (int)c-64 << " of the alphabet" << endl;
    } else {
        cout << "This is the letter number:"<< (int)c-96 << " of the alphabet" << endl;
    }
    isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'); //bool value that output true while "c" is one of these characters.
    isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'); //bool value that output true while "c" is one of these characters.
    if (isLowercaseVowel || isUppercaseVowel) {
        cout << c << " is a vowel." << endl;;
    } else {
        cout << c << " is a consonant." << endl;
    }
    return 0;

}

int main()
{
    srand(time(NULL));
    cout << "Input a letter" << endl;
    cin >> a;
    Vowel(a);
    for (int i=65; i < 123; i++){
    if (!(i >= 91 && i <= 96))
        cout << (char)i << " " << i << endl; // Print the char and the ascii code
    }
    cout << "Input number to generate: " << endl;
    cin >> b;
    for (int i = 0; i < b; i++){
        c += rand()%1000; // The other exercice asked us to generate random number. c += ... is equal to: c = c + ...
    }
    cout << c/b; //
    return 0;
}
