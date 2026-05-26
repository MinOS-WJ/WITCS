#include <iostream>
#include <string>
#include "person.h"
using namespace std;

int main() {
    Person p1;
    cout << p1.toString() << endl;

    int y, m, d;

    cin >> y >> m >> d;
    string num1 = "110105" + to_string(y) + to_string(m) + to_string(d) + "1001";
    Date birthday(y, m, d);
    Person p2("小明", num1, birthday);
    cout << p2.toString() << endl;

    cin >> y >> m >> d;
    string num2 = "110105" + to_string(y) + to_string(m) + to_string(d) + "1002";
    Person p3("大师兄", num2, y, m, d);
    cout << p3.toString() << endl;

    return 0;
}