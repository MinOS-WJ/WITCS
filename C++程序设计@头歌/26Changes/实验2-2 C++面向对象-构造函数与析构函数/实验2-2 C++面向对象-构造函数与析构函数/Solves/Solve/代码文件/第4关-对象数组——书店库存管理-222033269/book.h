#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<string>
using namespace std;
class Book
{
private:
    string name;
    int stock;
public:
    Book();
    Book(string n,int s);
    string getName();
    int getStock();
    void setName(string n);
    void setStock(int s);
    void sell(int num);
    void add(int num);
    void print();
};
void changeStock(Book& book,int op,int num);
#endif