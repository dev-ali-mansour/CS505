#include <iostream>

using namespace std;

template<class T>
class Number {
private:
    T num;  // Variable of type T

public:
    Number(T n) { num = n; }

    T getNum() { return num; }
};

int main() {
    //Create object with int type
    Number<int> numberInt(7);

    // Create object with double type
    Number<double> numberDouble(7.7);

    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;

    return 0;
}