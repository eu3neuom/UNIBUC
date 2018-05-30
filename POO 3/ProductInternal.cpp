#include <bits/stdc++.h>
#include "ProductInternal.h"

Product::Product() : startTime(-1), endTime(-1), needColdSupport(false) {

}

Product::Product(int a, int b, bool c) : startTime(a), endTime(b), needColdSupport(c) {

}

Product::Product(const Product &other) {
    startTime = other.startTime;
    endTime = other.endTime;
    needColdSupport = other.needColdSupport;
}

std::ostream& operator << (std::ostream &out, const Product &other) {
    out << "Product time interval: [ " << other.startTime << ", " << other.endTime << " ]\n";
    out << "Product cold support: " << other.needColdSupport << "\n";
    out << "Product start position: { " << other.sX << ", " << other.sY << " }\n";
    out << "Product end position: { " << other.eX << ", " << other.eY << " }\n";
    return out;
}

std::istream& operator >> (std::istream &in, Product &other) {
    int tip; in >> tip;

    switch(tip) {
    case 0: // Must finish until second x
        in >> other.sX >> other.sY >> other.eX >> other.eY;
        in >> other.endTime >> other.needColdSupport;
        other.startTime = 0;
        break;
    case 1: // Must finish in interval [a, b]
        in >> other.sX >> other.sY >> other.eX >> other.eY;
        in >> other.startTime >> other.endTime >> other.needColdSupport;
        break;
    case 2: // No restrictions
        in >> other.sX >> other.sY >> other.eX >> other.eY;
        in >> other.needColdSupport;
        other.startTime = 0;
        other.endTime = 1000000000;
        break;
    default:
        std::cout << "Invalid product type!" << std::endl;
        exit(0);
    }
    return in;
}