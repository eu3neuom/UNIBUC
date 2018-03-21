#include "PairInternal.h"
#include <bits/stdc++.h>

using namespace std;

Pair::~Pair() {
    polynomial.Clear();
}
Pair::Pair() : value(0) {
}
Pair::Pair(const double &value, const Polynomial &polynomial) : value(value), polynomial(polynomial) {
}
Pair::Pair(const Pair &other) {
    this -> value = other.value;
    this -> polynomial = other.polynomial;
}

istream& operator >> (istream &in, Pair &pai) {
    in >> pai.value >> pai.polynomial;
    
    return in;
}
ostream& operator << (ostream &out, Pair &pai) {
    out << "Value is " << pai.value << "\n" << pai.polynomial;
    return out;
}

Pair& Pair::operator = (const Pair &other) {
    this -> value = other.value;
    this -> polynomial = other.polynomial;

    return (*this);
}
bool Pair::operator == (const Pair &other) const {
    return ((this -> value == other.value) && (this -> polynomial == other.polynomial));
}
bool Pair::operator != (const Pair &other) const {
    return !(*this == other);
}
bool Pair::operator < (const Pair &other) const {
    if(this -> polynomial != other.polynomial) {
        return this -> polynomial < other.polynomial;
    }
    
    return (this -> value < other.value);
}
bool Pair::IsRoot() const {
    return (this -> polynomial.ValueOnPoint(this -> value) == 0.0);
}
double Pair::GetValue() const {
    return (this -> value);
}