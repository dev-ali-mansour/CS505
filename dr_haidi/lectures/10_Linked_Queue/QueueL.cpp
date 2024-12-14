#include "QueueL.h"
#include <iostream>

using namespace std;

// Class constructor
template<class Type>
QueueL<Type>::QueueL() {
    front = rear = NULL;
    count = 0;
}

// Class Destructor
template<class Type>
QueueL<Type>::~QueueL() {
    NodePointer cursor;
    while (front != NULL) {
        cursor = front;
        front = front->next;
        delete cursor;
    }
}

// Add a node with data (v) at the rear of the queue.
// The new node becomes the rear node.
template<class Type>
void QueueL<Type>::enqueue(const Type &v) {
    NodePointer pnew = new node;
    pnew->e = v;
    pnew->next = NULL;
    if (queueIsEmpty())front = pnew;
    else rear->next = pnew;
    rear = pnew;
    count++;
}

// Dequeue front node. Next Node becomes front node
template<class Type>
void QueueL<Type>::dequeue(Type &v) {
    if (queueIsEmpty())cerr << "Queue is empty" << endl;
    else {
        v = front->e;
        NodePointer cursor = front;
        front = front->next;
        delete cursor;
        count--;
    }
}

// Retrieve front node without removing it
template<class Type>
void QueueL<Type>::queueFront(Type &v) const {
    if (queueIsEmpty())cerr << "Queue is empty" << endl;
    else v = front->e;
}

// Return true if queue is empty
template<class Type>
bool QueueL<Type>::queueIsEmpty() const {
    return count == 0;
}

// Queue Length
template<class Type>
int QueueL<Type>::queueLength() const {
    return count;
}