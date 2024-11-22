#include "rational.h"
#include <iostream>

using namespace std;

rational::rational() {
    num = 0;
    denom = 1;
}

rational::rational(int n) {
    num = n;
    denom = 1;
}

rational::rational(int n, int d) {
    num = n;
    denom = d;
}

void rational::setNum(int n) {
    num = n;
}

void rational::setDenom(int d) {
    denom = d;
}

int rational::getNum() const {
    return num;
}

int rational::getDenom() const {
    return denom;
}

rational rational::operator+(const rational &f) const {
    rational temp(num * f.denom + f.num * denom,
                  denom * f.denom);
    return temp;
}

rational rational::operator-(const rational &f) const {
    rational temp(num * f.denom - f.num * denom,
                  denom * f.denom);
    return temp;
}

bool rational::operator==(const rational &f) const {
    return (num == f.num && denom == f.denom);
}

rational rational::multiply(const rational &f) const {
    rational temp(num * f.num, denom * f.denom);
    return temp;
}

rational rational::divide(const rational &f) const {
    rational temp(num * f.denom, denom * f.num);
    return temp;
}

rational rational::add(const rational &f) const {
    rational temp(num * f.denom + f.num * denom,
                  denom * f.denom);
    return temp;
}

rational rational::subtract(const rational &f) const {
    rational temp(num * f.denom - f.num * denom,
                  denom * f.denom);
    return temp;
}

void rational::readRational() {
    char slash;
    do {
        cout << "Enter numerator / denominator: ";
        cin >> num >> slash >> denom;
    } while (slash != '/');
}

void rational::displayRational() const {
    cout << num << '/' << denom;
}

rational rational::reduce() const {
    int n, m, rem, gcd;
    // Get the two integers
    n = abs(num);
    m = abs(denom);
    while (n > 0) {
        rem = m % n;
        m = n;
        n = rem;
    }
    gcd = m;
    rational g(num / gcd, denom / gcd);
    return g;
}