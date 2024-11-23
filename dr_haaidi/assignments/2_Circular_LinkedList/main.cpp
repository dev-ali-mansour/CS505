#include <iostream>

using namespace std;

struct node {
    string emp_name;
    int emp_id;
    float salary;
    node *next;
};

int main() {
    node *head, *cursor, *tail, *p, *q, *f, *x;
    //Creating four new nodes to construct the circular linked list
    p = new node;
    q = new node;
    f = new node;
    x = new node;

    p->emp_id = 1;
    p->emp_name = "ahmed ali";
    p->salary = 1500;

    q->emp_id = 2;
    q->emp_name = "asmaa ahmed";
    q->salary = 2000;

    f->emp_id = 3;
    f->emp_name = "ali ragab";
    f->salary = 3500;

    x->emp_id = 4;
    x->emp_name = "hend hany";
    x->salary = 1200;
    //assign the 3 pointers
    //head to the first node
    //tail to the last node
    //cursor to the current node
    head = p;
    cursor = f;
    tail = x;
    //connecting the nodes in a chain "circular linked list"
    p->next = q;
    q->next = f;
    f->next = x;
    x->next = head; //linking the last node with the first node

    //1- create a new node with pointer named “last” and insert it after the last node.
    node *last = new node;
    last->emp_id = 5;
    last->emp_name = "hoda mohsen";
    last->salary = 3000;

    last->next = head; //or last->next = tail->next
    x->next = last;
    tail = last;

    //2- create a new node with pointer named “mid” and insert it after the cursor pointer.
    node *mid = new node;
    mid->emp_id = 6;
    mid->emp_name = "mohamed adel";
    mid->salary = 6000;

    mid->next = cursor->next;
    cursor->next = mid;
    cursor = mid;

    //3- create a new node with pointer named “first” and insert it in the head.
    node *first = new node;
    first->emp_id = 7;
    first->emp_name = "hana morsy";
    first->salary = 8000;

    first->next = head;
    head = first;
    tail->next = head; //or tail->next = first;

    //4- delete the last node.
    node *remove = tail;
    cursor->next = head;
    tail = cursor;
    delete remove;

    //5- delete the first node.
    node *remove_first = head;
    head = head->next;
    tail->next = head;
    delete remove_first;


    return 0;
}