#ifndef PAIRINTERNAL_H
#define PAIRINTERNAL_H
#include <bits/stdc++.h>

class Pair {
    double value;
    Polynomial polynomial;
public:
    ~Pair();
    Pair();
    Pair(const double &value, const Polynomial &polinomial);
    Pair(const Pair &other);

    friend std::istream& operator >> (std::istream&, Pair &);
    friend std::ostream& operator << (std::ostream&, Pair &);

    Pair& operator = (const Pair &other);
    bool operator == (const Pair &other) const;
    bool operator != (const Pair &other) const;
    bool operator < (const Pair &other) const;
    bool IsRoot() const;
    double GetValue() const;
};

#endif