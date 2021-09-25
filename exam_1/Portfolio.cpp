#include "Portfolio.h"
#include "SRB.h"

Portfolio::Portfolio(size_t dim_, std::vector<std::reference_wrapper<SRB>> SRBVector_, std::vector<double> NotionalValueVector_)
	:dim(dim_), SRBVector(SRBVector_), NotionalValueVector(NotionalValueVector_)
{
}

double Portfolio::getPrice()
{
	double portfolioSum = 0;
	for (int i = 0; i != dim; i++)
	{
		portfolioSum += SRBVector[i].get().getPrice() * NotionalValueVector[i];
	}
	return portfolioSum;
}

Portfolio::Portfolio()
{
	dim = 0;
}

void Portfolio::addBond(const std::reference_wrapper<SRB> SRBBond, double notionalValue)
{
	SRBVector.push_back(SRBBond); 
	NotionalValueVector.push_back(notionalValue); 
	dim = SRBVector.size(); 
}

void Portfolio::removeBond(unsigned int bondIndex)
{
	SRBVector.erase(SRBVector.begin() + bondIndex); 
	NotionalValueVector.erase(NotionalValueVector.begin() + bondIndex); 
	dim = SRBVector.size(); 
}
