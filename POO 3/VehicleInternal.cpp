#include <bits/stdc++.h>
#include "VehicleInternal.h"

Vehicle::Vehicle() : x(0), y(0) {
}

Vehicle::Vehicle(const int &x, const int &y) : x(x), y(y) {
}

std::istream& operator >> (std::istream &in, Vehicle &veh) {
    in >> veh.x >> veh.y >> veh.maxMass >> veh.maxVolume;
    return veh.readVehicle(in, veh);
}
std::ostream& operator << (std::ostream &out, const Vehicle &veh) {
    veh.printVehicle(out, veh);
    return out;
}

bool Vehicle::CanDeliver(const Product &prod) {
    return canDeliver(prod);
}

void Vehicle::Update(const Product &prod) {
    return Deliver(prod);
}