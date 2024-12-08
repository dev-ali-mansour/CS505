#include <iostream>
#include "Queue.cpp"

using namespace std;

int main() {
    Queue<int> q, q1;
    int x, v, x1;

    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(4);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    cout << "queue length = " << q1.queueLength() << endl;


    return 0;
}