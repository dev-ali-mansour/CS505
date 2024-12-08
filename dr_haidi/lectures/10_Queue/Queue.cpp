#include "Queue.h"
#include <iostream>

using namespace std;

// Constructor with argument, size is nelements, default is 128
template<class Type>
Queue<Type>::Queue(int nelements) {
    maxSize = nelements;
    queue = new Type[maxSize];
    front = count = 0;
    rear = -1;
}

// Copy constructor
template<class Type>
Queue<Type>::Queue(const Queue &original)
        :maxSize(original.maxSize), front(original.front), rear(original.rear), count(original.count) {
    queue = new Type[maxSize];
    for (int i = 0; i < maxSize; ++i)
        queue[i] = original.queue[i];
}

// Destructor
template<class Type>
Queue<Type>::~Queue() {
    delete[]queue;
}

// Add to rear
template<class Type>
void Queue<Type>::enqueue(const Type &v) {
    if (queueIsFull()) cerr << "Queue is full" << endl;
    else {
        rear = (rear + 1) % maxSize;
        queue[rear] = v;
        count++;
    }
}

// Remove from front
template<class Type>
void Queue<Type>::dequeue(Type &v) {
    if (queueIsEmpty())cerr << "Queue is empty" << endl;
    else {
        v = queue[front];
        front = (front + 1) % maxSize;
        count--;
    }
}

// Retrieve front without removing it
template<class Type>
void Queue<Type>::queueFront(Type &v) const {
    if (queueIsEmpty())cerr << "Queue is empty" << endl;
    else v = queue[front];
}

// Test for Empty queue
template<class Type>
bool Queue<Type>::queueIsEmpty() const {
    return count == 0;
}

// Test for Full queue
template<class Type>
bool Queue<Type>::queueIsFull() const {
    return count == maxSize;
}

// Queue Length
template<class Type>
int Queue<Type>::queueLength() const {
    return count;
}

