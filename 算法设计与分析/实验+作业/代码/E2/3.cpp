#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// 最大位数限制，n=32时，乘积最多64位，加上结束符和中间计算冗余，开128足够
const int MAX_LEN = 128;

// 辅助函数：去除前导零
// 输入: 字符串指针
// 返回: 指向第一个非零字符的指针，如果全零则指向最后一个零
char* removeLeadingZeros(char* str) {
    int len = strlen(str);
    int i = 0;
    while (i < len - 1 && str[i] == '0') {
        i++;
    }
    return str + i;
}

// 辅助函数：大整数加法 (字符串形式)
// 结果存入 res 缓冲区
void addBigNumbers(const char* num1, const char* num2, char* res) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;
    
    int carry = 0;
    int i = len1 - 1;
    int j = len2 - 1;
    int k = 0;
    
    char temp[MAX_LEN];
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        
        temp[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }
    
    // 反转结果
    for (int m = 0; m < k; m++) {
        res[m] = temp[k - 1 - m];
    }
    res[k] = '\0';
}

// 辅助函数：大整数乘以 10 的幂 (即在末尾添加 zeros 个 '0')
// 结果存入 res 缓冲区
void multiplyByPowerOf10(const char* num, int zeros, char* res) {
    int len = strlen(num);
    // 特殊情况：如果是 "0"，则结果还是 "0"
    if (len == 1 && num[0] == '0') {
        res[0] = '0';
        res[1] = '\0';
        return;
    }
    
    for (int i = 0; i < len; i++) {
        res[i] = num[i];
    }
    for (int i = 0; i < zeros; i++) {
        res[len + i] = '0';
    }
    res[len + zeros] = '\0';
}

// 核心分治乘法函数
// num1, num2: 输入大整数字符串
// res: 结果存储缓冲区
void divideAndConquerMultiply(const char* num1, const char* num2, char* res) {
    // 去除前导零以获取有效长度
    char* n1 = removeLeadingZeros((char*)num1);
    char* n2 = removeLeadingZeros((char*)num2);
    
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    
    // 基准情况：如果长度很小，直接计算
    // 这里设定阈值为 1 或 2，为了简单和避免过多递归开销，一位数直接乘
    if (len1 <= 1 && len2 <= 1) {
        int val1 = (len1 == 0) ? 0 : (n1[0] - '0');
        int val2 = (len2 == 0) ? 0 : (n2[0] - '0');
        int product = val1 * val2;
        sprintf(res, "%d", product);
        return;
    }
    
    // 确保两个数长度一致，不足补前导零（逻辑上补，实际操作通过索引控制）
    // 为了方便分割，我们取最大长度，并向上取偶数
    int maxLen = (len1 > len2) ? len1 : len2;
    // 如果长度是奇数，增加1使其变为偶数，方便对半拆分
    if (maxLen % 2 != 0) {
        maxLen++;
    }
    
    // 拆分点
    int half = maxLen / 2;
    
    // 提取 A, B, C, D
    // X = A * 10^half + B
    // Y = C * 10^half + D
    
    char A[MAX_LEN], B[MAX_LEN], C[MAX_LEN], D[MAX_LEN];
    
    // 初始化
    A[0] = '\0'; B[0] = '\0'; C[0] = '\0'; D[0] = '\0';
    
    // 获取 A (num1 的高位)
    // num1 的有效部分从 n1 开始，长度 len1
    // 如果 len1 > half, 则 A 是前 len1-half 位, B 是后 half 位
    // 如果 len1 <= half, 则 A = 0, B = num1
    
    if (len1 > half) {
        int aLen = len1 - half;
        strncpy(A, n1, aLen);
        A[aLen] = '\0';
        strcpy(B, n1 + aLen);
    } else {
        strcpy(A, "0");
        strcpy(B, n1);
    }
    
    if (len2 > half) {
        int cLen = len2 - half;
        strncpy(C, n2, cLen);
        C[cLen] = '\0';
        strcpy(D, n2 + cLen);
    } else {
        strcpy(C, "0");
        strcpy(D, n2);
    }
    
    // 递归计算子问题
    char AC[MAX_LEN], BD[MAX_LEN], AD[MAX_LEN], BC[MAX_LEN];
    char AD_plus_BC[MAX_LEN];
    char term1[MAX_LEN], term2[MAX_LEN], term3[MAX_LEN];
    char sum1[MAX_LEN], finalRes[MAX_LEN];
    
    // 1. 计算 AC
    divideAndConquerMultiply(A, C, AC);
    
    // 2. 计算 BD
    divideAndConquerMultiply(B, D, BD);
    
    // 3. 计算 AD
    divideAndConquerMultiply(A, D, AD);
    
    // 4. 计算 BC
    divideAndConquerMultiply(B, C, BC);
    
    // 5. 计算 AD + BC
    addBigNumbers(AD, BC, AD_plus_BC);
    
    // 6. 组合结果
    // XY = AC * 10^(2*half) + (AD+BC) * 10^half + BD
    
    // Term 1: AC * 10^(2*half)
    multiplyByPowerOf10(AC, 2 * half, term1);
    
    // Term 2: (AD+BC) * 10^half
    multiplyByPowerOf10(AD_plus_BC, half, term2);
    
    // Term 3: BD
    strcpy(term3, BD);
    
    // Sum = Term1 + Term2
    addBigNumbers(term1, term2, sum1);
    
    // Final = Sum + Term3
    addBigNumbers(sum1, term3, finalRes);
    
    // 拷贝结果到输出缓冲区
    strcpy(res, finalRes);
}

