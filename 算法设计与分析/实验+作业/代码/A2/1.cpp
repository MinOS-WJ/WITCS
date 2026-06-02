#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int m, n;
    // 输入 m 和 n
    if (!(cin >> m >> n)) {
        return 0;
    }

    // 边界情况处理
    if (m <= 0 || n <= 0) {
        cout << 0 << endl;
        return 0;
    }

    // 动态分配二维数组 dp[m][n]
    long long** dp = new long long*[m];
    for (int i = 0; i < m; ++i) {
        dp[i] = new long long[n];
    }

    // 初始化第一列
    for (int i = 0; i < m; ++i) {
        dp[i][0] = 1;
    }

    // 初始化第一行
    for (int j = 0; j < n; ++j) {
        dp[0][j] = 1;
    }

    // 填充 dp 表
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    // 输出结果
    cout << dp[m - 1][n - 1] << endl;

    // 释放内存
    for (int i = 0; i < m; ++i) {
        delete[] dp[i];
    }
    delete[] dp;

    return 0;
}
// 时间复杂度: O(m * n)，需要遍历整个 m x n 的网格。
// 空间复杂度: O(m * n)，用于存储 dp 数组。