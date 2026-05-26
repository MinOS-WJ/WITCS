#include <iostream>
#include <cmath>
using namespace std;

#define A (4 * x * x * x + 3 * x * x + 2 * x + 1)
#define B (12 * x * x + 6 * x + 2)

int main()
{ 

    double x = 1, a;

do
{
    a = A / B;
    x = x - a;
} while (fabs(a) > 1e-6);

cout << x << endl;
}
