#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.14159265358979323846

int main()
{
    int n;
    cin >> n;
    for (int i = n; i < n + 5; i++)
    {
        cout << fixed << setprecision(i) << PI << endl;
    }
    return 0;
}
