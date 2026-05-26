#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

const double PI = 3.1416;
class Point {
public:
    Point(int = 0, int = 0);
    void print();
protected:
    int x;
    int y;
};

Point::Point(int a, int b) : x(a), y(b) {}

void Point::print() {
    cout << "[" << x << ", " << y << "]";
}
class Circle : public Point {
public:
    Circle(int = 0, int = 0, double = 0);
    double getDiameter();
    double getCircumference();
    double getArea();
    void print();
private:
    double radius;
};

Circle::Circle(int a, int b, double r) : Point(a, b), radius(r) {}

double Circle::getDiameter() {
    return 2.0 * radius;
}

double Circle::getCircumference() {
    return 2.0 * PI * radius;
}

double Circle::getArea() {
    return PI * radius * radius;
}

void Circle::print() {
    cout << "Center = ";
    Point::print();
    cout << " Radius = " << radius;
}

class Cylinder : public Circle {
public:
    Cylinder(int = 0, int = 0, double = 0, double = 0);
    double getArea();
    double getVolume();
    void print();
private:
    double height;
};

Cylinder::Cylinder(int a, int b, double r, double h)
    : Circle(a, b, r), height(h) {}

double Cylinder::getArea() {
    return 2.0 * Circle::getArea() + Circle::getCircumference() * height;
}

double Cylinder::getVolume() {
    return Circle::getArea() * height;
}

void Cylinder::print() {
    Circle::print();
    cout << " height = " << height;
}

#endif
