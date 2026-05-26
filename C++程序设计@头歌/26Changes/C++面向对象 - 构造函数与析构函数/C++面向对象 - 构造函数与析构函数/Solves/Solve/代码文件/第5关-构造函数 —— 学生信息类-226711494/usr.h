#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int SID;
    string Name;

    Student() : SID(0), Name("王小明") {}

    Student(int sid, string name) : SID(sid), Name(name) {}

    ~Student() {
        cout << SID << " " << Name << " 退出程序" << endl;
    }
};
#endif
