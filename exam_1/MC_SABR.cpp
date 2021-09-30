#include "MC_SABR.h"
#include <vector>
#include <iostream>
#include <cmath>

double MC_SABR(SABR SABRObj, CallOption CallOptionObj, MTRNG MTRNGObj, double steps, double paths) {
    std::vector<double> normVector(steps * 2.0);

    double payoff = 0;

    for(int j = 0; j < paths; j++){
        MTRNGObj.genNormal(normVector);
        payoff += CallOptionObj.callPayoff(SABRObj.genPath(normVector, CallOptionObj.getT()));
    }

    return payoff/paths;
}

double pathsNeededToMatchPrice(double eps, SABR SABRObj, CallOption CallOptionObj, MTRNG MTRNGObj, double steps) {
    std::vector<double> normVector(steps * 2.0);

    double payoff = 0, err = 1; 
    int paths = 0;
    double analyticalPrice = SABRObj.blackScholesSABR();
    
    while (err > eps) {
        for(int k = 0; k < 1; k++){ // used during test, set k < x to evaluate error based on x chunks
            paths += 1;
            MTRNGObj.genNormal(normVector);
            payoff += CallOptionObj.callPayoff(SABRObj.genPath(normVector, CallOptionObj.getT()));
        }
        err = abs(1 - (payoff / (double)paths) / analyticalPrice);
    }

    std::cout << "Payoff: " << payoff / (double)paths << "  Analytical price: " << analyticalPrice << "Error: " << abs(payoff / (double)paths - analyticalPrice) << std::endl;
    return paths;
}