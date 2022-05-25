#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

// Create a function that takes a vector of data, a vector of center values, and a width of the classes and returns a vector of the number of elements in each class.
void sort(vector<double> &data, vector<double> &cntr_values, double witdh, vector<int> &counter)
{
    counter.resize(cntr_values.size(), 0); // Check that the vector is the right size.

    for (int i = 0; i < data.size(); i++) // Go through each element of data to get each point sorted.
    {
        for (int j = 0; j < cntr_values.size(); j++) // For each central value, check if the point is in the class.
        {
            if (abs(data[i] - cntr_values[j]) <= witdh / 2) // If it is, add it to the counter.
            {
                counter[j]++; // Add one to the counter.
                break;        // Break out of the loop.
            }
        }
    }
}

// Show the data in a histogram.
void show(vector<double> &cntr_values, vector<int> &counter)
{
    int max = 0;                             // The maximum value in the counter.
    double q;                                // Establish the quantity of elements "=" per class.
    int q_max = 0;                           // Establish the maximum number of elements in a class.
    for (int i = 0; i < counter.size(); i++) // For each class, check if the number of elements is greater than the maximum.
    {
        if (q_max < counter[i])
            q_max = counter[i]; // If it is, set the maximum to that number.
    }
    q = q_max / 100; // Establish the quantity of elements "=" per class.
    // Add a title to the graph and show the text at the middle of the graph.
    cout << "=====================";
    cout << " Histogramme ";
    cout << "====================="
         << "\n\n";                          // "\n" is equal to endl.
    for (int i = 0; i < counter.size(); i++) // For each class, print the class and the number of elements "=".
    {
        cout << cntr_values[i] << "\t|";
        int n;              // Establish the number of elements "=" in the class.
        n = counter[i] / q; // Establish the number of elements "=" in the class.
        if (n > max)        // If the number of elements "=" is greater than the maximum, set the maximum to that number.
            max = n;
        if ((n == 0) && (counter[i] != 0)) // If the class is empty, add one "=".
            n = 1;
        for (int j = 0; j < n; j++) // Print the number of elements "=" in the class.
        {
            cout << "=";
        }
        cout << endl;
    }
    for (int i = 0; i < max + 9; i++) // Print the number of elements "-" of the arrow.
    {
        cout << "-";
    }
    cout << ">" << endl;
}

int main()
{
    // Create a vector data that will contain data from ./data.dat
    vector<double> data(0);
    // Create a vector cntr_values that will contain the values of the centers of the classes
    vector<double> cntr_values(15);
    // Create a vector repartition that will contain the number of elements in each class
    vector<int> repartition(0);
    // Create a double largeur that will contain the width of the classes
    double largeur = 0.6;
    // Open the file ./data.dat
    ifstream file("./data2.dat");
    if (!file.is_open()) // If the file is not open
    {
        cout << "Error: file not found" << endl; // Print an error message
        return 1;                                // Exit the program
    }
    while (file.good()) // While the file is not empty
    {
        double value;          // Create a double value that will contain the value of the current line
        file >> value;         // Read the value of the current line
        data.push_back(value); // Add the value to the vector data
    }
    // Fill the vector cntr_values with the values of the centers of the classes
    for (int h = 0; h < 15; h++)
    {
        cntr_values[h] = (-45 + 3 + 6 * h) / 10.;
    }
    // Sort the data in the vector data
    sort(data, cntr_values, largeur, repartition);
    // Show the data in a histogram
    show(cntr_values, repartition);
    return 0;
}