#include "StackL.h"
#include <iostream>

using namespace std;

// Class constructor
template<class Type>
StackL<Type>::StackL() {
    top = NULL;
}

// Class destructor
template<class Type>
StackL<Type>::~StackL() {
    NodePointer cursor;
    while (!stackIsEmpty()) {
        cursor = top;
        top = top->next;
        delete cursor;
    }
}

// return true if stack is empty
template<class Type>
bool StackL<Type>::stackIsEmpty() const {
    return top == NULL;
}

// Push a node with data (v) at the top of the stack.
// The new node become the top node.
template<class Type>
void StackL<Type>::push(Type v) {
    NodePointer pnew = new node;
    pnew->e = v;
    pnew->next = top;
    top = pnew;
}

// Pop top node. Next node become the top node.
template<class Type>
void StackL<Type>::pop(Type &v) {
    if (stackIsEmpty()) cerr << "Stack Underflow" << endl;
    else {
        v = top->e;
        NodePointer cursor = top;
        top = top->next;
        delete cursor;
    }
}

// Retrieve the top node without removing it.
template<class Type>
void StackL<Type>::stackTop(Type &v) const {
    if (stackIsEmpty()) cerr << "Stack Underflow" << endl;
    else v = top->e;
}

