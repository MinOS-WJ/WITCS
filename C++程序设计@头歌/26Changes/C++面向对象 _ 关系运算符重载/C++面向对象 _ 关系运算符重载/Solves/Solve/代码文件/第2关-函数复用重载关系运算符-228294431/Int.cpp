#include "Int.h"

bool operator < (Int const&lhs, Int const&rhs){
    return lhs.getValue() < rhs.getValue();
}

bool operator == (Int const&lhs, Int const&rhs){
    return lhs.getValue() == rhs.getValue();
}

bool operator <= (Int const&lhs, Int const&rhs){
    return (lhs < rhs) || (lhs == rhs);
}

bool operator > (Int const&lhs, Int const&rhs){
    return rhs < lhs;
}

bool operator >= (Int const&lhs, Int const&rhs){
    return (rhs < lhs) || (lhs == rhs);
}

bool operator != (Int const&lhs, Int const&rhs){
    return !(lhs == rhs);
}