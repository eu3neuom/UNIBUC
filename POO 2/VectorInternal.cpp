#include "VectorInternal.h"
#include <bits/stdc++.h>

const unsigned int ALLOC_CONST = 2;

template < class T >
Vector < T > :: ~Vector() {
    this -> Clear();
}
template < class T > 
Vector < T > :: Vector() : size(0), allocated(1) {
    this -> data = new T[allocated];
}
template < class T >
Vector < T > :: Vector(unsigned int size) : size(size), allocated(1) {
    while(allocated < size) {
        allocated *= ALLOC_CONST;
    }
    this -> data = new T[allocated];
    for(int i = 0; i < this -> size; ++i) {
        this -> data[i] = T();
    }
}
template < class T > 
Vector < T > :: Vector(unsigned int size, const T &value) : size(size), allocated(1) {
    while(allocated < size) {
        allocated *= ALLOC_CONST;
    }
    this -> data = new T[allocated];

    for(int i = 0; i < size; ++i) {
        this -> data[i] = value;
    }
}
template < class T > 
Vector < T > :: Vector(const Vector < T > &other) {
    this -> size = other.size;
    this -> allocated = other.allocated;
    this -> data = new T[allocated];
    for(int i = 0; i < this -> size; ++i) {
        this -> data[i] = other.data[i];
    }
}


template < class T > 
std::istream& operator >> (std::istream &in, Vector < T > &vec) {
    vec.Clear();
    unsigned int elements;
    in >> elements;
    
    for(unsigned int i = 0; i < elements; ++i) {
        T temp;
        in >> temp;
        vec.Push_Back(temp);
    }
    return in;
}
template < class T > 
std::ostream& operator << (std::ostream &out, const Vector < T > &vec) {
    out << "Vector size: " << vec.size << "\n";
    out << "Elements: ";
    for(int i = 0; i < vec.size; ++i) {
        out << vec.data[i] << " ";
        if(i) out << "* X^" << i << " ";
        if(i < vec.size - 1) out << "+ ";
    }
    return out;
}


template < class T > 
unsigned int Vector < T > :: getSize() const {
    return this -> size;
}
template < class T > 
bool Vector < T > :: isEmpty() const {
    return (this -> size == 0);
}
template < class T > 
void Vector < T > :: Resize(const unsigned int &size) {
    this -> size = size;
    if(this -> size > this -> allocated) {
        while(this -> size > this -> allocated) {
            this -> allocated *= ALLOC_CONST;
        }    
        T *temp = new T[this -> allocated];
        for(int i = 0; i < this -> size - 1; ++i) {
            temp[i] = this -> data[i];
        }
        
        delete[] this -> data;
        this -> data = temp;
    }
}
template < class T >
void Vector < T > :: Push_Back(const T &value) {
    this -> Resize(this -> size + 1);
    this -> data[this -> size - 1] = value;
}
template < class T > 
void Vector < T > :: Pop_Back() {
    if(this -> isEmpty()) {
        std::cout << "Vector is empty\n";
        exit(0);
    }
    this -> size -= 1;
}
template < class T > 
void Vector < T > :: Clear() {
    this -> size = 0;
    this -> allocated = 1;
    delete[] this -> data;
    this -> data = new T[allocated];
}


template < class T >
T& Vector < T > :: operator [] (const int &pos) const {
    if(pos < 0 || pos >= size) {
        std::cout << "Invalid position!";
        exit(0);
    }
    return this -> data[pos];
}
template < class T >
Vector < T > Vector < T > :: operator * (const Vector < T > &other) const {
    Vector < T > temp(this -> size + other.size - 1);
    for(int i = 0; i < this -> size; ++i) {
        for(int j = 0; j < other.size; ++j) {
            temp.data[i + j] += (this -> data[i] * other.data[j]);
        }
    }

    return temp;
}
template < class T >
Vector < T > Vector < T > :: operator - () const {
    Vector < T > temp(*this);
    for(int i = 0; i < temp.size; ++i) {
        temp.data[i] *= -1;
    }

    return temp;
}
template < class T > 
Vector < T >& Vector < T > :: operator = (const Vector < T > &other) {
    this -> Clear();
    this -> size = other.size;
    this -> Resize(this -> size);

    for(int i = 0; i < this -> size; ++i) {
        this -> data[i] = other.data[i];
    }

    return *this;
}
template < class T > 
Vector < T > Vector < T > :: operator + (const Vector < T > &other) const {
    unsigned int mxSize = std::max(this -> size, other.size);
    Vector < T > temp(mxSize, 0);

    for(int i = 0; i < mxSize; ++i) {
        if(i < this -> size) temp.data[i] += this -> data[i];
        if(i < other.size) temp.data[i] += other.data[i];
    }

    return temp;
}
template < class T >
Vector < T > Vector < T > :: operator - (const Vector < T > &other) const {
    unsigned int mxSize = std::max(this -> size, other.size);
    Vector < T > temp(mxSize, 0);

    for(int i = 0; i < mxSize; ++i) {
        if(i < this -> size) temp.data[i] += this -> data[i];
        if(i < other.size) temp.data[i] -= other.data[i];
    }

    return temp;
}
template < class T > 
bool Vector < T > :: operator == (const Vector < T > &other) const {
    if(this -> size != other.size) return false;

    for(int i = 0; i < this -> size; ++i) {
        if(this -> data[i] != other.data[i]) {
            return false;
        }
    }

    return true;
}
template < class T > 
bool Vector < T > :: operator != (const Vector < T > &other) const {
    return !(*this == other);
}
template < class T >
bool Vector < T > :: operator < (const Vector < T > &other) const {
    if(this -> size < other.size) return true;
    if(this -> size > other.size) return false;
    for(int i = this -> size - 1; i >= 0; --i) {
        if(this -> data[i] < other.data[i]) return true;
        if(this -> data[i] > other.data[i]) return false;
    }

    return false;
}
