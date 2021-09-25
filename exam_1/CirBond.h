#pragma once
#include "SRB.h"
#include "CIR.h"
#include "ZeroCouponBond.h"

class CirBond : private SRB
{
public:
	CirBond(CIR CIRObj_, ZeroCouponBond ZeroCouponBondobj_);
	double getPrice();
private:
	CIR CIRObj;
	ZeroCouponBond ZeroCouponBondObj;
};