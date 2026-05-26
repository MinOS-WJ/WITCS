#include "product.h"
#include <iostream>
#include <string>
using namespace std;
Product::Product()
{
    id="000000";
    name="未知";
    price=0;
    month=0;
    cout<<"生产产品"<<endl;
    Print();
}
Product::Product(string i,string n,double p,int m)
{
    id=i;
    name=n;
    price=p;
    month=m;
    cout<<"生产产品"<<endl;
    Print();
}
void Product::Print()
{
    cout<<"编号："<<id<<endl;
    cout<<"产品名称："<<name<<endl;
    cout<<"价格："<<price<<"元"<<endl;
    cout<<"有效期："<<month<<"个月"<<endl;
}
Product::~Product()
{
    cout<<"销毁产品："<<name<<endl;
}