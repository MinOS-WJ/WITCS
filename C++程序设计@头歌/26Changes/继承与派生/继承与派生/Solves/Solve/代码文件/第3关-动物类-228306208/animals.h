#ifndef ANIMALS_H
#define ANIMALS_H

#include <iostream>
#include <string>
using namespace std;
class Animal {
protected:
    string name;
public:
    Animal(const string &n) : name(n) {}
    virtual ~Animal() {}
    
    void breath() {
        cout << name << "可以呼吸" << endl;
    }
    
    void forage() {
        cout << name << "可以觅食" << endl;
    }
};
class Dog : public Animal {
public:
    Dog(const string &name) : Animal(name) {}
    
    void run() {
        cout << name << "可以奔跑" << endl;
    }
};
class Fish : public Animal {
public:
    Fish(const string &name) : Animal(name) {}
    
    void swim() {
        cout << name << "可以游动" << endl;
    }
};

#endif