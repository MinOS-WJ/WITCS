#include <iostream>
using namespace std;

int main()
{
    int x;
    int n = 0, sum = 0;
    double avg = 0;

    do
    {
        cin >> x;
        if (x > 0)
        {
            n++;
            sum += x;
        }
    } while (x != 0);

    avg = (double)sum / n;

    cout << "n=" << n << endl;
    cout << "avg=" << avg << endl;
    cout << "sum=" << sum << endl;
}