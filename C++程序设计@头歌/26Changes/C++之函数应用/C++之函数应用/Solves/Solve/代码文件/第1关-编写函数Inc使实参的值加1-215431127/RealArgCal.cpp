#include <iostream>
#include <fstream>
using namespace std;

int Inc(int &m)
{
    m = m + 1;
    return m;
}

int main()
{

    int m;
    cin >> m;

    Inc(m);
    cout << m << endl;
}
