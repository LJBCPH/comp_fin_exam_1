#include "SABR.h"
#include <cmath>
#include <iostream>

SABR::SABR(double S0_, double K_, double sigma0_, double alpha_, double beta_, double rho_, double T_)
	: S0(S0_), K(K_), sigma0(sigma0_), alpha(alpha_), beta(beta_), rho(rho_), T(T_)
{
}

double SABR::blackScholesSABR()
{
	double fMid = pow(S0 * K, 0.5);
	double gamma1 = beta / fMid;
	double gamma2 = -(beta * (1 - beta)) / (pow(fMid, 2));
	double zeta = alpha / (sigma0 * (1 - beta)) * (pow(S0, 1 - beta) - pow(K, 1 - beta));
	double dZeta = log((pow(1 - 2 * rho * zeta + pow(zeta, 2), 0.5)+zeta - rho) / (1 - rho));
	double eps = T * pow(alpha, 2);
	double impl_vol = alpha * log(S0/K)/dZeta*(1+(
		(2*gamma2-pow(gamma1, 2)+1/pow(fMid,2))/24*
		pow(sigma0*pow(fMid,beta)/alpha,2)+
		rho*gamma1/4*
		sigma0*pow(fMid, beta)/alpha+
		(2-3*pow(rho,2))/24)*eps);

	double d1 = (log(S0 / K) + (pow(impl_vol, 2) / 2) * T)/(impl_vol*pow(T,0.5));
	double d2 = d1 - impl_vol * pow(T, 0.5);
	double callPrice = exp(-0 * T) * (S0 * normalCdf(d1) - K * normalCdf(d2));

	return callPrice;
}
double SABR::genPath(std::vector<double> normVec, double T_)
{
	const int steps = normVec.size() / 2.0;
	double st = S0;
	double sigma = sigma0;
	double W1, W2, normY, normX, normZ;
	double W1Last = 0, W2Last = 0;
	
	for (int i = 0; i < steps; i++) {
		normX = normVec[2.0 * i];
		normZ = normX * rho + pow(1.0 - pow(rho, 2.0), 0.5) * normVec[1.0 + 2.0 * i];
		
		W1 = pow(T_ / steps, 0.5) * normX;
		W2 = pow(T_ / steps, 0.5) * normZ;

		st = st + sigma * pow(st, beta) * W1;
		sigma = sigma * exp(-0.5 * pow(alpha, 2.0) * (T_ / steps) + alpha * W2);

		//if (i == 10) {
		//	std::cout << "W1: " << W1 << std::endl;
		//	std::cout << "W2: " << W2 << std::endl;
		//	std::cout << "st: " << st << std::endl;
		//	std::cout << "sigma: " << sigma << std::endl;
		//	std::cout << "sigma: " << T_ / steps << std::endl;
		//}
	}

	return st;
}

