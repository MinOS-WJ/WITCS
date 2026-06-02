#include <iostream>
using namespace std;

int main() {
    int mods[9] = {10, 9, 8, 7, 6, 5, 4, 3, 2};
    int rems[9]; // 存储输入的余数

    for (int i = 0; i < 9; i++) {
        cin >> rems[i];
    }

    for (int n = rems[0]; n <= 2520; n += 10) {
        if (n == 0) {
            continue;
        }

        bool valid = true;
        for (int i = 0; i < 9; i++) {
            if (n % mods[i] != rems[i]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            cout << n << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}