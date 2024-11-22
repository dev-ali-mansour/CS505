#ifndef CS505_RATIONAL_H
#define CS505_RATIONAL_H


class rational {
    int num;
    int denom;
public:
    rational();

    rational(int);

    rational(int, int);

    void setNum(int);

    void setDenom(int);

    int getNum() const;

    int getDenom() const;

    rational operator+(const rational &) const;

    rational operator-(const rational &) const;

    bool operator==(const rational &) const;

    rational multiply(const rational &f) const;

    rational divide(const rational &f) const;

    rational add(const rational &f) const;

    rational subtract(const rational &f) const;

    void readRational();

    void displayRational() const;

    rational reduce() const;
};


#endif //CS505_RATIONAL_H
