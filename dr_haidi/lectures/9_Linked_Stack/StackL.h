#ifndef CS505_STACKL_H
#define CS505_STACKL_H

#include <iostream>

using namespace std;

template<class Type>
class StackL {
    class node {                // Hidden from user
    public:
        Type e;                 // stack element
        node *next;             // pointer to the next node
    };

    typedef node *NodePointer;
    NodePointer top;                // Pointer to top

public:
    StackL();                       // Constructor

    StackL(const StackL<Type> &);   // Copy Constructor

    ~StackL();                      // Destructor

    // Member Functions
    void push(Type);                // Push

    void pop(Type &);               // Pop

    void stackTop(Type &) const;    // Retrieve top

    bool stackIsEmpty() const;      // Test for empty stack

    int stackSize() const;

};

#endif //CS505_STACKL_H
