#ifndef CS505_LIST_H
#define CS505_LIST_H

template<class keyType, class dataType>
class List {
// Node Class
    class Node {
    public:
        keyType key;
        dataType data;
        Node *next;
    };

    typedef Node *NodePointer;

    NodePointer head, cursor, prev;

public:
    List();

    ~List();

    bool listIsEmpty() const;

    bool curIsEmpty() const;

    void toFirst();

    bool atFirst() const;

    void advance();

    void toEnd();

    bool atEnd() const;

    int listSize() const;

    void updateData(const dataType &d);

    void retrieveData(dataType &d) const;

    void insertFirst(const keyType &k, const dataType &d);

    void insertAfter(const keyType &k, const dataType &d);

    void insertBefore(const keyType &k, const dataType &d);

    void insertEnd(const keyType &k, const dataType &d);

    void deleteNode();

    void deleteFirst();

    void deleteEnd();

    void makeListEmpty();

    bool search(const keyType &);

    void orderInsert(const keyType &, const dataType &);

    void traverse();
};

#include "List.tpp"

#endif //CS505_LIST_H