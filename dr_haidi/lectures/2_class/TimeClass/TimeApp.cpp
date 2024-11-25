#include "Time.h"
#include <iostream>

using namespace std;

int main() {
    Time t1, t2;
    cout << "Start Time is: ";
    t1.displayTime();
    t2.setTime(5, 10, 30);
    cout << "End Time is: ";
    t2.displayTime();

    return 0;
}
