#include "Vasicek.h"
#include "RungeKutta.h"
#include <cmath>
#include <vector>
#include <iostream>

Vasicek::Vasicek(double r_input, double kappa_input, double theta_input, double sigma_input, double step_length_input) 
	:r(r_input), kappa(kappa_input), theta(theta_input), sigma(sigma_input), step_length(step_length_input)
{
	T = 1;
}

std::vector<std::vector<double>> Vasicek::solveODE(double T_)
{
    size_t vecDim = T;
    size_t ODEDim = 2;
    std::vector<std::vector<double>> solODE(10, std::vector<double>(2, 0));
    solODE[1][0] = 1;
    std::cout << "testeststse: " << solODE[1][0] << std::endl;

    double step_length_ = step_length;
    double kappa_ = kappa;
    double theta_ = theta;
    double sigma_ = sigma;
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

		if (i != 0 && (i) % (int)(1 / step_length - 1) == 0) {
            std::cout << "nom : " << i << std::endl;
            std::cout << "denom : " << (int)(1 / step_length - 2) << std::endl;
            solODE[0][i % (int)(1 / step_length - 1)] = z;
            solODE[1][i % (int)(1/step_length - 1)] = y;
        }
    }

	return sol = solODE;
}

double Vasicek::getODE(double T_)
{
    return (exp(sol[1][T-1] + sol[0][T-1] * r));
}

