#include "Int.h"

Int& Int::operator = (const Int&rhs){
    if(this != &rhs){
        this->value = rhs.value;
    }
    return *this;
}

Int operator + (const Int&lhs, const Int&rhs){
    return Int(lhs.getValue() + rhs.getValue());
}

Int& Int::operator += (const Int&rhs){
    *this = *this + rhs;
    return *this;
}