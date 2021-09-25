#pragma once
#include "ZeroCouponBond.h"
#include "Vasicek.h"
#include "SRB.h"

class VasicekBond : private SRB
{
public:
	VasicekBond(Vasicek VasicekObj_, ZeroCouponBond ZeroCouponBondobj_);
	double getPrice();
private:
	Vasicek VasicekObj;
	ZeroCouponBond ZeroCouponBondObj;
};