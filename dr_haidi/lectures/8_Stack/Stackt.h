#ifndef CS505_STACKT_H
#define CS505_STACKT_H

template<class Type>
class Stackt {
    Type *stack;                    // Pointer to dynamic array
    int top, maxSize, count = 0;

public:
    Stackt(int nelelments = 128);   // Constructor

    Stackt(const Stackt<Type> &);   // Copy Constructor

    ~Stackt();                      // Destructor

    // Member Functions
    void push(Type);                    // Push

    void pop(Type &);                   // Pop

    void stackTop(Type &) const;        // Retrieve top

    bool stackIsEmpty() const;          // Test for empty stack

    bool stackIsFull() const;           // Test for full stack

    int stackSize() const;

};

#endif //CS505_STACKT_H
