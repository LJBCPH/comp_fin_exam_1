#include "Vasicek.h"
#include <cmath>

double Vasicek::BFunction(double B) {
	return kappa * B + 1;
}

double Vasicek::AFunction(double B) {
	return -kappa * theta * B - 0.5 * pow(sigma, 2) * pow(B, 2);
}

Vasicek::Vasicek(double r_input, double kappa_input, double theta_input, double sigma_input, double step_length_input) 
	:r(r_input), kappa(kappa_input), theta(theta_input), sigma(sigma_input), step_length(step_length_input)
{
}

double Vasicek::rungeKutta()
{
    //double z = BFunction(kappa, B); //Bmærke = z
    //double y = AFunction(kappa, theta, B, sigma); //Amærke = y
    double z = 0;
    double y = 0;
    double k1, k2, k3, k4, l1, l2, l3, l4;
    for (int i = 0; i < 1 / step_length; i++) {

        k1 = -step_length * BFunction(z);
        l1 = -step_length * AFunction(z);

        k2 = -step_length * BFunction(z + 0.5 * k1);
        l2 = -step_length * AFunction(z + 0.5 * l1);

        k3 = -step_length * BFunction(z + 0.5 * k2);
        l3 = -step_length * AFunction(z + 0.5 * l2);

        k4 = -step_length * BFunction(z + k3);
        l4 = -step_length * AFunction(z + l3);

        z = z + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        y = y + (l1 + 2 * l2 + 2 * l3 + l4) / 6;
    }
    //std::cout << "z: " << z << "y: " << y << std::endl;
    return (exp(y + z * r));
}
