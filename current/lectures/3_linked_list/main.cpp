#include <iostream>
#include "List.cpp"

using namespace std;

int main() {
    List<int, string> myList;
    cout << "List is empty: " << (myList.listIsEmpty() ? "Yes" : "No") << endl;

    myList.insertFirst(1, "First Element");
    myList.insertAfter(2, "Second Element");
    myList.insertAfter(4, "Fourth Element");
    myList.insertBefore(3, "Third Element");

    cout << "Size of list: " << myList.listSize() << endl;
    cout << "Traversing List\n";
    myList.traverse();

    if (myList.search(2)) {
        cout << "Key 2 found in the list!" << endl;

        myList.updateData("Updated Second Element");
        cout << "Retrieve Updated Element" << endl;
        string updated;
        myList.retrieveData(updated);
        cout << "updated Element: " << updated << endl;
    } else
        cout << "Key 2 not found!" << endl;

    myList.deleteFirst();

    cout << "List after deletion: " << endl;
    myList.traverse();

    myList.orderInsert(0, "Zero Element");
    myList.orderInsert(3, "Duplicate Third Element");
    cout << "List after order insertion: " << endl;
    myList.traverse();

    myList.insertEnd(1000, "Last Element");
    cout << "List after insertion at end: " << endl;
    myList.traverse();

    cout << "Is list at end?: " << (myList.atEnd() ? "Yes" : "No") << endl;

    myList.deleteEnd();
    cout << "List after delete end: ";
    myList.traverse();

    return 0;
}