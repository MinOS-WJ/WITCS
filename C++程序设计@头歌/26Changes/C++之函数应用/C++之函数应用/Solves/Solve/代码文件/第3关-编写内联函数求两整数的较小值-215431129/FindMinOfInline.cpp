#include <iostream>  
using namespace std;
inline double Min(float x, float y)
{
    return x < y ? x : y;
}

int main()
{
    float a, b, c;

    
    cin >> a >> b;

    c = Min(a, b);
    cout << "Min(" << a << "," << b << ")=" << c << endl;
}
