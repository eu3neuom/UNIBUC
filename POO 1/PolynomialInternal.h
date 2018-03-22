#ifndef POLYNOMIALINTERNAL_H
#define POLYNOMIALINTERNAL_H
#include <bits/stdc++.h>

class Polynomial {
    int degree;
    double *coefficients;
public:
    ~Polynomial();
    Polynomial();
    Polynomial(const int &len);
    Polynomial(const Polynomial &other);

    friend std::istream& operator >> (std::istream&, Polynomial &);
    friend std::ostream& operator << (std::ostream&, Polynomial &);

    void Equilibrate();
    void Clear();
    bool IsNull() const;
    double ValueOnPoint(const double &point) const;
    Polynomial operator + (const Polynomial &other) const;
    Polynomial operator - (const Polynomial &other) const;
    Polynomial& operator = (const Polynomial &other);
    bool operator == (const Polynomial &other) const;
    bool operator != (const Polynomial &other) const;
    bool operator < (const Polynomial &other) const;
    Polynomial operator * (const Polynomial &other) const;
    Polynomial operator / (const Polynomial &other) const;
    Polynomial operator % (const Polynomial &other) const;
    double operator [] (const int &pos) const;

    friend class Pair;
};

#endif