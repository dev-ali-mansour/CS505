#include <iostream>

using namespace std;

void findX(const float x[], int size, float y) {
    for (int i = 0; i < size; ++i)
        if (x[i] == y) {
            cout << y << " is found!!!" << endl;
            break;
        }
}

int main() {
    float x[5] = {10, 20, 30, 40, 50};
    cout << "x = " << x << endl;
    cout << "*x = " << *x << endl;
    cout << "x[0] = " << x[0] << endl;
    cout << "*(x+1) = " << *(x + 1) << endl;

    findX(x, 5, 30);
    *(x + 3) = 100;
    cout << "x[3] = " << x[3] << endl;

    int num = 5;    // integer variable
    int *p;         // pointer of type integer
    p = &num;       // assign the address of num to the pointer

    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    cout << "&p = " << &p << endl;

    double y = 12.5;
    double *p1 = &y;
    *p1 = 17.9;
    cout << "y = " << y << endl;

    int *pnew;
    pnew = new int;
    *pnew = 10;
    cout << "pnew = " << pnew << endl;
    cout << "*pnew = " << *pnew << endl;
    delete pnew;

    return 0;
}