#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

class Polynomial {
    int degree;
    double *coefficients;
public:
    friend istream& operator >> (istream &, Polynomial &);
    friend ostream& operator << (ostream &, Polynomial &);

    void Equilibrate() {
        while(degree > 0 && coefficients[degree] == 0) --degree;
    }
    Polynomial operator + (const Polynomial &other) {
        Polynomial temp;
        temp.degree = max(degree, other.degree);
        temp.coefficients = new double[temp.degree + 1];

        for(int i = 0; i <= temp.degree; ++i) {
            if(i <= degree) temp.coefficients[i] += coefficients[i];
            if(i <= other.degree) temp.coefficients[i] += other.coefficients[i];     
        }

        temp.Equilibrate();
        return temp;
    }
    Polynomial operator - (const Polynomial &other) {
        Polynomial temp;
        temp.degree = max(degree, other.degree);
        temp.coefficients = new double[temp.degree + 1];

        for(int i = 0; i <= temp.degree; ++i) {
            if(i <= degree) temp.coefficients[i] += coefficients[i];
            if(i <= other.degree) temp.coefficients[i] -= other.coefficients[i];     
        }

        temp.Equilibrate();
        return temp;
    }
    Polynomial operator * (const Polynomial &other) {
        Polynomial temp;
        temp.degree = degree + other.degree;
        temp.coefficients = new double[temp.degree + 1];

        for(int i = 0; i <= degree; ++i) {
            for(int j = 0; j <= other.degree; ++j) {
                temp.coefficients[i + j] += coefficients[i] * other.coefficients[j]; 
            }  
        }

        temp.Equilibrate();
        return temp;
    }
    Polynomial operator / (const Polynomial &other) {
        if(other.degree > degree) {
            fout << "Polynomials can`t be divided. Degree incompatibility.\n";
            exit(0);
        }
        if(other.degree == 0 && other.coefficients[0] == 0) {
            fout << "Polynomials can`t be divided. Null divisor.\n";
            exit(0);
        }

        Polynomial temp;
        temp.degree = degree - other.degree;
        for(int )
    }

    double ValueOnPoint(double point) {
        double value = 0;
        double x = 1;

        for(int i = 0; i <= degree; ++i) {
            value = value + x * coefficients[i];
            x *= point;
        }

        return value;
    }
};
ostream& operator << (ostream &out, Polynomial &polynomial) {
    out << "Polynomial degree is " << polynomial.degree << "\n";
    for(int i = polynomial.degree; i > 0; --i) {
        out << "(" << polynomial.coefficients[i] << ") * x^" << i << " + ";
    }
    out << "(" << polynomial.coefficients[0] << ")";
    return out;
}
istream& operator >> (istream &in, Polynomial &polynomial) {
    in >> polynomial.degree;
    polynomial.coefficients = new double[polynomial.degree + 1];
    for(int i = 0; i <= polynomial.degree; ++i) {
        in >> polynomial.coefficients[i];
    }
    polynomial.Equilibrate();

    return in;
}

int main() {
    int polynomialNumber;
    fin >> polynomialNumber;

    Polynomial *polynomials = new Polynomial[polynomialNumber];  
    for(int i = 0; i < polynomialNumber; ++i) {
        fin >> polynomials[i];
    }  
    for(int i = 0; i < polynomialNumber; ++i) {
        fout << polynomials[i] << "\n";
    }
    polynomials[0] = polynomials[0] - polynomials[1] * polynomials[2];
    fout << polynomials[0] << "\n";

    delete[] polynomials;
    return 0;
}