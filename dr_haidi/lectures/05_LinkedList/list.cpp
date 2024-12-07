#include <iostream>
#include "list.h"

using namespace std;

// Class Constructor
template<class keyType, class dataType>
list<keyType, dataType>::list() {
    head = prev = cursor = NULL;
}

// Class Destructor
template<class keyType, class dataType>
list<keyType, dataType>::~list() {
    makeListEmpty();
}

// return True if list is empty
template<class keyType, class dataType>
bool list<keyType, dataType>::listIsEmpty() const {
    /*if (head == NULL) return true;
    else return false;*/
    return head == NULL;
}

// return True if current position is empty
template<class keyType, class dataType>
bool list<keyType, dataType>::cursorIsEmpty() const {
    return cursor == NULL;
}

// to make the current node the first node; if list is empty,
// the current position is still empty
template<class keyType, class dataType>
void list<keyType, dataType>::toFirst() {
    cursor = head;
    prev = NULL;
}

// to return True if the current node is the first node or
// if the list and the current position are both empty.
template<class keyType, class dataType>
bool list<keyType, dataType>::atFirst() const {
    return cursor == head;
}

// to advance to next node. Assume the current position
// is nonempty initially.
template<class keyType, class dataType>
void list<keyType, dataType>::advance() {
    prev = cursor;
    cursor = cursor->next;
}

// to make the current node the tail node;
// if list is empty, the current position is still empty
template<class keyType, class dataType>
void list<keyType, dataType>::toEnd() {
    if (!listIsEmpty()) {
        if (cursorIsEmpty()) toFirst();
        while (cursor->next != NULL)
            advance();
    }
}

// to return True if the current node is the tail node or
// if the list and the current position are both empty.
template<class keyType, class dataType>
bool list<keyType, dataType>::atEnd() const {
    if (listIsEmpty())return true;
    else if (cursorIsEmpty())return false;
    else return cursor->next == NULL;
}

// to return the size of the list
template<class keyType, class dataType>
int list<keyType, dataType>::listSize() const {
    node *q = head;
    int counter = 0;
    while (q != NULL) {
        counter++;
        q = q->next;
    }
    return counter;
}

// to update the data portion of the current node to contain el;
// assume the current position is nonempty.
template<class keyType, class dataType>
void list<keyType, dataType>::updateData(const dataType &d) {
    cursor->data = d;
}

// to return the data in the current node;
// assume the current position is nonempty.
template<class keyType, class dataType>
void list<keyType, dataType>::retrieveData(dataType &d) const {
    d = cursor->data;
}

template<class keyType, class dataType>
void list<keyType, dataType>::retrieveKey(keyType &k) const {
    k = cursor->key; //return cursor->data
}

// insert a node with data (el) at the head of the list;
// the new node becomes the current node.
template<class keyType, class dataType>
void list<keyType, dataType>::insertFirst(const keyType &k, const dataType &d) {
    toFirst();
    NodePointer pNew = new node; //node *pNew = new node;
    pNew->key = k;
    pNew->data = d;
    pNew->next = head;
    head = pNew;
    cursor = head;
    prev = NULL;
}


// insert a node with data (el) after the current node
// without changing the current position;
// assume the current position is nonempty in a non-empty list.
template<class keyType, class dataType>
void list<keyType, dataType>::insertAfter(const keyType &k, const dataType &d) {
    NodePointer pNew = new node;
    pNew->key = k;
    pNew->data = d;
    pNew->next = cursor->next;
    cursor->next = pNew;
}

// insert a node with data (el) before the current node,
// current position becomes the new node.
template<class keyType, class dataType>
void list<keyType, dataType>::insertBefore(const keyType &k, const dataType &d) {
    if (atFirst()) insertFirst(k, d); // Fix issue of inserting before the first node
    else {
        NodePointer pNew = new node;
        pNew->key = k;
        pNew->data = d;
        pNew->next = cursor;
        prev->next = pNew;
        cursor = pNew;
    }
}

// insert a node with data (el) at the end of the list,
// current position becomes the new node.
template<class keyType, class dataType>
void list<keyType, dataType>::insertEnd(const keyType &k, const dataType &d) {
    if (listIsEmpty())insertFirst(k, d);
    else {
        toEnd();
        insertAfter(k, d);
    }
}

// delete the current node and set the current position to the next node;
// if the current node is the last node initially, the current position becomes empty;
// assume the current position is nonempty initially.
template<class keyType, class dataType>
void list<keyType, dataType>::deleteNode() {
    NodePointer q;
    if (!cursorIsEmpty()) { // current node is not empty
        if (atFirst()) { // delete the head node
            q = cursor;
            cursor = cursor->next;
            head = cursor;
            prev = NULL;
            delete q;
            /* We can also use:
               q = head;
               head = head->next;
               cursor = head;
               prev = NULL;
               delete q;
             */

        } else { // delete a non-head node
            q = cursor;
            cursor = cursor->next;
            prev->next = cursor;
            delete q;
        }
    }
}

// delete the first node and set the current position to the next node;
// if it was initially the only node, the current position becomes empty;
// assume the current position is nonempty initially.
template<class keyType, class dataType>
void list<keyType, dataType>::deleteFirst() {
    if (!listIsEmpty()) {
        toFirst();
        deleteNode();
    }
}

// delete the last node and set the current position to empty;
// assume the current position is nonempty initially.
template<class keyType, class dataType>
void list<keyType, dataType>::deleteEnd() {
    if (!listIsEmpty()) {
        toEnd();
        deleteNode();
    }
}

// delete whole list
template<class keyType, class dataType>
void list<keyType, dataType>::makeListEmpty() {
    toFirst();
    while (!listIsEmpty()) {
        deleteNode();
    }
}

// search the list for the node with key part that matches (k).
// If found, set cursor to the node and return True,
// else return false and the current position becomes empty.
template<class keyType, class dataType>
bool list<keyType, dataType>::search(const keyType &k) {
    bool found = false;
    toFirst();
    while (!found && !cursorIsEmpty()) {
        if (cursor->key == k)found = true;
        else advance();
    }
    return found;
}

// insert a node in a position that maintains an ascending
// order of the key portion of the nodes.
template<class keyType, class dataType>
void list<keyType, dataType>::orderInsert(const keyType &k, const dataType &d) {
    toFirst();
    while (!cursorIsEmpty() && k > cursor->key)
        advance();
    if (prev == NULL) insertFirst(k, d);
    else insertBefore(k, d);
}

// traverse list to print key and data fields
template<class keyType, class dataType>
void list<keyType, dataType>::traverse() {
    toFirst();
    while (!cursorIsEmpty()) {
        cout << cursor->data << endl;
        advance();
    }
}

template<class keyType, class dataType>
int list<keyType, dataType>::Recursive_List_Size() {
    return list_size2(head);
}

template<class keyType, class dataType>
int list<keyType, dataType>::list_size2(NodePointer h) {
    if (h == NULL) return 0;
    else return 1 + list_size2(h->next);
}

template<class keyType, class dataType>
int list<keyType, dataType>::DisplayList() {
    return Display(head);
}

template<class keyType, class dataType>
int list<keyType, dataType>::Display(NodePointer h) {
    if (h == NULL) return 0;
    cout << h->key << " " << h->data << endl;
    return Display(h->next);
}

