#ifndef DATE_CLASS
#define DATE_CLASS

#include <iostream>
using namespace std;
class Date
{
private:
    int year;
    int month;
    int day;
    bool Default;
public:
    Date();
    Date(int y, int m, int d);
    void Print();
};
#endif