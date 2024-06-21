#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "../include/dense-star.hpp"

int main(){

    DenseStar star(5, 0.155);
    star.SaveDataToFile("cpp.dat");

    return 0;
}
