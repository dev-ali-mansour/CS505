#include <iostream>

using namespace std;

void f(int *j);

int main() {
    int i = 0;
    int *p;
    p = &i; // p now points to i
    cout << "*p is " << *p << endl
         << "i = " << i << endl;
    f(p);
    cout << "i is " << i << endl;
    return 0;
}

void f(int *j) {
    *j = 100;   // var pointed to by j is assigned 100
    cout << "*j is : " << *j << endl;
}