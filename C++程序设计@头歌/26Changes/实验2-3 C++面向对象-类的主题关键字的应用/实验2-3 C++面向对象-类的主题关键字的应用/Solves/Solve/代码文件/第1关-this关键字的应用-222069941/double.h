#pragma
#include <iostream>
using namespace std;

class Double{
private:
    double v;
public:
    Double(double v=0);
    void Set(double v);
    Double& operator=(double v);

    void Print(){cout<<v<<endl;}
};