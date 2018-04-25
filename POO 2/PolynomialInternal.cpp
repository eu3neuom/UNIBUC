#include "PolynomialInternal.h"
#include <bits/stdc++.h>

template < class T > 
Polynomial < T > :: ~Polynomial() {
    this -> Clear();
}
template < class T >
Polynomial < T > :: Polynomial() : degree(-1), Vector < T > (0) {
}
template < class T > 
Polynomial < T > :: Polynomial(const int &degree) : degree(degree), Vector < T > (degree + 1) {
}
template < class T > 
Polynomial < T > :: Polynomial (const Polynomial < T > &other) : degree(other.degree), Vector < T > ((Vector < T >&)other) {
}


template < class T > 
std::istream& operator >> (std::istream &in, Polynomial < T > &poly) {
    poly.Clear();
    in >> poly.degree;
    in >> (Vector < T >&)(poly);

    poly.Equilibrate();
    return in;
}
template < class T >
std::ostream& operator << (std::ostream &out, const Polynomial < T > &poly) {
    out << "Polynomial degree: " << poly.degree << "\n";
    out << (Vector < T >&)poly;

    return out;
}


template < class T > 
void Polynomial < T > :: Clear() {
    this -> degree = -1;
    this -> Vector < T > :: Clear();
}
template < class T >
void Polynomial < T > :: Equilibrate() {
    while(this -> degree >= 0 && this -> data[degree] == T()) {
        this -> Pop_Back();
        this -> degree -= 1;
    }
}
template < class T >
bool Polynomial < T > :: IsNull() const {
    return (this -> degree < 0);
}


template < class T > 
T& Polynomial < T > :: operator [] (const int &pos) const {
    if(pos < 0 || pos > degree) {
        std::cout << "Invalid position!" << std::endl;
        exit(0);
    }
    return this -> data[pos];
}
template < class T >
Polynomial < T >&  Polynomial < T > :: operator = (const Polynomial < T > &other) {
    this -> Clear();
    this -> degree = other.degree;
    (Vector < T >&)*this = (Vector < T >&)other;

    return *this;
}
template < class T >
Polynomial < T > Polynomial < T > :: operator + (const Polynomial < T > &other) const {
    Polynomial < T > temp(std::max(this -> degree, other.degree));
    (Vector < T >&)temp = (Vector < T >&)*this + (Vector < T >&)other;

    temp.Equilibrate();
    return temp;
}
template < class T >
Polynomial < T > Polynomial < T > :: operator - (const Polynomial < T > &other) const {
    Polynomial < T > temp(std::max(this -> degree, other.degree));
    (Vector < T >&)temp = (Vector < T >&)*this - (Vector < T >&)other;

    temp.Equilibrate();
    return temp;
}
template < class T >
Polynomial < T > Polynomial < T > :: operator * (const Polynomial < T > &other) const {
    Polynomial < T > temp(this -> degree + other.degree);
    (Vector < T >&)temp = (Vector < T >&)*this * (Vector < T >&)other;

    temp.Equilibrate();
    return temp;
}
template < class T >
Polynomial < T > Polynomial < T > :: operator - () const {
    Polynomial < T > temp(*this);
    (Vector < T >&)temp = -(Vector < T >&)temp;

    return temp;
}
template < class T > 
Polynomial<T> Polynomial<T>::operator / (const Polynomial<T> &other) const {
    if(other.IsNull()) {
        std::cout << "Null polynomial! " << std::endl;
        exit(0);
    }
    if(*this < other) {
        Polynomial<T> ret;
        return ret;
    }

    Polynomial<T> aux(*this);
    Polynomial<T> ret(this -> degree - other.degree);
    for(int a = aux.degree, b = other.degree; a >= other.degree; --a) {
        if(aux.getSize() <= a || other.getSize() <= b) continue;
        if(aux.data[a] == 0) continue;
        if(other.data[b] == 0) continue;
        
        double frac = aux.data[a] / other.data[b];
        Polynomial temp(a);
        for(int j = other.degree, k = a; j >= 0; --j, --k) {
            temp.data[k] = frac * other.data[j];
        }

        ret.data[a - b] = frac;
        aux = aux - temp;
    }
    
    ret.Equilibrate();
    return ret;
}
template < class T > 
Polynomial<T> Polynomial<T>::operator % (const Polynomial<T> &other) const {
    Polynomial<T> ret = (*this - ((*this / other) * other));

    ret.Equilibrate();
    return ret; 
}


template < class T >
bool Polynomial < T > :: operator == (const Polynomial < T > &other) const {
    if(this -> degree != other.degree) return false;
    return ((Vector < T >&)*this == (Vector < T >&)other);
}
template < class T > 
bool Polynomial < T > :: operator != (const Polynomial < T > &other) const {
    return !(*this == other);
}
template < class T > 
bool Polynomial < T > :: operator < (const Polynomial < T > &other) const {
    if(this -> degree < other.degree) return true;
    if(this -> degree > other.degree) return false;

    if((Vector < T >&)*this < (Vector < T >&)other) return true;
    return false;
}


template < class T > 
T Polynomial< T > :: ValueOnPoint(const T &point) const {
    double value = 0;
    double x = 1;

    for(int i = 0; i <= degree; ++i) {
        value = value + x * this -> data[i];
        x *= point;
    }

    return value;
}
