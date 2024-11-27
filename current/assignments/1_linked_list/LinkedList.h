#ifndef CS505_LINKEDLIST_H
#define CS505_LINKEDLIST_H

template<class T>
class LinkedList {
    class Node {
    public:
        T data;
        Node *next;
    };

    typedef Node *NodePointer;
    NodePointer head, cursor, prev;

public:
    LinkedList();

    ~LinkedList();

    void insertAtBegging(const T &data);

    void insertAtEnd(const T &data);

    void deleteNode(const T &data);

    void printList() const;

    bool isEmpty() const;

    int length() const;

private:
    void emptyLinkedList();

    void toFirst();

    void toEnd();
};

#endif //CS505_LINKEDLIST_H
