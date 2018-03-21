#include <bits/stdc++.h>
#include "Polynomial.h"
#include "Pair.h"

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    int polynomialNumber;
    fin >> polynomialNumber;

    Polynomial<double> *polynoms = new Polynomial<double>[polynomialNumber];
    for(int i = 0; i < polynomialNumber; ++i) {
        fin >> polynoms[i];
    }

    int pairNumber;
    fin >> pairNumber;

    Pair<double> *pairs = new Pair<double>[pairNumber];
    for(int i = 0; i < pairNumber; ++i) {
        fin >> pairs[i];
    }

    for(int i = 0; i < polynomialNumber; ++i) {
        fout << polynoms[i] << "\n";
    }
    if(polynomialNumber >= 2) {
        Polynomial<double> p = polynoms[0] + polynoms[1];
        fout << "SUM\n" << p << "\n";
        p = polynoms[0] - polynoms[1];
        fout << "DIF\n" << p << "\n";
        p = polynoms[0] / polynoms[1];
        fout << "DIV\n" << p << "\n";
        p = polynoms[0] * polynoms[1];
        fout << "MUL\n" << p << "\n";
        p = polynoms[0] % polynoms[1];
        fout << "MOD\n" << p << "\n";
    }
    for(int i = 0; i < pairNumber; ++i) {
        fout << pairs[i] << "\n";
    }
    for(int i = 0; i < pairNumber; ++i) {
        if(pairs[i].IsRoot()) {
            cout << "Value " << pairs[i].GetValue() << " is root.\n";
        } else {
            cout << "Value " << pairs[i].GetValue() << " is NOT root.\n";
        }
    }
    return 0;
}