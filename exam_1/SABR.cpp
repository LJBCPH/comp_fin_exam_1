#include "SABR.h"
#include <cmath>

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
	double dZeta = log((pow(1 - 2 * rho * zeta + pow(zeta, 2), 0.5)) / (1 - rho));
	double eps = T * pow(alpha, 2);
	double vol = alpha * log(S0/K)/dZeta*(1+(
		(2*gamma2-pow(gamma1, 2)+1/pow(fMid,2))/24*
		pow(sigma0*pow(fMid,beta)/alpha,2)+
		rho*gamma1/4*
		sigma0*pow(fMid, beta)/alpha+
		(2-3*pow(rho,2))/24)*eps);
	double d1 = (1 / (vol * pow(T, 0.5))) * (log(S0 / K) + 0.5 * pow(vol, 2) * T);
	double d2 = d1 - vol * pow(T, 0.5);
	double callPrice = normalCdf(d1) * S0 - normalCdf(d2) * K;
	return callPrice;
}
