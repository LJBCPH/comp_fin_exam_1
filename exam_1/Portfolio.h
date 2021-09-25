#pragma once
#include "SRB.h"
#include <vector>

class Portfolio
{
public:
	Portfolio(size_t dim_, SRB SRBOne, SRB SRBTwo);
private:
	size_t dim;
	std::vector<double> srbVectorOne;
	std::vector<double> srbVectorTwo;
	double notionalValueOne;
	double notionalValueTwo;
};