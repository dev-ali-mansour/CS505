#include "simpleString.h"
#include <iostream>

using namespace std;

simpleString::simpleString() {
    capacity = 255;
    s = new char[capacity];
    length = 0;
}

simpleString::simpleString(int mVal) {
    capacity = mVal;
    s = new char[capacity];
    length = 0;
}

simpleString::~simpleString() {
    delete[] s;
}

// Read a simple string
void simpleString::readString() {
    char next;
    int pos = 0;
    cin.get(next);
    while (next != '\n' && pos < capacity) {
        s[pos] = next;
        pos++;
        cin.get( next);
    }
    length = pos;
}

// Write a simple string
void simpleString::writeString() const {
    for (int pos = 0; pos < length; pos++)
        cout << s[pos];
}

// Retrieve the character at a specified position
// Returns the character \0 if position is out
// of bounds
char simpleString::at(int pos) const {
    char nullCharacter = '\0';
    if (pos < 0 || pos > length) {
        cerr << "position " << pos << " not defined" << endl;
        return nullCharacter;
    }
    return s[pos];
}

// Return the string length
int simpleString::getLength() const {
    return length;
}

// Return the string capacity
int simpleString::getCapacity() const {
    return capacity;
}

void simpleString::getContents(char str[]) const {
    for (int i = 0; i < length; ++i)
        str[i] = s[i];
}