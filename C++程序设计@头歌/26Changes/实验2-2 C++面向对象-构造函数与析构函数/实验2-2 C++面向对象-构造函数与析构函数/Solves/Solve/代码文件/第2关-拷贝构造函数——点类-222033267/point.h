#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;
class Point
{
private:
    int x,y;
public:
    Point(int m,int n);
    Point(const Point& p);
    void print();
};
#endif
