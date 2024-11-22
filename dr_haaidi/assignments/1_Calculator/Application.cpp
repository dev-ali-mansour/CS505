#include "calculator.h"
#include <iostream>

using namespace std;

int main() {
    calculator c(4, 5);

    cout << "The addition result = " << c.add() << endl;
    cout << "The subtraction result = " << c.subtract() << endl;
    cout << "The addition overloaded + operator result = " << c.operator+() << endl;

    return 0;
}