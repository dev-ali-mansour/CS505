#include <iostream>

#ifndef CS505_STUDENT_H
#define CS505_STUDENT_H

using namespace std;

class student {
    double degree[3];
public:
    struct data {
        int id;
        string name;
    } d;

    student();

    student(double gr[3]);

    void get_data();

    void display_data() const;

    void average_degree() const;

    ~student();
};


#endif //CS505_STUDENT_H
