#include <iostream>
#include "student.h"
using namespace std;

int main() {
    // s1：无参，全部默认值
    Student s1;
    cout << s1.toString() << endl;

    // s2：Tom，写死的日期
    Student s2("Tom", "110105200001010001", Date(2000, 12, 11),
               18070001, Date(2018, 9, 1));
    cout << s2.toString() << endl;

    // s3：Jerry，注册日期从输入读
    int y, m, d;
    cin >> y >> m >> d;
    Student s3("Jerry", "110105200001010001", Date(2001, 10, 1),
               18070002, Date(y, m, d));
    cout << s3.toString() << endl;

    return 0;
}