#include <iostream>
using namespace std;

inline double CalArea(double x)
{
    return x * x * 3.14;
}

int main()
{
    double radius, area;

    cin >> radius;

    double r(radius);
    area = CalArea(r);
    cout << area << endl;
}
