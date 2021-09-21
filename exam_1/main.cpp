
// HandIn 1 by XXX
// Student id :  ....

#include <iostream>
#include <random>
#include <string>
#include "gaussian_header.hpp"
#include "randomGenerator.h"
#include "TemplatedRNG.h"

//double BFunction(double kappa, double b1) {
//    return kappa * b1 - 1;
//}
//
//double AFunction(double kappa, double theta, double b1, double sigma, double b2) {
//    return -kappa * theta * b1 - 0.5 * sigma * b2;
//}
//
//double rungeKutta(double r, double kappa, double theta, double sigma, double T) {
//    double A = AFunction(kappa, theta, ;
//    double B = 0;
//}

int main() {

    // Question 1.

    // Problem 1
    std::cout << "---  Q1.P1  --- \n" << std::endl;

    // Here is some code that initializes a MT object with seed 1 
    //and outputs a random number as well as min and max values...

    std::mt19937 random_number_mt_;
    random_number_mt_.seed(1);
    std::cout << "Random value: " << random_number_mt_() << std::endl;
    std::cout << "Min value: " << random_number_mt_.min() << std::endl;
    std::cout << "Max value: " << random_number_mt_.max() << std::endl;

    // Problem 2.
    MTRNG RandNumber(1); // Initialisation of MTRNG class


    // Problem 3.
    std::cout << "---  Q1.P3  --- \n";
    // Output related to problem 3.
    std::cout << "Uniform Random Number: " << RandNumber() << std::endl;

    // Problem 4.
    std::cout << "---  Q1.P4  --- \n";
    // Output related to problem 4.
    RandNumber.setSeed(2);
    std::cout << RandNumber() << std::endl;
    RandNumber.setSeed(2);
    std::cout << RandNumber() << std::endl;

    // Problem 5.
    std::cout << "---  Q1.P5  --- \n";
    // Output related to problem 5.
    RandNumber.setSeed(1);
    std::cout << RandNumber(1, 2) << std::endl;

    // Problem 7.
    std::cout << "---  Q1.P7  --- \n";
    // Output related to problem 7.
    RandNumber.setSeed(1);
    std::cout << RandNumber.genNormal() << std::endl;


    // Problem 8.
    std::cout << "---  Q1.P8  --- \n";
    // Output related to problem 8.
    std::mt19937 random_number_mt;
    random_number_mt.seed(10);
    MTRNG RandNumber2(random_number_mt);
    std::cout << RandNumber2.genNormal() << std::endl;

    // Problem 9.
    std::cout << "---  Q1.P9  --- \n";
    // Output related to problem 9.
    MTRNG RandNumber3(1, 5);
    RandNumber3.setSeed(1);
    std::cout << "Dimension for vector: " << RandNumber3.getDim() << std::endl;
    std::vector<double> randVector(RandNumber3.getDim());
    RandNumber3.genNormal(randVector);
    for (int i = 0; i < 5; i++) {
        std::cout << randVector[i] << std::endl;
    }

    // Problem 10.
    std::cout << "---  Q1.P10  --- \n";
    // Output related to problem 10.
    RandNumber2.setSeed(1);
    MTRNG RandNumber4(RandNumber2);
    std::cout << "Copied: " << RandNumber4.genNormal() << std::endl;

    // Problem 11.
    std::cout << "---  Q1.P11  --- \n";
    // Output related to problem 11.
    //std::mt19937 random_number_mt;
    TemplatedRNG<std::mt19937> TemplatedRandNumMT(1);
    std::cout << "Std. Uniform from MT: " << TemplatedRandNumMT.genUniform() << std::endl;

    TemplatedRNG<std::mt19937> TemplatedRandNumOverloadedMT(random_number_mt, 1);
    std::cout << "Std. Uniform from MT using the overloaded: " << TemplatedRandNumOverloadedMT.genUniform() << std::endl;

    TemplatedRNG<std::minstd_rand> TemplatedRandNumMR(1);
    std::cout << "Std. Uniform from MINSTD using the overloaded: " << TemplatedRandNumMR.genUniform() << std::endl;

    std::minstd_rand random_number_mr;
    std::cout << "random: " << random_number_mr() << "max: " << random_number_mr.max();
    TemplatedRNG<std::minstd_rand> TemplatedRandNumOverloadedMR(random_number_mr, 1);
    std::cout << "Std. Uniform from MINSTD using the overloaded: " << TemplatedRandNumOverloadedMR.genUniform() << std::endl;
    //std::cout << "Std. Uniform from MT using the overloaded: " << random_number_mr.max() << std::endl;

    // Question 2.

        // Problem 1.
    std::cout << "---  Q2.P1  --- \n";

    //...


    return 0;
}
