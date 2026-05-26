#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date();
    Date(int y, int m, int d);

    int  getYear()  const;
    int  getMonth() const;
    int  getDay()   const;
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);

    string toString() const;
};

class Person {
private:
    string name;
    string num;
    Date   birthday;
public:
    Person();
    Person(string name, string num, Date birthday);
    Person(string name, string num, int year, int month, int day);
    string getName()     const;
    string getNum()      const;
    Date   getBirthday() const;
    void setName(string name);
    void setNum(string num);
    void setBirthday(Date birthday);

    string toString() const;
};

#endif