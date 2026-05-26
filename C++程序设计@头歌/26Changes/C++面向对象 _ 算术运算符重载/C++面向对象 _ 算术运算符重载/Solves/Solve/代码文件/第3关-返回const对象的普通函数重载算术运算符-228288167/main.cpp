#include "Int.h"
#include <iostream>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    Int a(x),b(y);
    Int c,d,e,f,g;
    
    c = a + b;
    d = a - b;
    e = a * b;
    f = a / b;
    g = a % b;
    
    cout<<c.getValue()<<" "
        <<d.getValue()<<" "
        <<e.getValue()<<" "
        <<f.getValue()<<" "
        <<g.getValue()<<endl;
    
    return 0;
}