int main() {
    char input1[MAX_LEN];
    char input2[MAX_LEN];
    char result[MAX_LEN];
    
    // 测试用例要求 n=16 或 32
    // 示例输入
    cout << "Enter first large integer: ";
    cin >> input1;
    cout << "Enter second large integer: ";
    cin >> input2;
    
    // 执行乘法
    divideAndConquerMultiply(input1, input2, result);
    
    cout << "Product: " << result << endl;
    
    return 0;
}

/*
 * 算法时间复杂度分析:
 * 
 * 设 T(n) 为计算两个 n 位大整数乘法所需的时间。
 * 
 * 在分治策略中：
 * 1. 分解步骤：将两个数各分为两部分，耗时 O(1) (仅涉及指针操作或字符串截取，若视为复制则为 O(n))。
 * 2. 解决步骤：递归计算 4 个子问题，每个子问题的规模为 n/2。即 4 * T(n/2)。
 * 3. 合并步骤：
 *    - 计算 AD+BC：涉及两个 n/2 位数的加法，耗时 O(n)。
 *    - 移位操作（乘以 10 的幂）：涉及字符串复制或填充零，耗时 O(n)。
 *    - 最终加法：涉及最多 n+1 位数的加法，耗时 O(n)。
 *    - 因此，合并步骤的总耗时为 O(n)。
 * 
 * 递归方程为：
 * T(n) = 4T(n/2) + O(n)
 * 
 * 根据主定理 (Master Theorem):
 * a = 4, b = 2, f(n) = O(n)
 * log_b(a) = log_2(4) = 2
 * 因为 f(n) = O(n) = O(n^(log_b(a) - epsilon))，其中 epsilon = 1 > 0
 * 所以属于主定理的第一种情况。
 * 
 * 时间复杂度 T(n) = Theta(n^(log_b(a))) = Theta(n^2)。
 * 
 * 这与传统的竖式乘法复杂度相同。若要优化至 O(n^1.585)，可使用 Karatsuba 算法，将递归子问题减少为 3 个。
 * 但本题要求使用公式 XY = AC·10^n + (AD+BC)·10^(n/2) + BD，该公式包含 4 次乘法，故复杂度为 O(n^2)。
 */