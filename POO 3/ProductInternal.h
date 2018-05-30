#ifndef PRODUCTINTERNAL_H
#define PRODUCTINTERNAL_H

#include <bits/stdc++.h>

class Product {
public:
    int startTime, endTime, sX, sY, eX, eY;
    bool needColdSupport;

    Product();
    Product(int, int, bool);

    friend std::ostream& operator << (std::ostream &, const Product &);
    friend std::istream& operator >> (std::istream &, Product &);
};

#endif