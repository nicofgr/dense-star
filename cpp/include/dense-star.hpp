#ifndef DENSE_STAR_INCLUDED
#define DENSE_STAR_INCLUDED
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

class DenseStar{
  private:
    const long double R0 = 1.47611;
    const long double M0 = 8.9616e-4;
    const long double n0 = 1.2277e-3;  // Densidade Bariônica
    long double B;  // Pressão de Sacola
    long double nc;  // Densidade Bariônica Central
    unsigned int numQuarks;
  public:
    DenseStar(double nc, double B, unsigned int numQuarks);
    void SaveDataToFile(std::string fileName);
    void UpdateRPME(long double &r, long double &p, long double &m, long double &e);
    void setNumQuarks(unsigned int numQuarks);
    void setBagPressure(long double B);


};

#endif
