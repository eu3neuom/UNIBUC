#include "PolynomialInternal.h"
#include <bits/stdc++.h>

using namespace std;

template < class T > 
Polynomial<T>::~Polynomial() {
    this -> Clear();
}
template < class T > 
Polynomial<T>::Polynomial() : degree(0) {
    this -> coefficients = new T[degree + 1];
    for(int i = 0; i <= this -> degree; ++i) {
        this -> coefficients[i] = 0;
    }
}
template < class T > 
Polynomial<T>::Polynomial(const int &len) : degree(len) {
    this -> coefficients = new T[len + 1];
    for(int i = 0; i <= len; ++i) {
        this -> coefficients[i] = 0;
    }
}
template < class T > 
Polynomial<T>::Polynomial(const Polynomial<T> &other) : degree(other.degree) {
    this -> coefficients = new T[this -> degree + 1];
    for(int i = 0; i <= this -> degree; ++i) {
        this -> coefficients[i] = other.coefficients[i];
    }
}
template < class T > 
void Polynomial<T>::Clear() {
    this -> degree = 0;
    delete[] this -> coefficients;
}

template < class T > 
istream& operator >> (istream &in, Polynomial<T> &polynomial) {
    polynomial.Clear();
    in >> polynomial.degree;
    polynomial.coefficients = new T[polynomial.degree + 1];
    for(int i = 0; i <= polynomial.degree; ++i) {
        in >> polynomial.coefficients[i];
    }
   
    polynomial.Equilibrate();
    return in;
}
template < class T > 
ostream& operator << (ostream &out, Polynomial<T> &polynomial) {
    out << "Polynomial degree is " << polynomial.degree << "\n";
    for(int i = polynomial.degree; i > 0; --i) {
        out << "((" << polynomial.coefficients[i] << ") * x^" << i << ") + ";
    }
    out << "(" << polynomial.coefficients[0] << ")";
    return out;
}

template < class T > 
void Polynomial<T>::Equilibrate() {
    while(this -> degree > 0 && this -> coefficients[this -> degree] == 0) {
        --this -> degree;
    }
}
template < class T > 
bool Polynomial<T>::IsNull() const {
    return ((this -> degree == 0) && (this -> coefficients[0] == 0.0));
}
template < class T > 
T Polynomial<T>::ValueOnPoint(const T &point) const {
    double value = 0;
    double x = 1;

    for(int i = 0; i <= degree; ++i) {
        value = value + x * coefficients[i];
        x *= point;
    }

    return value;
}
template < class T > 
Polynomial<T> Polynomial<T>::operator + (const Polynomial<T> &other) const {
    Polynomial<T> temp(max(this -> degree, other.degree));

    for(int i = 0; i <= temp.degree; ++i) {
        if(i <= degree) temp.coefficients[i] += coefficients[i];
        if(i <= other.degree) temp.coefficients[i] += other.coefficients[i];     
    }

    temp.Equilibrate();
    return temp;
}
template < class T > 
Polynomial<T> Polynomial<T>::operator - (const Polynomial<T> &other) const {
    Polynomial<T> temp(max(this -> degree, other.degree));

    for(int i = 0; i <= temp.degree; ++i) {
        if(i <= degree) temp.coefficients[i] += coefficients[i];
        if(i <= other.degree) temp.coefficients[i] -= other.coefficients[i];     
    }

    temp.Equilibrate();
    return temp;
}
template < class T > 
Polynomial<T>& Polynomial<T>::operator = (const Polynomial<T> &other) {
    this -> Clear();
    this -> degree = other.degree;
    this -> coefficients = new T[degree + 1];
    for(int i = 0; i <= degree; ++i) {
        this -> coefficients[i] = other.coefficients[i];
    }

    return *this;
}
template < class T > 
Polynomial<T> Polynomial<T>::operator * (const Polynomial<T> &other) const {
    Polynomial<T> temp(this -> degree + other.degree);

    for(int i = 0; i <= this -> degree; ++i) {
        for(int j = 0; j <= other.degree; ++j) {
            temp.coefficients[i + j] += this -> coefficients[i] * other.coefficients[j]; 
        }  
    }

    temp.Equilibrate();
    return temp;
}
template < class T > 
Polynomial<T> Polynomial<T>::operator / (const Polynomial<T> &other) const {
    if(other.IsNull()) {
        cout << "Null polynomial! " << endl;
        exit(0);
    }
    if(*this < other) {
        Polynomial<T> ret;
        return ret;
    }

    Polynomial<T> aux(*this);
    Polynomial<T> ret(this -> degree - other.degree);
    for(int a = aux.degree, b = other.degree; a >= other.degree; --a) {
        if(aux.coefficients[a] == 0) continue;

        double frac = aux.coefficients[a] / other.coefficients[b];
        Polynomial temp(a);
        for(int j = other.degree, k = a; j >= 0; --j, --k) {
            temp.coefficients[k] = frac * other.coefficients[j];
        }
        ret.coefficients[a - b] = frac;
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
T Polynomial<T>::operator [] (const int &pos) const {
    return this -> coefficients[pos];
}
template < class T > 
bool Polynomial<T>::operator == (const Polynomial<T> &other) const {
    if(this -> degree != other.degree) return false;
    for(int i = 0; i <= this -> degree; ++i) {
        if(this -> coefficients[i] != other.coefficients[i]) {
            return false;
        }
    }

    return true;
}
template < class T > 
bool Polynomial<T>::operator != (const Polynomial<T> &other) const {
    return !(*this == other);
}
template < class T > 
bool Polynomial<T>::operator < (const Polynomial<T> &other) const {
    if(this -> degree != other.degree) {
        return (this -> degree < other.degree);
    }
    for(int i = 0; i < this -> degree; ++i) {
        if(this -> coefficients[i] != other.coefficients[i]) {
            return (this -> coefficients[i] < other.coefficients[i]);
        }
    }

    return false;
}