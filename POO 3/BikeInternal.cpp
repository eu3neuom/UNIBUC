#include <bits/stdc++.h>
#include "BikeInternal.h"

Bike::~Bike() {

}

Bike::Bike() : speed(20) {

}

Bike::Bike(int speed) : speed(speed) {

}

Bike::Bike(const Bike &other) {
    speed = other.speed;
}

void Bike::printVehicle(std::ostream &out, const Vehicle &veh) const {
    out << "Bike position is: " << veh.x << " " << veh.y << "\n";
    out << "Bike speed is: " << speed << "\n";
    out << "Bike max vol: " << veh.maxVolume << "\n";
    out << "Bike max mass: " << veh.maxMass << "\n";
    out << "Bike current time: " << veh.currentTime << "\n";
}

std::istream& Bike::readVehicle(std::istream &in, Vehicle &veh) {
    return in;
}

int Bike::getDistance(int froX, int froY, int toX, int toY) {
    double ret = sqrtl((froX - toX) * (froX - toX) + (froY - toY) * (froY - toY));
    return ceil(ret);
}

bool Bike::canDeliver(const Product &prod) {
    if(prod.needColdSupport) return false;
    int startTime = this -> currentTime + ceil((double)getDistance(x, y, prod.sX, prod.sY) / (double)speed);
    startTime = std::max(startTime, prod.startTime);
    int endTime = startTime + ceil((double)getDistance(prod.sX, prod.sY, prod.eX, prod.eY) / (double)speed);

    return (endTime <= prod.endTime);
}

void Bike::Deliver(const Product &prod) {
    int startTime = this -> currentTime + ceil((double)getDistance(x, y, prod.sX, prod.sY) / (double)speed);
    startTime = std::max(startTime, prod.startTime);
    int endTime = startTime + ceil((double)getDistance(prod.sX, prod.sY, prod.eX, prod.eY) / (double)speed);

    this -> currentTime = endTime;
    this -> x = prod.eX;
    this -> y = prod.eY;
}

Bike& Bike :: operator = (const Bike &other) {
    this -> speed = other.speed;
    this -> x = other.x;
    this -> y = other.y;
    this -> maxMass = other.maxMass;
    this -> maxVolume = other.maxVolume;
    this -> currentTime = other.currentTime;
    return *this;
}