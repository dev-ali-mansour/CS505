#ifndef CS505_SIMPLESTRING_H
#define CS505_SIMPLESTRING_H


class simpleString {
    int capacity;
    char *s;
    int length;

public:
    simpleString();

    simpleString(int);

    ~simpleString();

    void readString();

    void writeString() const;

    char at(int) const;

    int getLength() const;

    int getCapacity() const;

    void getContents(char []) const;

};


#endif //CS505_SIMPLESTRING_H
