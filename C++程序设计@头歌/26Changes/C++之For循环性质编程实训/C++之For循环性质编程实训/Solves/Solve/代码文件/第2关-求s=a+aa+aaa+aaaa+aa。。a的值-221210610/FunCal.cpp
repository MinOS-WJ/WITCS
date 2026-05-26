// 求s=a+aa+aaa+aaaa+aa...a的值
int FunCal(int a, int n)
{
    int sum = 0;
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        t = t * 10 + a;
        sum += t;
    }
    return sum;
}