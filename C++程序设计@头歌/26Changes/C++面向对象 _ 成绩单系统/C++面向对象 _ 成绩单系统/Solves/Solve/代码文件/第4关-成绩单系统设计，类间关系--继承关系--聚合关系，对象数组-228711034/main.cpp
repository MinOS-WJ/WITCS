#include <iostream>
#include "report.h"
using namespace std;

int main() {
    Student tom("Tom", "110101200110175555", Date(2001, 10, 17),
                17070001, Date(2018, 9, 1), "Computer");
    Report r1(tom);
    r1.addCourse(Course(201, "math", Date(2018, 11, 15), 75));
    r1.addCourse(Course(202, "C++",  Date(2018, 11, 22), 86));
    cout << r1.toString() << endl;

    Student wuming;
    wuming.setMajor("Material");
    Report r2(wuming);
    r2.addCourse(Course(300, "Math",      Date(2018, 12, 1), 100));
    r2.addCourse(Course(301, "Physics",   Date(2018, 12, 2),  99));
    r2.addCourse(Course(302, "Chemistry", Date(2018, 12, 3),  98));
    r2.addCourse(Course(303, "biology",   Date(2018, 12, 4),  97));
    r2.addCourse(Course(304, "material",  Date(2018, 12, 5),  96));
    cout << r2.toString() << endl;

    r2.getStudent().setName("JERRY");
    r2.getStudent().setNum("610101200205010364");
    r2.getStudent().setBirthday(Date(2002, 5, 1));
    cout << r2.toString() << endl;

    return 0;
}