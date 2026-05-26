#include <iostream>
#include <string>
#include "product.h"
using namespace std;
int main()
{
    string id;
    string name;
    double price;
    int month;
    cin>>id>>name>>price>>month;
    Product p1;
    Product p2(id,name,price,month);
    return 0;
}