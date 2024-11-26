#ifndef CS505_LIST_H
#define CS505_LIST_H


class list {
    //data members
    class node {
    public:
        int key;
        char data;
        node *next;
    };

    typedef node *NodePointer;

    //pointers
    NodePointer head, prev, cursor;

    //operations/functions
public:
    list();

    ~list();

    bool listIsEmpty() const;

    bool cursorIsEmpty() const;

    void toFirst();

    bool atFirst() const;

    void advance();

    void toEnd();

    bool atEnd() const;

    int listSize() const;

    void updateData(const char &d);

    void retrieveData(char &d) const;

    void retrieveKey(int &k) const;

    void insertFirst(const int &k, const char &d);

    void insertAfter(const int &k, const char &d);

    void insertBefore(const int &k, const char &d);

    void insertEnd(const int &k, const char &d);

    void deleteNode();

    void deleteFirst();

    void deleteEnd();

    void makeListEmpty();

    bool search(const int &k);

    void orderInsert(const int &k, const char &d);

    void traverse();
};


#endif //CS505_LIST_H