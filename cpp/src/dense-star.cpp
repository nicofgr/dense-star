#include "../include/dense-star.hpp"


const long double pi = M_PIl;  // pi
const long double c = 2.99792458e23;  // [fm/s]  speed of light
const long double hbar = 6.58211915e-25;  // [GeV]  planck constant
//long double G = 6.67408e-11;
//long double mSol = 1.989e30;  // kg
//const long double B = pow(0.155, 4);  // [GeV^4]  pressao de sacola
const long double n0 = 1.2277e-3;  // [GeV^3]  densidade barionica nuclear
long double mi = 1e-3;  // [mSol]
long double r, m;  //  [km] raio, [Msol] massa
long double p, e;  // [GeV^4]  pressao, densidade de energia
long double n, nc;  // [GeV^3]  densidade barionica, densidade bariona central
    
DenseStar::DenseStar(double nc, double B, unsigned int numQuarks) : nc(nc*n0), B(pow(B, 4)), numQuarks(numQuarks){
    nc = 5*n0;  
    n = nc;
    //p = ((3*pow(pi, 2/3.)*pow(n,4/3.))/4) - this->B;
    p = ( ((numQuarks*pow(pi, 2/3.))/4) *pow(3*n/numQuarks,4/3.)) - this->B;
    e = 3*p + 4*this->B;
    r = 0;
    m = 0;
}

void DenseStar::SaveDataToFile(std::string fileName){
    nc = 5*n0;  
    n = nc;
    p = ( ((numQuarks*pow(pi, 2/3.))/4) *pow(3*n/numQuarks,4/3.)) - this->B;
    e = 3*p + 4*this->B;
    r = 0;
    m = 0;
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
    const long double dr = 1e-3;  // [km]  passo do raio
    r += dr;
    p += ((-R0*e*m*dr)/pow(r,2)) * (1+p/e)*(1+4*pi*pow(r,3)*p*M0/mi)/(1-2*R0*m/r);  // int TOV
    m += (4*pi*pow(r,2)*e*dr*M0)/pow(hbar*c,3);  // int da massa
    mi = m;
    e = 3*p + 4*B;
}

void DenseStar::setNumQuarks(unsigned int numQuarks){
    this->numQuarks = numQuarks;
}

void DenseStar::setBagPressure(long double B){
    this->B = B;
}
