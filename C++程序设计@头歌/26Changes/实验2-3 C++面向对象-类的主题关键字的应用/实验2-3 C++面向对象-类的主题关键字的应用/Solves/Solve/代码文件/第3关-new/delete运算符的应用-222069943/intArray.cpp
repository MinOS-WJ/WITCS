#include "intArray.h"
#include <iostream>
using namespace std;

intArray::intArray()
{
    data=nullptr;
    size =0;
}
intArray::intArray(const intArray& other)
{
    size =other.size;
    if(size>0)
    {
        data=new int[size];
        for(int i=0;i<size;i++)
        {
            data[i]=other.data[i];
        }
    }
    else
    {
        data=nullptr;
    }
}
intArray::~intArray()
{
    delete[] data;
}
intArray& intArray::operator=(const intArray& other)
{
    if(this != &other)

    {
        delete[] data;
        size=other.size;
        if(size>0)
        {
            data=new int[size];
            for (int i=0;i<size;i++)
            {
                data[i]=other.data[i];
            }
        }
        else
        {
            data=nullptr;
        }
    }
    return *this;
}
void intArray::Input()
{
    cin>>size;
    delete[] data;
    if(size>0)
    {
        data=new int[size];
        for(int i=0;i<size;i++)
        {
            cin>>data[i];

        }
    }
    else{
        data =nullptr;
    }
}
void intArray::Output() const
{
    cout<<"Array:";
    for(int i=0;i<size;i++)
    {
        if(i==0)
        {
            cout<<data[i];
        }
        else
        {
            cout<<" "<<data[i];
        }
    }
    cout<<endl;
}
void intArray::Resize(int newSize)
{
    int* newData=nullptr;
    if(newSize>0)
    {
        newData=new int[newSize];
        int minSize;
        if(size<newSize)
        {
            minSize=size;
        }
        else
        {
            minSize=newSize;
        }
        for(int i=0;i<minSize;i++)
        {
            newData[i]=data[i];
        }
        for(int i=minSize;i<newSize;i++)
        {
            newData[i]=0;
        }
    }
    delete[] data;
    data=newData;
    size=newSize;

}