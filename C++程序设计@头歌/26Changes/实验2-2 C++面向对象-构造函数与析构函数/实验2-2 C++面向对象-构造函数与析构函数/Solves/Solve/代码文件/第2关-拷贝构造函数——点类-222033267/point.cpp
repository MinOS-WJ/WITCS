#include "point.h"
#include <iostream>
using namespace std;
Point::Point(int m,int n)
{
    x=m;
    y=n;
}
Point::Point(const Point& p)
{
    x=p.x;
    y=p.y;
}
void Point::print()
{
    cout<<"x和y的值为：x="<<x<<",y="<<y<<endl;
}