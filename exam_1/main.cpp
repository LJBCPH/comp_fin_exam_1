
// HandIn 1 by XXX
// Student id :  kzx651

#include <iostream>
#include <random>
#include <string>
#include <cmath>
#include "gaussian_header.hpp"
//#include "randomGenerator.h"
#include "TemplatedRNG.h"
#include "RungeKutta.h"
#include "Vasicek.h"
#include "SABR.h"
#include "ZeroCouponBond.h"
#include "VasicekBond.h"
#include "CIR.h"
#include "CirBond.h"
#include "Portfolio.h"
#include "MTRNG.h"
#include "CallOption.h"
#include "MC_SABR.h"

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
    std::cout << "Max value: " << random_number_mt_.max() << "\n" << std::endl;

    // Problem 2.
    MTRNG RandNumber(1); // Initialisation of MTRNG class

    // Problem 3.
    std::cout << "---  Q1.P3  --- \n";
    // Output related to problem 3.
    std::cout << "Uniform Random Number: " << RandNumber() << "\n" << std::endl;

    // Problem 4.
    std::cout << "---  Q1.P4  --- \n";
    // Output related to problem 4.
    RandNumber.setSeed(2);
    std::cout << RandNumber() << std::endl;
    RandNumber.setSeed(2);
    std::cout << RandNumber() << "\n" << std::endl;

    // Problem 5.
    std::cout << "---  Q1.P5  --- \n";
    // Output related to problem 5.
    RandNumber.setSeed(1);
    std::cout << RandNumber(1, 2) << "\n" << std::endl;

    // Problem 7.
    std::cout << "---  Q1.P7  --- \n";
    // Output related to problem 7.
    RandNumber.setSeed(1);
    std::cout << RandNumber.genNormal() << "\n" << std::endl;

    // Problem 8.
    std::cout << "---  Q1.P8  --- \n";
    // Output related to problem 8.
    std::mt19937 random_number_mt;
    random_number_mt.seed(10);
    MTRNG RandNumber2(random_number_mt);
    std::cout << RandNumber2.genNormal() << "\n" << std::endl;

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
    std::cout << "Copied: " << RandNumber4.genNormal() << "\n" << std::endl;

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
    std::cout << "Std. Uniform from MINSTD using the overloaded: " << TemplatedRandNumOverloadedMR.genUniform() << "\n" << std::endl;
    //std::cout << "Std. Uniform from MT using the overloaded: " << random_number_mr.max() << std::endl;

    /*
    * 
    *  Question 2.
    * 
    */

    // Problem 3.
    std::cout << "---  Q2.P3  --- \n";
    double r = 0.02;
    double kappa = 0.3;
    double theta = 0.03;
    double sigma = 0.01;
    double T = 1;
    double stepLength = 0.01;
    double rkSolution = rungeKutta(r, kappa, theta, sigma, T, stepLength);
    std::cout << "Vasicek Bond Value using Runke Kutta: " << rkSolution << "\n" << std::endl;

    // Problem 4.
    std::cout << "---  Q2.P4  --- \n";
    Vasicek GetVasicek(r, kappa, theta, sigma, stepLength);
    std::cout << "r: " << GetVasicek.getR() << std::endl;
    std::cout << "Kappa: " << GetVasicek.getKappa() << std::endl;
    std::cout << "Theta: " << GetVasicek.getTheta() << std::endl;
    std::cout << "Sigma: " << GetVasicek.getSigma() << std::endl;
    std::cout << "Step Length: " << GetVasicek.getStepLength() << "\n" << std::endl;

    // Problem 5.
    std::cout << "---  Q2.P5  --- \n";
    std::cout << "Overloaded pricing function with Vasicek: " << rungeKutta(GetVasicek) << "\n" << std::endl;

    // Problem 6.
    std::cout << "---  Q2.P6  --- \n";
    ZeroCouponBond GetZCB(T);
    std::cout << "Overloaded pricing function with Zero Coupon and Vasicek: " << rungeKutta(GetVasicek, GetZCB) << "\n" << std::endl;

    // Problem 7.
    std::cout << "---  Q2.P7  --- \n";
    GetVasicek.solveODE(10);
    std::cout << "Solution to ODE with T = 10:\n "; 
    std::cout << "A: " << GetVasicek.getODE(10)[0] << std::endl;
    std::cout << "B: " << GetVasicek.getODE(10)[1] << "\n" << std::endl;

    // Problem 8.
    std::cout << "---  Q2.P8  --- \n";
    ZeroCouponBond ZCBOneYear(1);
    ZeroCouponBond ZCBThreeYear(3);
    VasicekBond VasicekBondObjOneYear(GetVasicek, ZCBOneYear);
    std::cout << "One Year Vasicek Bond from the two objects: " << VasicekBondObjOneYear.getPrice() << std::endl;
    VasicekBond VasicekBondObjThreeYear(GetVasicek, ZCBThreeYear);
    std::cout << "Three Year Vasicek Bond from the two objects: " << VasicekBondObjThreeYear.getPrice() << "\n" << std::endl;

    // Problem 9

    // Problem 10.
    std::cout << "---  Q2.P10  --- \n";
    
    double rkSolutionCir = rungeKuttaCir(r, kappa, theta, sigma, T, stepLength);
    std::cout << "Cir Bond Value using Runke Kutta: " << rkSolutionCir << "\n" << std::endl;

    // Problem 11.
    std::cout << "--- Q2.P11 ---\n" << std::endl;
    CIR GetCir(r, kappa, theta, sigma, stepLength);
    GetCir.solveODE(10);
    std::cout << "Solution to ODE with T = 10:\n ";
    std::cout << "A: " << GetCir.getODE(10)[0] << std::endl;
    std::cout << "B: " << GetCir.getODE(10)[1] << std::endl;
    CirBond CirBondObjOneYear(GetCir, ZCBOneYear);
    std::cout << "One Year CIR Bond from the two objects: " << CirBondObjOneYear.getPrice() << std::endl;
    CirBond CirBondObjThreeYear(GetCir, ZCBThreeYear);
    std::cout << "Three Year CIR Bond from the two objects: " << CirBondObjThreeYear.getPrice() << "\n" << std::endl;

    // Problem 12.
    std::cout << "--- Q2.P12 ---\n" << std::endl;
    std::vector<double> notionalValues = { 100, 100 };
    std::vector<std::reference_wrapper<SRB>> bondVector = {CirBondObjOneYear , VasicekBondObjOneYear};
    Portfolio PortfolioBonds(2, bondVector, notionalValues);
    std::cout << "Value of the portfolio is: " << PortfolioBonds.getPrice() << "\n" << std::endl;

    // Problem 13.
    std::cout << "--- Q2.P13 ---\n" << std::endl;
    Portfolio InitialPortfolio;
    std::cout << "Value of the empty portfolio is: " << InitialPortfolio.getPrice() << std::endl;
    InitialPortfolio.addBond(CirBondObjOneYear, 100);
    InitialPortfolio.addBond(VasicekBondObjThreeYear, 100);
    std::cout << "Value of the portfolio with 1YCIR and 3YVasicek is: " << InitialPortfolio.getPrice() << std::endl;
    InitialPortfolio.removeBond(1);
    std::cout << "Value of the portfolio with 1YCIR is: " << InitialPortfolio.getPrice() << std::endl;

    // Question 3.
    // Problem 1.
    std::cout << "---  Q3.P1  --- \n";
    std::cout.std::ios_base::precision(12); // To compare with R's function pnorm
    std::cout << "From function normalCdf(0.225): "  << normalCdf(0.225) << std::endl;
    std::cout << "From function normalCdf(0.775): " << normalCdf(0.775) << "\n" << std::endl;
    std::cout.std::ios_base::precision(6); // Back to normal output precision

    // Problem 2.
    std::cout << "---  Q3.P2  --- \n";
    const double S0 = 90.0;
    const double K = 100.0;
    const double SIGMA0 = 1.3;
    const double ALPHA = 0.5;
    const double BETA = 0.5;
    const double RHO = -0.5;
    T = 3.0;

    SABR SABRObj(S0, K, SIGMA0, ALPHA, BETA, RHO, T);
    std::cout << "SABR BS Call price: " << SABRObj.blackScholesSABR() << "\n" << std::endl;

    // Problem 4.
    std::cout << "---  Q3.P4  --- \n";
    MTRNG RandNumber200Dim(1, 200);
    std::vector<double> normVector(RandNumber200Dim.getDim());
    RandNumber200Dim.genNormal(normVector);
    std::cout << "Path using 100 steps: " << SABRObj.genPath(normVector, T) << std::endl;

    // Problem 6.
    std::cout << "---  Q3.P6  --- \n";
    const int STEPS = 100, PATHS = 10000;
    MTRNG RandNumberMC(1.0, STEPS *2);
    SABR SABRObjMC(S0, K, SIGMA0, ALPHA, BETA, RHO, T);
    CallOption CallOptionObj(K, T);
    //std::cout << "Call TEST " << CallOptionObj.callPayoff(SABRObj.genPath(normVector, T)) << std::endl;
    std::cout << "MC Price: " << MC_SABR(SABRObjMC, CallOptionObj, RandNumberMC, STEPS, PATHS) << std::endl;

    // Problem 7.
    MTRNG RandNumberPathTest(3.0, STEPS * 2);
    SABR SABRObjPathTest(S0, K, SIGMA0, ALPHA, BETA, RHO, T);
    CallOption CallOptionObjPathTest(K, T);
    std::cout << "---  Q3.P7  --- \n";
    std::cout << "needed paths to converge: " << pathsNeededToMatchPrice(0.001, SABRObjPathTest, CallOptionObjPathTest, RandNumberPathTest, STEPS) << std::endl;

    return 0;
}
