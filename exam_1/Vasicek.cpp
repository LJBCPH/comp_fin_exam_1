#include "Vasicek.h"
#include <cmath>

Vasicek::Vasicek(double r_input, double kappa_input, double theta_input, double sigma_input, double step_length_input) 
	:r(r_input), kappa(kappa_input), theta(theta_input), sigma(sigma_input), step_length(step_length_input)
{
}
