#include"book.h"
#include<iostream>
#include <string>
using namespace std;
Book::Book()
{
    name="";
    stock=0;
}
Book::Book(string n,int s)
{
    name=n;
    stock=s;
}
string Book::getName()
{
    return name;
}
int Book::getStock()
{
    return stock;
}
void Book::setName(string n)
{
    name=n;
}
void Book::setStock(int s)
{
    stock=s;
}
void Book::sell(int num)
{
    stock-=num;

}
void Book::add(int num)
{
    stock+=num;
}
void Book::print()
{
    cout <<name <<" "<<stock <<endl;
}
void changeStock(Book& book,int op,int num)
{
    if(op==1)
    {
        book.sell(num);
    }
    else if(op==2)
    {
        book.add(num);
    }
}