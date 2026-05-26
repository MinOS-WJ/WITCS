#include <iostream>
#include <iomanip>
#include "cuboid.h"
using namespace std;

void Cuboid::Set()
{
    length = 1.0;
    width = 1.0;
    height = 1.0;
}

void Cuboid::Set(double l, double w, double h)
{
    length = l;
    width = w;
    height = h;
}

double Cuboid::Volume() const
{
    return length * width * height;
}

double Cuboid::SurfaceArea() const
{
    return 2 * (length * width + length * height + width * height);
}

bool Cuboid::isCube() const
{
    return length == width && width == height;
}

void Cuboid::Print() const
{
    cout << fixed << setprecision(2);
    cout << "长：" << length
         << "-宽：" << width
         << "-高：" << height
         << "，";
    if (isCube())
        cout << "是立方体" << endl;
    else
        cout << "不是立方体" << endl;

    cout << "体积：" << Volume()
         << "-表面积：" << SurfaceArea() << endl;
}
