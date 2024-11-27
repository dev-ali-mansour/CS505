#include <iostream>
#include <stack>

using namespace std;

void findNGE(const int arr[], int size);

void findNGE2(const int arr[], int size);

void printNGE(int arr[], int n);

int main() {
    int arr[] = {13, 7, 6, 12};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    findNGE(arr, arrSize);
    cout << "=========" << endl;
    findNGE2(arr, arrSize);
    cout << "=========" << endl;
    printNGE(arr, arrSize);
    return 0;
}

void findNGE(const int arr[], int size) {
    stack<int> stk;
    int results[size];

    for (int i = size - 1; i >= 0; --i) {
        while (!stk.empty() && stk.top() <= arr[i])
            stk.pop();

        results[i] = stk.empty() ? -1 : stk.top();

        stk.push(arr[i]);
    }

    for (int i = 0; i < size; ++i)
        cout << arr[i] << " -> " << results[i] << endl;
}

void findNGE2(const int arr[], int size) {
    stack<int> stk;
    int result;

    for (int i = size - 1; i >= 0; --i) {
        while (!stk.empty() && stk.top() <= arr[i])
            stk.pop();

        result = stk.empty() ? -1 : stk.top();
        cout << arr[i] << " -> " << result << endl;

        stk.push(arr[i]);
    }
}

void printNGE(int arr[], int n) {
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() < arr[i]) {
            cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }
        s.push(arr[i]);
    }

    while (!s.empty()) {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}
