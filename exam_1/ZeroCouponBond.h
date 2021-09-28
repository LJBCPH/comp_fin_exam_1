#pragma once

class ZeroCouponBond
{
public:
	ZeroCouponBond(const double T_);
	const double getT() { return T; }
private:
	const double T;
};