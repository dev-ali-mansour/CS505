#include <iostream>
#include "student.h"

using namespace std;

student::student() {
    for (int i = 0; i < 3; ++i)
        degree[i] = 0;
}

student::student(double gr[3]) {
    for (int i = 0; i < 3; ++i)
        degree[i] = gr[i];
}

void student::get_data() {
    cout << "\nStudent id:";
    cin >> d.id;
    cout << "\nStudent name:";
    cin >> d.name;
    for (int i = 0; i < 3; ++i) {
        cout << "\nenter student degree " << i + 1 << ":";
        cin >> degree[i];
    }
}

void student::display_data() const {
    cout << "\nstudent id:" << d.id;
    cout << "\nstudent name:" << d.name;
    for (int i = 0; i < 3; ++i) {
        cout << "\ndegree " << i + 1 << ": " << degree[i];
    }
}

void student::average_degree() const {
    double average = (degree[0] + degree[1] + degree[2]) / 3;
    cout << "\naverage degrees:" << average;
}

student::~student() {

}