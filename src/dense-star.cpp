#include "../include/dense-star.hpp"


const long double pi = M_PIl;
const long double c = 2.99792458e23;  // fm/s
const long double hbar = 6.58211915e-25;  // GeV
//long double G = 6.67408e-11;
//long double mSol = 1.989e30;  // kg
//double B = pow(0.185, 4);  // GeV^4
const long double B = pow(0.155, 4);  // GeV^4
const long double n0 = 1.2277e-3;  // GeV^3
const long double dr = 1e-3;  // km
long double mi = 1e-3;  // mSol
long double r, m;
long double p, e;  // GeV^4
long double n, nc;  // GeV^3
    
DenseStar::DenseStar(double nc, double B) : nc(nc*n0), B(pow(B, 4)) {
    nc = 5*n0;
    n = nc;
    p = ((3*pow(pi, 2/3.)*pow(n,4/3.))/4) - this->B;
    e = 3*p + 4*this->B;
    r = 0;
    m = 0;
}

void DenseStar::SaveDataToFile(std::string fileName){
    std::ofstream file("../output/" + fileName);
    file << std::scientific << std::setprecision(10);
    file << r << ' ';
    file << (p*1e3)/pow(hbar*c,3) << ' ';
    file << m << ' ';
    file << (e*1e3)/pow(hbar*c,3) << '\n';
    while(p > 0){
        UpdateRPME(r, p, m, e);
        file << r << ' ';
        file << (p*1e3)/pow(hbar*c,3) << ' ';
        file << m << ' ';
        file << (e*1e3)/pow(hbar*c,3) << '\n';
    }
    file.close();
}

void DenseStar::UpdateRPME(long double &r, long double &p, long double &m, long double &e){
    r += dr;
    p += ((-R0*e*m*dr)/pow(r,2)) * (1+p/e)*(1+4*pi*pow(r,3)*p*M0/mi)/(1-2*R0*m/r);  // int TOV
    m += (4*pi*pow(r,2)*e*dr*M0)/pow(hbar*c,3);  // int da massa
    mi = m;
    e = 3*p + 4*B;
}