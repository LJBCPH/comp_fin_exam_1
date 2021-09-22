#pragma once
#include "gaussian_header.hpp"

class SABR
{
public:
	SABR(double S0_, double K_, double sigma0_, double alpha_, double beta_, double rho_, double T_);
	double blackScholesSABR();
private:
	double S0, K, sigma0, alpha, beta, rho, T;
};