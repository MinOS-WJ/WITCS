/********* Begin ********/
#include "Int.h"

Int::Int() : value(0) {}

Int::Int(int v) : value(v) {}

Int::Int(Int const& o) : value(o.value) {}

int Int::getValue() const {
    return value;
}





/******** End **********/