#include "Int.h"
#include <iostream>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    Int a(x),b(y);
    
    if ( a < b ) cout<<"a is less than b."<<endl;
    else if ( a == b ) cout<<"a is equal to b."<<endl;
    else cout<<"a is greater than b."<<endl;
    
    return 0;
}
