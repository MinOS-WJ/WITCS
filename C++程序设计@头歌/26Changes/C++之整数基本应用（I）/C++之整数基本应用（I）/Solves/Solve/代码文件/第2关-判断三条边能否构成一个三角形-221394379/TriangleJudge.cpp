// 判断三条边能否构成一个三角形
#include <iostream>
using namespace std;
bool TriangleJudge(float a, float b, float c)
{
    return (a + b > c && a + c > b && b + c > a);
}