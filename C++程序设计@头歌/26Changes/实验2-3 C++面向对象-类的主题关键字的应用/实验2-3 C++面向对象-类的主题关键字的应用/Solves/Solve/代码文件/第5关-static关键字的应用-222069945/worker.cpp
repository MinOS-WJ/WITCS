#include "worker.h"

// 静态成员的定义和初始化(必须在类外、且只能出现一次)
int Worker::totalAge = 0;
double Worker::totalSalary = 0.0;
int Worker::count = 0;

Worker::Worker() : name(""), age(0), salary(0.0) {}

void Worker::inPut() {
    cin >> name >> age >> salary;
    totalAge    += age;
    totalSalary += salary;
    ++count;
}

double Worker::getAverageAge() {
    return count == 0 ? 0.0 : (double)totalAge / count;
}

double Worker::getAverageSalary() {
    return count == 0 ? 0.0 : totalSalary / count;
}