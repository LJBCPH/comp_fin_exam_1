#include "VasicekBond.h"
#include <cmath>
#include <iostream>

VasicekBond::VasicekBond(Vasicek VasicekObj_, ZeroCouponBond ZeroCouponBondobj_)
	: VasicekObj(VasicekObj_), ZeroCouponBondObj(ZeroCouponBondobj_)
{
}

double VasicekBond::getPrice()
{
	std::vector<double> priceVector(2);
	priceVector = VasicekObj.getODE(ZeroCouponBondObj.getT());
	return exp(priceVector[0]+priceVector[1]*VasicekObj.getR());
}
