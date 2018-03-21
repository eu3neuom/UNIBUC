#include "PolynomialInternal.h"
#include <bits/stdc++.h>

using namespace std;

Polynomial::~Polynomial() {
    this -> Clear();
}
Polynomial::Polynomial() : degree(0) {
    this -> coefficients = new double[degree + 1];
    for(int i = 0; i <= this -> degree; ++i) {
        this -> coefficients[i] = 0;
    }
}
Polynomial::Polynomial(const int &len) : degree(len) {
    this -> coefficients = new double[len + 1];
    for(int i = 0; i <= len; ++i) {
        this -> coefficients[i] = 0;
    }
}
Polynomial::Polynomial(const Polynomial &other) : degree(other.degree) {
    this -> coefficients = new double[this -> degree + 1];
    for(int i = 0; i <= this -> degree; ++i) {
        this -> coefficients[i] = other.coefficients[i];
    }
}
void Polynomial::Clear() {
    this -> degree = 0;
    delete[] this -> coefficients;
}

istream& operator >> (istream &in, Polynomial &polynomial) {
    polynomial.Clear();
    in >> polynomial.degree;
    polynomial.coefficients = new double[polynomial.degree + 1];
    for(int i = 0; i <= polynomial.degree; ++i) {
        in >> polynomial.coefficients[i];
    }
   
    polynomial.Equilibrate();
    return in;
}
ostream& operator << (ostream &out, Polynomial &polynomial) {
    out << "Polynomial degree is " << polynomial.degree << "\n";
    for(int i = polynomial.degree; i > 0; --i) {
        out << "((" << polynomial.coefficients[i] << ") * x^" << i << ") + ";
    }
    out << "(" << polynomial.coefficients[0] << ")";
    return out;
}

void Polynomial::Equilibrate() {
    while(this -> degree > 0 && this -> coefficients[this -> degree] == 0) {
        --this -> degree;
    }
}
bool Polynomial::IsNull() const {
    return ((this -> degree == 0) && (this -> coefficients[0] == 0.0));
}
double Polynomial::ValueOnPoint(const double &point) const {
    double value = 0;
    double x = 1;

    for(int i = 0; i <= degree; ++i) {
        value = value + x * coefficients[i];
        x *= point;
    }

    return value;
}
Polynomial Polynomial::operator + (const Polynomial &other) const {
    Polynomial temp(max(this -> degree, other.degree));

    for(int i = 0; i <= temp.degree; ++i) {
        if(i <= degree) temp.coefficients[i] += coefficients[i];
        if(i <= other.degree) temp.coefficients[i] += other.coefficients[i];     
    }

    temp.Equilibrate();
    return temp;
}
Polynomial Polynomial::operator - (const Polynomial &other) const {
    Polynomial temp(max(this -> degree, other.degree));

    for(int i = 0; i <= temp.degree; ++i) {
        if(i <= degree) temp.coefficients[i] += coefficients[i];
        if(i <= other.degree) temp.coefficients[i] -= other.coefficients[i];     
    }

    temp.Equilibrate();
    return temp;
}
Polynomial& Polynomial::operator = (const Polynomial &other) {
    this -> Clear();
    this -> degree = other.degree;
    this -> coefficients = new double[degree + 1];
    for(int i = 0; i <= degree; ++i) {
        this -> coefficients[i] = other.coefficients[i];
    }

    return *this;
}
Polynomial Polynomial::operator * (const Polynomial &other) const {
    Polynomial temp(this -> degree + other.degree);

    for(int i = 0; i <= this -> degree; ++i) {
        for(int j = 0; j <= other.degree; ++j) {
            temp.coefficients[i + j] += this -> coefficients[i] * other.coefficients[j]; 
        }  
    }

    temp.Equilibrate();
    return temp;
}
Polynomial Polynomial::operator / (const Polynomial &other) const {
    if(other.IsNull()) {
        cout << "Null polynomial! " << endl;
        exit(0);
    }
    if(*this < other) {
        Polynomial ret;
        return ret;
    }

    Polynomial aux(*this);
    Polynomial ret(this -> degree - other.degree);
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
Polynomial Polynomial::operator % (const Polynomial &other) const {
    Polynomial ret = (*this - ((*this / other) * other));
    ret.Equilibrate();
    return ret; 
}
double Polynomial::operator [] (const int &pos) const {
    return this -> coefficients[pos];
}
bool Polynomial::operator == (const Polynomial &other) const {
    if(this -> degree != other.degree) return false;
    for(int i = 0; i <= this -> degree; ++i) {
        if(this -> coefficients[i] != other.coefficients[i]) {
            return false;
        }
    }

    return true;
}
bool Polynomial::operator != (const Polynomial &other) const {
    return !(*this == other);
}
bool Polynomial::operator < (const Polynomial &other) const {
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