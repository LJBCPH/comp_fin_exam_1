#include "CirBond.h"
#include <cmath>
#include <iostream>

CirBond::CirBond(CIR CIRObj_, ZeroCouponBond ZeroCouponBondobj_)
	: CIRObj(CIRObj_), ZeroCouponBondObj(ZeroCouponBondobj_)
{
}

double CirBond::getPrice()
{
	std::vector<double> priceVector(2);	
	priceVector = CIRObj.getODE(ZeroCouponBondObj.getT());
	return exp(priceVector[0] + priceVector[1] * CIRObj.getR());
}