#include <iostream>
#include <stack>

using namespace std;

void findNextGreaterElement(const int arr[], int size);

int main() {
    int arr[] = {13, 7, 6, 12};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    findNextGreaterElement(arr, arrSize);

    return 0;
}

void findNextGreaterElement(const int arr[], int size) {
    int results[size];
    stack<int> stk;

    for (int i = size - 1; i >= 0; --i) {
        while (!stk.empty() && stk.top() <= arr[i])
            stk.pop();

        results[i] = stk.empty() ? -1 : stk.top();

        stk.push(arr[i]);
    }

    for (int i = 0; i < size; ++i)
        cout << arr[i] << " -> " << results[i] << endl;
}