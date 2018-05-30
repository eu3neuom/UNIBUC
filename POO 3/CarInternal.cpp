#include <bits/stdc++.h>
#include "CarInternal.h"

Car::~Car() {

}

Car::Car() : speed(10) {

}

Car::Car(int speed) : speed(speed) {

}

void Car::printVehicle(std::ostream &out, const Vehicle &veh) const {
    out << "Car position is: " << veh.x << " " << veh.y << "\n";
    out << "Car speed is: " << speed << "\n";
    out << "Car max vol: " << veh.maxVolume << "\n";
    out << "Car max mass: " << veh.maxMass << "\n";
    out << "Car current time: " << veh.currentTime << "\n";
}

std::istream& Car::readVehicle(std::istream &in, Vehicle &veh) {
    return in;
}

int Car::getDistance(int froX, int froY, int toX, int toY) {
    return (abs(froX - toX) + abs(froY - toY));
}

bool Car::canDeliver(const Product &prod) {
    if(prod.needColdSupport) return false;
    int startTime = this -> currentTime + ceil((double)getDistance(x, y, prod.sX, prod.sY) / (double)speed);
    startTime = std::max(startTime, prod.startTime);
    int endTime = startTime + ceil((double)getDistance(prod.sX, prod.sY, prod.eX, prod.eY) / (double)speed);

    return (endTime <= prod.endTime);
}

void Car::Deliver(const Product &prod) {
    int startTime = this -> currentTime + ceil((double)getDistance(x, y, prod.sX, prod.sY) / (double)speed);
    startTime = std::max(startTime, prod.startTime);
    int endTime = startTime + ceil((double)getDistance(prod.sX, prod.sY, prod.eX, prod.eY) / (double)speed);

    this -> currentTime = endTime;
    this -> x = prod.eX;
    this -> y = prod.eY;
}
