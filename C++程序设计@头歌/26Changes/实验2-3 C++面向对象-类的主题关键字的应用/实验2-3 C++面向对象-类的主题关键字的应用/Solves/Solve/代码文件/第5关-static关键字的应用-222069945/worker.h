#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Worker {
private:
    string name;
    int age;
    double salary;
    static int totalAge;
    static double totalSalary;
    static int count;
    
public:
    Worker();
    void inPut();
    
    static double getAverageAge();
    static double getAverageSalary();
};

#endif