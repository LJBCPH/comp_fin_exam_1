#pragma once

class Vasicek {
public:
	Vasicek(double r_input, double kappa_input, double theta_input, double sigma_input, double step_length_input);

	double getR() { return r; }
	double getKappa() { return kappa; }
	double getTheta() { return theta; }
	double getSigma() { return sigma; }
	double getStepLength() { return step_length; }

	double rungeKutta();
	double BFunction(double B);
	double AFunction(double B);

private:
	double r;
	double kappa;
	double theta;
	double sigma;
	double step_length;
};