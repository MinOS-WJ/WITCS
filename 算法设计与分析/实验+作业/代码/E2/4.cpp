#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 10005; // 假设最大宽度，根据题目描述n不会太大，给一个足够大的值
const int INF = 1e9;     // 表示不可达

int springs[MAX_N];      // 存储每个弹簧的弹力
int dp[MAX_N];           // dp[i] 表示到达第 i 个弹簧所需的最少跳跃次数
int pre[MAX_N];          // pre[i] 记录到达第 i 个弹簧的前一个位置，用于回溯路径

int main() {
    int n;
    // 题目示例中给出的是具体数据，通常这类题目可能需要先输入n，再输入数组
    // 或者直接从文件/标准输入读取一行数据。
    // 为了通用性，这里假设输入格式为：
    // 第一行：n (河流宽度/弹簧数量)
    // 第二行：n 个整数，代表弹簧弹力
    
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; ++i) {
        cin >> springs[i];
    }

    // 初始化 dp 数组为无穷大
    for (int i = 0; i < n; ++i) {
        dp[i] = INF;
        pre[i] = -1;
    }

    // 初始位置在第一个弹簧上面，跳跃次数为 0 (因为还没开始跳，或者说在第0个位置上准备跳)
    // 注意：题目问“最少需要多少跳才能够到达对岸”。
    // 站在第0个弹簧上，算作起始状态。从第0个弹簧跳出去算第1跳。
    dp[0] = 0;

    // 动态规划过程
    for (int i = 0; i < n; ++i) {
        // 如果当前位置不可达，跳过
        if (dp[i] == INF) {
            continue;
        }

        // 如果当前弹簧弹力为0，除非它是最后一个且能直接过河，否则无法从这里起跳去更远的地方
        // 但循环内部逻辑是尝试更新 i+1 到 i+springs[i] 的位置
        // 如果 springs[i] == 0，内层循环不会执行，符合逻辑
        
        int maxJump = springs[i];
        
        // 尝试从位置 i 跳到位置 j
        // j 的范围是 i+1 到 i+maxJump
        // 注意：如果 i + maxJump >= n，说明可以直接跳出河外，到达对岸
        for (int j = 1; j <= maxJump; ++j) {
            int nextPos = i + j;
            
            // 情况1: 跳到了河中间的某个弹簧上 (nextPos < n)
            if (nextPos < n) {
                if (dp[i] + 1 < dp[nextPos]) {
                    dp[nextPos] = dp[i] + 1;
                    pre[nextPos] = i;
                }
            } 
            // 情况2: 直接跳出了河 (nextPos >= n)
            else {
                // 我们需要记录到达对岸的最小步数
                // 由于我们是按顺序遍历 i，且 dp[i] 是最小步数，
                // 第一个遇到的能跳出河的情况不一定全局最优？
                // 不，DP保证了 dp[i] 是到达 i 的最小步数。
                // 但是不同的 i 可能都能跳出河。我们需要找到所有能跳出河的 i 中 dp[i]+1 最小的。
                // 为了简单处理，我们可以引入一个变量 minJumpsToCross
                // 或者，我们可以虚拟一个终点 n，dp[n] 表示到达对岸的最小步数
                
                // 这里采用更新虚拟终点的方式不太方便数组大小固定。
                // 我们可以在循环结束后，检查所有能一步跨出边界的位置。
                // 或者，我们在循环内部维护一个全局最小值。
                
                // 让我们改变策略：
                // 不直接在内部 break，而是继续计算所有 dp[k] (k<n)。
                // 最后遍历所有位置 i，如果 i + springs[i] >= n，则 candidate = dp[i] + 1。
                // 取最小 candidate。
                
                // 因此，内层循环只处理 nextPos < n 的情况即可。
                // 跳出河的情况留到最后统一判断。
                break; 
            }
        }
    }

    // 计算到达对岸的最少跳跃次数
    int minJumps = INF;
    int lastSpringIndex = -1; // 记录是从哪个弹簧最后一跳跳出去的

    for (int i = 0; i < n; ++i) {
        if (dp[i] != INF) {
            // 如果从位置 i 可以跳出河
            if (i + springs[i] >= n) {
                if (dp[i] + 1 < minJumps) {
                    minJumps = dp[i] + 1;
                    lastSpringIndex = i;
                }
            }
        }
    }

    if (minJumps == INF) {
        cout << "-1" << endl;
    } else {
        cout << minJumps << endl;
        
        // 回溯路径
        // 路径包括：起点 -> ... -> lastSpringIndex -> 对岸
        // 我们需要输出跳跃方案，通常指经过的弹簧索引或者跳跃步骤
        // 题目要求“相应的跳跃方案”，这里输出经过的弹簧索引序列
        
        int path[MAX_N];
        int pathLen = 0;
        
        // 从 lastSpringIndex 回溯到 0
        int curr = lastSpringIndex;
        while (curr != -1) {
            path[pathLen++] = curr;
            curr = pre[curr];
        }
        
        // 逆序输出，从起点到最后一个弹簧
        for (int i = pathLen - 1; i >= 0; --i) {
            cout << path[i];
            if (i > 0) {
                cout << "->";
            }
        }
        cout << "->End" << endl; // 表示到达对岸
    }

    return 0;
}

/*
算法复杂度分析：
1. 时间复杂度：O(N * K)，其中 N 是弹簧的数量（河宽），K 是弹簧的最大弹力。
   在最坏情况下，每个弹簧的弹力都接近 N，此时内层循环执行 N 次，总复杂度为 O(N^2)。
   考虑到题目中“弹簧的最大弹力不超过n”，所以最坏时间复杂度为 O(N^2)。
   
2. 空间复杂度：O(N)，用于存储 springs, dp, pre 数组以及路径回溯数组。
*/