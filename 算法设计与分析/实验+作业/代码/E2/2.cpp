#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
    // 定义足够大的数组来存储高精度整数，假设最大长度为 1000
    char a[1005];
    int k;
    
    // 输入高精度整数和删除位数
    cin >> a >> k;
    
    int len = strlen(a);
    
    // 结果数组，模拟栈操作
    char result[1005];
    int top = -1; // 栈顶指针，-1表示为空
    
    // 贪心策略：遍历每一位数字
    for (int i = 0; i < len; ++i) {
        // 当栈不为空，且还有删除名额，且栈顶元素大于当前元素时，弹出栈顶（删除）
        while (top >= 0 && k > 0 && result[top] > a[i]) {
            top--;
            k--;
        }
        // 当前元素入栈
        result[++top] = a[i];
    }
    
    // 如果k还大于0，说明剩下的数字是递增的，直接从末尾删除k个
    top -= k;
    
    // 处理前导零
    int start = 0;
    while (start <= top && result[start] == '0') {
        start++;
    }
    
    // 输出结果
    if (start > top) {
        // 如果所有位都被移除或只剩下前导零，输出0
        cout << 0 << endl;
    } else {
        for (int i = start; i <= top; ++i) {
            cout << result[i];
        }
        cout << endl;
    }

    return 0;
}

// 算法复杂度分析:
// 时间复杂度: O(n)，其中 n 是输入数字的位数。每个数字最多入栈一次和出栈一次，所以总的操作次数是线性的。
// 空间复杂度: O(n)，用于存储结果数组，最坏情况下需要存储所有数字。