#pragma once
#include "ZeroCouponBond.h"
#include "Vasicek.h"
class VasicekBond
{
public:
	VasicekBond(Vasicek VasicekObj_, ZeroCouponBond ZeroCouponBondobj_);
	double getPrice();
private:
	Vasicek VasicekObj;
	ZeroCouponBond ZeroCouponBondObj;
};