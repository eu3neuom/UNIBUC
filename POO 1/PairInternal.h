#ifndef PAIRINTERNAL_H
#define PAIRINTERNAL_H
#include <bits/stdc++.h>

template < class T > class Polynomial;

template < class T >
class Pair {
    double value;
    Polynomial<T> polynomial;
public:
    ~Pair();
    Pair();
    Pair(const T &value, const Polynomial<T> &polinomial);
    Pair(const Pair<T> &other);

    template < class U > friend std::istream& operator >> (std::istream&, Pair<U> &);
    template < class U > friend std::ostream& operator << (std::ostream&, Pair<U> &);

    Pair<T>& operator = (const Pair<T> &other);
    bool operator == (const Pair<T> &other) const;
    bool operator != (const Pair<T> &other) const;
    bool operator < (const Pair<T> &other) const;
    bool IsRoot() const;
    double GetValue() const;

    friend class Polynomial<T>;
};

#endif