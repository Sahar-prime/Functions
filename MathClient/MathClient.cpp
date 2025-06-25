#include <iostream>
#include "Math_Lib.h"
using namespace std;

int main()
{
    double a = 7.4;
    int b = 99;

    cout << "a + b = " <<
        MathLibrary::Arithmetic::Add(a, b) << endl;
    cout << "a - b = " <<
        MathLibrary::Arithmetic::Subtract(a, b) << endl;
    cout << "a * b = " <<
        MathLibrary::Arithmetic::Multiply(a, b) << endl;
    cout << "a / b = " <<
        MathLibrary::Arithmetic::Divide(a, b) << endl;
}