#include <iostream>
#include "Math_Lib.h"
using namespace std;

int main()
{
    double a = 5;
    int b = 5;

    cout << "a + b = " <<
        MathLibrary::Arithmetic::Add(a, b) << endl;
    cout << "a - b = " <<
        MathLibrary::Arithmetic::Subtract(a, b) << endl;
    cout << "a * b = " <<
        MathLibrary::Arithmetic::Multiply(a, b) << endl;
    cout << "a : b = " <<
        MathLibrary::Arithmetic::Divide(a, b) << endl;
}