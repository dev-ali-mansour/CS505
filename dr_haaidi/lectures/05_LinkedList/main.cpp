#include <iostream>
#include "list.h"

using namespace std;

int main() {
    list cList;
    string s;
    char c;
    int i, count, output1, output2, output3;
    bool keyFound;

    //Read a string
    cout << "Enter a string:" << endl;
    getline(cin, s);
    cout << s << endl;
    for (i = 0; i < s.length(); ++i) {
        c = toupper(s.at(i));
        cList.insertEnd(0, c);
    }

    cout << "LIST CONTENT:" << endl;
    cList.traverse();
    cout << "LIST SIZE: " << cList.listSize() << endl;
    cList.~list();
    cout << "AFTER CALLING DESTRUCTOR: " << cList.listSize() << endl;
    getchar();

    return 0;
}