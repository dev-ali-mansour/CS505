#include <iostream>
#include "list.h"


list::list() {
    head = prev = cursor = NULL;
}

bool list::listIsEmpty() const {
    /*if (head == NULL) return true;
    else return false;*/
    return head == NULL;
}

bool list::cursorIsEmpty() const {
    return cursor == NULL;
}

void list::toFirst() {
    cursor = head;
    prev = NULL;
}

bool list::atFirst() const {
    return cursor == head;
}

void list::advance() {
    prev = cursor;
    cursor = cursor->next;
}

void list::toEnd() {
    if (!listIsEmpty()) {
        if (cursorIsEmpty()) toFirst();
        while (cursor->next != NULL)
            advance();
    }
}

bool list::atEnd() const {
    if (listIsEmpty())return true;
    else if (cursorIsEmpty())return false;
    else return cursor->next == NULL;
}

int list::listSize() const {
    node *q = head;
    int counter = 0;
    while (q != NULL) {
        counter++;
        q = q->next;
    }
    return counter;
}

void list::updateData(const char &d) {
    cursor->data = d;
}

void list::retrieveData(char &d) const {
    d = cursor->data;
}

void list::insertFirst(const int &k, const char &d) {
    toFirst();
    node *pnew = new node;
    pnew->key = k;
    pnew->data = d;
    pnew->next = head;
    head = pnew;
    cursor = head;
    prev = NULL;
}



