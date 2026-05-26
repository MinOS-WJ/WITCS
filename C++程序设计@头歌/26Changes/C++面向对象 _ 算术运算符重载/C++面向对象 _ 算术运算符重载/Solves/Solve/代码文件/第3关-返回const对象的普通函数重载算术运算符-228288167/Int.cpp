#include "Int.h"

const Int operator + (Int const&lhs, Int const&rhs){
    return Int(lhs.getValue() + rhs.getValue());
}

const Int operator - (Int const&lhs, Int const&rhs){
    return Int(lhs.getValue() - rhs.getValue());
}

const Int operator * (Int const&lhs, Int const&rhs){
    return Int(lhs.getValue() * rhs.getValue());
}

const Int operator / (Int const&lhs, Int const&rhs){
    return Int(lhs.getValue() / rhs.getValue());
}

const Int operator % (Int const&lhs, Int const&rhs){
    return Int(lhs.getValue() % rhs.getValue());
}