#include "Int.h"

Int operator + (Int const&lhs, Int const&rhs){
    return Int(lhs.getValue() + rhs.getValue());
}

Int operator - (Int const&lhs, Int const&rhs){
    return Int(lhs.getValue() - rhs.getValue());
}

Int operator * (Int const&lhs, Int const&rhs){
    return Int(lhs.getValue() * rhs.getValue());
}

Int operator / (Int const&lhs, Int const&rhs){
    return Int(lhs.getValue() / rhs.getValue());
}

Int operator % (Int const&lhs, Int const&rhs){
    return Int(lhs.getValue() % rhs.getValue());
}
