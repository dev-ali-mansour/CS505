#ifndef CS505_LIST_H
#define CS505_LIST_H

#include <iostream>

using namespace std;

// Specification of the class
class student {
public:
    string st_name;
    int st_no;
    float st_grade;
};

class list {
    //data members
    class node {
    public:
        int key;
        student data;
        node *next;
    };

    typedef node *NodePointer;

    //pointers
    NodePointer head, prev, cursor;

    //exercises
    int list_size2(NodePointer h);

    int Display(NodePointer h);

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

    void updateData(const student &d);

    void retrieveData(student &d) const;

    void retrieveKey(int &k) const;

    void insertFirst(const int &k, const student &d);

    void insertAfter(const int &k, const student &d);

    void insertBefore(const int &k, const student &d);

    void insertEnd(const int &k, const student &d);

    void deleteNode();

    void deleteFirst();

    void deleteEnd();

    void makeListEmpty();

    bool search(const int &k);

    void orderInsert(const int &k, const student &d);

    void traverse();

    float getGradesAverage();
};


#endif //CS505_LIST_H