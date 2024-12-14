#include <iostream>
#include "Queue.cpp"

using namespace std;

char QueueRear(const Queue<char> &q);

void reverseString(string &str);

void reverse(Queue<char> &q);

void split(Queue<int> &q, Queue<int> &q1, Queue<int> &q2);

void split2(const Queue<int> &Q, Queue<int> &Q1, Queue<int> &Q2);

void Append(Queue<int> &Q1, Queue<int> &Q2);

int NthElement(Queue<int> &Q, int n);

bool EqualQueues(Queue<int> q, Queue<int> q1);

bool EqualQueues2(const Queue<int> &Q1, const Queue<int> &Q2);

void min(const Queue<int> &q);

int main() {
    Queue<int> q, q1, q2;
    Queue<char> q3;
    int x, v, x1;
    char c;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    cout << "queue length = " << q.queueLength() << endl;
    q3.enqueue('A');
    q3.enqueue('B');
    q3.enqueue('C');
    q3.enqueue('D');
    cout << "queue rear = " << QueueRear(q3) << endl;
    string s = "ahmed";
    reverseString(s);
    reverse(q3);
    cout << "Reversed Queue:" << endl;
    while (!q3.queueIsEmpty()) {
        q3.dequeue(c);
        cout << c << endl;
    }

    q.reverse();
    cout << "Reversed Queue:" << endl;
    while (!q.queueIsEmpty()) {
        q.dequeue(x);
        cout << x << endl;
    }

//    split(q, q1, q2);
    split2(q, q1, q2);
    cout << "q1:" << endl;
    while (!q1.queueIsEmpty()) {
        q1.dequeue(x);
        cout << x << endl;
    }
    cout << "q2:" << endl;
    while (!q2.queueIsEmpty()) {
        q2.dequeue(x);
        cout << x << endl;
    }

    cout << "Original Queue:" << endl;
    while (!q.queueIsEmpty()) {
        q.dequeue(x);
        cout << x << endl;
    }

    Append(q1, q2);
    cout << "q1 after append:" << endl; // Don't forget to comment the previous print of q1,q2
    while (!q1.queueIsEmpty()) {
        q1.dequeue(x);
        cout << x << endl;
    }

    v = NthElement(q, 3);
    cout << "Element = " << v << endl;
    cout << "After removing element:" << endl;
    while (!q.queueIsEmpty()) {
        q.dequeue(x);
        cout << x << endl;
    }

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q2.enqueue(1);
    q2.enqueue(2);
    q2.enqueue(3);
    if (EqualQueues2(q1, q2))cout << "Queues are identical" << endl;
    else cout << "Queues are not equal" << endl;

    min(q1);

    return 0;
}

char QueueRear(const Queue<char> &q) {
    Queue<char> temp(q);
    char x;
    while (!temp.queueIsEmpty()) {
        temp.dequeue(x);
    }
    return x;
}

void reverseString(string &str) {
    Queue<char> q1, q2;
    string output = "";
    int length = str.length();
    for (int i = 0; i < length; i++) {
        q1.enqueue(str.at(i));
    }
    char el;
    for (int i = 0; i < length; i++) {
        int tempLength = q1.queueLength() - 1;
        for (int j = 0; j < tempLength; j++) {
            q1.dequeue(el);
            q2.enqueue(el);
        }
        q1.dequeue(el);
        output += el;
        tempLength = q2.queueLength();
        for (int j = 0; j < tempLength; j++) {
            q2.dequeue(el);
            q1.enqueue(el);
        }
    }
    cout << output << endl;
}

void reverse(Queue<char> &q) {
    char x;
    if (q.queueIsEmpty())return;
    q.dequeue(x);
    reverse(q);
    q.enqueue(x);
}

// Sheet 6 Answers

/*3. Implement a method that uses a stack to reverse a queue.
 Implemented inside Queue class and used in main().
 */

/* 4. A queue (Q) contains an even number of elements. Write a
function Split (Q,Q1,Q2) to copy the 1st half of (Q) into (Q1) and
the 2nd half into (Q2), leaving the original queue unchanged.*/
void split(Queue<int> &Q, Queue<int> &Q1, Queue<int> &Q2) {
    Queue<int> temp(Q);
    int length = Q.queueLength();
    int el;
    for (int i = 0; i < length / 2; i++) {
        temp.dequeue(el);
        Q1.enqueue(el);
    }
    int remain = temp.queueLength();
    for (int i = 0; i < remain; i++) {
        temp.dequeue(el);
        Q2.enqueue(el);
    }
}

// Suggested Solution
void split2(const Queue<int> &q, Queue<int> &q1, Queue<int> &q2) {
    Queue<int> temp(q);
    int x;
    int size = temp.queueLength();
    for (int i = 0; i < size; ++i) {
        temp.dequeue(x);
        if (i < (size / 2))
            q1.enqueue(x);
        else q2.enqueue(x);
    }
}

/* 5. Write a recursive function Append (Q1,Q2) to append a queue
 (Q2) to the end of a queue (Q1), leaving Q2 empty.*/
void Append(Queue<int> &Q1, Queue<int> &Q2) {
    int el;
    if (!Q2.queueIsEmpty()) {
        Q2.dequeue(el);
        Q1.enqueue(el);
        Append(Q1, Q2);
    }
}

/* 6. Write a function NthElement (Q) to return the nth element in a
 queue (Q), leaving the queue without that element.*/
int NthElement(Queue<int> &Q, int n) {
    int el, num;
    int len = Q.queueLength();
    for (int i = 1; i <= len; ++i) {
        Q.dequeue(el);
        if (i != n) Q.enqueue(el);
        else num = el;
    }
    return num;
}

/* 7. Write a boolean function EqualQueues ( Q1 , Q2 ) which receives
two queues Q1 and Q2 and returns True if they are identical and
False otherwise. The function should leave the queues unchanged.*/
bool EqualQueues(Queue<int> q, Queue<int> q1) {
    bool flag = false;
    Queue q2(q), q3(q1);
    int x, y;
    if (q2.queueLength() != q3.queueLength())
        return false;
    else {
        while (!q2.queueIsEmpty() && !q3.queueIsEmpty()) {
            q2.dequeue(x);
            q3.dequeue(y);
            if (x == y)
                flag = true;
            else
                return false;
        }
    }
    return flag;
}

// Suggested Answer
bool EqualQueues2(const Queue<int> &Q1, const Queue<int> &Q2) {
    if (Q1.queueLength() != Q2.queueLength()) return false;
    Queue<int> temp1(Q1), temp2(Q2);
    int x, y;
    while (!temp1.queueIsEmpty() && !temp2.queueIsEmpty()) {
        temp1.dequeue(x);
        temp2.dequeue(y);
        if (x != y) return false;
    }
    return true;
}

/* 8. Implement a method that find the minimum item in a queue
without changing the queue elements.*/


// Suggested Answer
void min(const Queue<int> &q) {
    Queue<int> temp(q);
    int x, min;
    q.queueFront(min);
    while (!temp.queueIsEmpty()) {
        temp.dequeue(x);
        if (x < min)min = x;
    }
    cout << "The minimum element = " << min << endl;
}