#include "Int.h"
#include <iostream>
using namespace std;

int main(){
    int x;
    cin>>x;
    Int a;
    a.setValue(x);
    cout<<a.getValue()<<endl;
    return 0;
}
