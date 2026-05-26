#include"object.h"
#include <iostream>
using namespace std;
object::object(int x,int y):a(x)
{
    b=y;
}
int object::GetA() const
{
    return a;
}
int& object::GetB()
{
    return b;
}
int object::GetB() const
{
    return b;
}
int object::GetC() const
{
    return c;
}
void object::Print() const
{
    cout<<a<<" "<<b<<" "<<c<<endl;
}