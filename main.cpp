#include <iostream>
#include <cmath>
#include <fstream>

int main(){
    double pi = M_PI;
    double c = 2.99792458e23;  // fm/s
    double hbar = 6.58211915e-25;  // GeV
    double G = 6.67408e-11;
    double mSol = 1.989e30;  // kg
    double RO = 1.47611;  // km
    double MO = 8.9616e-4;  // GeV
    double B = pow(0.185, 4);  // GeV^4
    double nO = 1.2277e-3;  // GeV^3
    double r, dr = 1e-3;  // km
    double m, mi = 1e-3;  // mSol
    double p, e;  // GeV^4
    double n, nc;  // GeV^3
    
    //Condicoes Iniciais
    nc = 8*nO;
    n = nc;
    p = (3*pow(pi, 2/3)*pow(n,4/3))/4 - B;
    e = 3*p + 4*B;
    r = 0;
    m = 0;

    std::ofstream file("data.dat");
    file << r << ' ';
    file << (p*1e3)/pow(hbar*c,3) << ' ';
    file << m << ' ';
    file << (e*1e3)/pow(hbar*c,3) << '\n';

    while(p > 0){
        r += dr;
        p += ((-RO*e*m*dr)/pow(r,2)) * (1+p/e)*(1+4*pi*pow(r,3)*p*MO/mi)/(1-2*RO*m/r);  // int TOV
        m += (4*pi*pow(r,2)*e*dr*MO)/pow(hbar*c,3);  // int da massa
        mi = m;
        e = 3*p + 4*B;
        file << r << ' ';
        file << (p*1e3)/pow(hbar*c,3) << ' ';
        file << m << ' ';
        file << (e*1e3)/pow(hbar*c,3) << '\n';
    }

    file.close();
    return 0;
}
