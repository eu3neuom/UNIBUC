#ifndef POLYNOMIALINTERNAL_H
#define POLYNOMIALINTERNAL_H
#include <bits/stdc++.h>

template < class T > class Pair;

template < class T >
class Polynomial {
    int degree;
    T *coefficients;
public:
    ~Polynomial();
    Polynomial();
    Polynomial(const int &len);
    Polynomial(const Polynomial<T> &other);

    template < class U > friend std::istream& operator >> (std::istream&, Polynomial < U > &);
    template < class U > friend std::ostream& operator << (std::ostream&, Polynomial < U > &);

    void Equilibrate();
    void Clear();
    bool IsNull() const;
    T ValueOnPoint(const T &point) const;
    Polynomial<T> operator + (const Polynomial<T> &other) const;
    Polynomial<T> operator - (const Polynomial<T> &other) const;
    Polynomial<T>& operator = (const Polynomial<T> &other);
    bool operator == (const Polynomial<T> &other) const;
    bool operator != (const Polynomial<T> &other) const;
    bool operator < (const Polynomial<T> &other) const;
    Polynomial<T> operator -() const;
    Polynomial<T> operator * (const Polynomial<T> &other) const;
    Polynomial<T> operator / (const Polynomial<T> &other) const;
    Polynomial<T> operator % (const Polynomial<T> &other) const;
    T& operator [] (const int &pos);

    friend class Pair<T>;
};

#endif