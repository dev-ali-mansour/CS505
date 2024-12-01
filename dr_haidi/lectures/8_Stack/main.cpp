#include <iostream>
#include "Stackt.cpp"

using namespace std;

int main() {
    Stackt<int> w, z;
    int x;
    w.push(2);
    w.push(3);
    w.push(4);
    Stackt<int> o(w);
    o.stackTop(x);
    cout << x << endl;
    while (!o.stackIsEmpty()) {
        o.pop(x);
        cout << x << endl;
    }

    Stackt<char> s1, s2;
    char c;
    string inString = "Testing Stack Class";
    string outString = "";
    cout << inString << endl;
    int L = inString.length();
    cout << "Pushing characters on s1\n";
    for (int i = 0; i < L; ++i)
        s1.push(inString.at(i));
    cout << "Copying s1 to s2\n";
    cout << "Popping characters from s1\n";
    while (!s1.stackIsEmpty()) {
        s1.pop(c);
        s2.push(c);
        outString += c;
    }
    cout << outString << endl;
    cout << "s1 is now empty. Trying to to pop from empty s1\n";
    s1.pop(c);
    cout << "Now popping contents of s2\n";
    while (!s2.stackIsEmpty()) {
        s2.pop(c);
        cout << c;
    }
    cout << endl;
    system("pause");

    return 0;
}