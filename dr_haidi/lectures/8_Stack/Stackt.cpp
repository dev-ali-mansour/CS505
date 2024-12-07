#include "Stackt.h"
#include <iostream>

using namespace std;

template<class Type>
Stackt<Type>::Stackt(int nelelments) {
    maxSize = nelelments;
    stack = new Type[maxSize];
    top = -1;
}

// Copy constructor
template<class Type>
Stackt<Type>::Stackt(const Stackt<Type> &original)
        :maxSize(original.maxSize), top(original.top) {
    stack = new Type[maxSize];
    for (int i = 0; i <= top; ++i)
        stack[i] = original.stack[i];
}

// Destructor
template<class Type>
Stackt<Type>::~Stackt() {
    delete[] stack;
}

// Push
template<class Type>
void Stackt<Type>::push(Type v) {
    if (stackIsFull()) cout << "Stack Overflow" << endl;
    else {
        stack[++top] = v;
        count++;
    }
}

// Pop
template<class Type>
void Stackt<Type>::pop(Type &v) {
    if (stackIsEmpty())cout << "Stack Underflow" << endl;
    else {
        v = stack[top--];
        count--;
    }
}

// Retrieve stack top without removing it
template<class Type>
void Stackt<Type>::stackTop(Type &v) const {
    if (stackIsEmpty())cout << "Stack underflow" << endl;
    else v = stack[top];
}

// Test for empty stack
template<class Type>
bool Stackt<Type>::stackIsEmpty() const {
    return top < 0;
}

// Test for full stack
template<class Type>
bool Stackt<Type>::stackIsFull() const {
    return top >= (maxSize - 1);
}

template<class Type>
int Stackt<Type>::stackSize() const {
    return count;
}