#ifndef POLYNOMIALINTERNAL_H
#define POLYNOMIALINTERNAL_H
#include <bits/stdc++.h>

template < class T >
class Polynomial : public Vector < T > {
private:
    int degree;
public:
    ~Polynomial();
    Polynomial();
    Polynomial(const int &);
    Polynomial(const Polynomial < T > &);

    template < class U > friend std::istream& operator >> (std::istream&, Polynomial < U >&);
    template < class U > friend std::ostream& operator << (std::ostream&, const Polynomial < U >&);

    void Clear();
    void Equilibrate();
    bool IsNull() const;

    T& operator [] (const int &) const;
    Polynomial < T >& operator = (const Polynomial < T > &);
    Polynomial < T > operator + (const Polynomial < T > &) const;
    Polynomial < T > operator - (const Polynomial < T > &) const;
    Polynomial < T > operator * (const Polynomial < T > &) const;
    Polynomial < T > operator - () const;
    Polynomial < T > operator / (const Polynomial < T > &) const;
    Polynomial < T > operator % (const Polynomial < T > &) const;
    bool operator == (const Polynomial < T > &) const;
    bool operator != (const Polynomial < T > &) const;
    bool operator < (const Polynomial < T > &) const;
    
    T ValueOnPoint(const T &) const;
};

#endif