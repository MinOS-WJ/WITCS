#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

// ===== Date =====
class Date {
private:
    int year, month, day;
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

// ===== Person =====
class Person {
protected:
    string name;
    string num;
    Date   birthday;
public:
    Person();                                                          // 无参
    Person(string name, string num, Date birthday);                    // Date 对象版
    Person(string name, string num, int year, int month, int day);     // 年月日版

    string getName()     const;
    string getNum()      const;
    Date   getBirthday() const;
    void setName(string n);
    void setNum(string n);
    void setBirthday(Date b);

    string toString() const;
};

#endif