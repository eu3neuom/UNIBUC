#ifndef PRODUCTINTERNAL_H
#define PRODUCTINTERNAL_H

#include <bits/stdc++.h>

class Product {
public:
    int startTime, endTime, sX, sY, eX, eY;
    bool needColdSupport;

    Product();
    Product(int, int, bool);
    Product(const Product &);

    friend std::ostream& operator << (std::ostream &, const Product &);
    friend std::istream& operator >> (std::istream &, Product &);

    Product& operator = (const Product &other);
};

#endif