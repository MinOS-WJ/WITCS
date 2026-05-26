#include "student.h"

Student::Student()
    : Person(), reg_Num(0), reg_day() {}

Student::Student(string name, string num, Date birthday,
                 int reg_Num, Date reg_day)
    : Person(name, num, birthday),
      reg_Num(reg_Num), reg_day(reg_day) {}

int  Student::getRegNum() const { return reg_Num; }
Date Student::getRegDay() const { return reg_day; }
void Student::setRegNum(int n)  { reg_Num = n; }
void Student::setRegDay(Date d) { reg_day = d; }

string Student::toString() const {
    // 注意：Person::toString 末尾没有空格/换行，
    // 这里直接拼接 reg_num，正好得到 "birthday:2000.12.11reg_num:18070001" 这种紧贴格式
    return Person::toString()
         + "reg_num:" + to_string(reg_Num)
         + "reg_day:" + reg_day.toString();
}