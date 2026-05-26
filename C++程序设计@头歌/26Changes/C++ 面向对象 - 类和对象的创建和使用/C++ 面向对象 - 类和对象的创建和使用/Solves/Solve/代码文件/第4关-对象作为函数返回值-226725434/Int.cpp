/********* Begin ********/
#include "Int.h"

Int add(Int const& lhs, Int const& rhs) {
    return Int(lhs.getValue() + rhs.getValue());
}

Int mul(Int const& lhs, Int const& rhs) {
    return Int(lhs.getValue() * rhs.getValue());
}

/********* End **********/