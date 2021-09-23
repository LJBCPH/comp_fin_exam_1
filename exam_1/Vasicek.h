#pragma once
#include <vector>

class Vasicek {
public:
	Vasicek(double r_input, double kappa_input, double theta_input, double sigma_input, double step_length_input);

	double getR() { return r; }
	double getKappa() { return kappa; }
	double getTheta() { return theta; }
	double getSigma() { return sigma; }
	double getStepLength() { return step_length; }
	double getT() { return T; }
	std::vector<std::vector<double>> solveODE(double T_);
	double getODE(double T_);

private:
	double r;
	double kappa;
	double theta;
	double sigma;
	double step_length;
	double T;
	std::vector<std::vector<double>> sol;
};