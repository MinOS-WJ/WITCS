#include "person.h"

// ===== Date =====
Date::Date() : year(1999), month(9), day(9) {}
Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

int  Date::getYear()  const { return year; }
int  Date::getMonth() const { return month; }
int  Date::getDay()   const { return day; }
void Date::setYear(int y)   { year  = y; }
void Date::setMonth(int m)  { month = m; }
void Date::setDay(int d)    { day   = d; }

string Date::toString() const {
    return to_string(year) + "." + to_string(month) + "." + to_string(day);
}

// ===== Person =====
Person::Person() : name("null"), num("null"), birthday() {}

Person::Person(string name, string num, Date birthday)
    : name(name), num(num), birthday(birthday) {}

Person::Person(string name, string num, int year, int month, int day)
    : name(name), num(num), birthday(year, month, day) {}

string Person::getName()     const { return name; }
string Person::getNum()      const { return num; }
Date   Person::getBirthday() const { return birthday; }
void Person::setName(string n)     { name = n; }
void Person::setNum(string n)      { num  = n; }
void Person::setBirthday(Date b)   { birthday = b; }

string Person::toString() const {
    return "name=" + name + " number=" + num + " birthday:" + birthday.toString();
}