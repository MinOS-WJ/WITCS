// 根据收入计算个人所得税
double TaxCalculate(double m)
{
    if (m <= 1200)
        return 0;
    else if (m - 1200 <= 1000)
        return (m - 1200) * 0.05;
    else if (m - 1200 <= 3000)
        return (m - 1200) * 0.10;
    else if (m - 1200 <= 5000)
        return (m - 1200) * 0.15;
    else if (m - 1200 <= 10000)
        return (m - 1200) * 0.20;
    else
        return (m - 1200) * 0.30;
}