#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
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

class Course {
private:
    int    code;
    string courseName;
    Date   testTime;
    int    score;
public:
    Course();
    Course(int code, string courseName, Date testTime, int score);

    int    getCode()       const;
    string getCourseName() const;
    Date   getTestTime()   const;
    int    getScore()      const;
    void setCode(int c);
    void setCourseName(string n);
    void setTestTime(Date t);
    void setScore(int s);

    string toString() const;
};

#endif