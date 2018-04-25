#ifndef VECTORINTERNAL_H
#define VECTORINTERNAL_H
#include <bits/stdc++.h>

template < class T >
class Vector {
private:
    unsigned int allocated;
    unsigned int size;
protected:
    T *data;
public:
    virtual ~Vector();
    Vector();
    Vector(unsigned int size);
    Vector(unsigned int size, const T &value);
    Vector(const Vector < T > &);

    template < class U > friend std::istream& operator >> (std::istream&, Vector < U > &);
    template < class U > friend std::ostream& operator << (std::ostream&, const Vector < U > &);
    
    unsigned int getSize() const;
    bool isEmpty() const;
    void Resize(const unsigned int &size);
    void Push_Back(const T &value);
    void Pop_Back();
    void Clear();
    void Print();

    virtual T& operator [] (const int &) const;
    Vector < T > operator * (const Vector < T > &) const;
    Vector < T > operator - () const;
    Vector < T >& operator = (const Vector < T > &);
    Vector < T > operator + (const Vector < T > &) const;
    Vector < T > operator - (const Vector < T > &) const;
    virtual bool operator == (const Vector < T > &) const;
    virtual bool operator != (const Vector < T > &) const;
    virtual bool operator < (const Vector < T > &) const;
};

#endif