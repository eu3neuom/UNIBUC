#ifndef BIKEINTERNAL_H
#define BIKEINTERNAL_H
#include "CommonInternal.h"
#include <bits/stdc++.h>

class Bike : virtual public Vehicle {
private:
    int speed;
protected:
    virtual void Deliver(const Product &);
    virtual bool canDeliver(const Product &);
    virtual int getDistance(int, int, int, int);
    virtual void printVehicle(std::ostream &, const Vehicle &) const;
    virtual std::istream& readVehicle(std::istream &, Vehicle &);
public:
    Bike();
};

#endif