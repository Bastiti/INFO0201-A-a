#include <iostream>
#include <cstdlib>

using namespace std;
float rightprice;
float price;
int tries = 10;
int main()
{
    srand(time(NULL)); // Generate random time based on the CPU.
    rightprice = rand()%100000; // 1000€*100 to get the cents.
    rightprice = rightprice/100; // Divde to get price as a decimal number.
    while (tries > 0){ // While is more appropritate for this.
        cout << "Guess the price, please input a price between 0 and 1000€: " << "You have: " << tries << " tries left." << endl;
        cin >> price;
        tries -= 1;
        if (price > rightprice){ // Check if input > generated
            cout << "Your price is too high, you have " << tries << " tries left." << endl;
        } else if ( price < rightprice){ // Check if input < generated
            cout << "Your price is too low, you have " << tries << " tries left." << endl;
        } else { // Check if input = generated
            cout << "gg";
            return 0;
        }
    }
    cout << "You failed, the right price was: " << rightprice << endl; // When you win, the return 0; trigger. That ends the program. So, Here, it's if the condition inside the while is equal to 0.

}
