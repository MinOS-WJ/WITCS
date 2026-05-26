#include "Int.h"

Int Int::operator + (Int const&rhs){
    return Int(this->value + rhs.value);
}

Int Int::operator - (Int const&rhs){
    return Int(this->value - rhs.value);
}

Int Int::operator * (Int const&rhs){
    return Int(this->value * rhs.value);
}

Int Int::operator / (Int const&rhs){
    return Int(this->value / rhs.value);
}

Int Int::operator % (Int const&rhs){
    return Int(this->value % rhs.value);
}