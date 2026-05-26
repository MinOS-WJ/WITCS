#ifndef _INT_H_
#define _INT_H_

class Int{
private:
    int value;
    
public:
    Int():value(0){}
    Int(Int const&rhs):value(rhs.value){}
    Int(int v):value(v){}
    
    int getValue()const{return value;}
    void setValue(int v){value=v;}
    
    // 拷贝赋值运算符重载
    Int& operator = (Int const&rhs){
        if(this != &rhs){
            this->value = rhs.value;
        }
        return *this;
    }
};

#endif