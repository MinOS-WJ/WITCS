#ifndef ANIMALSWORLD_H
#define ANIMALSWORLD_H

#include <iostream>
using namespace std;
class Mammal {
public:
    virtual void speak() = 0;
    virtual ~Mammal() {}
};
class Dog : public Mammal {
public:
    void speak() override {
        cout << "汪汪汪" << endl;
    }
};
class Cat : public Mammal {
public:
    void speak() override {
        cout << "喵喵喵" << endl;
    }
};
inline void MammalSpeak(Mammal &m) {
    m.speak();
}

#endif