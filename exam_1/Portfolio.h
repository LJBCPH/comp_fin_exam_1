#pragma once
#include "SRB.h"
#include <vector>

class Portfolio
{
public:
	Portfolio(size_t dim_,std::vector<std::reference_wrapper<SRB>> SRBVector_,std::vector <double> NotionalValueVector_);
	double getPrice();
private:
	size_t dim;
	std::vector<std::reference_wrapper<SRB>> SRBVector;
	std::vector<double> NotionalValueVector;
};