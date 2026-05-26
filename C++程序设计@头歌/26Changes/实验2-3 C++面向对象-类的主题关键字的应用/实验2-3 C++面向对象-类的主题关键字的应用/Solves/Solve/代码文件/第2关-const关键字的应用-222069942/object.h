#ifndef OBJECT_H
#define OBJECT_H
#include<iostream>
using namespace std;
class object
{
private:
    const int a;
    const int c=1;
    int b;
public:
    object(int x,int y);
    int GetA() const;
    int& GetB();
    int GetB() const;
    int GetC() const;
    void Print() const;
};


#endif