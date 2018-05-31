#ifndef VEHICLEINTERNAL_H
#define VEHICLEINTERNAL_H

#include <bits/stdc++.h>

enum VehicleType {
    VT_Car, VT_Truck, VT_Bike, ERROR
};

class Vehicle {
protected:
    virtual void Deliver(const Product &) = 0;
    virtual bool canDeliver(const Product &) = 0;
    virtual int getDistance(int, int, int, int) = 0;
    virtual void printVehicle(std::ostream&, const Vehicle &) const = 0;
    virtual std::istream& readVehicle(std::istream&, Vehicle&) = 0;
public:
    int x, y, maxMass, maxVolume, currentTime;
    
    Vehicle();
    Vehicle(const int &x, const int &y);

    static Vehicle* create(VehicleType);
    friend std::istream& operator >> (std::istream&, Vehicle&);
    friend std::ostream& operator << (std::ostream&, const Vehicle&);

    void Update(const Product &);
    bool CanDeliver(const Product &);
};

#endif