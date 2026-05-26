#include <iostream>
#include "shape.h"
using namespace std;

int main() {
    int x, y;
    double r, h;
    cin >> x >> y >> r >> h;

    Cylinder cyl(x, y, r, h);

    cyl.print();
    cout << endl;
    cout << endl;
    cout << "Diameter is " << cyl.getDiameter() << endl;
    cout << "Area is " << cyl.getArea() << endl;
    cout << "Volume is " << cyl.getVolume() << endl;
    cout << "Buttom area is " << cyl.Circle::getArea() << endl;
    cout << "Center is";
    Point center(x, y);
    center.print();
    cout << endl;

    return 0;
}
