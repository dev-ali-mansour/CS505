#include <iostream>

using namespace std;

class ClassExample {
private:
    int x;
public:
    void setx(int a) {
        x = a;
    }

    void print() {
        cout << "x = " << x << endl;
    }
};

int main() {
    ClassExample ob;
    ClassExample *obPointer;
    obPointer = &ob;

    ob.setx(10);
    obPointer->print();
    obPointer->setx(5);
    obPointer->print();
}