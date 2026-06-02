#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

// 定义最大容量限制
const int MAX_CAP = 1005;

// 状态结构体
struct State {
    int l, m, n;      // 当前三个容器（L, M, N）中的油量
    int steps;        // 当前步数
    int prevIdx;      // 前驱状态在队列中的索引
    char action[64];  // 操作描述字符串
    
    State() : l(0), m(0), n(0), steps(0), prevIdx(-1) {
        action[0] = '\0';
    }
};

// 手动实现的BFS队列
State queue[1000005]; 
int head = 0;
int tail = 0;

// 访问标记数组 visited[m][n]，因为 l = L - m - n，所以只需记录 m 和 n 即可确定状态
bool visited[MAX_CAP][MAX_CAP];

// 递归打印路径
void printPath(int idx) {
    if (idx == -1) return;
    printPath(queue[idx].prevIdx);
    if (queue[idx].action[0] != '\0') {
        cout << queue[idx].action << endl;
    }
}

// 广度优先搜索求解最少步骤
bool bfs(int L, int M, int N) {
    // 初始化队列指针和访问数组
    head = 0;
    tail = 0;
    memset(visited, 0, sizeof(visited));
    
    // 初始状态：L满，M空，N空
    State start;
    start.l = L;
    start.m = 0;
    start.n = 0;
    start.steps = 0;
    start.prevIdx = -1;
    start.action[0] = '\0';
    
    queue[tail++] = start;
    visited[0][0] = true; 
    
    int target = L / 2;
    
    while (head < tail) {
        State current = queue[head++];
        
        // 检查是否达成目标：任意一个容器中有 L/2 的油量
        if (current.l == target || current.m == target || current.n == target) {
            printPath(head - 1);
            return true;
        }
        
        // 尝试6种倒水操作
        
        // 1. L -> M
        {
            int pour = min(current.l, M - current.m);
            if (pour > 0) {
                int nl = current.l - pour;
                int nm = current.m + pour;
                int nn = current.n;
                if (!visited[nm][nn]) {
                    visited[nm][nn] = true;
                    State next;
                    next.l = nl;
                    next.m = nm;
                    next.n = nn;
                    next.steps = current.steps + 1;
                    next.prevIdx = head - 1;
                    sprintf(next.action, "Pour %d from L to M", pour);
                    queue[tail++] = next;
                }
            }
        }
        
        // 2. L -> N
        {
            int pour = min(current.l, N - current.n);
            if (pour > 0) {
                int nl = current.l - pour;
                int nm = current.m;
                int nn = current.n + pour;
                if (!visited[nm][nn]) {
                    visited[nm][nn] = true;
                    State next;
                    next.l = nl;
                    next.m = nm;
                    next.n = nn;
                    next.steps = current.steps + 1;
                    next.prevIdx = head - 1;
                    sprintf(next.action, "Pour %d from L to N", pour);
                    queue[tail++] = next;
                }
            }
        }
        
        // 3. M -> L
        {
            int pour = min(current.m, L - current.l);
            if (pour > 0) {
                int nl = current.l + pour;
                int nm = current.m - pour;
                int nn = current.n;
                if (!visited[nm][nn]) {
                    visited[nm][nn] = true;
                    State next;
                    next.l = nl;
                    next.m = nm;
                    next.n = nn;
                    next.steps = current.steps + 1;
                    next.prevIdx = head - 1;
                    sprintf(next.action, "Pour %d from M to L", pour);
                    queue[tail++] = next;
                }
            }
        }
        
        // 4. M -> N
        {
            int pour = min(current.m, N - current.n);
            if (pour > 0) {
                int nl = current.l;
                int nm = current.m - pour;
                int nn = current.n + pour;
                if (!visited[nm][nn]) {
                    visited[nm][nn] = true;
                    State next;
                    next.l = nl;
                    next.m = nm;
                    next.n = nn;
                    next.steps = current.steps + 1;
                    next.prevIdx = head - 1;
                    sprintf(next.action, "Pour %d from M to N", pour);
                    queue[tail++] = next;
                }
            }
        }
        
        // 5. N -> L
        {
            int pour = min(current.n, L - current.l);
            if (pour > 0) {
                int nl = current.l + pour;
                int nm = current.m;
                int nn = current.n - pour;
                if (!visited[nm][nn]) {
                    visited[nm][nn] = true;
                    State next;
                    next.l = nl;
                    next.m = nm;
                    next.n = nn;
                    next.steps = current.steps + 1;
                    next.prevIdx = head - 1;
                    sprintf(next.action, "Pour %d from N to L", pour);
                    queue[tail++] = next;
                }
            }
        }
        
        // 6. N -> M
        {
            int pour = min(current.n, M - current.m);
            if (pour > 0) {
                int nl = current.l;
                int nm = current.m + pour;
                int nn = current.n - pour;
                if (!visited[nm][nn]) {
                    visited[nm][nn] = true;
                    State next;
                    next.l = nl;
                    next.m = nm;
                    next.n = nn;
                    next.steps = current.steps + 1;
                    next.prevIdx = head - 1;
                    sprintf(next.action, "Pour %d from N to M", pour);
                    queue[tail++] = next;
                }
            }
        }
    }
    
    return false;
}

int main() {
    int L, M, N;
    cin >> L >> M >> N;
    
    // 验证输入合法性：正整数、L为偶数、L=M+N
    if (L <= 0 || M <= 0 || N <= 0 || L % 2 != 0 || L != M + N) {
        cout << "None" << endl;
        return 0;
    }
    
    // 执行 BFS 搜索
    bool found = bfs(L, M, N);
    
    if (!found) {
        cout << "None" << endl;
    }
    
    return 0;
}

/*
 * 算法复杂度分析：
 * 
 * 1. 时间复杂度：O(M * N)
 *    - 状态空间由 M 和 N 容器中可能的油量组合决定，最多有 (M+1)*(N+1) 种状态。
 *    - 每个状态最多进行 6 次状态转移尝试（常数时间）。
 *    - 因此总时间复杂度与状态数量成正比，即 O(M * N)。
 *
 * 2. 空间复杂度：O(M * N)
 *    - visited 数组占用 O(M * N) 空间。
 *    - BFS 队列在最坏情况下也可能存储 O(M * N) 个状态。
 *    - 故总空间复杂度为 O(M * N)。
 */


 /*
 初始化：将初始状态(L,0,0)加入队列，标记visited[0][0]=true

while (队列不为空) {
    取出队首状态 current
    
    if (current.l == L/2 || current.m == L/2 || current.n == L/2) {
        找到目标！打印路径，返回true
    }
    
    for (每种倒水操作) {
        计算新状态 next
        
        if (新状态未访问过) {
            设置next的属性（包括prevIdx指向前驱）
            标记visited
            将next加入队列尾部
        }
    }
}

如果队列空了还没找到，返回false（无解）

示例：
输入：8 5 3
初始状态: (8, 0, 0)
第1步: Pour 5 from L to M → (3, 5, 0)
第2步: Pour 3 from M to N → (3, 2, 3)
第3步: Pour 3 from N to L → (6, 2, 0)
第4步: Pour 2 from M to N → (6, 0, 2)
第5步: Pour 5 from L to M → (1, 5, 2)
第6步: Pour 1 from M to N → (1, 4, 3)
此时 M=4=L/2，找到解！



 */