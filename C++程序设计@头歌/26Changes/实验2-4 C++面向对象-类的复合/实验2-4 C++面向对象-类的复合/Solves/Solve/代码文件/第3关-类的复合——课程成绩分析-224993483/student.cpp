#include "student.h"
#include <cmath>

Student::Student()
    : quizScores(nullptr), quizCount(0), finalScore(0),
      regularScore(0), totalScore(0) {}

Student::~Student() {
    delete[] quizScores;          // nullptr 时 delete[] 也安全
}

void Student::input(int qc) {
    cin >> id >> name;
    quizCount = qc;
    quizScores = new double[qc];  // 动态生成数组
    for (int i = 0; i < qc; i++) cin >> quizScores[i];
    cin >> finalScore;
}

void Student::calculate() {
    double sum = 0;
    for (int i = 0; i < quizCount; i++) sum += quizScores[i];
    regularScore = (int)round(sum / quizCount);                    // 平时
    totalScore   = (int)round(regularScore * 0.4 + finalScore * 0.6); // 总评
}

int Student::getTotalScore() const { return totalScore; }