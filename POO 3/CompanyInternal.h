#ifndef COMPANYINTERNAL_H
#define COMPANYINTERNAL_H
#include "Common.h"
#include "Product.h"
#include <bits/stdc++.h>

class Company {
private:
    int vehNum, prodNum;
    std::vector < Vehicle* > veh;
    std::vector < Product > prod;
public:
    ~Company();
    Company();
    Company(int, int);
    Company(const Company &);

    friend std::ostream& operator << (std::ostream &, const Company &);
    friend std::istream& operator >> (std::istream &, Company &);

    void addProduct(const Product &);
    void Solve();

    Company& operator = (const Company &);
};

#endif