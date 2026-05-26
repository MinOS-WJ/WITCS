#include <iostream>
using namespace std;

class Circle
{
public:
    Circle(float r = 1) 
    {
        radius = r;
    }

    float GetArea() 
    {
        return 3.1416f * radius * radius; 
    }

private:
    float radius;
}; 

class Cylinder : public Circle
{
public:
    Cylinder(float r = 1.0f, float h = 6.2f) : Circle(r), height(h) {}
    float GetVolume()
    {
        return GetArea() * height;
    }

private:
    float height;
};