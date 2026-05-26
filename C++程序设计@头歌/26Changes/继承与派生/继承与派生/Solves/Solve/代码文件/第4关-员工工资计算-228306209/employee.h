#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <cstring>
using namespace std;
class Employee {
protected:
    char name[20];
    int hours;
    
public:
    Employee(const char *n, int h) : hours(h) {
        strcpy(name, n);
    }
    
    const char* getName() {
        return name;
    }
    virtual int getWage() {
        return 20 * hours;
    }
    
    virtual ~Employee() {}
};
class PartTimeEmployee : public Employee {
public:
    PartTimeEmployee(const char *n, int h) : Employee(n, h) {}
    int getWage() {
        if (hours <= 8) {
            return 12 * hours;
        } else {
            return 20 * hours;
        }
    }
};

#endif