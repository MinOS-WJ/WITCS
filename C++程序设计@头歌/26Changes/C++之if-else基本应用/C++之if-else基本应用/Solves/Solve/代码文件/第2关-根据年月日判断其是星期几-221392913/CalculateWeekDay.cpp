#include<iostream>
using namespace std;

int main(){
    int year,month,day;

    // 从命令行读入三个正整数
    // 这三个数取自测试集的输入
    cin>>year>>month>>day;
    if (month == 1 || month == 2)
    {
        month += 12;
        year--;
    }

    int w = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;

    switch (w)
    {
    case 0:
        cout << "星期日";
        break;
    case 1:
        cout << "星期一";
        break;
    case 2:
        cout << "星期二";
        break;
    case 3:
        cout << "星期三";
        break;
    case 4:
        cout << "星期四";
        break;
    case 5:
        cout << "星期五";
        break;
    case 6:
        cout << "星期六";
        break;
    }
}