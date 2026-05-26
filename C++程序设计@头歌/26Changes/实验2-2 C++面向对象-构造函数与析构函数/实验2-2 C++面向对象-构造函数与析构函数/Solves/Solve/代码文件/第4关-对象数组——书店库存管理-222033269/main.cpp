#include <iostream>
#include <string>
#include "book.h"
using namespace std;
int main()
{
    Book books[3];
    string name;
    int stock;
    for(int i=0;i<3;i++)
    {
        cin>>name>>stock;
        books[i].setName(name);
        books[i].setStock(stock);
    }
    string targetName;
    int op,num;
    for(int i=0;i<3;i++)
    {
        cin>>targetName>>op>>num;
        for(int j=0;j<3;j++)
        {
            if(books[j].getName()==targetName)
            {
                changeStock(books[j],op,num);
                break;
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        books[i].print();
    }
}