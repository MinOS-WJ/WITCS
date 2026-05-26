#include "part.h"
using namespace std;
Part::Part(int x):i(x){
    cout<<"in Part()"<<endl;
}
Part::~Part(){
    cout<<"in ~Part()"<<endl;
}
Whole::Whole(int x):p(x){
    cout<<"in Whole()"<<endl;
}
Whole::~Whole(){
    cout<<"in ~Whole()"<<endl;
}
