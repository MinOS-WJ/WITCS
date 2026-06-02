#include <iostream>

using namespace std;

int nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int count = 0;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void check_solution() {
    int two_digit = nums[0] * 10 + nums[1];
    int three_digit = nums[2] * 100 + nums[3] * 10 + nums[4];
    int four_digit = nums[5] * 1000 + nums[6] * 100 + nums[7] * 10 + nums[8];

    if (two_digit * three_digit == four_digit) {
        cout << two_digit << " x " << three_digit << " = " << four_digit << endl;
        count++;
    }
}

void generate_permutations(int start) {
    if (start == 9) {
        check_solution();
        return;
    }

    for (int i = start; i < 9; ++i) {
        swap(nums[start], nums[i]);
        generate_permutations(start + 1);
        swap(nums[start], nums[i]);
    }
}

int main() {
    generate_permutations(0);

    cout << "Total solutions found: " << count << endl;

    return 0;
}