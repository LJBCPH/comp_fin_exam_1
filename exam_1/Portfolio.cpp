#include "Portfolio.h"
#include "SRB.h"

Portfolio::Portfolio(size_t dim_, std::vector<std::reference_wrapper<SRB>> SRBVector_, std::vector<double> NotionalValueVector_)
	:dim(dim_), SRBVector(SRBVector_), NotionalValueVector(NotionalValueVector_)
{
}

double Portfolio::getPrice()
{
	double portfolioSum = 0;
	for (unsigned int i = 0; i != dim; i++)
	{
		portfolioSum += SRBVector[i].get().getPrice() * NotionalValueVector[i];
	}
	return portfolioSum;
}
