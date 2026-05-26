#include "course.h"

Course::Course() : code(0), courseName(""), testTime(), score(0) {}

Course::Course(int code, string courseName, Date testTime, int score)
    : code(code), courseName(courseName), testTime(testTime), score(score) {}

int    Course::getCode()       const { return code; }
string Course::getCourseName() const { return courseName; }
Date   Course::getTestTime()   const { return testTime; }
int    Course::getScore()      const { return score; }
void Course::setCode(int c)         { code = c; }
void Course::setCourseName(string n){ courseName = n; }
void Course::setTestTime(Date t)    { testTime = t; }
void Course::setScore(int s)        { score = s; }

string Course::toString() const {
    return to_string(code) + " " + courseName + " "
         + testTime.toString() + " " + to_string(score) + "\n";
}