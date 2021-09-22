
// HandIn 1 by XXX
// Student id :  ....

#include <iostream>
#include <random>
#include <string>
#include <cmath>
#include "gaussian_header.hpp"
#include "randomGenerator.h"
#include "TemplatedRNG.h"
#include "RungeKutta.h"
#include "Vasicek.h"
#include "SABR.h"


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
    //std::cout << "random: " << random_number_mr() << "max: " << random_number_mr.max();
    TemplatedRNG<std::minstd_rand> TemplatedRandNumOverloadedMR(random_number_mr, 1);
    std::cout << "Std. Uniform from MINSTD using the overloaded: " << TemplatedRandNumOverloadedMR.genUniform() << std::endl;
    //std::cout << "Std. Uniform from MT using the overloaded: " << random_number_mr.max() << std::endl;

    // Question 2.

    // Problem 3.
    std::cout << "---  Q2.P3  --- \n";
    double r = 0.02;
    double kappa = 0.3;
    double theta = 0.03;
    double sigma = 0.01;
    double T = 1;
    double stepLength = 0.01;
    double rkSolution = rungeKutta(r, kappa, theta, sigma, T, stepLength);
    std::cout << "Vasicek Bond Value using Runke Kutta: " << rkSolution << std::endl;

    // Problem 4.
    std::cout << "---  Q2.P4  --- \n";
    Vasicek GetVasicek(r, kappa, theta, sigma, stepLength);
    std::cout << "r: " << GetVasicek.getR() << std::endl;
    std::cout << "Kappa: " << GetVasicek.getKappa() << std::endl;
    std::cout << "Theta: " << GetVasicek.getTheta() << std::endl;
    std::cout << "Sigma: " << GetVasicek.getSigma() << std::endl;
    std::cout << "Step Length: " << GetVasicek.getStepLength() << std::endl;

    // Problem 5.
    std::cout << "---  Q2.P5  --- \n";
    std::cout << "Overloaded pricing functions price: " << rungeKutta(GetVasicek) << std::endl;

    // Problem 10.
    std::cout << "---  Q2.P5  --- \n";
    double rkSolutionCir = rungeKuttaCir(r, kappa, theta, sigma, T, stepLength);
    std::cout << "Cir Bond Value using Runke Kutta: " << rkSolutionCir << std::endl;

    // Question 3.
    // Problem 1.
    std::cout << "---  Q3.P1  --- \n";
    std::cout.std::ios_base::precision(12);
    std::cout << "From function normalCdf(0.225): "  << normalCdf(0.225) << std::endl;
    std::cout << "From function normalCdf(0.775): " << normalCdf(0.775) << std::endl;

    // Problem 1.
    std::cout << "---  Q3.P2  --- \n";
    double S0 = 90.0;
    double K = 100.0;
    double sigma0 = 1.3;
    double alpha = 0.5;
    double beta = 0.5;
    double rho = -0.5;
    T = 3.0;

    SABR SABRObj(S0, K, sigma0, alpha, beta, rho, T);
    std::cout << "SABR BS Call price: " << SABRObj.blackScholesSABR() << std::endl;

    return 0;
}
