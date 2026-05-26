/********* Begin ********/
#include "Int.h"

void add(Int const& lhs, Int const& rhs, Int& ret) {
    ret.setValue(lhs.getValue() + rhs.getValue());
}

void mul(Int const& lhs, Int const& rhs, Int& ret) {
    ret.setValue(lhs.getValue() * rhs.getValue());
}


/********* End **********/