#include <iostream>
#include "list.cpp"

using namespace std;

//exercises
int countZero(list<int, int> &l) {
    int count = 0, d;
    l.toFirst();
    while (!l.cursorIsEmpty()) { //l.cursorIsEmpty() != NULL
        l.retrieveData(d);
        if (d == 0)count++;
        l.advance();
    }
    return count;
}

int sum(list<int, int> &l) {
    int sum = 0, d;
    l.toFirst();
    while (!l.cursorIsEmpty()) {
        l.retrieveData(d);
        sum += d;
        l.advance();
    }
    return sum;
}

void split(list<int, int> &l) {
    list<int, int> l1, l2;
    int k, d;
    l1.makeListEmpty();
    l2.makeListEmpty();

    l.toFirst();
    l1.toFirst();
    l2.toFirst();
    while (!l.cursorIsEmpty()) {
        l.retrieveKey(k);
        l.retrieveData(d);
        if (d >= 0)l1.insertEnd(k, d);
        else l2.insertEnd(k, d);
        l.advance();
    }
    l.makeListEmpty();
}

int EvenKeys(list<int, char> &l) {
    l.toFirst();
    int count = 0, k;
    while (!l.cursorIsEmpty()) {
        l.retrieveKey(k);
        if (k % 2 == 0)count++;
        l.advance();
    }
    return count;
}

void AppendLists(list<int, char> &l, list<int, char> &l1, list<int, char> &l2) {
    int k;
    char d;
    l1.toFirst();
    l2.toFirst();
    while (!l1.cursorIsEmpty()) {
        l1.retrieveKey(k);
        l1.retrieveData(d);
        l.insertEnd(k, d);
        l1.advance();
    }
    while (!l2.cursorIsEmpty()) {
        l2.retrieveKey(k);
        l2.retrieveData(d);
        l.insertEnd(k, d);
        l2.advance();
    }
}

int main() {
    list<int, int> l1;
    int nodes_count = 0;

    /*l1.insertFirst(0, 'a');
    l1.insertBefore(1, 'b');
    l1.insertAfter(0, 'w');
    l1.insertEnd(0, 'x');*/
    l1.insertFirst(1, 0);
    l1.insertBefore(2, 1);
    l1.insertAfter(3, 0);
    l1.insertEnd(4, 0);
    nodes_count = countZero(l1);
    cout << "nodes_count = " << nodes_count << endl;
    cout << "sum = " << sum(l1) << endl;

    split(l1);
    cout << "l1 size = " << l1.listSize() << endl;

    list<int, char> cList, cList1, cListR;
    string s;
    char c;
    int i, count, output1, output2, output3;
    bool keyFound;
    int result = 0;

    cList1.insertEnd(6, 'a');
    cList1.insertEnd(7, 'b');
    cList1.insertEnd(8, 'c');
    cList1.insertEnd(9, 'd');

    //Read a string
    cout << "Enter a string:" << endl;
    getline(cin, s);
    cout << s << endl;
    for (i = 0; i < s.length(); ++i) {
        c = toupper(s.at(i));
        cList.insertEnd(i, c);
    }

    AppendLists(cListR, cList, cList1);

    cout << "LIST CONTENT:" << endl;
    cList.traverse();
    cout << "LIST SIZE: " << cList.listSize() << endl;
    cout << "List size using the recursive function: " << cList.Recursive_List_Size() << endl;
    cout << "Display list using the recursive function: \n" << cList.DisplayList() << endl;
    result = EvenKeys(cList);
    cout << "The even keys = " << result << endl;
    cout << "The content of the two appended lists:" << endl;
    cListR.traverse();
    cout << endl;
    cList.~list();
    cout << "AFTER CALLING DESTRUCTOR: " << cList.listSize() << endl;
    getchar();

    return 0;
}