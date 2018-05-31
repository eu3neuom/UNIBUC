#include <bits/stdc++.h>
#include "CompanyInternal.h"

Company::~Company() {
    veh.clear();
    prod.clear();
}

Company::Company() {

}

Company::Company(int vn, int pn) : vehNum(vn), prodNum(pn), veh(vn), prod(pn) {

}

Company::Company(const Company &other) {
    vehNum = other.vehNum;
    prodNum = other.prodNum;
    veh = other.veh;
    prod = other.prod;
}

std::ostream& operator << (std::ostream &out, const Company &other) {
    out << "Compania are " << other.vehNum << " masini si " << other.prodNum << " produse de livrat.\n";
    out << "Masinile sunt:\n";
    for(int i = 0; i < other.vehNum; ++i) {
        out << *other.veh[i] << "\n";
    }
    out << "Produsele sunt:\n";
    for(int i = 0; i < other.prodNum; ++i) {
        out << other.prod[i] << "\n";
    }

    return out;
}

std::istream& operator >> (std::istream &in, Company &other) {
    in >> other.vehNum >> other.prodNum;
    other.veh.resize(other.vehNum);
    other.prod.resize(other.prodNum);

    for(int i = 0; i < other.vehNum; ++i) {
        readKnownVehicleType(in, &other.veh[i]);
    }
    for(int i = 0; i < other.prodNum; ++i) {
        in >> other.prod[i];
    }

    return in;
}

void Company::addProduct(const Product &pr) {
    ++prodNum;
    prod.push_back(pr);
}

void Company::Solve() {
    std::vector < int > idx(prodNum);
    for(int i = 0; i < prodNum; ++i) {
        idx[i] = i;
    }

    sort(idx.begin(), idx.end(), [&](const int &a, const int &b) {
        return prod[a].endTime < prod[b].endTime;
    });

    for(int i = 0; i < prodNum; ++i) {
        bool flag = false;
        for(int j = 0; j < vehNum; ++j) {
            if((*veh[j]).CanDeliver(prod[idx[i]])) {
                (*veh[j]).Update(prod[idx[i]]);
                std::cout << "Vehiculul " << j << " se ocupa de comanda cu indexul " << idx[i] << "\n";
                std::cout << *veh[j];
                flag = true;
                break;
            }
        }

        if(flag == false) {
            std::cout << "Comanda cu indexul " << idx[i] << " nu a putut fi preluata! Ne cerem scuze.\n";
        }
    }
}

Company& Company::operator= (const Company &other) {
    veh.clear(); prod.clear();
    this -> vehNum = other.vehNum;
    this -> prodNum = other.prodNum;
    this -> veh = other.veh;
    this -> prod = other.prod;
    return *this;
}