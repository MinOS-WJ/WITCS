#ifndef REPORT_H
#define REPORT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date {
private:
    int year, month, day;
public:
    Date() : year(1999), month(9), day(9) {}
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    int  getYear()  const { return year; }
    int  getMonth() const { return month; }
    int  getDay()   const { return day; }
    void setYear(int y)   { year  = y; }
    void setMonth(int m)  { month = m; }
    void setDay(int d)    { day   = d; }

    string toString() const {
        return to_string(year) + "." + to_string(month) + "." + to_string(day);
    }
};

class Person {
protected:
    string name;
    string num;
    Date   birthday;
public:
    Person() : name("null"), num("null"), birthday() {}
    Person(string name, string num, Date birthday)
        : name(name), num(num), birthday(birthday) {}

    string getName()     const { return name; }
    string getNum()      const { return num; }
    Date   getBirthday() const { return birthday; }
    void setName(string n)     { name = n; }
    void setNum(string n)      { num  = n; }
    void setBirthday(Date b)   { birthday = b; }

    string toString() const {
        return "name=" + name + " number=" + num
             + " birthday:" + birthday.toString();
    }
};


class Student : public Person {
private:
    int    reg_num;
    Date   reg_day;
    string major;
public:
    Student() : Person(), reg_num(0), reg_day(), major("") {}
    Student(string name, string num, Date birthday,
            int reg_num, Date reg_day, string major)
        : Person(name, num, birthday),
          reg_num(reg_num), reg_day(reg_day), major(major) {}

    int    getRegNum() const { return reg_num; }
    Date   getRegDay() const { return reg_day; }
    string getMajor()  const { return major; }
    void setRegNum(int n)    { reg_num = n; }
    void setRegDay(Date d)   { reg_day = d; }
    void setMajor(string m)  { major   = m; }

    string toString() const {
        return Person::toString()
             + "reg_num:" + to_string(reg_num)
             + "reg_day:" + reg_day.toString()
             + " major:"  + major
             + "\n";
    }
};

class Course {
private:
    int    code;
    string courseName;
    Date   testTime;
    int    score;
public:
    Course() : code(0), courseName(""), testTime(), score(0) {}
    Course(int code, string courseName, Date testTime, int score)
        : code(code), courseName(courseName), testTime(testTime), score(score) {}

    int    getCode()       const { return code; }
    string getCourseName() const { return courseName; }
    Date   getTestTime()   const { return testTime; }
    int    getScore()      const { return score; }
    void setCode(int c)          { code = c; }
    void setCourseName(string n) { courseName = n; }
    void setTestTime(Date t)     { testTime = t; }
    void setScore(int s)         { score = s; }

    string toString() const {
        return to_string(code) + " " + courseName + " "
             + testTime.toString() + " " + to_string(score) + "\n";
    }
};

class Report {
private:
    Student        s;
    vector<Course> selCourse;
public:
    Report();
    Report(Student s);

    Student& getStudent();
    void setStudent(Student st);

    void addCourse(Course c);
    int  courseCount() const;

    string toString() const;
};

#endif