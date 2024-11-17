#include <iostream>
#include "LinkedList.cpp"

int main() {
    LinkedList<int> intList;
    cout << boolalpha;
    cout << "Is Empty? " << intList.isEmpty() << endl;
    intList.printList();
    intList.insertAtBegging(10);
    intList.insertAtEnd(20);
    intList.insertAtBegging(5);
    intList.insertAtEnd(30);
    intList.insertAtEnd(40);
    cout << "Print list after insertion:\n";
    intList.printList();
    cout << "List Length: " << intList.length() << endl;
    intList.deleteNode(20);
    cout << "Print list after delete node:\n";
    intList.printList();
    intList.deleteNode(5);
    cout << "Print list after delete first node:\n";
    intList.printList();
    intList.deleteNode(40);
    cout << "Print list after delete last node:\n";
    intList.printList();
    cout << "List Length: " << intList.length() << endl;
    intList.insertAtBegging(1);
    intList.insertAtEnd(50);
    cout << "Print list after re-insertion\n";
    intList.printList();

    cout << "==================================\n";
    LinkedList<string> strList;
    cout << "Is Empty? " << strList.isEmpty() << endl;
    strList.insertAtBegging("C++");
    strList.insertAtEnd("JAVA");
    strList.insertAtBegging("PHP");
    strList.insertAtEnd("C#");
    strList.insertAtEnd("Node JS");
    cout << "Print list after insertion:\n";
    strList.printList();
    cout << "List Length: " << strList.length() << endl;
    strList.deleteNode("C#");
    cout << "Print list after delete node:\n";
    strList.printList();
    strList.deleteNode("PHP");
    cout << "Print list after delete first node:\n";
    strList.printList();
    strList.deleteNode("Node JS");
    cout << "Print list after delete last node:\n";
    strList.printList();
    strList.insertAtEnd("Java Script");
    strList.insertAtBegging("Kotlin");
    cout << "Print list after re-insertion\n";
    strList.printList();

    return 0;
}