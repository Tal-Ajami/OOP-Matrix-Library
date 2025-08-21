#include <iostream>
#include "MyMatrix.h"

using namespace std;

int main() {
    try {
        cout << "Creating and filling matrices A, B, C, and Z:\n";
        MyMatrix A(2, 2), B(2, 2), C(2, 2), Z(2, 2);
        cout << "Fill Matrix A:\n";
        cin >> A;
        cout << "Fill Matrix B:\n";
        cin >> B;
        cout << "Fill Matrix C:\n";
        cin >> C;
        cout << "Fill Matrix Z:\n";
        cin >> Z;

        cout << "\nMatrix A:\n";
        cout << A;
        cout << "\nMatrix B:\n";
        cout << B;
        cout << "\nMatrix C:\n";
        cout << C;
        cout << "\nMatrix Z:\n";
        cout << Z;

        //Demonstrating mathematical operations with more than two matrices
        cout << "\nDemonstrating D = A + B + C + Z:\n";
        MyMatrix D = A + B + C + Z;
        cout << "Result of D = A + B + C + Z:\n";
        cout << D;

        //Demonstrating associativity: D = A + B - C
        cout << "\nDemonstrating associativity of operations:\n";
        MyMatrix D1 = A + B - C;        
        MyMatrix D2 = (A + B) - C;      
        MyMatrix D3 = A + (B - C);     

        cout << "Result of D1 = A + B - C:\n";
        cout << D1;

        cout << "Result of D2 = (A + B) - C:\n";
        cout << D2;

        cout << "Result of D3 = A + (B - C):\n";
        cout << D3;


        //Demonstrating operator[] to access a specific row and col
        cout << "\nAccessing specific value using operator A[0][1] = 2:\n";
        cout << A[0][1];
        cout << endl;

        //Demonstrating scalar multiplication
        cout << "\nMultiplying Matrix A by a scalar (Matrix A * 3):\n";
        MyMatrix ScalarResult = A * 3;
        cout << "Result of Matrix A * 3:\n";
        cout << ScalarResult;


        //Demonstrating type conversion to double
        cout << "\nConverting Matrix A to double (sum of all elements):\n";
        double sum = (double)(A);
        cout << "Sum of elements in Matrix A: " << sum << endl;

        // This should throw an exception
        cout << "\nCreating a matrix with invalid dimensions (-1x2):\n";
        MyMatrix invalidMatrix(-1, 2); 

    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
