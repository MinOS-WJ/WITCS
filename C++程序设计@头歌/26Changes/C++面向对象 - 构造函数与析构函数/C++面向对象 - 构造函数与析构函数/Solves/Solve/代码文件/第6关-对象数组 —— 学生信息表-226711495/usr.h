#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
public:
    int SID;
    string Name;
    float Score;

    Student() : SID(0), Name(""), Score(0) {}

    Student(int sid, string name, float sco) : SID(sid), Name(name), Score(sco) {}
};

Student table[5];
int cnt = 0;

void Add(int sid, string name, float sco) {
    table[cnt++] = Student(sid, name, sco);
}

void PrintAll() {
    for (int i = 0; i < cnt; i++) {
        cout << table[i].SID << " " << table[i].Name << " " << table[i].Score << endl;
    }
}

void Average() {
    float sum = 0;
    for (int i = 0; i < cnt; i++) sum += table[i].Score;
    cout << "平均成绩 " << fixed << setprecision(4) << sum / cnt << endl;
}

#endif
