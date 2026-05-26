#include"double.h"

Double::Double(double v)
{
    this->v=v;
}
void Double::Set(double v)
{
    this->v=v;
}
Double& Double::operator=(double v)
{
    this->v=v;
    return *this;
}