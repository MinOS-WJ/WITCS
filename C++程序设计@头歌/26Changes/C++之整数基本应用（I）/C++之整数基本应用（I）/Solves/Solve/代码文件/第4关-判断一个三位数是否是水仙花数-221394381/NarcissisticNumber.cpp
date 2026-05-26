//判断一个三位数是否是水仙花数
#include <iostream>
using namespace std;
bool NarcissisticNumber(int n)
{
    int a = n / 100;
    int b = n / 10 % 10;
    int c = n % 10;
    if (a * a * a + b * b * b + c * c * c == n)
        return true;
    else
        return false;
}