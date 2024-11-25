#ifndef CS505_CALCULATOR_H
#define CS505_CALCULATOR_H


class calculator {
    int num1, num2;

public:
    calculator();

    calculator(int, int);

    void setNum1(int);

    void setNum2(int);

    void setData(int, int);

    int getNum1() const;

    int getNum2() const;

    void getData(int &, int &) const;

    int add() const;

    int subtract() const;

    int multiply() const;

    int divide() const;

    int operator+() const;

    int operator-() const;
};


#endif //CS505_CALCULATOR_H
