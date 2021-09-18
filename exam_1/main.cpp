
// HandIn 1 by XXX
// Student id :  ....

#include <iostream>
#include "gaussian_header.hpp"
#include "randomGenerator.h"
#include <random>
#include <string>

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
    MTRNG RandNumber(1); // Here I initialize my class, there is no output so cout is not needed.
    // There are though  questions  answered in a seperate pdf file.

    // Problem 3.
    std::cout << "---  Q1.P3  --- \n";
    // Output related to problem 3.
    std::cout << "Uniform Random Number: " << RandNumber.genUniform() << std::endl;

    // Problem 4.
    std::cout << "---  Q1.P4  --- \n";
    // Output related to problem 4.
    RandNumber.setSeed(2);
    std::cout << RandNumber.genUniform() << std::endl;
    RandNumber.setSeed(2);
    std::cout << RandNumber.genUniform() << std::endl;

    // Problem 5.
    std::cout << "---  Q1.P5  --- \n";
    // Output related to problem 5.
    RandNumber.setSeed(1);
    std::cout << RandNumber.genUniform(1, 2) << std::endl;

    // Problem 7.
    std::cout << "---  Q1.P7  --- \n";
    // Output related to problem 7.
    RandNumber.setSeed(1);
    std::cout << RandNumber.genNormal() << std::endl;

    // Problem 7.
    std::cout << "---  Q1.P7  --- \n";
    // Output related to problem 7.
    RandNumber.setSeed(1);
    std::cout << RandNumber.genNormal() << std::endl;

    // Problem 8.
    std::cout << "---  Q1.P8  --- \n";
    // Output related to problem 8.
    MTRNG RandNumber2(10);
    std::uint_fast32_t RandMTSeed10 = RandNumber2.getMTRNG();
    std::cout << RandNumber2.genNormal(RandMTSeed10) << std::endl;


    // Question 2.

        // Problem 1.
    std::cout << "---  Q2.P1  --- \n";

    //...


    return 0;
}
