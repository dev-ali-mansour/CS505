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

    node *head, *prev, *cursor;

    //operations/functions
public:
    list();

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

    void insertFirst(const int &k, const char &d);

};


#endif //CS505_LIST_H