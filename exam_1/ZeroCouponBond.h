#pragma once

class ZeroCouponBond
{
public:
	ZeroCouponBond(double T_);
	double getT() { return T; }
private:
	double T;
};