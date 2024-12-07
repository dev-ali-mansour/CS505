#include <iostream>
#include <stack>
#include "StackL.cpp"

using namespace std;


string decToHex(int n);

bool areBracketsBalanced(const string &exp);

char GetBottom(const stack<char> &s_org);

char GetBottom2(stack<char> &s_org);

void RemoveBlanks(StackL<char> &s);

void SwapStack(stack<int> &s);

int main() {
    StackL<char> s;
    char x;
    s.push('a');
    s.push(' ');
    s.push('b');
    s.push(' ');
    s.push('c');

    RemoveBlanks(s);
    while (!s.stackIsEmpty()) {
        s.pop(x);
        cout << x;
    }
    cout << endl;
    cout << decToHex(127) << endl;

    string expr = "{()}[]";
    if (areBracketsBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not balanced" << endl;

    // Todo Revision on converting infix to postfix expression from lecture PDF file

     stack<char> st;
     st.push('A');
     st.push('B');
     st.push('c');
     st.push('D');
     char ch = GetBottom(st);
//     char ch = GetBottom2(st);
     cout << "ch = " << ch << endl;
     while (!st.empty()) {
         cout << st.top() << endl;
         st.pop();
     }

    stack<int> nums;
    nums.push(1);
    nums.push(2);
    nums.push(3);
    nums.push(4);
    SwapStack(nums);
    while (!nums.empty()) {
        cout << nums.top() << endl;
        nums.pop();
    }

    return 0;
}

string decToHex(int n) {
    StackL<char> s;
    string h;
    int rem;
    char c;
    do {
        rem = n % 16;
        n /= 16;
        if (rem < 10) c = char(int('0') + rem);
        else c = char(int('A') + rem - 10);
        s.push(c);
    } while (n != 0);
    while (!s.stackIsEmpty()) {
        s.pop(c);
        h += c;
    }
    return h;
}

bool areBracketsBalanced(const string &exp) {
    stack<char> s;
    char x;
    for (int i = 0; i < exp.length(); ++i) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            s.push(exp[i]);
            continue;
        }
        if (s.empty()) return false;
        // Store the top element
        x = s.top();
        s.pop();
        switch (exp[i]) {
            case ']':
                if (x == '{' || x == '(') return false;
                break;
            case '}':
                if (x == '(' || x == '[') return false;
                break;
            case ')':
                if (x == '[' || x == '{') return false;
                break;
        }
    }
    return s.empty();
}

/*Sheet(5) Solutions:*/

/*4. Write a function GetBottom to retrieve the bottom element from a nonempty
stack of characters. The procedure should leave the stack unchanged.*/
char GetBottom(const stack<char> &s_org) {
    stack<char> s(s_org);   // Using the copy constructor
    char x = '\0';
    if (s.empty())
        cout << "Stack Underflow" << endl;
    else {
        while (!s.empty()) {
            x = s.top();
            s.pop();
        }
    }
    return x;
}

char GetBottom2(stack<char> &s_org) {
    stack<char> s;
    while (!s_org.empty()) {
        s.push(s_org.top());
        s_org.pop();
    }
    char x = s.top();
    while (!s.empty()) {
        s_org.push(s.top());
        s.pop();
    }
    return x;
}

/*5. Write a function RemoveBlanks to remove all blanks from a stack of
characters, leaving the stack otherwise unchanged.*/
void RemoveBlanks(StackL<char> &s) {
    char d;
    StackL<char> a;
    while (!s.stackIsEmpty()) {
        s.pop(d);
        if (d != ' ') a.push(d);
    }
    while (!a.stackIsEmpty()) {
        a.pop(d);
        s.push(d);
    }
}

/*6. Write a function SwapStack to exchange the top two elements of the stack,
leaving the stack otherwise unchanged.*/
void SwapStack(stack<int> &s) {
    int el1, el2;
    el1 = s.top();
    s.pop();
    el2 = s.top();
    s.pop();
    s.push(el1);
    s.push(el2);
}