#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "../include/dense-star.hpp"

int main(){

    DenseStar star(5, 0.155, 2);
    star.SaveDataToFile("ud.dat");
    star.setNumQuarks(3);
    star.SaveDataToFile("uds.dat");
    star.setNumQuarks(4);
    star.SaveDataToFile("udsc.dat");
    star.setNumQuarks(5);
    star.SaveDataToFile("udscb.dat");
    star.setNumQuarks(6);
    star.SaveDataToFile("udscbt.dat");

    return 0;
}
