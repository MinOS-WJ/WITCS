#ifndef SEGMENT_H
#define SEGMENT_H
#include <iostream>
#include <cmath>
using namespace std;
class Point{
private:
    double  x,y;
public:
    Point();
    Point(double x,double y);
    double getX() const;
    double getY() const;
};
class Segment{
private:
    Point p1,p2;
public:
    Segment();
    Segment(Point a,Point b);
    Segment(double x1,double y1,double x2,double y2);
    Point MidPoint() const;
    double Length() const;
};
#endif