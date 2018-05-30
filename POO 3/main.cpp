#include <bits/stdc++.h>
#include "Common.h"
#include "Product.h"

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const string BIKE = "bike";
const string CAR = "car";
const string TRUCK = "truck";

int main() {
    int vehicleNum;
    fin >> vehicleNum;

    Vehicle **v = new Vehicle*[vehicleNum];
    for(int i = 0; i < vehicleNum; ++i) {
        v[i] = NULL;
    }
    
    for(int i = 0; i < vehicleNum; ++i) {
        readKnownVehicleType(fin, &v[i]);
    }

    int prodNum;
    fin >> prodNum;

    vector < Product > p(prodNum);
    vector < int > idx(prodNum);
    for(int i = 0; i < prodNum; ++i) {
        fin >> p[i];
        idx[i] = i;
    }

    sort(idx.begin(), idx.end(), [&](const int &a, const int &b) {
        return p[a].endTime < p[b].endTime;
    });

    for(int i = 0; i < prodNum; ++i) {
        bool flag = false;
        for(int j = 0; j < vehicleNum; ++j) {
            if((*v[j]).CanDeliver(p[idx[i]])) {
                (*v[j]).Update(p[idx[i]]);
                cout << "Vehiculul " << j << " se ocupa de comanda cu indexul " << idx[i] << "\n";
                cout << *v[j];
                flag = true;
                break;
            }
        }

        if(flag == false) {
            cout << "Comanda cu indexul " << idx[i] << " nu a putut fi preluata! Ne cerem scuze.\n";
        }
    }
    return 0;
}