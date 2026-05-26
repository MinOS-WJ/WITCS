#include "segment.h"
Point::Point(){
    cin>>x>>y;
}
Point::Point(double x,double y):x(x),y(y){}
double Point::getX()const {return x;}
double Point::getY() const{return y;}
Segment::Segment():p1(0,0),p2(0,0){}
Segment::Segment(Point a,Point b):p1(a),p2(b){}
Segment::Segment(double x1,double y1,double x2,double y2):p1(x1,y1),p2(x2,y2){}
Point Segment::MidPoint()const{
    return Point((p1.getX()+p2.getX())/2.0,(p1.getY()+p2.getY())/2.0);
}
double Segment::Length()const{
    double dx=p2.getX()-p1.getX();
    double dy=p2.getY()-p1.getY();
    return sqrt(dx*dx+dy*dy);
}