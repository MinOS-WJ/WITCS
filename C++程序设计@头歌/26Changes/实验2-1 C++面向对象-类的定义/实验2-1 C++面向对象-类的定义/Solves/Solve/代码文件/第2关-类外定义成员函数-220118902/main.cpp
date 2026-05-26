#include <iostream>
#include "rectangle.h"
using namespace std;

int main()
{
    Rectangle r;
    r.Set();
    cout << "长：" << r.GetLength() << endl;
    cout << "宽：" << r.GetWidth() << endl;
    cout << "面积：" << r.Area() << endl;
    cout << "周长：" << r.Perimeter() << endl;
    return 0;
}