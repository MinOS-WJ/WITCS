#include <iostream>
using namespace std;

const int N = 4;          // 作业数
const int M = 3;          // 机器数
const int MAXNODE = 1000;
const int INF = 1e9;

int t[N][M];

// 结点定义
struct Node {
    int x[N];       // 当前调度顺序
    int used[N];    // 是否已使用
    int level;      // 已调度作业数
    int f1, f2, f3; // 三台机器当前完成时间
    int bound;      // 下界
};

// 最小堆优先队列（手写）
struct Heap {
    Node h[MAXNODE];
    int sz;

    Heap() { sz = 0; }

    void push(Node x) {
        int i = ++sz;
        while (i > 1 && h[i/2].bound > x.bound) {
            h[i] = h[i/2];
            i /= 2;
        }
        h[i] = x;
    }

    Node pop() {
        Node ret = h[1];
        Node last = h[sz--];
        int i = 1, child;
        while (i * 2 <= sz) {
            child = i * 2;
            if (child + 1 <= sz && h[child+1].bound < h[child].bound)
                child++;
            if (last.bound <= h[child].bound) break;
            h[i] = h[child];
            i = child;
        }
        h[i] = last;
        return ret;
    }

    bool empty() {
        return sz == 0;
    }
};

// 计算下界
int calcBound(Node &u) {
    int s = u.f3;
    for(int i=0;i<N;i++) {
        if(!u.used[i])
            s += t[i][2];
    }
    return s;
}

int bestTime = INF;
int bestOrder[N];

void branchBound() {
    Heap pq;

    Node root;
    root.level = 0;
    root.f1 = root.f2 = root.f3 = 0;
    for(int i=0;i<N;i++) root.used[i]=0;
    root.bound = calcBound(root);

    pq.push(root);

    while(!pq.empty()) {
        Node u = pq.pop();

        if(u.bound >= bestTime) continue;

        if(u.level == N) {
            if(u.f3 < bestTime) {
                bestTime = u.f3;
                for(int i=0;i<N;i++) bestOrder[i]=u.x[i];
            }
            continue;
        }

        for(int i=0;i<N;i++) {
            if(!u.used[i]) {
                Node v = u;
                v.x[v.level] = i;
                v.used[i]=1;
                v.level++;

                v.f1 = u.f1 + t[i][0];
                v.f2 = (v.f1 > u.f2 ? v.f1 : u.f2) + t[i][1];
                v.f3 = (v.f2 > u.f3 ? v.f2 : u.f3) + t[i][2];

                v.bound = calcBound(v);

                if(v.bound < bestTime)
                    pq.push(v);
            }
        }
    }
}

int main() {
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>t[i][j];

    branchBound();

    for(int i=0;i<N;i++) {
        cout<<bestOrder[i];
        if(i!=N-1) cout<<"->";
    }
    cout<<endl;
    cout<<bestTime<<endl;

    return 0;
}

/*
时间复杂度：
最坏情况下需要遍历所有作业排列：
O(N!)

每个结点计算扩展和下界：
O(N)

优先队列插入/删除：
O(log(N!))

综合复杂度：
O(N! * N * log(N!))

空间复杂度：
优先队列最多存储 O(N!) 个结点
每个结点存储 O(N)

总空间复杂度：
O(N! * N)
*/