#include <bits/stdc++.h>
#include "Company.h"

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const string BIKE = "bike";
const string CAR = "car";
const string TRUCK = "truck";

int main() {
    Company comp;
    fin >> comp;
    comp.Solve();
    return 0;
}