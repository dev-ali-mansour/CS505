#include "simpleString.h"
#include <iostream>

using namespace std;

int main() {
    simpleString s1;
    simpleString s2(20);

    cout << s1.getCapacity() << " " << s1.getLength() << endl;
    cout << s2.getCapacity() << " " << s2.getLength() << endl;

    // Read in a string.
    cout << "Enter a string and press RETURN: ";
    s1.readString();

    // Display the string just read.
    s1.writeString();
    cout << endl;

    // Display each character on a separate line.
    cout << "The characters in the string flow:" << endl;
    for (int pos = 0; pos < s1.getLength(); ++pos)
        cout << s1.at(pos) << endl;

    return 0;
}