#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "../include/dense-star.hpp"

int main(){
    /**
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
    **/
    DenseStar star(2, 0.145, 2);
    star.SaveDataToFile("P3ud145.dat");
    star.setNumQuarks(3);
    star.SaveDataToFile("P3uds145.dat");
    star.setNumQuarks(4);
    star.SaveDataToFile("P3udsc145.dat");
    star.setNumQuarks(5);
    star.SaveDataToFile("P3udscb145.dat");
    star.setNumQuarks(6);
    star.SaveDataToFile("P3udscbt145.dat");
    
    DenseStar star3(2, 0.155, 2);
    star3.SaveDataToFile("P3ud155.dat");
    star3.setNumQuarks(3);
    star3.SaveDataToFile("P3uds155.dat");
    star3.setNumQuarks(4);
    star3.SaveDataToFile("P3udsc155.dat");
    star3.setNumQuarks(5);
    star3.SaveDataToFile("P3udscb155.dat");
    star3.setNumQuarks(6);
    star3.SaveDataToFile("P3udscbt155.dat");

    DenseStar star165(2, 0.165, 2);
    star165.SaveDataToFile("P3ud165.dat");
    star165.setNumQuarks(3);
    star165.SaveDataToFile("P3uds165.dat");
    star165.setNumQuarks(4);
    star165.SaveDataToFile("P3udsc165.dat");
    star165.setNumQuarks(5);
    star165.SaveDataToFile("P3udscb165.dat");
    star165.setNumQuarks(6);
    star165.SaveDataToFile("P3udscbt165.dat");

    DenseStar star2(2, 0.175, 2);
    star2.SaveDataToFile("P3ud175.dat");
    star2.setNumQuarks(3);
    star2.SaveDataToFile("P3uds175.dat");
    star2.setNumQuarks(4);
    star2.SaveDataToFile("P3udsc175.dat");
    star2.setNumQuarks(5);
    star2.SaveDataToFile("P3udscb175.dat");
    star2.setNumQuarks(6);
    star2.SaveDataToFile("P3udscbt175.dat");
    return 0;
}
