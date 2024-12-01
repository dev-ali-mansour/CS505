#include <iostream>
#include "list.h"

using namespace std;

int main() {
    list students;
    student st;

    char stayAlive;
    int counter = 1;
    do {
        cout << "Student Id: ";
        cin >> st.st_no;
        cout << "Student Name: ";
        cin >> st.st_name;
        cout << "Student Grade: ";
        cin >> st.st_grade;
        students.insertEnd(counter++, st);
        cout << "Add another student?\nY/y to continue , any other key to abort.\n";
        cin >> stayAlive;
    } while (stayAlive == 'Y' || stayAlive == 'y');

    students.traverse();
    cout << "Grades average: " << students.getGradesAverage() << endl;

    return 0;
}