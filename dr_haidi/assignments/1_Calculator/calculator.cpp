#include "calculator.h"

calculator::calculator() {
    num1 = num2 = 0;
}

calculator::calculator(int x, int y) {
    num1 = x;
    num2 = y;
}

void calculator::setNum1(int x) {
    num1 = x;
}

void calculator::setNum2(int x) {
    num2 = x;
}

void calculator::setData(int x, int y) {
    num1 = x;
    num2 = y;
}

int calculator::getNum1() const {
    return num1;
}

int calculator::getNum2() const {
    return num2;
}

void calculator::getData(int &x, int &y) const {
    x = num1;
    y = num2;
}

int calculator::add() const {
    return num1 + num2;
}

int calculator::subtract() const {
    return num1 - num2;
}

int calculator::multiply() const {
    return num1 * num2;
}

int calculator::divide() const {
    return num1 / num2;
}

int calculator::operator+() const {
    return num1 + num2;
}

int calculator::operator-() const {
    return num1 - num2;
}
