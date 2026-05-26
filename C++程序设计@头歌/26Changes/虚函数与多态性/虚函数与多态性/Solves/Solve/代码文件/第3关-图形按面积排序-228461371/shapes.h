#ifndef SHAPES_H
#define SHAPES_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual void print() const = 0;
    virtual ~Shape() {}
};
class Square : public Shape {
private:
    double side;
public:
    Square() { cin >> side; }
    double area() const override { return side * side; }
    void print() const override {
        cout << "正方形的面积是" << fixed << setprecision(2) << area() << endl;
    }
};
class Circle : public Shape {
private:
    double radius;
public:
    Circle() { cin >> radius; }
    double area() const override { return 3.14 * radius * radius; }
    void print() const override {
        cout << "圆形的面积是" << fixed << setprecision(2) << area() << endl;
    }
};
class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle() { cin >> a >> b >> c; }
    double area() const override {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    void print() const override {
        cout << "三角形的面积是" << fixed << setprecision(2) << area() << endl;
    }
};
inline void shape_sort(Shape **x, int n) {
    sort(x, x + n, [](Shape *a, Shape *b) {
        return a->area() < b->area();
    });
}

#endif