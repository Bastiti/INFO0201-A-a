#include <iostream>
#include <fstream>
using namespace std;
int matrix[3][3] = {0};
int cof[3];
ifstream matrixtab("./matrix.txt");
int det,x,y,z,sign;
int main()
{
    if (matrixtab.is_open())
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                matrixtab >> matrix[i][j];
                cout << matrix[i][j] << "\t";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "File cannot be opened.";
    }
    cout << "\n";
    cof[0] = ((matrix[1][1] * matrix[2][2]) - (matrix[2][1] * matrix[1][2]));
    cof[1] = ((matrix[1][0] * matrix[2][2]) - (matrix[2][0] * matrix[1][2]));
    cof[2] = ((matrix[1][0] * matrix[2][1]) - (matrix[2][0] * matrix[1][1]));
    sign = 1;
    for (int i = 0;i<3;i++){
        det += sign*matrix[0][i]*cof[i];
        sign = -sign;
    }
    cout << "Determinent is: " <<   det;
}
