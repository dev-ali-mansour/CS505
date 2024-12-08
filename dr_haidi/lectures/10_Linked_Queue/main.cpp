#include<iostream>
#include "QueueL.cpp"

using namespace std;

int main() {
    QueueL<int> q;
    int y;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.queueFront(y);
    cout << "queue front = " << y << endl;

    return 0;
}
