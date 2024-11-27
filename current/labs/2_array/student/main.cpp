#include "student.h"

using namespace std;

int main() {
    double grades[] = {5, 7, 10};
    student stu(grades);
    cout << "\nstudent id: ";
    cin >> stu.d.id;
    cout << "\nstudent name: ";
    cin >> stu.d.name;
    stu.display_data();

    //pointer to objects
    student *obj;
    int size;
    cout << "\nenter array size:";
    cin >> size;
    obj = new student[size];
    for (int i = 0; i < size; ++i)
        obj[i].get_data();

    for (int i = 0; i < size; ++i)
        obj[i].display_data();

    for (int i = 0; i < size; ++i)
        obj[i].average_degree();
}