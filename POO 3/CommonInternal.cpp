#include <bits/stdc++.h>
#include "CommonInternal.h"

Vehicle* Vehicle::create(VehicleType vehType) {
    if(vehType == VT_Car) return new Car;
    if(vehType == VT_Truck) return new Truck;
    if(vehType == VT_Bike) return new Bike;
}

void readKnownVehicleType(std::istream &in, Vehicle **veh) {
    std::string type;
    in >> type;

    VehicleType vehType = ERROR;
    if(type == "car") vehType = VT_Car; 
    if(type == "truck") vehType = VT_Truck;
    if(type == "bike") vehType = VT_Bike;

    if(vehType == ERROR) {
        std::cout << "Invalid vehicle type!" << std::endl;
        exit(0);
    }
    
    *veh = Vehicle::create(vehType);
    in >> **veh;
}
