#ifndef CS505_TIME_H
#define CS505_TIME_H


class Time {
private:
    int hour, minute, second;
public:
    Time();

    ~Time();

    void setTime(int, int, int);

    void displayTime() const;
};


#endif //CS505_TIME_H
