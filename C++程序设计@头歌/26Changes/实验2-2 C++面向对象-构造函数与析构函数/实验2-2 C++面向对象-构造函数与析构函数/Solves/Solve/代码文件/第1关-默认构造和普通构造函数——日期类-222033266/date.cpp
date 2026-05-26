#include "date.h"
#include <iostream>
using namespace std;

Date::Date()
{
    year = 1970;
    month = 1;
    day = 1;
    Default=1;
}

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
    Default=0;
}
void Date::Print()
{
    if (Default)
    {
        cout << "缺省日期为："<<year<<"-"<<month <<"-"<<day<<endl;
    }
    else
    {
        cout <<"日期为："<<year<<"-"<<month<<"-"<<day<<endl;
    }
}
