#include "PairInternal.h"
#include <bits/stdc++.h>

using namespace std;

template < class T >
Pair<T>::~Pair() {
    polynomial.Clear();
}
template < class T >
Pair<T>::Pair() : value(0) {
}
template < class T >
Pair<T>::Pair(const T &value, const Polynomial<T> &polynomial) : value(value), polynomial(polynomial) {
}
template < class T >
Pair<T>::Pair(const Pair<T> &other) {
    this -> value = other.value;
    this -> polynomial = other.polynomial;
}

template < class T >
istream& operator >> (istream &in, Pair<T> &pai) {
    in >> pai.value >> pai.polynomial;
    
    return in;
}
template < class T >
ostream& operator << (ostream &out, Pair<T> &pai) {
    out << "Value is " << pai.value << "\n" << pai.polynomial;
    return out;
}

template < class T >
Pair<T>& Pair<T>::operator = (const Pair<T> &other) {
    this -> value = other.value;
    this -> polynomial = other.polynomial;

    return (*this);
}
template < class T >
bool Pair<T>::operator == (const Pair<T> &other) const {
    return ((this -> value == other.value) && (this -> polynomial == other.polynomial));
}
template < class T >
bool Pair<T>::operator != (const Pair<T> &other) const {
    return !(*this == other);
}
template < class T >
bool Pair<T>::operator < (const Pair<T> &other) const {
    if(this -> polynomial != other.polynomial) {
        return this -> polynomial < other.polynomial;
    }
    
    return (this -> value < other.value);
}
template < class T >
bool Pair<T>::IsRoot() const {
    return (this -> polynomial.ValueOnPoint(this -> value) == 0.0);
}
template < class T >
double Pair<T>::GetValue() const {
    return (this -> value);
}