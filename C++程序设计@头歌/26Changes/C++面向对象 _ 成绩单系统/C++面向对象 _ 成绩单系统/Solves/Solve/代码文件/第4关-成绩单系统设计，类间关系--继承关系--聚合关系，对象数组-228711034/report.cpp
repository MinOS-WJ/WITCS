#include "report.h"

Report::Report() : s(), selCourse() {}
Report::Report(Student s) : s(s), selCourse() {}

Student& Report::getStudent()        { return s; }
void Report::setStudent(Student st)  { s = st; }

void Report::addCourse(Course c)     { selCourse.push_back(c); }
int  Report::courseCount() const     { return (int)selCourse.size(); }

string Report::toString() const {
    string result = s.toString();
    for (const Course& c : selCourse) {
        result += c.toString();
    }
    return result;
}