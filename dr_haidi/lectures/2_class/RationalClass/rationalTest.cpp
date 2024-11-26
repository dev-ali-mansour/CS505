#include "rational.h"
#include <iostream>

using namespace std;

int main() {
    rational f1, f2, f3;

    cout << "Enter 1st fraction: ";
    f1.readRational();
    cout << "Enter 2nd fraction: ";
    f2.readRational();

    f3 = f1.multiply(f2);
    f1.displayRational();
    cout << " * ";
    f2.displayRational();
    cout << " = ";
    f3.displayRational();
    cout << " = ";
    f3 = f3.reduce();
    f3.displayRational();
    cout << endl;

    f3 = f1.divide(f2);
    f1.displayRational();
    cout << " / ";
    f2.displayRational();
    cout << " = ";
    f3.displayRational();
    cout << " = ";
    f3 = f3.reduce();
    f3.displayRational();
    cout << endl;

    f3 = f1.add(f2);
    f1.displayRational();
    cout << " + ";
    f2.displayRational();
    cout << " = ";
    f3.displayRational();
    cout << " = ";
    f3 = f3.reduce();
    f3.displayRational();
    cout << endl;

    f3 = f1 + f2;
    f1.displayRational();
    cout << " + ";
    f2.displayRational();
    cout << " = ";
    f3.displayRational();
    cout << " = ";
    f3 = f3.reduce();
    f3.displayRational();
    cout << endl;


    f3 = f1.subtract(f2);
    f1.displayRational();
    cout << " - ";
    f2.displayRational();
    cout << " = ";
    f3.displayRational();
    cout << " = ";
    f3 = f3.reduce();
    f3.displayRational();
    cout << endl;

    f3 = f1 - f2;
    f1.displayRational();
    cout << " - ";
    f2.displayRational();
    cout << " = ";
    f3.displayRational();
    cout << " = ";
    f3 = f3.reduce();
    f3.displayRational();
    cout << endl;

    (f1 == f2) ? cout << "1st = 2nd" : cout << "1st != 2nd" << endl;
    f2 = f1;
    (f1 == f2) ? cout << "1st = 2nd" : cout << "1st != 2nd" << endl;

    return 0;
}