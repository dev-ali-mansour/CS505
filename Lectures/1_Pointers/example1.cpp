#include <iostream>
#include <string>

using namespace std;

int main() {
    int *p;
    int x = 37;
    cout << "x = " << x << endl;
    p = &x;
    cout << "*p= " << *p << " , x=" << x << endl;
    *p = 85;
    cout << "*p= " << *p << " , x=" << x << endl;
    cout << "Address of p is: " << &p << endl;
    cout << "Value of p: " << p << endl;
    cout << "Value of memory location pointed to by *p = " << *p << endl;
    cout << "Address of x = " << &x << endl;
    cout << "Value of x = " << x << endl;

    return 0;
}
