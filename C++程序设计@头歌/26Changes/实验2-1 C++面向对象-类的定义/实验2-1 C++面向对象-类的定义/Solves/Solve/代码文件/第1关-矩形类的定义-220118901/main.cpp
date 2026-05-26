#include <iostream>
using namespace std;
class Rectangle
{
private:
    double length;
    double width;
public:
    void Set()
    {
        cin >> length >> width;
    }

    double GetLength() const
    {
        return length;
    }

    double GetWidth() const
    {
        return width;
    }

    double Area() const
    {
        return length * width;
    }

    double Perimeter() const
    {
        return 2 * (length + width);
    }
};
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