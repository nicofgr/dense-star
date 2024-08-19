#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "../include/dense-star.hpp"

int main(){

    DenseStar star(5, 0.145, 2);
    star.SaveDataToFile("udB145.dat");
    star.setNumQuarks(3);
    star.SaveDataToFile("udsB145.dat");
    star.setNumQuarks(4);
    star.SaveDataToFile("udscB145.dat");
    star.setNumQuarks(5);
    star.SaveDataToFile("udscbB145.dat");
    star.setNumQuarks(6);
    star.SaveDataToFile("udscbtB145.dat");
    DenseStar star2(5, 0.155, 2);
    star2.SaveDataToFile("udB155.dat");
    star2.setNumQuarks(3);
    star2.SaveDataToFile("udsB155.dat");
    star2.setNumQuarks(4);
    star2.SaveDataToFile("udscB155.dat");
    star2.setNumQuarks(5);
    star2.SaveDataToFile("udscbB155.dat");
    star2.setNumQuarks(6);
    star2.SaveDataToFile("udscbtB155.dat");
    DenseStar star3(5, 0.165, 2);
    star3.SaveDataToFile("udB165.dat");
    star3.setNumQuarks(3);
    star3.SaveDataToFile("udsB165.dat");
    star3.setNumQuarks(4);
    star3.SaveDataToFile("udscB165.dat");
    star3.setNumQuarks(5);
    star3.SaveDataToFile("udscbB165.dat");
    star3.setNumQuarks(6);
    star3.SaveDataToFile("udscbtB165.dat");
    DenseStar star4(5, 0.175, 2);
    star4.SaveDataToFile("udB175.dat");
    star4.setNumQuarks(3);
    star4.SaveDataToFile("udsB175.dat");
    star4.setNumQuarks(4);
    star4.SaveDataToFile("udscB175.dat");
    star4.setNumQuarks(5);
    star4.SaveDataToFile("udscbB175.dat");
    star4.setNumQuarks(6);
    star4.SaveDataToFile("udscbtB175.dat");

    return 0;
}
