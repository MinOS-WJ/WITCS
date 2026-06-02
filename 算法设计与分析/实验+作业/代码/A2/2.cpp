#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 20; // 假设最大测试N为20，足够覆盖题目要求的12

// 全局变量用于计数
int solutions_count = 0;
int n_global = 0;
int cols[MAX_N]; // cols[i] 表示第i行皇后所在的列

// 检查在(row, col)放置皇后是否合法
bool is_valid(int row, int col) {
    for (int i = 0; i < row; ++i) {
        // 检查列冲突和对角线冲突
        // cols[i] == col: 同一列
        // abs(row - i) == abs(col - cols[i]): 同一对角线
        if (cols[i] == col || abs(row - i) == abs(col - cols[i])) {
            return false;
        }
    }
    return true;
}

// 回溯法求解
void backtrack(int row) {
    if (row == n_global) {
        solutions_count++;
        return;
    }

    for (int col = 0; col < n_global; ++col) {
        if (is_valid(row, col)) {
            cols[row] = col;
            backtrack(row + 1);
            // 不需要显式撤销，因为下一次循环会覆盖 cols[row]
        }
    }
}

// 计算n皇后问题的解个数
int solve_n_queens(int n) {
    n_global = n;
    solutions_count = 0;
    // 初始化cols数组，虽然回溯中会覆盖，但好习惯是初始化
    for(int i=0; i<n; ++i) cols[i] = -1;
    
    backtrack(0);
    return solutions_count;
}

int main() {
    // 需要验证的N值
    int test_cases[] = {4, 6, 8, 12};
    int num_cases = 4;

    cout << "验证结论：当n为偶数时，N皇后解个数是否为 (N/2)皇后解个数的2倍？" << endl;

    for (int i = 0; i < num_cases; ++i) {
        int n = test_cases[i];
        int half_n = n / 2;

        int count_n = solve_n_queens(n);
        int count_half_n = solve_n_queens(half_n);

        cout << "N = " << n << ": 解个数 = " << count_n << endl;
        cout << "N/2 = " << half_n << ": 解个数 = " << count_half_n << endl;
        
        bool hypothesis = (count_n == 2 * count_half_n);
        cout << "假设 (Count(N) == 2 * Count(N/2)): " << (hypothesis ? "成立" : "不成立") << endl;
    }

    return 0;
}

/*
算法复杂度分析：
1. 时间复杂度：
   回溯法在最坏情况下需要遍历所有可能的放置方案。
   对于N皇后问题，第一行有N种选择，第二行最多N-1种... 
   理论上界是 O(N!)，但实际上由于剪枝（is_valid检查），搜索空间远小于N!。
   精确的时间复杂度很难用简单的多项式表示，通常认为是指数级的 O(2^N) 或 O(N!) 量级。
   对于每个节点，检查合法性需要 O(N) 时间（遍历之前所有的行）。
   因此，总的时间复杂度大致为 O(N * S)，其中S是解空间搜索的节点数。

2. 空间复杂度：
   主要消耗在递归调用栈和存储皇后位置的数组上。
   递归深度为N，数组大小为N。
   因此，空间复杂度为 O(N)。
*/