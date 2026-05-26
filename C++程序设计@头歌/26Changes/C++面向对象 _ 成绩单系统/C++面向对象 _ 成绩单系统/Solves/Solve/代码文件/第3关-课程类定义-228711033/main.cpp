#include <iostream>
#include "course.h"
using namespace std;

int main() {
    Course c1;
    Course c2(201, "math", Date(2018, 12, 24), 95);

    int y, m, d;
    cin >> y >> m >> d;
    Course c3(202, "PE", Date(y, m, d), 98);

    cout << c1.toString();
    cout << c2.toString();
    cout << c3.toString();

    return 0;
}