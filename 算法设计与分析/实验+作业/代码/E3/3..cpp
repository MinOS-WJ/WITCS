#include <iostream>
using namespace std;

const int MAXN = 100;     // 最大候选数个数
const int MAXPATH = 100;  // 最大组合长度
const int MAXRES = 1000;  // 最大结果数

int candidates[MAXN];
int path[MAXPATH];

int result[MAXRES][MAXPATH];
int resultSize[MAXRES];
int resCount = 0;

int n, target;

// 保存结果
void saveResult(int len)
{
    resultSize[resCount] = len;
    for(int i = 0; i < len; i++)
        result[resCount][i] = path[i];
    resCount++;
}

// 回溯
void backtrack(int start, int remain, int depth)
{
    if(remain == 0)
    {
        saveResult(depth);
        return;
    }

    for(int i = start; i < n; i++)
    {
        if(candidates[i] > remain)
            continue;

        path[depth] = candidates[i];

        // i 不变，允许重复选
        backtrack(i, remain - candidates[i], depth + 1);
    }
}

// 冒泡排序（保证非降序）
void sortArray()
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(candidates[j] > candidates[j + 1])
            {
                int temp = candidates[j];
                candidates[j] = candidates[j + 1];
                candidates[j + 1] = temp;
            }
        }
    }
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> candidates[i];

    cin >> target;

    sortArray();

    backtrack(0, target, 0);

    cout << "[";

    for(int i = 0; i < resCount; i++)
    {
        cout << "[";
        for(int j = 0; j < resultSize[i]; j++)
        {
            cout << result[i][j];
            if(j != resultSize[i] - 1)
                cout << ",";
        }
        cout << "]";
        if(i != resCount - 1)
            cout << ",";
    }

    cout << "]";

    return 0;
}

/*
时间复杂度：
排序：O(n²)
回溯搜索：最坏情况下接近 O(target^n)
总体：O(n² + target^n)

空间复杂度：
递归栈 + 路径存储：O(target)
结果存储：O(MAXRES * MAXPATH)
*/