#ifndef CARINTERNAL_H
#define CARINTERNAL_H
#include "CommonInternal.h"
#include <bits/stdc++.h>

class Car : virtual public Vehicle {
private:
    int speed;
protected:
    virtual void Deliver(const Product &);
    virtual bool canDeliver(const Product &);
    virtual int getDistance(int, int, int, int);
    virtual void printVehicle(std::ostream &, const Vehicle &) const;
    virtual std::istream& readVehicle(std::istream &, Vehicle &);
public:
    ~Car();
    Car();
    Car(int);
    Car(const Car &);
};

#endif