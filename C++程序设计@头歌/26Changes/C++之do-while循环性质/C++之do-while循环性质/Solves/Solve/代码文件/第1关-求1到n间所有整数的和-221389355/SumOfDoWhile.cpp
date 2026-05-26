// 使用do-while循环求1到n间所有整数的和
int Sum(int n)
{
    int sum = 0;
    int i = 1;
    do
    {
        sum += i;
        i++;
    } while (i <= n);
    return sum;
}