#include "LinkedList.h"
#include <iostream>

using namespace std;

template<class T>
LinkedList<T>::LinkedList() {
    head = NULL;
    cursor = NULL;
    prev = NULL;
}

template<class T>
LinkedList<T>::~LinkedList() {
    emptyLinkedList();
}

template<class T>
void LinkedList<T>::insertAtBegging(const T &data) {
    NodePointer pNew = new Node;
    pNew->data = data;
    pNew->next = head;
    head = pNew;
    cursor = head;
    prev = NULL;
}

template<class T>
void LinkedList<T>::insertAtEnd(const T &data) {
    NodePointer pNew = new Node;
    pNew->data = data;
    pNew->next = NULL;
    if (isEmpty())
        head = pNew;
    else {
        NodePointer temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = pNew;
    }
}

template<class T>
void LinkedList<T>::deleteNode(const T &data) {
    if (isEmpty()) return;
    toFirst();
    while (cursor != NULL) {
        if (cursor->data == data) {
            if (cursor == head)
                head = head->next;
            else
                prev->next = cursor->next;

            delete cursor;
            cursor = NULL;
            cout << "Node with data " << data << " has been deleted!\n";
            return;
        }
        prev = cursor;
        cursor = cursor->next;
    }

}

template<class T>
void LinkedList<T>::printList() const {
    if (!isEmpty()) {
        cout << "NULL -> ";
        NodePointer temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    }
    cout << "NULL\n";
}

template<class T>
bool LinkedList<T>::isEmpty() const {
    return (head == NULL);
}

template<class T>
int LinkedList<T>::length() const {
    int counter = 0;
    NodePointer temp = head;
    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

template<class T>
void LinkedList<T>::emptyLinkedList() {
    while (head != NULL) {
        NodePointer temp = head;
        head = head->next;
        delete temp;
    }
}

template<class T>
void LinkedList<T>::toFirst() {
    prev = NULL;
    cursor = head;
}

template<class T>
void LinkedList<T>::toEnd() {
    while (cursor != NULL && cursor->next != NULL) {
        prev = cursor;
        cursor = cursor->next;
    }
}


