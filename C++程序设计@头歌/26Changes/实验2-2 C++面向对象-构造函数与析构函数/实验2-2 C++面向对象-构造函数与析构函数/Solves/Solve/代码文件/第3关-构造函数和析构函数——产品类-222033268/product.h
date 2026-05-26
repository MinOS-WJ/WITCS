#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
using namespace std;
class Product
{
private:
    string id;
    string name;
    double price;
    int month;
public:
    Product();
    Product(string i, string n, double p, int m);
    void Print();
    ~Product();
};

#endif