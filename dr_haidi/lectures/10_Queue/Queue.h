

#ifndef CS505_QUEUE_H
#define CS505_QUEUE_H

template<class Type>
class Queue {
    // Data Members
    Type *queue;                           // Pointer to dynamic array
    int front, rear, count, maxSize;

public:
    Queue(int nelements = 128);         // Constructor

    Queue(const Queue &);               // Copy Constructor

    ~Queue();                           // Destructor

    // Member Functions
    void enqueue(const Type &);            //Add to rear

    void dequeue(Type &);                  // Remove from front

    void queueFront(Type &) const;         // Retrieve front

    bool queueIsEmpty() const;          // Test for empty queue

    bool queueIsFull() const;           // Test for full queue

    int queueLength() const;            // Queue Length
};


#endif //CS505_QUEUE_H
