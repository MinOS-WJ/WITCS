#ifndef INTARRAY_H
#define INTARRAY_H
#include <iostream>
using namespace std;
class intArray
{
private:
    int *data;
    int size;
public:
    intArray();
    intArray(const intArray& other);
    ~intArray();
    intArray& operator=(const intArray& other);
    void Input();
    void Output() const;
    void Resize(int newSize);
};
#endif