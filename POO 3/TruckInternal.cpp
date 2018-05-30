#include <bits/stdc++.h>
#include "TruckInternal.h"

Truck::~Truck() {

}

Truck::Truck() : speed(5) {

}

Truck::Truck(int a, bool b) : speed(a), coldSupport(b) {

}

void Truck::printVehicle(std::ostream &out, const Vehicle &veh) const {
    out << "Truck position is: " << veh.x << " " << veh.y << "\n";
    out << "Truck speed is: " << speed << "\n";
    out << "Truck max vol: " << veh.maxVolume << "\n";
    out << "Truck max mass: " << veh.maxMass << "\n";
    out << "Truck support cold: " << this-> coldSupport << "\n";
    out << "Truck current time: " << veh.currentTime << "\n";
}

std::istream& Truck::readVehicle(std::istream &in, Vehicle &veh) {
    in >> coldSupport;
    return in;
}

int Truck::getDistance(int froX, int froY, int toX, int toY) {
    return (abs(froX - toX) + abs(froY - toY));
}

bool Truck::canDeliver(const Product &prod) {
    if(prod.needColdSupport && !coldSupport) return false;
    int startTime = this -> currentTime + ceil((double)getDistance(x, y, prod.sX, prod.sY) / (double)speed);
    startTime = std::max(startTime, prod.startTime);
    int endTime = startTime + ceil((double)getDistance(prod.sX, prod.sY, prod.eX, prod.eY) / (double)speed);

    return (endTime <= prod.endTime);
}

void Truck::Deliver(const Product &prod) {
    int startTime = this -> currentTime + ceil((double)getDistance(x, y, prod.sX, prod.sY) / (double)speed);
    startTime = std::max(startTime, prod.startTime);
    int endTime = startTime + ceil((double)getDistance(prod.sX, prod.sY, prod.eX, prod.eY) / (double)speed);

    this -> currentTime = endTime;
    this -> x = prod.eX;
    this -> y = prod.eY;
}