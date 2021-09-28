#pragma once
#include <vector>

class Vasicek {
public:
	Vasicek(const double r_input, const double kappa_input, const double theta_input, const double sigma_input, const double step_length_input);

	double getR() { return r; }
	double getKappa() { return kappa; }
	double getTheta() { return theta; }
	double getSigma() { return sigma; }
	double getStepLength() { return step_length; }
	double getT() { return T; }
	std::vector<std::vector<double>> solveODE(const double T_);
	std::vector<double> getODE(const double T_);

private:
	const double r, kappa, theta, sigma, step_length;
	double T;
	std::vector<std::vector<double>> sol;
};