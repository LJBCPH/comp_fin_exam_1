#pragma once
#include <vector>
#include "gaussian_header.hpp"

class SABR
{
public:
	SABR(const double S0_, const double K_, const double sigma0_, const double alpha_, const double beta_, const double rho_, const double T_);
	double blackScholesSABR();
	double genPath(std::vector<double> normVec, const double T_);
private:
	const double S0, K, sigma0, alpha, beta, rho, T;
};