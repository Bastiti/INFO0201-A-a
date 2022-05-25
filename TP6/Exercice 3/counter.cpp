// Create a string, and ask the user to enter a word.

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char word[] = "hello"; // Après être converti en int: 104 101 108 108 111
    for(int i = 0; i < strlen(word); i++)
    {
        cout << int(word[i]);
    }
    return 0;
}