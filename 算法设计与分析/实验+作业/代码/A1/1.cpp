#include <iostream>

using namespace std;

int main() {
    for (int num = 100; num <= 999; ++num) {
        int hundreds = num / 100;
        int tens = (num / 10) % 10;
        int units = num % 10;

        if (units > hundreds && hundreds > tens) {
            int sum = hundreds + tens + units;
            int product = hundreds * tens * units;

            if (sum == product) {
                cout << "找到满足条件的三位数: " << num << endl;
                cout << "百位: " << hundreds << ", 十位: " << tens << ", 个位: " << units << endl;
                cout << "数字之和: " << sum << ", 数字之积: " << product << endl;
            }
        }
    }

    return 0;
}