#ifndef TRUCKINTERNAL_H
#define TRUCKINTERNAL_H
#include "CommonInternal.h"
#include <bits/stdc++.h>

class Truck : virtual public Vehicle {
private:
    int speed;
    bool coldSupport;
protected:
    virtual void Deliver(const Product &);
    virtual bool canDeliver(const Product &);
    virtual int getDistance(int, int, int, int);
    virtual void printVehicle(std::ostream &, const Vehicle &) const;
    virtual std::istream& readVehicle(std::istream &, Vehicle &);
public:
    ~Truck();
    Truck();
    Truck(int , bool); 
};

#endif