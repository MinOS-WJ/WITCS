#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;
class Student{
private:
    string id;
    string name;
    double* quizScores;
    int quizCount;
    double finalScore;
    int regularScore;
    int totalScore;
public:
    Student();
    ~Student();
    void input(int qc);
    void calculate();
    int getTotalScore() const;
};
#endif