#include<iostream>
class Cuboid
{
private:
    double length;
    double width;
    double height;
public:
    void Set();
    void Set(double l, double w, double h);
    double Volume() const;
    double SurfaceArea() const;
    bool isCube() const;
    void Print() const;
};
