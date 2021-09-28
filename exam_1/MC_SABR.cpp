#include "MC_SABR.h"
#include <vector>
#include <iostream>
#include <cmath>

double MC_SABR(SABR SABRObj, CallOption CallOptionObj, MTRNG MTRNGObj, double steps, double paths) {
    std::vector<double> normVector(steps * 2);

    double payoff = 0;

    for(int j = 0; j < paths; j++){
        MTRNGObj.genNormal(normVector);
        payoff += CallOptionObj.callPayoff(SABRObj.genPath(normVector, CallOptionObj.getT()));
    }

//    std::cout << "PAYOFF " << payoff << "  PATJS " << paths << std::endl;
    return payoff/(double)paths;
}

double pathsNeededToMatchPrice(double eps, SABR SABRObj, CallOption CallOptionObj, MTRNG MTRNGObj, double steps) {
    std::vector<double> normVector(steps * 2);

    double payoff = 0, err = 1; //initial = 1 to not break while loop
    int paths = 0;
    double analyticalPrice = SABRObj.blackScholesSABR();
    std::cout << eps << std::endl;
    while (err > eps) {
            for(int k = 0; k < 50; k++){
                paths += 1;
                MTRNGObj.genNormal(normVector);
                payoff += CallOptionObj.callPayoff(SABRObj.genPath(normVector, CallOptionObj.getT()));
            }
            std::cout << "ERR " << err << " PRICE " << payoff / (double)paths << std::endl;
            err = abs(payoff / (double)paths - analyticalPrice);
            if (paths % 1000 == 0) {
              //  std::cout << "Path number: " << paths << " PRICE: " << payoff/(double) paths << std::endl;
            }
    }

    std::cout << "PAYOFF " << payoff / (double)paths << "  PATJS " << analyticalPrice << " DIFF : " << abs(payoff / (double)paths - analyticalPrice) << std::endl;
    return paths;
}