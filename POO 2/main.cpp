#include <bits/stdc++.h>
#include "Vector.h"
#include "Polynomial.h"

using namespace std;

ifstream fin("input.txt");

int main() {
    
    Polynomial < double > A, B, C;
    fin >> A >> B >> C;
    cout << A << "\n" << B << "\n" << C << "\n";

    Polynomial < double > E, F, G;
    E = A + B;
    F = A - B;
    G = A * B;
    cout << E << "\n" << F << "\n" << G << "\n";
    cout << (A == B) << "\n";
    cout << (A != B) << "\n";

    Polynomial < double > H, I;
    H = A / B;
    I = A % B;
    cout << H << "\n" << I << "\n";

    bool test = A == A / B * B + A % B;
    cout << test << endl;

    return 0;
}