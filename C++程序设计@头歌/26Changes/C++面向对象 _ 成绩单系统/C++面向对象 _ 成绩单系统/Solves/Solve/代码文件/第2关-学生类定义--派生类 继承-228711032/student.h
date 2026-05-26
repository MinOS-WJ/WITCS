#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : public Person {
private:
    int  reg_Num;   // 学号
    Date reg_day;   // 注册日期
public:
    Student();                                                              // 无参
    Student(string name, string num, Date birthday,                         // 全参
            int reg_Num, Date reg_day);

    int  getRegNum() const;
    Date getRegDay() const;
    void setRegNum(int n);
    void setRegDay(Date d);

    string toString() const;
};

#endif