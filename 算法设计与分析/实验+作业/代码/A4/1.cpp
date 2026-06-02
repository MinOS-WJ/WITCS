#include <iostream>

// 自定义 max 函数（避免使用 STL）
inline int myMax(int a, int b) {
    return a > b ? a : b;
}

// 动态规划解法（二维表）
int knapsackDP(int n, int cap, int weight[], int value[]) {
    // 分配 dp 表：dp[i][c] 表示前 i 个物品容量 c 的最大价值
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = new int[cap + 1];
        for (int c = 0; c <= cap; ++c)
            dp[i][c] = 0;
    }

    // 填表
    for (int i = 1; i <= n; ++i) {
        int w = weight[i - 1];
        int v = value[i - 1];
        for (int c = 0; c <= cap; ++c) {
            if (c < w)
                dp[i][c] = dp[i - 1][c];
            else
                dp[i][c] = myMax(dp[i - 1][c], dp[i - 1][c - w] + v);
        }
    }

    int ans = dp[n][cap];

    // 释放内存
    for (int i = 0; i <= n; ++i)
        delete[] dp[i];
    delete[] dp;

    return ans;
}

// 回溯法（暴力搜索）全局变量
int bestVal;              // 当前最优价值
int* w;                   // 物品重量数组（全局指针，便于递归访问）
int* v;                   // 物品价值数组

void dfs(int idx, int remCap, int curVal, int n) {
    if (idx == n) {       // 所有物品处理完毕
        if (curVal > bestVal)
            bestVal = curVal;
        return;
    }
    // 不选当前物品
    dfs(idx + 1, remCap, curVal, n);
    // 选当前物品（若容量允许）
    if (remCap >= w[idx]) {
        dfs(idx + 1, remCap - w[idx], curVal + v[idx], n);
    }
}

int knapsackBacktrack(int n, int cap, int weight[], int value[]) {
    w = weight;
    v = value;
    bestVal = 0;
    dfs(0, cap, 0, n);
    return bestVal;
}

int main() {
    int n, cap;
    std::cin >> n >> cap;

    int* weight = new int[n];
    int* value = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> weight[i] >> value[i];
    }

    int ansDP = knapsackDP(n, cap, weight, value);
    int ansBT = knapsackBacktrack(n, cap, weight, value);

    std::cout << "动态规划结果: " << ansDP << std::endl;
    std::cout << "回溯法结果:   " << ansBT << std::endl;

    delete[] weight;
    delete[] value;
    return 0;
}

/*
算法复杂度：
- 动态规划：时间复杂度 O(n * cap)，空间复杂度 O(n * cap)（使用二维表）。
- 回溯法：时间复杂度 O(2^n)（最坏情况遍历所有子集），空间复杂度 O(n)（递归栈深度）。
*/