#ifndef CARS_H
#define CARS_H

#include <iostream>
#include <string>
using namespace std;
class Car {
protected:
    string maker;
    string model;
    
public:
    Car(const string &m, const string &md) : maker(m), model(md) {}
    
    virtual void drive() {
        cout << maker << "-" << model;
    }
    
    virtual ~Car() {}
};
class FuelCar : virtual public Car {
public:
    FuelCar(const string &m, const string &md) : Car(m, md) {}
    
    void drive() {
        Car::drive();
        cout << "可以用燃油驱动" << endl;
    }
};
class ElectricCar : virtual public Car {
public:
    ElectricCar(const string &m, const string &md) : Car(m, md) {}
    
    void drive() {
        Car::drive();
        cout << "可以用电能驱动" << endl;
    }
};
class HybridCar : public FuelCar, public ElectricCar {
public:
    HybridCar(const string &m, const string &md) 
        : Car(m, md), FuelCar(m, md), ElectricCar(m, md) {}
    
    void drive() {
        cout << maker << "-" << model << "既可以用燃油驱动，也可以用电能驱动" << endl;
    }
};

#endif