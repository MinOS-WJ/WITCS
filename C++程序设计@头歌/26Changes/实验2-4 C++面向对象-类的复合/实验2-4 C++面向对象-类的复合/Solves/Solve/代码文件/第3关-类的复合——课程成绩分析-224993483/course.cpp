#include "course.h"
#include <iomanip>

Course::Course(string id, string name, int cred, int sc, int qc)
    :id(id), name(name), cred(cred), studentCount(sc), quizCount(qc),
      maxScore(0), minScore(0), avgScore(0),
      excellentCount(0), goodCount(0), mediumCount(0),
      passCount(0), failCount(0) {
    students = new Student[studentCount];   // 动态学生数组
}

Course::~Course() {
    delete[] students;
}

void Course::inputData() {
    for (int i = 0; i < studentCount; i++)
        students[i].input(quizCount);
}

void Course::calculateGrades() {
    for (int i = 0; i < studentCount; i++)
        students[i].calculate();

    if (studentCount == 0) return;

    int sum = 0;
    maxScore = minScore = students[0].getTotalScore();

    for (int i = 0; i < studentCount; i++) {
        int s = students[i].getTotalScore();
        sum += s;
        if (s > maxScore) maxScore = s;
        if (s < minScore) minScore = s;

        if      (s >= 90) excellentCount++;
        else if (s >= 80) goodCount++;
        else if (s >= 70) mediumCount++;
        else if (s >= 60) passCount++;
        else              failCount++;
    }
    avgScore = (double)sum / studentCount;
}

void Course::displayReport() {
    cout << "=== 课程成绩分析 ===" << endl;
    cout << "课程编号：" << id << endl;
    cout << "课程名称：" << name << endl;
    cout << "学分：" << cred << endl;
    cout << "学生人数：" << studentCount << endl;
    cout << "总评成绩分析：" << endl;
    cout << fixed << setprecision(2);
    cout << "最高分：" << maxScore
         << "-最低分：" << minScore
         << "-平均分：" << avgScore << endl;
    cout << "优秀人数：" << excellentCount << endl;
    cout << "良好人数：" << goodCount << endl;
    cout << "中等人数：" << mediumCount << endl;
    cout << "及格人数：" << passCount << endl;
    cout << "不及格人数：" << failCount << endl;
}