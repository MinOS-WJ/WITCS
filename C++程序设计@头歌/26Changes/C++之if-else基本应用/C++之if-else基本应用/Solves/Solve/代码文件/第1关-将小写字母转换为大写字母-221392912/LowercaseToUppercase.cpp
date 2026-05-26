// 将键盘输入的小写字母转换为大写字母，其他字母原样输出
char LowercaseToUppercase(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 32;
    else
        return c;
}