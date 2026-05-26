#include <iostream>
using namespace std;

int main()
{
    int x,y;
    char ch;
    cin >>x>>y>>ch;
    switch (ch)
    {
    case '+':
        cout << x << ch << y << "=" << x + y;
        break;
    case '-':
        cout << x << ch << y << "=" << x - y;
        break;
    case '*':
        cout << x << ch << y << "=" << x * y;
        break;
    case '/':
        cout << x << ch << y << "=" << x / y;
        break;
    case '%':
        cout << x << ch << y << "=" << x % y;
        break;
    default:
        cout << "Error Operator!";
    }
}
