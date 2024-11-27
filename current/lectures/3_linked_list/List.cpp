#include <iostream>
#include "List.h"

using namespace std;

template<class keyType, class dataType>
List<keyType, dataType>::List() {
    head = NULL;
    cursor = NULL;
    prev = NULL;
}

template<class keyType, class dataType>
List<keyType, dataType>::~List() {
    makeListEmpty();
}

template<class keyType, class dataType>
bool List<keyType, dataType>::listIsEmpty() const {
    return (head == NULL);
}

template<class keyType, class dataType>
bool List<keyType, dataType>::curIsEmpty() const {
    return (cursor == NULL);
}

template<class keyType, class dataType>
void List<keyType, dataType>::toFirst() {
    cursor = head;
    prev = NULL;
}

template<class keyType, class dataType>
bool List<keyType, dataType>::atFirst() const {
    return cursor == head;
}

template<class keyType, class dataType>
void List<keyType, dataType>::advance() {
    prev = cursor;
    cursor = cursor->next;
}

template<class keyType, class dataType>
void List<keyType, dataType>::toEnd() {
    if (!listIsEmpty())
        while (cursor != NULL && cursor->next != NULL)
            advance();
}

template<class keyType, class dataType>
bool List<keyType, dataType>::atEnd() const {
    return cursor == NULL || cursor->next == NULL;
}

template<class keyType, class dataType>
int List<keyType, dataType>::listSize() const {
    NodePointer temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

template<class keyType, class dataType>
void List<keyType, dataType>::updateData(const dataType &d) {
    if (!curIsEmpty())
        cursor->data = d;
}

template<class keyType, class dataType>
void List<keyType, dataType>::retrieveData(dataType &d) const {
    if (!curIsEmpty())
        d = cursor->data;
}

template<class keyType, class dataType>
void List<keyType, dataType>::insertFirst(const keyType &k, const dataType &d) {
    NodePointer newNode = new Node;
    newNode->key = k;
    newNode->data = d;
    newNode->next = head;
    head = newNode;
    cursor = head;
    prev = NULL;
}

template<class keyType, class dataType>
void List<keyType, dataType>::insertAfter(const keyType &k, const dataType &d) {
    NodePointer newNode = new Node;
    newNode->key = k;
    newNode->data = d;
    newNode->next = cursor->next;
    cursor->next = newNode;
    advance();
}

template<class keyType, class dataType>
void List<keyType, dataType>::insertBefore(const keyType &k, const dataType &d) {
    if (listIsEmpty())return;
    if (atFirst())
        insertFirst(k, d);
    else {
        NodePointer newNode = new Node;
        newNode->key = k;
        newNode->data = d;
        newNode->next = cursor;
        prev->next = newNode;
    }
}

template<class keyType, class dataType>
void List<keyType, dataType>::insertEnd(const keyType &k, const dataType &d) {
    if (listIsEmpty())
        insertFirst(k, d);
    else {
        toEnd();
        insertAfter(k, d);
    }
}

template<class keyType, class dataType>
void List<keyType, dataType>::deleteNode() {
    if (curIsEmpty()) return;
    if (atFirst())
        deleteFirst();
    else {
        prev->next = cursor->next;
        delete cursor;
        cursor = prev->next;
    }
}

template<class keyType, class dataType>
void List<keyType, dataType>::deleteFirst() {
    if (listIsEmpty())return;
    NodePointer temp = head;
    head = head->next;
    if (cursor == temp)
        cursor = head;
    delete temp;
}

template<class keyType, class dataType>
void List<keyType, dataType>::deleteEnd() {
    if (listIsEmpty())return;
    if (head->next == NULL)
        deleteFirst();
    else {
        toEnd();
        deleteNode();
    }
}

template<class keyType, class dataType>
void List<keyType, dataType>::makeListEmpty() {
    while (!listIsEmpty())
        deleteFirst();
}


template<class keyType, class dataType>
bool List<keyType, dataType>::search(const keyType &k) {
    toFirst();
    while (cursor != NULL) {
        if (cursor->key == k)
            return true;
        advance();
    }
    return false;
}

template<class keyType, class dataType>
void List<keyType, dataType>::orderInsert(const keyType &k, const dataType &d) {
    if (listIsEmpty() || k <= head->key)
        insertFirst(k, d);
    else {
        toFirst();
        while (cursor->next != NULL && cursor->next->key < k) {
            advance();
        }
        insertAfter(k, d);
    }
}

template<class keyType, class dataType>
void List<keyType, dataType>::traverse() {
    NodePointer temp = head;
    while (temp != NULL) {
        cout << "Key: " << temp->key << ", Data: " << temp->data << endl;
        temp = temp->next;
    }
}