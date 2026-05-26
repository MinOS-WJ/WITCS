#include "Int.h"

bool Int::operator < (Int const&rhs){
    return this->value < rhs.getValue();
}

bool Int::operator == (Int const&rhs){
    return this->value == rhs.getValue();
}

bool Int::operator <= (Int const&rhs){
    return (*this < rhs) || (*this == rhs);
}

bool Int::operator > (Int const&rhs){

    return this->value > rhs.getValue();
}

bool Int::operator >= (Int const&rhs){
    return !(*this < rhs);
}

bool Int::operator != (Int const&rhs){
    return !(*this == rhs);
}