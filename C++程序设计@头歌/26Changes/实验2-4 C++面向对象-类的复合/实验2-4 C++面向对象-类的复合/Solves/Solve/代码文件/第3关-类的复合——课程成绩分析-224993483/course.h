#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include "student.h"
using namespace std;
class Course{
private:
    string id;
    string name;
    int cred;
    int studentCount;
    int quizCount;
    Student* students;
    int maxScore,minScore;
    double avgScore;
    int excellentCount;
    int goodCount;
    int mediumCount;
    int passCount;
    int failCount;
public:
    Course(string id,string name,int cred,int sc,int qc);
    ~Course();
    void inputData();
    void calculateGrades();
    void displayReport();
};
#endif