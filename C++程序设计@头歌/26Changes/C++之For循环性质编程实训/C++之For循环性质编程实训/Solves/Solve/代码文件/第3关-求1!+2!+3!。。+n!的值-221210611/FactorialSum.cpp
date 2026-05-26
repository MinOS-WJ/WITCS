// 计算1!+2!+3!+...+n!的值
double FactorialSum(int n)
{
    double sum = 0;
    double fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
        sum += fact;
    }
    return sum;
}