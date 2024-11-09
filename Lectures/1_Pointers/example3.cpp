#include <iostream>

using namespace std;

double *getSalary() {
    double salary = 26.48;
    double *hourlySalary = &salary;
    return hourlySalary;
}

int main() {
    double hours = 46.50;
    double salary = *getSalary();

    cout << "Weekly Hours: " << hours << endl;
    cout<<"Hourly Salary: "<<salary<<endl;

    double weeklySalary = hours * salary;

    cout << "Weekly salary: " << weeklySalary;

    return 0;
}