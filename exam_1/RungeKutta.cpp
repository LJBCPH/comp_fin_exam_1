#include "RungeKutta.h"
#include <cmath>
#include <iostream>


/*
Vasicek with Runge Kutta Method
*/
double BFunctionVasicek(double kappa_, double B) {
    return kappa_ * B + 1;
}

double AFunctionVasicek(double kappa_, double theta_, double B, double sigma_) {
    return -kappa_ * theta_ * B - 0.5 * pow(sigma_, 2) * pow(B, 2);
}

double rungeKutta(double r_, double kappa_, double theta_, double sigma_, double T_, double step_length_) {
    double B = 0;
    //double z = BFunction(kappa_, B); //Bmærke = z
    //double y = AFunction(kappa_, theta_, B, sigma_); //Amærke = y
    double z = 0;
    double y = 0;
    double k1, k2, k3, k4, l1, l2, l3, l4;
    for (int i = 0; i < T_ / step_length_; i++) {

        k1 = -step_length_ * BFunctionVasicek(kappa_, z);
        l1 = -step_length_ * AFunctionVasicek(kappa_, theta_, z, sigma_);

        k2 = -step_length_ * BFunctionVasicek(kappa_, z + 0.5 * k1);
        l2 = -step_length_ * AFunctionVasicek(kappa_, theta_, z + 0.5 * l1, sigma_);

        k3 = -step_length_ * BFunctionVasicek(kappa_, z + 0.5 * k2);
        l3 = -step_length_ * AFunctionVasicek(kappa_, theta_, z + 0.5 * l2, sigma_);

        k4 = -step_length_ * BFunctionVasicek(kappa_, z + k3);
        l4 = -step_length_ * AFunctionVasicek(kappa_, theta_, z + l3, sigma_);

        z = z + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        y = y + (l1 + 2 * l2 + 2 * l3 + l4) / 6;
    }
    //std::cout << "z: " << z << "y: " << y << std::endl;
    return (exp(y + z * r_));
}

double rungeKutta(Vasicek VasicekObject)
{
    double step_length = VasicekObject.getStepLength();
    double r= VasicekObject.getR();
    double kappa = VasicekObject.getKappa();
    double theta = VasicekObject.getTheta();
    double sigma = VasicekObject.getSigma();
    double T = VasicekObject.getT();
    double z = 0;
    double y = 0;
    double k1, k2, k3, k4, l1, l2, l3, l4;
    std::cout << "tst: " << T / step_length << std::endl;
    for (int i = 0; i < T / step_length; i++) {

        k1 = -step_length * BFunctionVasicek(kappa, z);
        l1 = -step_length * AFunctionVasicek(kappa, theta, z, sigma);

        k2 = -step_length * BFunctionVasicek(kappa, z + 0.5 * k1);
        l2 = -step_length * AFunctionVasicek(kappa, theta, z + 0.5 * l1, sigma);

        k3 = -step_length * BFunctionVasicek(kappa, z + 0.5 * k2);
        l3 = -step_length * AFunctionVasicek(kappa, theta, z + 0.5 * l2, sigma);

        k4 = -step_length * BFunctionVasicek(kappa, z + k3);
        l4 = -step_length * AFunctionVasicek(kappa, theta, z + l3, sigma);

        z = z + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        y = y + (l1 + 2 * l2 + 2 * l3 + l4) / 6;
    }
    //std::cout << "z: " << z << "y: " << y << std::endl;
    return (exp(y + z * r));
}

/*
CIR with Runge Kutta Method
*/

double BFunctionCir(double kappa_, double B,double sigma_) {
    return kappa_ * B - 0.5 * pow(sigma_, 2) * pow(B,2) + 1;
}

double AFunctionCir(double kappa_, double theta_, double B) {
    return -kappa_ * theta_ * B;
}

double rungeKuttaCir(double r_, double kappa_, double theta_, double sigma_, double T_, double step_length_) {
    double B = 0;
    //double z = BFunction(kappa_, B); //Bmærke = z
    //double y = AFunction(kappa_, theta_, B, sigma_); //Amærke = y
    double z = 0;
    double y = 0;
    double k1, k2, k3, k4, l1, l2, l3, l4;
    for (int i = 0; i < T_ / step_length_; i++) {

        k1 = -step_length_ * BFunctionCir(kappa_, z, sigma_);
        l1 = -step_length_ * AFunctionCir(kappa_, theta_, z);

        k2 = -step_length_ * BFunctionCir(kappa_, z + 0.5 * k1, sigma_);
        l2 = -step_length_ * AFunctionCir(kappa_, theta_, z + 0.5 * l1);

        k3 = -step_length_ * BFunctionCir(kappa_, z + 0.5 * k2, sigma_);
        l3 = -step_length_ * AFunctionCir(kappa_, theta_, z + 0.5 * l2);

        k4 = -step_length_ * BFunctionCir(kappa_, z + k3, sigma_);
        l4 = -step_length_ * AFunctionCir(kappa_, theta_, z + l3);

        z = z + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        y = y + (l1 + 2 * l2 + 2 * l3 + l4) / 6;
    }
    //std::cout << "z: " << z << "y: " << y << std::endl;
    return (exp(y + z * r_));
}