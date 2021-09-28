#pragma once
#include "SRB.h"
#include <vector>

class Portfolio
{
public:
	Portfolio(size_t dim_,std::vector<std::reference_wrapper<SRB>> SRBVector_,std::vector <double> NotionalValueVector_);
	Portfolio();
	double getPrice();
	void addBond(const std::reference_wrapper<SRB> SRBBond, const double notionalValue);
	void removeBond(const unsigned int bondIndex);
private:
	size_t dim;
	std::vector<std::reference_wrapper<SRB>> SRBVector;
	std::vector<double> NotionalValueVector;
};