#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>
using namespace std;

const double PI = 3.14159;

class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }
};
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() override {
        return PI * radius * radius;
    }
};

#endif