#ifndef CS505_QUEUEL_H
#define CS505_QUEUEL_H

template<class Type>
class QueueL {
    // Node class
    class node {
    public:
        Type e;                             // Queue element
        node *next;                         // Pointer to next node
    }; // End of class node declaration

    typedef node *NodePointer;
    NodePointer front, rear;                // Pointers
    int count;                              // Length
public:
    QueueL();                               // Constructor

    ~QueueL();                              // Destructor

    void enqueue(const Type &);             // Add to rear

    void dequeue(Type &);                    // Remove from front

    void queueFront(Type &) const;          // Retrieve front

    bool queueIsEmpty() const;              // Test for empty queue

    int queueLength() const;                // Queue Length

};


#endif //CS505_QUEUEL_H
