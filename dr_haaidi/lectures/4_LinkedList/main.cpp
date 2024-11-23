#include <iostream>

using namespace std;

struct node {
    //data
    string name;
    int id;
    float grade;
    //pointer
    node *next; //to point to the next node
};

int main() {
    node *p, *q, *head, *f;
    //first student
    p = new node;
    head = p;
    p->name = "Ahmed"; //(*p).
    p->id = 1;
    p->grade = 89.5;

    //second student
    q = new node;
    q->name = "Mona";
    q->id = 2;
    q->grade = 100;

    f = new node;
    f->name = "Ali";
    f->id = 3;
    f->grade = 58;

    //insert at head node "at first"
    f->next = head;
    head = f;

    p->next = q;
    q->next = NULL;

    cout << "q->name: " << q->name << endl;
    cout << "p->next->name: " << p->next->name << endl;

    cout << "p->next " << p->next << endl;
    cout << "q " << q << endl;

    delete p;
    delete q;

    return 0;
}