#include "Vasicek.h"
#include "RungeKutta.h"
#include <cmath>
#include <vector>
#include <iostream>

Vasicek::Vasicek(const double r_input, const double kappa_input, const double theta_input, const double sigma_input, const double step_length_input)
	:r(r_input), kappa(kappa_input), theta(theta_input), sigma(sigma_input), step_length(step_length_input)
{
	T = 1;
}

std::vector<std::vector<double>> Vasicek::solveODE(const double T_)
{
    std::vector<std::vector<double>> solODE(T_, std::vector<double>(2, 0)); //vector of dim Tx2

    int j = 0;
    const double step_length_ = step_length;
    const double kappa_ = kappa;
    const double theta_ = theta;
    const double sigma_ = sigma;
    double z = 0;
    double y = 0;
    double k1, k2, k3, k4, l1, l2, l3, l4;
    for (int i = 0; i < T_ / step_length_; i++) {

        k1 = -step_length_ * BFunctionVasicek(kappa_, z);
        l1 = -step_length_ * AFunctionVasicek(kappa_, theta_, z, sigma_);

        k2 = -step_length_ * BFunctionVasicek(kappa_, z + 0.5 * k1);
        l2 = -step_length_ * AFunctionVasicek(kappa_, theta_, z + 0.5 * k1, sigma_);

        k3 = -step_length_ * BFunctionVasicek(kappa_, z + 0.5 * k2);
        l3 = -step_length_ * AFunctionVasicek(kappa_, theta_, z + 0.5 * k2, sigma_);

        k4 = -step_length_ * BFunctionVasicek(kappa_, z + k3);
        l4 = -step_length_ * AFunctionVasicek(kappa_, theta_, z + k3, sigma_);

        z = z + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        y = y + (l1 + 2 * l2 + 2 * l3 + l4) / 6;

        if (i == (j + 1.0) / step_length - 1) {
            solODE[j][0] = y;
            solODE[j][1] = z;
            j += 1;
        }
    }

	return sol = solODE;
}

std::vector<double> Vasicek::getODE(const double T_)
{
    std::vector<double> solVector(2);
    solVector[0] = sol[T_-1][0];
    solVector[1] = sol[T_-1][1];

    return solVector;
}

